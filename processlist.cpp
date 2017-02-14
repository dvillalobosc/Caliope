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
#include <QSpinBox>

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
  switch(serverConnection->getDBMSType()) {
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
    headers->append(QStringList() << tr("Binary data information") << "NoDelegate"  << "" << "Left");
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
  pushButtonKillIdleThreads = new QPushButton(this);
  pushButtonKillIdleThreads->setIcon(QIcon::fromTheme("user-trash", QIcon(":/images/svg/user-trash.svg")));
  connect(pushButtonKillIdleThreads, SIGNAL(clicked()), this, SLOT(killIdleThreadsSlot()));
  groupBoxHLayout->addWidget(pushButtonKillIdleThreads);
  spinBoxTimeLimit = new QSpinBox;
  spinBoxTimeLimit->setRange(0, 2147483647);
  groupBoxHLayout->addWidget(spinBoxTimeLimit);
  spinBoxTimeLimit->setValue(settings.value("Processes/TimeToKillThreads", 30).toUInt());
  spinBoxRefreshRate = new QSpinBox;
  spinBoxRefreshRate->setRange(0, 2147483647);
  groupBoxHLayout->addWidget(spinBoxRefreshRate);
  spinBoxRefreshRate->setValue(settings.value("Processes/RefreshRate", 1).toUInt());
  connect(spinBoxRefreshRate, SIGNAL(valueChanged(int)), this, SLOT(refreshRateSlot(int)));
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
  killQuery = new QAction(this);
  killQuery->setIcon(QIcon::fromTheme("dialog-close", QIcon(":/images/svg/document-close-4.svg")));
  connect(killQuery, SIGNAL(triggered()), this, SLOT(killQuerySlot()));
  menu->addAction(killQuery);
  timerRefresh->setInterval(1000 * settings.value("Processes/RefreshRate", 1).toInt());
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
  killThread->setToolTip(tr("Kills the given thread."));
  pushButtonKillIdleThreads->setText(tr("Kill idle threads"));
  pushButtonKillIdleThreads->setToolTip(tr("Kills thread exeding the given seconds inactive."));
  spinBoxTimeLimit->setToolTip(tr("Time to kill threads."));
  spinBoxTimeLimit->setSuffix(" " + tr("seconds"));
  spinBoxRefreshRate->setToolTip(tr("Refresh rate."));
  spinBoxRefreshRate->setPrefix(tr("Refresh rate:") + " ");
  spinBoxRefreshRate->setSuffix(" " + tr("seconds"));
  killQuery->setText(tr("Kill query"));
  killQuery->setToolTip(tr("Kills the given query."));
}

void ProcessList::killThreadSlot()
{
  serverConnection->processes()->killThread(killThread->text().split(": ").at(1).toLongLong());
}

void ProcessList::killIdleThreadsSlot()
{
  settings.setValue("Processes/TimeToKillThreads", spinBoxTimeLimit->value());
  serverConnection->processes()->killIdleThreads(spinBoxTimeLimit->value());
}

void ProcessList::refreshRateSlot(const int value)
{
  timerRefresh->setInterval(1000 * value);
  settings.setValue("Processes/RefreshRate", value);
}

void ProcessList::killQuerySlot()
{
  serverConnection->processes()->killQuery(killQuery->text().split(": ").at(1).toLongLong());
}

void ProcessList::reloadData()
{
  result = serverConnection->processes()->getProcessList();
  if (result->count() > 0)
    processTable->setModelData(result);
  if (pushButtonStopRefreshing->isChecked())
    timerRefresh->stop();
}

void ProcessList::contextMenuEvent(QContextMenuEvent *event)
{
  killThread->setText(tr("Kill thread: %1").arg(processTable->indexData(processTable->currentIndexItem().row(), 0, Qt::DisplayRole).toString()));
  killQuery->setText(tr("Kill query: %1").arg(processTable->indexData(processTable->currentIndexItem().row(), 0, Qt::DisplayRole).toString()));
  menu->exec(event->globalPos());
}
