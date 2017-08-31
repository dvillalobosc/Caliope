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

#include <QPainter>
#include <QTextBlock>
#include <QSettings>
#include <QAction>

#include "basetexteditor.h"
#include "generalhighlighter.h"
#include "staticfunctions.h"

#include <QDebug>

BaseTextEditor::BaseTextEditor(EditorTypes::EditorType type)
{
  folded = false;
  generalHighlighter = new GeneralHighlighter(document(), type);
  editorType = type;
  showNumberArea = true;
  homeKeyHitedTwice = true;
  foldRowList = new QList<unsigned int>;
  lineNumberArea = new LineNumberArea(this);
  lineNumberArea->setGeometry(0, 0, 0, 0);
  setFont(StaticFunctions::fixedWidthFont());
  connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth()));
  connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
  connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
  updateLineNumberAreaWidth();
  if (settings.value("TextEditor/VisualizeSpaces", false).toBool()) {
    QTextOption option =  document()->defaultTextOption();
    option.setFlags(option.flags() | QTextOption::ShowTabsAndSpaces);
    document()->setDefaultTextOption(option);
  }
  pointList = new QStringList();
  createActions();
  retranslateUi();
}

void BaseTextEditor::showHideLineNumbers(bool show)
{
  showNumberArea = show;
  lineNumberArea->setVisible(showNumberArea);
  if (!showNumberArea)
    lineNumberArea->hide();
  updateLineNumberAreaWidth();
}

void BaseTextEditor::dockmarkCurrentLine()
{
  QTextCursor cursor = textCursor();
  QString blockNumber = QString("%1").arg(cursor.blockNumber());
  if (pointList->contains(blockNumber))
    pointList->removeAt(pointList->indexOf(blockNumber));
  else
    pointList->append(blockNumber);
  repaint();
}

void BaseTextEditor::updateLineNumberAreaWidth()
{
  if (showNumberArea)
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
  else
    setViewportMargins(0, 0, 0, 0);
}

void BaseTextEditor::updateLineNumberArea(const QRect &rect, int dy)
{
  if (dy)
    lineNumberArea->scroll(0, dy);
  else
    lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
  if (rect.contains(viewport()->rect()))
    updateLineNumberAreaWidth();
}

void BaseTextEditor::highlightCurrentLine()
{
  if (!isReadOnly()) {
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;
    selection.format.setBackground(QColor(229, 233, 243));
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
    setExtraSelections(extraSelections);
  }
}

void BaseTextEditor::resizeEvent(QResizeEvent *event)
{
  QPlainTextEdit::resizeEvent(event);
  if (showNumberArea)
    lineNumberArea->setGeometry(QRect(contentsRect().left(), contentsRect().top(), lineNumberAreaWidth(), contentsRect().height()));
}

void BaseTextEditor::keyPressEvent(QKeyEvent *event)
{
  if (completedAndSelected && handledCompletedAndSelected(event))
    return;
  completedAndSelected = false;
  switch (event->key()) {
  case Qt::Key_Escape:
    emit escKeyPressed();
    break;
  }
//  if (completer->popup()->isVisible()) {
//    switch (event->key()) {
//    case Qt::Key_Up:
//    case Qt::Key_Down:
//    case Qt::Key_Enter:
//    case Qt::Key_Return:
//    case Qt::Key_Escape:
//      event->ignore();
//      return;
//    default:
//      completer->popup()->hide();
//      break;
//    }
//  }

  QTextCursor cursor;
  Qt::KeyboardModifiers modifiersControlShift;
  switch (event->key()) {
  case Qt::Key_AltGr:
    //Qt does no handle AltGrModifiers
    //Qt::ALT Qt::AltModifier The normal Alt keys, but not keys like AltGr.
    //http://doc.qt.io/qt-5/qt.html
    //Qt::Key_QuoteLeft
    smartTextInsertion("`", "`");
    return;
  case Qt::Key_Backspace:
    cursor = textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    if (cursor.selectedText() == "()") {
      setTextCursor(cursor);
    }
    if (cursor.selectedText().right(2) == "()" && cursor.selectedText().length() > 2) {
      cursor.insertText(cursor.selectedText().left(cursor.selectedText().length() - 2).repeated(2));
      setTextCursor(cursor);
    }
    break;
  case Qt::Key_QuoteDbl:
    smartTextInsertion("\"");
    return;
  case Qt::Key_Apostrophe:
    smartTextInsertion("'");
    return;
  case Qt::Key_Agrave:
    smartTextInsertion("`");
    return;
  case Qt::Key_ParenLeft:
    smartTextInsertion("(", ")");
    return;
  case Qt::Key_BracketLeft:
    smartTextInsertion("[", "]");
    return;
  case Qt::Key_BraceLeft:
    smartTextInsertion("{", "}");
    return;
  case Qt::Key_Tab:
    indentAction->trigger();
    return;
//  case Qt::Key_Escape:
//    setFocusToEditorActionTriggered();
//    break;
  case Qt::Key_Home:
    homeKeyHitedTwice = !homeKeyHitedTwice;
    if (homeKeyHitedTwice) {
      QTextCursor cursor = textCursor();
      cursor.movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor);
      setTextCursor(cursor);
      return;
    }
    break;
    //  case Qt::Key_Delete:
    //    if (event->modifiers() == Qt::ControlModifier)
    //      cutLineActionTriggerd();
    //    break;
  case Qt::Key_Up:
  case Qt::Key_Down:
    if (event->modifiers() == Qt::ControlModifier) {
      QList<int> list;
      QTextCursor cursor = textCursor();
      for (int counter = 0; counter < pointList->count(); counter++)
        list.append(pointList->at(counter).toUInt());
      if (list.indexOf(cursor.blockNumber()) == -1)
        list.append(cursor.blockNumber());
      qSort(list);
      if ((cursor.blockNumber() == list.last() && event->key() == Qt::Key_Down)
          || (cursor.blockNumber() == list.first() && event->key() == Qt::Key_Up))
        break;
      if (event->key() == Qt::Key_Up) {
        gotoLine(list.at(list.indexOf(cursor.blockNumber()) - 1));
        break;
      } else if (event->key() == Qt::Key_Down) {
        gotoLine(list.at(list.indexOf(cursor.blockNumber()) + 1));
        break;
      }
    }
    modifiersControlShift |= Qt::ShiftModifier;
    modifiersControlShift |= Qt::ControlModifier;
    if (event->modifiers() == modifiersControlShift) {
      QTextCursor cursor = textCursor();
      cursor.setPosition(cursor.position());
      cursor.setPosition(document()->find(";", cursor.position()).position(), QTextCursor::KeepAnchor);
      setTextCursor(cursor);
    }
    break;
  case Qt::Key_Return:
  case Qt::Key_Enter:
    cursor = textCursor();
    cursor.movePosition(QTextCursor::StartOfLine);
    cursor.select(QTextCursor::LineUnderCursor);
    if (cursor.selectedText().startsWith("/***"))
      cursor.insertText("/**********************************************************************************************/");
    break;
  case Qt::Key_Period:
    cursor = textCursor();
    cursor.movePosition(QTextCursor::WordLeft, QTextCursor::KeepAnchor);
    cursor.movePosition(QTextCursor::WordLeft, QTextCursor::KeepAnchor);
    cursor.movePosition(QTextCursor::WordLeft, QTextCursor::KeepAnchor);
    if (cursor.selectedText().startsWith("`") && cursor.selectedText().endsWith("`") && editorType == EditorTypes::SQLQuery)
      emit performPeriodCompletion(cursor.selectedText().mid(1, cursor.selectedText().length() - 2));
    break;
  default:
    homeKeyHitedTwice = true;
  }
  QPlainTextEdit::keyPressEvent(event);

  if (settings.value("TextEditor/AutomaticIndentation", Qt::Unchecked) == Qt::Checked)
    switch (event->key()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
      smartTextIndentation();
      break;
    // default: Q_ASSERT(false);
    }
  //  QPlainTextEdit::keyPressEvent(event);
}

void BaseTextEditor::mousePressEvent(QMouseEvent *event)
{
  QPlainTextEdit::mousePressEvent(event);
////  if (event->modifiers() == Qt::ControlModifier) {
//  if (folded) {
//    QTextBlock foldedBlock = foldedBlockAt(event->pos());
//    if (!foldedBlock.isValid()) {
//      QPlainTextEdit::mousePressEvent(event);
//      return;
//    }
//  } else {
//    QPlainTextEdit::mousePressEvent(event);
//  }

////  EditorLayout *layout = static_cast<EditorLayout *>(document()->documentLayout());

//  folded = !folded;
//  for (int i = 0; i < 3; ++i) {
//    QTextBlock block = document()->findBlockByNumber(i + 2);
//    block.setVisible(!folded);
//    block.setLineCount(folded ? 0 : qMax(1, block.layout()->lineCount()));
//  }
////  QTextBlock block = firstVisibleBlock();
////  int blockNumber = block.blockNumber();
////  int top = (int)blockBoundingGeometry(block).translated(contentOffset()).top();
////  int bottom = top + (int)blockBoundingRect(block).height();
////  while (block.isValid() /*&& top <= event->rect().bottom()*/) {
////    block.setVisible(!folded);
////    block.setLineCount(folded ? 0 : qMax(1, block.layout()->lineCount()));

////    if (block.isVisible() && bottom >= event->rect().top()) {
////      painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, QString::number(blockNumber + 1));
////      if (pointList->contains(QString("%1").arg(blockNumber)))
////        painter.drawImage(QRect(0, top, 16, 16), QImage(":/images/png/16/server-database.png"));
////      drawFoldMarks(block, painter, top);
//////      qDebug() << ": "  << blockNumber - 1;
////    }
////    block = block.next();
////    top = bottom;
////    bottom = top + (int)blockBoundingRect(block).height();
////    ++blockNumber;
////  }


//  QTextCursor cursor = textCursor();
//  if (!cursor.block().isVisible()) {
//    cursor.setVisualNavigation(true);
//    cursor.movePosition(QTextCursor::Up);
//    setTextCursor(cursor);
//  }
//  QPlainTextDocumentLayout *layout = static_cast<QPlainTextDocumentLayout *>(document()->documentLayout());
////  document()->documentLayout()->re
//  layout->requestUpdate();
////  layout->emitDocumentSizeChanged();
}

void BaseTextEditor::paintEvent(QPaintEvent *event)
{
//  if (folded) {
//    QTextBlock foldedBlock = document()->findBlockByNumber(1);
//    if (!foldedBlock.isValid() || !foldedBlock.isVisible())
//      return;

//    qreal top = blockBoundingGeometry(foldedBlock).translated(contentOffset()).top();

//    QTextLayout *layout = foldedBlock.layout();
//    QTextLine line = layout->lineAt(layout->lineCount()-1);
//    QRectF lineRect = line.naturalTextRect().translated(0, top);

//    lineRect.adjust(0, 0, -1, -1);

//    QRectF collapseRect(lineRect.right() + 12,
//                        lineRect.top(),
//                        fontMetrics().width(QLatin1String(" ...} ")),
//                        lineRect.height());

//    QPainter painter(viewport());
//    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.translate(.5, .5);
//    painter.drawRoundedRect(collapseRect.adjusted(0, 0, 0, -1), 3, 3);
//    painter.translate(-.5, -.5);
//    painter.drawText(collapseRect, Qt::AlignCenter, "...}");
//  }

  QPlainTextEdit::paintEvent(event);
}

void BaseTextEditor::mouseDoubleClickEvent(QMouseEvent *event)
{
  QPlainTextEdit::mouseDoubleClickEvent(event);
  rehighlightOnMouse();
}

//void BaseTextEditor::mouseReleaseEvent(QMouseEvent *event)
//{
//  QPlainTextEdit::mouseReleaseEvent(event);
//  rehighlightOnMouse();
//}

void BaseTextEditor::mouseMoveEvent(QMouseEvent *event)
{
  QPlainTextEdit::mouseMoveEvent(event);
  rehighlightOnMouse();
}

bool BaseTextEditor::handledCompletedAndSelected(QKeyEvent *event)
{
  completedAndSelected = false;
  QTextCursor cursor = textCursor();
  switch (event->key()) {
  case Qt::Key_Enter:
  case Qt::Key_Return:
    cursor.clearSelection();
    break;
  case Qt::Key_Escape:
    cursor.removeSelectedText();
    break;
  default: return false;
  }
  setTextCursor(cursor);
  event->accept();
  return true;
}

void BaseTextEditor::smartTextInsertion(QString leftKey, QString rightKey)
{
  QTextCursor cursor = textCursor();
  bool hasSelection = cursor.hasSelection();
  cursor.insertText(leftKey + cursor.selectedText() + (rightKey.isEmpty() ? leftKey : rightKey));
  if (!hasSelection)
    cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
  setTextCursor(cursor);
}

void BaseTextEditor::smartTextIndentation()
{
  QString prevText(textCursor().block().previous().text());
  int count = 0;
  for (int pos = 0; pos <= prevText.length(); pos++)
    if (prevText[pos] == QChar(' '))
      count++;
    else
      break;
  QTextCursor cursor = textCursor();
  cursor.insertText(QString(" ").repeated(count));
  setTextCursor(cursor);
}

void BaseTextEditor::createActions()
{
  indentAction = new QAction(this);
  indentAction->setIcon(QIcon::fromTheme("format-indent-more", QIcon(":/images/svg/format-indent-more-4.svg")));
  indentAction->setShortcut(QKeySequence(Qt::Key_Tab));
  connect(indentAction, SIGNAL(triggered()), this, SLOT(indentActionTriggered()));
  unidentAction = new QAction(this);
  unidentAction->setIcon(QIcon::fromTheme("format-indent-less", QIcon(":/images/svg/format-indent-less-4.svg")));
  unidentAction->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_Tab));
  connect(unidentAction, SIGNAL(triggered()), this, SLOT(unidentActionTriggered()));
  insertLicenceTamplateAction = new QAction(this);
  connect(insertLicenceTamplateAction, SIGNAL(triggered()), this, SLOT(insertLicenceTemplateSlot()));
  visualizeSpacesAction = new QAction(this);
  visualizeSpacesAction->setCheckable(true);
  visualizeSpacesAction->setChecked(settings.value("TextEditor/VisualizeSpaces", false).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(visualizeSpacesAction, SIGNAL(toggled(bool)), this, SLOT(visualizeSpacesActionTriggered(bool)));
}

void BaseTextEditor::retranslateUi()
{
  indentAction->setText(tr("Indent"));
  indentAction->setToolTip(indentAction->text());
  unidentAction->setText(tr("Unindent"));
  unidentAction->setToolTip(unidentAction->text());
  insertLicenceTamplateAction->setText(tr("Insert licence template"));
  insertLicenceTamplateAction->setToolTip(insertLicenceTamplateAction->text());
  visualizeSpacesAction->setText(tr("Visualize spaces"));
  visualizeSpacesAction->setToolTip(visualizeSpacesAction->text());
}

QStringList BaseTextEditor::wordList()
{
  QStringList words = toPlainText().split(QRegExp("\\W+"));
  words.removeDuplicates();
  return words;
}

void BaseTextEditor::insertLicenceTemplateSlot()
{
  QTextCursor cursor = textCursor();
  cursor.insertText(settings.value("License/Template", "").toString());
  setTextCursor(cursor);
}

void BaseTextEditor::setPlainText(const QString &text, bool concatenate)
{
  if (concatenate) {
    QPlainTextEdit::setPlainText(text + "\n" + toPlainText());
  } else {
    QPlainTextEdit::setPlainText(text);
  }
}

void BaseTextEditor::indentActionTriggered()
{
  indentOrUnindent(true);
}

void BaseTextEditor::unidentActionTriggered()
{
  indentOrUnindent(false);
}

void BaseTextEditor::visualizeSpacesActionTriggered(bool toggled)
{
  QTextOption option = document()->defaultTextOption();
  if (toggled)
    option.setFlags(option.flags() | QTextOption::ShowTabsAndSpaces);
  else
    option.setFlags(option.flags() & ~QTextOption::ShowTabsAndSpaces);
  //option.setFlags(option.flags() | QTextOption::AddSpaceForLineAndParagraphSeparators);
  document()->setDefaultTextOption(option);
  settings.setValue("TextEditor/VisualizeSpaces", toggled);
}

void BaseTextEditor::indentOrUnindent(bool doIndent)
{
  QTextCursor cursor = textCursor();
  cursor.beginEditBlock();

  if (cursor.hasSelection()) {
    int pos = cursor.position();
    int anchor = cursor.anchor();
    int start = qMin(anchor, pos);
    int end = qMax(anchor, pos);

    QTextDocument *doc = document();
    QTextBlock startBlock = doc->findBlock(start);
    QTextBlock endBlock = doc->findBlock(end - 1).next();

    for (QTextBlock block = startBlock; block != endBlock; block = block.next()) {
      QString text(block.text());
      int indentPosition = lineIndentPosition(text);
      if (!doIndent && !indentPosition)
        indentPosition = firstNonSpace(text);
      int targetColumn = indentedColumn(columnAt(text, indentPosition), doIndent);
      cursor.setPosition(block.position() + indentPosition);
      cursor.insertText(indentationString(0, targetColumn, block));
      cursor.setPosition(block.position());
      cursor.setPosition(block.position() + indentPosition, QTextCursor::KeepAnchor);
      cursor.removeSelectedText();
    }
  } else {
    QTextBlock block = cursor.block();
    QString text(block.text());
    int indentPosition = cursor.position() - block.position();
    int spaces = spacesLeftFromPosition(text, indentPosition);
    int startColumn = columnAt(text, indentPosition - spaces);
    int targetColumn = indentedColumn(columnAt(text, indentPosition), doIndent);
    cursor.setPosition(block.position() + indentPosition);
    cursor.setPosition(block.position() + indentPosition - spaces, QTextCursor::KeepAnchor);
    cursor.removeSelectedText();
    cursor.insertText(indentationString(startColumn, targetColumn, block));
    setTextCursor(cursor);
  }
  cursor.endEditBlock();
}

int BaseTextEditor::lineIndentPosition(const QString &text) const
{
  int i = 0;
  while (i < text.size()) {
    if (!text.at(i).isSpace())
      break;
    ++i;
  }
  int column = columnAt(text, i);
  return i - (column % settings.value("TextEditor/TabSize", 2).toInt());
}

int BaseTextEditor::firstNonSpace(const QString &text) const
{
  int i = 0;
  while (i < text.size()) {
    if (!text.at(i).isSpace())
      return i;
    ++i;
  }
  return i;
}

QString BaseTextEditor::indentationString(const QString &text) const
{
  return text.left(firstNonSpace(text));
}

int BaseTextEditor::indentationColumn(const QString &text) const
{
  return columnAt(text, firstNonSpace(text));
}

int BaseTextEditor::columnAt(const QString &text, int position) const
{
  int column = 0;
  for (int i = 0; i < position; ++i) {
    if (text.at(i) == QLatin1Char('\t'))
      column = column - (column % settings.value("TextEditor/TabSize", 2).toInt()) + settings.value("TextEditor/TabSize", 2).toInt();
    else
      ++column;
  }
  return column;
}

int BaseTextEditor::indentedColumn(int column, bool doIndent) const
{
  int aligned = (column / settings.value("TextEditor/TabSize", 2).toInt()) * settings.value("TextEditor/TabSize", 2).toInt();
  if (doIndent)
    return aligned + settings.value("TextEditor/TabSize", 2).toInt();
  if (aligned < column)
    return aligned;
  return qMax(0, aligned - settings.value("TextEditor/TabSize", 2).toInt());
}

int BaseTextEditor::spacesLeftFromPosition(const QString &text, int position) const
{
  int pos = position;
  while (pos > 0) {
    if (!text.at(pos-1).isSpace())
      break;
    --pos;
  }
  return position - pos;
}

QString BaseTextEditor::indentationString(int startColumn, int targetColumn, const QTextBlock &block) const
{
  targetColumn = qMax(startColumn, targetColumn);
  if (guessSpacesForTabs(block))
    return QString(targetColumn - startColumn, QLatin1Char(' '));

  QString s;
  int alignedStart = startColumn - (startColumn % settings.value("TextEditor/TabSize", 2).toInt())
      + settings.value("TextEditor/TabSize", 2).toInt();
  if (alignedStart > startColumn && alignedStart <= targetColumn) {
    s += QLatin1Char('\t');
    startColumn = alignedStart;
  }
  if (int columns = targetColumn - startColumn) {
    int tabs = columns / settings.value("TextEditor/TabSize", 2).toInt();
    s += QString(tabs, QLatin1Char('\t'));
    s += QString(columns - tabs * settings.value("TextEditor/TabSize", 2).toInt(), QLatin1Char(' '));
  }
  return s;
}

bool BaseTextEditor::guessSpacesForTabs(const QTextBlock &block) const
{
  if (block.isValid()) {
    const QTextDocument *doc = block.document();
    QVector<QTextBlock> currentBlocks(2, block);
    int maxLookAround = 100;
    while (maxLookAround-- > 0) {
      if (currentBlocks.at(0).isValid())
        currentBlocks[0] = currentBlocks.at(0).previous();
      if (currentBlocks.at(1).isValid())
        currentBlocks[1] = currentBlocks.at(1).next();
      bool done = true;
      foreach (const QTextBlock &block, currentBlocks) {
        if (block.isValid())
          done = false;
        if (!block.isValid() || block.length() == 0)
          continue;
        const QChar firstChar = doc->characterAt(block.position());
        if (firstChar == QLatin1Char(' ')) {
          return true;
        } else if (firstChar == QLatin1Char('\t')) {
          return false;
        }
      }
      if (done)
        break;
    }
  }
  return true;
}

void BaseTextEditor::drawFoldMarks(const QTextBlock &block, QPainter &painter, const int &top)
{
  bool drawFoldMark = false;

  switch(editorType) {
  case EditorTypes::SQLQuery:
    if (block.text().startsWith("CREATE", Qt::CaseInsensitive))
      drawFoldMark = true;
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
  if (drawFoldMark) {
//    QTextCursor cursor = textCursor();
//    QHash<unsigned int, bool>::const_iterator i = foldRowList->constBegin();
//    while (i != foldRowList->constEnd()) {
//      qDebug() << i.key() << ": " << i.value() << "L";
//      ++i;
//    }
//    qDebug() << "a: " << cursor.blockNumber();
//    qDebug() << blockNumber;

//    for (int a = 0; a < foldRowList->count(); a++)
//      qDebug() << foldRowList->at(a);

//    if (foldRowList->contains(block.blockNumber())) {
//      painter.drawImage(QRect(0, top, 16, 16), QImage(":/images/svg/go-next-7.svg"));
//    } else {
      painter.drawImage(QRect(0, top, 16, 16), QImage(":/images/svg/go-down-7.svg"));
      foldRowList->append(block.blockNumber());
//    }
//    return false;
  }
//  return true;


  //  QTextCursor cursor = codeEditor->textCursor();
  ////  QTextBlock startBlock = codeEditor->document()->findBlockByLineNumber(cursor.blockNumber());
  ////  startBlock.setVisible(false);
  //  if (codeEditor->foldRowList->contains(cursor.blockNumber()))
  //    painter.drawImage(QRect(0, 0, 16, 16), QImage(":/images/svg/go-next-7.svg"));
  ////  qDebug() << cursor.blockNumber();

}

void BaseTextEditor::rehighlightOnMouse()
{
  // If mouse tracking is switched off, mouse move events only occur if a mouse button is pressed while the mouse is being moved. If mouse tracking is switched on, mouse move events occur even if no mouse button is pressed.
  QTextCursor cursor = textCursor();
  if (editorType != EditorTypes::NoEditor)
    rehighlight(cursor.selectedText());
}

//QTextBlock BaseTextEditor::foldedBlockAt(const QPoint &point)
//{
////  QTextCursor cursor = textCursor();
////  QTextBlock block = document()->findBlockByNumber(cursor.position());
//  QTextBlock block = firstVisibleBlock();
//  qreal top = blockBoundingGeometry(block).translated(contentOffset()).top();
//  qreal bottom = top + blockBoundingRect(block).height();

//  int viewportHeight = viewport()->height();

//  while (block.isValid() && top <= viewportHeight) {
//    QTextBlock nextBlock = block.next();

//    if (block.isVisible() && bottom >= 0) {
//      if (nextBlock.isValid() && !nextBlock.isVisible()) {
//        QTextLayout *layout = block.layout();
//        QTextLine line = layout->lineAt(layout->lineCount()-1);
//        QRectF lineRect = line.naturalTextRect().translated(0, top);
//        lineRect.adjust(0, 0, -1, -1);
//        QRectF collapseRect(lineRect.right() + 12, lineRect.top(), fontMetrics().width(QLatin1String(" ...} ")), lineRect.height());
//        if (collapseRect.contains(point)) {
//          QTextBlock result = block;
//          return result;
//        } else {
//          block = nextBlock;
//          while (nextBlock.isValid() && !nextBlock.isVisible()) {
//            block = nextBlock;
//            nextBlock = block.next();
//          }
//        }
//      }
//    }

//    block = nextBlock;
//    top = bottom;
//    bottom = top + blockBoundingRect(block).height();
//  }
//  return QTextBlock();
//}

int BaseTextEditor::lineNumberAreaWidth()
{
  int digits = 1;
  int max = qMax(1, blockCount());
  while (max >= 10) {
    max /= 10;
    ++digits;
  }
  return 21 + fontMetrics().width(QLatin1Char('9')) * digits;
}

void BaseTextEditor::rehighlight(const QString &exp)
{
  generalHighlighter->setFindPattern(exp);
  generalHighlighter->rehighlight();
}

void BaseTextEditor::gotoLine(unsigned int lineNumber)
{
  QTextCursor cursor(document()->findBlockByNumber(lineNumber));
  cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 0);
  setTextCursor(cursor);
  centerCursor();
  setFocus();
}

void BaseTextEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
  QPainter painter(lineNumberArea);
  foldRowList->clear();
  painter.fillRect(event->rect(), QColor(240, 244, 247));
  QTextBlock block = firstVisibleBlock();
  int blockNumber = block.blockNumber();
  int top = (int)blockBoundingGeometry(block).translated(contentOffset()).top();
  int bottom = top + (int)blockBoundingRect(block).height();
  while (block.isValid() && top <= event->rect().bottom()) {
    if (block.isVisible() && bottom >= event->rect().top()) {
      painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, QString::number(blockNumber + 1));
      if (pointList->contains(QString("%1").arg(blockNumber)))
        painter.drawImage(QRect(0, top, 16, 16), QImage(":/images/png/16/server-database.png"));
      drawFoldMarks(block, painter, top);
//      qDebug() << ": "  << blockNumber - 1;
    }
    block = block.next();
    top = bottom;
    bottom = top + (int)blockBoundingRect(block).height();
    ++blockNumber;
  }
//  for (int a = 0; a < foldRowList->count(); a++)
//    qDebug() << foldRowList->at(a);
}

LineNumberArea::LineNumberArea(BaseTextEditor *editor) : QWidget(editor), codeEditor(editor)
{
}

void LineNumberArea::paintEvent(QPaintEvent *event)
{
  codeEditor->lineNumberAreaPaintEvent(event);
}

void LineNumberArea::mouseDoubleClickEvent(QMouseEvent *event)
{
  codeEditor->dockmarkCurrentLine();
  QWidget::mouseDoubleClickEvent(event);
}

void LineNumberArea::mousePressEvent(QMouseEvent *event)
{
  /* Code folding happens here*/
  QTextCursor cursor = codeEditor->cursorForPosition(QPoint(event->x(), event->y()));
  if (codeEditor->foldRowList->contains(cursor.blockNumber())) {
//    QTextBlock block = cursor.block();
//    block.next();
//    block.setVisible(!block.isVisible());
//    codeEditor->viewport()->repaint();
    qDebug() << cursor.blockNumber();
  }
  QWidget::mousePressEvent(event);
}
