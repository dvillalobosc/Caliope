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

#include <QFileDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDir>

#include "fileselector.h"
#include "dlineedit.h"

FileSelector::FileSelector(FileSelectorContexts::FileSelectorContext context, QString label, bool showSaveDialog)
{
  this->showSaveDialog = showSaveDialog;
  this->context = context;
  switch(context) {
  case FileSelectorContexts::BackupFile:
    setting = "Backup/LastFile";
    break;
  case FileSelectorContexts::LicenseFile:
    setting = "License/File";
    break;
  case FileSelectorContexts::ProjectFile:
    setting = "Project/File";
    break;
  case FileSelectorContexts::PHPExecutable:
    setting = "PHP/Executable";
  case FileSelectorContexts::Image:
    setting = "LastFileImg";
    break;
  // default: Q_ASSERT(false);
  }
  QHBoxLayout *fileLayout = new QHBoxLayout;
  fileLabel = new QLabel;
  setText(label);
  //fileLabel->setMargin(5);
  lineEditFile = new DLineEdit(QIcon::fromTheme("folder", QIcon(":/images/svg/folder.svg")));
//  lineEditFile->setText(settings.value(setting, "").toString());
  connect(lineEditFile, SIGNAL(textChanged(QString)), this, SLOT(emitChanged()));
  connect(lineEditFile, SIGNAL(clicked()), this, SLOT(selectFileSlot()));
  fileLabel->setBuddy(lineEditFile);
  fileLayout->addWidget(fileLabel);
  fileLayout->addWidget(lineEditFile);
  retranslateUi();
  setLayout(fileLayout);
}

void FileSelector::retranslateUi()
{
  switch(context) {
  case FileSelectorContexts::BackupFile:
    title = tr("SQL files (*.sql)");
    break;
  case FileSelectorContexts::LicenseFile:
    title = tr("Text files (*.txt)");
    break;
  case FileSelectorContexts::ProjectFile:
    title = tr("Project files (*.pro)");
    break;
  case FileSelectorContexts::PHPExecutable:
    title = tr("Bin files (*)");
    break;
  case FileSelectorContexts::Image:
    title = tr("Image files (*.png *.jpg *.bmp)");
    break;
  // default: Q_ASSERT(false);
  }
}

bool FileSelector::isEmpty()
{
  return lineEditFile->text().isEmpty();
}

QString FileSelector::getFileName()
{
  return lineEditFile->text();
}

QDir FileSelector::fileDir()
{
  QFileInfo file(lineEditFile->text());
  return file.dir();
}

void FileSelector::emitChanged()
{
  emit changed();
}

void FileSelector::selectFileSlot()
{
  if (showSaveDialog)
    lineEditFile->setText(QFileDialog::getSaveFileName(this, tr("Open a file"), "", title));
  else
    lineEditFile->setText(QFileDialog::getOpenFileName(this, tr("Open a file"), "", title));
  if (settings.value("OpenLastFile", false).toBool())
    settings.setValue(setting, lineEditFile->text());
}

void FileSelector::setFileName(QString text)
{
  lineEditFile->setText(text);
}

QString FileSelector::fileText()
{
  QFile fileToOpen(lineEditFile->text());
  fileToOpen.open(QFile::ReadOnly | QFile::Text);
//  if (!fileToOpen.open(QFile::ReadOnly | QFile::Text))
//    parentWidget->statusBarMessage(tr("Cannot read file %1:\n%2.").arg(fileName).arg(fileToOpen.errorString()), QSystemTrayIcon::Critical);
  QString output(QString::fromUtf8(fileToOpen.readAll()));
  fileToOpen.close();
  return output;
}

void FileSelector::setText(QString name)
{
  fileLabel->setText(name);
}
