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

#ifndef DQUERYLOG_H
#define DQUERYLOG_H

#include <dmdisubwindow.h>
#include "dbms.h"

class DTitleLabel;
class QTableView;
class QGroupBox;
class QPushButton;
class QComboBox;
class QLabel;
class DLineEdit;

class DQueryLog : public DMdiSubWindow
{
  Q_OBJECT

public:
  DQueryLog(DBMS *serverConnection);

private:
  DTitleLabel *dTitleLabel;
  DBMS *serverConnection;
  QTableView *queryLogTableView;
  QGroupBox *buttonBox;
  QPushButton *pushButtonRefresh;
  QComboBox *comboBoxFilter;
  QPushButton *pushButtonClearQueryLog;
  QLabel *labelFileSize;
  void getFileInfo();
  DLineEdit *lineEditFilter;
  QLabel *filterByQuery;

private slots:
  void pushButtonRefreshClicked();
  void comboBoxFilterActivated(QString filter);
  void pushButtonClearQueryLogClicked();
  void lineEditFilterTextChangedSlot(QString filter);

protected:
  void retranslateUi();
};

#endif // DQUERYLOG_H
