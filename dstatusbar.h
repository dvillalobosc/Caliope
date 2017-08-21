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

#ifndef DLABEL_H
#define DLABEL_H

#include <QStatusBar>

class QProgressBar;
class QLabel;
class QQuickView;

class DStatusBar : public QStatusBar
{
  Q_OBJECT

public:
  DStatusBar();
  void showMessagePopup(const QString &message, int timeout = 0);
  void resetStatusBar();
  void showFancyMessage(const QString &text, int timeout = 0);

public slots:
  void setPrositionViewer(const int x, const int y);
  void setProgress(const int progress = 0);

private:
  QProgressBar *progressBar;
  QLabel *labelPosition;
  QQuickView *qmlView;

protected:
  /*! \brief Reilplements the closeEvent.
   *
   *  Reilplements the closeEvent to make some checks on the window closing.
   */
  void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // DLABEL_H
