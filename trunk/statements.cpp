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

#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QClipboard>
#include <QApplication>
#include <QContextMenuEvent>
#include <QScrollArea>

#include "statements.h"
#include "dtablewidget.h"

#include "QDebug"

Statements::Statements()
{
  setWindowTitle(tr("Executed statements"));
  setObjectName(windowTitle());
//  setAttribute(Qt::WA_DeleteOnClose);
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));
  queriesDTableWidget = new DTableWidget(QStringList() << tr("Statements"));
  connect(queriesDTableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(queriesCellDoubleClickedSlot()));

  QScrollArea *scrollArea = new QScrollArea;
  scrollArea->setBackgroundRole(QPalette::Dark);
  scrollArea->setWidget(queriesDTableWidget);
  scrollArea->setWidgetResizable(true);
  QVBoxLayout *statementsLayout = new QVBoxLayout;
  statementsLayout->setMargin(0);
  statementsLayout->addWidget(scrollArea);
  setLayout(statementsLayout);
  clipboard = QApplication::clipboard();
  createActions();
  resize(600, 200);
  menu =  new QMenu(this);
  menu->addAction(copyAction);
  menu->addAction(removeStatementAction);
}

void Statements::createActions()
{
  copyAction = new QAction(QIcon::fromTheme("edit-copy", QIcon(":/images/svg/edit-copy-6.svg")), tr("Copy"), this);
  connect(copyAction, SIGNAL(triggered()), this, SLOT(copyToClipboard()));
  removeStatementAction = new QAction(QIcon::fromTheme("edit-delete", QIcon(":/images/svg/edit-delete-6.svg")), tr("Delete"), this);
  connect(removeStatementAction, SIGNAL(triggered()), this, SLOT(removeStatementActionTriggered()));
}

void Statements::removeStatementActionTriggered()
{
  queryList->removeAt(queryList->indexOf(queriesDTableWidget->item(queriesDTableWidget->currentItem()->row(), 1)->text()));
  fillGrid();
}

void Statements::copyToClipboard()
{
#if defined(Q_OS_LINUX)
  clipboard->setText(queriesDTableWidget->item(queriesDTableWidget->currentRow(), 0)->text(), QClipboard::Selection);
#elif defined(Q_OS_MAC)
  clipboard->setText(queriesDTableWidget->item(queriesDTableWidget->currentRow(), 0)->text(), QClipboard::Selection);
  clipboard->setText(queriesDTableWidget->item(queriesDTableWidget->currentRow(), 0)->text(), QClipboard::FindBuffer);
#endif
  clipboard->setText(queriesDTableWidget->item(queriesDTableWidget->currentRow(), 0)->text(), QClipboard::Clipboard);
}

void Statements::queriesCellDoubleClickedSlot()
{
  copyToClipboard();
  close();
}

void Statements::contextMenuEvent(QContextMenuEvent *e)
{
  menu->exec(e->globalPos());
}

void Statements::execSlot(QStringList *queries)
{
  queryList = queries;
  fillGrid();
  exec();
}

void Statements::fillGrid()
{
  QString icon;
  queriesDTableWidget->setRowCount(queryList->count());
  for (int row = 0; row < queryList->count(); row++) {
    icon = ":/images/svg/server-database.svg";
    if (QString(queryList->at(row)).contains(QRegExp("^insert", Qt::CaseInsensitive)))
      icon = ":/images/svg/server-database.svg";
    if (QString(queryList->at(row)).contains(QRegExp("^create", Qt::CaseInsensitive)))
      icon = ":/images/svg/server-database.svg";
    if (QString(queryList->at(row)).contains(QRegExp("^update", Qt::CaseInsensitive)))
      icon = ":/images/svg/server-database.svg";
    if (QString(queryList->at(row)).contains(QRegExp("^(delete|truncate|drop)", Qt::CaseInsensitive)))
      icon = ":/images/svg/server-database.svg";
    if (QString(queryList->at(row)).contains(QRegExp("^select", Qt::CaseInsensitive)))
      icon = ":/images/svg/server-database.svg";
    queriesDTableWidget->setItem(row, 0, new QTableWidgetItem(QIcon(icon), queryList->at(row)));
  }
  queriesDTableWidget->resizeColumnsToContents();
  queriesDTableWidget->resizeRowsToContents();
  queriesDTableWidget->setSortingEnabled(true);
}
