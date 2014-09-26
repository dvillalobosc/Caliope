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

#include <QToolButton>
#include <QStyle>

#include "dlineedit.h"

DLineEdit::DLineEdit(QIcon icon, bool autoHideIcon)
{
  this->icon = icon;
  actionButton = new QToolButton(this);
  actionButton->setIcon(icon);
  actionButton->setCursor(Qt::ArrowCursor);
  actionButton->setStyleSheet("QToolButton { border: none; padding: 0px; }");
  if (autoHideIcon) {
    actionButton->hide();
    connect(this, SIGNAL(textChanged(const QString&)), this, SLOT(showHideActionButton(const QString&)));
  }
  connect(actionButton, SIGNAL(clicked()), this, SLOT(emitTextChangedSignal()));
  connect(this, SIGNAL(returnPressed()), this, SLOT(returnPressedSlot()));
  int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  setStyleSheet(QString("QLineEdit { padding-right: %1px; } ").arg(actionButton->sizeHint().width() + frameWidth + 1));
  QSize msz = minimumSizeHint();
  setMinimumSize(qMax(msz.width(), actionButton->sizeHint().height() + frameWidth * 2 + 2),
                 qMax(msz.height(), actionButton->sizeHint().height() + frameWidth * 2 + 2));
}

void DLineEdit::resizeEvent(QResizeEvent *)
{
  QSize sz = actionButton->sizeHint();
  int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
  actionButton->move(rect().right() - frameWidth - sz.width(), (rect().bottom() + 1 - sz.height())/2);
}

void DLineEdit::showHideActionButton(const QString& text)
{
  actionButton->setVisible(!text.isEmpty());
}

void DLineEdit::emitTextChangedSignal()
{
  emit textChangedSignal(text());
  emit clicked();
}

void DLineEdit::returnPressedSlot()
{
  emit returnPressed(text());
}
