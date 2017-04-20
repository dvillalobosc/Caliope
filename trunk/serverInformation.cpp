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

#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QTabWidget>
#include <QTimer>
#include <QPainter>
#include <QApplication>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>

#include "serverInformation.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "dlineedit.h"
#include "dtableview.h"

#include "QDebug"

ServerInformation::ServerInformation(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon::fromTheme("dialog-information", QIcon(":/images/svg/dialog-information-4.svg")));
  serverInformationTab = new QTabWidget;
  serverInformationTab->setMovable(true);

  //Case 0
  labelUser = new QLabel(serverConnection->getUserName());
  labelHost = new QLabel(serverConnection->getHostName());
  labelSocket = new QLabel(serverConnection->getSocket());
  labelPort = new QLabel(QString::number(serverConnection->getPort()));
  labelVersion = new QLabel(serverConnection->getVersion());
  labelServerStatus = new QLabel(serverConnection->getStatus());
  labelServerStatus->setWordWrap(true);
  labelConnectionId = new QLabel(QString::number(serverConnection->getConnectionId()));
  formLayout = new QFormLayout;
  formLayout->addRow(" ", labelUser);
  formLayout->addRow(" ", labelHost);
  formLayout->addRow(" ", labelSocket);
  formLayout->addRow(" ", labelPort);
  formLayout->addRow(" ", labelVersion);
  formLayout->addRow(" ", labelConnectionId);
  formLayout->addRow(" ", labelServerStatus);
  informationGroupBox = new QGroupBox;
  informationGroupBox->setLayout(formLayout);
  QVBoxLayout *informationVLayout = new QVBoxLayout;
  informationVLayout->addWidget(informationGroupBox);
  groupServer = new QGroupBox;
  QVBoxLayout *groupServerVLayout = new QVBoxLayout;
  pushButtonRefreshServerStatus = new QPushButton(this);
  pushButtonRefreshServerStatus->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));
  connect(pushButtonRefreshServerStatus, SIGNAL(clicked()), this, SLOT(serverStatusTxt()));

  pushButtonShowSlowQueries = new QPushButton(this);
  pushButtonShowSlowQueries->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));
  connect(pushButtonShowSlowQueries, SIGNAL(clicked()), this, SLOT(serverSlowQueriesTxt()));

  serverStatus = new QPlainTextEdit;
  serverStatus->setFont(StaticFunctions::fixedWidthFont());
  serverStatus->setWordWrapMode(QTextOption::NoWrap);
  QHBoxLayout *informationHLayout2 = new QHBoxLayout;
  informationHLayout2->addWidget(pushButtonRefreshServerStatus);
  informationHLayout2->addWidget(pushButtonShowSlowQueries);
  informationHLayout2->addStretch();
  groupServerVLayout->addLayout(informationHLayout2);
  groupServer->setLayout(groupServerVLayout);
  informationVLayout->addWidget(groupServer);
  groupServerVLayout->addWidget(serverStatus);

  QString NoDelegate = StaticFunctions::DelegateTypeNoDelegate();
  QList<QStringList> *slowQueriesDTableViewHeaders = new QList<QStringList>;
  slowQueriesDTableViewHeaders->append(QStringList() << tr("Start time") << NoDelegate  << "" << "Left");
  slowQueriesDTableViewHeaders->append(QStringList() << tr("User") << NoDelegate  << "" << "Left");
  slowQueriesDTableViewHeaders->append(QStringList() << tr("Time") << NoDelegate  << "" << "Left");
  slowQueriesDTableViewHeaders->append(QStringList() << tr("SQL Text") << NoDelegate  << "" << "Left");
  slowQueriesDTableView = new DTableView(slowQueriesDTableViewHeaders);
  slowQueriesDTableView->setVisible(false);
  groupServerVLayout->addWidget(slowQueriesDTableView);

  QWidget *widgetInformation = new QWidget;
  widgetInformation->setLayout(informationVLayout);
  serverInformationTab->addTab(widgetInformation, windowIcon(), " ");

  //case 1
  timerReplicationStatusTxt = new QTimer(this);
  timerReplicationStatusTxt->setInterval(1000);
  connect(timerReplicationStatusTxt, SIGNAL(timeout()), this, SLOT(replicationStatusTxt()));
  replicationStatus = new QPlainTextEdit;
  replicationStatus->setFont(StaticFunctions::fixedWidthFont());
  replicationStatus->setWordWrapMode(QTextOption::NoWrap);
  QVBoxLayout *replicationVLayout = new QVBoxLayout;
  dTitleLabelReplicationStatus = new DTitleLabel;
  replicationVLayout->addWidget(dTitleLabelReplicationStatus);
  buttonGroupReplication = new QGroupBox(this);
  QHBoxLayout *groupBoxHLayout = new QHBoxLayout;
  pushButtonSkip0Error = new QPushButton;
  connect(pushButtonSkip0Error, SIGNAL(clicked()), this, SLOT(pushButtonSkip0ErrorClicked()));
  pushButtonSkip1Error = new QPushButton;
  pushButtonSkip1Error->setIcon(QIcon::fromTheme("media-skip-forward", QIcon(":/images/svg/media-skip-forward-8.svg")));
  connect(pushButtonSkip1Error, SIGNAL(clicked()), this, SLOT(pushButtonSkip1ErrorClicked()));
  pushButtonSkip10Error = new QPushButton;
  pushButtonSkip10Error->setIcon(QIcon::fromTheme("media-skip-forward", QIcon(":/images/svg/media-skip-forward-8.svg")));
  connect(pushButtonSkip10Error, SIGNAL(clicked()), this, SLOT(pushButtonSkip10ErrorClicked()));
  pushButtonSkip100Error = new QPushButton;
  pushButtonSkip100Error->setIcon(QIcon::fromTheme("media-skip-forward", QIcon(":/images/svg/media-skip-forward-8.svg")));
  connect(pushButtonSkip100Error, SIGNAL(clicked()), this, SLOT(pushButtonSkip100ErrorClicked()));
  pushButtonStopRefreshingReplicator = new QPushButton;
  pushButtonStopRefreshingReplicator->setIcon(QIcon::fromTheme("process-stop", QIcon(":/images/svg/process-stop-7.svg")));
  pushButtonStopRefreshingReplicator->setCheckable(true);
  pushButtonStopRefreshingReplicator->setChecked(true);
  connect(pushButtonStopRefreshingReplicator, SIGNAL(toggled(bool)), timerReplicationStatusTxt, SLOT(start()));
  groupBoxHLayout->addWidget(pushButtonStopRefreshingReplicator);
  groupBoxHLayout->addWidget(pushButtonSkip0Error);
  groupBoxHLayout->addWidget(pushButtonSkip1Error);
  groupBoxHLayout->addWidget(pushButtonSkip10Error);
  groupBoxHLayout->addWidget(pushButtonSkip100Error);

  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
    break;
  case StaticFunctions::MariaDB:
    slavesListComboBox = new QComboBox();
    slavesListComboBox->insertItems(0, QStringList() << tr("All"));
    slavesListComboBox->insertItems(1, serverConnection->replication()->getSlavesNames());
    slavesListComboBox->setCurrentIndex(slavesListComboBox->findText(settings.value("Replication/LastMasterConnection", tr("All")).toString()));
    connect(slavesListComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDefaultMasterConnection(QString)));
//    connect(lineEditConnectioName, SIGNAL(clicked()), this, SLOT(lineEditConnectioNameClicked()));
    groupBoxHLayout->addWidget(new QLabel(tr("List of available connections")));
    groupBoxHLayout->addWidget(slavesListComboBox);
    this->serverConnection->replication()->changeDefaultMasterConnection(settings.value("Replication/LastMasterConnection", QString()).toString());
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }

  groupBoxHLayout->addStretch(1);
  buttonGroupReplication->setLayout(groupBoxHLayout);
  replicationVLayout->addWidget(buttonGroupReplication);
  replicationVLayout->addWidget(replicationStatus);
  replicationVLayout->setMargin(0);
  QWidget *widgetReplication = new QWidget;
  widgetReplication->setLayout(replicationVLayout);
  serverInformationTab->addTab(widgetReplication, QIcon(":/images/svg/server-database.svg"), " ");

  //case 2
  QVBoxLayout *globalVariablesVLayout = new QVBoxLayout;
  QHBoxLayout *groupBoxVariablesHLayout = new QHBoxLayout;
  labelFilter = new QLabel;
  lineEditFilter = new DLineEdit(QIcon(":/images/svg/view-filter.svg"));
  connect(lineEditFilter, SIGNAL(textChanged(QString)), this, SLOT(lineEditFilterTextChangedSlot(QString)));
  dTitleLabelGlobalVariables = new DTitleLabel;
  globalVariablesVLayout->addWidget(dTitleLabelGlobalVariables);
  globalVariables = new QPlainTextEdit;
  buttonGroupVariables = new QGroupBox(this);
  pushButtonShowGlobalVariables = new QPushButton;
  connect(pushButtonShowGlobalVariables, SIGNAL(clicked()), this, SLOT(pushButtonShowGlobalVariablesSlot()));
  pushButtonShowGlobalStatus = new QPushButton;
  connect(pushButtonShowGlobalStatus, SIGNAL(clicked()), this, SLOT(pushButtonShowGlobalStatusSlot()));
  pushButtonShowSessionStatus = new QPushButton;
  connect(pushButtonShowSessionStatus, SIGNAL(clicked()), this, SLOT(pushButtonShowSessionStatusSlot()));
  pushButtonShowSessionVariables = new QPushButton;
  connect(pushButtonShowSessionVariables, SIGNAL(clicked()), this, SLOT(pushButtonShowSessionVariablesSlot()));
  groupBoxVariablesHLayout->addWidget(pushButtonShowGlobalStatus);
  groupBoxVariablesHLayout->addWidget(pushButtonShowGlobalVariables);
  groupBoxVariablesHLayout->addWidget(pushButtonShowSessionStatus);
  groupBoxVariablesHLayout->addWidget(pushButtonShowSessionVariables);
  groupBoxVariablesHLayout->addWidget(labelFilter);
  groupBoxVariablesHLayout->addWidget(lineEditFilter);
  globalVariables->setFont(StaticFunctions::fixedWidthFont());
  globalVariables->setWordWrapMode(QTextOption::NoWrap);
  buttonGroupVariables->setLayout(groupBoxVariablesHLayout);
  globalVariablesVLayout->addWidget(buttonGroupVariables);
  globalVariablesVLayout->addWidget(globalVariables);
  globalVariablesVLayout->setMargin(0);
  QWidget *widgetVariables = new QWidget;
  widgetVariables->setLayout(globalVariablesVLayout);
  serverInformationTab->addTab(widgetVariables, QIcon(":/images/svg/server-database.svg"), " ");

  //case 3
  timerServerGraphsDataTxt = new QTimer(this);
  timerServerGraphsDataTxt->setInterval(1000);
  connect(timerServerGraphsDataTxt, SIGNAL(timeout()), this, SLOT(serverGraphsDataTxt()));
  serverGraphs = new QPlainTextEdit;
  serverGraphs->setFont(StaticFunctions::fixedWidthFont());
  serverGraphs->setWordWrapMode(QTextOption::NoWrap);
  QVBoxLayout *serverGraphsVLayout = new QVBoxLayout;
  dTitleLabelServerGraphics = new DTitleLabel;
  serverGraphsVLayout->addWidget(dTitleLabelServerGraphics);
  buttonGroupServerGraphicsTXT = new QGroupBox(this);
  QHBoxLayout *groupBoxHLayoutServerGraphics = new QHBoxLayout;
  pushButtonStopRefreshingServerGraphicsTXT = new QPushButton;
  pushButtonStopRefreshingServerGraphicsTXT->setIcon(QIcon::fromTheme("process-stop", QIcon(":/images/svg/process-stop-7.svg")));
  pushButtonStopRefreshingServerGraphicsTXT->setCheckable(true);
  pushButtonStopRefreshingServerGraphicsTXT->setChecked(true);
  connect(pushButtonStopRefreshingServerGraphicsTXT, SIGNAL(toggled(bool)), timerServerGraphsDataTxt, SLOT(start()));
  groupBoxHLayoutServerGraphics->addWidget(pushButtonStopRefreshingServerGraphicsTXT);
  groupBoxHLayoutServerGraphics->addStretch(1);
  buttonGroupServerGraphicsTXT->setLayout(groupBoxHLayoutServerGraphics);
  serverGraphsVLayout->addWidget(buttonGroupServerGraphicsTXT);
  serverGraphsVLayout->addWidget(serverGraphs);
  serverGraphsVLayout->setMargin(0);
  QWidget *widgetServerGraphs = new QWidget;
  widgetServerGraphs->setLayout(serverGraphsVLayout);
  serverInformationTab->addTab(widgetServerGraphs, QIcon(":/images/svg/server-database.svg"), " ");

  //case 4
  timerServerGraphsData = new QTimer(this);
  timerServerGraphsData->setInterval(1000);
  connect(timerServerGraphsData, SIGNAL(timeout()), this, SLOT(serverGraphsData()));
  QVBoxLayout *serverGraphs2VLayout = new QVBoxLayout;
  dTitleLabelServerGraphicsData = new DTitleLabel;
  serverGraphs2VLayout->addWidget(dTitleLabelServerGraphicsData);
  buttonGroupServerGraphics = new QGroupBox(this);
  QHBoxLayout *groupBoxHLayoutServerGraphics2 = new QHBoxLayout;
  pushButtonServerGraphicsFullScreen = new QPushButton;
  pushButtonServerGraphicsFullScreen->setCheckable(true);
  pushButtonServerGraphicsFullScreen->setIcon(QIcon::fromTheme("view-fullscreen", QIcon(":/images/svg/view-fullscreen-6.svg")));
  connect(pushButtonServerGraphicsFullScreen, SIGNAL(clicked(bool)), this, SLOT(pushButtonServerGraphicsFullScreenSlot(bool)));
  pushButtonStopRefreshingServerGraphics = new QPushButton;
  pushButtonStopRefreshingServerGraphics->setIcon(QIcon::fromTheme("process-stop", QIcon(":/images/svg/process-stop-7.svg")));
  pushButtonStopRefreshingServerGraphics->setCheckable(true);
  pushButtonStopRefreshingServerGraphics->setChecked(false);
  connect(pushButtonStopRefreshingServerGraphics, SIGNAL(toggled(bool)), timerServerGraphsData, SLOT(start()));
  groupBoxHLayoutServerGraphics2->addWidget(pushButtonStopRefreshingServerGraphics);
  groupBoxHLayoutServerGraphics2->addWidget(pushButtonServerGraphicsFullScreen);
  groupBoxHLayoutServerGraphics2->addStretch(1);
  buttonGroupServerGraphics->setLayout(groupBoxHLayoutServerGraphics2);
  serverGraphs2VLayout->addWidget(buttonGroupServerGraphics);
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    graphicsWidget = new DBarChartWidget;
    serverGraphs2VLayout->addWidget(graphicsWidget, Qt::Vertical);
    break;
  case StaticFunctions::Undefined:
  default:
    serverGraphs2VLayout->addStretch(1);
    break;
  }
  serverGraphs2VLayout->setMargin(0);
  widgetServerGraphs2 = new QWidget;
  widgetServerGraphs2->setLayout(serverGraphs2VLayout);
  serverInformationTab->addTab(widgetServerGraphs2, QIcon(":/images/svg/view-statistics.svg"), " ");

  //case 5
  hddUsage = new QPlainTextEdit;
  hddUsage->setFont(StaticFunctions::fixedWidthFont());
  hddUsage->setWordWrapMode(QTextOption::NoWrap);
  buttonGroupHDDUsage = new QGroupBox(this);
  QVBoxLayout *hddUsageStatusVLayout = new QVBoxLayout;
  QHBoxLayout *hddUsageStatusVLayout2 = new QHBoxLayout;
  spinBoxTableSize = new QSpinBox;
  spinBoxTableSize->setRange(1, 2048);
  spinBoxTableSize->setValue(settings.value("ServerInformation/TableSize", 1).toInt());
  connect(spinBoxTableSize, SIGNAL(valueChanged(int)), this, SLOT(spinBoxTableSizeValueChanged(int)));
  hddUsageStatusVLayout2->addWidget(spinBoxTableSize);
  hddUsageStatusVLayout2->addStretch();
  buttonGroupHDDUsage->setLayout(hddUsageStatusVLayout2);
  dTitleLabelHDDUsage = new DTitleLabel;
  hddUsageStatusVLayout->addWidget(dTitleLabelHDDUsage);
  hddUsageStatusVLayout->addWidget(buttonGroupHDDUsage);
  hddUsageStatusVLayout->addWidget(hddUsage);
  hddUsageStatusVLayout->setMargin(0);
  QWidget *widgetHDDUsage = new QWidget;
  widgetHDDUsage->setLayout(hddUsageStatusVLayout);
  serverInformationTab->addTab(widgetHDDUsage, QIcon::fromTheme("drive-harddisk", QIcon(":/images/svg/drive-harddisk-8.svg")), " ");

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  mainVLayout->addWidget(serverInformationTab);

  QWidget *widMain = new QWidget;
  retranslateUi();
  widMain->setLayout(mainVLayout);
  connect(serverInformationTab, SIGNAL(currentChanged(int)), this, SLOT(showInformation(int)));

  setWidget(widMain);

  tBytesSent0 = 0;
  tBytesSent1 = 0;
  tBytesSent2 = 0;
  tBytesSent3 = 0;
  tBytesSent4 = 0;
  tBytesSent5 = 0;
  rateBytesSent = 0;

  tBytesReceived0 = 0;
  tBytesReceived1 = 0;
  tBytesReceived2 = 0;
  tBytesReceived3 = 0;
  tBytesReceived4 = 0;
  tBytesReceived5 = 0;
  rateBytesReceived = 0;

  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    kbSentGraph1 = serverConnection->runQuery("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'BYTES_SENT'")->at(0).at(0).toDouble();
    executedQueriesGraph1 = serverConnection->runQuery("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'QUERIES'")->at(0).at(0).toDouble();
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  kbSentGraph2 = kbSentGraph1;
  executedQueriesGraph2 = executedQueriesGraph1;
}

void ServerInformation::retranslateUi()
{
  setWindowTitle(tr("Server Information"));
  setObjectName(windowTitle());
  QLabel *label = qobject_cast<QLabel *>(formLayout->labelForField(labelUser));
  label->setText(tr("User:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(labelHost));
  label->setText(tr("Host:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(labelSocket));
  label->setText(tr("Socket:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(labelPort));
  label->setText(tr("Port:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(labelVersion));
  label->setText(tr("Version:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(labelConnectionId));
  label->setText(tr("Connection id:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(labelServerStatus));
  label->setText(tr("Server status:"));
  informationGroupBox->setTitle(tr("Connection"));
  groupServer->setTitle(tr("Status"));
  pushButtonRefreshServerStatus->setText(tr("Show server status"));
  pushButtonShowSlowQueries->setText(tr("Show slow queries"));
  serverInformationTab->setTabText(0, windowTitle());
  dTitleLabelReplicationStatus->setText(tr("Replication Status"));
  buttonGroupReplication->setTitle(tr("Actions"));
  pushButtonSkip0Error->setText(tr("Skip 0"));
  pushButtonSkip1Error->setText(tr("Skip 1"));
  pushButtonSkip10Error->setText(tr("Skip 10"));
  pushButtonSkip100Error->setText(tr("Skip 100"));
  pushButtonStopRefreshingReplicator->setText(tr("Stop refreshing"));
  serverInformationTab->setTabText(1, tr("Replication Status"));
  dTitleLabelGlobalVariables->setText(tr("Variables"));
  serverInformationTab->setTabText(2, tr("Variables"));
  buttonGroupServerGraphicsTXT->setTitle(tr("Actions"));
  dTitleLabelServerGraphics->setText(tr("Server Graphics"));
  pushButtonStopRefreshingServerGraphicsTXT->setText(tr("Stop refreshing"));
  serverInformationTab->setTabText(3, tr("Server Graphics"));
  dTitleLabelServerGraphicsData->setText(tr("Server Graphics"));
  buttonGroupServerGraphics->setTitle(tr("Actions"));
  pushButtonStopRefreshingServerGraphics->setText(tr("Stop refreshing"));
  serverInformationTab->setTabText(4, tr("Server Graphics"));
  buttonGroupHDDUsage->setTitle(tr("Actions"));
  dTitleLabelHDDUsage->setText(tr("HDD Usage"));
  serverInformationTab->setTabText(5, tr("HDD Usage"));
  dTitleLabel->setText(windowTitle());
  buttonGroupVariables->setTitle(tr("Filter"));
  pushButtonShowGlobalVariables->setText(tr("Show global variables"));
  pushButtonShowGlobalStatus->setText(tr("Show global status"));
  pushButtonShowSessionStatus->setText(tr("Show session status"));
  pushButtonShowSessionVariables->setText(tr("Show session variables"));
  labelFilter->setText(tr("Filter:"));
  lineEditFilter->setPlaceholderText(tr("Three characters at least"));
  pushButtonServerGraphicsFullScreen->setText(tr("Full screen"));
}

void ServerInformation::setCurrentTab(unsigned int tabNumber)
{
  serverInformationTab->setCurrentIndex(tabNumber);
}

QString ServerInformation::serverGraphsDataTxtMariaDB()
{
  QString out;

  //Bytes sent
  tBytesSent5 = tBytesSent4;
  tBytesSent4 = tBytesSent3;
  tBytesSent3 = tBytesSent2;
  tBytesSent2 = tBytesSent1;
  tBytesSent1 = tBytesSent0 / 1024;
  rateBytesSent = tBytesSent0;
  tBytesSent0 = serverConnection->runQuery("SELECT `VARIABLE_VALUE` / 1024 FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'BYTES_SENT'")->at(0).at(0).toDouble();
  statementServerGraphs = QString("SELECT FORMAT(%1, 2) AS `T`, FORMAT(%2, 2) AS `T-1`, FORMAT(%3, 2) AS `T-2`, FORMAT(%4, 2) AS `T-3`, FORMAT(%5, 2) AS `T-4`, FORMAT(%6, 2) AS `T-5`")
      .arg(tBytesSent0 / 1024).arg(tBytesSent1).arg(tBytesSent2).arg(tBytesSent3).arg(tBytesSent4).arg(tBytesSent5);
  out += tr("Data sent in MB.");
  out += "\n" + serverConnection->outputAsTable(statementServerGraphs);
  out += tr("Transfer rate: %1 Kb per second.").arg(tBytesSent0 - rateBytesSent);

  //Bytes received
  tBytesReceived5 = tBytesReceived4;
  tBytesReceived4 = tBytesReceived3;
  tBytesReceived3 = tBytesReceived2;
  tBytesReceived2 = tBytesReceived1;
  tBytesReceived1 = tBytesReceived0 / 1024;
  rateBytesReceived = tBytesReceived0;
  tBytesReceived0 = serverConnection->runQuery("SELECT `VARIABLE_VALUE` / 1024 FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'BYTES_RECEIVED'")->at(0).at(0).toDouble();
  statementServerGraphs = QString("SELECT FORMAT(%1, 2) AS `T`, FORMAT(%2, 2) AS `T-1`, FORMAT(%3, 2) AS `T-2`, FORMAT(%4, 2) AS `T-3`, FORMAT(%5, 2) AS `T-4`, FORMAT(%6, 2) AS `T-5`")
      .arg(tBytesReceived0 / 1024).arg(tBytesReceived1).arg(tBytesReceived2).arg(tBytesReceived3).arg(tBytesReceived4).arg(tBytesReceived5);
  out += "\n\n" + tr("Data received in MB.");
  out += "\n" + serverConnection->outputAsTable(statementServerGraphs);
  out += tr("Transfer rate: %1 Kb per second.").arg(tBytesReceived0 - rateBytesReceived);

  //Misc Values
  out += "\n\n" + tr("Miscellaneous values.");
  out += "\n" + serverConnection->outputAsTable("SELECT `VARIABLE_NAME`, LPAD(FORMAT(`VARIABLE_VALUE`, 0), 14, ' ') AS `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` IN ("
                                                              "'OPEN_TABLES', 'COM_DELETE', 'COM_INSERT', 'COM_SELECT'"
                                                              ", 'COM_UPDATE', 'SLOW_QUERIES', 'TABLE_LOCKS_IMMEDIATE'"
                                                              ", 'TABLE_LOCKS_WAITED', 'THREADS_CONNECTED', 'THREADS_RUNNING')");
  return out;
}

void ServerInformation::skipReplicationErrors(unsigned int count)
{
  serverConnection->replication()->skipErrors(count);
}

void ServerInformation::changeDefaultMasterConnection(QString masterConnectionName)
{
  serverConnection->replication()->changeDefaultMasterConnection(masterConnectionName);
  settings.setValue("Replication/LastMasterConnection", masterConnectionName);
}

void ServerInformation::showInformation(int tabIndex)
{
  timerServerGraphsData->stop();
  switch (tabIndex) {
  case 0:
    serverStatusTxt();
    break;
  case 1:
    replicationStatusTxt();
    break;
  case 2:
    globalVariables->setPlainText(serverConnection->getGlobalStatus());
    break;
  case 3:
    serverGraphsDataTxt();
    break;
  case 4:
    timerServerGraphsData->start();
    serverGraphsData();
    break;
  case 5:
    hddUsageData();
    break;
  // default: Q_ASSERT(false);
  }
}

void ServerInformation::serverGraphsDataTxt()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    serverGraphs->setPlainText(serverGraphsDataTxtMariaDB());
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  if (pushButtonStopRefreshingServerGraphicsTXT->isChecked())
    timerServerGraphsDataTxt->stop();
}

void ServerInformation::serverGraphsData()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    kbSentGraph2 = kbSentGraph1;
    kbSentGraph1 = serverConnection->runQuery("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'BYTES_SENT'")->at(0).at(0).toDouble();
    executedQueriesGraph2 = executedQueriesGraph1;
    executedQueriesGraph1 = serverConnection->runQuery("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'QUERIES'")->at(0).at(0).toDouble();
    graphicsWidget->addPoints(serverConnection->runQuery("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'THREADS_CONNECTED'")->at(0).at(0).toDouble()
                             , (kbSentGraph1 - kbSentGraph2) / 1024, executedQueriesGraph1 - executedQueriesGraph2);
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  if (pushButtonStopRefreshingServerGraphics->isChecked())
    timerServerGraphsData->stop();
}

void ServerInformation::replicationStatusTxt()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
    replicationStatus->setPlainText(serverConnection->replication()->getStatus());
    break;
  case StaticFunctions::MariaDB:
    if (slavesListComboBox->currentText() == tr("All"))
      replicationStatus->setPlainText(serverConnection->replication()->getStatus());
    else
      replicationStatus->setPlainText(serverConnection->replication()->getStatus(slavesListComboBox->currentText()));
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  if (pushButtonStopRefreshingReplicator->isChecked())
    timerReplicationStatusTxt->stop();
}

void ServerInformation::hddUsageData()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QString output(tr("Database sizes description.") + "\n");
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    output += serverConnection->outputAsTable("SELECT `TABLE_SCHEMA` AS `" + tr("Database") + "`"
                                                            " , LPAD(FORMAT((SUM(`DATA_LENGTH` + `INDEX_LENGTH`) / 1024 / 1024), 2), 9, ' ') AS `" + tr("Total") + "`"
                                                            " , LPAD(FORMAT((SUM(`DATA_LENGTH`) / 1024 / 1024), 2), 9, ' ') AS `" + tr("Data") + "`"
                                                            " , LPAD(FORMAT((SUM(`INDEX_LENGTH`) / 1024 / 1024), 2), 9, ' ') AS `" + tr("Indexes") + "`"
                                                            " , LPAD(COUNT(*), 6, ' ') AS `" + tr("Tables") + "`"
                                                            " , LPAD(FORMAT(SUM(`TABLE_ROWS`), 0), 15, ' ') AS `" + tr("Rows") + "`"
                                                            " FROM `information_schema`.`TABLES`"
                                                            " GROUP BY `TABLE_SCHEMA`"
                                                            " ORDER BY `TABLE_SCHEMA`");
    output += "\n" + tr("Detailed size table description. Table size greater than %1 MB.").arg(settings.value("ServerInformation/TableSize", 1).toString()) + "\n";
    output += serverConnection->outputAsTable("SELECT `TABLE_SCHEMA` AS `" + tr("Database") + "`, `TABLE_NAME` AS `" + tr("Table name") + "`"
                                                            " , LPAD(FORMAT(((`DATA_LENGTH` + `INDEX_LENGTH`) / 1024 / 1024), 2), 9, ' ') AS `" + tr("Total") + "`"
                                                            " , LPAD(FORMAT((`DATA_LENGTH` / 1024 / 1024), 2), 9, ' ') AS `" + tr("Data") + "`"
                                                            " , LPAD(FORMAT((`INDEX_LENGTH` / 1024 / 1024), 2), 9, ' ') AS `" + tr("Indexes") + "`"
                                                            " , LPAD(FORMAT(`TABLE_ROWS`, 0), 15, ' ') AS `" + tr("Rows") + "`"
                                                            " FROM `information_schema`.`TABLES`"
                                                            " WHERE `TABLE_TYPE` = 'BASE TABLE'"
                                                            "  AND ((`DATA_LENGTH` + `INDEX_LENGTH`) / 1024 / 1024) > " + settings.value("ServerInformation/TableSize", 1).toString()
                                                            + " ORDER BY `TABLE_SCHEMA`, `TABLE_NAME`");
    hddUsage->setPlainText(output);
    break;
  case StaticFunctions::Undefined:
  default:
    hddUsage->setPlainText(tr("There was an error determinating the DBMS type."));
    break;
  }
  QApplication::restoreOverrideCursor();
}

void ServerInformation::serverStatusTxt()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  serverStatus->setVisible(true);
  slowQueriesDTableView->setVisible(false);
  QString output(tr("Main server data.") + "\n");
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    output += serverConnection->outputAsTable(StaticFunctions::serverInformationQuery());
    output += "\n" + tr("Average of slow queries per day since server started.") + "\n";
    output += serverConnection->outputAsTable(StaticFunctions::slowQueriesQuery());
    serverStatus->setPlainText(output);
    break;
  case StaticFunctions::Undefined:
  default:
    serverStatus->setPlainText(tr("There was an error determinating the DBMS type."));
    break;
  }
  QApplication::restoreOverrideCursor();
}

void ServerInformation::serverSlowQueriesTxt()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    serverStatus->setVisible(false);
    slowQueriesDTableView->setVisible(true);
    result = serverConnection->runQuery("SELECT '', `start_time`, `user_host`, `query_time`, `sql_text` FROM `mysql`.`slow_log` WHERE `start_time` >= (SELECT FROM_UNIXTIME((SELECT UNIX_TIMESTAMP(CURRENT_TIMESTAMP())) - (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME')))");
    result->takeLast(); //Remove the "Affected rows" line.
    slowQueriesDTableView->setModelData(result);
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  QApplication::restoreOverrideCursor();
}

void ServerInformation::pushButtonSkip0ErrorClicked()
{
  skipReplicationErrors();
}

void ServerInformation::pushButtonSkip1ErrorClicked()
{
  skipReplicationErrors(1);
}

void ServerInformation::pushButtonSkip10ErrorClicked()
{
  skipReplicationErrors(10);
}

void ServerInformation::pushButtonSkip100ErrorClicked()
{
  skipReplicationErrors(100);
}

void ServerInformation::spinBoxTableSizeValueChanged(int value)
{
  settings.setValue("ServerInformation/TableSize", value);
  hddUsageData();
}

void ServerInformation::pushButtonShowGlobalVariablesSlot()
{
  globalVariables->setPlainText(serverConnection->getGlobalVariables());
}

void ServerInformation::pushButtonShowGlobalStatusSlot()
{
  globalVariables->setPlainText(serverConnection->getGlobalStatus());
}

void ServerInformation::pushButtonShowSessionStatusSlot()
{
  globalVariables->setPlainText(serverConnection->getSessionStatus());
}

void ServerInformation::pushButtonShowSessionVariablesSlot()
{
  globalVariables->setPlainText(serverConnection->getSessionlVariables());
}

void ServerInformation::lineEditFilterTextChangedSlot(QString filter)
{
  QString output;
  if (filter.length() >= 3) {
    output += tr("Global status") + "\n";
    output += serverConnection->getGlobalStatus(filter);
    output += "\n" + tr("Session status") + "\n";
    output += serverConnection->getSessionStatus(filter);
    output += "\n" + tr("Global variables") + "\n";
    output += serverConnection->getGlobalVariables(filter);
    output += "\n" + tr("Session variables") + "\n";
    output += serverConnection->getSessionlVariables(filter);
  }
  globalVariables->setPlainText(output);
}

void ServerInformation::pushButtonServerGraphicsFullScreenSlot(bool checked)
{
  if (checked) {
    serverInformationTab->widget(4)->setParent(0);
    widgetServerGraphs2->showFullScreen();
  } else {
    serverInformationTab->insertTab(4, widgetServerGraphs2, QIcon(":/images/svg/view-statistics.svg"), tr("Server Graphics"));
    serverInformationTab->setCurrentIndex(4);
  }
}

//void ServerInformation::lineEditConnectioNameClicked()
//{
//  pushButtonStopRefreshingReplicator->setChecked(true);
//  timerReplicationStatusTxt->stop();
//}

/****************************************************/

DBarChartWidget::DBarChartWidget()
{
}

void DBarChartWidget::addPoints(double point, double point2, double point3)
{
  if (pointsConnections.count() == 60)
    pointsConnections.removeFirst();
  pointsConnections.append(point);
  if (pointsKbSent.count() == 60)
    pointsKbSent.removeFirst();
  pointsKbSent.append(point2);
  if (pointsExecutedQueries.count() == 60)
    pointsExecutedQueries.removeFirst();
  pointsExecutedQueries.append(point3);
  update();
}

void DBarChartWidget::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  QRect rect;
  rect = drawGraphicArea(painter, QRect(5, 5, 0, 0), tr("Total connections in the last 60 seconds"), pointsConnections);
  rect = drawGraphicArea(painter, rect, tr("Kb sent by second"), pointsKbSent);
  rect = drawGraphicArea(painter, rect, tr("Executed queries in the last 60 seconds"), pointsExecutedQueries);
}

float DBarChartWidget::calculateYPosition(double recHeight, double value, double maximunPoint)
{
  return (recHeight / 100) * (100 - ((100 * value) / maximunPoint));
}

QRect DBarChartWidget::drawWrapText(QPainter &painter, const QRect &rectangle, const QString &text, int flags)
{
  QRect textArea1(rectangle.x(), rectangle.y(), 7 * text.length() + 10, 15);
  painter.drawRect(textArea1);
  painter.drawText(textArea1, flags, text);
  return QRect(textArea1.x() + textArea1.width() + 10, rectangle.y(), 7 * text.length() + 10, 15);
}

QRect DBarChartWidget::drawGraphicArea(QPainter &painter, QRect rect, const QString title, const QList<double> points)
{
  double margin = rect.x();
  double widgetSeparator1 = 5;
  double widgetSeparator2 = 25;
  double graphAreaWidth = width() - (rect.x() * 2);
  double graphAreaHeight = (height() - 50 - (6 * 10) - ((widgetSeparator1 * 3) + (widgetSeparator2 * 3))) / 3;
  double stepSeparator = graphAreaWidth / 60; //57

  painter.setPen(QPen(Qt::blue, 2));
  rect = drawWrapText(painter, QRect(margin, rect.y(), 0, 0), title);
  painter.setPen(QPen(Qt::black, 1));
  rect = QRect(margin, rect.height() + rect.y() + widgetSeparator1, graphAreaWidth, graphAreaHeight);
  QLinearGradient linearGradient(QPointF(graphAreaWidth / 2, rect.y()), QPointF(graphAreaWidth / 2, rect.y() + rect.height()));
  linearGradient.setColorAt(0, Qt::red);
  linearGradient.setColorAt(0.5, Qt::yellow);
  linearGradient.setColorAt(1, Qt::green);
  linearGradient.setSpread(QGradient::PadSpread);
  QBrush brush(linearGradient);
  painter.drawRect(rect);
  painter.fillRect(rect, brush);
//  brush.setStyle(Qt::CrossPattern);
//  painter.fillRect(rect, brush);

  painter.setPen(QPen(Qt::blue, 2));
  double maximun = 0;
  double minimun = 0;
  for (int step = 0; step < points.count(); step++) {
    if (maximun < points.at(step))
      maximun = points.at(step);
    else
      minimun = points.at(step);
  }
  for (int step = 1; step < points.count(); step++)
    painter.drawLine(QPointF(rect.left() + ((step - 1) * stepSeparator), calculateYPosition(rect.height(), points.at(step - 1), maximun) + rect.y())
                     , QPointF(rect.left() + (step * stepSeparator), calculateYPosition(rect.height(), points.at(step), maximun) + rect.y()));
  rect = drawWrapText(painter, QRect(rect.left(), rect.y() + rect.height() + 10, 0, 0), tr("Current: %1").arg((points.count() == 0 ? 0 : points.last())));
  rect = drawWrapText(painter, rect, tr("Max: %1").arg(maximun));
  rect = drawWrapText(painter, rect, tr("Min: %1").arg(minimun));
  return QRect(margin, rect.y() + rect.height() + widgetSeparator1 + widgetSeparator2, graphAreaWidth, graphAreaHeight);
}
