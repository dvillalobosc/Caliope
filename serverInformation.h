/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2018 David Villalobos Cambronero (david.villalobos.c@gmail.com).
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

#ifndef SERVERINFORMATION_H
#define SERVERINFORMATION_H

#include <QSettings>

class QPlainTextEdit;
class QTabWidget;
class QPushButton;
class QSpinBox;
class QLabel;
class QFormLayout;
class QGroupBox;
class DTitleLabel;
class DLineEdit;
class DTableView;
class QComboBox;

#include "dmdisubwindow.h"
#include "dbms.h"

class DBarChartWidget : public QWidget
{
  Q_OBJECT

public:
  DBarChartWidget();
  void addPoints(double point, double point2, double point3);

protected:
  void paintEvent(QPaintEvent *event);

private:
  QList<double> pointsConnections;
  QList<double> pointsKbSent;
  QList<double> pointsExecutedQueries;
  inline float calculateYPosition(double recHeight, double value, double maximunPoint);
  inline QRect drawWrapText(QPainter &painter, const QRect &rectangle, const QString &text, int flags = Qt::AlignCenter);
  inline QRect drawGraphicArea(QPainter &painter, QRect rect, const QString title, const QList<double> points);
};

class ServerInformation : public DMdiSubWindow
{
  Q_OBJECT

public:
  ServerInformation(DBMS *serverConnection);
  void setCurrentTab(unsigned int tabNumber);

protected:
  void retranslateUi();

private:
  DBMS *serverConnection;
  QPlainTextEdit *globalVariables;
  QPlainTextEdit *replicationStatus;
  QPlainTextEdit *serverStatus;
  QPlainTextEdit *serverGraphs;
  QPlainTextEdit *hddUsage;
  QString statementServerGraphs;
  qulonglong tBytesSent0;
  qulonglong tBytesSent1;
  qulonglong tBytesSent2;
  qulonglong tBytesSent3;
  qulonglong tBytesSent4;
  qulonglong tBytesSent5;
  qulonglong rateBytesSent;
  DBarChartWidget *graphicsWidget;
  QTabWidget *serverInformationTab;

  qulonglong tBytesReceived0;
  qulonglong tBytesReceived1;
  qulonglong tBytesReceived2;
  qulonglong tBytesReceived3;
  qulonglong tBytesReceived4;
  qulonglong tBytesReceived5;
  qulonglong rateBytesReceived;

  double kbSentGraph1;
  double kbSentGraph2;
  double executedQueriesGraph1;
  double executedQueriesGraph2;
  QString serverGraphsDataTxtMariaDB();
  QTimer *timerServerGraphsDataTxt;
  QTimer *timerServerGraphsData;
  QTimer *timerReplicationStatusTxt;
  QPushButton *pushButtonSkip0Error;
  QPushButton *pushButtonSkip1Error;
  QPushButton *pushButtonSkip10Error;
  QPushButton *pushButtonSkip100Error;
  QPushButton *pushButtonSkip1000Error;
  QPushButton *pushButtonStopRefreshingReplicator;
  QPushButton *pushButtonStopRefreshingServerGraphicsTXT;
  QPushButton *pushButtonStopRefreshingServerGraphics;
  QPushButton *pushButtonRefreshServerStatus;
  void skipReplicationErrors(int unsigned count = 0);
  QSpinBox *spinBoxTableSize;
  QSettings settings;
  QLabel *labelUser;
  QLabel *labelHost;
  QLabel *labelSocket;
  QLabel *labelPort;
  QLabel *labelVersion;
  QLabel *labelConnectionId;
  QFormLayout *formLayout;
  QGroupBox *informationGroupBox;
  QGroupBox *groupServer;
  DTitleLabel *dTitleLabelReplicationStatus;
  QGroupBox *buttonGroupReplication;
  DTitleLabel *dTitleLabelGlobalVariables;
  DTitleLabel *dTitleLabelServerGraphics;
  QGroupBox *buttonGroupServerGraphicsTXT;
  DTitleLabel *dTitleLabelServerGraphicsData;
  QGroupBox *buttonGroupServerGraphics;
  QGroupBox *buttonGroupHDDUsage;
  DTitleLabel *dTitleLabelHDDUsage;
  DTitleLabel *dTitleLabel;
  QGroupBox *buttonGroupVariables;
  QPushButton *pushButtonShowGlobalVariables;
  QPushButton *pushButtonShowGlobalStatus;
  QPushButton *pushButtonShowSessionStatus;
  QPushButton *pushButtonShowSessionVariables;
  QLabel *labelFilter;
  DLineEdit *lineEditFilter;
  QWidget *widgetServerGraphs2;
  QPushButton *pushButtonServerGraphicsFullScreen;
  QPushButton *pushButtonShowSlowQueries;
  QLabel *labelServerStatus;
  //DLineEdit *lineEditConnectioName;
  DTableView *slowQueriesDTableView;
  QList<QStringList> *result;
  QComboBox *slavesListComboBox;
  QSpinBox *spinBoxReplicationRefreshRate;

public slots:
  void showInformation(int tabIndex);
  void serverGraphsDataTxt();
  void serverGraphsData();
  void replicationStatusTxt();
  void hddUsageData();
  void serverStatusTxt();
  void serverSlowQueriesTxt();

private slots:
  void pushButtonSkip0ErrorClicked();
  void pushButtonSkip1ErrorClicked();
  void pushButtonSkip10ErrorClicked();
  void pushButtonSkip100ErrorClicked();
  void pushButtonSkip1000ErrorClicked();
  void spinBoxTableSizeValueChanged(int value);
  void pushButtonShowGlobalVariablesSlot();
  void pushButtonShowGlobalStatusSlot();
  void pushButtonShowSessionStatusSlot();
  void pushButtonShowSessionVariablesSlot();
  void lineEditFilterTextChangedSlot(QString filter);
  void pushButtonServerGraphicsFullScreenSlot(bool checked = false);
  //void lineEditConnectioNameClicked();
  void changeDefaultMasterConnection(QString masterConnectionName);
  void replicationRefreshRateSlot(const int value);
};

#endif // SERVERINFORMATION_H
