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

#include <QPlainTextEdit>
#include <QDialog>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QGraphicsObject>

#include "dstatusbar.h"
#include "staticfunctions.h"

DStatusBar::DStatusBar()
{
  setCursor(Qt::PointingHandCursor);
  labelPosition = new QLabel(" 0 : 0 ");
  labelPosition->setAlignment(Qt::AlignCenter);
  labelPosition->setFrameShape(QFrame::Box);
  labelPosition->setFrameShadow(QFrame::Sunken);
  addPermanentWidget(labelPosition);
  progressBar = new QProgressBar;
  progressBar->setMaximum(1);
  progressBar->setMaximum(100);
  progressBar->setMaximumWidth(200);
  addPermanentWidget(progressBar);
}

void DStatusBar::mouseDoubleClickEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  QDialog *dialog = new QDialog;
  dialog->resize(470, 275);
  QHBoxLayout *layout = new QHBoxLayout(dialog);
  QPlainTextEdit *textMessage = new QPlainTextEdit(currentMessage());
  textMessage->setFont(StaticFunctions::fixedWidthFont());
  textMessage->setWordWrapMode(QTextOption::NoWrap);
  layout->addWidget(textMessage);
  layout->setMargin(1);
  dialog->exec();
}

void DStatusBar::showMessagePopup(const QString &message, int timeout)
{
  showMessage(message, timeout);
  mouseDoubleClickEvent(0);
}

void DStatusBar::setProgress(const int progress)
{
  progressBar->setValue(progress);
}

void DStatusBar::setPrositionViewer(const int x, const int y)
{
  labelPosition->setText(QString(" %1 : %2 ").arg(x + 1).arg(y + 1));
}

void DStatusBar::resetStatusBar()
{
  progressBar->reset();
  setPrositionViewer(-1, -1);
  showMessage("");
}

void DStatusBar::showFancyMessage(const QString &text, int timeout)
{
//  qmlView->rootObject()->setProperty("message", text);
  showMessage(text, timeout);
}
