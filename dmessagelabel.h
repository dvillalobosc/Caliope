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

#ifndef DMESSAGELABEL_H
#define DMESSAGELABEL_H

#include <QWidget>

class QLabel;

class MessageTypes
{
public:
  enum MessageType {Error, Information, Warning};
};

class DMessageLabel : public QWidget
{
  Q_OBJECT

public:
  DMessageLabel(MessageTypes::MessageType type, QString message = QString());
  void setEnabled(bool enabled);
  void setText(QString message = QString());

private:
  QLabel *icon;
  QLabel *label;
};

#endif // DMESSAGELABEL_H
