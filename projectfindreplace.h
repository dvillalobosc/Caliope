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

#ifndef PROJECTFINDREPLACE_H
#define PROJECTFINDREPLACE_H

#include "dmdisubwindow.h"
#include "projects.h"

class QGroupBox;
class QLineEdit;
class QFormLayout;
class QTreeWidget;
class QTreeWidgetItem;
class QCheckBox;
class QCompleter;

class ProjectFindReplace : public DMdiSubWindow
{
  Q_OBJECT

public:
  ProjectFindReplace(Projects *project);

private:
  Projects *project;
  QGroupBox *mainGroupBox;
  QLineEdit *lineEditTextToFind;
  QFormLayout *formLayout;
  QTreeWidget *findsListWidget;
  QPushButton *pushButtonFind;
  QCheckBox *checkBoxCaseSensitive;
  QCheckBox *checkBoxWholeWords;
  QCheckBox *checkBoxRegularExp;
  QLineEdit *lineEditTextToReplace;
  QSettings settings;
  QCompleter *completer;
  QPushButton *pushButtonReplace;

signals:
  void statusBarMessage(QString message);
  void openFile(QString file, unsigned int line);

protected:
  void retranslateUi();
  bool eventFilter(QObject *obj, QEvent *event);

private slots:
  void findSlot();
  void itemDoubleClickedSlot(QTreeWidgetItem *item, int column);
  void replaceSlot();
  void validateInputs();
};

#endif // PROJECTFINDREPLACE_H
