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

#ifndef RESULT_H
#define RESULT_H

#include <QVariant>

class DBMS;
class DTableView;
class QMenu;
class DTitleLabel;
class QToolBar;
class Statements;
class QStandardItem;

#include "dmdisubwindow.h"

class Result : public DMdiSubWindow
{
  Q_OBJECT
  Q_PROPERTY(QString table READ getTable WRITE setTable)
  Q_PROPERTY(QString database READ getDatabase WRITE setDatabase)
  Q_PROPERTY(QString where READ getWhere WRITE setWhere)

public:
  Result(DBMS *serverConnection, QString table, QString database = QString(), QString where = QString());
  QString getTable();
  QString getDatabase();
  QString getWhere();
  void setTable(QString tableName = QString());
  void setDatabase(QString databaseName = QString());
  void setWhere(QString where = QString());

private:
  DBMS *serverConnection;
  DTableView *resultDTableView;
  QList<QStringList> *result;
  QAction *refreshAction;
  QAction *applyStatementsAction;
  QAction *discardStatementsAction;
  QAction *deleteCurrentLineAction;
  QMenu *menu;
  QString p_table;
  QString p_database;
  QString p_where;
  DTitleLabel *dTitleLabel;
  QList<QStringList> *headers;
  QStringList *statements;
  QToolBar *resultToolBar;
  void createActions();
  Statements *statementsDialog;
  QAction *viewChangesAction;
  QAction *addRowAction;

public slots:
  void updateResult();

private slots:
  void itemChangedSlot(QStandardItem *item);
  void applyStatementsActionTriggered();
  void discardStatementsActionTriggered();
  void deleteCurrentLineActionTriggered();
  void viewChangesActionTriggered();
  void addRow();
  void statusBarProgressMessageSlot(const QString &message, const unsigned int timeout, const double progress);

signals:
  void statusBarMessagePopup(QString message);
  void statusBarProgressMessage(const QString &message, const unsigned int timeout, const double progress);

protected:
  void contextMenuEvent(QContextMenuEvent *event);
  void retranslateUi();
};

#endif // RESULT_H
