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

#ifndef DLINEEDIT_H
#define DLINEEDIT_H

#include <QLineEdit>
#include <QIcon>

class QToolButton;

class DLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  DLineEdit(QIcon icon, bool autoHideIcon = false);

private:
  QIcon icon;
  QToolButton *actionButton;

protected:
  void resizeEvent(QResizeEvent *event);
  void mousePressEvent(QMouseEvent *event);

private slots:
  void showHideActionButton(const QString &text);
  void emitTextChangedSignal();
  void returnPressedSlot();

signals:
  void textChangedSignal(const QString &text);
  void clicked();
  void returnPressed(const QString &text);
};

#endif // DLINEEDIT_H
