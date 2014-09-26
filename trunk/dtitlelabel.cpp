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

#include "dtitlelabel.h"

DTitleLabel::DTitleLabel(const QString text)
{
  QFont font;
  font.setPointSize(16);
  font.setBold(true);
  font.setWeight(75);

  setFont(font);
  setText(text);
  setFrameShape(QFrame::Box);
  setMargin(10);
  setFrameShadow(QFrame::Sunken);
  setAlignment(Qt::AlignCenter);
  setMaximumHeight(50);
  setStyleSheet("background-color: lightblue");
}

void DTitleLabel::setTitleText(const QString text)
{
  setText(text);
}
