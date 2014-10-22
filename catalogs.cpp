/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2014 David Villalobos Cambronero (dvillalobosc@yahoo.com).
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

#include <QTabWidget>
#include <QApplication>
#include <QToolBar>
#include <QVBoxLayout>
#include <QAction>
#include <QComboBox>
#include <QMenu>
#include <QSplitter>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QTimer>
#include <QStandardItemModel>
#include <QStandardItem>

#include "catalogs.h"
#include "dtitlelabel.h"
#include "newdatabase.h"
#include "texteditor.h"
#include "basetexteditor.h"
#include "dtableview.h"
#include "staticfunctions.h"
#include "projects.h"

#include "QDebug"

Catalogs::Catalogs(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  readOnly = true;
  result = new QList<QStringList>;
  dTitleLabel = new DTitleLabel;
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  mainVLayout->addWidget(dTitleLabel);

  catalogsTab = new QTabWidget;
  catalogsTab->setMovable(true);

  /**
  * Pending translation
  */
  QString NoDelegate = StaticFunctions::DelegateTypeNoDelegate();
  QList<QStringList> *tablesDTableViewHeaders = new QList<QStringList>;
  tablesDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate  << ":/images/svg/table.svg" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Engine") << (StaticFunctions::DelegateTypeEnum() + "(" +
                                                                    serverConnection->getEngines().join(",") + ")")
                                  << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Version") << NoDelegate << "" << "Right");
  tablesDTableViewHeaders->append(QStringList() << tr("Row format") << NoDelegate << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Rows") << NoDelegate << "" << "Right");
  tablesDTableViewHeaders->append(QStringList() << tr("Row length") << NoDelegate << "" << "ToBytes");
  tablesDTableViewHeaders->append(QStringList() << tr("Data length") << NoDelegate << "" << "ToBytes");
  tablesDTableViewHeaders->append(QStringList() << tr("Max data length") << NoDelegate << "" << "ToBytes");
  tablesDTableViewHeaders->append(QStringList() << tr("Index length") << NoDelegate << "" << "ToBytes");
  tablesDTableViewHeaders->append(QStringList() << tr("Data free") << NoDelegate << "" << "ToBytes");
  tablesDTableViewHeaders->append(QStringList() << tr("Autoincrement") << NoDelegate << "" << "Right");
  tablesDTableViewHeaders->append(QStringList() << tr("Creation time") << NoDelegate << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Update time") << NoDelegate << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Check time") << NoDelegate << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Collation") << (StaticFunctions::DelegateTypeEnum() + "(" +
                                                                       serverConnection->getCollations().join(",") + ")")
                                  << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Checksum") << NoDelegate << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Options") << NoDelegate << "" << "Left");
  tablesDTableViewHeaders->append(QStringList() << tr("Comment") << NoDelegate << "" << "Left");
  tablesDTableView = new DTableView(tablesDTableViewHeaders);
  connect(tablesDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(tablesDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(tablesDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(tablesDTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(tablesClicked(QModelIndex)));
  connect(tablesDTableView, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(tablesItemChangedSlot(QStandardItem*)));
  catalogsTab->addTab(tablesDTableView, QIcon(":/images/svg/table.svg"), tr("Tables"));

  QList<QStringList> *viewsDTableViewHeaders = new QList<QStringList>;
  viewsDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << ":/images/svg/view.svg" << "Left");
  viewsDTableViewHeaders->append(QStringList() << tr("Updatable") << NoDelegate << "" << "Left");
  viewsDTableViewHeaders->append(QStringList() << tr("Definer") << NoDelegate << "" << "Left");
  viewsDTableViewHeaders->append(QStringList() << tr("Security") << NoDelegate << "" << "Left");
  viewsDTableViewHeaders->append(QStringList() << tr("Check") << NoDelegate << "" << "Left");
  viewsDTableViewHeaders->append(QStringList() << tr("Charset") << NoDelegate << "" << "Left");
  viewsDTableViewHeaders->append(QStringList() << tr("Collation") << NoDelegate << "" << "Left");
  viewsDTableView = new DTableView(viewsDTableViewHeaders);
  connect(viewsDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(viewsDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(viewsDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(viewsDTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(viewsClicked(QModelIndex)));
  catalogsTab->addTab(viewsDTableView, QIcon(":/images/svg/view.svg"), tr("Views"));

  QList<QStringList> *indexesDTableViewHeaders = new QList<QStringList>;
  indexesDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << ":images/svg/server-database.svg" << "Left");
  indexesDTableViewHeaders->append(QStringList() << tr("Position") << NoDelegate << "" << "Right");
  indexesDTableViewHeaders->append(QStringList() << tr("Column") << NoDelegate << "" << "Left");
  indexesDTableViewHeaders->append(QStringList() << tr("Collation") << NoDelegate << "" << "Right");
  indexesDTableViewHeaders->append(QStringList() << tr("Cardinality") << NoDelegate << "" << "Left");
  indexesDTableViewHeaders->append(QStringList() << tr("Subpart") << NoDelegate << "" << "Right");
  indexesDTableViewHeaders->append(QStringList() << tr("Packed") << NoDelegate << "" << "Left");
  indexesDTableViewHeaders->append(QStringList() << tr("Null") << NoDelegate << "" << "Left");
  indexesDTableViewHeaders->append(QStringList() << tr("Type") << NoDelegate << "" << "Left");
  indexesDTableViewHeaders->append(QStringList() << tr("Comment") << NoDelegate << "" << "Left");
  indexesDTableView = new DTableView(indexesDTableViewHeaders);
  connect(indexesDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(indexesDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(indexesDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  catalogsTab->addTab(indexesDTableView, QIcon(":images/svg/server-database.svg"), tr("Indexes on: "));

  QList<QStringList> *fieldsDTableViewHeaders = new QList<QStringList>;
  fieldsDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << ":/images/svg/server-database.svg" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Position") << NoDelegate << "" << "Right");
  fieldsDTableViewHeaders->append(QStringList() << tr("Default") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Nullable") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Datatype") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Character max length") << NoDelegate << "" << "ToBytes");
  fieldsDTableViewHeaders->append(QStringList() << tr("Character octet length") << NoDelegate << "" << "ToBytes");
  fieldsDTableViewHeaders->append(QStringList() << tr("Numeric precision") << NoDelegate << "" << "Right");
  fieldsDTableViewHeaders->append(QStringList() << tr("Numeric scale") << NoDelegate << "" << "Right");
  fieldsDTableViewHeaders->append(QStringList() << tr("Charset") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Collation") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Type") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Key") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Extra") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Privileges") << NoDelegate << "" << "Left");
  fieldsDTableViewHeaders->append(QStringList() << tr("Comment") << NoDelegate << "" << "Left");
  fieldsDTableView = new DTableView(fieldsDTableViewHeaders);
  connect(fieldsDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(fieldsDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(fieldsDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  catalogsTab->addTab(fieldsDTableView, QIcon(":/images/svg/server-database.svg"), tr("Fields on: "));

  QList<QStringList> *routinesDTableViewHeaders = new QList<QStringList>;
  routinesDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << ":/images/svg/system-run-5.svg" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Type") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Returns") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Body") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("External name") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("External language") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Parameter style") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Is deterministic") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("SQL data access") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("SQL path") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Security type") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Created") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Last altered") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("SQL mode") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Comment") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Definer") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Charset") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Collation") << NoDelegate << "" << "Left");
  routinesDTableViewHeaders->append(QStringList() << tr("Database collation") << NoDelegate << "" << "Left");
  routinesDTableView = new DTableView(routinesDTableViewHeaders);
  connect(routinesDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(routinesDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(routinesDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(routinesDTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(routinesClicked(QModelIndex)));
  catalogsTab->addTab(routinesDTableView, QIcon(":/images/svg/system-run-5.svg"), tr("Routines"));

  QList<QStringList> *triggersDTableViewHeaders = new QList<QStringList>;
  triggersDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << ":/images/svg/server-database.svg" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Event manipulation") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Action order") << NoDelegate << "" << "Right");
  triggersDTableViewHeaders->append(QStringList() << tr("Action condition") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Acction orientation") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Action timing") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Created") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("SQL mode") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Definer") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Charset") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Collation") << NoDelegate << "" << "Left");
  triggersDTableViewHeaders->append(QStringList() << tr("Database collation") << NoDelegate << "" << "Left");
  triggersDTableView = new DTableView(triggersDTableViewHeaders);
  connect(triggersDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(triggersDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(triggersDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(triggersDTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(triggersClicked(QModelIndex)));
  catalogsTab->addTab(triggersDTableView, QIcon(":/images/svg/server-database.svg"), tr("Triggers"));

  QList<QStringList> *eventsDTableViewHeaders = new QList<QStringList>;
  eventsDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << ":/images/svg/view-calendar-upcoming-events.svg" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Definer") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Time zone") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Body") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Type") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Execute at") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Internal value") << NoDelegate << "" << "Right");
  eventsDTableViewHeaders->append(QStringList() << tr("Internal field") << NoDelegate << "" << "Right");
  eventsDTableViewHeaders->append(QStringList() << tr("SQL mode") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Starts") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Ends") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Status") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("On completion") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Created") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Last altered") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Last executed") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Comment") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Originator") << NoDelegate << "" << "Right");
  eventsDTableViewHeaders->append(QStringList() << tr("Charset") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Collation") << NoDelegate << "" << "Left");
  eventsDTableViewHeaders->append(QStringList() << tr("Database collation") << NoDelegate << "" << "Left");
  eventsDTableView = new DTableView(eventsDTableViewHeaders);
  connect(eventsDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(eventsDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(eventsDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(eventsDTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(eventsClicked(QModelIndex)));
  catalogsTab->addTab(eventsDTableView, QIcon::fromTheme("x-office-calendar", QIcon(":/images/svg/view-calendar-upcoming-events.svg")), tr("Events"));

  readOnlyEditor = new BaseTextEditor(EditorTypes::SQLQuery);

  QSplitter *mainSplitter = new QSplitter;
  mainSplitter->setOrientation(Qt::Vertical);
  mainSplitter->addWidget(catalogsTab);
  mainSplitter->addWidget(readOnlyEditor);
  mainVLayout->addWidget(mainSplitter);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
  QTimer::singleShot(0, this, SLOT(tablesInfo()));
  QTimer::singleShot(0, this, SLOT(viewsInfo()));
  QTimer::singleShot(0, this, SLOT(routinesInfo()));
  QTimer::singleShot(0, this, SLOT(eventsInfo()));
}

void Catalogs::retranslateUi()
{
  setTitle();
  catalogsTab->setWindowTitle(tr("Catalogs"));
  catalogsTab->setObjectName(windowTitle());
}

void Catalogs::tablesItemChangedSlot(QStandardItem *item)
{
  bool done = false;
  if (!readOnly) {
    switch(item->column()) {
    case 0:
      done = serverConnection->table(item->data(Qt::UserRole).toString())->renameTable(item->data(Qt::DisplayRole).toString());
      break;
    case 1:
      done = serverConnection->table(tablesDTableView->indexData(item->row(), 0, Qt::UserRole).toString())
          ->changeEngine(item->data(Qt::DisplayRole).toString());
      break;
    case 14:
      done = serverConnection->table(tablesDTableView->indexData(item->row(), 0, Qt::UserRole).toString())
          ->changeCollation(item->data(Qt::DisplayRole).toString());
      break;
    case 17:
      done = serverConnection->table(tablesDTableView->indexData(item->row(), 0, Qt::UserRole).toString())
          ->changeComment(item->data(Qt::DisplayRole).toString());
      break;
    default:
      emit statusBarMessagePopup(tr("The column %1 cannot be modified.").arg(tablesDTableView->getHeaders()->at(item->column()).at(0)));
      break;
    }
    if (done)
      emit statusBarMessagePopup(tr("Changes applied."));
    tablesInfo();
  } else {
    emit statusBarMessage(tr("Tables in Read-Only mode, no changes will be applied."), QSystemTrayIcon::Information);
  }
}

void Catalogs::statusBarProgressMessageSlot(const QString &message, const unsigned int timeout, const double progress)
{
  emit statusBarProgressMessage(message, timeout, progress);
}

void Catalogs::setTitle()
{
  setWindowTitle(tr("Catalogs in %1").arg(serverConnection->getDatabase()));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
}

QString Catalogs::valueToPopulate(QString dataType, unsigned int length)
{
  if (dataType.contains(QRegExp("(varchar|longtext|char|text|mediumblob|longblob|mediumtext|blob|tinyblob|binary|varbinary|tinytext)")))
    return "'" + StaticFunctions::randomString(length) + "'";
  if (dataType.contains(QRegExp("(datetime|timestamp)")))
    return "NOW()";
  if (dataType.contains(QRegExp("(date)")))
    return "DATE(NOW())";
  if (dataType.contains(QRegExp("(year)")))
    return "YEAR(NOW())";
  if (dataType.contains(QRegExp("(time)")))
    return "TIME(NOW())";
  if (dataType.contains(QRegExp("(set|enum)")))
    return "1";
  if (dataType.contains(QRegExp("(bigint|int|decimal|double|smallint|mediumint|tinyint|float|bit)")))
    return QString("%1").arg((qrand() % length) + 1);
  return QString();
}

void Catalogs::deleteObjectSlot()
{
  if (!readOnly) {
    switch (catalogsTab->currentIndex()) {
    case 0:
      deleteTables();
      break;
    case 1:
      deleteViews();
      break;
    case 2:
      deleteIndexes();
      break;
    case 3:
      deleteFields();
      break;
    case 4:
      deleteRoutines();
      break;
    // default: Q_ASSERT(false);
    }
    updateObjectInfo();
  }
}

void Catalogs::deleteRoutines()
{
  if (QMessageBox::question(this, tr("Routine deletion"),
                            tr("Do you really want to delete the routine?<BR />")
                            + "<B>" + routinesDTableView->indexData(routinesDTableView->currentIndex()
                                                                     , Qt::DisplayRole, 0).toString() + "</B>",
                            QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
    serverConnection->routine(routinesDTableView->indexData(routinesDTableView->currentIndex()
                                                                          , Qt::DisplayRole, 0).toString())->drop();
}

void Catalogs::deleteFields()
{
//  if (QMessageBox::question(this, tr("Field deletion"),
//                            tr("Do you really want to delete the field?<BR />")
//                            + "<B>" + fields->item(fields->currentRow(), 1)->text() + "</B>",
//                            QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
//    emit statusBarMessage(serverConnection->column()
//                                   ->dropField(fields->item(fields->currentRow(), 1)->text()
//                                               , tablesDTableView->item(tablesDTableView->currentRow(), 0)->text()));
}

void Catalogs::deleteIndexes()
{
//  if (QMessageBox::question(this, tr("Index deletion"),
//                            tr("Do you really want to delete the index?<BR />")
//                            + "<B>" + indexes->item(indexes->currentRow(), 0)->text() + "</B>",
//                            QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
//    emit statusBarMessage(serverConnection->index()
//                                   ->dropIndex(indexes->item(indexes->currentRow(), 0)->text()
//                                               , tablesDTableView->item(tablesDTableView->currentRow(), 0)->text()));
}

void Catalogs::deleteTables()
{
//  QStringList objectsToDelete;
//  QString items;
//  foreach (QTableWidgetItem *item, tablesDTableView->selectedItems())
//    if (item->column() == 0) {
//      objectsToDelete.append(item->text());
//      items += item->text() + ", ";
//    }
//  if (QMessageBox::question(this, tr("Table deletion"),
//                            tr("Do you really want to delete the table(s)?<BR />")
//                            + "<B>" + QString(items).mid(0, items.size() - 2) + "</B>",
//                            QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
//    emit statusBarMessage(serverConnection->table()->dropTables(objectsToDelete, true));
}

void Catalogs::deleteViews()
{
//  QStringList objectsToDelete;
//  QString items;
//  foreach (QTableWidgetItem *item, views->selectedItems())
//    if (item->column() == 0) {
//      objectsToDelete.append(item->text());
//      items += item->text() + ", ";
//    }
//  if (QMessageBox::question(this, tr("View deletion"),
//                            tr("Do you really want to delete the view(s)?<BR />")
//                            + "<B>" + QString(items).mid(0, items.size() - 2) + "</B>",
//                            QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Ok)
//    emit statusBarMessage(serverConnection->view()->dropViews(objectsToDelete, true));
}

void Catalogs::newDatabaseActionTriggered()
{
  if (!readOnly) {
    newDatabase = new NewDatabase(serverConnection);
    newDatabase->exec();
  }
}

void Catalogs::deleteDatabaseActionTriggered()
{
  if (!readOnly) {
    serverConnection->database(QInputDialog::getItem(this, tr("Delete a database")
                                                                   , tr("Select a database to delete:")
                                                                   , serverConnection->getDatabases()
                                                                   , serverConnection->getDatabases()
                                                                   .indexOf(QRegExp("^" + serverConnection->getDatabase() + "$"))
                                                                   , false))->drop();
    switch(qApp->property("DBMSType").toInt()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->changeDatabase("mysql");
      break;
    case StaticFunctions::PostgreSQL:
      serverConnection->changeDatabase("postgres");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }

  }
}

void Catalogs::setReadOnly(bool readOnly)
{
  this->readOnly = readOnly;
  tablesInfo();
}

void Catalogs::populateTableActionTriggered()
{
  if (!tablesDTableView->indexData(tablesDTableView->currentIndex().row(), 0).toString().isEmpty()) {
    int count = QInputDialog::getInt(this, tr("Rows to be inserted"), tr("Rows to be inserted"));
    emit loadStarted(tr("Inserting records..."), 2000, 0);
    result = serverConnection->runQuery("SELECT `COLUMN_NAME`, `DATA_TYPE`"
                                                      ", IF(`CHARACTER_MAXIMUM_LENGTH` IS NOT NULL, `CHARACTER_MAXIMUM_LENGTH`, `NUMERIC_PRECISION`)"
                                                      " FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '" + serverConnection->getDatabase()
                                                      + "' AND `TABLE_NAME` = '" + tablesDTableView->indexData(tablesDTableView->currentIndex().row(), 0).toString() + "'");
    result->takeLast(); //Remove the "Affected rows" line.
    QString query;
    QString fields;
    QString values;
    for (int counter = 0; counter < result->count(); counter++)
      fields +=  "`" + result->at(counter).at(0) + "`, ";
    for (int rows = 0; rows < count; rows++) {
      values = "";
      for (int counter = 0; counter < result->count(); counter++)
        values +=  valueToPopulate(result->at(counter).at(1), result->at(counter).at(2).toUInt()) + ", ";
      query = QString("INSERT IGNORE INTO `%1`.`%2` (%3) VALUES (%4)")
          .arg(serverConnection->getDatabase())
          .arg(tablesDTableView->indexData(tablesDTableView->currentIndex().row(), 0).toString())
          .arg(fields.mid(0, fields.length() - 2))
          .arg(values.mid(0, values.length() - 2));
      serverConnection->runQuery(query);
      emit loadProgress(tr("Inserting records..."), 2000, rows * 100 / count);
    }
    emit loadStarted(tr("Records inserted."), 2000, 100);
  }
}

void Catalogs::newObjectSlot()
{
  if (!readOnly) {
    switch (catalogsTab->currentIndex()) {
    case 0:
      itemEditor = new ItemEditor(serverConnection, tr("New table"), ItemEditorTypes::Table);
      break;
    case 1:
      itemEditor = new ItemEditor(serverConnection, tr("New view"), ItemEditorTypes::View);
      break;
    case 2:
      itemEditor = new ItemEditor(serverConnection, tr("New index"), ItemEditorTypes::Index);
      break;
    case 3:
      itemEditor = new ItemEditor(serverConnection, tr("New field"), ItemEditorTypes::Field);
      break;
    case 4:
      itemEditor = new ItemEditor(serverConnection, tr("New routine"), ItemEditorTypes::Routine);
      break;
    case 5:
      itemEditor = new ItemEditor(serverConnection, tr("New trigger"), ItemEditorTypes::Trigger);
      break;
    case 6:
      itemEditor = new ItemEditor(serverConnection, tr("New event"), ItemEditorTypes::Event);
      break;
    // default: Q_ASSERT(false);
    }
    itemEditor->exec();
    updateObjectInfo();
  }
}

void Catalogs::editObjectSlot()
{
//  if (!readOnly) {
//    switch (catalogsTab->currentIndex()) {
//    case 0:
//    case 2:
//    case 3:
//      itemEditor = new ItemEditor(parentWidget, tr("Edit table"), ItemEditorTypes::Table);
////      itemEditor->editor->insertPlainText(serverConnection->getTableDefinition(
////                                                        tablesDTableView->item(tablesDTableView->currentRow(), 0)->text()
////                                                        , serverConnection->getDatabase()));
//      itemEditor->editor->insertPlainText("");
//      break;
//    case 1:
//      itemEditor = new ItemEditor(parentWidget, tr("Edit view"), ItemEditorTypes::View);
//      itemEditor->editor->insertPlainText("");
////      itemEditor->editor->insertPlainText(serverConnection->getViewDefinition(
////                                                        views->item(tables->currentRow(), 0)->text()
////                                                        , serverConnection->getDatabase()));
//      break;
//    case 4:
//      itemEditor = new ItemEditor(parentWidget, tr("Edit routine"), ItemEditorTypes::Routine);
//      itemEditor->editor->insertPlainText("");
////      itemEditor->editor->insertPlainText(serverConnection->getRoutineDefinition(
////                                                        routinesDTableView->item(routinesDTableView->currentRow(), 1)->text()
////                                                        , serverConnection->getDatabase()));
//      break;
//    case 5:
//      itemEditor = new ItemEditor(parentWidget, tr("Edit trigger"), ItemEditorTypes::Trigger);
//      itemEditor->editor->insertPlainText("");
////      itemEditor->editor->insertPlainText(serverConnection->getTriggeredefinition(
////                                                        triggersDTableView->item(triggersDTableView->currentRow(), 0)->text()
////                                                        , serverConnection->getDatabase()));
//      break;
//    case 6:
//      itemEditor = new ItemEditor(parentWidget, tr("Edit event"), ItemEditorTypes::Event);
//      itemEditor->editor->insertPlainText("");
////      itemEditor->editor->insertPlainText(serverConnection->getEventDefinition(
////                                                        eventsDTableView->item(eventsDTableView->currentRow(), 0)->text()
////                                                        , serverConnection->getDatabase()));
//      break;
//    // default: Q_ASSERT(false);
//    }
//    itemEditor->exec();
//    updateObjectInfo();
//  }
}

void Catalogs::updateObjectInfo()
{
  readOnlyEditor->clear();
  setTitle();
  switch (catalogsTab->currentIndex()) {
  case 0:
    tablesInfo();
    break;
  case 1:
    viewsInfo();
    break;
  case 4:
    routinesInfo();
    break;
  case 6:
    eventsInfo();
    break;
  // default: Q_ASSERT(false);
  }
}

void Catalogs::tablesClicked(QModelIndex modelIndex)
{
  if (lastRow != modelIndex.row()) {
    QString table(tablesDTableView->indexData(modelIndex, Qt::DisplayRole, 0).toString());
    readOnlyEditor->setPlainText(serverConnection->table(table)->getDefinition());
    indexesInfo(table);
    catalogsTab->setTabText(catalogsTab->indexOf(indexesDTableView), tr("Indexes on: %1").arg(table));
    fieldsInfo(table);
    catalogsTab->setTabText(catalogsTab->indexOf(fieldsDTableView), tr("Fields on: %1").arg(table));
    triggersInfo(table);
    catalogsTab->setTabText(catalogsTab->indexOf(triggersDTableView), tr("Triggers on: %1").arg(table));
    lastRow = modelIndex.row();
  }
}

void Catalogs::viewsClicked(QModelIndex modelIndex)
{
  readOnlyEditor->setPlainText(serverConnection->view(viewsDTableView->indexData(modelIndex, Qt::DisplayRole, 0).toString())
                               ->getDefinition());
}

void Catalogs::routinesClicked(QModelIndex modelIndex)
{
  readOnlyEditor->setPlainText(serverConnection->routine(
                                 routinesDTableView->indexData(modelIndex, Qt::DisplayRole, 0).toString())->getDefinition());
}

void Catalogs::triggersClicked(QModelIndex modelIndex)
{
  readOnlyEditor->setPlainText(serverConnection->getTriggeredefinition(
                                 triggersDTableView->indexData(modelIndex, Qt::DisplayRole, 0).toString()
                                 , serverConnection->getDatabase()));
}

void Catalogs::eventsClicked(QModelIndex modelIndex)
{
  readOnlyEditor->setPlainText(serverConnection->event(eventsDTableView->indexData(modelIndex, Qt::DisplayRole, 0)
                                                                     .toString())->getDefinition());
}

void Catalogs::tablesInfo()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  result = serverConnection->runQuery("SELECT ':/images/svg/table.svg', `TABLE_NAME`, `ENGINE`, `VERSION`, `ROW_FORMAT`"
                                                    ", FORMAT(`TABLE_ROWS`, 0), FORMAT(`AVG_ROW_LENGTH`, 0), FORMAT(`DATA_LENGTH`, 0), FORMAT(`MAX_DATA_LENGTH`, 0)"
                                                    ", FORMAT(`INDEX_LENGTH`, 0), FORMAT(`DATA_FREE`, 0), FORMAT(`AUTO_INCREMENT`, 0), `CREATE_TIME`"
                                                    ", `UPDATE_TIME`, `CHECK_TIME`, `TABLE_COLLATION`, `CHECKSUM`"
                                                    ", `CREATE_OPTIONS`, `TABLE_COMMENT` FROM"
                                                    " `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = '"
                                                    + serverConnection->getDatabase() + "' AND "
                                                    "(`TABLE_TYPE` = 'BASE TABLE' OR `TABLE_TYPE` = 'SYSTEM VIEW')");
  result->takeLast(); //Remove the "Affected rows" line.
  tablesDTableView->setModelData(result, readOnly);
  QApplication::restoreOverrideCursor();
}

void Catalogs::viewsInfo()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  if (!serverConnection->oldVersion) {
    result = serverConnection->runQuery("SELECT ':/images/svg/view.svg', `TABLE_NAME`, `IS_UPDATABLE`, `DEFINER`, `SECURITY_TYPE`"
                                                      ", `CHECK_OPTION`, `CHARACTER_SET_CLIENT`, `COLLATION_CONNECTION`"
                                                      " FROM `information_schema`.`VIEWS` WHERE `TABLE_SCHEMA` = '"
                                                      + serverConnection->getDatabase()
                                                      + "' ORDER BY `TABLE_NAME`");
  } else {
    result = serverConnection->runQuery("SELECT '', `TABLE_NAME`, `IS_UPDATABLE`, `DEFINER`, `SECURITY_TYPE`"
                                                      ", `CHECK_OPTION` FROM `information_schema`.`VIEWS` WHERE"
                                                      " `TABLE_SCHEMA` = '" + serverConnection->getDatabase()
                                                      + "' ORDER BY `TABLE_NAME`");
  }
  result->takeLast(); //Remove the "Affected rows" line.
  viewsDTableView->setModelData(result);
  QApplication::restoreOverrideCursor();
}

void Catalogs::indexesInfo(QString table)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  result->clear();
  QList<QStringList> *rows = new QList<QStringList>();
  rows = serverConnection->table(table)->getIndexes();
  rows->takeLast(); //Remove the "Affected rows" line.
  QStringList newRow;
  for (int row = 0; row < rows->count(); row++) {
    newRow.append(rows->at(row).at(2) == "PRIMARY" ? ":/images/svg/application-pgp-keys.svg" : ":/images/svg/server-database.svg");
    for (int column = 0; column < rows->at(0).count(); column++)
      newRow.append(rows->at(row).at(column));
    result->append(newRow);
  }
  indexesDTableView->setModelData(result, true, 1);
  QApplication::restoreOverrideCursor();
}

void Catalogs::routinesInfo()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  if (!serverConnection->oldVersion) {
    result = serverConnection->runQuery("SELECT ':/images/svg/system-run-5.svg', `ROUTINE_NAME`, `ROUTINE_TYPE`, `DTD_IDENTIFIER`, `ROUTINE_BODY`"
                                                      ", `EXTERNAL_NAME`, `EXTERNAL_LANGUAGE`, `PARAMETER_STYLE`, `IS_DETERMINISTIC`"
                                                      ", `SQL_DATA_ACCESS`, `SQL_PATH`, `SECURITY_TYPE`, `CREATED`, `LAST_ALTERED`, `SQL_MODE`"
                                                      ", `ROUTINE_COMMENT`, `DEFINER`, `CHARACTER_SET_CLIENT`, `COLLATION_CONNECTION`"
                                                      ", `DATABASE_COLLATION` FROM `information_schema`.`ROUTINES` WHERE `ROUTINE_SCHEMA` ="
                                                      " '" + serverConnection->getDatabase() + "' ORDER BY `ROUTINE_NAME`");
  } else {
    result = serverConnection->runQuery("SELECT ':/images/svg/system-run-5.svg', `ROUTINE_NAME`, `ROUTINE_TYPE`, `DTD_IDENTIFIER`, `ROUTINE_BODY`"
                                                      ", `EXTERNAL_NAME`, `EXTERNAL_LANGUAGE`, `PARAMETER_STYLE`, `IS_DETERMINISTIC`"
                                                      ", `SQL_DATA_ACCESS`, `SQL_PATH`, `SECURITY_TYPE`, `CREATED`, `LAST_ALTERED`, `SQL_MODE`"
                                                      ", `ROUTINE_COMMENT`, `DEFINER` FROM `information_schema`.`ROUTINES` WHERE `ROUTINE_SCHEMA` ="
                                                      " '" + serverConnection->getDatabase() + "' ORDER BY `ROUTINE_NAME`");
  }
  result->takeLast(); //Remove the "Affected rows" line.
  routinesDTableView->setModelData(result);
  QApplication::restoreOverrideCursor();
}

void Catalogs::fieldsInfo(QString table)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  result = serverConnection->runQuery("SELECT IF(`COLUMN_KEY` = 'PRI', ':/images/svg/application-pgp-keys.svg', ':/images/svg/server-database.svg'), `COLUMN_NAME`, `ORDINAL_POSITION`, `COLUMN_DEFAULT`,"
                                                    " `IS_NULLABLE`, `DATA_TYPE`, `CHARACTER_MAXIMUM_LENGTH`,"
                                                    " `CHARACTER_OCTET_LENGTH`, `NUMERIC_PRECISION`, `NUMERIC_SCALE`"
                                                    ", `CHARACTER_SET_NAME`, `COLLATION_NAME`, `COLUMN_TYPE`, `COLUMN_KEY`"
                                                    ", `EXTRA`, `PRIVILEGES`, `COLUMN_COMMENT` FROM `information_schema`.`COLUMNS`"
                                                    " WHERE `TABLE_NAME` = '" + table + "' AND `TABLE_SCHEMA` = '"
                                                    + serverConnection->getDatabase() + "'");
  result->takeLast(); //Remove the "Affected rows" line.
  fieldsDTableView->setModelData(result, true, 1);
  QApplication::restoreOverrideCursor();
}

void Catalogs::triggersInfo(QString table)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  if (!serverConnection->oldVersion) {
    result = serverConnection->runQuery("SELECT ':/images/svg/server-database.svg', `TRIGGER_NAME`, `EVENT_MANIPULATION`, `ACTION_ORDER`, `ACTION_CONDITION`"
                                                      ", `ACTION_ORIENTATION`, `ACTION_TIMING`, `CREATED`, `SQL_MODE`, `DEFINER`"
                                                      ", `CHARACTER_SET_CLIENT`, `COLLATION_CONNECTION`, `DATABASE_COLLATION`"
                                                      " FROM `information_schema`.`TRIGGERS` WHERE `EVENT_OBJECT_TABLE` = '"
                                                      + table + "' AND `EVENT_OBJECT_SCHEMA` = '" + serverConnection->getDatabase()
                                                      + "' ORDER BY `TRIGGER_NAME`");
  } else {
    result = serverConnection->runQuery("SELECT ':/images/svg/server-database.svg', `TRIGGER_NAME`, `EVENT_MANIPULATION`, `ACTION_ORDER`, `ACTION_CONDITION`"
                                                      ", `ACTION_ORIENTATION`, `ACTION_TIMING`, `CREATED`, `SQL_MODE`, `DEFINER`"
                                                      " FROM `information_schema`.`TRIGGERS` WHERE `EVENT_OBJECT_TABLE` = '"
                                                      + table + "' AND `EVENT_OBJECT_SCHEMA` = '" + serverConnection->getDatabase()
                                                      + "' ORDER BY `TRIGGER_NAME`");
  }
  result->takeLast(); //Remove the "Affected rows" line.
  triggersDTableView->setModelData(result);
  QApplication::restoreOverrideCursor();
}

void Catalogs::eventsInfo()
{
  if (serverConnection->oldVersion)
    return;
  QApplication::setOverrideCursor(Qt::WaitCursor);
  result = serverConnection->runQuery("SELECT ':/images/svg/view-calendar-upcoming-events.svg', `EVENT_NAME`, `DEFINER`, `TIME_ZONE`, `EVENT_BODY`, `EVENT_TYPE`, `EXECUTE_AT`"
                                                    ", `INTERVAL_VALUE`, `INTERVAL_FIELD`, `SQL_MODE`, `STARTS`, `ENDS`, `STATUS`"
                                                    ", `ON_COMPLETION`, `CREATED`, `LAST_ALTERED`, `LAST_EXECUTED`, `EVENT_COMMENT`"
                                                    ", `ORIGINATOR`, `CHARACTER_SET_CLIENT`, `COLLATION_CONNECTION`, `DATABASE_COLLATION`"
                                                    " FROM `information_schema`.`EVENTS` WHERE `EVENT_SCHEMA` = '"
                                                    + serverConnection->getDatabase() + "'");
  result->takeLast(); //Remove the "Affected rows" line.
  eventsDTableView->setModelData(result);
  QApplication::restoreOverrideCursor();
}

ItemEditor::ItemEditor(DBMS *serverConnection, QString title, ItemEditorTypes::ItemEditorType type)
{
  itemType = type;
  setWindowIcon(QIcon::fromTheme("document-new", QIcon(":/images/svg/document-new-6.svg")));
  setWindowTitle(title);
  setObjectName(windowTitle());
  resize(700, 400);
  setAttribute(Qt::WA_DeleteOnClose);
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->addWidget(new DTitleLabel(windowTitle()));
  editor = new TextEditor(new Projects, serverConnection, EditorTypes::SQLQuery);
  connect(editor, SIGNAL(openURL(QString)), this, SLOT(openURLSlot(QString)));
  ///connect(editor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), parent, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  //connect(editor, SIGNAL(updatePrositionViewer(int,int)), parentWidget->dStatusBar, SLOT(set)
  mainVLayout->addWidget(editor);
  QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Apply | QDialogButtonBox::Close
                                                     | QDialogButtonBox::Cancel | QDialogButtonBox::Help
                                                     | QDialogButtonBox::Reset);
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
  connect(buttonBox->button(QDialogButtonBox::Apply), SIGNAL(clicked()), this, SLOT(applyStatement()));
  connect(buttonBox->button(QDialogButtonBox::Help), SIGNAL(clicked()), this, SLOT(help()));
//  connect(buttonBox->button(QDialogButtonBox::Reset), SIGNAL(clicked()), editor->textEditor, SLOT(clear()));
  mainVLayout->addWidget(buttonBox);
  setLayout(mainVLayout);
}

void ItemEditor::applyStatement()
{
//  serverConnection->runQuery(editor->toPlainText());
}

void ItemEditor::help()
{
  QString helpText;

  switch (itemType) {
  case ItemEditorTypes::Table:
    helpText = "CREATE TABLE `NewTable` (\n  `Field01` VARCHAR(15) COLLATE utf8_spanish_ci NOT NULL,"
        "\n  `Field02` ENUM('Enum1', 'Enum2') COLLATE utf8_spanish_ci NOT NULL DEFAULT 'Enum1',"
        "\n  `Field03` DATE NOT NULL,\n  `Foto` BLOB,\n  `LastUpdate` TIMESTAMP NOT NULL DEFAULT"
        " CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,\n  PRIMARY KEY (`Field01`),\n  KEY `Idx_Apellido1`"
        " (`Field02`),\n) ENGINE = InnoDB DEFAULT CHARSET = utf8 COLLATE = utf8_spanish_ci COMMENT = 'Foo comment'\n";
    break;
  case ItemEditorTypes::View:
    helpText = "CREATE OR REPLACE VIEW `NewView` AS SELECT * FROM `mysql`.`user`;\n";
    break;
  case ItemEditorTypes::Index:
    helpText = "CREATE INDEX `NewIndex` (\n);\n";
    break;
  case ItemEditorTypes::Field:
    helpText = "CREATE TABLE `NewField` (\n);\n";
    break;
  case ItemEditorTypes::Routine:
    helpText = "CREATE {FUNCTION | PROCEDURE} `NewRoutine` (\n);\n";
    break;
  case ItemEditorTypes::Trigger:
    helpText = "CREATE TRIGGER `NewTrigger` (\n);\n";
    break;
  case ItemEditorTypes::Event:
    helpText = "CREATE EVENT `NewEvent` (\n);\n";
    break;
  // default: Q_ASSERT(false);
  }
  //  editor->insertPlainText(helpText);
}

void ItemEditor::openURLSlot(QString url)
{
  emit openURL(url);
}
