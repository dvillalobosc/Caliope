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

#ifndef OBJECTSDIAGRAM_H
#define OBJECTSDIAGRAM_H

#include <QGraphicsItem>

class QGraphicsView;
class QGraphicsScene;
class DTitleLabel;

#include "dmdisubwindow.h"

class TableGraphicsItem : public QGraphicsItem
{
public:
  TableGraphicsItem();
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class ObjectsDiagram : public DMdiSubWindow
{
  Q_OBJECT

public:
  ObjectsDiagram();

protected:
  void retranslateUi();

private:
  QGraphicsView *view;
  QGraphicsScene *scene;
  DTitleLabel *dTitleLabel;
};

#endif // OBJECTSDIAGRAM_H
