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

#ifndef MARIADBHELP_H
#define MARIADBHELP_H

#include <QTreeWidget>

#include "dmdisubwindow.h"
#include "dbms.h"

class QTextEdit;
class QLineEdit;
class QSplitter;
class DLineEdit;
class DTitleLabel;

class MariaDBHelp : public DMdiSubWindow
{
  Q_OBJECT

public:
  MariaDBHelp(DBMS *serverConnection);

protected:
  void retranslateUi();

private:
  QTextEdit *helpView;
  DBMS *serverConnection;
  DLineEdit *lineEditFilter;
  QTreeWidget *helpTreeWidget;
  QList<QStringList> *rows;
  QSplitter *mainSplitter;
  DTitleLabel *dTitleLabel;

private slots:
  void showTopicSlot(QTreeWidgetItem *item, int column);
  void saveSizesSlot(int pos, int index);
  void fillHelpTreeWidget(QString filter = QString());
};

#endif // MARIADBHELP_H
