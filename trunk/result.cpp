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
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QContextMenuEvent>
#include <QShortcut>
#include <QToolBar>
#include <QStandardItem>

#include "result.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "statements.h"
#include "dtableview.h"
#include "dbms.h"

#include "QDebug"

Result::Result(DBMS *serverConnection, QString table, QString database, QString where)
{
  this->serverConnection = serverConnection;
  setTable(table);
  if (database.isEmpty())
    database = serverConnection->getDatabase();
  setDatabase(database);
  setWhere(where);
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));

  statements = new QStringList;
  statementsDialog = new Statements;
  headers = new QList<QStringList>;
  resultDTableView = new DTableView(headers);
  connect(resultDTableView, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(resultDTableView, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(resultDTableView, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  createActions();
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  resultToolBar = new QToolBar;
  resultToolBar->addAction(refreshAction);
  resultToolBar->addSeparator();
  resultToolBar->addAction(applyStatementsAction);
  resultToolBar->addAction(discardStatementsAction);
  resultToolBar->addAction(viewChangesAction);
  resultToolBar->addSeparator();
  resultToolBar->addAction(addRowAction);
  mainVLayout->addWidget(resultToolBar);
  mainVLayout->addWidget(resultDTableView);
  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  menu = new QMenu(this);
  menu->addAction(refreshAction);
  resultToolBar->addSeparator();
  menu->addAction(applyStatementsAction);
  menu->addAction(discardStatementsAction);
  menu->addAction(deleteCurrentLineAction);
  menu->addAction(viewChangesAction);
  menu->addSeparator();
  menu->addAction(addRowAction);
  retranslateUi();
  setWidget(widMain);
  connect(resultDTableView, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(itemChangedSlot(QStandardItem*)));
}

void Result::retranslateUi()
{
  setWindowTitle(tr("Result"));
  setObjectName(windowTitle());
  refreshAction->setText(tr("Refresh"));
  refreshAction->setToolTip(refreshAction->text());
  applyStatementsAction->setText(tr("Apply changes"));
  applyStatementsAction->setToolTip(applyStatementsAction->text());
  discardStatementsAction->setText(tr("Discard changes"));
  discardStatementsAction->setToolTip(discardStatementsAction->text());
  deleteCurrentLineAction->setText(tr("Delete line: %1"));
  deleteCurrentLineAction->setToolTip(deleteCurrentLineAction->text());
  viewChangesAction->setText(tr("History"));
  viewChangesAction->setToolTip(viewChangesAction->text());
  addRowAction->setText(tr("Add a row"));
  addRowAction->setToolTip(addRowAction->text());
}

void Result::createActions()
{
  refreshAction = new QAction(this);
  refreshAction->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));
  refreshAction->setShortcut(QKeySequence(Qt::Key_F5));
  (void) new QShortcut(QKeySequence(Qt::Key_F5),  this, SLOT(updateResult()));
  connect(refreshAction, SIGNAL(triggered()), this, SLOT(updateResult()));
  applyStatementsAction = new QAction(this);
  applyStatementsAction->setIcon(QIcon::fromTheme("document-save-as", QIcon(":/images/svg/document-save-as-5.svg")));
  connect(applyStatementsAction, SIGNAL(triggered()), this, SLOT(applyStatementsActionTriggered()));
  discardStatementsAction = new QAction(this);
  discardStatementsAction->setIcon(QIcon::fromTheme("user-trash", QIcon(":/images/svg/user-trash.svg")));
  discardStatementsAction->setEnabled(!statements->empty());
  connect(discardStatementsAction, SIGNAL(triggered()), this, SLOT(discardStatementsActionTriggered()));
  deleteCurrentLineAction = new QAction(this);
  deleteCurrentLineAction->setIcon(QIcon::fromTheme("user-trash", QIcon(":/images/svg/user-trash.svg")));
  connect(deleteCurrentLineAction, SIGNAL(triggered()), this, SLOT(deleteCurrentLineActionTriggered()));
  viewChangesAction = new QAction(this);
  viewChangesAction->setIcon(QIcon(":/images/svg/view-history.svg"));
  connect(viewChangesAction, SIGNAL(triggered()), this, SLOT(viewChangesActionTriggered()));
  viewChangesAction->setEnabled(!statements->empty());
  addRowAction = new QAction(this);
  addRowAction->setIcon(QIcon::fromTheme("list-add", QIcon(":/images/svg/list-add-5.svg")));
  connect(addRowAction, SIGNAL(triggered()), this, SLOT(addRow()));
}

void Result::viewChangesActionTriggered()
{
  statementsDialog->execSlot(statements);
}

void Result::addRow()
{
  resultDTableView->addRow();
  addRowAction->setDisabled(true);
}

void Result::statusBarProgressMessageSlot(const QString &message, const unsigned int timeout, const double progress)
{
  emit statusBarProgressMessage(message, timeout, progress);
}

void Result::discardStatementsActionTriggered()
{
  statements->clear();
  updateResult();
  discardStatementsAction->setIcon(QIcon::fromTheme("user-trash", QIcon(":/images/svg/user-trash.svg")));
  discardStatementsAction->setEnabled(!statements->empty());
  viewChangesAction->setEnabled(!statements->empty());
  addRowAction->setDisabled(false);
}

void Result::applyStatementsActionTriggered()
{
  QString output;
  for (int row = 0; row < statements->count(); row++) {
    serverConnection->logStatement(statements->at(row));
    output += serverConnection->outputAsTable(statements->at(row), true) + "\n";
  }
  emit statusBarMessagePopup(output);
  discardStatementsActionTriggered();
}

void Result::updateResult()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  result = serverConnection->runQuery("SELECT `COLUMN_NAME`"
                                                    "  , IF(`DATA_TYPE` REGEXP '(varchar|char|text|blob).*', '" + StaticFunctions::DelegateTypeNoDelegate() + "'"
                                                    "  , IF(`DATA_TYPE` REGEXP '(float|int).*', '" + StaticFunctions::DelegateTypeNumber() + "'"
                                                    "  , IF(`DATA_TYPE` = 'date', '" + StaticFunctions::DelegateTypeDate() + "'"
                                                    "  , IF(`DATA_TYPE` = 'enum', CONCAT('" + StaticFunctions::DelegateTypeEnum() + "', SUBSTRING(`COLUMN_TYPE`, 5))"
                                                    "  , IF(`DATA_TYPE` REGEXP '(datetime|timestamp).*', '" + StaticFunctions::DelegateTypeDateTime() + "', 0)))))"
                                                    "  , IF(`COLUMN_KEY` = 'PRI', 'PRI', '')"
                                                    "  , `COLUMN_DEFAULT`"
                                                    " FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = '"
                                                    + StaticFunctions::unquoteSymbol(p_database) + "' AND `TABLE_NAME` = '"
                                                    + StaticFunctions::unquoteSymbol(p_table) + "'");
  result->takeLast(); //Remove the "Affected rows" line.
  headers->clear();
  QString fields("'', ");
  for (int row = 0; row < result->count(); row++) {
    headers->append(QStringList() << result->at(row).at(0) << result->at(row).at(1)
                    << (result->at(row).at(2).startsWith("PRI") ? ":/images/svg/server-database.svg" : "")
                    << "Left"
                    << result->at(row).at(3));
    fields += "`" + result->at(row).at(0) + "`, ";
  }
  fields = fields.mid(0, fields.length() - 2);
  resultDTableView->setHeaders(headers);
  result = serverConnection->runQuery("SELECT " + fields + " FROM " + p_database + "." + p_table + (!p_where.isEmpty() ? " WHERE " + p_where : ""));
  result->takeLast(); //Remove the "Affected rows" line.
  if (headers->count() > 0) {
    resultDTableView->setModelData(result, false);
    dTitleLabel->setText(tr("Result for: %1.%2").arg(p_database).arg(p_table));
    dTitleLabel->setToolTip(dTitleLabel->text());
    resultDTableView->blockSignals(false);
  } else {
    emit statusBarMessagePopup(tr("Database or table does not exist."));
  }
  QApplication::restoreOverrideCursor();
}

void Result::itemChangedSlot(QStandardItem *item)
{
  QString statement;
  if (item->data(80).toString().isEmpty()) {
    statement = "UPDATE "
        + p_database + "." + p_table
        + " SET " + StaticFunctions::quoteSymbol(resultDTableView->getHeaders()->at(item->column()).at(0))
        + " = " + (resultDTableView->getHeaders()->at(item->column()).at(0) == StaticFunctions::DelegateTypeNumber() ? item->data(Qt::DisplayRole).toString() : "'" + item->data(Qt::DisplayRole).toString() + "'")
        + " WHERE ";
    for (int row2 = 0; row2 < headers->count(); row2++)
      if (headers->at(row2).at(2) == ":/images/svg/server-database.svg")
        statement += StaticFunctions::quoteSymbol(headers->at(row2).at(0)) + " = '" + (headers->at(row2).at(0) == resultDTableView->getHeaders()->at(item->column()).at(0) ? item->data(Qt::UserRole).toString() : resultDTableView->indexData(item->row(), row2).toString()) + "' AND ";
    statement = statement.left(statement.length() - 5) + ";";
    resultDTableView->blockSignals(true);
    resultDTableView->currentItem()->setBackground(QBrush(QColor("yellow")));
    resultDTableView->blockSignals(false);
  } else {
    statement = "INSERT INTO " + p_database + "." + p_table + " VALUES (";
    for (int row = 0; row < statements->count(); row++)
      if (statements->at(row).startsWith(statement))
        statements->takeAt(row);
    for (int column = 0; column < resultDTableView->model()->columnCount(); column++)
      statement += "'" + resultDTableView->indexData(item->row(), column).toString() + "', ";
    statement = statement.mid(0, statement.length() - 2);
    statement += ")";
  }
  statements->append(statement);
  discardStatementsAction->setIcon(QIcon::fromTheme("user-trash-full", QIcon(":/images/svg/user-trash-full-4.svg")));
  discardStatementsAction->setEnabled(!statements->empty());
  viewChangesAction->setEnabled(!statements->empty());
}

void Result::deleteCurrentLineActionTriggered()
{
  QString statement;
  for (int row2 = 0; row2 < headers->count(); row2++)
    if (headers->at(row2).at(2) == ":/images/svg/server-database.svg")
      statement += StaticFunctions::quoteSymbol(headers->at(row2).at(0))
          + " = '" + resultDTableView->indexData(deleteCurrentLineAction->text().split(": ").at(1).toInt() - 1, row2).toString() + "' AND ";
  statement = statement.left(statement.length() - 5) + ";";
  statements->append("DELETE FROM " + p_database + "." + p_table + " WHERE " + statement);
  discardStatementsAction->setIcon(QIcon::fromTheme("user-trash-full", QIcon(":/images/svg/user-trash-full-4.svg")));
  discardStatementsAction->setEnabled(!statements->empty());
  viewChangesAction->setEnabled(!statements->empty());
  resultDTableView->blockSignals(true);
  foreach (QStandardItem *cel, resultDTableView->getRow(resultDTableView->currentItem()->row()))
    cel->setBackground(QBrush(QColor("red")));
  resultDTableView->blockSignals(false);
}

void Result::contextMenuEvent(QContextMenuEvent *event)
{
  deleteCurrentLineAction->setText(tr("Delete line: %1").arg(resultDTableView->currentIndexItem().row() + 1));
  deleteCurrentLineAction->setToolTip(deleteCurrentLineAction->text());
  menu->exec(event->globalPos());
}

QString Result::getDatabase()
{
  return p_database;
}

void Result::setDatabase(QString databaseName)
{
  p_database = StaticFunctions::quoteSymbol(databaseName);
}

QString Result::getTable()
{
  return p_table;
}

void Result::setTable(QString tableName)
{
  p_table = StaticFunctions::quoteSymbol(tableName);
}

QString Result::getWhere()
{
  return p_where;
}

void Result::setWhere(QString where)
{
  p_where = where;
}

