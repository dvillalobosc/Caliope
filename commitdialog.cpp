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

#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTabWidget>
#include <QTemporaryFile>
#include <QTextStream>
#include <QFileInfo>

#include "commitdialog.h"
#include "dtitlelabel.h"
#include "basedifffile.h"
#include "basetexteditor.h"
#include "staticfunctions.h"

CommitDialog::CommitDialog(QString file)
{
  QFileInfo svnFile(file);
  setWindowTitle(tr("Commit changes for ") + svnFile.completeBaseName() + "." + svnFile.completeSuffix());
  setObjectName(windowTitle());
  setWindowIcon(QIcon(":/images/svg/svn-commit.svg"));

  lineEditUser = new QLineEdit;
  lineEditUser->setText(settings.value("Subversion/LastUser", "").toString());

  lineEditPassword = new QLineEdit;
  lineEditPassword->setText(StaticFunctions::password(settings.value("Subversion/LastPassword", "").toString()));
  lineEditPassword->setEchoMode(QLineEdit::Password);

  QVBoxLayout *diffVLayout = new QVBoxLayout;
  diffVLayout->addWidget(new BaseDiffFile(file));
  QWidget *widDiff = new QWidget;
  widDiff->setLayout(diffVLayout);

  commitLog = new BaseTextEditor(EditorTypes::Commit);
  commitLog->setPlainText(settings.value("Subversion/LastLog", "").toString());

  QTabWidget *commitTab = new QTabWidget;
  commitTab->setMovable(true);
  commitTab->addTab(commitLog, tr("Commit log"));
  commitTab->addTab(widDiff, tr("Diff file"));

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("&User:"), lineEditUser);
  formLayout->addRow(tr("&Password:"), lineEditPassword);

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::Help);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  QVBoxLayout *verticalLayout = new QVBoxLayout;
  verticalLayout->addWidget(new DTitleLabel(windowTitle()));
  verticalLayout->addWidget(commitTab);
  verticalLayout->addLayout(formLayout);
  verticalLayout->addWidget(buttonBox);
  setLayout(verticalLayout);
}

QStringList CommitDialog::getValues()
{
  QTemporaryFile file;
  file.open();
  file.setAutoRemove(false);
  QTextStream out(&file);
  out << commitLog->toPlainText();
  file.close();
  settings.setValue("Subversion/LastPassword", StaticFunctions::password(lineEditPassword->text(), true));
  settings.setValue("Subversion/LastUser", lineEditUser->text());
  settings.setValue("Subversion/LastLog", commitLog->toPlainText());
  return QStringList() << "--non-interactive"
                       << "--username" << lineEditUser->text()
                       << "--password" << lineEditPassword->text()
                       << "--file" << file.fileName();
}
