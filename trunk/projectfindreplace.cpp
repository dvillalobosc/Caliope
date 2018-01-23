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

#include <QErrorMessage>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QTreeWidget>
#include <QPushButton>
#include <QFile>
#include <QApplication>
#include <QCheckBox>
#include <QCompleter>
#include <QMessageBox>

#include "projectfindreplace.h"
#include "fileselector.h"
#include "staticfunctions.h"

#include "QDebug"

ProjectFindReplace::ProjectFindReplace(Projects *project)
{
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));
  this->project = project;
  if (this->project->name().isEmpty()) {
    emit statusBarMessage(tr("Select a Project first."));
    QErrorMessage *errorMessage = new QErrorMessage;
    errorMessage->setWindowTitle(tr("Project Error"));
    errorMessage->showMessage(tr("Select a Project first."));
    errorMessage->exec();
  }
  completer = new QCompleter(settings.value("Projects/SearchedValues", QStringList()).toStringList());
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setFilterMode(Qt::MatchContains);

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  lineEditTextToFind = new QLineEdit;
  connect(lineEditTextToFind, SIGNAL(returnPressed()), this, SLOT(findSlot()));
  connect(lineEditTextToFind, SIGNAL(textChanged(QString)), this, SLOT(validateInputs()));
  lineEditTextToFind->installEventFilter(this);
  lineEditTextToFind->setCompleter(completer);
  lineEditTextToReplace = new QLineEdit;
  connect(lineEditTextToReplace, SIGNAL(returnPressed()), this, SLOT(replaceSlot()));
  connect(lineEditTextToReplace, SIGNAL(textChanged(QString)), this, SLOT(validateInputs()));

  formLayout = new QFormLayout;
  formLayout->addRow(" ", lineEditTextToFind);
  formLayout->addRow(" ", lineEditTextToReplace);

  mainGroupBox = new QGroupBox;
  mainVLayout->addWidget(mainGroupBox);
  mainGroupBox->setLayout(formLayout);

  checkBoxCaseSensitive = new QCheckBox;
  checkBoxWholeWords = new QCheckBox;
  checkBoxRegularExp = new QCheckBox;

  QHBoxLayout *groupBoxHLayout1 = new QHBoxLayout;
  groupBoxHLayout1->addWidget(checkBoxCaseSensitive);
  groupBoxHLayout1->addWidget(checkBoxWholeWords);
  groupBoxHLayout1->addWidget(checkBoxRegularExp);
  formLayout->addRow(groupBoxHLayout1);
  groupBoxHLayout1->addStretch(1);

  QHBoxLayout *groupBoxHLayout2 = new QHBoxLayout;
  pushButtonFind = new QPushButton;
  pushButtonFind->setEnabled(false);
  pushButtonFind->setIcon(QIcon::fromTheme("edit-find", QIcon(":/images/svg/edit-find-7.svg")));
  connect(pushButtonFind, SIGNAL(clicked()), this, SLOT(findSlot()));
  groupBoxHLayout2->addWidget(pushButtonFind);
  pushButtonReplace = new QPushButton;
  pushButtonReplace->setEnabled(false);
  pushButtonReplace->setIcon(QIcon::fromTheme("edit-find-replace", QIcon(":/images/svg/edit-find-replace.svg")));
  connect(pushButtonReplace, SIGNAL(clicked()), this, SLOT(replaceSlot()));
  groupBoxHLayout2->addWidget(pushButtonReplace);
  formLayout->addRow(groupBoxHLayout2);
  groupBoxHLayout2->addStretch(1);

  findsListWidget = new QTreeWidget;
  connect(findsListWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(itemDoubleClickedSlot(QTreeWidgetItem*,int)));
  mainVLayout->addWidget(findsListWidget);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
}

void ProjectFindReplace::retranslateUi()
{
  setWindowTitle(tr("Find & Replace"));
  setObjectName(windowTitle());
  mainGroupBox->setTitle(windowTitle());
  QLabel *label = qobject_cast<QLabel *>(formLayout->labelForField(lineEditTextToFind));
  label->setText(tr("Text to find:"));
  label->setToolTip(label->text());
  label = qobject_cast<QLabel *>(formLayout->labelForField(lineEditTextToReplace));
  label->setText(tr("Text to replace:"));
  label->setToolTip(label->text());
  pushButtonFind->setText(tr("Find"));
  pushButtonFind->setToolTip(pushButtonFind->text());
  checkBoxCaseSensitive->setText(tr("Case sensitive"));
  checkBoxCaseSensitive->setToolTip(checkBoxCaseSensitive->text());
  checkBoxWholeWords->setText(tr("Whole words"));
  checkBoxWholeWords->setToolTip(checkBoxWholeWords->text());
  checkBoxRegularExp->setText(tr("Regular expression"));
  checkBoxRegularExp->setToolTip(checkBoxRegularExp->text());
  findsListWidget->setHeaderLabel(tr("Results"));
  pushButtonReplace->setText(tr("Replace"));
  pushButtonReplace->setToolTip(pushButtonReplace->text());
}

bool ProjectFindReplace::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseButtonDblClick)
    completer->complete();
  return QObject::eventFilter(obj, event);
}

void ProjectFindReplace::findSlot()
{
  unsigned int lineNumber = 0;
  findsListWidget->clear();
  bool foundInCurrentFile = false;
  QList<QTreeWidgetItem *> items;
  QTreeWidgetItem *item;
  QTreeWidgetItem *itemChild;
  bool foundInCurrentLine = false;
  QApplication::setOverrideCursor(Qt::WaitCursor);
  foreach (QString fileName, project->getProjectFileList()) {
    QFile file(fileName);
    if(file.open(QFile::ReadOnly | QFile::Text)) {
      QTextStream in(&file);
      in.setCodec("UTF-8");
      item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(fileName));
      while(!in.atEnd()) {
        ++lineNumber;
        QString line = in.readLine();
        if (checkBoxRegularExp->isChecked()) {
          if (line.contains(QRegExp(lineEditTextToFind->text(), checkBoxCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive)))
            foundInCurrentLine = true;
        } else if (checkBoxWholeWords->isChecked()) {
          if (line.contains(QRegExp("\\b" + lineEditTextToFind->text() + "\\b", checkBoxCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive)))
            foundInCurrentLine = true;
        } else {
          if (line.contains(lineEditTextToFind->text(), checkBoxCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive))
            foundInCurrentLine = true;
        }
        if (foundInCurrentLine) {
          foundInCurrentFile = true;
          itemChild = new QTreeWidgetItem(item, QStringList(QString("%1:%2").arg(lineNumber).arg(line)));
          itemChild->setIcon(0, QIcon(StaticFunctions::iconFromFileName(fileName)));
        }
        foundInCurrentLine = false;
      }
      if (foundInCurrentFile)
        items.append(item);
      foundInCurrentFile = false;
    }
    file.close();
    lineNumber = 0;
  }
  findsListWidget->insertTopLevelItems(0, items);
  QStringList searchedValues(settings.value("Projects/SearchedValues", QStringList()).toStringList());
  searchedValues.append(lineEditTextToFind->text());
  searchedValues.removeDuplicates();
  settings.setValue("Projects/SearchedValues", searchedValues);
  completer = new QCompleter(settings.value("Projects/SearchedValues", QStringList()).toStringList());
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  lineEditTextToFind->setCompleter(completer);
  QApplication::restoreOverrideCursor();
}

void ProjectFindReplace::replaceSlot()
{
  QMessageBox msgBox;
  msgBox.setText(windowTitle());
  msgBox.setInformativeText(tr("Do you really want to apply the changes?"));
  msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
  msgBox.setDefaultButton(QMessageBox::Discard);
  if (msgBox.exec() == QMessageBox::Save) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    foreach (QString fileName, project->getProjectFileList()) {
      QFile file(fileName);
      if(file.open(QFile::ReadWrite | QFile::Text)) {
        QString fileContents(file.readAll());
        file.seek(0);
        if (checkBoxRegularExp->isChecked()) {
          file.write(fileContents.replace(QRegExp(lineEditTextToFind->text(), checkBoxCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive), lineEditTextToReplace->text()).toUtf8());
        } else if (checkBoxWholeWords->isChecked()) {
          file.write(fileContents.replace(QRegExp("\\b" + lineEditTextToFind->text() + "\\b", checkBoxCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive), lineEditTextToReplace->text()).toUtf8());
        } else {
          file.write(fileContents.replace(lineEditTextToFind->text(), lineEditTextToReplace->text(), checkBoxCaseSensitive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive).toUtf8());
        }
        file.close();
      }
    }
    QApplication::restoreOverrideCursor();
  }
}

void ProjectFindReplace::validateInputs()
{
  pushButtonFind->setEnabled(!lineEditTextToFind->text().isEmpty());
  pushButtonReplace->setEnabled(pushButtonFind->isEnabled());
}

void ProjectFindReplace::itemDoubleClickedSlot(QTreeWidgetItem *item, int column)
{
  if (!item->parent())
    return;
  emit openFile(item->parent()->text(column), item->text(0).split(":").at(0).toUInt() - 1);
}
