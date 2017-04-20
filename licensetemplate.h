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

#ifndef LICENSETEMPLATE_H
#define LICENSETEMPLATE_H

#include <QDialog>
#include <QSettings>

class QPlainTextEdit;
class QDialogButtonBox;
class FileSelector;

class LicenseTemplate : public QDialog
{
  Q_OBJECT

public:
  LicenseTemplate();
  static QString License();
  void retranslateUi();

private:
  QSettings settings;
  QPlainTextEdit *licensePlainTextEdit;
  QDialogButtonBox *buttonBox;
  FileSelector *fileSelector;

private slots:
  void saveLicenseTemplateText();
  void helpLicenseTemplate();
  void fileSelectorSlot();
  void validateText();
};

#endif // LICENSETEMPLATE_H
