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

#include <QAction>
#include <QMessageBox>
#include <QProcess>
#include <QList>

#include "subversionedfile.h"
#include "commitdialog.h"
#include "difffile.h"
#include "svnlog.h"

#include "QDebug"

SubversionedFile::SubversionedFile(QString file)
{
  fileName = file;
  svnDiffAction = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Diff"), this);
  connect(svnDiffAction, SIGNAL(triggered()), this, SLOT(svnDiffActionTriggered()));
  svnCommitAction = new QAction(QIcon(":/images/svg/svn-commit.svg"), tr("Commit"), this);
  connect(svnCommitAction, SIGNAL(triggered()), this, SLOT(svnCommitActionTriggered()));
  svnRevertAction = new QAction(QIcon::fromTheme("document-revert", QIcon(":/images/svg/document-revert-5.svg")), tr("Revert"), this);
  connect(svnRevertAction, SIGNAL(triggered()), this, SLOT(svnRevertActionTriggered()));
  svnInfoAction = new QAction(QIcon::fromTheme("dialog-information", QIcon(":/images/svg/dialog-information-4.svg")), tr("Info"), this);
  connect(svnInfoAction, SIGNAL(triggered()), this, SLOT(svnInfoActionTriggered()));
  svnStatusAction = new QAction(tr("Status"), this);
  connect(svnStatusAction, SIGNAL(triggered()), this, SLOT(svnStatusActionTriggered()));
  svnUpdateAction = new QAction(QIcon(":/images/svg/svn-update.svg"), tr("Update"), this);
  connect(svnUpdateAction, SIGNAL(triggered()), this, SLOT(svnUpdateActionTriggered()));
  svnAddAction = new QAction(QIcon::fromTheme("list-add", QIcon(":/images/svg/list-add-5.svg")), tr("Add"), this);
  connect(svnAddAction, SIGNAL(triggered()), this, SLOT(svnAddActionTriggered()));
  svnDeleteAction = new QAction(QIcon::fromTheme("list-remove", QIcon(":/images/svg/list-remove-5.svg")), tr("Delete"), this);
  connect(svnDeleteAction, SIGNAL(triggered()), this, SLOT(svnDeleteActionTriggered()));
  svnLogAction = new QAction(QIcon(":/images/svg/text-x-changelog.svg"), tr("Log"), this);
  connect(svnLogAction, SIGNAL(triggered()), this, SLOT(svnLogActionTriggered()));
}

QString SubversionedFile::svnCommand(QStringList commands)
{
  QProcess *process = new QProcess(this);
  process->start("svn", QStringList() << commands << fileName);
  process->waitForFinished();
  QByteArray output = process->readAll();
  QString result;
  for (int counter = 0; counter < output.size(); ++counter)
    result += output.at(counter);
  return result;
}

bool SubversionedFile::validateVersionedFile()
{
  if (fileName.isEmpty()) {
    QMessageBox::warning(this, tr("Version control"), tr("This is not a versioned file.") + "\n" + fileName);
    return false;
  }
  return true;
}

void SubversionedFile::svnDiffActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit addSubWindow(new DiffFile(fileName));
}

void SubversionedFile::svnCommitActionTriggered()
{
  if (!validateVersionedFile())
    return;

  CommitDialog *commitForm = new CommitDialog(fileName);
  if (commitForm->exec() == QDialog::Accepted)
    emit statusBarMessagePopup(svnCommand(QStringList() << "commit" << commitForm->getValues()));
}

void SubversionedFile::svnRevertActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit statusBarMessage(svnCommand(QStringList() << "revert" << "-R"));
  emit reverted();
}

void SubversionedFile::svnInfoActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit statusBarMessage(svnCommand(QStringList() << "info"));
}

void SubversionedFile::svnStatusActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit statusBarMessage(svnCommand(QStringList() << "status"));
}

void SubversionedFile::svnUpdateActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit statusBarMessage(svnCommand(QStringList() << "update"));
  emit reverted();
}

void SubversionedFile::svnAddActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit statusBarMessage(svnCommand(QStringList() << "add"));
}

void SubversionedFile::svnDeleteActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit statusBarMessage(svnCommand(QStringList() << "delete" << "--force"));
}

void SubversionedFile::svnLogActionTriggered()
{
  if (!validateVersionedFile())
    return;
  emit addSubWindow(new SVNLog(fileName));
}

QList<QAction *> SubversionedFile::getActions()
{
  QList<QAction *> actionsList;
  actionsList.append(svnDiffAction);
  actionsList.append(svnCommitAction);
  actionsList.append(svnRevertAction);
  actionsList.append(svnInfoAction);
  actionsList.append(svnStatusAction);
  actionsList.append(svnUpdateAction);
  actionsList.append(svnAddAction);
  actionsList.append(svnDeleteAction);
  actionsList.append(svnLogAction);
  return actionsList;
}

QString SubversionedFile::svnAdd(QString filePath)
{
  QProcess *process = new QProcess;
  process->start("svn", QStringList() << "add" << filePath);
  process->waitForFinished();
  QByteArray output = process->readAll();
  QString result;
  for (int counter = 0; counter < output.size(); ++counter)
    result += output.at(counter);
  return result;
}
