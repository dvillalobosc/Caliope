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

#include <QStandardItemModel>
#include <QApplication>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>

#include "dtableview.h"
#include "ditemdelegate.h"
#include "staticfunctions.h"

#include "QDebug"

DTableView::DTableView(QList<QStringList> *headers, QAbstractItemView::SelectionMode selectionMode) : readOnly(true)
{
  setHeaders(headers);
  setAlternatingRowColors(true);
  setSelectionMode(selectionMode);
  connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClickedSlot(QModelIndex)));
  mainMenu = new QMenu(this);
  sortingColumn = 0;
  sortOrder = Qt::AscendingOrder;
  dheaderView = new DheaderView();
  connect(dheaderView, SIGNAL(sectionClicked(int)), SLOT(sortingColumnSlot(int)));
  setHorizontalHeader(dheaderView);
}

void DTableView::setHeaders(QList<QStringList> *headers)
{
  headersList = headers;
  setHeaders();
}

void DTableView::setHeaders(QStringList headers)
{
  for (int counter = 0; counter < headers.count(); counter++)
    headersList->append(QStringList() << headers.at(counter) << StaticFunctions::DelegateTypeNoDelegate() << "" << "Left");
  setHeaders();
}

void DTableView::setHeaders()
{
  if (!this->readOnly) {
    for (int column = 0; column < headersList->count(); column++) {
      if (headersList->at(column).at(1) == StaticFunctions::DelegateTypeNumber())
        setItemDelegateForColumn(column, new DItemDelegate(StaticFunctions::DelegateTypeNumber()));
      if (headersList->at(column).at(1) == StaticFunctions::DelegateTypeDateTime())
        setItemDelegateForColumn(column, new DItemDelegate(StaticFunctions::DelegateTypeDateTime()));
      if (headersList->at(column).at(1) == StaticFunctions::DelegateTypePassword())
        setItemDelegateForColumn(column, new DItemDelegate(StaticFunctions::DelegateTypePassword()));
      if (headersList->at(column).at(1) == StaticFunctions::DelegateTypeDate())
        setItemDelegateForColumn(column, new DItemDelegate(StaticFunctions::DelegateTypeDate()));
      if (headersList->at(column).at(1).startsWith(StaticFunctions::DelegateTypeEnum()))
        setItemDelegateForColumn(column, new DItemDelegate(headersList->at(column).at(1)));
    }
  } else {
    for (int column = 0; column < headersList->count(); column++)
      setItemDelegateForColumn(column, new QItemDelegate());
  }
}

QList<QStringList> *DTableView::getHeaders()
{
  return headersList;
}

void DTableView::setModelData(QList<QStringList> *modelData, bool readOnly, unsigned int orderColumn, bool modelDataHasIcons)
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  this->readOnly = readOnly;
  setHeaders();
  emit loadStarted(tr("Loading records..."), 0, 0);
  itemModel = new QStandardItemModel(modelData->count(), headersList->count());
  itemModel->blockSignals(true);
  connect(itemModel, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(itemChangedSlot(QStandardItem*)));
  int handleIconsOnModelData;
  if (modelDataHasIcons)
    handleIconsOnModelData = 1;
  else
    handleIconsOnModelData = 0;
  for (int row = 0; row < modelData->count(); row++) {
    for (int column = 0; column < headersList->count(); column++) {
      itemModel->setHorizontalHeaderItem(column, new QStandardItem(QIcon(headersList->at(column).at(2)), headersList->at(column).at(0)));
      QStandardItem *item;
      if (column == 0)
        item = new QStandardItem(QIcon(modelData->at(row).at(0)), modelData->at(row).at(column + handleIconsOnModelData));
      else
        item = new QStandardItem(modelData->at(row).at(column + handleIconsOnModelData));

      if (headersList->at(column).at(3) == "Right")
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
      if (headersList->at(column).at(3) == "ToBytes") {
        item->setText(StaticFunctions::bytesConvertor(item->text()));
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        item->setToolTip(item->text());
      }
      itemModel->setItem(row, column, item);
      if (!this->readOnly)
        itemModel->setData(itemModel->index(row, column, QModelIndex()), modelData->at(row).at(column + handleIconsOnModelData), Qt::UserRole);
    }
    emit loadProgress(tr("Loading records..."), 0, row * 100 / modelData->count());
  }
  QItemSelectionModel *oldModel = selectionModel();
  setModel(itemModel);
  delete oldModel;
  resizeColumnsToContents();
  resizeRowsToContents();
  setSortingEnabled(true);
  if (orderColumn == 0)
    orderColumn = sortingColumn;
  sortByColumn(orderColumn, sortOrder);
  itemModel->blockSignals(false);
  emit loadStarted(tr("Records loaded."), 0, 100);
  QApplication::restoreOverrideCursor();
}

void DTableView::itemChangedSlot(QStandardItem *item)
{
  if (!this->readOnly)
    emit itemChanged(item);
}

QVariant DTableView::indexData(const unsigned int row, const unsigned int column, int role)
{
  return itemModel->index(row, column).data(role);
}

QVariant DTableView::indexData(const QModelIndex &index, int role, int column)
{
  if (column > -1)
    return itemModel->index(index.row(), column).data(role);
  return itemModel->data(index, role);
}

void DTableView::doubleClickedSlot(const QModelIndex &index)
{
  QList<QVariant> row;
  for(int column = 0; column <= headersList->count(); column++)
    row.append(itemModel->index(index.row(), column).data());
  emit rowDoubleClicked(row);
}

void DTableView::sortingColumnSlot(int index)
{
  if (sortingColumn == index)
    sortOrder = Qt::DescendingOrder;
  else
    sortOrder = Qt::AscendingOrder;
  sortingColumn = index;
}

QModelIndex DTableView::currentIndexItem()
{
  return currentIndex();
}

void DTableView::setCurrentItem(QString item, unsigned int column)
{
  setCurrentIndex(itemModel->indexFromItem(itemModel->findItems(item, Qt::MatchExactly, column).at(0)));
}

QStandardItem *DTableView::currentItem()
{
  return itemModel->itemFromIndex(currentIndex());
}

QList<QStandardItem *> DTableView::getRow(int row)
{
  QList<QStandardItem *> items;
  for (int column = 0; column < itemModel->columnCount(); column++)
    items.append(itemModel->item(row, column));
  return items;
}

void DTableView::addRow()
{
  if (this->readOnly)
    return;
  QList<QStandardItem *> items;
  for (int column = 0; column < headersList->count(); column++) {
    QStandardItem *item = new QStandardItem(headersList->at(column).at(4));
    item->setData("Inserted", 80);
    item->setBackground(QBrush(QColor("green")));
    items.append(item);
  }
  itemModel->insertRow(0, items);
  resizeRowsToContents();
}

void DTableView::contextMenuEvent(QContextMenuEvent *event)
{
  mainMenu->exec(event->globalPos());
  QTableView::contextMenuEvent(event);
}
