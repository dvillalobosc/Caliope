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

#include <QVBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QFileInfo>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDialogButtonBox>

#include "restore.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "dmessagelabel.h"
#include "fileselector.h"

Restore::Restore()
{
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  dMessageLabel = new DMessageLabel(MessageTypes::Warning);
  mainVLayout->addWidget(dMessageLabel);
  QHBoxLayout *fileLayout = new QHBoxLayout;
  fileSelector = new FileSelector(FileSelectorContexts::BackupFile);
  connect(fileSelector, SIGNAL(changed()), this, SLOT(getFileInfo()));
  fileLayout->addWidget(fileSelector);
  mainVLayout->addLayout(fileLayout);

  fileGroupBox = new QGroupBox;
  fileGroupBoxLayout = new QFormLayout;
  fileLabel = new QLabel;
  fileLabel->setTextFormat(Qt::PlainText);
//  charsetLabel = new QLabel;
  schemasLabel = new QLabel;
  tablesLabel = new QLabel;
  dataLengthLabel = new QLabel;
  fileGroupBoxLayout->addRow(" ", fileLabel);
//  fileGroupBoxLayout->addRow(tr("Character set:"), charsetLabel);
  fileGroupBoxLayout->addRow(" ", schemasLabel);
  fileGroupBoxLayout->addRow(" ", tablesLabel);
  fileGroupBoxLayout->addRow(" ", dataLengthLabel);
  fileGroupBox->setLayout(fileGroupBoxLayout);
  mainVLayout->addWidget(fileGroupBox);

  optionsGroupBox = new QGroupBox;
  QGridLayout *optionsGroupBoxLayout = new QGridLayout;
  ignoreErrorsCheckBox = new QCheckBox;
  optionsGroupBoxLayout->addWidget(ignoreErrorsCheckBox, 0, 0, Qt::AlignLeft);
  restoreEntireFileCheckBox = new QCheckBox;
  connect(restoreEntireFileCheckBox, SIGNAL(stateChanged(int)), this, SLOT(restoreEntireFileSlot(int)));
  optionsGroupBoxLayout->addWidget(restoreEntireFileCheckBox, 0, 1, Qt::AlignLeft);
  optionsGroupBox->setLayout(optionsGroupBoxLayout);
  mainVLayout->addWidget(optionsGroupBox);

  selectionGroupBox = new QGroupBox;
  QHBoxLayout *selectionGroupBoxLayout = new QHBoxLayout;
  databasesListWidget = new QListWidget;
  tablesListWidget = new QListWidget;
  viewsListWidget = new QListWidget;
  selectionGroupBoxLayout->addWidget(databasesListWidget);
  selectionGroupBoxLayout->addWidget(tablesListWidget);
  selectionGroupBoxLayout->addWidget(viewsListWidget);
  selectionGroupBox->setLayout(selectionGroupBoxLayout);
  mainVLayout->addWidget(selectionGroupBox);
//  mainVLayout->addStretch();

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Apply | QDialogButtonBox::Help);
//  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  mainVLayout->addWidget(buttonBox);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);

  getFileInfo();
  restoreEntireFileCheckBox->setChecked(true);
}

void Restore::retranslateUi()
{
  setWindowTitle(tr("Restore"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  dTitleLabel->setToolTip(dTitleLabel->text());
  dMessageLabel->setText(tr("Unfortunately read backup files is a very complex process."
                            " Especially when finding objects names. Therefore we recommend that only"
                            " use backup files created with this application. But restore an entire"
                            " file should work without any problem."));
  fileSelector->setText(tr("&File:"));
  fileGroupBox->setTitle(tr("File information"));
  QLabel *label = qobject_cast<QLabel *>(fileGroupBoxLayout->labelForField(fileLabel));
  label->setText(tr("File:"));
  label->setToolTip(label->text());
  label = qobject_cast<QLabel *>(fileGroupBoxLayout->labelForField(schemasLabel));
  label->setText(tr("Total schemas:"));
  label->setToolTip(label->text());
  label = qobject_cast<QLabel *>(fileGroupBoxLayout->labelForField(tablesLabel));
  label->setText(tr("Total tables:"));
  label->setToolTip(label->text());
  label = qobject_cast<QLabel *>(fileGroupBoxLayout->labelForField(dataLengthLabel));
  label->setText(tr("Total data length:"));
  label->setToolTip(label->text());
  optionsGroupBox->setTitle(tr("Options"));
  optionsGroupBox->setToolTip(optionsGroupBox->title());
  ignoreErrorsCheckBox->setText(tr("Ignore errors"));
  ignoreErrorsCheckBox->setToolTip(ignoreErrorsCheckBox->text());
  restoreEntireFileCheckBox->setText(tr("Restore the entire file"));
  restoreEntireFileCheckBox->setToolTip(restoreEntireFileCheckBox->text());
  selectionGroupBox->setTitle(tr("Object selection"));
  selectionGroupBox->setToolTip(selectionGroupBox->title());
}

void Restore::restoreEntireFileSlot(int state)
{
  selectionGroupBox->setEnabled(state == Qt::Checked ? false : true);
}

void Restore::addDatabase(QString databaseName)
{
  databaseList << databaseName;
  listItem = new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), databaseName);
  listItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);// | Qt::ItemIsSelectable);
  listItem->setCheckState(Qt::Unchecked);
  databasesListWidget->addItem(listItem);
}

void Restore::addTable(QString tableName)
{
  tableList << tableName;
  listItem = new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), tableName);
  listItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);// | Qt::ItemIsSelectable);
  listItem->setCheckState(Qt::Unchecked);
  tablesListWidget->addItem(listItem);
}

void Restore::addView(QString viewName)
{
  viewList << viewName;
  listItem = new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), viewName);
  listItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);// | Qt::ItemIsSelectable);
  listItem->setCheckState(Qt::Unchecked);
  viewsListWidget->addItem(listItem);
}

void Restore::getFileInfo(QString file)
{
  if (file.isEmpty())
    file = fileSelector->getFileName();
  QFileInfo fileInfo(file);
  QFile backupFie(file);
  databaseList.clear();
  databasesListWidget->clear();
  tableList.clear();
  tablesListWidget->clear();
  backupFie.open(QIODevice::ReadOnly);
  while (!backupFie.atEnd()) {
    QString line(backupFie.readLine());
    if (line.contains(QRegExp("^CREATE.*DATABASE")))
      addDatabase(line.mid(line.indexOf("`") + 1, line.indexOf("`", line.indexOf("`") + 1) - line.indexOf("`") -1 ));
    if (line.contains(QRegExp("^CREATE.*TABLE")))
      addTable(line.mid(line.indexOf("`") + 1, line.indexOf("`", line.indexOf("`") + 1) - line.indexOf("`") -1 ));
    if (line.contains(QRegExp("^CREATE.*VIEW")))
      addView(line.mid(line.indexOf("`") + 1, line.indexOf("`", line.indexOf("`") + 1) - line.indexOf("`") -1 ));
  }
  schemasLabel->setText(QString("%1").arg(databaseList.count()));
  schemasLabel->setToolTip(schemasLabel->text());
  fileLabel->setText(fileSelector->getFileName());
  fileLabel->setToolTip(fileLabel->text());
  tablesLabel->setText(QString("%1").arg(tableList.count()));
  tablesLabel->setToolTip(tablesLabel->text());
  dataLengthLabel->setText("~" + StaticFunctions::bytesConvertor(QString("%1").arg(fileInfo.size())));
  dataLengthLabel->setToolTip(dataLengthLabel->text());
}
