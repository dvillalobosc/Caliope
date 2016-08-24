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

#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "dmdisubwindow.h"
#include "dbms.h"

class QMenu;
class DTableView;
class QGroupBox;
class DTitleLabel;
class QPushButton;
class QSpinBox;

class ProcessList : public DMdiSubWindow
{
  Q_OBJECT

public:
  ProcessList(DBMS *serverConnection);

protected:
  void retranslateUi();

private:
  DBMS *serverConnection;
  DTableView *processTable;
  QList<QStringList> *result;
  QAction *killThread;
  QMenu *menu;
  QPushButton *pushButtonStopRefreshing;
  QTimer *timerRefresh;
  QGroupBox *buttonGroup;
  DTitleLabel *dTitleLabel;
  QPushButton *pushButtonKillIdleThreads;
  QSpinBox *spinBoxTimeLimit;
  QSettings settings;
  QSpinBox *spinBoxRefreshRate;
  QAction *killQuery;

private slots:
  void reloadData();
  void killThreadSlot();
  void killIdleThreadsSlot();
  void refreshRateSlot(const int value);
  void killQuerySlot();

protected:
  void contextMenuEvent(QContextMenuEvent *event);
};

#endif // PROCESSLIST_H
