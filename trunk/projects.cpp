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

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QListView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QInputDialog>
#include <QDomDocument>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "projects.h"
#include "dtitlelabel.h"
#include "fileselector.h"
#include "staticfunctions.h"
#include "projectfindreplace.h"
#include "subversionedfile.h"
#include "fileassociations.h"

#include "QDebug"

Projects::Projects()
{
  newProjectAction = new QAction(this);
  newProjectAction->setIcon(QIcon(":/images/svg/project-development.svg"));
  connect(newProjectAction, SIGNAL(triggered()), this, SLOT(newProjectActionSlot()));
  openProjectAction = new QAction(this);
  openProjectAction->setIcon(QIcon(":/images/svg/project-open-3.svg"));
  openProjectAction->setShortcut(QKeySequence::Open);
  connect(openProjectAction, SIGNAL(triggered()), this, SLOT(openProjectActionSlot()));
  openRecentFilesMenu = new QMenu();
  openRecentFilesMenu->setIcon(QIcon::fromTheme("document-open-recent", QIcon(":/images/svg/document-open-recent-3.svg")));
  connect(openRecentFilesMenu, SIGNAL(aboutToShow()), this, SLOT(openRecentFilesMenuAboutToShowSlot()));
  recentFilesActionGroup = new QActionGroup(this);
  connect(recentFilesActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(recentFilesActionGroupTriggered(QAction*)));
  clearRecentFilesAction = new QAction(this);
  clearRecentFilesAction->setIcon(QIcon::fromTheme("edit-clear", QIcon(":/images/svg/computerjanitor.svg")));
  connect(clearRecentFilesAction, SIGNAL(triggered()), this, SLOT(clearRecentFilesActionTriggered()));
  projectFilesActionGroup = new QActionGroup(this);
  connect(projectFilesActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(projectFilesActionGroupTriggered(QAction*)));
  closeProjectAction = new QAction(this);
  closeProjectAction->setIcon(QIcon(":/images/svg/project-development-close.svg"));
  connect(closeProjectAction, SIGNAL(triggered()), this, SLOT(closeProjectActionTriggered()));
  findInProjectAction = new QAction(this);
  findInProjectAction->setIcon(QIcon::fromTheme("edit-find", QIcon(":/images/svg/edit-find-7.svg")));
  connect(findInProjectAction, SIGNAL(triggered()), this, SLOT(findInProjectActionTriggered()));
  projectFilesMenu = new QMenu();
  projectFilesMenu->setIcon(QIcon::fromTheme("accessories-text-editor", QIcon(":/images/svg/accessories-text-editor-7.svg")));
  connect(projectFilesMenu, SIGNAL(aboutToShow()), this, SLOT(projectFilesSlot()));
  versionControlMenu = new QMenu;
  subversionMenu = new QMenu();
  versionControlMenu->addMenu(subversionMenu);
  subversionMenu->setIcon(QIcon(":/images/svg/subversion_logo.svg"));
//  subversionDiffRepository = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Diff repository"), this);
//  subversionDiffRepository->setToolTip(subversionDiffRepository->text());
//  connect(subversionDiffRepository, SIGNAL(triggered()), this, SLOT(subversionDiffRepositoryActionTriggered()));
//  subversionMenu->addAction(subversionDiffRepository);
  subversionedFile = new SubversionedFile(getProjectPath());
  connect(subversionedFile, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessageSlot(QString)));
  connect(subversionedFile, SIGNAL(statusBarMessagePopup(QString)), this, SLOT(statusBarMessagePopupSlot(QString)));
  connect(subversionedFile, SIGNAL(addSubWindow(DMdiSubWindow*)), this, SLOT(addSubWindowSlot(DMdiSubWindow*)));
  subversionMenu->addActions(subversionedFile->getActions());
  addFileToProjectAction = new QAction(this);
  addFileToProjectAction->setIcon(QIcon::fromTheme("list-add", QIcon(":/images/svg/list-add-5.svg")));
  connect(addFileToProjectAction, SIGNAL(triggered()), this, SLOT(addFileToProjectActionTriggered()));
  addExistingFileToProjectAction = new QAction(this);
  addExistingFileToProjectAction->setIcon(QIcon::fromTheme("list-add", QIcon(":/images/svg/list-add-5.svg")));
  connect(addExistingFileToProjectAction, SIGNAL(triggered()), this, SLOT(addExistingFileToProjectActionTriggered()));

  retranslateUi();
  enableMenuOption(false);
}

void Projects::clearRecentFilesActionTriggered()
{
  settings.remove("Projects/RecentFiles");
}

void Projects::recentFilesActionGroupTriggered(QAction *action)
{
  openProjectActionSlot(action->text());
}

void Projects::openRecentFilesMenuAboutToShowSlot()
{
  openRecentFilesMenu->clear();
  QStringList fileList(settings.value("Projects/RecentFiles", QStringList()).toStringList());
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(QIcon(":/images/svg/project-open-3.svg"), file));
  openRecentFilesMenu->addSeparator()->setText(tr("Clean"));
  openRecentFilesMenu->addAction(clearRecentFilesAction);
}

QList<QAction *> Projects::getProjectFiles()
{
  QStringList filesList;
  foreach (QAction *action, projectFilesActionGroup->actions())
    projectFilesActionGroup->removeAction(action);
  if (!fileName.isEmpty()) {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line(in.readLine());
      if (line.startsWith("File"))
        filesList.append(line.split("=").at(1));
    }
    file.close();
    filesList.sort();
    foreach (QString file, filesList) {
      QFileInfo fileInfo(file);
      projectFilesActionGroup->addAction(StaticFunctions::iconFromFileName(file), fileInfo.completeBaseName() + "." + fileInfo.suffix());
    }
  }
  return projectFilesActionGroup->actions();
}

QString Projects::name()
{
  if (fileName.isEmpty()) {
    return tr("No projet");
  } else {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
      line = in.readLine();
      if (line.startsWith("Name"))
        break;
    }
    file.close();
    return line.split("=").at(1);
  }
}

void Projects::buildMenu(QMenu *menu)
{
  menu->addAction(newProjectAction);
  menu->addAction(openProjectAction);
  menu->addAction(closeProjectAction);
  menu->addSeparator();
  menu->addMenu(openRecentFilesMenu);
  menu->addSeparator();
  menu->addAction(findInProjectAction);
  menu->addAction(addFileToProjectAction);
  menu->addAction(addExistingFileToProjectAction);
  menu->addSeparator();
  menu->addMenu(projectFilesMenu);
  menu->addSeparator();
  menu->addMenu(versionControlMenu);
}

bool Projects::openedProject()
{
  if (!fileName.isEmpty())
    return true;
  else
    return false;
}

QStringList *Projects::getFileSettings(const QString filename)
{
  QStringList *settingsList = new QStringList();
  if (!filename.isEmpty()) {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line(in.readLine());
      if (line.startsWith(filename.split("/").takeLast() + "-DockMarks"))
        foreach (QString item, line.split("=").at(1).split(","))
          settingsList->append(item);
    }
    file.close();
  }
  return settingsList;
}

void Projects::saveFileSettings(const QString filename, const QStringList *options)
{
  if (options->count() > 0) {
    QString baseName(filename.split("/").takeLast() + "-DockMarks");
    QStringList settingList;
    foreach (QString line, loadProjectFile())
      if (!line.isEmpty())
        if (!line.startsWith(baseName))
          settingList.append(line);
    settingList.append(baseName + "=" + options->join(","));
    saveProjectFile(settingList);
  }
}

QString Projects::getProjectPath()
{
  QString path(".");
  if (!fileName.isEmpty()) {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line(in.readLine());
      if (line.startsWith("Path"))
        path = line.split("=").at(1);
    }
  }
  return path;
}

QStringList Projects::getProjectFileList()
{
  QStringList list;
  if (!fileName.isEmpty()) {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
      QString line(in.readLine());
      if (line.startsWith("File"))
        list.append(line.split("=").at(1));
    }
    file.close();
    list.sort();
  }
  return list.filter(QRegExp("\\.(" + FileAssociations::FileAssociationsList() + ")$"));
}

QHash<QString, QString> Projects::getProjectFunctionListComplete()
{
//  switch(editorType) {
//  case EditorTypes::SQLQuery:
//    setWindowTitle(tr("SQL Query %1").arg(windowCount));
//    break;
//  case EditorTypes::PHP:
//    setWindowTitle(tr("PHP Script %1").arg(windowCount));
//    break;
//  case EditorTypes::CSS:
//    setWindowTitle(tr("CSS Script %1").arg(windowCount));
//    break;
//  case EditorTypes::HTML:
//    setWindowTitle(tr("HTML Script %1").arg(windowCount));
//    break;
//  case EditorTypes::JavaScript:
//    setWindowTitle(tr("JavaScript Script %1").arg(windowCount));
//    break;
//  case EditorTypes::NoEditor:
//    setWindowTitle(tr("Text File %1").arg(windowCount));
//    break;
//  case EditorTypes::Diff:
//  case EditorTypes::Commit:
//  case EditorTypes::SVNLog:
//    break;
//  // case EditorTypes::Diff:
//  // default: Q_ASSERT(false);
//  }
  QHash<QString, QString> data;
  unsigned int lineNumber = 0;
  QString param1;
  QString param3;
  QString param4;
  QString previousLine1;
  QString previousLine2;
  QString previousLine3;
  QString previousLine4;
  QString previousLine5;
  foreach (QString fileName, getProjectFileList()) {
    QFile file(fileName);
    if(file.open(QFile::ReadOnly | QFile::Text)) {
      QTextStream in(&file);
      in.setCodec("UTF-8");
      while(!in.atEnd()) {
        ++lineNumber;
        QString line = in.readLine();
        previousLine5 = previousLine4;
        previousLine4 = previousLine3;
        previousLine3 = previousLine2;
        previousLine2 = previousLine1;
        previousLine1 = line;
        if (line.contains(QRegExp("^function.*\\(.*\\) \\{$", Qt::CaseInsensitive))) {
          if (previousLine5.startsWith(" * @summary:"))
            param4 = previousLine5.mid(12);
          if (previousLine4.startsWith(" * @param:"))
            param3 = previousLine4.mid(10);
          if (previousLine3.startsWith(" * @return:"))
            param1 = previousLine3.mid(11);
          data.insert(line.mid(9, line.indexOf("(") - 9), QString("%1 <u>%2</u>(<b>%3</b>) <br />%4").arg(param1.trimmed()).arg(line.mid(9, line.indexOf("(") - 9)).arg(param3.trimmed()).arg(param4.trimmed()));
        }
        param1 = QString();
        param3 = QString();
        param4 = QString();
      }
      file.close();
      lineNumber = 0;
    }
  }
  return data;
}

QStringList Projects::getProjectFunctionList()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(getProjectFunctionListComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}

void Projects::retranslateUi()
{
  newProjectAction->setText(tr("New Project..."));
  newProjectAction->setToolTip(newProjectAction->text());
  openProjectAction->setText(tr("Open Project..."));
  openProjectAction->setToolTip(openProjectAction->text());
  openRecentFilesMenu->setTitle(tr("Recent files"));
  openRecentFilesMenu->setToolTip(openRecentFilesMenu->title());
  clearRecentFilesAction->setText(tr("Clear recent files"));
  clearRecentFilesAction->setToolTip(clearRecentFilesAction->text());
  closeProjectAction->setText(tr("Close current project"));
  closeProjectAction->setToolTip(closeProjectAction->text());
  findInProjectAction->setText(tr("Find in project"));
  findInProjectAction->setToolTip(findInProjectAction->text());
  projectFilesMenu->setTitle(tr("Project files"));
  subversionMenu->setTitle(tr("Subversion"));
  addFileToProjectAction->setText(tr("Add new file to project"));
  addFileToProjectAction->setToolTip(addFileToProjectAction->text());
  addExistingFileToProjectAction->setText(tr("Add existing file to project"));
  addExistingFileToProjectAction->setToolTip(addExistingFileToProjectAction->text());
  versionControlMenu->setTitle(tr("Version &control"));
}

void Projects::openProjectActionSlot(QString file)
{
  QFileInfo fileInfo(file);
  if (file.isEmpty() || !fileInfo.exists()) {
    QFileDialog fileDialog;
    fileDialog.setDirectory(QDir::home());
    fileName = fileDialog.getOpenFileName(0, tr("Open a project"), QDir::home().absolutePath(), tr("Project files (*.pro)"));
  } else {
    fileName = file;
  }
  fileInfo.setFile(fileName);
  workingFolder = fileInfo.absoluteDir().absolutePath();
  QStringList fileList;
  fileList = settings.value("Projects/RecentFiles", QStringList()).toStringList();
  if (fileList.indexOf(fileName) == -1)
    fileList.append(fileName);
  settings.setValue("Projects/RecentFiles", fileList);
  emit updateTitle();
  enableMenuOption(true);
  subversionedFile->fileName = getProjectPath();

//  QFile files(fileName + ".xml");
//  if(files.open(QIODevice::WriteOnly | QIODevice::Text)) {
//    QXmlStreamWriter xmlStreamWriter(&files);
//    xmlStreamWriter.setAutoFormatting(true);
//    xmlStreamWriter.writeStartDocument();

//    xmlStreamWriter.writeStartElement("Project");

//    xmlStreamWriter.writeStartElement("Information");
//    xmlStreamWriter.writeTextElement("Name", name());
//    xmlStreamWriter.writeTextElement("Path", getProjectPath());
//    xmlStreamWriter.writeEndElement(); // Information

//    xmlStreamWriter.writeStartElement("Files");
//    foreach (QString fileName, getProjectFileList())
//      xmlStreamWriter.writeTextElement("File", fileName);
//    xmlStreamWriter.writeEndElement(); // Files


//    xmlStreamWriter.writeStartElement("DockMarks");
//    foreach (QString projectFile, getProjectFileList()) {
//      QString dockMarks(getFileSettings(projectFile)->join(","));
//      if (!dockMarks.isEmpty()) {
//        xmlStreamWriter.writeStartElement("DockMark");
//        xmlStreamWriter.writeAttribute("FileName", projectFile);
//        foreach (QString mark, dockMarks.split(","))
//          xmlStreamWriter.writeTextElement("Value", mark);
//        xmlStreamWriter.writeEndElement(); // Files
//      }
//    }
//    xmlStreamWriter.writeEndElement(); // DockMarks

//    xmlStreamWriter.writeEndElement(); // Project
//    xmlStreamWriter.writeEndDocument();
//    files.close();
//  } else {
//    emit statusBarMessage(tr("Cannot write file %1:\n%2.").arg(fileName).arg(files.errorString()));
//  }

//  QFile files(fileName + ".xml");
//  if(files.open(QIODevice::ReadOnly | QIODevice::Text)) {
//    QXmlStreamReader xmlStreamReader(&files);
//    while (!xmlStreamReader.atEnd()) {
//      xmlStreamReader.readNext();
//      if (xmlStreamReader.error())
//        emit statusBarMessage(tr("Cannot read file %1:\n%2.").arg(fileName).arg(xmlStreamReader.errorString()));
//      else
//        if (!xmlStreamReader.text().toString().trimmed().isEmpty())
//          qDebug() << xmlStreamReader.name() << xmlStreamReader.text().toString().trimmed();
//    }
//    files.close();
//  } else {
//    emit statusBarMessage(tr("Cannot read file %1:\n%2.").arg(fileName).arg(files.errorString()));
//  }
}

void Projects::newProjectActionSlot()
{
  dialog = new QDialog;
  dialog->setWindowTitle(tr("New project..."));
  dialog->setObjectName(dialog->windowTitle());
  dialog->setWindowIcon(QIcon(":/images/svg/server-database.svg"));
  dialog->resize(600, 600);

  QLineEdit *nameLineEdit = new QLineEdit;

  //Project info
  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("&Name:"), nameLineEdit);
  projectFile = new FileSelector(FileSelectorContexts::ProjectFile, tr("Destination:"), true);
  formLayout->addRow(projectFile);
  QGroupBox *projectGroupBox = new QGroupBox(tr("Poject information"));
  projectGroupBox->setLayout(formLayout);

  //Project files
  loadFilesPushButton = new QPushButton(QIcon(":/images/svg/server-database.svg"), tr("Load files"));
  loadFilesAction = new QAction("Load files", this);
  connect(loadFilesPushButton, SIGNAL(clicked()), this, SLOT(loadFilesActionTriggered()));
  if (!projectFile->getFileName().isEmpty()) {
    projectFiles.clear();
    loadProjectFile();
    fillFilesList();
  }
  filesList = new QListView;
  QVBoxLayout *projectFilesLayout = new QVBoxLayout;
  projectFilesLayout->addWidget(loadFilesPushButton);
  projectFilesLayout->addWidget(filesList);
  QGroupBox *projectFilesGroupBox = new QGroupBox(tr("Poject files"));
  projectFilesGroupBox->setLayout(projectFilesLayout);

  QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
  connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

  QVBoxLayout *verticalLayout = new QVBoxLayout;
  verticalLayout->addWidget(new DTitleLabel(tr("Create new Project")));
  verticalLayout->addWidget(projectGroupBox);
  verticalLayout->addWidget(projectFilesGroupBox);
  verticalLayout->addWidget(buttonBox);
  dialog->setLayout(verticalLayout);
  if (dialog->exec() == QDialog::Accepted) {
    QStringList lines;
    lines.append("Name=" + nameLineEdit->text());
    for (int row = 0; row < projectFiles.count(); row++)
      lines.append("File=" + projectFiles.at(row));
    fileName = projectFile->getFileName();
    lines.append("Path=" + projectFile->fileDir().path());
    saveProjectFile(lines);
    emit statusBarMessage(tr("Info saved."));
    openProjectActionSlot(projectFile->getFileName());
  }
  enableMenuOption(true);
}

void Projects::fillFilesList()
{
  if (projectFiles.empty())
    return;

  QStandardItemModel *model = new QStandardItemModel(projectFiles.count(), 1);
  for (int row = 0; row < projectFiles.count(); row++)
    model->setItem(row, 0, new QStandardItem(StaticFunctions::iconFromFileName(projectFiles.at(row)), projectFiles.at(row)));
  filesList->setModel(model);
}

void Projects::saveProjectFile(const QStringList lines)
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
  QTextStream out(&file);
  foreach (QString line, lines)
    out << line << "\n";
  file.close();
}

QStringList Projects::loadProjectFile()
{
  QStringList lineList;
  QFile file(fileName);
  projectFiles.clear();
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return QStringList();
  while (!file.atEnd()) {
    QByteArray line = file.readLine();
    if(line.startsWith("File"))
      projectFiles.append(QString(line).split("=").at(1).trimmed());
    lineList.append(line.trimmed());
  }
  return lineList;
}

void Projects::enableMenuOption(bool enable)
{
  closeProjectAction->setEnabled(enable);
  findInProjectAction->setEnabled(enable);
  projectFilesMenu->setEnabled(enable);
  subversionMenu->setEnabled(enable);
  versionControlMenu->setEnabled(enable);
  addFileToProjectAction->setEnabled(enable);
  addExistingFileToProjectAction->setEnabled(enable);
}

void Projects::loadFilesActionTriggered()
{
  projectFiles = QFileDialog::getOpenFileNames(0, tr("Select files"), projectFile->fileDir().absolutePath());
  projectFiles.sort();
  fillFilesList();
}

void Projects::projectFilesActionGroupTriggered(QAction *action)
{
  emit openFile(workingFolder + "/" + action->text());
}

void Projects::closeProjectActionTriggered()
{
  fileName.clear();
  emit updateTitle();
  enableMenuOption(false);
}

void Projects::findInProjectActionTriggered()
{
  projectFindReplace = new ProjectFindReplace(this);
  connect(projectFindReplace, SIGNAL(openFile(QString,uint)), this, SLOT(openFileSlot(QString,uint)));
  emit addSubWindow(projectFindReplace);
}

void Projects::projectFilesSlot()
{
  projectFilesMenu->clear();
  projectFilesMenu->addActions(getProjectFiles());
}

void Projects::addFileToProjectActionTriggered()
{
  QString fileName = getProjectPath() + "/" + QInputDialog::getText(0, tr("File name"), tr("File name")).trimmed();
  saveProjectFile(loadProjectFile() << "File=" + fileName);
  emit statusBarMessage(tr("Info saved."));
  QFile file(fileName);
  if (!file.open(QFile::ReadWrite | QFile::Text))
    emit statusBarMessage(tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
  file.close();
  emit statusBarMessage(SubversionedFile::svnAdd(fileName));
}

void Projects::addExistingFileToProjectActionTriggered()
{
  saveProjectFile(loadProjectFile() << "File=" + QFileDialog::getOpenFileName(0, tr("Select a file"), getProjectPath()).trimmed());
  emit statusBarMessage(tr("Info saved."));
}

void Projects::openFileSlot(QString fileName, unsigned int line)
{
  emit openFile(fileName, line);
}

void Projects::statusBarMessageSlot(QString message)
{
  emit statusBarMessage(message);
}

void Projects::statusBarMessagePopupSlot(QString message)
{
  emit statusBarMessagePopup(message);
}

void Projects::addSubWindowSlot(DMdiSubWindow *window)
{
  emit addSubWindow(window);
}

//void Projects::subversionDiffRepositoryActionTriggered()
//{
//  QString path;
//  QFile file(fileName);
//  file.open(QIODevice::ReadOnly | QIODevice::Text);
//  QTextStream in(&file);
//  while (!in.atEnd()) {
//    QString line(in.readLine());
//    if (line.startsWith("Path"))
//      path = line.split("=").at(1);
//  }
//  addSubWindow(new DiffFile(path));
//}
