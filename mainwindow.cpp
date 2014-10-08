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

#include <QTreeWidget>
#include <QDockWidget>
#include <QMdiArea>
#include <QAction>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include <QCoreApplication>
#if QT_VERSION > 0x040801
  #include <QtWebKitWidgets/QWebView>
#else
  #include <QtWebKit/QWebView>
#endif
#include <QTranslator>
#include <QFile>
#include <QApplication>
#include <QDir>
#include <QPushButton>
#include <QTime>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QDateTimeEdit>
#include <QCloseEvent>
//#include <QtDeclarative/QDeclarativeView>
#include <QProcess>
#include <QProgressDialog>
#include <QTimer>
//#include <QSplashScreen>
#include <QImageWriter>

#include "mainwindow.h"
#include "connectdialog.h"
#include "serverInformation.h"
#include "catalogs.h"
#include "dstatusbar.h"
#include "mysqlhelp.h"
#include "processlist.h"
#include "sqlquery.h"
#include "tablemaintenance.h"
#include "result.h"
#include "backup.h"
#include "restore.h"
#include "users.h"
#include "preferences.h"
#include "objectsdiagram.h"
#include "networksettings.h"
#include "projects.h"
#include "dwebview.h"
#include "staticfunctions.h"
#include "texteditor.h"
#include "dtitlelabel.h"
#include "databasecomparision.h"
#include "dmdisubwindow.h"
#include "dquerylog.h"
#include "basetexteditor.h"

#include "QDebug"

MainWindow::MainWindow()
{
  QCoreApplication::setApplicationName("Calíope");
  QCoreApplication::setOrganizationName("DVC Software");
  qApp->setProperty("SessionId", StaticFunctions::randomString(10));
  serverConnection = new DBMS;
  connect(serverConnection, SIGNAL(databaseChanged()), this, SLOT(changeDatabaseSlot()));
  connect(serverConnection, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(serverConnection, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));

  projects = new Projects;
  connect(projects, SIGNAL(updateTitle()), this, SLOT(setTitle()));
  connect(projects, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  connect(projects, SIGNAL(addSubWindow(DMdiSubWindow*)), this, SLOT(addSubWindow(DMdiSubWindow*)));
  connect(projects, SIGNAL(openFile(QString)), this, SLOT(openFile(QString)));
  connect(projects, SIGNAL(statusBarMessagePopup(QString)), this, SLOT(statusBarMessagePopup(QString)));

  sqlWindowCounter = 0;
  mysqlQueryWindowCounter = 0;
  htmlWindowCounter = 0;
  phpWindowCounter = 0;
  cssWindowCounter = 0;
  javascriptWindowCounter = 0;
  textWindowCounter = 0;


//  QSplashScreen *splash = new QSplashScreen(QPixmap(":/images/png/512/server-database.png"));
//  splash->show();
//  splash->showMessage("Task 1");
//  qApp->processEvents();
//  splash->showMessage("Task 2");
//  qApp->processEvents();
//  //splash->hide();

  QFile styleFile(":/styles/mainStyle.css");
  if (!styleFile.open(QFile::ReadOnly | QFile::Text))
    statusBarMessage(tr("Cannot read file %1:\n%2.").arg(":/styles/mainStyle.css").arg(styleFile.errorString()), QSystemTrayIcon::Critical);
  QSettings settings;
  qApp->setStyle(settings.value("Style", QApplication::style()->objectName()).toString());
  qApp->setStyleSheet(QString::fromUtf8(styleFile.readAll()));
  styleFile.close();
  setGeometry(settings.value("MainWindow/Geometry", QRect(100, 100, 600, 400)).toRect());
  if (settings.value("MainWindow/Maximized", false).toBool())
    setWindowState(Qt::WindowMaximized);
  setWindowTitle(QCoreApplication::applicationName());
  setObjectName(windowTitle());
  setAttribute(Qt::WA_DeleteOnClose);
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));

  mdiMain = new QMdiArea;
  mdiMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  mdiMain->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  connect(mdiMain, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(mdiSubWindowActivatedSlot(QMdiSubWindow*)));
  setCentralWidget(mdiMain);

  createActions();
  createMenus();
  createSystemaTrayIcon();
  updateWindowMenu();
  dStatusBar = new DStatusBar;
  setStatusBar(dStatusBar);
  createToolBar();

  windowMapper = new QSignalMapper(this);
  connect(windowMapper, SIGNAL(mapped(QWidget*)), this, SLOT(setActiveSubWindowMap(QWidget*)));
  databasesMapper = new QSignalMapper(this);
  connect(databasesMapper, SIGNAL(mapped(QString)), this, SLOT(changeDatabaseSlot(QString)));
  charsetMapper = new QSignalMapper(this);
  connect(charsetMapper, SIGNAL(mapped(QString)), this, SLOT(changeCharsetSlot(QString)));
  databaseInformationMapper = new QSignalMapper(this);
  connect(databaseInformationMapper, SIGNAL(mapped(QString)), this, SLOT(databaseInformationSlot(QString)));

  connect(showFileToolBarAction, SIGNAL(triggered(bool)), fileToolbar, SLOT(setVisible(bool)));

  mainTranslator = new QTranslator(this);
  if (settings.value("General/Language", "en") != "en") {
    QAction *languageAction = new QAction("", this);
    languageAction->setData(settings.value("General/Language", "en"));
    swithLanguage(languageAction);
  }

  if (QApplication::arguments().count() == 1)
    connectToServerActionTriggered();

  createInitialSettings();

  NetworkSettings::setProxySettings();

  showWelcomeMessage();

  if (settings.value("RememberOpenedWindows", false).toBool()) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    foreach (QString window, settings.value("OpenedWindows", QStringList()).toStringList()) {
      if (window == tr("Server Information"))
        serverInformationActionTriggered();
      if (window == tr("User Administration"))
        userAdministrationActionTriggered();
      if (window == tr("Backup"))
        backupActionTriggered();
      if (window == tr("Restore"))
        restoreActionTriggered();
      if (window.startsWith(tr("Catalogs")))
        catalogsActionTriggered();
      if (window == tr("Table Maintenance"))
        tableMaintenanceActionTriggered();
      if (window == tr("Process List"))
        processActionTriggered();
      if (window == tr("Query Log")) {
        viewQueryLogActionSlot();
        continue;
      }
      if (window.startsWith(tr("SQL Query")))
        sqlScriptActionTriggered();
      if (window.startsWith(tr("Query")))
        queryActionTriggered();
      if (window.startsWith(tr("PHP")))
        phpScriptActionTriggered();
      if (window == tr("Database Comparision"))
        databaseComparisionActionTriggered();
    }
    QApplication::restoreOverrideCursor();
  }
  foreach (QString arg, QApplication::arguments()) {
    QFile file(arg);
    if (file.exists()) {
      QFileInfo fileInfo(file.fileName());
      QString fileCompleteSuffix = fileInfo.completeSuffix().toLower();
      if (fileCompleteSuffix == "sql") {
        sqlScriptActionTriggered();
        sqlEditor->openFile(fileInfo.absoluteFilePath());
      }
      if (fileCompleteSuffix == "inc" || fileCompleteSuffix == "php") {
        phpScriptActionTriggered();
        phpEditor->openFile(fileInfo.absoluteFilePath());
      }
      if (fileCompleteSuffix == "js") {
        javasctiptEditorActionTriggered();
        javascriptEditor->openFile(fileInfo.absoluteFilePath());
      }
      if (fileCompleteSuffix == "html") {
        htmlEditorActionTriggered();
        htmlEditor->openFile(fileInfo.absoluteFilePath());
      }

    }
  }

  if (settings.value("General/Language", "en") != "en") {
    QAction *languageAction = new QAction("", this);
    languageAction->setData(settings.value("General/Language", "en"));
    swithLanguage(languageAction);
  }
  retranslateUi();
  serverConnection->logApplicationStarted();
}

void MainWindow::statusBarProgressMessageSlot(const QString &message, const unsigned int timeout, const double progress)
{
  statusBarMessage(message, QSystemTrayIcon::Information, timeout);
  dStatusBar->setProgress(progress);
}

void MainWindow::toggleFullScreenActionTriggered(const bool fullScreen)
{
  if (fullScreen)
    setWindowState(windowState() | Qt::WindowFullScreen);
  else
    setWindowState(windowState() & ~Qt::WindowFullScreen);
}

void MainWindow::addSubWindow(DMdiSubWindow *window)
{
  mdiMain->addSubWindow(window);
  window->showMaximized();
  dStatusBar->resetStatusBar();
}

//void MainWindow::openFile(QString fileName, unsigned int line)
//{
//}

void MainWindow::mdiSubWindowActivatedSlot(QMdiSubWindow *window)
{
  dStatusBar->resetStatusBar();
  if (window == 0) {
    catalogsToolbar->hide();
    return;
  }
  if (window->windowTitle().startsWith(tr("Catalogs")))
    catalogsToolbar->show();
  else
    catalogsToolbar->hide();
//  if (window->windowTitle().startsWith(tr("Query")))
//    sqlQueryToolbar->show();
//  else
//    sqlQueryToolbar->hide();
}

void MainWindow::showWelcomeMessage()
{
  QStringList texts;
  texts << tr( "In God we trust")
        << tr("In a world without walls and fences, who needs windows and gates?")
        << tr("Wellcome!!! Have a nice day.")
        << tr("MariaDB is great!!!")
        << tr("Qt is great!!!")
        << tr("Open space has more fresh air than closed Windows")
        << tr("Microsoft gives you \"Windows\", Linux a \"home\"!");
  qsrand(QTime::currentTime().second());
  dStatusBar->showFancyMessage(texts[(int) qrand() % texts.size()]);
}

bool MainWindow::okToClose()
{
  foreach (QMdiSubWindow *subWindow, mdiMain->subWindowList()) {
    if (subWindow->inherits("TextEditor")) {
      TextEditor *wid = qobject_cast<TextEditor *>(subWindow);
      if (!wid->okToClose())
        return false;
    }
  }
  return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  if (okToClose()) {
    QSettings settings;
    settings.setValue("MainWindow/Geometry", geometry());
    settings.setValue("MainWindow/Maximized", isMaximized());
    if (settings.value("RememberOpenedWindows", false).toBool()) {
      QStringList list;
      foreach (QMdiSubWindow *window, mdiMain->subWindowList(QMdiArea::ActivationHistoryOrder))
        list.append(window->windowTitle());
      settings.setValue("OpenedWindows", list);
    }
    settings.sync();
    serverConnection->close();
    event->accept();
  } else {
    event->ignore();
  }
}

void MainWindow::resizeEvent(QResizeEvent *resizeEvent)
{
  QImage newBackground(mdiMain->size(), QImage::Format_ARGB32_Premultiplied);
  QPainter painter(&newBackground);
  painter.fillRect(newBackground.rect(), Qt::darkGray);
  QSettings setting;
  QImage originalImage(setting.value("General/BackgroundImage", ":/images/png/512/server-database.png").toString());
  QRect scaledRect = originalImage.rect();
  scaledRect.moveCenter(newBackground.rect().center());
  painter.drawImage(scaledRect, originalImage);
  mdiMain->setBackground(newBackground);
  QMainWindow::resizeEvent(resizeEvent);
}

void MainWindow::createActions()
{
  exitAction = new QAction(this);
  exitAction->setIcon(QIcon::fromTheme("application-exit", QIcon(":/images/svg/application-exit-4.svg")));
  exitAction->setShortcut(QKeySequence::Quit);
  connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

  aboutQtAction = new QAction(this);
  aboutQtAction->setIcon(QIcon(":/images/svg/Qt-logo.svg"));
  connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  aboutMariaDBGUIAction = new QAction(this);
  aboutMariaDBGUIAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(aboutMariaDBGUIAction, SIGNAL(triggered()), this, SLOT(aboutMariaDBGUIActionTriggered()));

  connectToServerAction = new QAction(this);
  connectToServerAction->setIcon(QIcon(":/images/svg/network-server-database.svg"));
  connect(connectToServerAction, SIGNAL(triggered()), this, SLOT(connectToServerActionTriggered()));

  serverInformationAction = new QAction(this);
  serverInformationAction->setIcon(QIcon::fromTheme("dialog-information", QIcon(":/images/svg/dialog-information-4.svg")));
  serverInformationAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_I));
  connect(serverInformationAction, SIGNAL(triggered()), this, SLOT(serverInformationActionTriggered()));

  userAdministrationAction = new QAction(this);
  userAdministrationAction->setIcon(QIcon(":/images/svg/system-users-4.svg"));
  connect(userAdministrationAction, SIGNAL(triggered()), this, SLOT(userAdministrationActionTriggered()));

  backupAction = new QAction(this);
  backupAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(backupAction, SIGNAL(triggered()), this, SLOT(backupActionTriggered()));

  restoreAction = new QAction(this);
  restoreAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(restoreAction, SIGNAL(triggered()), this, SLOT(restoreActionTriggered()));

  catalogsAction = new QAction(this);
  catalogsAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  catalogsAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_C));
  connect(catalogsAction, SIGNAL(triggered()), this, SLOT(catalogsActionTriggered()));

  queryAction = new QAction(this);
  queryAction->setIcon(QIcon(":/images/svg/application-x-executable-script.svg"));
  queryAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_Q));
  connect(queryAction, SIGNAL(triggered()), this, SLOT(queryActionTriggered()));

  tableMaintenanceAction = new QAction(this);
  tableMaintenanceAction->setIcon(QIcon::fromTheme("preferences-system", QIcon(":/images/svg/preferences-system-4.svg")));
  tableMaintenanceAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_M));
  connect(tableMaintenanceAction, SIGNAL(triggered()), this, SLOT(tableMaintenanceActionTriggered()));

  mysqlScriptAction = new QAction(this);
  mysqlScriptAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(mysqlScriptAction, SIGNAL(triggered()), this, SLOT(sqlScriptActionTriggered()));

  phpScriptAction = new QAction(this);
  phpScriptAction->setIcon(QIcon(":/images/svg/application-x-php.svg"));
  connect(phpScriptAction, SIGNAL(triggered()), this, SLOT(phpScriptActionTriggered()));

  mariaDBGUIHelpAction = new QAction(this);
  mariaDBGUIHelpAction->setShortcut(QKeySequence(Qt::Key_F1));
  mariaDBGUIHelpAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(mariaDBGUIHelpAction, SIGNAL(triggered()), this, SLOT(mariaDBGUIHelpActionTriggered()));

  mysqlHelpAction = new QAction(this);
  mysqlHelpAction->setIcon(QIcon(":/images/svg/mysql.svg"));
  connect(mysqlHelpAction, SIGNAL(triggered()), this, SLOT(mysqlHelpActionTriggered()));

  viewQueryLogAction = new QAction(this);
  viewQueryLogAction->setIcon(QIcon(":/images/svg/utilities-log-viewer-2.svg"));
  connect(viewQueryLogAction, SIGNAL(triggered()), this, SLOT(viewQueryLogActionSlot()));

  mysqlOnLineHelpAction = new QAction(this);
  mysqlOnLineHelpAction->setIcon(QIcon(":/images/svg/mysql.svg"));
  connect(mysqlOnLineHelpAction, SIGNAL(triggered()), this, SLOT(mysqlOnLineHelpActionTriggered()));

  phpOnLineHelpAction = new QAction(this);
  phpOnLineHelpAction->setIcon(QIcon(":/images/svg/php-logo.svg"));
  connect(phpOnLineHelpAction, SIGNAL(triggered()), this, SLOT(phpOnLineHelpActionTriggered()));

  preferencesAction = new QAction(this);
  preferencesAction->setIcon(QIcon::fromTheme("preferences-system", QIcon(":/images/svg/preferences-system-4.svg")));
  preferencesAction->setShortcut(QKeySequence::Preferences);
  connect(preferencesAction, SIGNAL(triggered()), this, SLOT(preferencesActionTriggered()));

  processAction = new QAction(this);
  processAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  processAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_P));
  connect(processAction, SIGNAL(triggered()), this, SLOT(processActionTriggered()));

  showFileToolBarAction = new QAction(this);
  showFileToolBarAction->setCheckable(true);
  showFileToolBarAction->setChecked(true);

  closeCurrentConnectionAction = new QAction(this);
  closeCurrentConnectionAction->setIcon(QIcon::fromTheme("dialog-close", QIcon(":/images/svg/document-close-4.svg")));
  closeCurrentConnectionAction->setDisabled(true);
  connect(closeCurrentConnectionAction, SIGNAL(triggered()), this, SLOT(closeCurrentConnectionActionTriggered()));

  cascadeSubWindowsAction = new QAction(this);
  cascadeSubWindowsAction->setIcon(QIcon(":/images/svg/preferences-system-windows-2.svg"));
  connect(cascadeSubWindowsAction, SIGNAL(triggered()), mdiMain, SLOT(cascadeSubWindows()));

  activateNextSubWindowAction = new QAction(this);
  activateNextSubWindowAction->setIcon(QIcon::fromTheme("find-next", QIcon(":/images/svg/go-next-view.svg")));
  activateNextSubWindowAction->setShortcut(QKeySequence::NextChild);
  connect(activateNextSubWindowAction, SIGNAL(triggered()), mdiMain, SLOT(activateNextSubWindow()));

  activatePreviousSubWindowAction = new QAction(this);
  activatePreviousSubWindowAction->setIcon(QIcon::fromTheme("find-previous", QIcon(":/images/svg/go-previous-view.svg")));
  activatePreviousSubWindowAction->setShortcut(QKeySequence::PreviousChild);
  connect(activatePreviousSubWindowAction, SIGNAL(triggered()), mdiMain, SLOT(activatePreviousSubWindow()));

  closeActiveSubWindowAction = new QAction(this);
  closeActiveSubWindowAction->setIcon(QIcon::fromTheme("document-close", QIcon(":/images/svg/document-close-4.svg")));
  connect(closeActiveSubWindowAction, SIGNAL(triggered()), mdiMain, SLOT(closeActiveSubWindow()));

  closeAllSubWindowsAction = new QAction(this);
  closeAllSubWindowsAction->setIcon(QIcon::fromTheme("window-close", QIcon(":/images/svg/window-close-3.svg")));
  connect(closeAllSubWindowsAction, SIGNAL(triggered()), mdiMain, SLOT(closeAllSubWindows()));

  tileSubWindowsAction = new QAction(this);
  tileSubWindowsAction->setIcon(QIcon::fromTheme("view-sort-ascending", QIcon(":/images/svg/view-sort-ascending-2.svg")));
  connect(tileSubWindowsAction, SIGNAL(triggered()), mdiMain, SLOT(tileSubWindows()));

  shutdownServerAction = new QAction(this);
  shutdownServerAction->setIcon(QIcon::fromTheme("system-shutdown", QIcon(":/images/svg/system-shutdown-6.svg")));
  shutdownServerAction->setDisabled(true);
  connect(shutdownServerAction, SIGNAL(triggered()), this, SLOT(shutdownServerActionTriggered()));

  cssEditorAction = new QAction(this);
  cssEditorAction->setIcon(QIcon(":/images/svg/text-css.svg"));
  connect(cssEditorAction, SIGNAL(triggered()), this, SLOT(cssEditorActionTriggered()));

  htmlEditorAction = new QAction(this);
  htmlEditorAction->setIcon(QIcon::fromTheme("text-html", QIcon(":/images/svg/text-html.svg")));
  connect(htmlEditorAction, SIGNAL(triggered()), this, SLOT(htmlEditorActionTriggered()));

  javascriptEditorAction = new QAction(this);
  javascriptEditorAction->setIcon(QIcon::fromTheme("text-x-generic", QIcon(":/images/svg/text-x-generic.svg")));
  connect(javascriptEditorAction, SIGNAL(triggered()), this, SLOT(javasctiptEditorActionTriggered()));

  openExternalWebPage = new QAction(this);
  openExternalWebPage->setIcon(QIcon::fromTheme("applications-internet", QIcon(":/images/svg/applications-internet-5.svg")));
  connect(openExternalWebPage, SIGNAL(triggered()), this, SLOT(externalWebPageActionTriggered()));

  toggleFullScreenAction = new QAction(this);
  toggleFullScreenAction->setIcon(QIcon::fromTheme("view-fullscreen", QIcon(":/images/svg/view-fullscreen-6.svg")));
  toggleFullScreenAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F10));
  toggleFullScreenAction->setCheckable(true);
  connect(toggleFullScreenAction, SIGNAL(triggered(bool)), this, SLOT(toggleFullScreenActionTriggered(bool)));

  objectsDiagramAction = new QAction(this);
  objectsDiagramAction->setIcon(QIcon(":/images/svg/application-vnd.oasis.opendocument.graphics.svg"));
  connect(objectsDiagramAction, SIGNAL(triggered()), this, SLOT(objectsDiagramActionTriggered()));

  openFileAction = new QAction(this);
  openFileAction->setIcon(QIcon::fromTheme("document-open", QIcon(":/images/svg/document-open-7.svg")));
  connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFileActionTriggered()));

  recentFilesActionGroup = new QActionGroup(this);
  connect(recentFilesActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(recentFilesActionGroupTriggered(QAction*)));

  textEditorAction = new QAction(this);
  textEditorAction->setIcon(QIcon::fromTheme("document-new", QIcon(":/images/svg/document-new-6.svg")));
  connect(textEditorAction, SIGNAL(triggered()), this, SLOT(textEditorActionTriggered()));

  stopReplicationSlaveAction = new QAction(this);
  stopReplicationSlaveAction->setIcon(QIcon::fromTheme("process-stop", QIcon(":/images/svg/process-stop-7.svg")));
  connect(stopReplicationSlaveAction, SIGNAL(triggered()), this, SLOT(stopReplicationSlaveActionTriggered()));

  resetSlaveAction = new QAction(this);
  resetSlaveAction->setIcon(QIcon::fromTheme("system-reboot", QIcon(":/images/svg/system-reboot-2.svg")));
  connect(resetSlaveAction, SIGNAL(triggered()), this, SLOT(maintenanceResetSlaveActionTriggered()));

  startReplicationSlaveAction = new QAction(this);
  startReplicationSlaveAction->setIcon(QIcon::fromTheme("start-here", QIcon(":/images/svg/start-here.svg")));
  connect(startReplicationSlaveAction, SIGNAL(triggered()), this, SLOT(startReplicationSlaveActionTriggered()));

  rebootReplicationSlaveAction = new QAction(this);
  rebootReplicationSlaveAction->setIcon(QIcon::fromTheme("system-reboot", QIcon(":/images/svg/system-reboot-2.svg")));
  connect(rebootReplicationSlaveAction, SIGNAL(triggered()), this, SLOT(rebootReplicationSlaveActionTriggered()));

  replicationInformationAction = new QAction(this);
  replicationInformationAction->setIcon(QIcon::fromTheme("dialog-information", QIcon(":/images/svg/dialog-information-4.svg")));
  connect(replicationInformationAction, SIGNAL(triggered()), this, SLOT(replicationInformationActionTriggered()));

  maintenanceFlushPrivilegesAction = new QAction(QIcon(":/images/svg/system-run-5.svg"), "FLUSH PRIVILEGES", this);
  connect(maintenanceFlushPrivilegesAction, SIGNAL(triggered()), this, SLOT(maintenanceFlushPrivilegesActionTriggered()));

  maintenancePurgeBinaryLogsAction = new QAction(QIcon(":/images/svg/system-run-5.svg"), "PURGE BINARY LOGS BEFORE NOW()", this);
  connect(maintenancePurgeBinaryLogsAction, SIGNAL(triggered()), this, SLOT(maintenancePurgeBinaryLogsActionTriggered()));

  maintenanceFlushRelayLogsAction = new QAction(QIcon(":/images/svg/system-run-5.svg"), "FLUSH RELAY LOGS", this);
  connect(maintenanceFlushRelayLogsAction, SIGNAL(triggered()), this, SLOT(maintenanceFlushRelayLogsActionTriggered()));

  maintenanceTimeDifferenceAction = new QAction(this);
  maintenanceTimeDifferenceAction->setIcon(QIcon(":/images/svg/view-calendar-time-spent.svg"));
  connect(maintenanceTimeDifferenceAction, SIGNAL(triggered()), this, SLOT(maintenanceTimeDifferenceActionTriggered()));

  showSlowLogAction = new QAction(this);
  showSlowLogAction->setIcon(QIcon(":/images/svg/system-run-5.svg"));
  connect(showSlowLogAction, SIGNAL(triggered()), this, SLOT(showSlowLogActionTriggered()));

  postgresqlOnLineHelpAction = new QAction(this);
  postgresqlOnLineHelpAction->setIcon(QIcon(":/images/svg/postgresql.svg"));
  connect(postgresqlOnLineHelpAction, SIGNAL(triggered()), this, SLOT(postgresqlOnLineHelpActionTriggered()));

  mariadbOnLineHelpAction = new QAction(this);
  mariadbOnLineHelpAction->setIcon(QIcon(":/images/svg/MariaDB-seal.svg"));
  connect(mariadbOnLineHelpAction, SIGNAL(triggered()), this, SLOT(mariadbOnLineHelpActionTriggered()));

  //Catalogs' Actions
  catalogsRefreshAction = new QAction(this);
  catalogsRefreshAction->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));

  catalogsReadOnlyAction = new QAction(this);
  catalogsReadOnlyAction->setIcon(QIcon::fromTheme("system-lock-screen", QIcon(":/images/svg/system-lock-screen-5.svg")));
  catalogsReadOnlyAction->setCheckable(true);
  catalogsReadOnlyAction->setChecked(true);

  catalogsNewDatabaseAction = new QAction(this);
  catalogsNewDatabaseAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  catalogsNewDatabaseAction->setEnabled(false);

  catalogsDeleteDatabaseAction = new QAction(this);
  catalogsDeleteDatabaseAction->setIcon(QIcon::fromTheme("edit-delete", QIcon(":/images/svg/edit-delete-6.svg")));
  catalogsDeleteDatabaseAction->setEnabled(false);

  catalogsPopulateTableAction = new QAction(this);
  catalogsPopulateTableAction->setIcon(QIcon(":/images/svg/insert-object.svg"));
  catalogsPopulateTableAction->setEnabled(false);

  viewRecentFilesAction = new QAction(this);
  viewRecentFilesAction->setIcon(QIcon::fromTheme("document-open-recent", QIcon(":/images/svg/document-open-recent-3.svg")));
  viewRecentFilesAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_R));
  connect(viewRecentFilesAction, SIGNAL(triggered()), this, SLOT(viewRecentFilesActionTriggered()));

  recentURLsActionGroup = new QActionGroup(this);
  connect(recentURLsActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(recentURLsActionGroupTriggered(QAction*)));

  clearRecentURLsAction = new QAction(this);
  clearRecentURLsAction->setIcon(QIcon::fromTheme("edit-clear", QIcon(":/images/svg/computerjanitor.svg")));
  connect(clearRecentURLsAction, SIGNAL(triggered()), this, SLOT(clearRecentURLsActionTriggered()));

  databaseComparisionAction = new QAction(this);
  databaseComparisionAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  databaseComparisionAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_D));
  connect(databaseComparisionAction, SIGNAL(triggered()), this, SLOT(databaseComparisionActionTriggered()));

  migrateDatabaseAction = new QAction(this);
  migrateDatabaseAction->setIcon(QIcon(":/images/svg/server-database.svg"));
  migrateDatabaseAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_Y));
  connect(migrateDatabaseAction, SIGNAL(triggered()), this, SLOT(migrateDatabaseActionTriggered()));

  openRecentConnectionActionGroup = new QActionGroup(this);
  connect(openRecentConnectionActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(openRecentConnectionActionGroupTriggered(QAction*)));

  takeASnapShotAction = new QAction(this);
  takeASnapShotAction->setIcon(QIcon::fromTheme("camera-photo", QIcon(":/images/svg/camera-photo-6.svg")));
  connect(takeASnapShotAction, SIGNAL(triggered()), this, SLOT(takeASnapShotActionTriggered()));

  caliopeSourceDocumentationAction = new QAction(this);
  caliopeSourceDocumentationAction->setIcon(windowIcon());
  connect(caliopeSourceDocumentationAction, SIGNAL(triggered()), this, SLOT(caliopeSourceDocumentationActionTriggered()));
}

void MainWindow::objectsDiagramActionTriggered()
{
  if (serverConnection->testOpened()) {
    objectsDiagram = mdiMain->findChild<ObjectsDiagram *>(tr("Objects Diagram"));
    if (!objectsDiagram) {
      objectsDiagram = new ObjectsDiagram;
      addSubWindow(objectsDiagram);
    }
    mdiMain->setActiveSubWindow(objectsDiagram);
  }
}

void MainWindow::openFileActionTriggered()
{
  openFile();
}

void MainWindow::openRecentFilesMenuAboutToShowSlot()
{
  QSettings settings;
  QString setting;
  openRecentFilesMenu->clear();
  setting = "RecentMariaDBFiles/Files";
  QStringList fileList = settings.value(setting, QStringList()).toStringList();
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(StaticFunctions::iconFromFileName(file), file));
  setting = "RecentPHPFiles/Files";
  fileList = settings.value(setting, QStringList()).toStringList();
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(StaticFunctions::iconFromFileName(file), file));
  setting = "RecentCSSFiles/Files";
  fileList = settings.value(setting, QStringList()).toStringList();
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(StaticFunctions::iconFromFileName(file), file));
  setting = "RecentHTMLFiles/Files";
  fileList = settings.value(setting, QStringList()).toStringList();
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(StaticFunctions::iconFromFileName(file), file));
  setting = "RecentJavaScriptFiles/Files";
  fileList = settings.value(setting, QStringList()).toStringList();
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(StaticFunctions::iconFromFileName(file), file));
}

void MainWindow::recentFilesActionGroupTriggered(QAction *action)
{
  openFile(action->text());
}

//void MainWindow::projectFilesSlot()
//{
//  projectFilesMenu->clear();
//  projectFilesMenu->addActions(projects->getProjectFiles());
//}

void MainWindow::openFile(QString fileName, unsigned int line)
{
  if (fileName.isEmpty()) {
    QFileDialog fileDialog;
    fileDialog.setDirectory(QDir::home());
    fileName = fileDialog.getOpenFileName(0, tr("Open a file"), QDir::home().absolutePath());
  }
  QApplication::setOverrideCursor(Qt::WaitCursor);
  switch(StaticFunctions::findEditorType(fileName)) {
  case EditorTypes::SQLQuery:
    sqlScriptActionTriggered();
    sqlEditor->openFile(fileName);
    if (line > 1)
      sqlEditor->gotoLine(line);
    break;
  case EditorTypes::PHP:
    phpScriptActionTriggered();
    phpEditor->openFile(fileName);
    if (line > 1)
      phpEditor->gotoLine(line);
    break;
  case EditorTypes::CSS:
    cssEditorActionTriggered();
    cssEditor->openFile(fileName);
    if (line > 1)
      cssEditor->gotoLine(line);
    break;
  case EditorTypes::HTML:
    htmlEditorActionTriggered();
    htmlEditor->openFile(fileName);
    if (line > 1)
      htmlEditor->gotoLine(line);
    break;
  case EditorTypes::JavaScript:
    javasctiptEditorActionTriggered();
    javascriptEditor->openFile(fileName);
    if (line > 1)
      javascriptEditor->gotoLine(line);
    break;
  case EditorTypes::NoEditor:
    textEditorActionTriggered();
    textEditor->openFile(fileName);
    if (line > 1)
      textEditor->gotoLine(line);
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
    break;
  // default: Q_ASSERT(false);
  }
  QApplication::restoreOverrideCursor();
}

void MainWindow::setProgressBarProgressSlot(const double progress)
{
  dStatusBar->setProgress(progress);
}

void MainWindow::javasctiptEditorActionTriggered()
{
//  if (optionsDock->isVisible())
//    optionsDock->hide();
  javascriptEditor = new TextEditor(projects, this->serverConnection, EditorTypes::JavaScript, ++javascriptWindowCounter);
  connect(javascriptEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(javascriptEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(javascriptEditor);
}

void MainWindow::htmlEditorActionTriggered()
{
//  if (optionsDock->isVisible())
//    optionsDock->hide();
  htmlEditor = new TextEditor(projects, this->serverConnection, EditorTypes::HTML, ++htmlWindowCounter);
  connect(htmlEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(htmlEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(htmlEditor);
}

void MainWindow::textEditorActionTriggered()
{
//  if (optionsDock->isVisible())
//    optionsDock->hide();
  textEditor = new TextEditor(projects, this->serverConnection, EditorTypes::NoEditor, ++textWindowCounter);
  connect(textEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(textEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(textEditor);
}

void MainWindow::stopReplicationSlaveActionTriggered()
{
  serverConnection->stopReplicationSlave();
  statusBarMessage(tr("The replication slave has been stoped."));
}

void MainWindow::startReplicationSlaveActionTriggered()
{
  serverConnection->startReplicationSlave();
  statusBarMessage(tr("The replication slave has been started."));
}

void MainWindow::rebootReplicationSlaveActionTriggered()
{
  serverConnection->rebootReplicationSlave();
  statusBarMessage(tr("The replication slave has been rebooted."));
}

void MainWindow::replicationInformationActionTriggered()
{
  serverInformationActionTriggered();
  serverInformationTab->setCurrentTab(1);
}

void MainWindow::maintenanceFlushPrivilegesActionTriggered()
{
  serverConnection->flushPrivileges();
  statusBarMessage(tr("Privileges flushed."));
}

void MainWindow::maintenancePurgeBinaryLogsActionTriggered()
{
  serverConnection->purgeBinaryLogs();
  statusBarMessage(tr("Logs purged."));
}

void MainWindow::maintenanceTimeDifferenceActionTriggered()
{
  QMessageBox::information(this, tr("Time Difference")
                           , tr("Seconds of difference: %1").arg(serverConnection->runQuerySingleColumn("SELECT UNIX_TIMESTAMP()").at(0).toLongLong()
                                                                 - (QDateTime::currentMSecsSinceEpoch() / 1000)));
}

void MainWindow::showSlowLogActionTriggered()
{
  QDialog *dialog = new QDialog(this);
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->addWidget(new DTitleLabel(tr("Select a date")));
  QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
  dateTimeEdit->setDisplayFormat("yyyy-MMM-dd hh:mm:ss");
  mainVLayout->addWidget(dateTimeEdit);
  QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
  connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
  connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
  mainVLayout->addWidget(buttonBox);
  dialog->setLayout(mainVLayout);
  if (dialog->exec() == QDialog::Accepted)
    showResultTab("slow_log", "mysql", "`start_time` >= '" + dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss") + "'");
}

void MainWindow::postgresqlOnLineHelpActionTriggered()
{
//  if (optionsDock->isVisible())
//    optionsDock->hide();
  dWebView = new DWebView(tr("PostgreSQL On-Line Help"), QUrl("http://www.postgresql.org/docs/manuals/"));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  addSubWindow(dWebView);
}

void MainWindow::mariadbOnLineHelpActionTriggered()
{
//  if (optionsDock->isVisible())
//    optionsDock->hide();
  dWebView = new DWebView(tr("MariaDB On-Line Help"), QUrl("https://kb.askmonty.org"));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  addSubWindow(dWebView);
}

void MainWindow::catalogsReadOnlyActionSlot(bool readOnly)
{
  catalogsNewDatabaseAction->setEnabled(!readOnly);
  catalogsDeleteDatabaseAction->setEnabled(!readOnly);
  catalogsPopulateTableAction->setEnabled(!readOnly);
  catalogs->setReadOnly(readOnly);
}

void MainWindow::viewRecentFilesActionTriggered()
{
  QPoint point = pos();
  point.setX(point.x() + (width() / 2) - (openRecentFilesMenu->width() / 2));
  point.setY(point.y() + (height() / 2) - (openRecentFilesMenu->height() / 2));
  openRecentFilesMenu->popup(point);
}

void MainWindow::recentURLsActionGroupTriggered(QAction *action)
{
  dWebView = new DWebView(tr("External Web Page"), QUrl(action->text()));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  addSubWindow(dWebView);
}

void MainWindow::openRecentURLsMenuAboutToShowSlot()
{
  QSettings settings;
  externalWebPageMenu->clear();
  externalWebPageMenu->addAction(openExternalWebPage);
  externalWebPageMenu->addSeparator()->setText(tr("Visited sites"));
  foreach (QString url, settings.value("Internet/VisitedURLs", QStringList()).toStringList())
    if (!url.isEmpty())
      recentURLsActionGroup->addAction(externalWebPageMenu->addAction(QIcon::fromTheme("applications-internet", QIcon(":/images/svg/applications-internet-5.svg")), url));
  externalWebPageMenu->addAction(clearRecentURLsAction);
}

void MainWindow::clearRecentURLsActionTriggered()
{
  QSettings settings;
//  settings.beginGroup("Internet/VisitedURLs");
  settings.remove("Internet/VisitedURLs");
  //  settings.endGroup();
}

void MainWindow::maintenanceResetSlaveActionTriggered()
{
  serverConnection->resetSlave();
  statusBarMessage(tr("The slave has been reset."));
}

void MainWindow::maintenanceFlushRelayLogsActionTriggered()
{
  serverConnection->flushRelayLogs();
  statusBarMessage(tr("Logs flushed."));
}

void MainWindow::databaseComparisionActionTriggered()
{
  if (serverConnection->testOpened()) {
    databaseComparision = mdiMain->findChild<DatabaseComparision *>(tr("Database Comparision"));
    if (!databaseComparision) {
      databaseComparision = new DatabaseComparision(this->serverConnection);
      connect(databaseComparision, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
      addSubWindow(databaseComparision);
    }
    mdiMain->setActiveSubWindow(databaseComparision);
  }
}

void MainWindow::migrateDatabaseActionTriggered()
{
  ConnectDialog *connectFrom = new ConnectDialog(this->serverConnection);
  QStringList argumentsProcess1;
  QStringList argumentsProcess2;
  QStringList params;
  secondaryServerConnection = new DBMS(false);
  connect(secondaryServerConnection, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(secondaryServerConnection, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  processMariaDBDump = new QProcess;
  processMariaDB = new QProcess;
  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    connect(processMariaDBDump, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardErrorDatabaseMigrationDumpSlot()));
    connect(processMariaDB, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardErrorDatabaseMigrationMariaDBSlot()));
    connect(processMariaDB, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finishedDatabaseMigrationSlot(int)));
    processMariaDBDump->setStandardOutputProcess(processMariaDB);
    if (connectFrom->exec() == QDialog::Accepted) {
      params = connectFrom->getValues();
      argumentsProcess1 << "--user=" + params.at(3);
      argumentsProcess1 << "--host=" + params.at(1);
      argumentsProcess1 << "--password=" + params.at(4);
      argumentsProcess1 << "--port=" + params.at(2);
      argumentsProcess1 << params.at(5);
      connectFrom = new ConnectDialog(secondaryServerConnection);
      if (connectFrom->exec() == QDialog::Accepted) {
        params = connectFrom->getValues();
        argumentsProcess2 << "--user=" + params.at(3);
        argumentsProcess2 << "--host=" + params.at(1);
        argumentsProcess2 << "--password=" + params.at(4);
        argumentsProcess2 << "--port=" + params.at(2);
        argumentsProcess2 << params.at(5);
        if (secondaryServerConnection->isOpened())
          secondaryServerConnection->close();
        params = connectFrom->getValues();
        secondaryServerConnection->setUserName(params.at(3));
        secondaryServerConnection->setHostName(params.at(1));
        secondaryServerConnection->setPassword(params.at(4));
        secondaryServerConnection->setDatabase(params.at(5));
        secondaryServerConnection->setPort(params.at(2).toUInt());

        timerTableCount = new QTimer(this);
        timerTableCount->setInterval(2000);
        connect(timerTableCount, SIGNAL(timeout()), this, SLOT(tableCountSlot()));
        if (secondaryServerConnection->open()) {
          //      timerTableCount->start();
          migrationProgressDialog = new QProgressDialog(tr("Migrating data"), tr("Abort"), 0, 0, this);
          migrationProgressDialog->setWindowModality(Qt::WindowModal);
          connect(migrationProgressDialog, SIGNAL(canceled()), this, SLOT(cancelDatabaseMigrationSlot()));
          processMariaDBDump->start("mysqldump", argumentsProcess1);
          processMariaDB->start("mysql", argumentsProcess2);
          migrationProgressDialog->show();
          secondaryServerConnection->close();
        }
      }
    }
    break;
  case StaticFunctions::PostgreSQL:
  case StaticFunctions::Undefined:
  default:
    QMessageBox::information(this, tr("Database migration"), tr("Database migration is only aviable for MariaDB and MySQL."));
    break;
  }
}

void MainWindow::tableCountSlot()
{
  statusBarMessage(tr("Table count: %1").arg(secondaryServerConnection->database(secondaryServerConnection->getDatabase())->tableCount()));
}

void MainWindow::connectionMenuAboutToShowSlot()
{
  if (!serverConnection->isOpened()) {
    closeCurrentConnectionAction->setEnabled(false);
    changeCharsetMenu->setEnabled(false);
    changeDatabaseMenu->setEnabled(false);
    replicationMenu->setEnabled(false);
    maintenanceMenu->setEnabled(false);
    shutdownServerAction->setEnabled(false);
  } else {
    closeCurrentConnectionAction->setEnabled(true);
    changeCharsetMenu->setEnabled(true);
    changeDatabaseMenu->setEnabled(true);
    replicationMenu->setEnabled(true);
    maintenanceMenu->setEnabled(true);
    shutdownServerAction->setEnabled(true);
  }
  QSettings settings;
  viewQueryLogAction->setEnabled(settings.value("EnableQueryLog", false).toBool());
}

void MainWindow::openRecentConnectionMenuAboutToShowSlot()
{
  QSettings settings;
  openRecentConnectionMenu->clear();

  settings.beginGroup("ServerConnections");
  QStringList connections = settings.allKeys();
  connections.removeAt(connections.indexOf("StorePassword"));
  connections.sort();
  foreach (QString connection, connections)
   if (!connection.isEmpty())
     openRecentConnectionActionGroup->addAction(openRecentConnectionMenu->addAction(connection));
  settings.endGroup();
}

void MainWindow::openRecentConnectionActionGroupTriggered(QAction *action)
{
  QStringList params = StaticFunctions::explodeConnectionString(action->text());
  if (serverConnection->isOpened())
    serverConnection->close();
  serverConnection->setUserName(params.at(1));
  serverConnection->setHostName(params.at(2));
  serverConnection->setPassword(StaticFunctions::password(params.at(5)));
  serverConnection->setDatabase(params.at(4));
  serverConnection->setPort(params.at(3).toUInt());
  if (!serverConnection->open())
    QMessageBox::critical(this, tr("Cannot connect to the server"), serverConnection->lastError());
  if (serverConnection->isOpened()) {
    statusBarMessage(tr("Connected successfully to: %1").arg(serverConnection->getHostName()));
    enabledDisableConnectionMenus(true);
    setTitle();
  }
}

void MainWindow::viewQueryLogActionSlot()
{
  dQueryLog = mdiMain->findChild<DQueryLog *>(tr("Query Log"));
  if (!dQueryLog) {
    dQueryLog = new DQueryLog(serverConnection);
    addSubWindow(dQueryLog);
  }
  mdiMain->setActiveSubWindow(dQueryLog);
}

void MainWindow::updatedatabaseInformationMenu()
{
  databaseInformationMenu->clear();
  foreach (QString database, serverConnection->getDatabases()) {
    QAction *action = databaseInformationMenu->addAction(database);
    action->setIcon(QIcon(":/images/svg/server-database.svg"));
    connect(action, SIGNAL(triggered()), databaseInformationMapper, SLOT(map()));
    databaseInformationMapper->setMapping(action, database);
  }
}

void MainWindow::databaseInformationSlot(QString database)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QString information = "";
  foreach (QString info, serverConnection->database(database)->info())
    information += info + "\n";
  QApplication::restoreOverrideCursor();
  QMessageBox::information(this, tr("Database information"), information);
}

void MainWindow::takeASnapShotActionTriggered()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString imageFormats;
  foreach(QString format, QImageWriter::supportedImageFormats())
    imageFormats += "*." + format + " ";
  QString file = fileDialog.getSaveFileName(this, tr("Save to Image"), settings.value("LastFileImg", QDir::home().absolutePath()).toString(), tr("Image files (%1)").arg(imageFormats));
  settings.setValue("LastFileImg", fileDialog.directory().filePath(file));
  QPixmap pixmap(this->size());
  this->render(&pixmap);
  pixmap.save(file, "PNG", 5);
  QApplication::restoreOverrideCursor();
  statusBarMessage(tr("File saved at: %1").arg(file));
}

void MainWindow::caliopeSourceDocumentationActionTriggered()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QDir tempDir(QDir::tempPath() + "/html");
  tempDir.removeRecursively();
  tempDir.mkpath(QDir::tempPath() + "/html/search");
  QFile fileList(":/documentation/docs/filelist.txt");
  fileList.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream stream(&fileList);
  while (!stream.atEnd()) {
    QString fileName(stream.readLine());
    QFile fileToOpen(":/documentation/docs" + fileName);
    if (!fileToOpen.open(QIODevice::ReadOnly | QIODevice::Text))
      qDebug() << fileName << fileToOpen.error();
    //Work arround since fileToOpen.copy is not coping HTML file correctly.
    if (fileName.endsWith(".html") || fileName.endsWith(".css") || fileName.endsWith(".js")) {
      QFile fileToSave(QDir::tempPath() + fileName);
      if (!fileToSave.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << fileName << fileToOpen.error();
      QTextStream out(&fileToSave);
      out << fileToOpen.readAll();
      fileToSave.close();
      fileToOpen.close();
    } else {
      if (!fileToOpen.copy(QDir::tempPath() + fileName))
        qDebug() << fileName << fileToOpen.error();
    }
  }
  dWebView = new DWebView(tr("Calíope source documentation"), QUrl("file:///tmp/html/index.html"));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  connect(dWebView, SIGNAL(showPagesource(QString)), this, SLOT(viewDWebViewPageSource(QString)));
  addSubWindow(dWebView);
  QApplication::restoreOverrideCursor();
}

void MainWindow::viewDWebViewPageSource(QString pageSource)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  htmlEditor = new TextEditor(projects, this->serverConnection, EditorTypes::HTML, ++htmlWindowCounter);
  connect(htmlEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(htmlEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(htmlEditor);
  htmlEditor->textEditor->setPlainText(pageSource);
  QApplication::restoreOverrideCursor();
}

void MainWindow::mariaDBGUIHelpActionTriggered()
{

}

void MainWindow::finishedDatabaseMigrationSlot(int exitCode)
{
  if (exitCode == QProcess::NormalExit && processMariaDBDump->exitCode() == QProcess::NormalExit) {
    migrationProgressDialog->close();
    secondaryServerConnection->close();
    timerTableCount->stop();
    QMessageBox::information(this, tr("Database migration"), tr("Migration done."));
  }
}

void MainWindow::readyReadStandardErrorDatabaseMigrationDumpSlot()
{
  migrationProgressDialog->close();
  QMessageBox::warning(this, tr("Database migration"), QString(processMariaDBDump->readAllStandardError()));
  processMariaDBDump->close();
  processMariaDB->close();
  timerTableCount->stop();
  secondaryServerConnection->close();
}

void MainWindow::readyReadStandardErrorDatabaseMigrationMariaDBSlot()
{
  migrationProgressDialog->close();
  QMessageBox::warning(this, tr("Database migration"), QString(processMariaDB->readAllStandardError()));
  processMariaDB->close();
  processMariaDBDump->close();
  timerTableCount->stop();
  secondaryServerConnection->close();
}

void MainWindow::cancelDatabaseMigrationSlot()
{
  migrationProgressDialog->close();
  processMariaDBDump->close();
  processMariaDB->close();
  timerTableCount->stop();
  secondaryServerConnection->close();
//  QMessageBox::warning(this, tr("Database migration"), tr("Migration process canceled"));
}

void MainWindow::cssEditorActionTriggered()
{
//  if (optionsDock->isVisible())
//    optionsDock->hide();
  cssEditor = new TextEditor(projects, this->serverConnection, EditorTypes::CSS, ++cssWindowCounter);
  connect(cssEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(cssEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(cssEditor);
}

void MainWindow::shutdownServerActionTriggered()
{
  if (serverConnection->shutdown())
    statusBarMessage(tr("The database server has been shutdown."));
}

void MainWindow::retranslateUi()
{
  //createActions
  exitAction->setText(tr("&Quit"));
  exitAction->setStatusTip(tr("Exits the application."));

  aboutQtAction->setText(tr("About &Qt"));
  aboutQtAction->setStatusTip(tr("Shows the About dialog for Qt."));

  aboutMariaDBGUIAction->setText(tr("About Calíope"));
  aboutMariaDBGUIAction->setStatusTip(tr("Shows the About dialog for Calíope."));

  connectToServerAction->setText(tr("Connect to Server..."));
  connectToServerAction->setStatusTip(tr("Connect to a Database Server."));

  serverInformationAction->setText(tr("Server Information"));
  serverInformationAction->setStatusTip(serverInformationAction->text());

  userAdministrationAction->setText(tr("User Administration"));
  userAdministrationAction->setStatusTip(userAdministrationAction->text());

  backupAction->setText(tr("Backup"));
  backupAction->setStatusTip(backupAction->text());

  restoreAction->setText(tr("Restore Backup"));
  restoreAction->setStatusTip(restoreAction->text());

  catalogsAction->setText(tr("Catalogs"));
  catalogsAction->setStatusTip(catalogsAction->text());

  queryAction->setText(tr("Query"));
  queryAction->setStatusTip(queryAction->text());

  tableMaintenanceAction->setText(tr("Table Maintenance"));
  tableMaintenanceAction->setStatusTip(tableMaintenanceAction->text());

  mysqlScriptAction->setText(tr("SQL Script"));
  mysqlScriptAction->setStatusTip(mysqlScriptAction->text());

  phpScriptAction->setText(tr("PHP Script"));
  phpScriptAction->setStatusTip(phpScriptAction->text());

  mariaDBGUIHelpAction->setText(tr("Calíope"));
  mariaDBGUIHelpAction->setStatusTip(mariaDBGUIHelpAction->text());

  mysqlHelpAction->setText(tr("MySQL Help"));
  mysqlHelpAction->setStatusTip(mysqlHelpAction->text());

  viewQueryLogAction->setText(tr("View query log"));
  viewQueryLogAction->setStatusTip(viewQueryLogAction->text());

  mysqlOnLineHelpAction->setText(tr("MySQL On-Line Help"));
  mysqlOnLineHelpAction->setStatusTip(mysqlOnLineHelpAction->text());

  phpOnLineHelpAction->setText(tr("PHP On-Line Help"));
  phpOnLineHelpAction->setStatusTip(phpOnLineHelpAction->text());

  preferencesAction->setText(tr("Preferences"));
  preferencesAction->setStatusTip(preferencesAction->text());

  processAction->setText(tr("Processes"));

  showFileToolBarAction->setText(tr("&File Toolbar"));
  showFileToolBarAction->setStatusTip(showFileToolBarAction->text());

//  showOptionsDockAction->setText(tr("Options"));
//  showOptionsDockAction->setStatusTip(showOptionsDockAction->text());

  closeCurrentConnectionAction->setText(tr("&Close connection"));
  closeCurrentConnectionAction->setStatusTip(tr("Close current database connection"));

  cascadeSubWindowsAction->setText(tr("Cascade windows"));
  cascadeSubWindowsAction->setStatusTip(cascadeSubWindowsAction->text());

  activateNextSubWindowAction->setText(tr("Next window"));
  activateNextSubWindowAction->setStatusTip(activateNextSubWindowAction->text());

  activatePreviousSubWindowAction->setText(tr("Previous window"));
  activatePreviousSubWindowAction->setStatusTip(activatePreviousSubWindowAction->text());

  closeActiveSubWindowAction->setText(tr("Close current window"));
  closeActiveSubWindowAction->setStatusTip(closeActiveSubWindowAction->text());

  closeAllSubWindowsAction->setText(tr("Close all windows"));
  closeAllSubWindowsAction->setStatusTip(closeAllSubWindowsAction->text());

  tileSubWindowsAction->setText(tr("Tile windows"));
  tileSubWindowsAction->setStatusTip(tileSubWindowsAction->text());

  shutdownServerAction->setText(tr("Shutdown Database Server"));
  shutdownServerAction->setStatusTip(shutdownServerAction->text());

  cssEditorAction->setText(tr("CSS Editor"));
  cssEditorAction->setStatusTip(cssEditorAction->text());

  htmlEditorAction->setText(tr("HTML Editor"));
  htmlEditorAction->setStatusTip(htmlEditorAction->text());

  javascriptEditorAction->setText(tr("JavaScript Editor"));
  javascriptEditorAction->setStatusTip(javascriptEditorAction->text());

  openExternalWebPage->setText(tr("Web site"));
  openExternalWebPage->setStatusTip(openExternalWebPage->text());

  toggleFullScreenAction->setText(tr("Full screen"));
  toggleFullScreenAction->setStatusTip(toggleFullScreenAction->text());

  objectsDiagramAction->setText(tr("Objects diagram"));
  objectsDiagramAction->setStatusTip(objectsDiagramAction->text());

  openFileAction->setText(tr("Open file"));
  openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_O));
  openFileAction->setStatusTip(openFileAction->text());

  textEditorAction->setText(tr("Text Editor"));
  textEditorAction->setStatusTip(textEditorAction->text());

  stopReplicationSlaveAction->setText(tr("Stop Slave"));
  stopReplicationSlaveAction->setStatusTip(textEditorAction->text());

  resetSlaveAction->setText(tr("Reset Slave"));
  resetSlaveAction->setStatusTip(resetSlaveAction->text());

  startReplicationSlaveAction->setText(tr("Start Slave"));
  startReplicationSlaveAction->setStatusTip(textEditorAction->text());

  rebootReplicationSlaveAction->setText(tr("Restart Slave"));
  rebootReplicationSlaveAction->setStatusTip(textEditorAction->text());

  replicationInformationAction->setText(tr("Replication Information"));
  replicationInformationAction->setStatusTip(textEditorAction->text());

  maintenanceFlushPrivilegesAction->setStatusTip(maintenanceFlushPrivilegesAction->text());

  maintenancePurgeBinaryLogsAction->setStatusTip(maintenancePurgeBinaryLogsAction->text());

  maintenanceFlushPrivilegesAction->setStatusTip(maintenanceFlushPrivilegesAction->text());

  maintenanceTimeDifferenceAction->setText(tr("Time Difference"));
  maintenanceTimeDifferenceAction->setStatusTip(maintenanceTimeDifferenceAction->text());

  showSlowLogAction->setText(tr("Show the Slow Log"));
  showSlowLogAction->setStatusTip(showSlowLogAction->text());

  postgresqlOnLineHelpAction->setText(tr("PostgreSQL On-Line Help"));
  postgresqlOnLineHelpAction->setStatusTip(postgresqlOnLineHelpAction->text());

  mariadbOnLineHelpAction->setText(tr("MariaDB On-Line Help"));
  mariadbOnLineHelpAction->setStatusTip(mariadbOnLineHelpAction->text());

  //Create Menus
  editorsMenu->setTitle(tr("Editors"));
//  projectFilesMenu->setTitle(tr("Project files"));
  externalWebPageMenu->setTitle(tr("Open external web page"));
  fileMenu->setTitle(tr("&File"));
  openRecentFilesMenu->setTitle(tr("Recent files"));
  projectMenu->setTitle(tr("&Projects"));
  connectionMenu->setTitle(tr("&Conecction"));
  changeCharsetMenu->setTitle(tr("Change character set"));
  changeDatabaseMenu->setTitle(tr("Change database"));
  replicationMenu->setTitle(tr("Replication"));
  maintenanceMenu->setTitle(tr("Maintenance"));
  viewMenu->setTitle(tr("&View"));
  languageMenu->setTitle(tr("&Languaje"));
  windowMenu->setTitle(tr("&Window"));
  helpMenu->setTitle(tr("&Help"));
  openRecentConnectionMenu->setTitle(tr("Recent connections"));
  databaseInformationMenu->setTitle(tr("Database information"));

  //Create Toobar
  editorsPushButton->setText(tr("Editors"));
  projectFilesPushButton->setText(tr("Project files"));

  viewRecentFilesAction->setText(tr("Select recent file..."));
  viewRecentFilesAction->setStatusTip(viewRecentFilesAction->text());

  catalogsRefreshAction->setText(tr("Refresh"));
  catalogsRefreshAction->setStatusTip(catalogsRefreshAction->text());

  catalogsReadOnlyAction->setText(tr("Read only"));
  catalogsReadOnlyAction->setStatusTip(catalogsReadOnlyAction->text());

  catalogsNewDatabaseAction->setText(tr("Create Database"));
  catalogsNewDatabaseAction->setStatusTip(catalogsNewDatabaseAction->text());

  catalogsDeleteDatabaseAction->setText(tr("Delete Database"));
  catalogsDeleteDatabaseAction->setStatusTip(catalogsDeleteDatabaseAction->text());

  catalogsPopulateTableAction->setText(tr("Populate table"));
  catalogsPopulateTableAction->setStatusTip(catalogsPopulateTableAction->text());

  viewRecentFilesAction->setText(tr("Select recent file..."));
  viewRecentFilesAction->setStatusTip(viewRecentFilesAction->text());

  clearRecentURLsAction->setText(tr("Clear recent files"));
  clearRecentURLsAction->setStatusTip(clearRecentURLsAction->text());

  databaseComparisionAction->setText(tr("Database comparation"));
  databaseComparisionAction->setStatusTip(databaseComparisionAction->text());

  migrateDatabaseAction->setText(tr("Migrate database"));
  migrateDatabaseAction->setStatusTip(migrateDatabaseAction->text());

  takeASnapShotAction->setText(tr("Take a snapshot"));
  takeASnapShotAction->setStatusTip(takeASnapShotAction->text());

  caliopeSourceDocumentationAction->setText(tr("Calíope source documentation"));
  caliopeSourceDocumentationAction->setStatusTip(caliopeSourceDocumentationAction->text());
}

void MainWindow::createInitialSettings()
{
  QSettings settings;
  if (!settings.value("FileAssociations/SQLFiles", false).toBool())
    settings.setValue("FileAssociations/SQLFiles", "sql");
  if (!settings.value("FileAssociations/PHPFiles", false).toBool())
    settings.setValue("FileAssociations/PHPFiles", "php,inc,module");
  if (!settings.value("FileAssociations/CSSFiles", false).toBool())
    settings.setValue("FileAssociations/CSSFiles", "css");
  if (!settings.value("FileAssociations/HTMLFiles", false).toBool())
    settings.setValue("FileAssociations/HTMLFiles", "html,htm");
  if (!settings.value("FileAssociations/JavaScriptFiles", false).toBool())
    settings.setValue("FileAssociations/JavaScriptFiles", "js");
  if (!settings.value("TextEditor/DefaultPointSize", false).toBool())
    settings.setValue("TextEditor/DefaultPointSize", 11);
}

void MainWindow::enabledDisableConnectionMenus(bool enabled)
{
  closeCurrentConnectionAction->setEnabled(enabled);
  changeDatabaseMenu->setEnabled(enabled);
  changeCharsetMenu->setEnabled(enabled);
  shutdownServerAction->setEnabled(enabled);
  replicationMenu->setEnabled(enabled);
  maintenanceMenu->setEnabled(enabled);
  databaseInformationMenu->setEnabled(enabled);
}

void MainWindow::createSystemaTrayIcon()
{
  trayIconEnabled = false;
  if (QSystemTrayIcon::isSystemTrayAvailable()) {
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(exitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(windowIcon());
    trayIcon->setToolTip(QCoreApplication::applicationName());
    trayIcon->setContextMenu(trayIconMenu);
    trayIconEnabled = true;
    trayIcon->show();
  }
}

void MainWindow::preferencesActionTriggered()
{
  preferences = mdiMain->findChild<Preferences *>(tr("Preferences"));
  if (!preferences) {
    preferences = new Preferences();
    addSubWindow(preferences);
  }
  mdiMain->setActiveSubWindow(preferences);
}

void MainWindow::userAdministrationActionTriggered()
{
  if (serverConnection->testOpened()) {
    userAdministration = mdiMain->findChild<Users *>(tr("Users"));
    if (!userAdministration) {
      userAdministration = new Users;
      addSubWindow(userAdministration);
    }
    mdiMain->setActiveSubWindow(userAdministration);
  }
}

void MainWindow::restoreActionTriggered()
{
  if (serverConnection->testOpened()) {
    restore = mdiMain->findChild<Restore *>(tr("Restore"));
    if (!restore) {
      restore = new Restore;
      addSubWindow(restore);
    }
    mdiMain->setActiveSubWindow(restore);
  }
}

void MainWindow::backupActionTriggered()
{
  if (serverConnection->testOpened()) {
    backup = mdiMain->findChild<Backup *>(tr("Backup"));
    if (!backup) {
      backup = new Backup(serverConnection);
      addSubWindow(backup);
    }
    mdiMain->setActiveSubWindow(backup);
  }
}

void MainWindow::sqlScriptActionTriggered()
{
  sqlEditor = new TextEditor(projects, this->serverConnection, EditorTypes::SQLQuery, ++sqlWindowCounter);
  connect(sqlEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(sqlEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(sqlEditor);
}

void MainWindow::phpScriptActionTriggered()
{
  phpEditor = new TextEditor(projects, this->serverConnection, EditorTypes::PHP, ++phpWindowCounter);
  connect(phpEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  connect(phpEditor, SIGNAL(updatePrositionViewer(int,int)), dStatusBar, SLOT(setPrositionViewer(int,int)));
  addSubWindow(phpEditor);
}

void MainWindow::externalWebPageActionTriggered()
{
  dWebView = new DWebView(tr("External Web page"));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  addSubWindow(dWebView);
}

void MainWindow::phpOnLineHelpActionTriggered()
{
  dWebView = new DWebView(tr("PHP On-Line Help"), QUrl("http://php.net/search.php"));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  addSubWindow(dWebView);
}

void MainWindow::mysqlOnLineHelpActionTriggered()
{
  dWebView = new DWebView(tr("MySQL On-Line Help"), QUrl("http://dev.mysql.com/doc/refman/5.5/en/"));
  connect(dWebView, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(dWebView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  addSubWindow(dWebView);
}

void MainWindow::processActionTriggered()
{
  if (serverConnection->testOpened()) {
    processList = mdiMain->findChild<ProcessList *>(tr("Process List"));
    if (!processList) {
      processList = new ProcessList(this->serverConnection);
      addSubWindow(processList);
    }
    mdiMain->setActiveSubWindow(processList);
  }
}

void MainWindow::mysqlHelpActionTriggered()
{
  if (serverConnection->testOpened()) {
    mysqlHelp = mdiMain->findChild<MySQLHelp *>(tr("MySQL On-Line Help"));
    if (!mysqlHelp) {
      mysqlHelp = new MySQLHelp(this->serverConnection);
      addSubWindow(mysqlHelp);
    }
    mdiMain->setActiveSubWindow(mysqlHelp);
  }
}

void MainWindow::queryActionTriggered()
{
  if (serverConnection->testOpened()) {
    query = new SQLQuery(projects, this->serverConnection, ++mysqlQueryWindowCounter);
    addSubWindow(query);
    connect(query, SIGNAL(executionStarted(double)), this, SLOT(setProgressBarProgressSlot(double)));
    connect(query, SIGNAL(executionProgress(double)), this, SLOT(setProgressBarProgressSlot(double)));
    connect(query, SIGNAL(executionFinished(double)) , this, SLOT(setProgressBarProgressSlot(double)));
    connect(query, SIGNAL(showResultTab(QString,QString,QString)), this, SLOT(showResultTab(QString,QString,QString)));
    connect(query, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessage(QString)));
  }
}

void MainWindow::serverInformationActionTriggered()
{
  if (serverConnection->testOpened()) {
    serverInformationTab = mdiMain->findChild<ServerInformation *>(tr("Server Information"));
    if (!serverInformationTab) {
      serverInformationTab = new ServerInformation(this->serverConnection);
      addSubWindow(serverInformationTab);
    }
    mdiMain->setActiveSubWindow(serverInformationTab);
  }
}

void MainWindow::catalogsActionTriggered()
{
  if (serverConnection->testOpened()) {
    catalogs = mdiMain->findChild<Catalogs *>(tr("Catalogs"));
    if (!catalogs) {
      catalogs = new Catalogs(this->serverConnection);
      connect(catalogsNewDatabaseAction, SIGNAL(triggered()), catalogs, SLOT(newDatabaseActionTriggered()));
      connect(catalogsReadOnlyAction, SIGNAL(toggled(bool)), this, SLOT(catalogsReadOnlyActionSlot(bool)));
      connect(catalogsDeleteDatabaseAction, SIGNAL(triggered()), catalogs, SLOT(deleteDatabaseActionTriggered()));
      connect(catalogsPopulateTableAction, SIGNAL(triggered()), catalogs, SLOT(populateTableActionTriggered()));
      connect(catalogsRefreshAction, SIGNAL(triggered()), catalogs, SLOT(updateObjectInfo()));
      connect(this, SIGNAL(databaseChanged()), catalogs, SLOT(updateObjectInfo()));
      connect(catalogs, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
      connect(catalogs, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
      connect(catalogs, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
      connect(catalogs, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
      connect(catalogs, SIGNAL(statusBarMessagePopup(QString)), this, SLOT(statusBarMessagePopup(QString)));
      connect(catalogs, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), this, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
      addSubWindow(catalogs);
    }
    mdiMain->setActiveSubWindow(catalogs);
  }
}

void MainWindow::connectToServerActionTriggered()
{
  ConnectDialog *connectFrom = new ConnectDialog(this->serverConnection);
  QStringList params;
  if (connectFrom->exec() == QDialog::Accepted) {
    if (!connectFrom->getConnectionPerformed()) {
      if (serverConnection->isOpened())
        serverConnection->close();
      params = connectFrom->getValues();
      serverConnection->setUserName(params.at(3));
      serverConnection->setHostName(params.at(1));
      serverConnection->setPassword(params.at(4));
      serverConnection->setDatabase(params.at(5));
      serverConnection->setPort(params.at(2).toUInt());
      if (!serverConnection->open())
        QMessageBox::critical(this, tr("Cannot connect to the server"), serverConnection->lastError());
    }
  }
  if (serverConnection->isOpened()) {
    statusBarMessage(tr("Connected successfully to: %1").arg(serverConnection->getHostName()));
    enabledDisableConnectionMenus(true);
    setTitle();
  }
}

void MainWindow::tableMaintenanceActionTriggered()
{
//  if (serverConnection->testOpened()) {
//    tableMaintenance = mdiMain->findChild<TableMaintenance *>(tr("Table Maintenance"));
//    if (!tableMaintenance) {
//      tableMaintenance = new TableMaintenance(this);
//      mdiMain->addSubWindow(tableMaintenance);
//      tableMaintenance->showMaximized();
//      dStatusBar->resetStatusBar();
//    }
//  }
  if (serverConnection->testOpened()) {
//    optionsDock->hide();
    tableMaintenance = mdiMain->findChild<TableMaintenance *>(tr("Table Maintenance"));
    if (!tableMaintenance) {
      tableMaintenance = new TableMaintenance(this->serverConnection);
      addSubWindow(tableMaintenance);
    }
    mdiMain->setActiveSubWindow(tableMaintenance);
  }
}

void MainWindow::showResultTab(QString table, QString database, QString where)
{
  if (serverConnection->testOpened()) {
    result = mdiMain->findChild<Result *>(tr("Result"));
    if (!result) {
//      if (optionsDock->isVisible())
//        optionsDock->hide();
      result = new Result(this->serverConnection, table, database, where);
      connect(result, SIGNAL(statusBarProgressMessage(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
      addSubWindow(result);
    }
    result->setDatabase(database.isEmpty() ? serverConnection->getDatabase() : database);
    result->setTable(table);
    result->setWhere(where);
    result->updateResult();
    result->showMaximized();
  }
}

void MainWindow::setTitle()
{
  setWindowTitle("[" + projects->name() + "]" + (serverConnection->isOpened() ? serverConnection->getTitle() : ""));
}

//Projects *MainWindow::getCurrentProject()
//{
//  return projects;
//}

bool MainWindow::changeDatabase(QString database)
{
  if (database != serverConnection->getDatabase()) {
    serverConnection->changeDatabase(database);
    setTitle();
    return true;
  }
  return false;
}

//void MainWindow::optionsTreeViewItemClicked(QTreeWidgetItem *item, int column)
//{
//  switch (item->type()) {
//  case ItemTypes::Database:
//    changeDatabase(item->text(column).split(".").at(0));
//    catalogs->updateObjectInfo();
//    break;
//  case ItemTypes::Table:
//    catalogs->selectTable(item->text(column).split(".").at(0), item->text(column).split(".").at(1));
//    break;
//  case ItemTypes::User:
//    userAdministration->userInfo(item->text(column));
//    break;
//  case ItemTypes::UserHost:
//    userAdministration->userInfo(item->parent()->text(column));
//    break;
//  // default: Q_ASSERT(false);
//  }
//}

//void MainWindow::optionsDoubleClickedSlot(QTreeWidgetItem *item, int column)
//{
//  if (item->type() == ItemTypes::Table)
//    showResultTab(item->text(column).split(".").at(1));
//}

//void MainWindow::selectOptionsItem(QString item)
//{
//  optionsTreeView->clearSelection();
//  optionsTreeView->setCurrentItem(optionsTreeView->findItems(serverConnection->getDatabase() + "." + item
//                                                             , Qt::MatchRecursive | Qt::MatchExactly).at(0)
//                                  , 0, QItemSelectionModel::Select);
//}

//void MainWindow::fillOptions(ItemTypes::ItemType type)
//{
//  int maxWidth = 0;
//  QList<QTreeWidgetItem *> items;
//  optionsTreeView->clear();
//  optionsTreeView->setColumnCount(1);

//  switch (type) {
//  case ItemTypes::CatalogsTab:
//    optionsTreeView->setWindowTitle(tr("Databases"));
//    optionsTreeView->setHeaderLabel(optionsTreeView->windowTitle());
//    foreach (QString database, serverConnection->getDatabases()) {
//      if (maxWidth < QString(database).length())
//        maxWidth = QString(database).length();
//      QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(database), ItemTypes::Database);
//      item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
//      items.append(item);
//      foreach (QString table, serverConnection->database(database)->getTables()) {
//        if (maxWidth < QString(table).length())
//          maxWidth = QString(table).length();
//        QTreeWidgetItem *childItem = new QTreeWidgetItem(item, QStringList(database + "." + table), ItemTypes::Table);
//        childItem->setIcon(0, QIcon(":/images/svg/table.svg"));
//        items.append(childItem);
//      }
//    }
//    break;
//  case ItemTypes::UsersTab:
////    optionsTreeView->setWindowTitle(tr("Users"));
////    optionsTreeView->setHeaderLabel(optionsTreeView->windowTitle());
////    rows = serverConnection->getUsers();
////    for (int counter = 0; counter < rows.count(); counter++) {
////      rowsData = serverConnection->getUserHosts(rows.at(counter));
////      if (maxWidth < QString(rows.at(counter)).length())
////        maxWidth = QString(rows.at(counter)).length();
////      item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(rows.at(counter)), ItemTypes::User);
////      item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
////      items.append(item);
////      for (int counter2 = 0; counter2 < rowsData.count(); counter2++) {
////        itemChild = new QTreeWidgetItem(item, QStringList(rowsData.at(counter2)), ItemTypes::UserHost);
////        itemChild->setIcon(0, QIcon(":/images/svg/server-database.svg"));
////        items.append(itemChild);
////      }
////    }
//    break;
//  // default: Q_ASSERT(false);
//  }
//  optionsTreeView->resizeColumnToContents(0);
//  optionsTreeView->insertTopLevelItems(0, items);
//  optionsTreeView->setMaximumWidth(maxWidth * 10);
//}

void MainWindow::createToolBar()
{
  editorsPushButton = new QPushButton(QIcon::fromTheme("accessories-text-editor", QIcon(":/images/svg/accessories-text-editor-7.svg")), "", this);
  editorsPushButton->setMenu(editorsMenu);

  fileToolbar = addToolBar("Main");
  fileToolbar->addWidget(editorsPushButton);
  fileToolbar->addAction(catalogsAction);
  fileToolbar->addAction(queryAction);
  fileToolbar->addAction(processAction);
  fileToolbar->addAction(serverInformationAction);
  //  fileToolBar->addAction(userAdministrationAction);
  //  fileToolBar->addAction(restoreAction);
  //  fileToolBar->addAction(backupAction);
  //  fileToolBar->addAction(mysqlScriptAction);
  //  fileToolBar->addAction(phpScriptAction);
  //  fileToolBar->addAction(tableMaintenanceAction);
  //  fileToolBar->addAction(showOptionsDockAction);
  fileToolbar->setIconSize(QSize(24, 24));

  projectFilesPushButton = new QPushButton(QIcon::fromTheme("accessories-text-editor", QIcon(":/images/svg/accessories-text-editor-7.svg")), "", this);
  projectFilesPushButton->setMenu(projects->projectFilesMenu);
  fileToolbar->addWidget(projectFilesPushButton);

  //Catalogs Toolbar
  catalogsToolbar = addToolBar("Catalogs Toolbar");
  catalogsToolbar->addAction(catalogsReadOnlyAction);
  catalogsToolbar->addSeparator();
  catalogsToolbar->addAction(catalogsRefreshAction);
//  catalogsToolBar->addSeparator();
//  catalogsToolBar->addAction(newObjectAction);
//  catalogsToolBar->addAction(editObjectAction);
//  catalogsToolBar->addAction(deleteObjectAction);
  catalogsToolbar->addSeparator();
  catalogsToolbar->addAction(catalogsNewDatabaseAction);
  catalogsToolbar->addAction(catalogsDeleteDatabaseAction);
  catalogsToolbar->addAction(catalogsPopulateTableAction);
  catalogsToolbar->setIconSize(QSize(24, 24));
  catalogsToolbar->hide();
}

void MainWindow::closeCurrentConnectionActionTriggered()
{
  okToClose();
  setWindowTitle(QCoreApplication::applicationName());
  serverConnection->close();
  enabledDisableConnectionMenus(false);
}

void MainWindow::createMenus()
{
  editorsMenu = new QMenu(this);
  editorsMenu->setIcon(QIcon::fromTheme("accessories-text-editor", QIcon(":/images/svg/accessories-text-editor-7.svg")));
  editorsMenu->addAction(mysqlScriptAction);
  editorsMenu->addAction(phpScriptAction);
  editorsMenu->addAction(cssEditorAction);
  editorsMenu->addAction(htmlEditorAction);
  editorsMenu->addAction(javascriptEditorAction);
  editorsMenu->addAction(textEditorAction);

//  projectFilesMenu = new QMenu(this);
//  projectFilesMenu->setIcon(QIcon::fromTheme("accessories-text-editor", QIcon(":/images/svg/accessories-text-editor-7.svg")));
//  connect(projectFilesMenu, SIGNAL(aboutToShow()), this, SLOT(projectFilesSlot()));

  externalWebPageMenu = new QMenu(this);
  externalWebPageMenu->setIcon(QIcon::fromTheme("applications-internet", QIcon(":/images/svg/applications-internet-5.svg")));
  connect(externalWebPageMenu, SIGNAL(aboutToShow()), this, SLOT(openRecentURLsMenuAboutToShowSlot()));

  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addMenu(editorsMenu);
  fileMenu->addSeparator();
  fileMenu->addMenu(externalWebPageMenu);
  fileMenu->addSeparator();
  fileMenu->addAction(openFileAction);
  openRecentFilesMenu = new QMenu(this);
  openRecentFilesMenu->setIcon(QIcon::fromTheme("document-open-recent", QIcon(":/images/svg/document-open-recent-3.svg")));
  connect(openRecentFilesMenu, SIGNAL(aboutToShow()), this, SLOT(openRecentFilesMenuAboutToShowSlot()));
  fileMenu->addMenu(openRecentFilesMenu);
  fileMenu->addAction(viewRecentFilesAction);
  fileMenu->addSeparator();
  fileMenu->addAction(serverInformationAction);
//  fileMenu->addAction(userAdministrationAction);
//  fileMenu->addAction(backupAction);
//  fileMenu->addAction(restoreAction);
  fileMenu->addAction(catalogsAction);
  fileMenu->addAction(queryAction);
  fileMenu->addAction(tableMaintenanceAction);
  fileMenu->addAction(databaseComparisionAction);
  fileMenu->addAction(migrateDatabaseAction);
  fileMenu->addAction(preferencesAction);
  fileMenu->addAction(processAction);
//  fileMenu->addAction(objectsDiagramAction);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAction);

  projectMenu = menuBar()->addMenu("");
  projects->buildMenu(projectMenu);

  connectionMenu = menuBar()->addMenu("");
  connect(connectionMenu, SIGNAL(aboutToShow()), this, SLOT(connectionMenuAboutToShowSlot()));
  connectionMenu->addAction(connectToServerAction);
  connectionMenu->addAction(closeCurrentConnectionAction);
  connectionMenu->addSeparator();

  openRecentConnectionMenu = new QMenu(this);
  openRecentConnectionMenu->setIcon(QIcon::fromTheme("document-open-recent", QIcon(":/images/svg/document-open-recent-3.svg")));
  connect(openRecentConnectionMenu, SIGNAL(aboutToShow()), this, SLOT(openRecentConnectionMenuAboutToShowSlot()));
  connectionMenu->addMenu(openRecentConnectionMenu);
  connectionMenu->addSeparator();

  changeCharsetMenu = new QMenu(this);
  changeCharsetMenu->setIcon(QIcon(":/images/svg/character-set.svg"));
  changeCharsetMenu->setDisabled(true);
  connect(changeCharsetMenu, SIGNAL(aboutToShow()), this, SLOT(updateChangeCharsetMenu()));
  connectionMenu->addMenu(changeCharsetMenu);
  changeDatabaseMenu = new QMenu(this);
  changeDatabaseMenu->setIcon(QIcon(":/images/svg/server-database.svg"));
  changeDatabaseMenu->setDisabled(true);
  connect(changeDatabaseMenu, SIGNAL(aboutToShow()), this, SLOT(updateChangeDatabaseMenu()));
  connectionMenu->addMenu(changeDatabaseMenu);

  databaseInformationMenu = new QMenu(this);
  databaseInformationMenu->setIcon(QIcon::fromTheme("dialog-information", QIcon(":/images/svg/dialog-information-4.svg")));
  databaseInformationMenu->setDisabled(true);
  connect(databaseInformationMenu, SIGNAL(aboutToShow()), this, SLOT(updatedatabaseInformationMenu()));
  connectionMenu->addMenu(databaseInformationMenu);

  connectionMenu->addSeparator();
  replicationMenu = new QMenu(this);
  replicationMenu->setIcon(QIcon(":/images/svg/network-server-database.svg"));
  replicationMenu->setDisabled(true);
  replicationMenu->addAction(startReplicationSlaveAction);
  replicationMenu->addAction(stopReplicationSlaveAction);
  replicationMenu->addAction(resetSlaveAction);
  replicationMenu->addAction(rebootReplicationSlaveAction);
  replicationMenu->addAction(replicationInformationAction);
  replicationMenu->addAction(maintenancePurgeBinaryLogsAction);
  replicationMenu->addAction(maintenanceFlushRelayLogsAction);
  connectionMenu->addMenu(replicationMenu);

  maintenanceMenu = new QMenu(this);
  maintenanceMenu->setIcon(QIcon(":/images/svg/system-run-5.svg"));
  maintenanceMenu->setDisabled(true);
  maintenanceMenu->addSeparator()->setText(tr("General"));
  maintenanceMenu->addAction(maintenanceTimeDifferenceAction);
  maintenanceMenu->addAction(maintenanceFlushPrivilegesAction);
  maintenanceMenu->addSeparator()->setText(tr("Replication"));
  maintenanceMenu->addAction(maintenancePurgeBinaryLogsAction);
  maintenanceMenu->addAction(maintenanceFlushRelayLogsAction);
  maintenanceMenu->addSeparator()->setText(tr("Logs"));
  maintenanceMenu->addAction(showSlowLogAction);
  connectionMenu->addMenu(maintenanceMenu);

  connectionMenu->addSeparator();
  connectionMenu->addAction(shutdownServerAction);
  connectionMenu->addSeparator();
  connectionMenu->addAction(viewQueryLogAction);

  viewMenu = menuBar()->addMenu("");
  viewMenu->addAction(toggleFullScreenAction);
  viewMenu->addAction(showFileToolBarAction);

  languageMenu = menuBar()->addMenu(QIcon::fromTheme("accessories-character-map", QIcon(":/images/svg/accessories-character-map-3.svg")), "");
  languageActionGroup = new QActionGroup(this);
  connect(languageActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(swithLanguage(QAction*)));

  QSettings settings;
  QAction *languageAction = new QAction("English", this);
  languageAction->setCheckable(true);
  languageAction->setData("en");
  languageAction->setChecked(settings.value("General/Language", "en") == languageAction->data().toString() ? true : false);
  languageAction->setIcon(QIcon::fromTheme("flag-us", QIcon(":/images/svg/flag-us.svg")));
  languageMenu->addAction(languageAction);
  languageActionGroup->addAction(languageAction);
  languageAction = new QAction("Español", this);
  languageAction->setCheckable(true);
  languageAction->setData("es");
  languageAction->setChecked(settings.value("General/Language", "en") == languageAction->data().toString() ? true : false);
  languageAction->setIcon(QIcon::fromTheme("flag-cr", QIcon(":/images/svg/flag-cr.svg")));
  languageMenu->addAction(languageAction);
  languageActionGroup->addAction(languageAction);

  windowMenu = menuBar()->addMenu("");
  connect(windowMenu, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));

  helpMenu = menuBar()->addMenu(QIcon::fromTheme("help-about", QIcon(":/images/svg/help-about-3.svg")), "");
  helpMenu->addAction(mariaDBGUIHelpAction);
  helpMenu->addSeparator();
  helpMenu->addAction(mariadbOnLineHelpAction);
  helpMenu->addSeparator();
  helpMenu->addAction(mysqlHelpAction);
  helpMenu->addAction(mysqlOnLineHelpAction);
  helpMenu->addSeparator();
  helpMenu->addAction(postgresqlOnLineHelpAction);
  helpMenu->addSeparator();
  helpMenu->addAction(phpOnLineHelpAction);
  helpMenu->addSeparator();
  helpMenu->addAction(aboutQtAction);
  helpMenu->addAction(aboutMariaDBGUIAction);
  helpMenu->addAction(caliopeSourceDocumentationAction);
}

void MainWindow::swithLanguage(QAction *action)
{
  bool translatable = true;
  if (action->data().toString() == "es")
    translatable = mainTranslator->load("caliope_" + action->data().toString(), ":/translations");
  if (action->data().toString() == "en")
    mainTranslator->load("", "");
  if (translatable) {
    qApp->installTranslator(mainTranslator);
    retranslateUi();
    foreach (QMdiSubWindow *subWindow, mdiMain->subWindowList())
      if (subWindow->inherits("DMdiSubWindow")) {
        DMdiSubWindow *wid = qobject_cast<DMdiSubWindow *>(subWindow);
        wid->retranslateUi();
      }
    projects->retranslateUi();
  } else {
    statusBarMessage(tr("Cannot load the translation."), QSystemTrayIcon::Critical);
    action->setChecked(false);
  }
  QSettings settings;
  settings.setValue("General/Language", action->data().toString());
}

void MainWindow::statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon, int timeout)
{
  if (message.isEmpty())
    return;
  dStatusBar->showFancyMessage(message, timeout);
  if (trayIconEnabled)
    trayIcon->showMessage(QCoreApplication::applicationName(), message, icon, timeout * 2);
}

void MainWindow::statusBarMessagePopup(const QString &message, int timeout)
{
  dStatusBar->showMessagePopup(message, timeout);
}

void MainWindow::aboutMariaDBGUIActionTriggered()
{
  QMessageBox::information(0, tr("About Calíope"),
                           "Calíope Database Administrator.\n"
                           "Copyright (C) 2008-2014  David Villalobos Cambronero.\n\n"

                           "This program is free software: you can redistribute it and/or modify"
                           "it under the terms of the GNU General Public License as published by"
                           "the Free Software Foundation, either version 3 of the License, or"
                           "(at your option) any later version.\n\n"

                           "This program is distributed in the hope that it will be useful,"
                           "but WITHOUT ANY WARRANTY; without even the implied warranty of"
                           "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the"
                           "GNU General Public License for more details.\n\n"

                           "You should have received a copy of the GNU General Public License"
                           "along with this program. If not, see <http://www.gnu.org/licenses/>.\n");
}

void MainWindow::updateWindowMenu()
{
  windowMenu->clear();
  windowMenu->addAction(cascadeSubWindowsAction);
  windowMenu->addAction(tileSubWindowsAction);
  windowMenu->addAction(activateNextSubWindowAction);
  windowMenu->addAction(activatePreviousSubWindowAction);
  windowMenu->addAction(closeActiveSubWindowAction);
  windowMenu->addAction(closeAllSubWindowsAction);
  windowMenu->addSeparator()->setText(tr("Windows"));
  foreach (QMdiSubWindow *subWindow, mdiMain->subWindowList()) {
    QAction *action = windowMenu->addAction(subWindow->windowTitle());
    action->setCheckable(true);
    // The following line was commented because there are moments when
    // mdiMain->currentSubWindow() == 0, so, windowTitle() cannot be reached
    // It happends on SQLQuery Windows
    action->setChecked(action->text() == mdiMain->currentSubWindow()->windowTitle());
    connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
    windowMapper->setMapping(action, subWindow);
  }
  windowMenu->addSeparator()->setText(tr("Windows options"));
  windowMenu->addAction(takeASnapShotAction);
}

void MainWindow::setActiveSubWindowMap(QWidget *window)
{
  mdiMain->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

void MainWindow::updateChangeDatabaseMenu()
{
  changeDatabaseMenu->clear();
  QString currentDatabase = serverConnection->getDatabase();
  foreach (QString database, serverConnection->getDatabases()) {
    QAction *action = changeDatabaseMenu->addAction(database);
    action->setCheckable(true);
    action->setChecked(action->text() == currentDatabase);
    action->setIcon(QIcon(":/images/svg/server-database.svg"));
    connect(action, SIGNAL(triggered()), databasesMapper, SLOT(map()));
    databasesMapper->setMapping(action, database);
  }
}

void MainWindow::changeDatabaseSlot()
{
  //serverConnection->changeDatabase(database);
  foreach (QMdiSubWindow *subWindow, mdiMain->subWindowList())
    if (subWindow->inherits("SQLQuery")) {
      SQLQuery *wid = qobject_cast<SQLQuery *>(subWindow);
      wid->fillMariaDBSymbols();
    }
  setTitle();
  emit databaseChanged();
}

void MainWindow::changeDatabaseSlot(QString database)
{
  serverConnection->changeDatabase(database);
  changeDatabaseSlot();
}

void MainWindow::updateChangeCharsetMenu()
{
  changeCharsetMenu->clear();
  QList<QStringList> *rows = serverConnection->getCharacterSets();
  QString charSet(serverConnection->getCharacterSet());
  charSet = charSet.toLower().replace("-", "");
  for (int row = 0; row < rows->count(); row++) {
    QAction *action = changeCharsetMenu->addAction(rows->at(row).at(0) + " | " + rows->at(row).at(1));
    action->setCheckable(true);
    action->setChecked(rows->at(row).at(0).toLower() == charSet);
    connect(action, SIGNAL(triggered()), charsetMapper, SLOT(map()));
    charsetMapper->setMapping(action, rows->at(row).at(0));
  }
}

void MainWindow::changeCharsetSlot(QString charset)
{
  serverConnection->setCharacterSet(charset);
  statusBarMessage(tr("Character set changed to: %1").arg(serverConnection->getCharacterSet()));
}
