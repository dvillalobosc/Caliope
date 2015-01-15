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

#include <QCompleter>
#include <QShortcut>
#include <QScrollBar>
#include <QAbstractItemView>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMenu>
#include <QApplication>
#include <QTextStream>
#include <QSettings>
#include <QMessageBox>
#include <QInputDialog>
#include <QPrinter>
#include <QToolTip>
#include <QTextDocumentWriter>
#include <QtSvg/QSvgGenerator>
#include <QPainter>
#include <QImageWriter>
#include <QListWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QProcess>
#include <QWhatsThis>
#include <QPrintDialog>

#include "texteditor.h"
#include "editortypes.h"
#include "staticfunctions.h"
#include "generalhighlighter.h"
#include "findreplace.h"
#include "subversionedfile.h"
#include "dstatusbar.h"
#include "basetexteditor.h"
#include "projects.h"
#include "dtitlelabel.h"
#include "dbms.h"

#include "QDebug"

TextEditor::TextEditor(Projects *project, DBMS *serverConnection, EditorTypes::EditorType type, unsigned int windowCount, bool hideTitle)
{
  this->project = project;
  editorType = type;
  this->serverConnection = serverConnection;
  setWindowIcon(StaticFunctions::iconFromFileName(type));
//  homeKeyHitedTwice = true;
  this->windowCount = windowCount;
  readOnlyTextEditor = new BaseTextEditor(type);
  readOnlyTextEditor->setReadOnly(true);
  textEditor = new BaseTextEditor(type);
  connect(this, SIGNAL(changeTitle(QString)), this, SLOT(setTitle(QString)));
  connect(textEditor, SIGNAL(performPeriodCompletion(QString)), this, SLOT(performPeriodCompletion(QString)));
  model = new QStandardItemModel(this);
  completer = new QCompleter(this);
  completer->setWidget(this);
  completer->setCompletionMode(QCompleter::PopupCompletion);
  completer->setModel(model);
  completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setFilterMode(Qt::MatchContains);
  completer->setWrapAround(true);
  connect(completer, SIGNAL(activated(const QString&)), this, SLOT(insertCompletion(const QString&)));

  modelForPeriodCompeltion = new QStandardItemModel(this);
  completerForPeriodCompeltion = new QCompleter(this);
  completerForPeriodCompeltion->setWidget(this);
  completerForPeriodCompeltion->setCompletionMode(QCompleter::PopupCompletion);
  completerForPeriodCompeltion->setModel(modelForPeriodCompeltion);
  completerForPeriodCompeltion->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
  completerForPeriodCompeltion->setCaseSensitivity(Qt::CaseInsensitive);
  completerForPeriodCompeltion->setFilterMode(Qt::MatchContains);
  completerForPeriodCompeltion->setWrapAround(true);
  connect(completerForPeriodCompeltion, SIGNAL(activated(const QString&)), this, SLOT(insertCompletionForPeriodCompeltion(const QString&)));

  (void) new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Space), this, SLOT(performCompletion()));
  findReplace = new FindReplace(this);
  createActions();
  openRecentFilesMenu = new QMenu(this);
  openRecentFilesMenu->setIcon(QIcon::fromTheme("document-open-recent", QIcon(":/images/svg/document-open-recent-3.svg")));
  connect(openRecentFilesMenu, SIGNAL(aboutToShow()), this, SLOT(openRecentFilesMenuAboutToShowSlot()));
  symbolsMenu = new QMenu(this);
  symbolsMenu->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(symbolsMenu, SIGNAL(aboutToShow()), this, SLOT(symbolsMenuAboutToShowSlot()));
  contextualMenu = new QMenu(this);
  contextualMenu->addMenu(symbolsMenu);
  contextualMenuSeparatorAction = contextualMenu->addSeparator();
  contextualMenu->addActions(editActionList());
  exportMenu = new QMenu;
  exportMenu->setIcon(QIcon(":/images/svg/document-export-4.svg"));
  exportMenu->addAction(exportoToPdfOrPsAction);
  exportMenu->addAction(exportoToOdtAction);
  exportMenu->addAction(exportoToHtmlAction);
  exportMenu->addAction(exportoToSvgAction);
  exportMenu->addAction(exportoToImgAction);
  newFont = font();
  newFont.setPointSize(settings.value("TextEditor/PointSize", 12).toInt());
  setFontToWidgets(newFont);
  fillMariaDBSymbolsActionSlot();
//  connect(textEditor, SIGNAL(cursorPositionChanged()), this, SLOT(matchBracket()));

  subversionedFile = new SubversionedFile(this->fileName);
  connect(subversionedFile, SIGNAL(reverted()), this, SLOT(reloadFileActionTriggerd()));

  connect(subversionedFile, SIGNAL(statusBarMessage(QString)), this->project, SLOT(statusBarMessageSlot(QString)));
  connect(subversionedFile, SIGNAL(statusBarMessagePopup(QString)), this->project, SLOT(statusBarMessagePopupSlot(QString)));
  connect(subversionedFile, SIGNAL(addSubWindow(DMdiSubWindow*)), this->project, SLOT(addSubWindowSlot(DMdiSubWindow*)));

  listSymbols = new QListWidget;
  createToolBars();
  createMenu();

  secondSplitter = new QSplitter(Qt::Vertical, this);
  QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, this);
  mainSplitter->addWidget(secondSplitter);
  mainSplitter->addWidget(listSymbols);

  secondSplitter->addWidget(textEditor);
  secondSplitter->addWidget(readOnlyTextEditor);
  secondSplitter->widget(1)->hide();
  connect(textEditor, SIGNAL(cursorPositionChanged()), this, SLOT(updateCursorPositionSlot()));
  connect(textEditor->document(), SIGNAL(contentsChanged()), this, SLOT(showSymbolsActionTriggered()));
  connect(listSymbols, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClickedSlot(QListWidgetItem*)));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  if (hideTitle)
    dTitleLabel->hide();
  mainVLayout->addWidget(menuBar);
  mainVLayout->addWidget(mainToolBar);
  mainVLayout->addWidget(mainSplitter);
  mainVLayout->addWidget(findReplace);

  openLastOpenedFile();
  sortSymbols = new QAction(this);
  sortSymbols->setIcon(QIcon::fromTheme("view-sort-ascending", QIcon(":/images/svg/view-sort-ascending-2.svg")));
  connect(sortSymbols, SIGNAL(triggered()), this, SLOT(sortSymbolsSlot()));
  contextualMenu = new QMenu(this);
  contextualMenu->addAction(sortSymbols);
  retranslateUi();

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
}

void TextEditor::setTitle(QString title)
{
  setWindowTitle(title);
  dTitleLabel->setText(title);
}

void TextEditor::uppercaseKeywordsActionSlot()
{
  changeTextCase(true);
}

void TextEditor::lowercaseKeywordsActionSlot()
{
  changeTextCase(false);
}

void TextEditor::performPeriodCompletion(const QString &completionPrefix)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  modelForPeriodCompeltion->clear();
  foreach (QString item, serverConnection->runQuerySingleColumn("SELECT `TABLE_NAME` FROM `information_schema`.`TABLES` WHERE `TABLE_TYPE` = 'BASE TABLE' AND `TABLE_SCHEMA` = '" + completionPrefix + "'"))
    modelForPeriodCompeltion->appendRow(new QStandardItem(QIcon(":/images/svg/table.svg"), item));
  foreach (QString item, serverConnection->runQuerySingleColumn("SELECT `TABLE_NAME` FROM `information_schema`.`TABLES` WHERE `TABLE_TYPE` IN ('VIEW', 'SYSTEM VIEW') AND `TABLE_SCHEMA` = '" + completionPrefix + "'"))
    modelForPeriodCompeltion->appendRow(new QStandardItem(QIcon(":/images/svg/view.svg"), item));
  foreach (QString item, serverConnection->runQuerySingleColumn("SELECT `EVENT_NAME` FROM `information_schema`.`EVENTS` WHERE `EVENT_SCHEMA` = '" + completionPrefix + "'"))
    modelForPeriodCompeltion->appendRow(new QStandardItem(QIcon(":/images/svg/view-calendar-upcoming-events.svg"), item));
  foreach (QString item, serverConnection->runQuerySingleColumn("SELECT `SPECIFIC_NAME` FROM `information_schema`.`ROUTINES` WHERE `ROUTINE_SCHEMA` = '" + completionPrefix + "'"))
    modelForPeriodCompeltion->appendRow(new QStandardItem(QIcon(":/images/svg/system-run-5.svg"), item));
  foreach (QString item, serverConnection->runQuerySingleColumn("SELECT `TRIGGER_NAME` FROM `information_schema`.`TRIGGERS` WHERE `TRIGGER_SCHEMA` = '" + completionPrefix + "'"))
    modelForPeriodCompeltion->appendRow(new QStandardItem(QIcon(":/images/svg/view-calendar-upcoming-events.svg"), item));

//  if (completionPrefix != completer->completionPrefix()) {
//    completer->setCompletionPrefix(completionPrefix);
//    completer->popup()->setCurrentIndex(completer->completionModel()->index(0, 0));
//  }
//  if (completer->completionCount() == 1) {
//    insertCompletion(completer->currentCompletion());
//  } else {
    completerForPeriodCompeltion->complete(QRect(textEditor->cursorRect().x() + 5
                              , textEditor->cursorRect().y() + (dTitleLabel->isVisible() ? (dTitleLabel->height() + 5) : 0)
                              , completerForPeriodCompeltion->popup()->sizeHintForColumn(0) + completerForPeriodCompeltion->popup()->verticalScrollBar()->sizeHint().width()
                              , 40));
//  }
  QApplication::restoreOverrideCursor();
}

void TextEditor::insertCompletionForPeriodCompeltion(const QString &completion)
{
  QTextCursor cursor = textEditor->textCursor();
  cursor.setPosition(cursor.position() - completerForPeriodCompeltion->completionPrefix().length());
  cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
  cursor.insertText("`" + completion + "`");
  textEditor->setTextCursor(cursor);
}

void TextEditor::retranslateUi()
{
  openRecentFilesMenu->setTitle(tr("Recent files"));
  symbolsMenu->setTitle(tr("Symbols"));
  sortSymbols->setText(tr("Sort by name"));
  sortSymbols->setToolTip(sortSymbols->text());
  contextualMenuSeparatorAction->setText(tr("Edit Menu"));
  exportMenu->setTitle(tr("&Export"));
  fileMenu->setTitle(tr("&File"));
  editMenu->setTitle(tr("&Edit"));
  optionsMenu->setTitle(tr("&Options"));
  subversionMenu->setTitle(tr("&Subversion"));
  viewMenu->setTitle(tr("&View"));
  viewMenuSeparatorActionView->setText(tr("View"));
  viewMenuSeparatorActionSymbols->setText(tr("Symbols"));
  clearAction->setText(tr("Clear"));
  openAction->setText(tr("Open"));
  saveAction->setText(tr("Save"));
  saveAsAction->setText(tr("Save as..."));
  copyAction->setText(tr("Copy"));
  cutAction->setText(tr("Cut"));
  pasteAction->setText(tr("Paste"));
  undoAction->setText(tr("Undo"));
  redoAction->setText(tr("Redo"));
  wordWrapAction->setText(tr("Word wrap"));
  zoomInAction->setText(tr("In"));
  zoomOutAction->setText(tr("Out"));
  restoreZoomAction->setText(tr("Restore"));
  gotoLineAction->setText(tr("Line..."));
  selectAllAction->setText(tr("Select all"));
  clearRecentFilesAction->setText(tr("Clear recent files"));
  printAction->setText(tr("Print..."));
  reloadFile->setText(tr("Reload file"));
  disableCompletionAction->setText(tr("Disable completion"));
  showHideLineNumbersAction->setText(tr("Show/Hide line numbers"));
  cutLineAction->setText(tr("Cut line"));

  switch(editorType) {
  case EditorTypes::SQLQuery:
    setWindowTitle(tr("SQL Query %1").arg(windowCount));
    fillMariaDBSymbolsAction->setText(tr("Fill MariaDB Symbols"));
    break;
  case EditorTypes::PHP:
    executePHPScriptAction->setText(tr("Run PHP Script"));
    setWindowTitle(tr("PHP Script %1").arg(windowCount));
    break;
  case EditorTypes::CSS:
    setWindowTitle(tr("CSS Script %1").arg(windowCount));
    break;
  case EditorTypes::HTML:
    setWindowTitle(tr("HTML Script %1").arg(windowCount));
    break;
  case EditorTypes::JavaScript:
    setWindowTitle(tr("JavaScript Script %1").arg(windowCount));
    break;
  case EditorTypes::NoEditor:
    setWindowTitle(tr("Text File %1").arg(windowCount));
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
    break;
  // case EditorTypes::Diff:
  // default: Q_ASSERT(false);
  }

  showMariaDBHelperAction->setText(tr("Show SQL Helpers in the completion"));
  showMariaDBHelperAction->setToolTip(showMariaDBHelperAction->text());
  exportoToPdfOrPsAction->setText(tr("Export to Pdf"));
  exportoToOdtAction->setText(tr("Export to Odt"));
  exportoToHtmlAction->setText(tr("Export to Html"));
  exportoToSvgAction->setText(tr("Export to Svg"));
  exportoToImgAction->setText(tr("Export to Image"));
  toggleCommentAction->setText(tr("Toggle Comment"));
  highlightCurrentLineAction->setText(tr("Highlight current line"));
  viewNormalAction->setText(tr("Normal"));
  viewVerticalAction->setText(tr("Vertical"));
  viewHorizoltalAction->setText(tr("Horizontal"));
  showSymbolsAction->setText(tr("&Show Symols"));
  normalizeTextAction->setText(tr("&Normalize text"));
  readOnlyTextEditor->retranslateUi();
  textEditor->retranslateUi();
  uppercaseKeywordsAction->setText(tr("Uppercase keywords"));
  lowercaseKeywordsAction->setText(tr("Lowercase keywords"));

  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
}

void TextEditor::setPlainText(const QString &text)
{
  textEditor->setPlainText(text);
}

QTextDocument *TextEditor::document()
{
  return textEditor->document();
}

void TextEditor::gotoLine(unsigned int line)
{
  textEditor->gotoLine(line);
}

void TextEditor::matchBracket()
{
  QList<QTextEdit::ExtraSelection> selections = textEditor->extraSelections();
  textEditor->setExtraSelections(selections);
  TextBlockData *data = static_cast<TextBlockData *>(textEditor->textCursor().block().userData());
  if (data) {
    QVector<BracketInfo *> infos = data->brackets();
    int pos = textEditor->textCursor().block().position();
    for (int i = 0; i < infos.size(); ++i) {
      foreach (char leftBracket, StaticFunctions::bracketLeftList()) {
        char rightBracket = StaticFunctions::rightBracketMatch(leftBracket);
        BracketInfo *info = infos.at(i);
        int curPos = textEditor->textCursor().position() - textEditor->textCursor().block().position();
        if (info->position == curPos - 1 && info->character == leftBracket) {
          if (matchLeftBracket(textEditor->textCursor().block(), i + 1, 0, leftBracket))
            createBracketSelection(pos + info->position);
        } else if (info->position == curPos - 1 && info->character == rightBracket)
          if (matchRightBracket(textEditor->textCursor().block(), i - 1, 0, rightBracket, true))
            createBracketSelection(pos + info->position);
      }
    }
  }
}

bool TextEditor::matchLeftBracket(QTextBlock currentBlock, int index, int numLeftBracket, const char leftBracket)
{
  TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
  QVector<BracketInfo *> infos = data->brackets();
  int docPos = currentBlock.position();
  for (; index < infos.size(); ++index) {
    BracketInfo *info = infos.at(index);
    if (info->character == leftBracket) {
      ++numLeftBracket;
      continue;
    }
    if (info->character == StaticFunctions::rightBracketMatch(leftBracket) && numLeftBracket == 0) {
      createBracketSelection(docPos + info->position);
      return true;
    } else
      --numLeftBracket;
  }
  currentBlock = currentBlock.next();
  if (currentBlock.isValid())
    return matchLeftBracket(currentBlock, 0, numLeftBracket, leftBracket);
  return false;
}

bool TextEditor::matchRightBracket(QTextBlock currentBlock, int index, int numRightBracket, const char rightBracket, bool firstTime)
{
//  TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
//  QVector<BracketInfo *> parentheses = data->brackets();
//  int docPos = currentBlock.position();
//  for (; index > -1 && parentheses.size() > 0; --index) {
//    BracketInfo *info = parentheses.at(index);
//    if (info->character == rightBracket) {
//      ++numRightBracket;
//      continue;
//    }
//    if (info->character == StaticFunctions::leftBracketMatch(rightBracket) && numRightBracket == 0) {
//      createBracketSelection(docPos + info->position);
//      return true;
//    } else
//      --numRightBracket;
//  }
//  currentBlock = currentBlock.previous();
//  if (currentBlock.isValid())
//    return matchRightBracket(currentBlock, 0, numRightBracket, rightBracket);
//  return false;

  TextBlockData *data = static_cast<TextBlockData *>(currentBlock.userData());
  QVector<BracketInfo *> parentheses = data->brackets();

  if(!firstTime) //Set i to the end of the parentheses list.
    index = parentheses.size() - 1;
  int docPos = currentBlock.position();
  for (; index > -1 && parentheses.size() > 0; --index) {
    BracketInfo *info = parentheses.at(index);
    if (info->character == rightBracket) {
      ++numRightBracket;
      continue;
    }
    if (info->character == StaticFunctions::leftBracketMatch(rightBracket) && numRightBracket == 0) {
      createBracketSelection(docPos + info->position);
      return true;
    } else
      --numRightBracket;
  }
  currentBlock = currentBlock.previous();
  if (currentBlock.isValid())
    return matchRightBracket(currentBlock, 0, numRightBracket, rightBracket);
  return false;
}

void TextEditor::createBracketSelection(int pos)
{
  QList<QTextEdit::ExtraSelection> selections = textEditor->extraSelections();
  QTextEdit::ExtraSelection selection;
  QTextCharFormat format = selection.format;
  format.setBackground(Qt::lightGray);
  selection.format = format;
  QTextCursor cursor = textEditor->textCursor();
  cursor.setPosition(pos);
  cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
  selection.cursor = cursor;
  selections.append(selection);
  textEditor->setExtraSelections(selections);
}

void TextEditor::fillMariaDBSymbolsActionSlot()
{
  if (serverConnection->isOpened() && editorType == EditorTypes::SQLQuery) {
    databaseSymbols.clear();
    databaseSymbols = serverConnection->runQuerySingleColumn("SELECT `TABLE_NAME` FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = DATABASE() UNION SELECT DISTINCT(`COLUMN_NAME`) FROM `information_schema`.`COLUMNS` WHERE `TABLE_SCHEMA` = DATABASE() UNION SELECT DISTINCT(`name`) FROM `mysql`.`proc` WHERE `db` = DATABASE() UNION SELECT `EVENT_NAME` FROM `information_schema`.`EVENTS` WHERE `EVENT_SCHEMA` = DATABASE() UNION SELECT `TRIGGER_NAME` FROM `information_schema`.`TRIGGERS` WHERE `TRIGGER_SCHEMA` = DATABASE()");
    databaseSymbols += serverConnection->runQuerySingleColumn("SHOW DATABASES");
  }
}

void TextEditor::openLastOpenedFile()
{
  QSettings settings;
  if (settings.value("General/OpenLastFile", false).toBool()) {
    switch(editorType) {
    case EditorTypes::SQLQuery:
      openFile(settings.value("General/LastMariaDBFile", "").toString());
      break;
    case EditorTypes::PHP:
      openFile(settings.value("General/LastPHPFile", "").toString());
      break;
    case EditorTypes::CSS:
      openFile(settings.value("General/LastCSSFile", "").toString());
      break;
    case EditorTypes::HTML:
      openFile(settings.value("General/LastHTMLFile", "").toString());
      break;
    case EditorTypes::JavaScript:
      openFile(settings.value("General/LastJavaScriptFile", "").toString());
      break;
    case EditorTypes::Diff:
    case EditorTypes::Commit:
    case EditorTypes::SVNLog:
    case EditorTypes::NoEditor:
      break;
    // default: Q_ASSERT(false);
    }
  }
}

void TextEditor::reloadFileActionTriggerd()
{
  openFile(fileName);
}

void TextEditor::printActionTriggerd()
{
  QPrinter printer;
  printer.setResolution(QPrinter::HighResolution);
  QFileInfo file(fileName);
  printer.setOutputFileName(file.completeBaseName() + ".pdf");
  printer.setPageSize(QPrinter::Letter);
  printer.setPageMargins(10, 10, 10, 10, QPrinter::Millimeter);
  QPrintDialog *printDialog = new QPrintDialog(&printer, this);
  printDialog->setWindowTitle(tr("Print Script"));
  if (printDialog->exec() == QDialog::Accepted)
    textEditor->print(&printer);
}

void TextEditor::openRecentFilesMenuAboutToShowSlot()
{
  QSettings settings;
  QString setting;
  openRecentFilesMenu->clear();
  switch(editorType) {
  case EditorTypes::SQLQuery:
    setting = "RecentMariaDBFiles/Files";
    break;
  case EditorTypes::PHP:
    setting = "RecentPHPFiles/Files";
    break;
  case EditorTypes::CSS:
    setting = "RecentCSSFiles/Files";
    break;
  case EditorTypes::HTML:
    setting = "RecentHTMLFiles/Files";
    break;
  case EditorTypes::JavaScript:
    setting = "RecentJavaScriptFiles/Files";
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
  QStringList fileList = settings.value(setting, QStringList()).toStringList();
  fileList.sort();
  foreach (QString file, fileList)
    if (!file.isEmpty())
      recentFilesActionGroup->addAction(openRecentFilesMenu->addAction(StaticFunctions::iconFromFileName(file), file));
  openRecentFilesMenu->addSeparator()->setText(tr("Clean"));
  openRecentFilesMenu->addAction(clearRecentFilesAction);
}

void TextEditor::insertCompletion(const QString &completion)
{
  QTextCursor cursor = textEditor->textCursor();
  cursor.setPosition(cursor.position() - completer->completionPrefix().length());
  cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
  QString sufix;
  switch(editorType) {
  case EditorTypes::CSS:
    if (StaticFunctions::cssProperties().contains(completion))
      sufix = ": ";
    cursor.insertText(completion + sufix);
    break;
  case EditorTypes::SQLQuery:
    if (StaticFunctions::mariadbFunctions().contains(completion) || StaticFunctions::postgresqlFunctions().contains(completion)) {
      sufix = "()";
      cursor.insertText(completion + sufix);
      cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
    } else if (databaseSymbols.contains(completion)) {
      cursor.insertText("`" + completion + "`");
    } else {
      cursor.insertText(completion + sufix);
    }
    break;
  case EditorTypes::PHP:
    if (StaticFunctions::phpFunctions().contains(completion)) {
      sufix = "()";
      cursor.insertText(completion + sufix);
      cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
    } else {
      cursor.insertText(completion + sufix);
    }
    break;
  case EditorTypes::JavaScript:
    if (StaticFunctions::javascriptFunctions().contains(completion)) {
      sufix = "()";
      cursor.insertText(completion + sufix);
      cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
    } else {
      cursor.insertText(completion + sufix);
    }
    break;
  case EditorTypes::HTML:
    if (StaticFunctions::htmlTags().contains(completion)) {
      sufix = "></" + completion + ">";
      cursor.insertText(completion + sufix);
      cursor.movePosition(QTextCursor::PreviousWord, QTextCursor::MoveAnchor, 2);
      cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor, 2);
    }
    if (StaticFunctions::htmlAttributes().contains(completion)) {
      sufix = "=\"\"";
      cursor.insertText(completion + sufix);
      cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
    }
    break;
  default:
    cursor.insertText(completion + sufix);
    break;
  }
  textEditor->setTextCursor(cursor);
}

//void TextEditor::keyPressEvent(QKeyEvent *event)
//{
//  QPlainTextEdit::keyPressEvent(event);
//  qDebug() << event->key();
//  if (completedAndSelected && handledCompletedAndSelected(event))
//    return;
//  completedAndSelected = false;
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

//  switch (event->key()) {
//  case Qt::Key_QuoteDbl:
//    smartTextInsertion("\"");
//    return;
//  case Qt::Key_Apostrophe:
//    smartTextInsertion("'");
//    return;
//  case Qt::Key_Agrave:
//    smartTextInsertion("`");
//    return;
//  case Qt::Key_ParenLeft:
//    smartTextInsertion("(", ")");
//    return;
//  case Qt::Key_BracketLeft:
//    smartTextInsertion("[", "]");
//    return;
//  case Qt::Key_BraceLeft:
//    smartTextInsertion("{", "}");
//    return;
//  case Qt::Key_Tab:
//    indentAction->trigger();
//    return;
//  case Qt::Key_Escape:
//    setFocusToEditorActionTriggered();
//    break;
//  case Qt::Key_Home:
//    homeKeyHitedTwice = !homeKeyHitedTwice;
//    if (homeKeyHitedTwice) {
//      QTextCursor cursor = textEditor->textCursor();
//      cursor.movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor);
//      textEditor->setTextCursor(cursor);
//      return;
//    }
//    break;
////  case Qt::Key_Delete:
////    if (event->modifiers() == Qt::ControlModifier)
////      cutLineActionTriggerd();
////    break;
//  default:
//    homeKeyHitedTwice = true;
//  }
////  **********************QPlainTextEdit::keyPressEvent(event);

//  if (settings.value("TextEditor/AutomaticIndentation", Qt::Unchecked) == Qt::Checked)
//    switch (event->key()) {
//    case Qt::Key_Return:
//    case Qt::Key_Enter:
//      smartTextIndentation();
//      break;
//    // default: Q_ASSERT(false);
//    }
//}

//void TextEditor::smartTextIndentation()
//{
//  QString prevText(textEditor->textCursor().block().previous().text());
//  int count = 0;
//  for (int pos = 0; pos <= prevText.length(); pos++)
//    if (prevText[pos] == QChar(' '))
//      count++;
//    else
//      break;
//  QTextCursor cursor = textEditor->textCursor();
//  cursor.insertText(QString(" ").repeated(count));
//  textEditor->setTextCursor(cursor);
//}

//void TextEditor::smartTextInsertion(QString leftKey, QString rightKey)
//{
//  QTextCursor cursor = textEditor->textCursor();
//  bool hasSelection = cursor.hasSelection();
//  cursor.insertText(leftKey + cursor.selectedText() + (rightKey.isEmpty() ? leftKey : rightKey));
//  if (!hasSelection)
//    cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
//  textEditor->setTextCursor(cursor);
//}

void TextEditor::mousePressEvent(QMouseEvent *event)
{
  if (completedAndSelected) {
    completedAndSelected = false;
    QTextCursor cursor = textEditor->textCursor();
    cursor.removeSelectedText();
    textEditor->setTextCursor(cursor);
  }
  QWidget::mousePressEvent(event);
}

//bool TextEditor::handledCompletedAndSelected(QKeyEvent *event)
//{
//  completedAndSelected = false;
//  QTextCursor cursor = textEditor->textCursor();
//  switch (event->key()) {
//  case Qt::Key_Enter:
//  case Qt::Key_Return:
//    cursor.clearSelection();
//    break;
//  case Qt::Key_Escape:
//    cursor.removeSelectedText();
//    break;
//  default: return false;
//  }
//  textEditor->setTextCursor(cursor);
//  event->accept();
//  return true;
//}

void TextEditor::performCompletion()
{
  if (disableCompletionAction->isChecked())
    return;
  QTextCursor cursor = textEditor->textCursor();
  cursor.movePosition(QTextCursor::StartOfWord, QTextCursor::KeepAnchor);
  const QString completionPrefix(cursor.selectedText());

  if (!completionPrefix.isEmpty() && completionPrefix.at(completionPrefix.length() - 1).isLetter())
    performCompletion(completionPrefix);
  if (cursor.selectedText().endsWith("(") || cursor.selectedText().endsWith("`(") || cursor.selectedText().endsWith(":")) {
    cursor.movePosition(QTextCursor::PreviousWord, QTextCursor::KeepAnchor);
    QString message("<table><tr><td><img src=\":/images/svg/server-database.svg\" width=\"48\"></td><td valign=middle><p style='white-space:pre'>%1</p></td></tr></table>");
    QString messageText;
    QString text(cursor.selectedText().left(cursor.selectedText().length() - 1));
    QStringList data;
    switch(editorType) {
    case EditorTypes::SQLQuery:
      switch(qApp->property("DBMSType").toInt()) {
      case StaticFunctions::MySQL:
      case StaticFunctions::MariaDB:
        messageText = StaticFunctions::mariadbFunctionsComplete().value(text);
        if (messageText.isEmpty() && serverConnection->isOpened()) {
          data = serverConnection->runQuerySingleColumn("SELECT `param_list` FROM `mysql`.`proc` WHERE `name` = '" + StaticFunctions::unquoteSymbol(text) + "' AND `db` = DATABASE()");
          if (!data.empty())
            messageText = data.at(0);
        }
        break;
      case StaticFunctions::PostgreSQL:
        messageText = StaticFunctions::postgresqlFunctionsComplete().value(text);
        break;
      case StaticFunctions::Undefined:
      default:
        break;
      }
      message = message.arg(messageText);
      break;
    case EditorTypes::PHP:
      messageText = QString();
      messageText = StaticFunctions::phpFunctionsComplete().value(text);
      if (!messageText.isEmpty())
        message = message.arg(StaticFunctions::phpFunctionsComplete().value(text));
      else
        message = message.arg(project->getProjectFunctionListComplete().value(text));
      break;
    case EditorTypes::JavaScript:
      message = message.arg(StaticFunctions::javascriptFunctionsComplete().value(text));
      break;
    case EditorTypes::CSS:
      message = message.arg(StaticFunctions::cssPropertiesComplete().value(text));
      break;
    case EditorTypes::Diff:
    case EditorTypes::Commit:
    case EditorTypes::SVNLog:
    case EditorTypes::NoEditor:
    case EditorTypes::HTML:
      break;
    // default: Q_ASSERT(false);
    }
    QToolTip::showText(mapToGlobal(textEditor->cursorRect().topLeft()), message, this);
  }
}

void TextEditor::performCompletion(const QString &completionPrefix)
{
  populateModel(completionPrefix);
  if (completionPrefix != completer->completionPrefix()) {
    completer->setCompletionPrefix(completionPrefix);
    completer->popup()->setCurrentIndex(completer->completionModel()->index(0, 0));
  }
  if (completer->completionCount() == 1) {
    insertCompletion(completer->currentCompletion());
  } else {
    completer->complete(QRect(textEditor->cursorRect().x() + 5
                              , textEditor->cursorRect().y() + (dTitleLabel->isVisible() ? (dTitleLabel->height() + 5) : 0)
                              , completer->popup()->sizeHintForColumn(0) + completer->popup()->verticalScrollBar()->sizeHint().width()
                              , 40));
  }
}

void TextEditor::populateModel(const QString &completionPrefix)
{
  model->clear();
  switch(editorType) {
  case EditorTypes::SQLQuery:
    switch(qApp->property("DBMSType").toInt()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      foreach (QString item, StaticFunctions::mariadbKeywords().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
      foreach (QString item, StaticFunctions::mariadbFunctions().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
      foreach (QString item, StaticFunctions::mariadbDatatypes().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
      foreach (QString item, StaticFunctions::mariadbCharsets().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/character-set.svg"), item));
      foreach (QString item, databaseSymbols.filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
      if (showMariaDBHelperAction->isChecked())
        foreach (QString item, StaticFunctions::mariadbHelper().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
          model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
      break;
    case StaticFunctions::PostgreSQL:
      foreach (QString item, StaticFunctions::postgresqlKeywords().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
      foreach (QString item, StaticFunctions::postgresqlFunctions().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
      foreach (QString item, StaticFunctions::postgresqlDatatypes().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
      foreach (QString item, StaticFunctions::postgresqlCharsets().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/character-set.svg"), item));
      foreach (QString item, databaseSymbols.filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
        model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
    break;
  case EditorTypes::PHP:
    foreach (QString item, StaticFunctions::phpKeywords().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
    foreach (QString item, StaticFunctions::phpFunctions().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
    foreach (QString item, project->getProjectFunctionList().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
    break;
  case EditorTypes::CSS:
    foreach (QString item, StaticFunctions::cssProperties().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon::fromTheme("document-properties", QIcon(":/images/svg/document-properties-4.svg")), item));
    foreach (QString item, StaticFunctions::cssKeywords().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
    break;
  case EditorTypes::HTML:
    foreach (QString item, StaticFunctions::htmlAttributes().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon::fromTheme("document-properties", QIcon(":/images/svg/document-properties-4.svg")), item));
    foreach (QString item, StaticFunctions::htmlTags().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
    break;
  case EditorTypes::JavaScript:
    foreach (QString item, StaticFunctions::javascriptFunctions().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/server-database.svg"), item));
    foreach (QString item, StaticFunctions::javascriptKeywords().filter(QRegExp(QString("^%1").arg(completionPrefix), Qt::CaseInsensitive)))
      model->appendRow(new QStandardItem(QIcon(":/images/svg/application-pgp-keys.svg"), item));
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
  model->sort(0);
}

void TextEditor::updateRecentFiles(QString fileToSave)
{
  if (fileToSave.isEmpty())
    fileToSave = fileName;

  QString setting;
  QStringList fileList;
  switch(editorType) {
  case EditorTypes::SQLQuery:
    setting = "RecentMariaDBFiles/Files";
    break;
  case EditorTypes::PHP:
    setting = "RecentPHPFiles/Files";
    break;
  case EditorTypes::CSS:
    setting = "RecentCSSFiles/Files";
    break;
  case EditorTypes::HTML:
    setting = "RecentHTMLFiles/Files";
    break;
  case EditorTypes::JavaScript:
    setting = "RecentJavaScriptFiles/Files";
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
  fileList = settings.value(setting, QStringList()).toStringList();
  if (fileList.indexOf(fileToSave) == -1)
    fileList.append(fileToSave);
  settings.setValue(setting, fileList);
  if (settings.value("General/OpenLastFile", false).toBool()) {
    switch(editorType) {
    case EditorTypes::SQLQuery:
      settings.setValue("General/LastMariaDBFile", fileToSave);
      break;
    case EditorTypes::PHP:
      settings.setValue("General/LastPHPFile", fileToSave);
      break;
    case EditorTypes::CSS:
      settings.setValue("General/LastCSSFile", fileToSave);
      break;
    case EditorTypes::HTML:
      settings.setValue("General/LastHTMLFile", fileToSave);
      break;
    case EditorTypes::JavaScript:
      settings.setValue("General/LastJavaScriptFile", fileToSave);
      break;
    case EditorTypes::Diff:
    case EditorTypes::Commit:
    case EditorTypes::SVNLog:
    case EditorTypes::NoEditor:
      break;
    // default: Q_ASSERT(false);
    }
  }
}

bool TextEditor::saveFileAsActionTriggered()
{
  saveAs = true;
  return saveFileActionTriggered();
}

bool TextEditor::saveFileActionTriggered()
{
  if (fileName.isEmpty() || saveAs) {
    if (textEditor->toPlainText().isEmpty()) {
      QMessageBox::warning(this, tr("Save file"), tr("Cannot save empty files."));
      return false;
    }
    QFileInfo fileInfo(fileName);
    fileName = QFileDialog::getSaveFileName(this, tr("Save file"), fileInfo.filePath(), fileExtention());
    saveAs = false;
  }
  QFile file(fileName);
  if (settings.value("TextEditor/CreateBackupFile", Qt::Checked).toBool()) {
    QFile backupFile(fileName + "~");
    backupFile.remove();
    file.copy(fileName + "~");
  }
  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    emit statusBarMessage(tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()), QSystemTrayIcon::Critical);
    return false;
  }
  QTextStream out(&file);
//  if (settings.value("TextEditor/CleanWhiteSpaces", Qt::Unchecked) == Qt::Checked) {
//    QString newText;
//    foreach(QString line, toPlainText().split("\n"))
//      newText.append(line.replace(QRegExp("\\s*$"), "") + "\n");
//    setPlainText(newText);
//  }
  out << textEditor->toPlainText();
  file.close();
  updateRecentFiles(fileName);
  lineEditFile->setText(fileName);
  textEditor->document()->setModified(false);
  emit statusBarMessage(tr("File saved at: %1").arg(fileName), QSystemTrayIcon::Information);
//  parentWidget2->updateReadOnlyEditor();
  QApplication::restoreOverrideCursor();
  return true;
}

//int TextEditor::columnAt(const QString &text, int position) const
//{
//  int column = 0;
//  for (int i = 0; i < position; ++i) {
//    if (text.at(i) == QLatin1Char('\t'))
//      column = column - (column % settings.value("TextEditor/TabSize", 2).toInt()) + settings.value("TextEditor/TabSize", 2).toInt();
//    else
//      ++column;
//  }
//  return column;
//}

void TextEditor::createActions()
{
  clearAction = new QAction(this);
  clearAction->setIcon(QIcon::fromTheme("edit-clear", QIcon(":/images/svg/edit-clear-4.svg")));
  connect(clearAction, SIGNAL(triggered()), textEditor, SLOT(clear()));
  openAction = new QAction(this);
  openAction->setIcon(QIcon::fromTheme("document-open", QIcon(":/images/svg/document-open-7.svg")));
  openAction->setShortcut(QKeySequence::Open);
  connect(openAction, SIGNAL(triggered()), this, SLOT(openFileActionTriggered()));
  saveAction = new QAction(this);
  saveAction->setIcon(QIcon::fromTheme("document-save", QIcon(":/images/svg/document-save-5.svg")));
  saveAction->setShortcut(QKeySequence::Save);
  connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFileActionTriggered()));
  saveAsAction = new QAction(this);
  saveAsAction->setIcon(QIcon::fromTheme("document-save-as", QIcon(":/images/svg/document-save-as-5.svg")));
  saveAsAction->setShortcut(QKeySequence::SaveAs);
  connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveFileAsActionTriggered()));
  copyAction = new QAction(this);
  copyAction->setIcon(QIcon::fromTheme("edit-copy", QIcon(":/images/svg/edit-copy-6.svg")));
  copyAction->setShortcut(QKeySequence::Copy);
  connect(copyAction, SIGNAL(triggered()), textEditor, SLOT(copy()));
  cutAction = new QAction(this);
  cutAction->setIcon(QIcon::fromTheme("edit-cut", QIcon(":/images/svg/edit-cut-6.svg")));
  cutAction->setShortcut(QKeySequence::Cut);
  connect(cutAction, SIGNAL(triggered()), textEditor, SLOT(cut()));
  pasteAction = new QAction(this);
  pasteAction->setIcon(QIcon::fromTheme("edit-paste", QIcon(":/images/svg/edit-paste-6.svg")));
  pasteAction->setShortcut(QKeySequence::Paste);
  connect(pasteAction, SIGNAL(triggered()), textEditor, SLOT(paste()));
  undoAction = new QAction(this);
  undoAction->setIcon(QIcon::fromTheme("edit-undo", QIcon(":/images/svg/edit-undo-7.svg")));
  undoAction->setShortcut(QKeySequence::Undo);
  connect(undoAction, SIGNAL(triggered()), textEditor, SLOT(undo()));
  redoAction = new QAction(this);
  redoAction->setIcon(QIcon::fromTheme("edit-redo", QIcon(":/images/svg/edit-redo-7.svg")));
  redoAction->setShortcut(QKeySequence::Redo);
  connect(redoAction, SIGNAL(triggered()), textEditor, SLOT(redo()));
  wordWrapAction = new QAction(this);
  wordWrapAction->setShortcut(QKeySequence(Qt::Key_F12));
  wordWrapAction->setCheckable(true);
  wordWrapAction->setChecked(textEditor->wordWrapMode());
  connect(wordWrapAction, SIGNAL(toggled(bool)), this, SLOT(wordWrapActionToggled()));
  zoomInAction = new QAction(this);
  zoomInAction->setIcon(QIcon::fromTheme("zoom-in", QIcon(":/images/svg/zoom-in-5.svg")));
  zoomInAction->setShortcut(QKeySequence::ZoomIn);
  connect(zoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));
  zoomOutAction = new QAction(this);
  zoomOutAction->setIcon(QIcon::fromTheme("zoom-out", QIcon(":/images/svg/zoom-out-5.svg")));
  zoomOutAction->setShortcut(QKeySequence::ZoomOut);
  connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));
  restoreZoomAction = new QAction(this);
  restoreZoomAction->setIcon(QIcon::fromTheme("zoom-original", QIcon(":/images/svg/zoom-original-4.svg")));
  restoreZoomAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_0));
  connect(restoreZoomAction, SIGNAL(triggered()), this, SLOT(zoomReset()));
  gotoLineAction = new QAction(this);
  gotoLineAction->setIcon(QIcon::fromTheme("go-jump", QIcon(":/images/svg/go-jump-4.svg")));
  gotoLineAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
  connect(gotoLineAction, SIGNAL(triggered()), this, SLOT(gotoLineActionTriggered()));
  selectAllAction = new QAction(this);
  selectAllAction->setIcon(QIcon::fromTheme("edit-select-all", QIcon(":/images/svg/edit-select-all-3.svg")));
  selectAllAction->setShortcut(QKeySequence::SelectAll);
  connect(selectAllAction, SIGNAL(triggered()), textEditor, SLOT(selectAll()));
  clearRecentFilesAction = new QAction(this);
  clearRecentFilesAction->setIcon(QIcon::fromTheme("edit-clear", QIcon(":/images/svg/computerjanitor.svg")));
  connect(clearRecentFilesAction, SIGNAL(triggered()), this, SLOT(clearRecentFilesActionTriggered()));
  recentFilesActionGroup = new QActionGroup(this);
  connect(recentFilesActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(recentFilesActionGroupTriggered(QAction*)));
  gotoLineActionGroup = new QActionGroup(this);
  connect(gotoLineActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(gotoLineActionGroupTriggered(QAction*)));
  printAction = new QAction(this);
  printAction->setIcon(QIcon::fromTheme("document-print", QIcon(":/images/svg/document-print-5.svg")));
  printAction->setShortcut(QKeySequence::Print);
  connect(printAction, SIGNAL(triggered()), this, SLOT(printActionTriggerd()));
  reloadFile = new QAction(this);
  reloadFile->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));
  reloadFile->setShortcut(QKeySequence::Print);
  connect(reloadFile, SIGNAL(triggered()), this, SLOT(reloadFileActionTriggerd()));
  disableCompletionAction = new QAction(this);
  disableCompletionAction->setShortcut(QKeySequence(Qt::Key_F11));
  disableCompletionAction->setCheckable(true);
  showHideLineNumbersAction = new QAction(this);
  showHideLineNumbersAction->setShortcut(QKeySequence(Qt::Key_F10));
  showHideLineNumbersAction->setCheckable(true);
  showHideLineNumbersAction->setChecked(true);
  connect(showHideLineNumbersAction, SIGNAL(toggled(bool)), textEditor, SLOT(showHideLineNumbers(bool)));
  connect(textEditor, SIGNAL(modificationChanged(bool)), this, SLOT(modificationChangedSlot(bool)));
  cutLineAction = new QAction(this);
  cutLineAction->setIcon(QIcon::fromTheme("edit-cut", QIcon(":/images/svg/edit-cut-6.svg")));
  cutLineAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Delete));
  connect(cutLineAction, SIGNAL(triggered()), this, SLOT(cutLineActionTriggerd()));

  switch (editorType) {
  case EditorTypes::SQLQuery:
    fillMariaDBSymbolsAction = new QAction(this);
    fillMariaDBSymbolsAction->setIcon(QIcon(":/images/svg/application-pgp-keys.svg"));
    fillMariaDBSymbolsAction->setShortcut(QKeySequence(Qt::Key_F6));
    connect(fillMariaDBSymbolsAction, SIGNAL(triggered()), this, SLOT(fillMariaDBSymbolsActionSlot()));
    break;
  case EditorTypes::PHP:
    executePHPScriptAction = new QAction(this);
    executePHPScriptAction->setIcon(QIcon(":/images/svg/system-run-5.svg"));
    executePHPScriptAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Return));
    connect(executePHPScriptAction, SIGNAL(triggered()), this, SLOT(executePHPScriptActionSlot()));
    procOutput = new BaseTextEditor(EditorTypes::HTML);
    procOutput->resize(400, 400);
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
  case EditorTypes::CSS:
  case EditorTypes::HTML:
  case EditorTypes::JavaScript:
    break;
  // default: Q_ASSERT(false);
  }

  showMariaDBHelperAction = new QAction(this);
  showMariaDBHelperAction->setIcon(QIcon(":/images/svg/application-x-executable.svg"));
  showMariaDBHelperAction->setCheckable(true);
  showMariaDBHelperAction->setChecked(settings.value("TextEditor/ShowMariaDBHelper", true).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(showMariaDBHelperAction, SIGNAL(triggered()), this, SLOT(showMariaDBHlperActionTriggered()));
  exportoToPdfOrPsAction = new QAction(this);
  exportoToPdfOrPsAction->setIcon(QIcon(":/images/svg/application-pdf.svg"));
  connect(exportoToPdfOrPsAction, SIGNAL(triggered()), this, SLOT(exportoToPdfOrPsActionTriggerd()));
  exportoToOdtAction = new QAction(this);
  exportoToOdtAction->setIcon(QIcon::fromTheme("x-office-document", QIcon(":/images/svg/application-vnd.oasis.opendocument.text.svg")));
  connect(exportoToOdtAction, SIGNAL(triggered()), this, SLOT(exportoToOdtActionTriggerd()));
  exportoToHtmlAction = new QAction(this);
  exportoToHtmlAction->setIcon(QIcon::fromTheme("text-html", QIcon(":/images/svg/application-xhtml.svg")));
  connect(exportoToHtmlAction, SIGNAL(triggered()), this, SLOT(exportoToHtmlActionTriggerd()));
  exportoToSvgAction = new QAction(this);
  exportoToSvgAction->setIcon(QIcon(":/images/svg/image-svg.svg"));
  connect(exportoToSvgAction, SIGNAL(triggered()), this, SLOT(exportoToSvgActionTriggerd()));
  exportoToImgAction = new QAction(this);
  exportoToImgAction->setIcon(QIcon::fromTheme("image-x-generic", QIcon(":/images/svg/image-png.svg")));
  connect(exportoToImgAction, SIGNAL(triggered()), this, SLOT(exportoToImgActionTriggerd()));
  toggleCommentAction = new QAction(this);
  toggleCommentAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Slash));
  connect(toggleCommentAction, SIGNAL(triggered()), this, SLOT(toggleCommentActionTriggerd()));
  highlightCurrentLineAction = new QAction(this);
  highlightCurrentLineAction->setCheckable(true);
  highlightCurrentLineAction->setChecked(settings.value("TextEditor/HighlightCurrentLine", true).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(highlightCurrentLineAction, SIGNAL(triggered()), this, SLOT(highlightCurrentLineActionTriggered()));
  viewNormalAction = new QAction(this);
  viewNormalAction->setIcon(QIcon(":/images/svg/view-close.svg"));
  connect(viewNormalAction, SIGNAL(triggered()), this, SLOT(viewNormalActionTriggered()));
  viewVerticalAction = new QAction(this);
  viewVerticalAction->setIcon(QIcon(":/images/svg/view-split-top-bottom-3.svg"));
  connect(viewVerticalAction, SIGNAL(triggered()), this, SLOT(viewVerticalActionTriggered()));
  viewHorizoltalAction = new QAction(this);
  viewHorizoltalAction->setIcon(QIcon(":/images/svg/view-split-left-right-3.svg"));
  connect(viewHorizoltalAction, SIGNAL(triggered()), this, SLOT(viewHorizoltalActionTriggered()));
  showSymbolsAction = new QAction(this);
  showSymbolsAction->setIcon(QIcon(":/images/svg/application-pgp-keys.svg"));
  showSymbolsAction->setCheckable(true);
  showSymbolsAction->setShortcut(QKeySequence(Qt::Key_F2));
  connect(showSymbolsAction, SIGNAL(triggered(bool)), this, SLOT(showSymbolsActionTriggered(bool)));
  normalizeTextAction = new QAction(this);
  normalizeTextAction->setIcon(QIcon(":/images/svg/application-pgp-keys.svg"));
  connect(normalizeTextAction, SIGNAL(triggered()), this, SLOT(normalizeTextActionTriggered()));

  uppercaseKeywordsAction = new QAction(this);
  connect(uppercaseKeywordsAction, SIGNAL(triggered()), this, SLOT(uppercaseKeywordsActionSlot()));
  lowercaseKeywordsAction = new QAction(this);
  connect(lowercaseKeywordsAction, SIGNAL(triggered()), this, SLOT(lowercaseKeywordsActionSlot()));
}

void TextEditor::showMariaDBHlperActionTriggered()
{
  settings.setValue("TextEditor/ShowMariaDBHelper", showMariaDBHelperAction->isChecked());
}

void TextEditor::highlightCurrentLineActionTriggered()
{
  settings.setValue("TextEditor/HighlightCurrentLine", highlightCurrentLineAction->isChecked());
}

void TextEditor::toggleCommentActionTriggerd()
{
  QTextCursor cursor = textEditor->textCursor();
  cursor.beginEditBlock();

  if (cursor.hasSelection()) {
    QTextDocument *doc = textEditor->document();
    QTextBlock startBlock = doc->findBlock(qMin(cursor.anchor(), cursor.position()));
    QTextBlock endBlock = doc->findBlock(qMax(cursor.anchor(), cursor.position()) - 1).next();
    for (QTextBlock block = startBlock; block != endBlock; block = block.next()) {
      cursor.setPosition(block.position());
      cursor.movePosition(QTextCursor::StartOfLine);
      cursor.select(QTextCursor::LineUnderCursor);
      if (cursor.selectedText().startsWith(commentString()))
        cursor.insertText(cursor.selectedText().right(cursor.selectedText().length() - commentString().length()));
      else
        cursor.insertText(commentString() + cursor.selectedText());
      cursor.movePosition(QTextCursor::StartOfLine);
    }
  } else {
    cursor.movePosition(QTextCursor::StartOfLine);
    cursor.select(QTextCursor::LineUnderCursor);
    if (cursor.selectedText().startsWith(commentString()))
      cursor.insertText(cursor.selectedText().right(cursor.selectedText().length() - commentString().length()));
    else
      cursor.insertText(commentString() + cursor.selectedText());
    textEditor->setTextCursor(cursor);
  }
  cursor.endEditBlock();
}

void TextEditor::cutLineActionTriggerd()
{
  QTextCursor cursor = textEditor->textCursor();
  if (!cursor.hasSelection()) {
    const QTextBlock &block = cursor.block();
    if (block.next().isValid()) {
      cursor.setPosition(block.position());
      cursor.setPosition(block.next().position(), QTextCursor::KeepAnchor);
    } else {
      cursor.movePosition(QTextCursor::EndOfBlock);
      cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::KeepAnchor);
      cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor);
    }
    textEditor->setTextCursor(cursor);
  }
  textEditor->cut();
}

QString TextEditor::commentString()
{
  QString commentCharacters;
  switch(editorType) {
  case EditorTypes::SQLQuery:
    commentCharacters = "-- ";
    break;
  case EditorTypes::PHP:
  case EditorTypes::JavaScript:
    commentCharacters = "// ";
    break;
  case EditorTypes::CSS:
    commentCharacters = "/*";
    break;
  case EditorTypes::HTML:
    commentCharacters = "<!--";
    break;
  case EditorTypes::Diff:
  case EditorTypes::NoEditor:
  default:
    commentCharacters = "";
    Q_ASSERT(false);
  }
  return commentCharacters;
}

bool TextEditor::okToClose()
{
  if (textEditor->document()->isModified()) {
    settings.setValue("TextEditor/PointSize", font().pointSize());
    QMessageBox msgBox;
    switch(editorType) {
    case EditorTypes::SQLQuery:
      settings.setValue("SQLQuery/LastQuery-" + qApp->property("ConnectionName").toString(), textEditor->toPlainText());
      msgBox.setWindowTitle(tr("SQL Query: Save file..."));
      break;
    case EditorTypes::PHP:
      msgBox.setWindowTitle(tr("PHP Script: Save file..."));
      break;
    case EditorTypes::CSS:
      msgBox.setWindowTitle(tr("CSS File: Save file..."));
      break;
    case EditorTypes::HTML:
      msgBox.setWindowTitle(tr("HTML File: Save file..."));
      break;
    case EditorTypes::JavaScript:
      msgBox.setWindowTitle(tr("JavaScript Script: Save file..."));
      break;
    case EditorTypes::Diff:
    case EditorTypes::Commit:
    case EditorTypes::SVNLog:
    case EditorTypes::NoEditor:
      break;
    // default: Q_ASSERT(false);
    }
    int option = QMessageBox::Discard;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save the changes?"));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    option = msgBox.exec();
    switch (option) {
    case QMessageBox::Discard:
      return true;
    case QMessageBox::Save:
      if (saveFileActionTriggered())
        return true;
    case QMessageBox::Cancel:
      return false;
    default:
      return false;
    }
  }
  if (project->openedProject())
    project->saveFileSettings(fileName, textEditor->pointList);
  return true;
}

//void TextEditor::gotoLine(unsigned int lineNumber)
//{
//  QTextCursor cursor(textEditor->document()->findBlockByNumber(lineNumber));
//  cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 0);
//  textEditor->setTextCursor(cursor);
//  textEditor->centerCursor();
//  textEditor->setFocus();
//}

void TextEditor::gotoLineActionGroupTriggered(QAction *action)
{
  textEditor->gotoLine(symbolsLineNumber.value(action->text()));
}

void TextEditor::recentFilesActionGroupTriggered(QAction *action)
{
  openFile(action->text());
}

void TextEditor::clearRecentFilesActionTriggered()
{
  QSettings settings;
  switch(editorType) {
  case EditorTypes::SQLQuery:
    settings.remove("General/RecentMariaDBFiles");
    break;
  case EditorTypes::PHP:
    settings.remove("General/RecentPHPFiles");
    break;
  case EditorTypes::CSS:
    settings.remove("General/RecentCSSFiles");
    break;
  case EditorTypes::HTML:
    settings.remove("General/RecentHTMLFiles");
    break;
  case EditorTypes::JavaScript:
    settings.remove("General/RecentJavaScriptFiles");
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
}

void TextEditor::wordWrapActionToggled()
{
  textEditor->setWordWrapMode(wordWrapAction->isChecked() ? QTextOption::WordWrap : QTextOption::NoWrap);
  readOnlyTextEditor->setWordWrapMode(textEditor->wordWrapMode());
}

void TextEditor::gotoLineActionTriggered()
{
  textEditor->gotoLine(QInputDialog::getInt(this, tr("Go To Line..."), tr("Line number")) - 1);
}

void TextEditor::clear()
{
  lineEditFile->clear();
}

void TextEditor::symbolsMenuAboutToShowSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  symbolsMenu->clear();
  int counter = 0;
  symbolsLineNumber.clear();
  if (editorType == EditorTypes::PHP) {
    foreach (QString line, textEditor->document()->toPlainText().split("\n", QString::KeepEmptyParts)) {
      if (line.contains(QRegExp("^function.*\\("))) {
        symbolsLineNumber.insert(line.mid(line.indexOf("function") + 9, line.indexOf("(") - 9), counter);
        gotoLineActionGroup->addAction(symbolsMenu->addAction(QIcon(":/images/svg/server-database.svg"), line.mid(line.indexOf("function") + 9, line.indexOf("(") - 9)));
      }
      counter++;
    }
  }
  if (editorType == EditorTypes::SQLQuery) {
    QString icon;
    QString symbolName;
    foreach (QString line, textEditor->document()->toPlainText().split("\n", QString::KeepEmptyParts)) {
      icon = "";
      if (line.contains(QRegExp("^CREATE.*TABLE")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*VIEW")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*DATABASE")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*PROCEDURE")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*FUNCTION")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*TRIGGER")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*EVENT")))
        icon = ":/images/svg/server-database.svg";
      if (!icon.isEmpty()) {
        QRegExp expression("^CREATE.*(TABLE |TABLE IF NOT EXISTS |VIEW |DATABASE |PROCEDURE |FUNCTION |TRIGGER |EVENT ).*`[A-Za-z_\\d%]*`\\.{0,1}`[A-Za-z_\\d%]*`{0,1}");
        expression.indexIn(line);
        QRegExp expression2("`[A-Za-z_\\d%]*`\\.`[A-Za-z_\\d%]*`");
        expression2.indexIn(line);
        symbolName = expression2.capturedTexts().at(0);
        if (symbolName.isEmpty()) {
          QRegExp expression3("`[A-Za-z_\\d%]*`");
          expression3.indexIn(line);
          symbolName = expression3.capturedTexts().at(0);
        }
        symbolName = symbolName.replace("`", "");
        symbolsLineNumber.insert(symbolName, counter);
        gotoLineActionGroup->addAction(symbolsMenu->addAction(QIcon(icon), symbolName));

//        symbolsLineNumber.insert(symbolName, counter);
//        listSymbols->addItem(new QListWidgetItem(QIcon(icon), symbolName));
      }
      counter++;
    }

//    foreach (QString line, textEditor->document()->toPlainText().split("\n", QString::KeepEmptyParts)) {
//      icon = "";
//      if (line.contains(QRegExp("^CREATE.*(TABLE `|TABLE IF NOT EXISTS `)")))
//        icon = ":/images/svg/server-database.svg";
//      if (line.contains(QRegExp("^CREATE.*VIEW `")))
//        icon = ":/images/svg/server-database.svg";
//      if (line.contains(QRegExp("^CREATE.*DATABASE `")))
//        icon = ":/images/svg/server-database.svg";
//      if (line.contains(QRegExp("^CREATE.*PROCEDURE `")))
//        icon = ":/images/svg/server-database.svg";
//      if (line.contains(QRegExp("^CREATE.*FUNCTION `")))
//        icon = ":/images/svg/server-database.svg";
//      if (line.contains(QRegExp("^CREATE.*TRIGGER `")))
//        icon = ":/images/svg/server-database.svg";
//      if (line.contains(QRegExp("^CREATE.*EVENT `")))
//        icon = ":/images/svg/server-database.svg";
//      if (!icon.isEmpty()) {
//        symbolsLineNumber.insert(line.mid(line.indexOf("`") + 1, line.indexOf("`", line.indexOf("`") + 1) - line.indexOf("`") -1 ), counter);
//        gotoLineActionGroup->addAction(symbolsMenu->addAction(QIcon(icon), line.mid(line.indexOf("`") + 1, line.indexOf("`", line.indexOf("`") + 1) - line.indexOf("`") - 1 )));
//      }
//      counter++;
//    }
  }
  QApplication::restoreOverrideCursor();
}

void TextEditor::contextMenuEvent(QContextMenuEvent *event)
{
  contextualMenu->exec(event->globalPos());
}

void TextEditor::openFileActionTriggered()
{
  openFile();
}

QString TextEditor::fileExtention()
{
  QString type;
  switch(editorType) {
  case EditorTypes::SQLQuery:
    type = tr("SQL files (*.sql)");
    break;
  case EditorTypes::PHP:
    type = tr("PHP files (*.php *.inc *.module)");
    break;
  case EditorTypes::CSS:
    type = tr("CSS files (*.css)");
    break;
  case EditorTypes::HTML:
    type = tr("HTML files (*.html *.htm)");
    break;
  case EditorTypes::JavaScript:
    type = tr("JavaScript files (*.js)");
    break;
  default:
    type = "";
    break;
  }
  return type;
}

void TextEditor::openFile(QString file)
{
  if (file.isEmpty()) {
    QFileDialog fileDialog;
    fileDialog.setDirectory(QDir::home());
    fileName = fileDialog.getOpenFileName(this, tr("Open a file"), settings.value("General/LastPath", QDir::home().absolutePath()).toString(), fileExtention());
    settings.setValue("General/LastPath", fileDialog.directory().filePath(fileName));
  } else {
    fileName = file;
  }
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFile fileToOpen(fileName);
  if (!fileToOpen.open(QFile::ReadWrite | QFile::Text))
    emit statusBarMessage(tr("Cannot read file %1:\n%2.").arg(fileName).arg(fileToOpen.errorString()), QSystemTrayIcon::Critical);
  textEditor->setPlainText(QString::fromUtf8(fileToOpen.readAll()));
  fileToOpen.close();
  updateRecentFiles(fileName);
  lineEditFile->setText(fileName);
  updateReadOnlyEditor();
  QFileInfo fileInfo(fileName);
  emit changeTitle(fileInfo.completeBaseName() + "." + fileInfo.completeSuffix());
  if (project->openedProject())
    textEditor->pointList = project->getFileSettings(fileName);
  subversionedFile->fileName = fileName;
  QApplication::restoreOverrideCursor();
}

QList<QAction *> TextEditor::viewActionList()
{
  QList<QAction *> actionsList;
  QMenu *menu = new QMenu;
  QAction *separator = menu->addSeparator();
  separator->setText(tr("Zoom"));
  actionsList.append(separator);
  actionsList.append(zoomInAction);
  actionsList.append(zoomOutAction);
  actionsList.append(restoreZoomAction);
  return actionsList;
}

QList<QAction *> TextEditor::fileActionList()
{
  QList<QAction *> actionsList;
  actionsList.append(openAction);
  actionsList.append(saveAction);
  actionsList.append(saveAsAction);
  actionsList.append(clearAction);
  return actionsList;
}

void TextEditor::changeTextCase(bool uppercse)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  gotoLine(0);
  QTextCursor cursor = textEditor->document()->find(QRegExp("\\b\\w+\\b", Qt::CaseInsensitive), textEditor->textCursor(), QTextDocument::FindWholeWords);
  while (cursor.hasSelection()) {
    if (StaticFunctions::currentEditorTypeKeywords(editorType).contains(cursor.selectedText(), Qt::CaseInsensitive)) {
      if (uppercse)
        cursor.insertText(cursor.selectedText().toUpper());
      else
        cursor.insertText(cursor.selectedText().toLower());
    }
    textEditor->setTextCursor(cursor);
    cursor = textEditor->document()->find(QRegExp("\\b\\w+\\b", Qt::CaseInsensitive), textEditor->textCursor(), QTextDocument::FindWholeWords);
  }
  gotoLine(0);
  QApplication::restoreOverrideCursor();
}

QList<QAction *> TextEditor::editActionList()
{
  QList<QAction *> actionsList;
  QMenu *menu = new QMenu;
  actionsList.append(copyAction);
  actionsList.append(cutAction);
  actionsList.append(pasteAction);
  actionsList.append(undoAction);
  actionsList.append(redoAction);
  actionsList.append(menu->addSeparator());
  actionsList.append(textEditor->indentAction);
  actionsList.append(textEditor->unidentAction);
  actionsList.append(menu->addSeparator());
//  actionsList.append(disableCompletionAction);
  actionsList.append(showHideLineNumbersAction);
  actionsList.append(menu->addSeparator());
  actionsList.append(cutLineAction);
  actionsList.append(toggleCommentAction);
  actionsList.append(menu->addSeparator());
  actionsList.append(wordWrapAction);
  actionsList.append(uppercaseKeywordsAction);
  actionsList.append(lowercaseKeywordsAction);
  actionsList.append(textEditor->visualizeSpacesAction);
  //->setText(tr("Line"))
  actionsList.append(menu->addSeparator());
  actionsList.append(gotoLineAction);
  actionsList.append(highlightCurrentLineAction);
  actionsList.append(normalizeTextAction);
  actionsList.append(textEditor->insertLicenceTamplateAction);
  return actionsList;
}

void TextEditor::modificationChangedSlot(bool changed)
{
  Q_UNUSED(changed);
//  if (changed)
//    parentWidget2->dTitleLabel->setTitleText(parentWidget2->dTitleLabel->text() + "*");
//  else
//    parentWidget2->dTitleLabel->setTitleText(parentWidget2->dTitleLabel->text().left(parentWidget2->dTitleLabel->text().length() -1));
}

//void TextEditor::indentActionTriggered()
//{
//  indentOrUnindent(true);
//}

//void TextEditor::indentOrUnindent(bool doIndent)
//{
//  QTextCursor cursor = textEditor->textCursor();
//  cursor.beginEditBlock();

//  if (cursor.hasSelection()) {
//    int pos = cursor.position();
//    int anchor = cursor.anchor();
//    int start = qMin(anchor, pos);
//    int end = qMax(anchor, pos);

//    QTextDocument *doc = textEditor->document();
//    QTextBlock startBlock = doc->findBlock(start);
//    QTextBlock endBlock = doc->findBlock(end - 1).next();

//    for (QTextBlock block = startBlock; block != endBlock; block = block.next()) {
//      QString text(block.text());
//      int indentPosition = lineIndentPosition(text);
//      if (!doIndent && !indentPosition)
//        indentPosition = firstNonSpace(text);
//      int targetColumn = indentedColumn(columnAt(text, indentPosition), doIndent);
//      cursor.setPosition(block.position() + indentPosition);
//      cursor.insertText(indentationString(0, targetColumn, block));
//      cursor.setPosition(block.position());
//      cursor.setPosition(block.position() + indentPosition, QTextCursor::KeepAnchor);
//      cursor.removeSelectedText();
//    }
//  } else {
//    QTextBlock block = cursor.block();
//    QString text(block.text());
//    int indentPosition = cursor.position() - block.position();
//    int spaces = spacesLeftFromPosition(text, indentPosition);
//    int startColumn = columnAt(text, indentPosition - spaces);
//    int targetColumn = indentedColumn(columnAt(text, indentPosition), doIndent);
//    cursor.setPosition(block.position() + indentPosition);
//    cursor.setPosition(block.position() + indentPosition - spaces, QTextCursor::KeepAnchor);
//    cursor.removeSelectedText();
//    cursor.insertText(indentationString(startColumn, targetColumn, block));
//    textEditor->setTextCursor(cursor);
//  }
//  cursor.endEditBlock();
//}

//int TextEditor::spacesLeftFromPosition(const QString &text, int position) const
//{
//  int pos = position;
//  while (pos > 0) {
//    if (!text.at(pos-1).isSpace())
//      break;
//    --pos;
//  }
//  return position - pos;
//}

//QString TextEditor::indentationString(int startColumn, int targetColumn, const QTextBlock &block) const
//{
//  targetColumn = qMax(startColumn, targetColumn);
//  if (guessSpacesForTabs(block))
//    return QString(targetColumn - startColumn, QLatin1Char(' '));

//  QString s;
//  int alignedStart = startColumn - (startColumn % settings.value("TextEditor/TabSize", 2).toInt())
//      + settings.value("TextEditor/TabSize", 2).toInt();
//  if (alignedStart > startColumn && alignedStart <= targetColumn) {
//    s += QLatin1Char('\t');
//    startColumn = alignedStart;
//  }
//  if (int columns = targetColumn - startColumn) {
//    int tabs = columns / settings.value("TextEditor/TabSize", 2).toInt();
//    s += QString(tabs, QLatin1Char('\t'));
//    s += QString(columns - tabs * settings.value("TextEditor/TabSize", 2).toInt(), QLatin1Char(' '));
//  }
//  return s;
//}

//bool TextEditor::guessSpacesForTabs(const QTextBlock &block) const
//{
//  if (block.isValid()) {
//    const QTextDocument *doc = block.document();
//    QVector<QTextBlock> currentBlocks(2, block);
//    int maxLookAround = 100;
//    while (maxLookAround-- > 0) {
//      if (currentBlocks.at(0).isValid())
//        currentBlocks[0] = currentBlocks.at(0).previous();
//      if (currentBlocks.at(1).isValid())
//        currentBlocks[1] = currentBlocks.at(1).next();
//      bool done = true;
//      foreach (const QTextBlock &block, currentBlocks) {
//        if (block.isValid())
//          done = false;
//        if (!block.isValid() || block.length() == 0)
//          continue;
//        const QChar firstChar = doc->characterAt(block.position());
//        if (firstChar == QLatin1Char(' ')) {
//          return true;
//        } else if (firstChar == QLatin1Char('\t')) {
//          return false;
//        }
//      }
//      if (done)
//        break;
//    }
//  }
//  return true;
//}

//QString TextEditor::indentationString(const QString &text) const
//{
//  return text.left(firstNonSpace(text));
//}

//int TextEditor::indentationColumn(const QString &text) const
//{
//  return columnAt(text, firstNonSpace(text));
//}

//int TextEditor::indentedColumn(int column, bool doIndent) const
//{
//  int aligned = (column / settings.value("TextEditor/TabSize", 2).toInt()) * settings.value("TextEditor/TabSize", 2).toInt();
//  if (doIndent)
//    return aligned + settings.value("TextEditor/TabSize", 2).toInt();
//  if (aligned < column)
//    return aligned;
//  return qMax(0, aligned - settings.value("TextEditor/TabSize", 2).toInt());
//}

//int TextEditor::lineIndentPosition(const QString &text) const
//{
//  int i = 0;
//  while (i < text.size()) {
//    if (!text.at(i).isSpace())
//      break;
//    ++i;
//  }
//  int column = columnAt(text, i);
//  return i - (column % settings.value("TextEditor/TabSize", 2).toInt());
//}

//int TextEditor::firstNonSpace(const QString &text) const
//{
//  int i = 0;
//  while (i < text.size()) {
//    if (!text.at(i).isSpace())
//      return i;
//    ++i;
//  }
//  return i;
//}

//void TextEditor::unidentActionTriggered()
//{
//  indentOrUnindent(false);
//}

void TextEditor::wheelEvent(QWheelEvent *e)
{
  if (e->modifiers() == Qt::ControlModifier) {
    if (e->delta() > 0)
      zoomIn();
    else
      if (e->delta() < 0)
        zoomOut();
  }
  QWidget::wheelEvent(e);
}

void TextEditor::zoomIn()
{
  newFont = textEditor->font();
  newFont.setPointSize(textEditor->font().pointSize() + 1);
  settings.setValue("TextEditor/PointSize", newFont.pointSize());
  setFontToWidgets(newFont);
}

void TextEditor::zoomOut()
{
  newFont = textEditor->font();
  newFont.setPointSize(textEditor->font().pointSize() - 1);
  settings.setValue("TextEditor/PointSize", newFont.pointSize());
  setFontToWidgets(newFont);
}

void TextEditor::zoomReset()
{
  newFont = textEditor->font();
  newFont.setPointSize(settings.value("TextEditor/DefaultPointSize", 11).toInt());
  settings.setValue("TextEditor/PointSize", settings.value("TextEditor/DefaultPointSize", 11).toInt());
  setFontToWidgets(newFont);
}

void TextEditor::setFontToWidgets(const QFont &)
{
  textEditor->setFont(newFont);
  textEditor->lineNumberArea->setFont(newFont);
  completer->popup()->setFont(newFont);
  readOnlyTextEditor->setFont(newFont);
  readOnlyTextEditor->lineNumberArea->setFont(newFont);
}

void TextEditor::exportoToPdfOrPsActionTriggerd()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString file = fileDialog.getSaveFileName(this, tr("Save to Pdf"), settings.value("General/LastFilePdf", QDir::home().absolutePath()).toString(), tr("Pdf & Ps files (*.pdf *.ps)"));
  settings.setValue("General/LastFilePdf", fileDialog.directory().filePath(file));
  QPrinter printer(QPrinter::HighResolution);
  printer.setOutputFileName(file);
  printer.setOutputFormat(file.endsWith(".pdf") ? QPrinter::PdfFormat : QPrinter::NativeFormat);
  textEditor->document()->print(&printer);
  QApplication::restoreOverrideCursor();
  emit statusBarMessage(tr("File saved at: %1").arg(file));
}

void TextEditor::exportoToOdtActionTriggerd()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString file = fileDialog.getSaveFileName(this, tr("Save to Odt"), settings.value("General/LastFileOdt", QDir::home().absolutePath()).toString(), tr("Odt files (*.odt)"));
  settings.setValue("General/LastFileOdt", fileDialog.directory().filePath(file));
  QTextDocumentWriter writer(file);
  writer.write(textEditor->document());
  QApplication::restoreOverrideCursor();
  emit statusBarMessage(tr("File saved at: %1").arg(file));
}

void TextEditor::exportoToHtmlActionTriggerd()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString file = fileDialog.getSaveFileName(this, tr("Save to Html"), settings.value("General/LastFileHtml", QDir::home().absolutePath()).toString(), tr("Html files (*.html *.htm)"));
  settings.setValue("General/LastFileHtml", fileDialog.directory().filePath(file));
  QFile fileOut(file);
  if (!fileOut.open(QIODevice::WriteOnly|QIODevice::Text))
    emit statusBarMessage(tr("Cannot write file %1:\n%2.").arg(file).arg(fileOut.errorString()), QSystemTrayIcon::Critical);
  QTextStream out(&fileOut);
  out.setCodec("utf-8");
  out << textEditor->document()->toHtml("utf-8");
  fileOut.close();
  QApplication::restoreOverrideCursor();
  emit statusBarMessage(tr("File saved at: %1").arg(file));
}

void TextEditor::exportoToSvgActionTriggerd()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString file = fileDialog.getSaveFileName(this, tr("Save to Svg"), settings.value("General/LastFileSvg", QDir::home().absolutePath()).toString(), tr("Svg files (*.svg)"));
  settings.setValue("General/LastFileSvg", fileDialog.directory().filePath(file));
  QSvgGenerator svg;
  svg.setFileName(file);
  QTextDocument *doc = textEditor->document()->clone();
  QRect rectSize(0, 0, (int) doc->size().width(), (int) doc->size().height());
  QPainter painter(&svg);
  painter.setViewport(rectSize);
  doc->documentLayout()->setPaintDevice(&svg);
  doc->drawContents(&painter);
  QApplication::restoreOverrideCursor();
  emit statusBarMessage(tr("File saved at: %1").arg(file));
}

void TextEditor::exportoToImgActionTriggerd()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString imageFormats;
  foreach(QString format, QImageWriter::supportedImageFormats())
    imageFormats += "*." + format + " ";
  QString file = fileDialog.getSaveFileName(this, tr("Save to Image"), settings.value("General/LastFileImg", QDir::home().absolutePath()).toString(), tr("Image files (%1)").arg(imageFormats));
  settings.setValue("General/LastFileImg", fileDialog.directory().filePath(file));
  QTextDocument *doc = textEditor->document()->clone();
  QImage image(QRect(0, 0, (int) doc->size().width(), (int) doc->size().height()).size(), QImage::Format_ARGB32);
  QPainter painter(&image);
  painter.setRenderHints(QPainter::Antialiasing| QPainter::TextAntialiasing);
  painter.fillRect(painter.viewport(), Qt::white);
  painter.setViewport(printer.paperRect());
  doc->documentLayout()->setPaintDevice(&image);
  doc->drawContents(&painter);
  image.save(file);
  QApplication::restoreOverrideCursor();
  emit statusBarMessage(tr("File saved at: %1").arg(file));
}

bool TextEditor::event(QEvent *event)
{
  switch (event->type()) {
  case QEvent::WhatsThis: {
    QHelpEvent* helpEvent = static_cast<QHelpEvent*>(event);
    QTextCursor cursor = textEditor->cursorForPosition(QPoint(helpEvent->x() - (textEditor->lineNumberAreaWidth() + 5), helpEvent->y() - (menuBar->height() + 5 + (dTitleLabel->isVisible() ? (dTitleLabel->height() + 5) : 0))));
    cursor.select(QTextCursor::WordUnderCursor);
    QString message = "<table><tr><td><img src=\":/images/svg/server-database.svg\" width=\"48\"></td><td valign=middle><p style='white-space:pre'><a href='%1'>%2</a></p></td></tr></table>";
    QString matchedValue = QString();
    QString url = QString();
    switch(editorType) {
    case EditorTypes::SQLQuery:
      switch(qApp->property("DBMSType").toInt()) {
      case StaticFunctions::MySQL:
      case StaticFunctions::MariaDB:
        matchedValue = StaticFunctions::mariadbFunctionsComplete().value(cursor.selectedText().toUpper());
        url = "https://mariadb.com/kb/en/" + cursor.selectedText().toLower() + "/";
        break;
      case StaticFunctions::PostgreSQL:
        matchedValue = StaticFunctions::postgresqlFunctionsComplete().value(cursor.selectedText().toLower());
        break;
      case StaticFunctions::Undefined:
      default:
        break;
      }
      break;
    case EditorTypes::PHP:
      matchedValue = StaticFunctions::phpFunctionsComplete().value(cursor.selectedText().toLower());
      if (matchedValue.isEmpty())
        matchedValue = project->getProjectFunctionListComplete().value(cursor.selectedText());
      url = "http://php.net/manual/en/function." + cursor.selectedText().toLower() + ".php";
      break;
    case EditorTypes::HTML:
      matchedValue = StaticFunctions::htmlTagsComplete().value(cursor.selectedText().toLower());
      break;
    case EditorTypes::JavaScript:
      matchedValue = StaticFunctions::javascriptFunctionsComplete().value(cursor.selectedText().toLower());
      break;
    case EditorTypes::CSS:
      matchedValue = StaticFunctions::cssPropertiesComplete().value(cursor.selectedText().toLower());
      break;
    case EditorTypes::Diff:
    case EditorTypes::Commit:
    case EditorTypes::SVNLog:
    case EditorTypes::NoEditor:
      break;
      // default: Q_ASSERT(false);
    }
    if (!matchedValue.isEmpty())
      QWhatsThis::showText(helpEvent->globalPos(), message.arg(url).arg(matchedValue), this);
    event->accept();
  }
    break;
  case QEvent::WhatsThisClicked: {
    QWhatsThisClickedEvent *whatsThisEvent = static_cast<QWhatsThisClickedEvent*>(event);
    QWhatsThis::hideText();
    //emit linkClicked( wtcEvent->href() );
    emit openURL(whatsThisEvent->href());
    event->accept();
  }
    break;
  case QEvent::ToolTip: {
    QHelpEvent* helpEvent = static_cast<QHelpEvent*>(event);
    QTextCursor cursor = textEditor->cursorForPosition(QPoint(helpEvent->x() - (textEditor->lineNumberAreaWidth() + 5), helpEvent->y() - (menuBar->height() + 5 + (dTitleLabel->isVisible() ? (dTitleLabel->height() + 5) : 0))));
    cursor.select(QTextCursor::WordUnderCursor);
    QString message = "<table><tr><td><img src=\":/images/svg/server-database.svg\" width=\"48\"></td><td valign=middle><p style='white-space:pre'>%1</p></td></tr></table>";
    QString matchedValue = QString();
    switch(editorType) {
    case EditorTypes::SQLQuery:
      switch(qApp->property("DBMSType").toInt()) {
      case StaticFunctions::MySQL:
      case StaticFunctions::MariaDB:
        matchedValue = StaticFunctions::mariadbFunctionsComplete().value(cursor.selectedText().toUpper());
        break;
      case StaticFunctions::PostgreSQL:
        matchedValue = StaticFunctions::postgresqlFunctionsComplete().value(cursor.selectedText().toLower());
        break;
      case StaticFunctions::Undefined:
      default:
        break;
      }
      break;
    case EditorTypes::PHP:
      matchedValue = StaticFunctions::phpFunctionsComplete().value(cursor.selectedText().toLower());
      if (matchedValue.isEmpty())
        matchedValue = project->getProjectFunctionListComplete().value(cursor.selectedText());
      break;
    case EditorTypes::HTML:
      matchedValue = StaticFunctions::htmlTagsComplete().value(cursor.selectedText().toLower());
      break;
    case EditorTypes::JavaScript:
      matchedValue = StaticFunctions::javascriptFunctionsComplete().value(cursor.selectedText().toLower());
      break;
    case EditorTypes::CSS:
      matchedValue = StaticFunctions::cssPropertiesComplete().value(cursor.selectedText().toLower());
      break;
    case EditorTypes::Diff:
    case EditorTypes::Commit:
    case EditorTypes::SVNLog:
    case EditorTypes::NoEditor:
      break;
      // default: Q_ASSERT(false);
    }
    if (!matchedValue.isEmpty())
      QToolTip::showText(helpEvent->globalPos(), message.arg(matchedValue), this);
    event->accept();
  }
    break;
  default:
    break;
  }
  return QMdiSubWindow::event(event);
}

//void TextEditor::showEvent(QShowEvent *event)
//{
//  textEditor->setFocus();
//  //QWidget::showEvent(event);
//  QMdiSubWindow::event(event);
//}

void TextEditor::closeEvent(QCloseEvent *event)
{
  if (okToClose())
    event->accept();
  else
    event->ignore();
}

///*! \brief Try to close the widgets and set the focus
// * to the Editor.
// *
// */
//void TextEditor::setFocusToEditorActionTriggered()
//{
//  qDebug() << "asdf";
//  if (findReplace->isVisible())
//    findReplace->hide();
//  setFocus(Qt::OtherFocusReason);
//}

void TextEditor::createMenu()
{
  menuBar = new QMenuBar;
  fileMenu = new QMenu(" ");
  menuBar->addMenu(fileMenu);
  fileMenu->addActions(fileActionList());
  fileMenu->addSeparator();
  fileMenu->addAction(printAction);
  fileMenu->addSeparator();
  fileMenu->addMenu(exportMenu);
  fileMenu->addSeparator();
  fileMenu->addMenu(openRecentFilesMenu);

  editMenu = new QMenu;
  menuBar->addMenu(editMenu);
  editMenu->addActions(editActionList());
  editMenu->addSeparator();
  editMenu->addAction(findReplace->toggleViewAction());

  optionsMenu = new QMenu;
  menuBar->addMenu(optionsMenu);
  optionsMenu->addAction(disableCompletionAction);

  switch (editorType) {
  case EditorTypes::SQLQuery:
    optionsMenu->addSeparator();
    optionsMenu->addAction(fillMariaDBSymbolsAction);
    optionsMenu->addAction(showMariaDBHelperAction);
    break;
  case EditorTypes::PHP:
    optionsMenu->addSeparator();
    optionsMenu->addAction(executePHPScriptAction);
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
  case EditorTypes::CSS:
  case EditorTypes::HTML:
  case EditorTypes::JavaScript:
    break;
  // default: Q_ASSERT(false);
  }

  subversionMenu = new QMenu;
  menuBar->addMenu(subversionMenu);
  subversionMenu->addActions(subversionedFile->getActions());

  viewMenu = new QMenu;
  menuBar->addMenu(viewMenu);
  viewMenu->addAction(mainToolBar->toggleViewAction());
  viewMenu->addActions(viewActionList());
  viewMenuSeparatorActionView = viewMenu->addSeparator();
  viewMenu->addAction(viewNormalAction);
  viewMenu->addAction(viewHorizoltalAction);
  viewMenu->addAction(viewVerticalAction);
  viewMenuSeparatorActionSymbols = viewMenu->addSeparator();
  viewMenu->addAction(showSymbolsAction);

  menuBar->setMaximumHeight(menuBar->sizeHint().rheight());
}

/*! \brief Toolbar creation.
 *
 */
void TextEditor::createToolBars()
{
  mainToolBar = new QToolBar;
  lineEditFile = new QLineEdit(fileName);
  lineEditFile->setReadOnly(true);
  mainToolBar->addWidget(lineEditFile);
  mainToolBar->addSeparator();
  mainToolBar->addAction(showSymbolsAction);
  mainToolBar->addSeparator();
  labelPosition = new QLabel(" 0 : 0 ");
  labelPosition->setAlignment(Qt::AlignCenter);
  labelPosition->setFrameShape(QFrame::Box);
  labelPosition->setFrameShadow(QFrame::Sunken);
  mainToolBar->addWidget(labelPosition);
  mainToolBar->setIconSize(QSize(18, 18));
  mainToolBar->hide();
}

void TextEditor::viewNormalActionTriggered()
{
  secondSplitter->widget(1)->hide();
}

void TextEditor::viewVerticalActionTriggered()
{
  secondSplitter->setOrientation(Qt::Vertical);
  secondSplitter->widget(1)->show();
  updateReadOnlyEditor();
}

void TextEditor::viewHorizoltalActionTriggered()
{
  secondSplitter->setOrientation(Qt::Horizontal);
  secondSplitter->widget(1)->show();
  updateReadOnlyEditor();
}

void TextEditor::itemClickedSlot(QListWidgetItem *item)
{
  textEditor->gotoLine(symbolsLineNumber.value(item->text()));
}

void TextEditor::sortSymbolsSlot()
{
  listSymbols->sortItems(Qt::AscendingOrder);
}

void TextEditor::normalizeTextActionTriggered()
{
  bool found = true;
  while (found) {
    QTextCursor cursor = textEditor->document()->find(QRegExp(":(\\w|#|\")", Qt::CaseInsensitive));
    if (!cursor.hasSelection())
      found = false;
    cursor.setPosition(cursor.position() - 2);
    cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
    cursor.insertText(": ");
  }
}

void TextEditor::executePHPScriptActionSlot()
{
  proc = new QProcess;

//  ini_set('display_errors', 'On');
//  error_reporting(E_ALL | E_STRICT);

  connect(proc, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutputSlot()));
//  connect(proc, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardErrorSlot()));
//  connect(proc, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finishedSlot(int)));
  QStringList arguments;
  arguments << "--file=" + fileName;
//  arguments << "-s";
//  arguments << "--timing";

  procOutput->clear();
  saveFileActionTriggered();
  QApplication::setOverrideCursor(Qt::WaitCursor);
  procOutput->show();
  proc->start(settings.value("PHP/Executable", "/usr/bin/php").toString(), arguments);
  proc->waitForFinished();
  QApplication::restoreOverrideCursor();
}

void TextEditor::readyReadStandardOutputSlot()
{
  procOutput->insertPlainText(proc->readAllStandardOutput());
}

void TextEditor::updateCursorPositionSlot()
{
  labelPosition->setText(QString(" %1 : %2 ").arg(textEditor->textCursor().block().blockNumber() + 1).arg(textEditor->textCursor().columnNumber() + 1));
  emit updatePrositionViewer(textEditor->textCursor().block().blockNumber(), textEditor->textCursor().columnNumber());
  if (settings.value("TextEditor/HighlightCurrentLine", true).toBool())
    textEditor->highlightCurrentLine();
  matchBracket();
}

void TextEditor::showSymbolsActionTriggered(bool checked)
{
  showSymbolsAction->setChecked(checked);
  listSymbols->setVisible(checked);
  if (!showSymbolsAction->isChecked())
    return;
  QApplication::setOverrideCursor(Qt::WaitCursor);
  int counter = 0;
  listSymbols->clear();
  symbolsLineNumber.clear();
  QString icon;
  QString symbolName;
  switch(editorType) {
  case EditorTypes::PHP:
  case EditorTypes::JavaScript:
    foreach (QString line, textEditor->document()->toPlainText().split("\n", QString::KeepEmptyParts)) {
      if (line.contains(QRegExp("^function.*\\("))) {
        symbolsLineNumber.insert(line.mid(9, line.indexOf("(") - 9), counter);
        listSymbols->addItem(new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), line.mid(9, line.indexOf("(") - 9)));
      }
      counter++;
    }
    break;
  case EditorTypes::SQLQuery:
    foreach (QString line, textEditor->document()->toPlainText().split("\n", QString::KeepEmptyParts)) {
      icon = "";
      if (line.contains(QRegExp("^CREATE.*TABLE")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*VIEW")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*DATABASE")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*PROCEDURE")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*FUNCTION")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*TRIGGER")))
        icon = ":/images/svg/server-database.svg";
      if (line.contains(QRegExp("^CREATE.*EVENT")))
        icon = ":/images/svg/server-database.svg";
      if (!icon.isEmpty()) {
        QRegExp expression("^CREATE.*(TABLE |TABLE IF NOT EXISTS |VIEW |DATABASE |PROCEDURE |FUNCTION |TRIGGER |EVENT ).*`[A-Za-z_\\d%]*`\\.{0,1}`[A-Za-z_\\d%]*`{0,1}");
        expression.indexIn(line);
        QRegExp expression2("`[A-Za-z_\\d%]*`\\.`[A-Za-z_\\d%]*`");
        expression2.indexIn(line);
        symbolName = expression2.capturedTexts().at(0);
        if (symbolName.isEmpty()) {
          QRegExp expression3("`[A-Za-z_\\d%]*`");
          expression3.indexIn(line);
          symbolName = expression3.capturedTexts().at(0);
        }
        symbolName = symbolName.replace("`", "");
        symbolsLineNumber.insert(symbolName, counter);
        listSymbols->addItem(new QListWidgetItem(QIcon(icon), symbolName));
      }
      counter++;
    }
    break;
  case EditorTypes::CSS:
    foreach (QString line, textEditor->document()->toPlainText().split("\n", QString::KeepEmptyParts)) {
      if (line.contains(QRegExp("^(\\.|#)"))) {
        symbolsLineNumber.insert(line.mid(0, line.indexOf("{")), counter);
        listSymbols->addItem(new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), line.mid(0, line.indexOf("{"))));
      }
      counter++;
    }
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
  case EditorTypes::HTML:
    break;
  // default: Q_ASSERT(false);
  }
  QApplication::restoreOverrideCursor();
}

void TextEditor::updateReadOnlyEditor()
{
  if (readOnlyTextEditor->isVisible())
    readOnlyTextEditor->setPlainText(textEditor->toPlainText());
}

//void TextEditor::openFile(QString file)
//{
//  textEditor->openFile(file);
//}

void TextEditor::fillMariaDBSymbols()
{
  fillMariaDBSymbolsActionSlot();
}
