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

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QSettings>

class QComboBox;
class QCheckBox;
class QSpinBox;
class QLineEdit;
class DTableView;
class FileAssociations;
class QStandardItem;
class FileSelector;
class DTitleLabel;
class QFormLayout;
class QGroupBox;
class LicenseTemplate;
class NetworkSettings;
class DStackedWidget;
class ApplicationTheme;

#include "dmdisubwindow.h"

class Preferences : public DMdiSubWindow
{
  Q_OBJECT

public:
  Preferences();

private:
  QComboBox *stylesCombo;
  QSpinBox *tabSizeSpinBox;
  QCheckBox *checkBoxRememberWindows;
  QCheckBox *checkBoxOpenLastFile;
  QSettings settings;
  QCheckBox *checkBoxAutomaticIndentation;
  QCheckBox *checkBoxCleanwhiteSpaces;
  QCheckBox *checkBoxSaveABackupFile;
  DTableView *listConnections;
  QList<QStringList> *connectionsData;
  FileAssociations *fileAssociationsTab;
  QCheckBox *checkBoxSaveQueryBeforeExecution;
  QCheckBox *checkBoxShowTabsAndSpaces;
  FileSelector *phpPHPCommand;
  DTitleLabel *dTitleLabel;
  QFormLayout *styleFLayout;
  QGroupBox *styleGroupBox;
  QFormLayout *textEditorFLayout;
  LicenseTemplate *licenseTemplate;
  NetworkSettings *networkSettings;
  FileAssociations *fileAssociations;
  void fillModelData();
  DStackedWidget *dStackedWidget;
  QCheckBox *checkBoxEnableQueryLog;
  ApplicationTheme *applicationTheme;
  FileSelector *fileSelectorBackgroundImage;

protected:
  void retranslateUi();

private slots:
  void stylesComboCurrentIndexChanged(const QString &text);
  void checkBoxRememberWindowsStateChanged();
  void checkBoxOpenLastFileStateChanged();
  void tabSizeSpinBoxValueChanged(int value);
  void checkBoxAutomaticIndentationValueChanged(int value);
  void checkBoxCleanwhiteSpacesValueChanged(int value);
  void checkBoxSaveABackupFileValueChanged(int value);
  void connectioItemChangedSlot(QStandardItem *item);
  void checkBoxSaveQueryBeforeExecutionStateChanged();
  void checkBoxShowTabsAndSpacesValueChanged(int value);
  void checkBoxEnableQueryLogValueChanged(int value);
  void fileSelectorBackgroundImageSlot();
};

#endif // PREFERENCES_H
