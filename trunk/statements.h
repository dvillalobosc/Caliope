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

#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <QDialog>

class QMenu;
class DTableWidget;

class Statements : public QDialog
{
  Q_OBJECT

public:
  Statements();

public slots:
  void execSlot(QStringList *queries);

private:
  DTableWidget *queriesDTableWidget;
  QAction *copyAction;
  QClipboard *clipboard;
  QMenu *menu;
  QStringList *queryList;
  QAction *removeStatementAction;
  void createActions();
  void fillGrid();

private slots:
  void queriesCellDoubleClickedSlot();
  void copyToClipboard();
  void removeStatementActionTriggered();

protected:
  void contextMenuEvent(QContextMenuEvent *e);
};


#endif // STATEMENTS_H
