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

#ifndef SUBVERSIONEDFILE_H
#define SUBVERSIONEDFILE_H

#include <QWidget>

//#include "texteditor.h"

class QAction;
class QProcess;
class DMdiSubWindow;

class SubversionedFile : public QWidget
{
  Q_OBJECT

public:
  SubversionedFile(QString file);
  QList<QAction *> getActions();
  QString fileName;

private:
  bool validateVersionedFile();
  QString svnCommand(QStringList commands);

  QAction *svnDiffAction;
  QAction *svnCommitAction;
  QAction *svnRevertAction;
  QAction *svnInfoAction;
  QAction *svnStatusAction;
  QAction *svnUpdateAction;
  QAction *svnAddAction;
  QAction *svnDeleteAction;
  QAction *svnLogAction;

private slots:
  void svnDiffActionTriggered();
  void svnCommitActionTriggered();
  void svnRevertActionTriggered();
  void svnInfoActionTriggered();
  void svnStatusActionTriggered();
  void svnUpdateActionTriggered();
  void svnAddActionTriggered();
  void svnDeleteActionTriggered();
  void svnLogActionTriggered();

signals:
  void reverted();
  void statusBarMessage(QString message);
  void statusBarMessagePopup(QString message);
  void addSubWindow(DMdiSubWindow *dmdiSubWindow);
};

#endif // SUBVERSIONEDFILE_H
