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

#ifndef DatabaseComparision_H
#define DatabaseComparision_H

class QTreeWidgetItem;
class QTreeWidget;
class BaseTextEditor;
class DBMS;
class QPushButton;
class DTitleLabel;
class QGroupBox;

#include "dmdisubwindow.h"

class DatabaseComparision : public DMdiSubWindow
{
  Q_OBJECT

public:
  DatabaseComparision(DBMS *serverConnection);

private:
  DBMS *serverConnection;
  DBMS *secondaryServerConnection;
  QList<QTreeWidgetItem *> tables;
  QList<QTreeWidgetItem *> secondaryTables;
  QTreeWidget *tablesListWidget;
  QTreeWidget *secondaryTablesListWidget;
  BaseTextEditor *resutlEditor;
  QPushButton *pushButtonPrimaryCompare;
  QPushButton *pushButtonSecondaryCompare;
  QString highlightError(QList<QStringList> *rows, int row);
  void comparision(bool primary = true);
  DTitleLabel *dTitleLabel;
  QGroupBox *buttonGroup;

protected:
  void retranslateUi();

private slots:
  void fillTablesSlot();
  void comparePrimarySlot();
  void compareSeconadarySlot();
  void itemActivatedSlot(QTreeWidgetItem *item, int column);
  void secondaryItemActivatedSlot(QTreeWidgetItem *item, int column);

signals:
  void statusBarMessage(QString message);
};

#endif // DatabaseComparision_H
