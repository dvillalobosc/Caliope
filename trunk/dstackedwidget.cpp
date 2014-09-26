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

#include <QStackedWidget>
#include <QHBoxLayout>
#include <QListWidget>

#include "dstackedwidget.h"

DStackedWidget::DStackedWidget()
{
  listWidget = new QListWidget(this);
  listWidget->setMaximumWidth(256);
  listWidget->setFlow(QListView::TopToBottom);
  stackedWidget = new QStackedWidget(this);
  connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
  QHBoxLayout *mainHLayout = new QHBoxLayout;
  mainHLayout->addWidget(listWidget);
  mainHLayout->addWidget(stackedWidget);
  setLayout(mainHLayout);
}

int DStackedWidget::addWidget(QWidget *widget, const QIcon &icon, const QString &label)
{
  listWidget->addItem(new QListWidgetItem(icon, label));
  return stackedWidget->addWidget(widget);
}

