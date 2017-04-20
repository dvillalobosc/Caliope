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

#ifndef FINDREPLACE_H
#define FINDREPLACE_H

#include <QToolBar>
#include <QTextDocument>
#include <QSettings>

class QLineEdit;
class QAction;
class TextEditor;
class QCompleter;

class FindReplace : public QToolBar
{
  Q_OBJECT

public:
  FindReplace(TextEditor *document);

private slots:
  void closeToolBar();
  bool find(QString text = QString(), QTextDocument::FindFlags direction = 0);
  void findNext();
  void findPrev();
  void replaceActionTriggerd();
  void replaceAllActionTriggerd();
  void highlightAllActionTriggerd();

private:
  TextEditor *plainTextEdit;
  QLineEdit *findLineEdit;
  QLineEdit *replaceLineEdit;
  QAction *caseSensitiveAction;
  QAction *entireWordAction;
  QAction *regExpAction;
  QCompleter *completer;
  QSettings settings;
  void SaveSearchedStrings();

protected:
  void showEvent(QShowEvent *event);
  void keyPressEvent(QKeyEvent *event);
  bool eventFilter(QObject *obj, QEvent *event);
};

#endif // FINDREPLACE_H
