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

#ifndef TABLEMAINTENANCE_H
#define TABLEMAINTENANCE_H

#include <QWizard>
#include <QWizardPage>

class QTreeWidget;
class BaseTextEditor;
class QTreeWidgetItem;
class QCheckBox;
class QRadioButton;
class DTitleLabel;
class QGroupBox;

#include "dbms.h"
#include "dmdisubwindow.h"

class TableMaintenance : public DMdiSubWindow
{
  Q_OBJECT

public:
  TableMaintenance(DBMS *serverConnection);

protected:
  void retranslateUi();

private:
  DBMS *serverConnection;
  QTreeWidget *tablesListWidget;
  BaseTextEditor *resutlEditor;
  QPushButton *analyzePushButton;
  QPushButton *checkPushButton;
  QPushButton *checksumPushButton;
  QPushButton *optimizePushButton;
  QPushButton *repairPushButton;
  QList<QTreeWidgetItem *> tables;
  QCheckBox *optionLOCAL;
  QRadioButton *optionFORUPGRADE;
  QRadioButton *optionQUICK;
  QRadioButton *optionFAST;
  QRadioButton *optionMEDIUM;
  QRadioButton *optionEXTENDED;
  QRadioButton *optionCHANGED;
  QRadioButton *optionUSE_FRM;
  DTitleLabel *dTitleLabel;
  QGroupBox *groupBoxAction;
  QPushButton *clearSelectionPushButton;
  QPushButton *selectAllTablesPushButton;
  QPushButton *selectAllLocalTablesPushButton;
  bool selectAllLocalTables;

private:
  QString tableList();
  void executeStatement(const QString statement);

private slots:
  void fillDatabasesSlot();
  void analyzePushButtonSlot();
  void checkPushButtonSlot();
  void checksumPushButtonSlot();
  void optimizePushButtonSlot();
  void repairPushButtonSlot();
  void itemActivatedSlot(QTreeWidgetItem *item, int column);
  void clearSelectionPushButtonSlot();
  void selectAllTablesPushButtonSlot();
  void selectAllLocalTablesPushButtonSlot();
};

//class IntroPageTableMaintenance : public QWizardPage
//{
//public:
//  IntroPageTableMaintenance();
//};

//class SelectDatabase : public QWizardPage
//{
//  Q_OBJECT

//public:
//  SelectDatabase();

//private:
//  QListWidget *listWidget;

////private slots:
////  void itemSelectionChangedSlot();
//};

//class SelectTables : public QWizardPage
//{
//  Q_OBJECT

//public:
//  SelectTables();

//private:
//  QPushButton *button;
//  QString databases;

//protected:
//  void initializePage();
//};

//class TableMaintenanceWizard : public QWizard
//{
//public:
//  TableMaintenanceWizard();
//  enum {Intro_Page, SelectDatabase_Page, SelectTables_Page};

//private:
//  SelectDatabase *selectDatabases;
//  SelectTables *selectTables;
////  QString database;
//};

#endif // TABLEMAINTENANCE_H
