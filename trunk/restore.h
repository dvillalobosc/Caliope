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

#ifndef RESTORE_H
#define RESTORE_H

#include <QSettings>

class QProcess;
class QCheckBox;
class QLabel;
class QListWidget;
class QListWidgetItem;
class QDialogButtonBox;
class QGroupBox;
class FileSelector;
class DTitleLabel;
class DMessageLabel;
class QFormLayout;

#include "dmdisubwindow.h"

class Restore : public DMdiSubWindow
{
  Q_OBJECT

public:
  Restore();

private:
  QProcess *proc;
  QCheckBox *ignoreErrorsCheckBox;
  QCheckBox *restoreEntireFileCheckBox;
  QLabel *fileLabel;
//  QLabel *charsetLabel;
  QLabel *schemasLabel;
  QLabel *tablesLabel;
  QLabel *dataLengthLabel;
  QSettings settings;
  QStringList databaseList;
  void addDatabase(QString databaseName);
  QStringList tableList;
  void addTable(QString tableName);
  QStringList viewList;
  void addView(QString viewName);
  QListWidgetItem *listItem;
  QListWidget *databasesListWidget;
  QListWidget *tablesListWidget;
  QListWidget *viewsListWidget;
  QDialogButtonBox *buttonBox;
  QGroupBox *selectionGroupBox;
  FileSelector *fileSelector;
  DTitleLabel *dTitleLabel;
  DMessageLabel *dMessageLabel;
  QGroupBox *fileGroupBox;
  QFormLayout *fileGroupBoxLayout;
  QGroupBox *optionsGroupBox;

protected:
  void retranslateUi();

private slots:
  void restoreEntireFileSlot(int state);
  void getFileInfo(QString file = QString());
};

#endif // RESTORE_H
