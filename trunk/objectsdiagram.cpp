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

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QStyleOptionGraphicsItem>

#include "objectsdiagram.h"
#include "dtitlelabel.h"

ObjectsDiagram::ObjectsDiagram()
{
  setWindowIcon(QIcon(":/images/svg/application-vnd.oasis.opendocument.graphics.svg"));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);

  scene = new QGraphicsScene(this);
  scene->setItemIndexMethod(QGraphicsScene::NoIndex);

  view = new QGraphicsView(scene);
  view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
  view->setBackgroundBrush(Qt::lightGray);
  mainVLayout->addWidget(view);

  scene->addItem(new TableGraphicsItem);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
}

void ObjectsDiagram::retranslateUi()
{
  setWindowTitle(tr("Objects Diagram"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
}

/************************************************************************************/

TableGraphicsItem::TableGraphicsItem()
{
  setFlags(QGraphicsItem::ItemClipsChildrenToShape);
//  setPen(QPen(QColor("brown"), 2.5));
//  setBrush(Qt::white);
//  setRect(100, 5, 200, 200);
}

QRectF TableGraphicsItem::boundingRect() const
{
  qreal penWidth = 1;
  return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void TableGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(widget);
  QString tableName(QObject::tr("Table: %1"));
  painter->drawText(QRectF(0, 0, 20, option->fontMetrics.width(tableName.toUtf8())), tableName);
  painter->drawRoundedRect(QRectF(-10, -10, 20, option->fontMetrics.width(tableName.toUtf8())), 5, 5);
}
