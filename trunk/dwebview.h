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

#ifndef DWEBVIEW_H
#define DWEBVIEW_H

#include <QUrl>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QWebEnginePage>
#include <QSslError>

class QWebView;
class QLineEdit;
class QCompleter;
class QToolBar;
class QWebPage;

#include "dmdisubwindow.h"

class DWebView : public DMdiSubWindow
{
  Q_OBJECT

public:
  DWebView(QString title, QUrl url = QUrl());
  QWebPage *page();

private:
  QWebView *webView;
  QLineEdit *urlLineEdit;
  QSettings settings;
  QCompleter *urlCompleter;
  QToolBar *mainToolBar;
  QString title;
  QAction *showSourceCode;
  QAction *openInExternalBrowser;

protected:
  void retranslateUi();

public slots:
  void sslErrors(QNetworkReply * reply, const QList<QSslError> & errors);

signals:
  void loadStarted(QString message, unsigned int timeout, double progress);
  void loadFinished(QString message, unsigned int timeout, double progress);
  void loadProgress(QString message, unsigned int timeout, double progress);
  void statusBarProgressMessage(const QString &message, const unsigned int timeout = 0, const double progress = 0);
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 0);
  void showPagesource(const QString pageSource);

private slots:
  void statusBarMessageSlot(const QString &message, const int timeout = 0);
  void loadFinishedSlot(const bool state);
  void loadStartedSlot();
  void loadProgressSlot(const int progress);
  void urlChangedSlot(const QUrl &url);
  void urlLineEditReturnPressed();
  void statusBarProgressMessageSlot(const QString &message, const unsigned int timeout = 0, const double progress = 0);
  void showSourceCodeTriggered();
  void openInExternalBrowserTriggered();
  void slotSourceDownloaded();
};

#endif // DWEBVIEW_H
