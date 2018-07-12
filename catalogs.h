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

#ifndef CATALOGS_H
#define CATALOGS_H

#include <QDialog>
#include <QModelIndex>
#include <QStandardItem>
#include <QSystemTrayIcon>

class QTabWidget;
class QToolBar;
class QAction;
class QComboBox;
class QMenu;
class NewDatabase;
class BaseTextEditor;
class DTableView;
class DTitleLabel;
class TextEditor;
class Projects;

#include "dmdisubwindow.h"
#include "dbms.h"

class ItemEditorTypes
{
public:
  enum ItemEditorType {Table, View, Index, Field, Routine, Trigger, Event};
};

class ItemEditor : public QDialog
{
  Q_OBJECT

public:
  ItemEditor(DBMS *serverConnection, QString title, ItemEditorTypes::ItemEditorType type);
  TextEditor *editor;

private:
  ItemEditorTypes::ItemEditorType itemType;

signals:
  void openURL(QString url);

private slots:
  void applyStatement();
  void help();
  void openURLSlot(QString url);
};

class Catalogs : public DMdiSubWindow
{
  Q_OBJECT

public:
  Catalogs(DBMS *serverConnection);
  bool readOnly;

protected:
  void retranslateUi();

public slots:
  void updateObjectInfo();
  void newDatabaseActionTriggered();
  void deleteDatabaseActionTriggered();
  void setReadOnly(bool readOnly);
  void populateTableActionTriggered();

private:
  DBMS *serverConnection;
  QTabWidget *catalogsTab;
  DTableView *tablesDTableView;
  DTableView *viewsDTableView;
  DTableView *indexesDTableView;
  DTableView *fieldsDTableView;
  DTableView *routinesDTableView;
  DTableView *triggersDTableView;
  DTableView *eventsDTableView;
  BaseTextEditor *readOnlyEditor;
  QList<QStringList> *result;
  ItemEditor *itemEditor;
  NewDatabase *newDatabase;
  int lastRow;

  void indexesInfo(QString table);
  void fieldsInfo(QString table);
  void triggersInfo(QString table);
  void deleteTables();
  void deleteViews();
  void deleteIndexes();
  void deleteFields();
  void deleteRoutines();
  void setTitle();
  DTitleLabel *dTitleLabel;
  QString valueToPopulate(QString dataType, unsigned int length = 1);

private slots:
  void tablesInfo();
  void viewsInfo();
  void routinesInfo();
  void eventsInfo();
  void tablesClicked(QModelIndex modelIndex);
  void viewsClicked(QModelIndex modelIndex);
  void routinesClicked(QModelIndex modelIndex);
  void triggersClicked(QModelIndex modelIndex);
  void eventsClicked(QModelIndex modelIndex);
  void newObjectSlot();
  void editObjectSlot();
  void deleteObjectSlot();
  void tablesItemChangedSlot(QStandardItem *item);
  void statusBarProgressMessageSlot(const QString &message, const unsigned int timeout = 0, const double progress = 0);

signals:
  void loadStarted(QString message, unsigned int timeout, double progress);
  void loadFinished(QString message, unsigned int timeout, double progress);
  void loadProgress(QString message, unsigned int timeout, double progress);
  void statusBarProgressMessage(const QString &message, const unsigned int timeout = 0, const double progress = 0);
  void statusBarMessagePopup(const QString &message, const int timeout = 0);
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 0);
};

#endif // CATALOGS_H
