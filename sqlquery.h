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

#ifndef SQLQUERY_H
#define SQLQUERY_H

#include <QSettings>

class BaseTextEditor;
class QHBoxLayout;
class QRadioButton;
class QToolBar;
class Statements;
class TextEditor;
class DTitleLabel;
class QPushButton;
class QLabel;
class QElapsedTimer;
class QSqlDatabase;
class Projects;

#include "dmdisubwindow.h"
#include "dbms.h"

class SQLQuery : public DMdiSubWindow
{
  Q_OBJECT

public:
  SQLQuery(Projects *project, DBMS *serverConnection, unsigned int windowCount = 0);
  bool okToClose();
  void fillMariaDBSymbols();
  QToolBar *getToolBar();

private:
  TextEditor *scriptEditor;
  BaseTextEditor *resutlEditor;
  DBMS *serverConnection;
  QToolBar *queryToolBar;
  Projects *project;

  void outputT();
  void outputV();
  void outputVV();
  void outputVVV();
  void createActions();
  QString statement();

  QRadioButton *radioT;
  QRadioButton *radioV;
  QRadioButton *radioVV;
  QRadioButton *radioVVV;
  QHBoxLayout *toolbarHorizontalLayout;
  QWidget *widToolbar;
  QRadioButton *radioG;
  QAction *executeAction;
  QAction *exportAction;
  QAction *viewHistoryAction;
  QRadioButton *radioHTML;
  QRadioButton *radioTXT;
  QRadioButton *radioXML;
  Statements *statementsDialog;
  QSettings settings;
  QAction *showNewLinesAction;
  QAction *splitAction;
  unsigned int windowCount;
  DTitleLabel *dTitleLabel;
  QAction *startSQLPlayerAction;
  QStringList *queriesToBePlayed;
  QToolBar *queryPlayerToolBar;
  QAction *queryPlayerRunQueryAction;
  QDialog *dialogQueryPlayer;
  void execureStatement(QString statement = QString());
  float nextQueryToExecute;
  QAction *queryPlayerStopAction;
  QAction *queryPlayerRunPreviousQueryAction;
  QAction *queryPlayerRunNextQueryAction;
  QAction *queryPlayerRunFirstQueryAction;
  QAction *queryPlayerRunLastQueryAction;
  bool queryPlayerStopBecauseAnError;
  QAction *concatenateOutputAction;
  QAction *exportTableDataForInsertAction;
  QAction *explainSelectAction;
  QAction *explainInsertAction;
  QAction *safeStatementsAction;
  QLabel *timeLabel;
  unsigned long long elapsedSeconds;
  QTimer *elapsedSecondsTimer;
  QThread *threadElapsedSecondsTimer;
  QThread *threadQueryRunQueryAction;
  QAction *showStatementsErrorAction;
  QAction *explainUpdateAction;
  QAction *repeatQueryExecutionAction;
  unsigned int repeatQueryExecutionTime;
  QRadioButton *radioPDF;
  QAction *wordWrapOnResultAction;
  QAction *logStatementsAction;
  bool logStatements;
  QAction *trimColumnsAction;

signals:
  void enableDisableAction();
  void executionStarted(double progress);
  void executionFinished(double progress);
  void executionProgress(double progress);
  void showResultTab(QString table, QString database, QString where);
  void statusBarMessage(QString message);

private slots:
  void executeActionTriggered();
  void setScriptText(QString text);
  void viewHistoryActionTriggered();
  void showNewLinesActionTriggered(bool triggered);
  void splitActionTriggered(bool triggered);
  void startSQLPlayerActionTriggered();
  void queryPlayerRunQueryActionTriggered();
  void queryPlayerStopActionTriggered();
  void queryPlayerRunPreviousQueryActionTriggered();
  QString queryToBePlayed(int position);
  void queryPlayerRunNextQueryActionTriggered();
  void enableDisableActionSlot();
  void queryPlayerRunFirstQueryActionTriggered();
  void queryPlayerRunLastQueryActionTriggered();
  void exportTableDataForInsertActionTriggered();
  void explainSelectActionTriggered();
  void explainInsertActionTriggered();
  void safeStatementsActionTriggered(bool triggered);
  void incrementSeconds();
  void runQueryActionTriggered();
  void showStatementsErrorActionTriggered();
  void errorAcceptedSlot();
  void errorOccurredSlot();
  void explainUpdateActionTriggered();
  void repeatQueryExecutionActionTriggered();
  void wordWrapOnResultActionToggled();
  void loadLastQuery();
  void logStatementsActionToggled();
  void trimColumnsActionTriggered();

protected:
  /*! \brief Reilplements the closeEvent.
   *
   *  Reilplements the closeEvent to make some checks on the window closing.
   */
  void retranslateUi();
};

#endif // SQLQUERY_H
