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

#include "dtablewidget.h"

DTableWidget::DTableWidget(QStringList headers, QAbstractItemView::SelectionMode selectionMode)
{
  setRowCount(0);
  setColumnCount(headers.count());
  setAlternatingRowColors(true);
  setSelectionMode(selectionMode);
  setHorizontalHeaderLabels(headers);
  connect(this, SIGNAL(cellClicked(int,int)), this, SLOT(cellClickedSlot()));

}
void DTableWidget::cellClickedSlot()
{
  setRangeSelected(QTableWidgetSelectionRange(currentRow(), 0, currentRow(), columnCount() - 1), true);
}
