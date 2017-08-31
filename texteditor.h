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

#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QSettings>
#include <QSystemTrayIcon>
#include <QPrinter>
#include <QWidget>

#include "editortypes.h"
//#include "dmdisubwindow.h"

class QCompleter;
class QStandardItemModel;
class QToolBar;
class QSignalMapper;
class QActionGroup;
class Projects;
class DToolTip;
class SubversionedFile;
class QMenuBar;
class FindReplace;
class QSplitter;
class QListWidget;
class QListWidgetItem;
class QLineEdit;
class QLabel;
class QMenu;
class QAction;
class BaseTextEditor;
class QTextBlock;
class QProcess;
class DTitleLabel;
class DBMS;
class QTextDocument;

class TextEditor : public QWidget
{
  Q_OBJECT

public:
  TextEditor(Projects *project, DBMS *serverConnection, EditorTypes::EditorType type, unsigned int windowCount = 0, bool hideTitle = false);
  bool okToClose();
//  void gotoLine(unsigned int lineNumber = 0);
  QString fileName;
  void openFile(QString file = QString());
  QAction *reloadFile;
  BaseTextEditor *textEditor;
  void gotoLine(unsigned int line);
  void retranslateUi();
  void setPlainText(const QString &text);
  QTextDocument *document();

protected:
//  void keyPressEvent(QKeyEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void contextMenuEvent(QContextMenuEvent *event);
  void wheelEvent(QWheelEvent *e);
  bool event(QEvent *event);
//  void showEvent(QShowEvent *event);
//  void closeEvent(QCloseEvent *event);
//  void closeEvent(QCloseEvent *event);

signals:
  void changeTitle(QString title);
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 0);
  void updatePrositionViewer(const int x, const int y);
  void openURL(QString url);
  void windowClosed();

public slots:
  bool saveFileActionTriggered();
  bool saveFileAsActionTriggered();
  void openFileActionTriggered();
  void clear();
  void cutLineActionTriggerd();
  void fillMariaDBSymbolsActionSlot();
  void viewNormalActionTriggered();
  void viewVerticalActionTriggered();
  void viewHorizoltalActionTriggered();

private slots:
  void insertCompletion(const QString &completion);
  void performCompletion();
  void wordWrapActionToggled();
  void zoomIn();
  void zoomOut();
  void zoomReset();
  void gotoLineActionTriggered();
  void symbolsMenuAboutToShowSlot();
  void openRecentFilesMenuAboutToShowSlot();
  void clearRecentFilesActionTriggered();
  void recentFilesActionGroupTriggered(QAction *action);
  void gotoLineActionGroupTriggered(QAction *action);
  void printActionTriggerd();
  void reloadFileActionTriggerd();
  void modificationChangedSlot(bool changed);
  void exportoToPdfOrPsActionTriggerd();
  void exportoToOdtActionTriggerd();
  void exportoToHtmlActionTriggerd();
  void exportoToSvgActionTriggerd();
  void exportoToImgActionTriggerd();
  void matchBracket();
  void toggleCommentActionTriggerd();
  void showMariaDBHlperActionTriggered();
  void highlightCurrentLineActionTriggered();
  void updateCursorPositionSlot();
  void showSymbolsActionTriggered(bool checked = false);
  void itemClickedSlot(QListWidgetItem *item);
  void sortSymbolsSlot();
  void normalizeTextActionTriggered();
  void readyReadStandardOutputSlot();
  void setTitle(QString title);
  void uppercaseKeywordsActionSlot();
  void lowercaseKeywordsActionSlot();
  void performPeriodCompletion(const QString &completionPrefix);
  void insertCompletionForPeriodCompeltion(const QString &completion);
  void readyReadStandardErrorSlot();
  void performCodeSnippetCompletion();
  void insertCompletionCodeSnippet(const QString &completion);

private:
  DBMS *serverConnection;
  QCompleter *completer;
  bool completedAndSelected;
  void performCompletion(const QString &completionPrefix);
  void populateModel(const QString &completionPrefix);
  QStandardItemModel *model;
  QStringList keywords();
  QStringList functions();
  QStringList datatypes();
  QStringList charsets();
  void createActions();
  Projects *project;
  EditorTypes::EditorType editorType;
  QHash<QString, int> symbolsLineNumber;
  void updateRecentFiles(QString fileToSave = QString());
  QSettings settings;
  QFont newFont;
  void setFontToWidgets(const QFont &);
  bool saveAs;
  QString fileExtention();
  QStringList databaseSymbols;
  bool matchLeftBracket(QTextBlock currentBlock, int index, int numLeftBracket, const char leftBracket);
  bool matchRightBracket(QTextBlock currentBlock, int index, int numRightBracket, const char rightBracket, bool firstTime = false);
  void createBracketSelection(int pos);
  QPrinter printer;
  QAction *copyAction;
  QAction *cutAction;
  QAction *cutLineAction;
  QAction *pasteAction;
  QAction *undoAction;
  QAction *redoAction;
  QAction *showHideLineNumbersAction;
  QAction *wordWrapAction;
  QAction *gotoLineAction;
  QAction *toggleCommentAction;
  inline QString commentString();
  QAction *clearAction;
  QAction *openAction;
  QAction *saveAction;
  QAction *saveAsAction;
  QAction *zoomInAction;
  QAction *zoomOutAction;
  QAction *restoreZoomAction;
  QAction *exportoToPdfOrPsAction;
  QAction *exportoToOdtAction;
  QAction *exportoToHtmlAction;
  QAction *exportoToSvgAction;
  QAction *exportoToImgAction;
  QAction *selectAllAction;
  QAction *clearRecentFilesAction;
  QActionGroup *recentFilesActionGroup;
  QActionGroup *gotoLineActionGroup;
  QAction *highlightCurrentLineAction;
  QAction *normalizeTextAction;
  SubversionedFile *subversionedFile;
  void createMenu();
  QToolBar *mainToolBar;
  void createToolBars();
  QMenuBar *menuBar;
  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *optionsMenu;
  QMenu *subversionMenu;
  QMenu *viewMenu;
  FindReplace *findReplace;
  QSplitter *secondSplitter;
  QListWidget *listSymbols;
  QAction *viewNormalAction;
  QAction *viewVerticalAction;
  QAction *viewHorizoltalAction;
  BaseTextEditor *readOnlyTextEditor;
  void updateReadOnlyEditor();
  QAction *showSymbolsAction;
  QLineEdit *lineEditFile;
  QLabel *labelPosition;
  QAction *sortSymbols;
  void fillMariaDBSymbols();
  void openLastOpenedFile();
  QMenu *openRecentFilesMenu;
  QMenu *contextualMenu;
  QMenu *symbolsMenu;
  QMenu *exportMenu;
  QAction *printAction;
  QAction *fillMariaDBSymbolsAction;
  QList<QAction *> editActionList();
  QList<QAction *> viewActionList();
  QList<QAction *> fileActionList();
  QAction *showMariaDBHelperAction;
  QAction *disableCompletionAction;
  QProcess *proc;
  BaseTextEditor *procOutput;
  QAction *contextualMenuSeparatorAction;
  QAction *viewMenuSeparatorActionView;
  QAction *viewMenuSeparatorActionSymbols;
  unsigned int windowCount;
  DTitleLabel *dTitleLabel;
  QAction *uppercaseKeywordsAction;
  QAction *lowercaseKeywordsAction;
  void changeTextCase(bool uppercse = true);
  QStandardItemModel *modelForPeriodCompeltion;
  QCompleter *completerForPeriodCompeltion;
  QMenu *versionControlMenu;
  QCompleter *codeSnippetCompleter;
  QStandardItemModel *modelCodeSnippet;
};

#endif // TEXTEDITOR_H
