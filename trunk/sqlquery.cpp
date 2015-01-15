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

#include <QVBoxLayout>
#include <QToolBar>
#include <QRadioButton>
#include <QAction>
#include <QSplitter>
#include <QTextDocumentFragment>
#include <QApplication>
#include <QPushButton>
#include <QTimer>
#include <QTextBlock>
#include <QMessageBox>
#include <QThread>
#include <QDateTime>
#include <QInputDialog>
#include <QFileDialog>

#include "sqlquery.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "statements.h"
#include "texteditor.h"
#include "basetexteditor.h"

#include "QDebug"

SQLQuery::SQLQuery(Projects *project, DBMS *serverConnection, unsigned int windowCount)
{
  this->project = project;
  this->serverConnection = serverConnection;
  this->queryPlayerStopBecauseAnError = false;
  connect(this->serverConnection, SIGNAL(errorOccurred()), this, SLOT(errorOccurredSlot()));
  connect(this->serverConnection, SIGNAL(errorMessageAccepted()), this, SLOT(errorAcceptedSlot()));
  ///connect(this->serverConnection, SIGNAL(errorOccurred()), this, SLOT(queryPlayerStopActionTriggered()));
  this->windowCount = windowCount;
  setWindowIcon(QIcon(":/images/svg/application-x-executable-script.svg"));
  statementsDialog = new Statements;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  QSplitter *mainSplitter = new QSplitter(Qt::Vertical);
  timeLabel = new QLabel("\n\n\n");
  elapsedSeconds = 0;
  repeatQueryExecutionTime = 0;
  createActions();
  radioT = new QRadioButton("-t");
  radioT->setChecked(true);
  radioV = new QRadioButton("-v");
  radioVV = new QRadioButton("-vv");
  radioVVV = new QRadioButton("-vvv");
  radioHTML = new QRadioButton("HTML");
  radioTXT = new QRadioButton("TXT");
  radioXML = new QRadioButton("XML");
  radioPDF = new QRadioButton("PDF");
  radioG = new QRadioButton("G");
  queryToolBar = new QToolBar;
  queryToolBar->addAction(safeStatementsAction);
  queryToolBar->addAction(executeAction);
  queryToolBar->addAction(exportAction);
  queryToolBar->addAction(concatenateOutputAction);
  queryToolBar->addAction(showStatementsErrorAction);
  queryToolBar->addSeparator();
  queryToolBar->addWidget(radioPDF);
  queryToolBar->addWidget(radioHTML);
  queryToolBar->addWidget(radioTXT);
  queryToolBar->addWidget(radioXML);
  queryToolBar->addWidget(radioG);
  queryToolBar->addWidget(radioV);
  queryToolBar->addWidget(radioVV);
  queryToolBar->addWidget(radioVVV);
  queryToolBar->addWidget(radioT);
  queryToolBar->addAction(showNewLinesAction);
  queryToolBar->addAction(splitAction);
  queryToolBar->addSeparator();
  queryToolBar->addAction(viewHistoryAction);
  queryToolBar->addSeparator();
  queryToolBar->addAction(startSQLPlayerAction);
  queryToolBar->setIconSize(QSize(24, 24));
  queryToolBar->addSeparator();
  queryToolBar->addAction(explainSelectAction);
  queryToolBar->addAction(explainInsertAction);
  queryToolBar->addAction(exportTableDataForInsertAction);
  queryToolBar->addAction(explainUpdateAction);
  queryToolBar->addAction(repeatQueryExecutionAction);
  queryToolBar->addAction(wordWrapOnResultAction);
  queryToolBar->addAction(logStatementsAction);
  queryToolBar->addAction(trimColumnsAction);
  queryToolBar->addAction(checkTablesAction);
  mainVLayout->addWidget(queryToolBar);
  QFrame* separatorFrame = new QFrame();
  separatorFrame->setFrameShape(QFrame::HLine);
  mainVLayout->addWidget(separatorFrame);
  scriptEditor = new TextEditor(project, serverConnection, EditorTypes::SQLQuery, 0, true);
  connect(scriptEditor, SIGNAL(openURL(QString)), this, SLOT(openURLSlot(QString)));
  ///connect(scriptEditor, SIGNAL(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)), project, SLOT(statusBarMessage(QString,QSystemTrayIcon::MessageIcon,int)));
  mainSplitter->addWidget(scriptEditor);
  resutlEditor = new BaseTextEditor(EditorTypes::NoEditor);
  resutlEditor->setWordWrapMode(settings.value("SQLQuery/WordWrapOnResul", false).toBool() ? QTextOption::WordWrap : QTextOption::NoWrap);
  mainSplitter->addWidget(resutlEditor);
  queriesToBePlayed = new QStringList();
  dialogQueryPlayer = new QDialog;
//   dialogQueryPlayer->setWindowFlags(Qt::FramelessWindowHint);
  QVBoxLayout *queryPlayerVLayout = new QVBoxLayout;
  queryPlayerVLayout->setContentsMargins(0, 0, 0, 0);
  queryPlayerVLayout->addWidget(queryPlayerToolBar);
  queryPlayerVLayout->addWidget(timeLabel);
  dialogQueryPlayer->setLayout(queryPlayerVLayout);
  connect(this, SIGNAL(enableDisableAction()), this, SLOT(enableDisableActionSlot()));

  QWidget *widMain = new QWidget;
  mainVLayout->addWidget(mainSplitter);
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
  radioVVV->setChecked(true);
  scriptEditor->setFocus();
  scriptEditor->setWindowFlags(Qt::FramelessWindowHint);

  threadElapsedSecondsTimer = new QThread;
  elapsedSecondsTimer = new QTimer;
  elapsedSecondsTimer->moveToThread(threadElapsedSecondsTimer);
  connect(threadElapsedSecondsTimer, SIGNAL(started()), elapsedSecondsTimer, SLOT(start()));
  connect(threadElapsedSecondsTimer, SIGNAL(finished()), elapsedSecondsTimer, SLOT(stop()));

  threadQueryRunQueryAction = new QThread;
  connect(elapsedSecondsTimer, SIGNAL(timeout()), this, SLOT(incrementSeconds()));
  elapsedSecondsTimer->setInterval(1000);
  connect(threadQueryRunQueryAction, SIGNAL(started()), this, SLOT(runQueryActionTriggered()));
  QTimer::singleShot(0, this, SLOT(loadLastQuery()));
}

void SQLQuery::retranslateUi()
{
  setWindowTitle(tr("Query %1").arg(windowCount));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  executeAction->setText(tr("Run"));
  executeAction->setToolTip(tr("Runs a query"));
  exportAction->setText(tr("Export"));
  exportAction->setToolTip(tr("Export query output"));
  viewHistoryAction->setText(tr("History"));
  viewHistoryAction->setToolTip(viewHistoryAction->text());
  showNewLinesAction->setText(tr("Show New Lines"));
  showNewLinesAction->setToolTip(showNewLinesAction->text());
  startSQLPlayerAction->setText(tr("Start SQL Player"));
  startSQLPlayerAction->setToolTip(startSQLPlayerAction->text());
  splitAction->setText(tr("Split query"));
  splitAction->setToolTip(splitAction->text());
  queryPlayerToolBar->setWindowTitle(tr("Actions"));
  queryPlayerToolBar->setToolTip(queryPlayerToolBar->windowTitle());
  queryPlayerRunQueryAction->setText(tr("Start/Pause execution"));
  queryPlayerRunQueryAction->setToolTip(queryPlayerRunQueryAction->text());
  queryPlayerStopAction->setText(tr("Stop execution"));
  queryPlayerStopAction->setToolTip(queryPlayerStopAction->text());
  queryPlayerRunPreviousQueryAction->setText(tr("Run previous query"));
  queryPlayerRunPreviousQueryAction->setToolTip(queryPlayerRunPreviousQueryAction->text());
  queryPlayerRunNextQueryAction->setText(tr("Run next query"));
  queryPlayerRunNextQueryAction->setToolTip(queryPlayerRunNextQueryAction->text());
  queryPlayerRunFirstQueryAction->setText(tr("Run first query"));
  queryPlayerRunFirstQueryAction->setToolTip(queryPlayerRunFirstQueryAction->text());
  queryPlayerRunLastQueryAction->setText(tr("Run last query"));
  queryPlayerRunLastQueryAction->setToolTip(queryPlayerRunLastQueryAction->text());
  concatenateOutputAction->setText(tr("Concatenate query output"));
  concatenateOutputAction->setToolTip(concatenateOutputAction->text());
  exportTableDataForInsertAction->setText(tr("Export table data for INSERT"));
  exportTableDataForInsertAction->setToolTip(exportTableDataForInsertAction->text());
  explainSelectAction->setText(tr("Explain SELECT"));
  explainSelectAction->setToolTip(explainSelectAction->text());
  explainInsertAction->setText(tr("Explain INSERT"));
  explainInsertAction->setToolTip(explainInsertAction->text());
  safeStatementsAction->setText(tr("Safe statements"));
  safeStatementsAction->setToolTip(safeStatementsAction->text());
  showStatementsErrorAction->setText(tr("Show statements with error"));
  showStatementsErrorAction->setToolTip(showStatementsErrorAction->text());
  explainUpdateAction->setText(tr("Explain UPDATE"));
  explainUpdateAction->setToolTip(explainUpdateAction->text());
  repeatQueryExecutionAction->setText(tr("Repeate execution"));
  repeatQueryExecutionAction->setToolTip(repeatQueryExecutionAction->text());
  wordWrapOnResultAction->setText(tr("Word wrap on result"));
  logStatementsAction->setText(tr("Log statements"));
  logStatementsAction->setToolTip(logStatementsAction->text());
  trimColumnsAction->setText(tr("TRIM columns in table"));
  trimColumnsAction->setToolTip(trimColumnsAction->text());
  checkTablesAction->setText(tr("Check tables status"));
  checkTablesAction->setToolTip(checkTablesAction->text());

  scriptEditor->retranslateUi();
  resutlEditor->retranslateUi();
}

void SQLQuery::createActions()
{
  executeAction = new QAction(this);
  executeAction->setIcon(QIcon(":/images/svg/system-run-5.svg"));
  executeAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Return));
  connect(executeAction, SIGNAL(triggered()), this, SLOT(executeActionTriggered()));
  exportAction = new QAction(this);
  exportAction->setIcon(QIcon(":/images/svg/document-export-4.svg"));
  exportAction->setCheckable(true);
  exportAction->setChecked(false);
  viewHistoryAction = new QAction(this);
  viewHistoryAction->setIcon(QIcon(":/images/svg/view-history.svg"));
  connect(viewHistoryAction, SIGNAL(triggered()), this, SLOT(viewHistoryActionTriggered()));
  showNewLinesAction = new QAction(this);
  showNewLinesAction->setIcon(QIcon(":/images/svg/document-export-4.svg"));
  showNewLinesAction->setShortcut(QKeySequence(Qt::Key_F8));
  showNewLinesAction->setCheckable(true);
  showNewLinesAction->setChecked(settings.value("SQLQuery/ReplaceNewLines", true).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(showNewLinesAction, SIGNAL(triggered(bool)), this, SLOT(showNewLinesActionTriggered(bool)));
  splitAction = new QAction(this);
  splitAction->setIcon(QIcon::fromTheme("edit-cut", QIcon(":/images/svg/edit-cut-6.svg")));
  splitAction->setCheckable(true);
  splitAction->setChecked(settings.value("SQLQuery/SplitQueries", true).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(splitAction, SIGNAL(triggered(bool)), this, SLOT(splitActionTriggered(bool)));
  startSQLPlayerAction = new QAction(this);
  startSQLPlayerAction->setIcon(QIcon::fromTheme("media-playback-start", QIcon(":/images/svg/media-playback-start-8.svg")));
  connect(startSQLPlayerAction, SIGNAL(triggered()), this, SLOT(startSQLPlayerActionTriggered()));
  queryPlayerRunQueryAction = new QAction(this);
  queryPlayerRunQueryAction->setIcon(QIcon::fromTheme("media-playback-start", QIcon(":/images/svg/media-playback-start-8.svg")));
  connect(queryPlayerRunQueryAction, SIGNAL(triggered()), this, SLOT(queryPlayerRunQueryActionTriggered()));
  queryPlayerRunQueryAction->setCheckable(true);
  queryPlayerStopAction = new QAction(this);
  queryPlayerStopAction->setIcon(QIcon::fromTheme("media-playback-stop", QIcon(":/images/svg/media-playback-stop-8.svg")));
  connect(queryPlayerStopAction, SIGNAL(triggered()), this, SLOT(queryPlayerStopActionTriggered()));
  showStatementsErrorAction = new QAction(this);
  showStatementsErrorAction->setIcon(QIcon::fromTheme("dialog-error", QIcon(":/images/svg/dialog-error-4.svg")));
  connect(showStatementsErrorAction, SIGNAL(triggered()), this, SLOT(showStatementsErrorActionTriggered()));
  queryPlayerRunPreviousQueryAction = new QAction(this);
  queryPlayerRunPreviousQueryAction->setIcon(QIcon::fromTheme("media-seek-backward", QIcon(":/images/svg/media-seek-backward-8.svg")));
  connect(queryPlayerRunPreviousQueryAction, SIGNAL(triggered()), this, SLOT(queryPlayerRunPreviousQueryActionTriggered()));
  queryPlayerRunNextQueryAction = new QAction(this);
  queryPlayerRunNextQueryAction->setIcon(QIcon::fromTheme("media-seek-forward", QIcon(":/images/svg/media-seek-forward-8.svg")));
  connect(queryPlayerRunNextQueryAction, SIGNAL(triggered()), this, SLOT(queryPlayerRunNextQueryActionTriggered()));
  queryPlayerRunFirstQueryAction = new QAction(this);
  queryPlayerRunFirstQueryAction->setIcon(QIcon::fromTheme("media-skip-backward", QIcon(":/images/svg/media-skip-backward-8.svg")));
  connect(queryPlayerRunFirstQueryAction, SIGNAL(triggered()), this, SLOT(queryPlayerRunFirstQueryActionTriggered()));
  queryPlayerRunLastQueryAction = new QAction(this);
  queryPlayerRunLastQueryAction->setIcon(QIcon::fromTheme("media-skip-forward", QIcon(":/images/svg/media-skip-forward-8.svg")));
  connect(queryPlayerRunLastQueryAction, SIGNAL(triggered()), this, SLOT(queryPlayerRunLastQueryActionTriggered()));
  concatenateOutputAction = new QAction(this);
  concatenateOutputAction->setIcon(QIcon::fromTheme("mail-attachment", QIcon(":/images/svg/mail-attachment.svg")));
  concatenateOutputAction->setCheckable(true);
  concatenateOutputAction->setChecked(false);
  exportTableDataForInsertAction = new QAction(this);
  exportTableDataForInsertAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  connect(exportTableDataForInsertAction, SIGNAL(triggered()), this, SLOT(exportTableDataForInsertActionTriggered()));
  explainSelectAction = new QAction(this);
  explainSelectAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  explainSelectAction->setShortcut(QKeySequence(Qt::Key_F7));
  connect(explainSelectAction, SIGNAL(triggered()), this, SLOT(explainSelectActionTriggered()));
  explainInsertAction = new QAction(this);
  explainInsertAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  explainInsertAction->setShortcut(QKeySequence(Qt::Key_F9));
  connect(explainInsertAction, SIGNAL(triggered()), this, SLOT(explainInsertActionTriggered()));
  safeStatementsAction = new QAction(this);
  safeStatementsAction->setIcon(QIcon::fromTheme("system-lock-screen", QIcon(":/images/svg/system-lock-screen-5.svg")));
  safeStatementsAction->setCheckable(true);
  safeStatementsAction->setChecked(settings.value("SQLQuery/ExecuteSafeStatements-" + qApp->property("ConnectionName").toString(), true).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(safeStatementsAction, SIGNAL(triggered(bool)), this, SLOT(safeStatementsActionTriggered(bool)));
  explainUpdateAction = new QAction(this);
  explainUpdateAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  connect(explainUpdateAction, SIGNAL(triggered()), this, SLOT(explainUpdateActionTriggered()));
  repeatQueryExecutionAction = new QAction(this);
  repeatQueryExecutionAction->setIcon(QIcon::fromTheme("media-playlist-repeat", QIcon(":/images/svg/media-playlist-repeat.svg")));
  connect(repeatQueryExecutionAction, SIGNAL(triggered()), this, SLOT(repeatQueryExecutionActionTriggered()));
  repeatQueryExecutionAction->setCheckable(true);
  logStatementsAction = new QAction(this);
  logStatementsAction->setIcon(QIcon(":/images/svg/text-x-log.svg"));
  logStatementsAction->setCheckable(true);
  logStatementsAction->setChecked(settings.value("SQLQuery/LogStatements", true).toBool());
  connect(logStatementsAction, SIGNAL(toggled(bool)), this, SLOT(logStatementsActionToggled()));
  logStatements = logStatementsAction->isChecked();
  trimColumnsAction = new QAction(this);
  trimColumnsAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  connect(trimColumnsAction, SIGNAL(triggered()), this, SLOT(trimColumnsActionTriggered()));

  wordWrapOnResultAction = new QAction(this);
  wordWrapOnResultAction->setCheckable(true);
  wordWrapOnResultAction->setChecked(settings.value("SQLQuery/WordWrapOnResul", false).toBool());
  connect(wordWrapOnResultAction, SIGNAL(toggled(bool)), this, SLOT(wordWrapOnResultActionToggled()));

  checkTablesAction = new QAction(this);
  checkTablesAction->setIcon(QIcon(":/images/svg/checkbox.svg"));
  connect(checkTablesAction, SIGNAL(triggered()), this, SLOT(checkTablesActionTriggered()));

  queryPlayerToolBar = new QToolBar();
  queryPlayerToolBar->addAction(queryPlayerRunFirstQueryAction);
  queryPlayerToolBar->addAction(queryPlayerRunPreviousQueryAction);
  queryPlayerToolBar->addAction(queryPlayerRunQueryAction);
  queryPlayerToolBar->addAction(queryPlayerRunNextQueryAction);
  queryPlayerToolBar->addAction(queryPlayerRunLastQueryAction);
  queryPlayerToolBar->addSeparator();
  queryPlayerToolBar->addAction(queryPlayerStopAction);
  queryPlayerToolBar->addSeparator();
  queryPlayerToolBar->addAction(explainSelectAction);
  queryPlayerToolBar->addAction(explainInsertAction);
  queryPlayerToolBar->addAction(explainUpdateAction);
  queryPlayerToolBar->addAction(concatenateOutputAction);
}

void SQLQuery::viewHistoryActionTriggered()
{
  statementsDialog->execSlot(serverConnection->executedQueries);
}

void SQLQuery::showNewLinesActionTriggered(bool triggered)
{
  settings.setValue("SQLQuery/ReplaceNewLines", triggered);
}

void SQLQuery::splitActionTriggered(bool triggered)
{
  settings.setValue("SQLQuerySplitQueries", triggered);
}

void SQLQuery::startSQLPlayerActionTriggered()
{
  queriesToBePlayed = new QStringList(statement().split(QRegExp(";\\s+"), QString::SkipEmptyParts));
  nextQueryToExecute = 0;
  emit enableDisableAction();
  timeLabel->setText("\n\n\n");
  dialogQueryPlayer->show();
  emit executionStarted(0);
}

void SQLQuery::queryPlayerRunQueryActionTriggered()
{
  threadElapsedSecondsTimer->start();
  threadQueryRunQueryAction->start();
}

void SQLQuery::queryPlayerStopActionTriggered()
{
  queryPlayerRunQueryAction->setChecked(false);
  queryPlayerRunQueryAction->setIcon(QIcon::fromTheme("media-playback-start", QIcon(":/images/svg/media-playback-start-8.svg")));
  threadQueryRunQueryAction->quit();
  threadElapsedSecondsTimer->quit();
  elapsedSeconds = 0;
  dialogQueryPlayer->close();
}

void SQLQuery::queryPlayerRunPreviousQueryActionTriggered()
{
  executeStatement(queryToBePlayed(--nextQueryToExecute));
  emit enableDisableAction();
}

QString SQLQuery::queryToBePlayed(int position)
{
  if ((position < queriesToBePlayed->count()) && (position >= 0)) {
    return queriesToBePlayed->at(position);
  } else {
    queryPlayerRunQueryAction->setChecked(false);
    queryPlayerRunQueryAction->setIcon(QIcon::fromTheme("media-playback-start", QIcon(":/images/svg/media-playback-start-8.svg")));
  }
  if (position == queriesToBePlayed->count())
    return queriesToBePlayed->last();
  return QString();
}

void SQLQuery::queryPlayerRunNextQueryActionTriggered()
{
  executeStatement(queryToBePlayed(++nextQueryToExecute));
  emit enableDisableAction();
}

void SQLQuery::enableDisableActionSlot()
{
  if (nextQueryToExecute <= 0) {
    queryPlayerRunPreviousQueryAction->setEnabled(false);
    queryPlayerStopAction->setEnabled(false);
    queryPlayerRunFirstQueryAction->setEnabled(false);
    emit executionStarted(0);
  } else {
    queryPlayerRunPreviousQueryAction->setEnabled(true);
    queryPlayerStopAction->setEnabled(true);
    queryPlayerRunFirstQueryAction->setEnabled(true);
  }
  if (nextQueryToExecute >= queriesToBePlayed->count() - 1) {
    queryPlayerRunNextQueryAction->setEnabled(false);
    queryPlayerRunQueryAction->setEnabled(false);
    queryPlayerRunLastQueryAction->setEnabled(false);
    emit executionFinished(100);
  } else {
    queryPlayerRunNextQueryAction->setEnabled(true);
    queryPlayerRunQueryAction->setEnabled(true);
    queryPlayerRunLastQueryAction->setEnabled(true);
  }
}

void SQLQuery::queryPlayerRunFirstQueryActionTriggered()
{
  nextQueryToExecute = 0;
  executeStatement(queryToBePlayed(nextQueryToExecute));
  emit enableDisableAction();
}

void SQLQuery::queryPlayerRunLastQueryActionTriggered()
{
  nextQueryToExecute =  queriesToBePlayed->count() - 1;
  executeStatement(queryToBePlayed(nextQueryToExecute));
  emit enableDisableAction();
}

QString SQLQuery::statement()
{
  if (scriptEditor->textEditor->textCursor().hasSelection()) {
    return scriptEditor->textEditor->textCursor().selection().toPlainText().trimmed();
  } else {
    return scriptEditor->textEditor->toPlainText().trimmed();
  }
}

void SQLQuery::executeStatement(QString statement)
{
  if (!statement.isEmpty()) {
    if (statement.contains(QRegExp("(ALTER|CREATE|DELETE|DROP|GRANT|LOAD|RENAME|TRUNCATE|UPDATE)", Qt::CaseInsensitive))
        && safeStatementsAction->isChecked()) {
      QString message(tr("Could not execute statement on safe mode."));
      QMessageBox::warning(this, tr("Safe mode"), message);
      resutlEditor->setPlainText(message + "\n" + statement);
      return;
    }
    if (logStatements) //Use a variable here because is faster
      serverConnection->logStatement(statement);
    serverConnection->executedQueries->append(statement);
    if (settings.value("General/SaveQueriesBeforeExecution", true).toBool())
      settings.setValue("General/LastQuery-" + qApp->property("ConnectionName").toString() + "-" + windowTitle(), scriptEditor->textEditor->toPlainText().trimmed());
    if (!concatenateOutputAction->isChecked())
      resutlEditor->clear();
    if (radioT->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsTable(statement, false, exportAction->isChecked()
                                                                 , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioV->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsV(statement, false, exportAction->isChecked()
                                                             , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioVV->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsVV(statement, exportAction->isChecked()
                                                              , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioVVV->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsTable(statement, true, exportAction->isChecked()
                                                                 , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioHTML->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsHTML(statement, exportAction->isChecked()
                                                                , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioTXT->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsTable(statement, false, exportAction->isChecked()
                                                                 , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioXML->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsXML(statement, exportAction->isChecked()
                                                               , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioG->isChecked())
      resutlEditor->setPlainText(serverConnection->outputAsG(statement, exportAction->isChecked()
                                                             , showNewLinesAction->isChecked(), splitAction->isChecked())
                                 , concatenateOutputAction->isChecked());
    if (radioPDF->isChecked()) {
      resutlEditor->setPlainText(serverConnection->outputAsTable(statement, false, false, showNewLinesAction->isChecked(), splitAction->isChecked()));
      QApplication::setOverrideCursor(Qt::WaitCursor);
      QFileDialog fileDialog;
      fileDialog.setDirectory(QDir::home());
      QString file = fileDialog.getSaveFileName(this, tr("Save to Pdf"), settings.value("General/LastFilePdf", QDir::home().absolutePath()).toString(), tr("Pdf & Ps files (*.pdf *.ps)"));
      settings.setValue("General/LastFilePdf", fileDialog.directory().filePath(file));
      QPrinter printer(QPrinter::HighResolution);
      printer.setOutputFileName(file);
      printer.setOutputFormat(file.endsWith(".pdf") ? QPrinter::PdfFormat : QPrinter::NativeFormat);
      resutlEditor->document()->print(&printer);
      QApplication::restoreOverrideCursor();
      emit statusBarMessage(tr("File saved at: %1").arg(file));
    }
    //resutlEditor->setPlainText(statement);
  }
}

void SQLQuery::executeActionTriggered()
{
  if (statement().startsWith("EDIT ", Qt::CaseInsensitive)) {
    QString stmnt(statement());
    QString where;
    QString database;
    QString table;
    int indexOfWhere = stmnt.indexOf(" WHERE ", 0, Qt::CaseInsensitive);
    table = stmnt.mid(5, indexOfWhere - 5);
    if (table.contains(".")) {
      QStringList list = table.split(".");
      database = list.at(0);
      table = list.at(1);
    }
    if (indexOfWhere > 1) {
      indexOfWhere += 7;
      where = stmnt.mid(indexOfWhere, stmnt.length() - indexOfWhere);
      if (where.endsWith(";"))
        where = where.mid(0, where.length() - 1);
    }
    emit showResultTab(table, database, where);
  } else {
    queryPlayerStopBecauseAnError = false;
    executeStatement(statement());
  }
}

void SQLQuery::setScriptText(QString text)
{
  scriptEditor->textEditor->setPlainText(text);
  scriptEditor->textEditor->setFocus(Qt::OtherFocusReason);
}

void SQLQuery::fillMariaDBSymbols()
{
  scriptEditor->fillMariaDBSymbolsActionSlot();
}

QToolBar *SQLQuery::getToolBar()
{
  return queryToolBar;
}

void SQLQuery::exportTableDataForInsertActionTriggered()
{
  QTextCursor cursor = scriptEditor->textEditor->textCursor();
  QTextDocument *doc = scriptEditor->textEditor->document();
  QTextBlock block = doc->findBlock(qMin(cursor.anchor(), cursor.position()));
  QString outPut;
  QString fields;
  QString table;
  if (block.text().startsWith("EXPORT DATA FOR INSERT `")) {
    QRegExp expression("`[A-Za-z_\\d%]*`");
    expression.indexIn(block.text());
    table = expression.capturedTexts().at(0).mid(1, expression.capturedTexts().at(0).length() - 2);
    QString queryString("SELECT `COLUMN_NAME` FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '" + serverConnection->getDatabase() + "' AND `TABLE_NAME` = '" + table + "'");
    foreach (QString column, serverConnection->runQuerySingleColumn(queryString))
      fields += "`" + column + "`, ";
    fields = fields.mid(0, fields.length() - 2);
    QString rowData("INSERT INTO `" + table + "` (" + fields + ") VALUES (");
    QString rowTMP;
    QRegExp expressionWHERE(" WHERE `[A-Za-z_\\d%]*.*");
    expressionWHERE.indexIn(block.text());
    QList<QStringList> *rows = serverConnection->runQuery("SELECT * FROM `" + table + "`" + expressionWHERE.capturedTexts().at(0));

    for (int row = 0; row < rows->count() - 1; row++) {
      for (int row2 = 0; row2 < rows->at(row).count(); row2++) {
        rowTMP += "'" + rows->at(row).at(row2) + "', ";
      }
      outPut += rowData + rowTMP.mid(0, rowTMP.length() - 2) + ");\n";
      rowTMP = "";
    }
    if (radioTXT->isChecked()) {
      QString fileName = QFileDialog::getSaveFileName(this, tr("Select a file"), settings.value("General/LastSQLFile", "").toString(), "SQL Files (*.sql)");
      QFile file(fileName);
      if (!file.open(QFile::WriteOnly | QFile::Text))
        emit statusBarMessage(tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
      QTextStream out(&file);
      out << outPut.toUtf8();
      file.close();
    } else {
      resutlEditor->setPlainText(outPut);
    }
  } else {
    resutlEditor->setPlainText(tr("Incorrect use of the EXPORT DATA FOR INSERT Option. Example: EXPORT DATA FOR INSERT `columns_pri`, it only works for the current database."));
  }
}

void SQLQuery::explainSelectActionTriggered()
{
  QTextCursor cursor = scriptEditor->textEditor->textCursor();
  if (cursor.hasSelection() && cursor.selectedText() == "*") {
    QTextDocument *doc = scriptEditor->textEditor->document();
    QTextBlock block = doc->findBlock(qMin(cursor.anchor(), cursor.position()));
    QRegExp expression("`[A-Za-z_\\d%]*`");
    expression.indexIn(block.text());
    QString symbolName = expression.capturedTexts().at(0);
    QString queryString("SELECT `COLUMN_NAME` FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '" + serverConnection->getDatabase() + "' AND `TABLE_NAME` = '" + symbolName.mid(1, symbolName.length() - 2) + "'");
    QString outPut;
    foreach (QString column, serverConnection->runQuerySingleColumn(queryString))
      outPut += "`" + column + "`, ";
    cursor.insertText(outPut.mid(0, outPut.length() - 2));
  } else {
    resutlEditor->setPlainText(tr("Incorrect use of the EXPLAIN SELECT Option. Example: SELECT * FROM `columns_pri`, it only works for the current database, the asterisk must be selected."));
  }
}

void SQLQuery::explainInsertActionTriggered()
{
  QTextCursor cursor = scriptEditor->textEditor->textCursor();
  QTextDocument *doc = scriptEditor->textEditor->document();
  QTextBlock block = doc->findBlock(qMin(cursor.anchor(), cursor.position()));
  if (block.text().startsWith("INSERT INTO `")) {
    QRegExp expression("`[A-Za-z_\\d%]*`");
    expression.indexIn(block.text());
    QString queryString("SELECT `COLUMN_NAME` FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '" + serverConnection->getDatabase() + "' AND `TABLE_NAME` = '" + expression.capturedTexts().at(0).mid(1, expression.capturedTexts().at(0).length() - 2) + "'");
    QString outPut;
    foreach (QString column, serverConnection->runQuerySingleColumn(queryString))
      outPut += "TRIM('" + column + "'), ";
    cursor.insertText(" VALUES (" + outPut.mid(0, outPut.length() - 2) + ");");
  } else {
    resutlEditor->setPlainText(tr("Incorrect use of the EXPLAIN INSERT Option. Example: INSERT INTO `columns_pri`, it only works for the current database."));
  }
}

void SQLQuery::safeStatementsActionTriggered(bool triggered)
{
  settings.setValue("SQLQuery/ExecuteSafeStatements-" + qApp->property("ConnectionName").toString(), triggered);
}

void SQLQuery::incrementSeconds()
{
  elapsedSeconds++;
  float elapsedTime = elapsedSeconds;
  QString timeUnit(tr("seconds"));
  QString timeUnit2 = timeUnit;
  if (elapsedSeconds > 60) {
    elapsedTime /= 60 ;
    timeUnit = tr("minutes");
  }
  float remaniningTime = (queriesToBePlayed->count() - nextQueryToExecute) * (elapsedSeconds / nextQueryToExecute);
  if (remaniningTime > 60) {
    remaniningTime /= 60;
    timeUnit2 = tr("minutes");
  }
  timeLabel->setText(tr("Elapsed: %1 %2. Remaining: %3 %4.\nTotal of queries: %5, remaining: %6.\nQueries per second: %7.")
                     .arg(elapsedTime)
                     .arg(timeUnit)
                     .arg(remaniningTime)
                     .arg(timeUnit2)
                     .arg(queriesToBePlayed->count())
                     .arg(queriesToBePlayed->count() - nextQueryToExecute)
                     .arg(nextQueryToExecute / elapsedSeconds));
  if (nextQueryToExecute >= queriesToBePlayed->count())
    elapsedSecondsTimer->stop();
}

void SQLQuery::runQueryActionTriggered()
{
  if (queryPlayerRunQueryAction->isChecked()) {
    queryPlayerRunQueryAction->setIcon(QIcon::fromTheme("media-playback-pause", QIcon(":/images/svg/media-playback-pause-8.svg")));
  } else {
    queryPlayerRunQueryAction->setIcon(QIcon::fromTheme("media-playback-start", QIcon(":/images/svg/media-playback-start-8.svg")));
  }
  if (!queryPlayerStopBecauseAnError)
    executeStatement(queryToBePlayed(nextQueryToExecute++));
  emit enableDisableAction();
  if (queryPlayerRunQueryAction->isChecked() && nextQueryToExecute < queriesToBePlayed->count())
    QTimer::singleShot(0, this, SLOT(runQueryActionTriggered()));
  emit executionProgress(nextQueryToExecute * 100 / queriesToBePlayed->count());
}

void SQLQuery::showStatementsErrorActionTriggered()
{
  resutlEditor->setPlainText(serverConnection->getfailedQueries());
}

void SQLQuery::errorAcceptedSlot()
{
  queryPlayerStopBecauseAnError = false;
}

void SQLQuery::errorOccurredSlot()
{
  queryPlayerStopBecauseAnError = true;
}

void SQLQuery::explainUpdateActionTriggered()
{
  QTextCursor cursor = scriptEditor->textEditor->textCursor();
  QTextDocument *doc = scriptEditor->textEditor->document();
  QTextBlock block = doc->findBlock(qMin(cursor.anchor(), cursor.position()));
  if (block.text().startsWith("UPDATE `")) {
    QRegExp expression("`[A-Za-z_\\d%]*`");
    expression.indexIn(block.text());
    QString queryString("SELECT `COLUMN_NAME` FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '" + serverConnection->getDatabase() + "' AND `TABLE_NAME` = '" + expression.capturedTexts().at(0).mid(1, expression.capturedTexts().at(0).length() - 2) + "' AND `COLUMN_KEY` = 'PRI'");
    QString outPut(" SET COLUMNS WHERE ");
    foreach (QString column, serverConnection->runQuerySingleColumn(queryString))
      outPut += "`" + column + "` = TRIM('" + column + "') AND ";
    cursor.insertText(outPut.mid(0, outPut.length() - 5) + ";");
  } else {
    resutlEditor->setPlainText(tr("Incorrect use of the EXPLAIN UPDATE Option. Example: UPDATE `columns_pri`, it only works for the current database."));
  }
}

void SQLQuery::repeatQueryExecutionActionTriggered()
{
  scriptEditor->setEnabled(!repeatQueryExecutionAction->isChecked());
  if (repeatQueryExecutionAction->isChecked()) {
    if (repeatQueryExecutionTime == 0)
      repeatQueryExecutionTime = QInputDialog::getInt(this, tr("Repeat time in seconds"), tr("Repeat time in seconds"), 1, 1);
    executeActionTriggered();
    QTimer::singleShot(repeatQueryExecutionTime * 1000, this, SLOT(repeatQueryExecutionActionTriggered()));
  } else {
    repeatQueryExecutionTime = 0;
  }
}

void SQLQuery::wordWrapOnResultActionToggled()
{
  resutlEditor->setWordWrapMode(wordWrapOnResultAction->isChecked() ? QTextOption::WordWrap : QTextOption::NoWrap);
  settings.setValue("SQLQuery/WordWrapOnResul", wordWrapOnResultAction->isChecked());
}

void SQLQuery::loadLastQuery()
{
  scriptEditor->textEditor->setPlainText(settings.value("SQLQuery/LastQuery-" + qApp->property("ConnectionName").toString() + "-" + windowTitle(), "").toString());
}

void SQLQuery::logStatementsActionToggled()
{
  settings.setValue("SQLQuery/LogStatements", logStatementsAction->isChecked());
  logStatements = logStatementsAction->isChecked();
}

void SQLQuery::trimColumnsActionTriggered()
{
  QTextCursor cursor = scriptEditor->textEditor->textCursor();
  QTextDocument *doc = scriptEditor->textEditor->document();
  QTextBlock block = doc->findBlock(qMin(cursor.anchor(), cursor.position()));
  if (block.text().startsWith("TRIM COLUMNS IN `")) {
    QRegExp expression("`[A-Za-z_\\d%]*`");
    expression.indexIn(block.text());
    QString queryString("SELECT `COLUMN_NAME` FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '" + serverConnection->getDatabase() + "' AND `TABLE_NAME` = '" + expression.capturedTexts().at(0).mid(1, expression.capturedTexts().at(0).length() - 2) + "' AND `DATA_TYPE` IN ('char', 'varchar', 'text', 'mediumtext', 'longtext', 'tinytext')");
    QString outPut("UPDATE `" + expression.capturedTexts().at(0).mid(1, expression.capturedTexts().at(0).length() - 2) + "` SET ");
    foreach (QString column, serverConnection->runQuerySingleColumn(queryString))
      outPut += "`" + column + "` = TRIM(`" + column + "`), ";
    resutlEditor->setPlainText(outPut.mid(0, outPut.length() - 2) + ";");
  } else {
    resutlEditor->setPlainText(tr("Incorrect use of the TRIM columns Option. Example: TRIM COLUMNS IN `columns_pri`, it only works for the current database."));
  }
}

void SQLQuery::openURLSlot(QString url)
{
  emit openURL(url);
}

void SQLQuery::checkTablesActionTriggered()
{
//  QApplication::setOverrideCursor(Qt::WaitCursor);
//  concatenateOutputAction->setChecked(true);
//  foreach (QString table, serverConnection->database()->getTables())
//    executeStatement("SELECT * FROM `" + table + "` LIMIT 1");
//  concatenateOutputAction->setChecked(false);
//  QApplication::restoreOverrideCursor();

  startSQLPlayerActionTriggered();
  nextQueryToExecute = 0;
  emit executionStarted(0);
  queriesToBePlayed->clear();
  concatenateOutputAction->setChecked(true);
  foreach (QString table, serverConnection->database()->getTables())
    queriesToBePlayed->append("SELECT * FROM `" + table + "` LIMIT 1");
  emit enableDisableAction();
}
