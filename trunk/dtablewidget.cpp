/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2018 David Villalobos Cambronero (david.villalobos.c@gmail.com).
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

#include <QMenu>
#include <QContextMenuEvent>
#include <QTableWidgetSelectionRange>
#include <QApplication>
#include <QClipboard>
#include <QAction>
#include <QMessageBox>

#include "dtablewidget.h"

#include <QDebug>

DTableWidget::DTableWidget(QStringList headers, QAbstractItemView::SelectionMode selectionMode)
{
  setRowCount(0);
  setColumnCount(headers.count());
  setAlternatingRowColors(true);
  setSelectionMode(selectionMode);
  setHorizontalHeaderLabels(headers);
  connect(this, SIGNAL(cellClicked(int,int)), this, SLOT(cellClickedSlot()));
  mainMenu = new QMenu(this);
  copyAction = new QAction(this);
  copyAction->setIcon(QIcon::fromTheme("edit-copy", QIcon(":/images/svg/edit-copy-6.svg")));
//  copyAction->setShortcut(QKeySequence::Copy);
  connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));
  pasteAction = new QAction(this);
  pasteAction->setIcon(QIcon::fromTheme("edit-paste", QIcon(":/images/svg/edit-paste-6.svg")));
//  pasteAction->setShortcut(QKeySequence::Paste);
  connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));
//  mainMenu->addAction(copyAction);
  mainMenu->addAction(pasteAction);
  retranslateUi();
}

void DTableWidget::setHeaders(QStringList headers)
{
  setColumnCount(headers.count());
  setHorizontalHeaderLabels(headers);
}

void DTableWidget::fillTable(QList<QStringList> *rows)
{
  setRowCount(rows->count());
  for (int row = 0; row < rows->count(); row++) {
    for (int column = 0; column < rows->at(row).count(); column++) {
      setItem(row, column, new QTableWidgetItem(rows->at(row).at(column)));
    }
  }
  resizeColumnsToContents();
  resizeRowsToContents();
  setSortingEnabled(true);
}

void DTableWidget::retranslateUi()
{
  copyAction->setText(tr("Copy all"));
  copyAction->setToolTip(copyAction->text());
  pasteAction->setText(tr("Paste"));
  pasteAction->setToolTip(pasteAction->text());
}

void DTableWidget::setPasteActionEnabled(bool enabled)
{
  pasteAction->setEnabled(enabled);
}

void DTableWidget::setTableName(QString tableName)
{
  this->tableName = tableName;
}

QString DTableWidget::getTableName()
{
  return this->tableName;
}

void DTableWidget::cellClickedSlot()
{
  setRangeSelected(QTableWidgetSelectionRange(currentRow(), 0, currentRow(), columnCount() - 1), true);
}

void DTableWidget::copy()
{
////  QList<QTableWidgetSelectionRange> ranges = selectedRanges();
////  if (ranges.isEmpty())
////    return;
////  QTableWidgetSelectionRange range = ranges.first();
//  QString clipboardData;
//  for (int row = 0; row < columnCount(); row++) {
//    clipboardData += horizontalHeaderItem(row)->text();
//    clipboardData += "\t";
//  }
//  clipboardData += "\n";
//  for (int counterRow = 0; counterRow < rowCount(); counterRow++) {
//    if (counterRow > 0)
//      clipboardData += "\n";
//    for (int counterColumn = 0; counterColumn < columnCount(); counterColumn++) {
//      if (counterColumn > 0)
//        clipboardData += "\t";
//      clipboardData += itemAt(counterRow, counterColumn)->text();
//    }
//  }
//  QApplication::clipboard()->setText(clipboardData);
}

void DTableWidget::paste()
{
  QList<QTableWidgetSelectionRange> ranges = selectedRanges();
  if (ranges.isEmpty())
    return;
  QTableWidgetSelectionRange range = ranges.first();
  QStringList rows = QApplication::clipboard()->text().split('\n');
  rows.takeLast();
  int numRows = rows.count();
  int numColumns = rows.first().count('\t') + 1;

  if (range.columnCount() != numColumns) {
    QMessageBox::information(this, tr("Paste error"), tr("The data cannot be pasted because the copy and paste areas are not the same size."));
    return;
  }

  QString insertingColumns;
  for (int row = 0; row < columnCount(); row++) {
    insertingColumns += "`" + horizontalHeaderItem(row)->text() + "`, ";
  }

  QString insertingValues;
  QString value;
  for (int counterRow = 0; counterRow < numRows; counterRow++) {
    insertRow(rowCount());
    QStringList columns = rows[counterRow].split('\t');
    for (int columnCount = 0; columnCount < numColumns; columnCount++) {
      setItem(rowCount() - 1, columnCount, new QTableWidgetItem(columns.at(columnCount)));
      value = columns.at(columnCount);
      if (value.compare("NULL", Qt::CaseInsensitive) == 0)
        insertingValues += columns.at(columnCount) + ", ";
      else
        insertingValues += "'" + columns.at(columnCount) + "', ";
    }

    if (!getTableName().isEmpty())
      statementsToExecute.append("INSERT INTO " + getTableName()
                                 + " (" + insertingColumns.mid(0, insertingColumns.length() - 2)
                                 + ") VALUES (" + insertingValues.mid(0, insertingValues.length() - 2)
                                 + ");");
  }
  if (QMessageBox::question(this, tr("Insert exectution"),
                            tr("Do you really want to execute these Inserts?"),
                            QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes) {
    emit executeStatements(statementsToExecute);
  }
  statementsToExecute.clear();
}

void DTableWidget::contextMenuEvent(QContextMenuEvent *event)
{
  mainMenu->exec(event->globalPos());
  QTableWidget::contextMenuEvent(event);
}
