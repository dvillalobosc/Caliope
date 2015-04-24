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

#ifndef BASETEXTEDITOR_H
#define BASETEXTEDITOR_H

#include <QPlainTextEdit>
#include <QSettings>

#include "editortypes.h"

class GeneralHighlighter;

class BaseTextEditor : public QPlainTextEdit
{
  Q_OBJECT

public:
  BaseTextEditor(EditorTypes::EditorType type);
  void lineNumberAreaPaintEvent(QPaintEvent *event);
  int lineNumberAreaWidth();
  QWidget *lineNumberArea;
  bool showNumberArea;
  void rehighlight(const QString &exp);
  QAction *indentAction;
  QAction *unidentAction;
  QStringList *pointList;
  void gotoLine(unsigned int lineNumber = 0);
  void retranslateUi();
  QAction *insertLicenceTamplateAction;
  QList<unsigned int> *foldRowList;
  QAction *visualizeSpacesAction;
  QStringList wordList();

protected:
  void resizeEvent(QResizeEvent *event);
  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void paintEvent(QPaintEvent *event);

private slots:
  void updateLineNumberAreaWidth();
  void updateLineNumberArea(const QRect &rect, int dy);
  void indentActionTriggered();
  void unidentActionTriggered();
  void visualizeSpacesActionTriggered(bool toggled);

public slots:
  void highlightCurrentLine();
  void showHideLineNumbers(bool show);
  void dockmarkCurrentLine();
  void insertLicenceTemplateSlot();
  void setPlainText(const QString &text, bool concatenate = false);

private:
  GeneralHighlighter *generalHighlighter;
  bool completedAndSelected;
  bool handledCompletedAndSelected(QKeyEvent *event);
  void smartTextInsertion(QString leftKey, QString rightKey = QString());
  QSettings settings;
  void smartTextIndentation();
  bool homeKeyHitedTwice;
  void createActions();
  void indentOrUnindent(bool doIndent);
  int lineIndentPosition(const QString &text) const;
  int firstNonSpace(const QString &text) const;
  QString indentationString(const QString &text) const;
  int indentationColumn(const QString &text) const;
  int columnAt(const QString &text, int position) const;
  int indentedColumn(int column, bool doIndent) const;
  int spacesLeftFromPosition(const QString &text, int position) const;
  QString indentationString(int startColumn, int targetColumn, const QTextBlock &block) const;
  bool guessSpacesForTabs(const QTextBlock &_block) const;
  void drawFoldMarks(const QTextBlock &block, QPainter &painter, const int &top);
  EditorTypes::EditorType editorType;
  bool folded;
  QTextBlock foldedBlockAt(const QPoint &point);

signals:
  void escKeyPressed();
  void performPeriodCompletion(QString completionPrefix);
};

//class EditorLayout : public QPlainTextDocumentLayout
//{
//    Q_OBJECT

//public:
//  EditorLayout(QTextDocument *document) : QPlainTextDocumentLayout(document) {
//  }

//  void emitDocumentSizeChanged() { emit documentSizeChanged(documentSize());
//  }
//};

class LineNumberArea : public QWidget
{
public:
  LineNumberArea(BaseTextEditor *editor);

protected:
  void paintEvent(QPaintEvent *event);
  void mouseDoubleClickEvent(QMouseEvent *event);

private:
  BaseTextEditor *codeEditor;
};

#endif // BASETEXTEDITOR_H
