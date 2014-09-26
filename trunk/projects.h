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

#ifndef PROJECTS_H
#define PROJECTS_H

#include <QObject>
#include <QStringList>
#include <QSettings>

class QAction;
class QMenu;
class QActionGroup;
class QDialog;
class FileSelector;
class QListView;
class QPushButton;
class ProjectFindReplace;
class SubversionedFile;
class DMdiSubWindow;

class Projects : public QObject
{
  Q_OBJECT

public:
  Projects();
  QList<QAction *> getProjectFiles();
  QString name();
  void buildMenu(QMenu *menu);
  bool openedProject();
  QStringList *getFileSettings(const QString filename);
  void saveFileSettings(const QString filename, const QStringList *options);
  QMenu *projectFilesMenu;
  QString getProjectPath();
  QStringList getProjectFileList();
  QHash<QString, QString> getProjectFunctionListComplete();
  QStringList getProjectFunctionList();
  void retranslateUi();

private:
  QAction *newProjectAction;
  QAction *openProjectAction;
  QMenu *openRecentFilesMenu;
  QActionGroup *recentFilesActionGroup;
  QAction *clearRecentFilesAction;
  QDialog *dialog;
  FileSelector *projectFile;
  QListView *filesList;
  QPushButton *loadFilesPushButton;
  QAction *loadFilesAction;
  QStringList projectFiles;
  void fillFilesList();
  QSettings settings;
  QActionGroup *projectFilesActionGroup;
  QString fileName;
  QString workingFolder;
  QAction *closeProjectAction;
  QAction *findInProjectAction;
  ProjectFindReplace *projectFindReplace;
  void saveProjectFile(const QStringList lines);
  QStringList loadProjectFile();
  void enableMenuOption(bool enable = false);
  QMenu *subversionMenu;
//  QAction *subversionDiffRepository;
  SubversionedFile *subversionedFile;
  QAction *addFileToProjectAction;
  QAction *addExistingFileToProjectAction;

private slots:
  void openProjectActionSlot(QString file = QString());
  void openRecentFilesMenuAboutToShowSlot();
  void recentFilesActionGroupTriggered(QAction *action);
  void clearRecentFilesActionTriggered();
  void newProjectActionSlot();
  void loadFilesActionTriggered();
  void projectFilesActionGroupTriggered(QAction *action);
  void closeProjectActionTriggered();
  void findInProjectActionTriggered();
  void projectFilesSlot();
//  void subversionDiffRepositoryActionTriggered();
  void addFileToProjectActionTriggered();
  void addExistingFileToProjectActionTriggered();
  void openFileSlot(QString fileName = QString(), unsigned int line = 1);

public slots:
  void statusBarMessagePopupSlot(QString message);
  void statusBarMessageSlot(QString message);
  void addSubWindowSlot(DMdiSubWindow *window);

signals:
  void updateTitle();
  void statusBarMessage(QString message);
  void addSubWindow(DMdiSubWindow *window);
  void openFile(QString fileName = QString(), unsigned int line = 1);
  void statusBarMessagePopup(QString message);
};

#endif // PROJECTS_H
