/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2018 David Villalobos Cambronero (dvillalobosc@yahoo.com).
*
* Calíope is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Calíope is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*
*****************************************************************************/

#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTimer>
#include <QApplication>
#include <QMessageBox>
#include <QGroupBox>
#include <QPushButton>
#include <QSplitter>

#include "databasecomparision.h"
#include "dtitlelabel.h"
#include "basetexteditor.h"
#include "dbms.h"
#include "connectdialog.h"

#include "QDebug"

DatabaseComparision::DatabaseComparision(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  secondaryServerConnection = new DBMS(false);
  connect(secondaryServerConnection, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessageSlot(QString)));
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));
  QWidget *widMain = new QWidget;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  buttonGroup = new QGroupBox(this);
  QHBoxLayout *groupBoxHLayout = new QHBoxLayout;
  buttonGroup->setLayout(groupBoxHLayout);
  pushButtonPrimaryCompare = new QPushButton;
  pushButtonPrimaryCompare->setIcon(QIcon(":/images/svg/system-run-5.svg"));
  connect(pushButtonPrimaryCompare, SIGNAL(clicked()), this, SLOT(comparePrimarySlot()));
  groupBoxHLayout->addWidget(pushButtonPrimaryCompare);
  pushButtonSecondaryCompare = new QPushButton;
  pushButtonSecondaryCompare->setIcon(QIcon(":/images/svg/system-run-5.svg"));
  connect(pushButtonSecondaryCompare, SIGNAL(clicked()), this, SLOT(compareSeconadarySlot()));
  groupBoxHLayout->addWidget(pushButtonSecondaryCompare);
  groupBoxHLayout->addStretch(1);
  mainVLayout->addWidget(buttonGroup);

  QSplitter *mainSplitter = new QSplitter(Qt::Horizontal);
  QSplitter *secondSplitter = new QSplitter(Qt::Vertical);
  QVBoxLayout *secondLayout = new QVBoxLayout;
  tablesListWidget = new QTreeWidget;
  connect(tablesListWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  connect(tablesListWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  secondaryTablesListWidget = new QTreeWidget;
  connect(secondaryTablesListWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(secondaryItemActivatedSlot(QTreeWidgetItem*,int)));
  connect(secondaryTablesListWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(secondaryItemActivatedSlot(QTreeWidgetItem*,int)));
  resutlEditor = new BaseTextEditor(EditorTypes::NoEditor);
  resutlEditor->setWordWrapMode(QTextOption::NoWrap);
  mainSplitter->addWidget(tablesListWidget);
  mainSplitter->addWidget(secondaryTablesListWidget);
  secondSplitter->addWidget(mainSplitter);
  secondSplitter->addWidget(resutlEditor);
  secondLayout->addWidget(secondSplitter);
  mainVLayout->addWidget(secondSplitter);
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
  QTimer::singleShot(0, this, SLOT(fillTablesSlot()));
}

void DatabaseComparision::retranslateUi()
{
  setWindowTitle(tr("Database Comparision"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  buttonGroup->setTitle(tr("Actions"));
  pushButtonPrimaryCompare->setText(tr("Primary compare"));
  pushButtonPrimaryCompare->setToolTip(pushButtonPrimaryCompare->text());
  pushButtonSecondaryCompare->setText(tr("Secondary compare"));
  pushButtonSecondaryCompare->setToolTip(pushButtonSecondaryCompare->text());
}

void DatabaseComparision::fillTablesSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  tables.clear();
  tablesListWidget->setWindowTitle(tr("Original database server: %1").arg(serverConnection->getHostName()));
  tablesListWidget->setHeaderLabel(tablesListWidget->windowTitle());
  foreach (QString database, serverConnection->getDatabases()) {
    QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(database), ItemTypes::Database);
    item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item->setCheckState(0, Qt::Unchecked);
    tables.append(item);
//    foreach (QString table, serverConnection->database(database)->getTables()) {
//      QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(database + "." + table), ItemTypes::Table);
//      itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//      itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
//      itemChild->setCheckState(0, Qt::Unchecked);
//      tables.append(itemChild);
//    }
  }
  tablesListWidget->clear();
  tablesListWidget->insertTopLevelItems(0, tables);
  QApplication::restoreOverrideCursor();

  pushButtonPrimaryCompare->setEnabled(false);
  ConnectDialog *connectFrom = new ConnectDialog(secondaryServerConnection);
  if (connectFrom->exec() == QDialog::Accepted) {
    if (!connectFrom->getConnectionPerformed()) {
      if (secondaryServerConnection->isOpened())
        secondaryServerConnection->close();
      //0 - Connection name
      //1 - User
      //2 - Host
      //3 - Port
      //4 - Database
      //5 - Conexion count
      //6 - Collation
      //7 - UseSSL
      //8 - KeyFile
      //9 - CertFile
      //10 - Password
      secondaryServerConnection->setUserName(connectFrom->getValues().at(1));
      secondaryServerConnection->setHostName(connectFrom->getValues().at(2));
      secondaryServerConnection->setPassword(connectFrom->getValues().at(10));
      secondaryServerConnection->setDatabase(connectFrom->getValues().at(4));
      secondaryServerConnection->setPort(connectFrom->getValues().at(3).toUInt());
      secondaryServerConnection->setCharacterSet(connectFrom->getValues().at(6).split("|").at(0));
      secondaryServerConnection->setCollation(connectFrom->getValues().at(6).split("|").at(1));
      secondaryServerConnection->setUseSSL(connectFrom->getValues().at(7).toInt());
      secondaryServerConnection->setKeyFile(connectFrom->getValues().at(8));
      secondaryServerConnection->setCertFile(connectFrom->getValues().at(9));
      if (!secondaryServerConnection->open())
        QMessageBox::critical(this, tr("Cannot connect to the server"), secondaryServerConnection->lastError());
    }
  }
  if (secondaryServerConnection->isOpened()) {
    secondaryTablesListWidget->setWindowTitle(tr("Secondary database server: %1").arg(secondaryServerConnection->getHostName()));
    secondaryTablesListWidget->setHeaderLabel(secondaryTablesListWidget->windowTitle());
    pushButtonPrimaryCompare->setEnabled(true);
    emit statusBarMessage(tr("Connected successfully to: %1").arg(secondaryServerConnection->getHostName()));
    QApplication::setOverrideCursor(Qt::WaitCursor);
    secondaryTables.clear();
    foreach (QString database, secondaryServerConnection->getDatabases()) {
      QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(database), ItemTypes::Database);
      item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
      item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
      item->setCheckState(0, Qt::Unchecked);
      secondaryTables.append(item);
//      foreach (QString table, secondaryServerConnection->database(database)->getTables()) {
//        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(database + "." + table), ItemTypes::Table);
//        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
//        itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
//        itemChild->setCheckState(0, Qt::Unchecked);
//        secondaryTables.append(itemChild);
//      }
    }
    secondaryTablesListWidget->clear();
    secondaryTablesListWidget->insertTopLevelItems(0, secondaryTables);
    QApplication::restoreOverrideCursor();
  }
}

void DatabaseComparision::comparePrimarySlot()
{
  comparision();
}

void DatabaseComparision::comparision(bool primary)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QList<QStringList> *rows = new QList<QStringList>();
  rows->append(QStringList() << tr("Server") << tr("Database") << tr("Table") << tr("Row count") << tr("Data length") << tr("Checksum")
               << tr("Row count validation")
               << tr("Data length validation")
               << tr("Checksum validation")
               );
  QString database;
  QString table;
  QList<QTreeWidgetItem *> tablesToCompare;
  int unsigned itemProcessed = 0;
  unsigned long rowCount1 = 0;
  unsigned long rowCount2 = 0;
  unsigned long dataLength1 = 0;
  unsigned long dataLength2 = 0;
  unsigned long checksum1 = 0;
  unsigned long checksum2 = 0;

  if (primary)
    tablesToCompare = tables;
  else
    tablesToCompare = secondaryTables;

  foreach (QTreeWidgetItem *item, tables) {
    if (item->checkState(0) == Qt::Checked && item->parent()) {
      database = item->text(0).split(".").at(0);
      table = item->text(0).split(".").at(1);
      rowCount1 = serverConnection->table(table, database)->getRowCount();
      rowCount2 = secondaryServerConnection->table(table, database)->getRowCount();
      dataLength1 = serverConnection->table(table, database)->getDataLength();
      dataLength2 = secondaryServerConnection->table(table, database)->getDataLength();
      checksum1 = serverConnection->table(table, database)->getChecksum();
      checksum2 = secondaryServerConnection->table(table, database)->getChecksum();
      rows->append(QStringList() << serverConnection->getHostName()
                   << database
                   << table
                   << QString("%1").arg(rowCount1)
                   << QString("%1").arg(dataLength1)
                   << QString("%1").arg(checksum1)
                   << (primary ? (rowCount1 != rowCount2 ? "*" : "") : "")
                   << (primary ? (dataLength1 != dataLength2 ? "*" : "") : "")
                   << (primary ? (checksum1 != checksum2 ? "*" : "") : "")
                   );
      rows->append(QStringList() << secondaryServerConnection->getHostName()
                   << database
                   << table
                   << QString("%1").arg(rowCount2)
                   << QString("%1").arg(dataLength2)
                   << QString("%1").arg(checksum2)
                   << (primary ? "" : (rowCount1 != rowCount2 ? "*" : ""))
                   << (primary ? "" : (dataLength1 != dataLength2 ? "*" : ""))
                   << (primary ? "" : (checksum1 != checksum2 ? "*" : ""))
                   );
      rows->append(QStringList() << "***"
                   << "***"
                   << "***"
                   << "***"
                   << "***"
                   << "***"
                   << "***"
                   << "***"
                   << "***"
                   );
    }
    emit statusBarProgressMessage(item->text(0), 0, (++itemProcessed * 100 / tables.count()));
  }
  //Remove the last ***
 rows->takeLast();

  int row = 0;
  int row2 = 0;
  QList<int> maxWidthList;
  QString output;

  //Find the maximum values for the width of the columns
  for (row = 0; row < rows->at(0).count(); row++)
    maxWidthList.append(1);
  for (row = 0; row < rows->count(); row++)
    for (row2 = 0; row2 < rows->at(row).count(); row2++)
      if (QString(rows->at(row).at(row2)).length() > maxWidthList.at(row2))
        maxWidthList.replace(row2, QString(rows->at(row).at(row2)).length());

  //Prints the headres and theirs borders
  output += "+";
  for (row = 0; row < rows->at(0).count(); row++)
    output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";
  output += "\n|";
  for (row = 0; row < rows->at(0).count(); row++)
    output +=  " " + rows->at(0).at(row).leftJustified(maxWidthList.at(row), ' ') + " |";
  output += "\n+";
  for (row = 0; row < rows->at(0).count(); row++)
    output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";

  //Print the data
  for (row = 1; row < rows->count(); row++) {
    //output += "\n|" + ((row % 2 != 0) ? highlightError(rows, row) : "");
    output += "\n|";
    for (row2 = 0; row2 < rows->at(row).count(); row2++)
      if (rows->at(row).at(row2) == "***")
        output +=  QString('-').repeated(maxWidthList.at(row2) + 2) + "|";
      else
        output +=  " " + rows->at(row).at(row2).leftJustified(maxWidthList.at(row2), ' ') + " |";
  }

  //Print the botton border
  output += "\n+";
  for (row = 0; row < rows->at(0).count(); row++)
    output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";

  resutlEditor->setPlainText(output);
  QApplication::restoreOverrideCursor();
}

void DatabaseComparision::compareSeconadarySlot()
{
  comparision(false);
}

void DatabaseComparision::itemActivatedSlot(QTreeWidgetItem *item, int column)
{
  if (item->type() == ItemTypes::Database) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    foreach (QTreeWidgetItem *tableItem, tables)
      if (tableItem->parent() == item)
        tableItem->setCheckState(column, item->checkState(column));
    if (item->childCount() == 0)
      foreach (QString table, serverConnection->database(item->text(0))->getLocalTables()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(item->text(0) + "." + table), ItemTypes::Table);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
        itemChild->setCheckState(0, Qt::Unchecked);
        tables.append(itemChild);
      }
    QApplication::restoreOverrideCursor();
  }
}

void DatabaseComparision::secondaryItemActivatedSlot(QTreeWidgetItem *item, int column)
{
  if (item->type() == ItemTypes::Database) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    foreach (QTreeWidgetItem *tableItem, secondaryTables)
      if (tableItem->parent() == item)
        tableItem->setCheckState(column, item->checkState(column));
    if (item->childCount() == 0)
      foreach (QString table, secondaryServerConnection->database(item->text(0))->getLocalTables()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(item->text(0) + "." + table), ItemTypes::Table);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
        itemChild->setCheckState(0, Qt::Unchecked);
        secondaryTables.append(itemChild);
      }
    QApplication::restoreOverrideCursor();
  }
}

void DatabaseComparision::statusBarMessageSlot(QString message)
{
  emit statusBarMessage(message);
}
