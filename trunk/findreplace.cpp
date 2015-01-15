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

#include <QLineEdit>
#include <QTextDocumentFragment>
#include <QAction>
#include <QPlainTextEdit>
#include <QToolTip>
#include <QCompleter>

#include "findreplace.h"
#include "basetexteditor.h"
#include "texteditor.h"

#include "QDebug"

FindReplace::FindReplace(TextEditor *document)
{
  hide();
  plainTextEdit = document;
  connect(document->textEditor, SIGNAL(escKeyPressed()), this, SLOT(closeToolBar()));
  QAction *viewAction = toggleViewAction();
  viewAction->setIcon(QIcon::fromTheme("edit-find", QIcon(":/images/svg/edit-find-7.svg")));
  viewAction->setShortcut(QKeySequence::Find);
  setWindowIcon(QIcon::fromTheme("edit-find", QIcon(":/images/svg/edit-find-7.svg")));
  setWindowTitle(tr("Find/Replace"));
  setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
  setIconSize(QSize(24, 24));
  findLineEdit = new QLineEdit;
  findLineEdit->installEventFilter(this);
  connect(findLineEdit, SIGNAL(textChanged(QString)), this, SLOT(find(QString)));
  addWidget(findLineEdit);
  completer = new QCompleter(settings.value("General/SearchedValues", QStringList()).toStringList());
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setFilterMode(Qt::MatchContains);
  findLineEdit->setCompleter(completer);
  QAction *findNextAction = new QAction(QIcon::fromTheme("go-next", QIcon(":/images/svg/go-next-7.svg")), tr("Find next"), this);
  findNextAction->setToolTip(findNextAction->text());
  findNextAction->setShortcut(QKeySequence::FindNext);
  connect(findNextAction, SIGNAL(triggered()), this, SLOT(findNext()));
  addAction(findNextAction);
  QAction *findPrevAction = new QAction(QIcon::fromTheme("go-previous", QIcon(":/images/svg/go-previous-7.svg")), tr("Find previous"), this);
  findPrevAction->setToolTip(findPrevAction->text());
  findPrevAction->setShortcut(QKeySequence::FindPrevious);
  connect(findPrevAction, SIGNAL(triggered()), this, SLOT(findPrev()));
  addAction(findPrevAction);
  replaceLineEdit = new QLineEdit;
  addWidget(replaceLineEdit);
  QAction *findReplaceAction = new QAction(QIcon::fromTheme("edit-find-replace", QIcon(":/images/svg/edit-find-replace.svg")), tr("Replace"), this);
  findReplaceAction->setToolTip(findReplaceAction->text());
  findReplaceAction->setShortcut(QKeySequence::Replace);
  connect(findReplaceAction, SIGNAL(triggered()), this, SLOT(replaceActionTriggerd()));
  addAction(findReplaceAction);
  QAction *replaceAllAction = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Replace all"), this);
  replaceAllAction->setToolTip(replaceAllAction->text());
  connect(replaceAllAction, SIGNAL(triggered()), this, SLOT(replaceAllActionTriggerd()));
  addAction(replaceAllAction);
  caseSensitiveAction = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Case sensitive"), this);
  caseSensitiveAction->setToolTip(caseSensitiveAction->text());
  caseSensitiveAction->setCheckable(true);
  addAction(caseSensitiveAction);
  entireWordAction = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Hole word"), this);
  entireWordAction->setToolTip(entireWordAction->text());
  entireWordAction->setCheckable(true);
  addAction(entireWordAction);
  regExpAction = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Regular Expression"), this);
  regExpAction->setToolTip(regExpAction->text());
  regExpAction->setCheckable(true);
  addAction(regExpAction);
  QAction *highlightAllAction = new QAction(QIcon(":/images/svg/server-database.svg"), tr("Highlight all"), this);
  highlightAllAction->setToolTip(highlightAllAction->text());
  connect(highlightAllAction, SIGNAL(triggered()), this, SLOT(highlightAllActionTriggerd()));
  addAction(highlightAllAction);
}

void FindReplace::closeToolBar()
{
  findLineEdit->setText("");
  highlightAllActionTriggerd();
  hide();
}

bool FindReplace::find(QString text, QTextDocument::FindFlags direction)
{
  if (text.isEmpty())
    text = findLineEdit->text();
  QTextDocument::FindFlags flags;
  if (direction)
    flags |= QTextDocument::FindBackward;
  if (caseSensitiveAction->isChecked())
    flags |= QTextDocument::FindCaseSensitively;
  if (entireWordAction->isChecked())
    flags |= QTextDocument::FindWholeWords;
  if (regExpAction->isChecked()) {
    QTextCursor cursor = plainTextEdit->textEditor->document()->find(QRegExp(text, Qt::CaseInsensitive), plainTextEdit->textEditor->textCursor(), flags);
    plainTextEdit->textEditor->setTextCursor(cursor);
    if (cursor.hasSelection())
      return true;
    else
      return false;
  } else {
    if (plainTextEdit->textEditor->find(text, flags)) {
      return true;
    } else {
      return false;
    }
  }
}

void FindReplace::findNext()
{
  if (!find(findLineEdit->text()))
    QToolTip::showText(findLineEdit->mapToGlobal(QPoint(0,0)), tr("Reached the end of the document."), findLineEdit);
  SaveSearchedStrings();
}

void FindReplace::findPrev()
{
  if (!find(findLineEdit->text(), QTextDocument::FindBackward))
    QToolTip::showText(findLineEdit->mapToGlobal(QPoint(0,0)), tr("Reached the begining of the document."), findLineEdit);
  SaveSearchedStrings();
}

void FindReplace::showEvent(QShowEvent *event)
{
  QWidget::showEvent(event);
  findLineEdit->setFocus(Qt::OtherFocusReason);
  if (plainTextEdit->textEditor->textCursor().hasSelection())
    findLineEdit->setText(plainTextEdit->textEditor->textCursor().selection().toPlainText());
  findLineEdit->selectAll();
}

void FindReplace::keyPressEvent(QKeyEvent *event)
{
  QToolBar::keyPressEvent(event);
  switch (event->key()) {
  case Qt::Key_Escape:
    closeToolBar();
    break;
  }
}

bool FindReplace::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseButtonDblClick)
    completer->complete();
  return QObject::eventFilter(obj, event);
}

void FindReplace::replaceActionTriggerd()
{
  QTextCursor cursor = plainTextEdit->textEditor->textCursor();
  if (cursor.hasSelection())
    cursor.insertText(replaceLineEdit->text());
  findNext();
}

void FindReplace::replaceAllActionTriggerd()
{
  plainTextEdit->textEditor->gotoLine();
  while (find()) {
    QTextCursor cursor = plainTextEdit->textEditor->textCursor();
    if (cursor.hasSelection())
      cursor.insertText(replaceLineEdit->text());
  }
}

void FindReplace::highlightAllActionTriggerd()
{
  plainTextEdit->textEditor->rehighlight(findLineEdit->text());
}

void FindReplace::SaveSearchedStrings()
{
  QStringList searchedValues(settings.value("General/SearchedValues", QStringList()).toStringList());
  searchedValues.append(findLineEdit->text());
  searchedValues.removeDuplicates();
  settings.setValue("General/SearchedValues", searchedValues);
  completer = new QCompleter(settings.value("General/SearchedValues", QStringList()).toStringList());
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  findLineEdit->setCompleter(completer);
}
