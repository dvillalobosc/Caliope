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

#ifndef FILESELECTOR_H
#define FILESELECTOR_H

#include <QWidget>
#include <QSettings>

class DLineEdit;
class QDir;
class QLabel;

class FileSelectorContexts
{
public:
  enum FileSelectorContext {BackupFile = 1, LicenseFile, ProjectFile, PHPExecutable, Image};
};

class FileSelector : public QWidget
{
  Q_OBJECT

signals:
  void changed();

public:
  FileSelector(FileSelectorContexts::FileSelectorContext context, QString label = QString(), bool showSaveDialog = false);
  bool isEmpty();
  QString getFileName();
  QDir fileDir();
  void setFileName(QString getFileName = QString());
  QString fileText();
  void setText(QString name = QString());
  void retranslateUi();

private:
  DLineEdit *lineEditFile;
  QSettings settings;
  QString setting;
  QString title;
  bool showSaveDialog;
  QLabel *fileLabel;
  FileSelectorContexts::FileSelectorContext context;

private slots:
  void selectFileSlot();
  void emitChanged();
};

#endif // FILESELECTOR_H
