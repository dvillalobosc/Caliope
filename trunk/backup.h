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

#ifndef BACKUP_H
#define BACKUP_H

#include <QSettings>

#include "dmdisubwindow.h"
#include "dbms.h"

class QProcess;
class QListWidget;
class QPushButton;
class QCheckBox;
class QGridLayout;
class FileSelector;
class DTitleLabel;
class DMessageLabel;

class Backup : public DMdiSubWindow
{
  Q_OBJECT

public:
  Backup(DBMS *serverConnection);

private:
  QProcess *proc;
  DBMS *serverConnection;
  QListWidget *databasesListWidget;
  QPushButton *backItUpPushButton;
  QSettings settings;
  FileSelector *fileSelector;

  void createCheckBoxesMariaDB();
  QGridLayout *gridChecks;
  QCheckBox *addDropDatabase;
  QCheckBox *addDropTable;
  QCheckBox *addDropTrigger;
  QCheckBox *addLocks;
  QCheckBox *allDatabases;
  QCheckBox *allTablespaces;
  QCheckBox *allowKeywords;
  QCheckBox *comments;
  QCheckBox *xml;
  QCheckBox *createOptions;
  QCheckBox *compact;
  QCheckBox *compliteInsert;
  QCheckBox *delayedInsert;
  QCheckBox *deleteMasterLogs;
  QCheckBox *verbose;
  QCheckBox *disableKeys;
  QCheckBox *dumpDate;
  QCheckBox *events;
  QCheckBox *extendedInsert;
  QCheckBox *flushLogs;
  QCheckBox *flushPrivileges;
  QCheckBox *hexBlob;
  QCheckBox *insertIgnore;
  QCheckBox *lockAllTables;
  QCheckBox *lockTables;
  QCheckBox *noAutocommit;
  QCheckBox *noCreateDb;
  QCheckBox *triggers;
  QCheckBox *tzUtc;
  QCheckBox *noCreateInfo;
  QCheckBox *noData;
  QCheckBox *noSetNames;
  QCheckBox *noTablespaces;
  QCheckBox *opt;
  QCheckBox *orderByPrimary;
  QCheckBox *quick;
  QCheckBox *quoteNames;
  QCheckBox *replace;
  QCheckBox *routines;
  QCheckBox *singleTransaction;
  QCheckBox *skipAddDropTable;
  QCheckBox *skipAddLocks;
  QCheckBox *skipComments;
  QCheckBox *skipCompact;
  QCheckBox *skipDisableKeys;
  QCheckBox *skipExtendedInsert;
  QCheckBox *skipOpt;
  QCheckBox *skipQuick;
  QCheckBox *skipQuoteNames;
  QCheckBox *skipSetCharset;
  QCheckBox *skipTriggers;
  QCheckBox *skipTzUtc;
  QCheckBox *item;
  DTitleLabel *dTitleLabel;
  DMessageLabel *dMessageLabel;

private slots:
  void finishedSlot(int exitCode);
  void readyReadStandardErrorSlot();
  void backItUpSlot();
  void allDatabasesSlot();
  void disbaleBackItIp();

  void skipAddDropTableSlot(int state);
  void skipAddLocksSlot(int state);
  void skipCommentsSlot(int state);
  void skipCompactSlot(int state);
  void skipDisableKeysSlot(int state);
  void skipExtendedInsertSlot(int state);
  void skipOptSlot(int state);
  void skipQuickSlot(int state);
  void skipQuoteNamesSlot(int state);
  void skipSetCharsetSlot(int state);
  void skipTriggersSlot(int state);
  void skipTzUtcSlot(int state);

protected:
  void retranslateUi();
};

#endif // BACKUP_H
