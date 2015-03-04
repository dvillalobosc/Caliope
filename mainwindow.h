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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QUrl>

#include "dbms.h"

class QLabel;
class ConnectDialog;
class QMdiArea;
class ServerInformation;
class QTreeWidget;
class QDockWidget;
class Catalogs;
class QTreeWidgetItem;
class SQLQuery;
class QSignalMapper;
class DWebView;
class MySQLHelp;
class ProcessList;
class TableMaintenance;
class Result;
class Backup;
class Restore;
class Users;
class QActionGroup;
class QTranslator;
class Preferences;
class QMdiSubWindow;
class TextEditor;
class DStatusBar;
class ObjectsDiagram;
class Projects;
class QPushButton;
class QSettings;
class QSystemTrayIcon;
class DatabaseComparision;
class QProcess;
class QProgressDialog;
class DMdiSubWindow;
class DQueryLog;
class DReportViewer;

/*! \brief This class represents the main class.
 *
 *  All other classes and objects are called from here.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  /*! \brief Constructs a MainWindow with the given parent.
   */
  MainWindow();
  DBMS *serverConnection;
  DStatusBar *dStatusBar;

protected:
  /*! \brief Reilplements the closeEvent.
   *  \param event to be processed.
   *
   *  Reilplements the closeEvent to make some checks on the window closing event.
   */
  void closeEvent(QCloseEvent *event);
  /*! \brief Reilplements the resizeEvent.
   *  \param resizeEvent to be processed.
   *
   *  Reilplements the resizeEvent scale the background image.
   */
  void resizeEvent(QResizeEvent *resizeEvent);

private slots:
  /*! \brief This is the code executed when aboutMySQLGUIAction is triggered.
   *
   */
  void aboutMariaDBGUIActionTriggered();
  void connectToServerActionTriggered();
  void serverInformationActionTriggered();
  void userAdministrationActionTriggered();
  void closeCurrentConnectionActionTriggered();
  void mysqlOnLineHelpActionTriggered();
  void phpOnLineHelpActionTriggered();
  void catalogsActionTriggered();
  void mysqlHelpActionTriggered();
  void processActionTriggered();
  void tableMaintenanceActionTriggered();
  void phpScriptActionTriggered();
  void backupActionTriggered();
  void restoreActionTriggered();
  void preferencesActionTriggered();
  void sqlScriptActionTriggered();
  void queryActionTriggered();
  void updateWindowMenu();
  void setActiveSubWindowMap(QWidget *window);
  void swithLanguage(QAction *action);
  void mdiSubWindowActivatedSlot(QMdiSubWindow * window);
  void shutdownServerActionTriggered();
  void updateChangeDatabaseMenu();
  void changeDatabaseSlot();
  void changeDatabaseSlot(QString database);
  void updateChangeCharsetMenu();
  void changeCharsetSlot(QString charset);
  void cssEditorActionTriggered();
  void htmlEditorActionTriggered();
  void javasctiptEditorActionTriggered();
  void externalWebPageActionTriggered();
  void toggleFullScreenActionTriggered(const bool fullScreen);
  void objectsDiagramActionTriggered();
  void openFileActionTriggered();
  void openRecentFilesMenuAboutToShowSlot();
  void recentFilesActionGroupTriggered(QAction *action);
  void textEditorActionTriggered();
  void stopReplicationSlaveActionTriggered();
  void startReplicationSlaveActionTriggered();
  void rebootReplicationSlaveActionTriggered();
  void replicationInformationActionTriggered();
  void maintenanceFlushPrivilegesActionTriggered();
  void maintenancePurgeBinaryLogsActionTriggered();
  void maintenanceTimeDifferenceActionTriggered();
  void showSlowLogActionTriggered();
  void postgresqlOnLineHelpActionTriggered();
  void mariadbOnLineHelpActionTriggered();
  void catalogsReadOnlyActionSlot(bool readOnly);
  void viewRecentFilesActionTriggered();
  void recentURLsActionGroupTriggered(QAction *action);
  void openRecentURLsMenuAboutToShowSlot();
  void clearRecentURLsActionTriggered();
  void maintenanceResetSlaveActionTriggered();
  void maintenanceFlushRelayLogsActionTriggered();
  void databaseComparisionActionTriggered();
  void migrateDatabaseActionTriggered();
  void finishedDatabaseMigrationSlot(int exitCode);
  void readyReadStandardErrorDatabaseMigrationDumpSlot();
  void readyReadStandardErrorDatabaseMigrationMariaDBSlot();
  void cancelDatabaseMigrationSlot();
  void tableCountSlot();
  void connectionMenuAboutToShowSlot();
  void openRecentConnectionMenuAboutToShowSlot();
  void openRecentConnectionActionGroupTriggered(QAction *action);
  void viewQueryLogActionSlot();
  void updatedatabaseInformationMenu();
  void databaseInformationSlot(QString database);
  void takeASnapShotActionTriggered();
  void caliopeSourceDocumentationActionTriggered();
  void viewDWebViewPageSource(QString pageSource);
  void mariaDBGUIHelpActionTriggered();
  void openURLSlot(QString url);
  void actionReportServerInformationTriggered();
  void actionReportHDDUsageTriggered();
  void actionReportExecutedQueriesTriggered();
  void actionReportDataSentReceivedTriggered();
  void actionCreateCustomReportTriggered();
  void menuReportsAboutToShowSlot();
  void openCustomReport(QString report);
  void actionReportSlowQueriesTriggered();
  void tellUsYourCommentsActionTriggered();
  void stopAllReplicationSlavesActionTriggered();
  void startAllReplicationSlavesActionTriggered();
  void reconnectionPerformedSlot();
  void decrementSQLWindowCounter();
  void decrementHTMLWindowCounter();
  void decrementPHPWindowCounter();
  void decrementCSSWindowCounter();
  void decrementJavascriptWindowCounter();
  void decrementSQLQueryWindowCounter();
  void decrementTextWindowCounter();
  void exportSettingsActionTriggered();
  void importSettingsActionTriggered();
  void saveAllActionTriggered();

public slots:
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 2000);
  void statusBarProgressMessageSlot(const QString &message, const unsigned int timeout = 2000, const double progress = 0);
  void statusBarMessagePopup(const QString &message, const int timeout = 2000);
  void addSubWindow(DMdiSubWindow *window);
  void openFile(QString fileName = QString(), unsigned int line = 1);
  void setProgressBarProgressSlot(const double progress);
  void showResultTab(QString table, QString database = QString(), QString where = QString());
  void setTitle();

signals:
  void databaseChanged();

private:
  bool okToClose();
  QLabel *messageLabel;
  QMdiArea *mdiMain;
  ServerInformation *serverInformationTab;
  Catalogs *catalogs;
  SQLQuery *query;
  DWebView *dWebView;
  MySQLHelp *mysqlHelp;
  ProcessList *processList;
  TextEditor *sqlEditor;
  TableMaintenance *tableMaintenance;
  TextEditor *phpEditor;
  Result *result;
  Backup *backup;
  Restore *restore;
  Users *userAdministration;
  Preferences *preferences;
  QAction *exitAction;
  QAction *aboutQtAction;
  QAction *aboutMariaDBGUIAction;
  QAction *connectToServerAction;
  QAction *serverInformationAction;
  QAction *userAdministrationAction;
  QAction *backupAction;
  QAction *restoreAction;
  QAction *catalogsAction;
  QAction *queryAction;
  QAction *tableMaintenanceAction;
  QAction *mysqlScriptAction;
  QAction *phpScriptAction;
  QAction *mariaDBGUIHelpAction;
  QAction *mysqlHelpAction;
  QAction *mysqlOnLineHelpAction;
  QAction *phpOnLineHelpAction;
  QAction *mariadbOnLineHelpAction;
  QAction *postgresqlOnLineHelpAction;
  QAction *preferencesAction;
  QAction *processAction;
  QAction *showFileToolBarAction;
  QAction *closeCurrentConnectionAction;
  QAction *showCurrent;
  QAction *cascadeSubWindowsAction;
  QAction *activateNextSubWindowAction;
  QAction *activatePreviousSubWindowAction;
  QAction *closeActiveSubWindowAction;
  QAction *closeAllSubWindowsAction;
  QAction *tileSubWindowsAction;
  QAction *openExternalWebPage;
  QAction *objectsDiagramAction;
  QMenu *fileMenu;
  QMenu *projectMenu;
  QMenu *helpMenu;
  QMenu *connectionMenu;
  QMenu *languageMenu;
  QMenu *changeDatabaseMenu;
  QMenu *changeCharsetMenu;
  QActionGroup *languageActionGroup;
  QMenu *viewMenu;
  QMenu *windowMenu;
  QSignalMapper *windowMapper;
  QSignalMapper *databasesMapper;
  QSignalMapper *charsetMapper;
  QToolBar *fileToolbar;
  void retranslateUi();
  QTranslator *mainTranslator;
  ObjectsDiagram *objectsDiagram;
  QAction *shutdownServerAction;
  Projects *projects;
  TextEditor *cssEditor;
  QAction *cssEditorAction;
  TextEditor *htmlEditor;
  QAction *htmlEditorAction;
  TextEditor *javascriptEditor;
  QAction *javascriptEditorAction;
  QMenu *editorsMenu;
  QMenu *externalWebPageMenu;
  QPushButton *editorsPushButton;
  int sqlWindowCounter;
  int htmlWindowCounter;
  int phpWindowCounter;
  int cssWindowCounter;
  int javascriptWindowCounter;
  int sqlQueryWindowCounter;
  int textWindowCounter;
  QAction *toggleFullScreenAction;
  QAction *openFileAction;
  QMenu *openRecentFilesMenu;
  QActionGroup *recentFilesActionGroup;
  QPushButton *projectFilesPushButton;
  TextEditor *textEditor;
  QAction *textEditorAction;
  void createInitialSettings();
  QSettings settings;
  QMenu *replicationMenu;
  QAction *stopReplicationSlaveAction;
  QAction *startReplicationSlaveAction;
  QAction *rebootReplicationSlaveAction;
  QAction *replicationInformationAction;
  QMenu *maintenanceMenu;
  void enabledDisableConnectionMenus(bool enabled);
  QAction *maintenanceFlushPrivilegesAction;
  QAction *maintenancePurgeBinaryLogsAction;
  QAction *maintenanceTimeDifferenceAction;
  QAction *showSlowLogAction;
  QSystemTrayIcon *trayIcon;
  QMenu *trayIconMenu;
  bool trayIconEnabled;
  void createSystemaTrayIcon();
  QToolBar *catalogsToolbar;
  QAction *catalogsReadOnlyAction;
  QAction *catalogsRefreshAction;
  QAction *catalogsNewDatabaseAction;
  QAction *catalogsDeleteDatabaseAction;
  QAction *viewRecentFilesAction;
  QActionGroup *recentURLsActionGroup;
  QAction *clearRecentURLsAction;
  QAction *resetSlaveAction;
  QAction *maintenanceFlushRelayLogsAction;
  QAction *databaseComparisionAction;
  DatabaseComparision *databaseComparision;
  QAction *migrateDatabaseAction;
  QProcess *processMariaDBDump;
  QProcess *processMariaDB;
  QProgressDialog *migrationProgressDialog;
  DBMS *secondaryServerConnection;
  QTimer *timerTableCount;
  QMenu *openRecentConnectionMenu;
  QActionGroup *openRecentConnectionActionGroup;
  QAction *catalogsPopulateTableAction;
  bool changeDatabase(QString database);
  QAction *viewQueryLogAction;
  DQueryLog *dQueryLog;
  QMenu *databaseInformationMenu;
  QSignalMapper *databaseInformationMapper;
  QAction *takeASnapShotAction;
  QAction *caliopeSourceDocumentationAction;
  QMenu *menuReports;
  QAction *actionReportServerInformation;
  DReportViewer *dReportViewerServerInformation;
  DReportViewer *dReportViewerHDDUsage;
  QAction *actionReportHDDUsage;
  DReportViewer *dReportViewerExecutedQueries;
  QAction *actionReportExecutedQueries;
  DReportViewer *dReportViewerDataSentReceived;
  QAction *actionReportDataSentReceived;
  QAction *actionCreateCustomReport;
  QSignalMapper *customReportMapper;
  DReportViewer *dReportViewerCustomReport;
  QAction *actionReportSlowQueries;
  DReportViewer *dReportViewerSlowQueries;
  QAction *tellUsYourCommentsAction;
  QAction *stopAllReplicationSlavesAction;
  QAction *startAllReplicationSlavesAction;
  DWebView *newDWebView(QString title, QUrl url = QUrl());
  void addSubWindow(QWidget *window);
  QAction *exportSettingsAction;
  QAction *importSettingsAction;
  QAction *saveAllAction;

  /*! \brief This is the code executed when aboutMySQLGUIAction is triggered.
   *
   */
  void createActions();
  void createMenus();
  void createToolBar();
  void fillWindowMenu();
  void showWelcomeMessage();
  void newConnectionPerformed();
};

#endif // MAINWINDOW_H
