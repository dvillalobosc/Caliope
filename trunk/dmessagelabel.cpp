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

#include <QHBoxLayout>
#include <QLabel>
#include <QIcon>

#include "dmessagelabel.h"

DMessageLabel::DMessageLabel(MessageTypes::MessageType type, QString message)
{
  QHBoxLayout *mainLayout = new QHBoxLayout;
  icon = new QLabel;
  if (type == MessageTypes::Warning)
    icon->setPixmap(QIcon::fromTheme("dialog-warning", QIcon(":/images/svg/dialog-warning-4.svg")).pixmap(QSize(32, 32)));
  if (type == MessageTypes::Information)
    icon->setPixmap(QIcon::fromTheme("dialog-information", QIcon(":/images/svg/dialog-information-4.svg")).pixmap(QSize(32, 32)));
  if (type == MessageTypes::Error)
    icon->setPixmap(QIcon::fromTheme("dialog-error", QIcon(":/images/svg/dialog-error-4.svg")).pixmap(QSize(32, 32)));
  icon->setMaximumSize(QSize(36, 36));
  icon->setAlignment(Qt::AlignCenter);
  icon->setMargin(3);
  label = new QLabel;
  setText(message);
  label->setWordWrap(true);
  label->setFrameShape(QFrame::Box);
  label->setMargin(5);
  label->setFrameShadow(QFrame::Sunken);
  label->setStyleSheet("background-color: lightyellow");
  mainLayout->addWidget(icon);
  mainLayout->addWidget(label);
  setLayout(mainLayout);
}

void DMessageLabel::setEnabled(bool enabled)
{
  icon->setEnabled(enabled);
  label->setEnabled(enabled);
}

void DMessageLabel::setText(QString message)
{
  label->setText("<B>" + message + "</B>");
  label->setToolTip(label->text());
}
