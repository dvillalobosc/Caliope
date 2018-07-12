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

#ifndef DTABLEWIDGET_H
#define DTABLEWIDGET_H

#include <QTableWidget>

#include "dbms.h"

class DTableWidget : public QTableWidget
{
  Q_OBJECT

  Q_PROPERTY(QString tableName READ getTableName WRITE setTableName)

public:
  DTableWidget(QStringList headers = QStringList(), QAbstractItemView::SelectionMode selectionMode = QAbstractItemView::SingleSelection);
  void setHeaders(QStringList headers);
  void fillTable(QList<QStringList> *rows);
  void retranslateUi();
  void setPasteActionEnabled(bool enabled = true);
  void setTableName(QString tableName);
  QString getTableName();

private:
  QMenu *mainMenu;
  QAction *copyAction;
  QAction *pasteAction;
  QString tableName;
  QStringList statementsToExecute;

signals:
  void executeStatements(QStringList statements);

public slots:
  void cellClickedSlot();
  void copy();
  void paste();

protected:
  void contextMenuEvent(QContextMenuEvent *event);
};

#endif // DTABLEWIDGET_H
