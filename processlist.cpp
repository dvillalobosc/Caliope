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

#include <QLabel>
#include <QVBoxLayout>
#include <QAction>
#include <QTimer>
#include <QMenu>
#include <QContextMenuEvent>
#include <QApplication>
#include <QGroupBox>
#include <QPushButton>
#include <QPushButton>

#include "processlist.h"
#include "dtitlelabel.h"
#include "dtableview.h"
#include "staticfunctions.h"

#include "QDebug"

ProcessList::ProcessList(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));

  /**
  * Pending translation
  */
  QList<QStringList> *headers = new QList<QStringList>;
  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
    headers->append(QStringList() << tr("Id") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("User") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Host") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Database") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Command") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Time") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("State") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Info") << "NoDelegate"  << "" << "Left");
    break;
  case StaticFunctions::MariaDB:
    headers->append(QStringList() << tr("Id") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("User") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Host") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Database") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Command") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Time") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("State") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Info") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Milliseconds") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Stage") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Max Stage") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Progress") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Memory") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Examined Rows") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Query Id") << "NoDelegate"  << "" << "Left");
    break;
  case StaticFunctions::PostgreSQL:
    headers->append(QStringList() << tr("DatId") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("DatName") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("ProcPid") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("UseName") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Current Query") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Waiting") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Xact Start") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Query Start") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Backend Start") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Client Addr") << "NoDelegate"  << "" << "Left");
    headers->append(QStringList() << tr("Client Port") << "NoDelegate"  << "" << "Left");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }

  timerRefresh = new QTimer(this);
  connect(timerRefresh, SIGNAL(timeout()), this, SLOT(reloadData()));
  timerRefresh->setInterval(1000);
  processTable = new DTableView(headers);
//  connect(processTable, SIGNAL(loadStarted(QString,uint,double)), parentWidget, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
//  connect(processTable, SIGNAL(loadFinished(QString,uint,double)), parentWidget, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
//  connect(processTable, SIGNAL(loadProgress(QString,uint,double)), parentWidget, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->setContentsMargins(0, 0, 0, 0);
  dTitleLabel = new DTitleLabel;
  mainLayout->addWidget(dTitleLabel);
  buttonGroup = new QGroupBox(this);
  QHBoxLayout *groupBoxHLayout = new QHBoxLayout;
  pushButtonStopRefreshing = new QPushButton;
  pushButtonStopRefreshing->setIcon(QIcon::fromTheme("process-stop", QIcon(":/images/svg/process-stop-7.svg")));
  pushButtonStopRefreshing->setCheckable(true);
  pushButtonStopRefreshing->setChecked(false);
  connect(pushButtonStopRefreshing, SIGNAL(toggled(bool)), timerRefresh, SLOT(start()));
  groupBoxHLayout->addWidget(pushButtonStopRefreshing);
  groupBoxHLayout->addStretch(1);
  buttonGroup->setLayout(groupBoxHLayout);
  mainLayout->addWidget(buttonGroup);
  mainLayout->addWidget(processTable);
  mainLayout->setMargin(0);
  QWidget *widMain = new QWidget;
  widMain->setLayout(mainLayout);
  killThread = new QAction(this);
  killThread->setIcon(QIcon::fromTheme("dialog-close", QIcon(":/images/svg/document-close-4.svg")));
  connect(killThread, SIGNAL(triggered()), this, SLOT(killThreadSlot()));
  menu = new QMenu(this);
  menu->addAction(killThread);
  timerRefresh->start();
  retranslateUi();
  setWidget(widMain);
}

void ProcessList::retranslateUi()
{
  setWindowTitle(tr("Process List"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  buttonGroup->setTitle(tr("Actions"));
  pushButtonStopRefreshing->setText(tr("Stop refreshing"));
  killThread->setText(tr("Kill thread"));
}

void ProcessList::killThreadSlot()
{
  serverConnection->runQuery(QString("KILL CONNECTION %1").arg(killThread->text().split(": ").at(1)));
}

void ProcessList::reloadData()
{
  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
    result = serverConnection->runQuery("SELECT '', `ID`, `USER`, `HOST`, `DB`, `COMMAND`, `TIME`, `STATE`, `INFO` FROM `information_schema`.`PROCESSLIST`");
    break;
  case StaticFunctions::MariaDB:
    result = serverConnection->runQuery("SELECT '', `ID`, `USER`, `HOST`, `DB`, `COMMAND`, `TIME`, `STATE`, `INFO`, `TIME_MS`, `STAGE`, `MAX_STAGE`, `PROGRESS`, `MEMORY_USED`, `EXAMINED_ROWS`, `QUERY_ID` FROM `information_schema`.`PROCESSLIST`");
    break;
  case StaticFunctions::PostgreSQL:
    result = serverConnection->runQuery("SELECT '', datid, datname, procpid, usename, current_query, waiting, xact_start, query_start, backend_start, client_addr, client_port FROM pg_stat_activity");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  result->takeLast(); //Remove the "Affected rows" line.
  if (result->count() > 0)
    processTable->setModelData(result);
  if (pushButtonStopRefreshing->isChecked())
    timerRefresh->stop();
}

void ProcessList::contextMenuEvent(QContextMenuEvent *event)
{
  killThread->setText(tr("Kill thread: %1").arg(processTable->indexData(processTable->currentIndexItem().row(), 0, Qt::DisplayRole).toString()));
  menu->exec(event->globalPos());
}
