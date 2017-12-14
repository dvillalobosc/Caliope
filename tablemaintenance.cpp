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
#include <QCheckBox>
#include <QTreeWidget>
#include <QGroupBox>
#include <QTimer>
#include <QApplication>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QTreeWidgetItemIterator>

#include "tablemaintenance.h"
#include "dtitlelabel.h"
#include "dbms.h"
#include "basetexteditor.h"

#include "QDebug"

TableMaintenance::TableMaintenance(DBMS *serverConnection)
{

  this->serverConnection = serverConnection;
  setWindowIcon(QIcon::fromTheme("preferences-system", QIcon(":/images/svg/preferences-system-4.svg")));
  QWidget *widMain = new QWidget;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
//  mainVLayout->addWidget(new TableMaintenanceWizard(parent));

  groupBoxAction = new QGroupBox(this);
  QVBoxLayout *thirdLayout = new QVBoxLayout;
  analyzePushButton = new QPushButton;
  connect(analyzePushButton, SIGNAL(clicked()), this, SLOT(analyzePushButtonSlot()));
  checkPushButton = new QPushButton;
  connect(checkPushButton, SIGNAL(clicked()), this, SLOT(checkPushButtonSlot()));
  checksumPushButton = new QPushButton;
  connect(checksumPushButton, SIGNAL(clicked()), this, SLOT(checksumPushButtonSlot()));
  optimizePushButton = new QPushButton;
  connect(optimizePushButton, SIGNAL(clicked()), this, SLOT(optimizePushButtonSlot()));
  repairPushButton = new QPushButton;
  connect(repairPushButton, SIGNAL(clicked()), this, SLOT(repairPushButtonSlot()));
  thirdLayout->addWidget(analyzePushButton);
  thirdLayout->addWidget(checkPushButton);
  thirdLayout->addWidget(checksumPushButton);
  thirdLayout->addWidget(optimizePushButton);
  thirdLayout->addWidget(repairPushButton);
  //Set tooltips for these options
  optionLOCAL = new QCheckBox("LOCAL");
  optionFORUPGRADE = new QRadioButton("FOR UPGRADE");
  optionQUICK = new QRadioButton("QUICK");
  optionFAST = new QRadioButton("FAST");
  optionMEDIUM = new QRadioButton("MEDIUM");
  optionEXTENDED = new QRadioButton("EXTENDED");
  optionCHANGED = new QRadioButton("CHANGED");
  optionUSE_FRM = new QRadioButton("USE_FRM");
  thirdLayout->addWidget(optionLOCAL);
  thirdLayout->addWidget(optionFORUPGRADE);
  thirdLayout->addWidget(optionQUICK);
  thirdLayout->addWidget(optionFAST);
  thirdLayout->addWidget(optionMEDIUM);
  thirdLayout->addWidget(optionEXTENDED);
  thirdLayout->addWidget(optionCHANGED);
  thirdLayout->addWidget(optionUSE_FRM);

  QFrame* sepatatorFrame = new QFrame();
  sepatatorFrame->setFrameShape(QFrame::HLine);
  thirdLayout->addWidget(sepatatorFrame);
  clearSelectionPushButton = new QPushButton;
  connect(clearSelectionPushButton, SIGNAL(clicked()), this, SLOT(clearSelectionPushButtonSlot()));
  thirdLayout->addWidget(clearSelectionPushButton);

  selectAllTablesPushButton = new QPushButton;
  connect(selectAllTablesPushButton, SIGNAL(clicked()), this, SLOT(selectAllTablesPushButtonSlot()));
  thirdLayout->addWidget(selectAllTablesPushButton);

  selectAllLocalTablesPushButton = new QPushButton;
  connect(selectAllLocalTablesPushButton, SIGNAL(clicked()), this, SLOT(selectAllLocalTablesPushButtonSlot()));
  thirdLayout->addWidget(selectAllLocalTablesPushButton);

  thirdLayout->addStretch();
  groupBoxAction->setLayout(thirdLayout);
  QHBoxLayout *secondLayout = new QHBoxLayout;
  tablesListWidget = new QTreeWidget;
  tablesListWidget->setFixedWidth(300);
  connect(tablesListWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  connect(tablesListWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  secondLayout->addWidget(tablesListWidget);
  secondLayout->addWidget(groupBoxAction);
  mainVLayout->addLayout(secondLayout);
  resultEditor = new BaseTextEditor(EditorTypes::NoEditor);
  resultEditor->setWordWrapMode(QTextOption::NoWrap);
  secondLayout->addWidget(resultEditor);
  retranslateUi();
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
  QTimer::singleShot(0, this, SLOT(fillDatabasesSlot()));
}

void TableMaintenance::retranslateUi()
{
  setWindowTitle(tr("Table Maintenance"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  groupBoxAction->setTitle(tr("Actions"));
  analyzePushButton->setText(tr("Analyze"));
  checkPushButton->setText(tr("Check"));
  checksumPushButton->setText(tr("Checksum"));
  optimizePushButton->setText(tr("Optimize"));
  repairPushButton->setText(tr("Repair"));
  tablesListWidget->setWindowTitle(tr("Databases"));
  tablesListWidget->setHeaderLabel(tablesListWidget->windowTitle());
  clearSelectionPushButton->setText(tr("Clear selection"));
  selectAllTablesPushButton->setText(tr("Select all"));
  selectAllLocalTablesPushButton->setText(tr("Select local tables"));
}

QString TableMaintenance::tableList()
{
  QString tablesToCheck;
  foreach (QTreeWidgetItem *item, tables)
    if (item->checkState(0) == Qt::Checked && item->parent())
      tablesToCheck += item->text(0) + ", ";
  return tablesToCheck.mid(0, tablesToCheck.length() - 2);
}

void TableMaintenance::executeStatement(const QString statement)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  resultEditor->setPlainText(serverConnection->outputAsTable(statement));
  QApplication::restoreOverrideCursor();
}

void TableMaintenance::fillDatabasesSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
//  foreach (QString database, serverConnection->getDatabases()) {
//    QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), database);
//    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
////    item->setCheckState(Qt::Unchecked);
//    tablesListWidget->addItem(item);
//    foreach (QString table, serverConnection->database(database)->getTables()) {
//      QListWidgetItem *childItem = new QListWidgetItem(QIcon(":/images/svg/table.svg"), table);
//      childItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
////      childItem->setCheckState(Qt::Unchecked);
//      tablesListWidget->addItem(childItem);
//    }
//  }
  tables.clear();
  QTreeWidgetItem *item;
  QStringList databases = serverConnection->getDatabases(true);
  int counter = 0;
  emit loadProgress(0);
  foreach (QString database, databases) {
    item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(database), ItemTypes::Database);
    item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item->setCheckState(0, Qt::Unchecked);
    tables.append(item);
    emit loadProgress((int) (counter * 100 / databases.count()));
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
  tablesListWidget->resizeColumnToContents(0);
  emit loadProgress(100);
  QApplication::restoreOverrideCursor();
}

void TableMaintenance::analyzePushButtonSlot()
{
  QString statement("ANALYZE ");
  statement += (optionLOCAL->isChecked() ? "LOCAL" : "");
  statement += " TABLE " + tableList();
  executeStatement(statement);
}

void TableMaintenance::checkPushButtonSlot()
{
  QString statement("CHECK TABLE " + tableList());
  statement += (optionFORUPGRADE->isChecked() ? " FOR UPGRADE" : "");
  statement += (optionQUICK->isChecked() ? " QUICK" : "");
  statement += (optionFAST->isChecked() ? " FAST" : "");
  statement += (optionMEDIUM->isChecked() ? " MEDIUM" : "");
  statement += (optionEXTENDED->isChecked() ? " EXTENDED" : "");
  statement += (optionCHANGED->isChecked() ? " CHANGED" : "");
  executeStatement(statement);
}

void TableMaintenance::checksumPushButtonSlot()
{
  QString statement("CHECKSUM TABLE " + tableList());
  statement += (optionQUICK->isChecked() ? " QUICK" : "");
  statement += (optionEXTENDED->isChecked() ? " EXTENDED" : "");
  executeStatement(statement);
}

void TableMaintenance::optimizePushButtonSlot()
{
  QString statement("OPTIMIZE ");
  statement += (optionLOCAL->isChecked() ? "LOCAL" : "");
  statement += " TABLE " + tableList();
  executeStatement(statement);
}

void TableMaintenance::repairPushButtonSlot()
{
  QString statement("REPAIR ");
  statement += (optionLOCAL->isChecked() ? "LOCAL" : "");
  statement += " TABLE " + tableList();
  statement += (optionQUICK->isChecked() ? " QUICK" : "");
  statement += (optionEXTENDED->isChecked() ? " EXTENDED" : "");
  statement += (optionUSE_FRM->isChecked() ? " USE_FRM" : "");
  executeStatement(statement);
}

void TableMaintenance::itemActivatedSlot(QTreeWidgetItem *item, int column)
{
  if (item->type() == ItemTypes::Database) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QTreeWidgetItem *itemChild;
    int counter = 0;
    emit loadProgress(0);
    foreach (QTreeWidgetItem *tableItem, tables) {
      if (tableItem->parent() == item)
        tableItem->setCheckState(column, item->checkState(column));
      emit loadProgress((int) (counter * 100 / tables.count()));
      counter++;
    }
    if (item->childCount() == 0) {
      QStringList databaseTables;
      if (selectAllLocalTables)
        databaseTables = serverConnection->database(item->text(0))->getLocalTables();
      else
        databaseTables = serverConnection->database(item->text(0))->getTables();
      counter = 0;
      foreach (QString table, databaseTables) {
        itemChild = new QTreeWidgetItem(item, QStringList("`" + item->text(0) + "`.`" + table + "`"), ItemTypes::Table);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        tables.append(itemChild);
        emit loadProgress((int) (counter * 100 / databaseTables.count()));
      }
    }
    emit loadProgress(100);
    QApplication::restoreOverrideCursor();
  }
}

void TableMaintenance::clearSelectionPushButtonSlot()
{
//  foreach (QTreeWidgetItem *item, tables)
//    if (item->isSelected())
//      item->setSelected(false);

  /**
    The code above does not clear the selection, so, I fill it againg.
    */
  fillDatabasesSlot();
  optionLOCAL->setChecked(false);

  optionFORUPGRADE->setAutoExclusive(false);
  optionQUICK->setAutoExclusive(false);
  optionFAST->setAutoExclusive(false);
  optionMEDIUM->setAutoExclusive(false);
  optionEXTENDED->setAutoExclusive(false);
  optionCHANGED->setAutoExclusive(false);
  optionUSE_FRM->setAutoExclusive(false);

  optionFORUPGRADE->setChecked(false);
  optionQUICK->setChecked(false);
  optionFAST->setChecked(false);
  optionMEDIUM->setChecked(false);
  optionEXTENDED->setChecked(false);
  optionCHANGED->setChecked(false);
  optionUSE_FRM->setChecked(false);

  optionFORUPGRADE->setAutoExclusive(true);
  optionQUICK->setAutoExclusive(true);
  optionFAST->setAutoExclusive(true);
  optionMEDIUM->setAutoExclusive(true);
  optionEXTENDED->setAutoExclusive(true);
  optionCHANGED->setAutoExclusive(true);
  optionUSE_FRM->setAutoExclusive(true);
}

void TableMaintenance::selectAllTablesPushButtonSlot()
{
  QTreeWidgetItemIterator it(tablesListWidget);
  while (*it) {
    if ((*it)->type() == ItemTypes::Database)
      (*it)->setCheckState(0, Qt::Checked);
    ++it;
  }
}

void TableMaintenance::selectAllLocalTablesPushButtonSlot()
{
  selectAllLocalTables = true;
  selectAllTablesPushButtonSlot();
  selectAllLocalTables = false;
}

//TableMaintenanceWizard::TableMaintenanceWizard()
//{
//  parentWidget = parent;
//  setWindowTitle(tr("Table Maintenance"));
//  setObjectName(windowTitle());
//  setAttribute(Qt::WA_DeleteOnClose);
//  setPage(Intro_Page, new IntroPageTableMaintenance());
//  selectDatabases = new SelectDatabase(parentWidget);
//  setPage(SelectDatabase_Page, selectDatabases);
//  selectTables = new SelectTables(parentWidget);
//  setPage(SelectTables_Page, selectTables);
////  outputTypeSelection = new OutputTypeSelection();
////  setPage(OutputTypeSelection_Page, outputTypeSelection);
//  setOption(QWizard::HaveHelpButton, true);
//  setPixmap(QWizard::LogoPixmap, QPixmap(":/images/svg/server-database.svg"));
//  setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/svg/server-database.svg"));
////  connect(this, SIGNAL(accepted()), this, SLOT(generateMetadata()));
//}

//SelectDatabase::SelectDatabase()
//{
//  setTitle(tr("Select the database"));
//  setSubTitle(tr("Subtitle for database"));
//  QVBoxLayout *mainLayout = new QVBoxLayout(this);
//  foreach (const QString &database, parent->serverConnection->getDatabases()) {
//    QCheckBox *item = new QCheckBox(database);
//    registerField(database, item);
//    mainLayout->addWidget(item);
//  }
//  mainLayout->setMargin(0);
//}

//IntroPageTableMaintenance::IntroPageTableMaintenance()
//{
//  setTitle(tr("Intro Page"));
//  setSubTitle(tr("Subtitle"));
//  QVBoxLayout *mainLayout = new QVBoxLayout(this);
//  QLabel *label = new QLabel(tr("Write the maintenance propuese here..."), this);
//  label->setWordWrap(true);
//  mainLayout->addWidget(label);
//}

//SelectTables::SelectTables()
//{
//  parentWidget = parent;
//  setTitle(tr("Select the table(s)"));
//  setSubTitle(tr("Subtitle for tables"));
//}

//void SelectTables::initializePage()
//{
////  databases = "";
////  foreach (QString database, serverConnection->getDatabases())
////    if (field(database).toBool())
////      databases += "'" + database + "', ";
////  databases = databases.mid(0, databases.length() - 2);
////  QStringList rows;
////  rows = serverConnection->runQuerySingleColumn("SELECT CONCAT('`', `TABLE_SCHEMA`, '`.`', `TABLE_NAME`, '`')"
////                                                              " FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` IN (" + databases + ")");
////  QVBoxLayout *mainLayout = new QVBoxLayout(this);
////  foreach (const QString &table, rows) {
////    QCheckBox *item = new QCheckBox(table);
////    registerField(table, item);
////    mainLayout->addWidget(item);
////  }
////  mainLayout->setMargin(0);
//}
