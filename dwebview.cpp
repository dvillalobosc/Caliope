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

#include <QtNetwork>
#include <QtWebKitWidgets>
#include <QCompleter>
#include <QLineEdit>
#include <QWebEngineSettings>

#include "dwebview.h"

DWebView::DWebView(QString title, QUrl url)
{
  this->title = title;
  setWindowIcon(QIcon::fromTheme("applications-internet", QIcon(":/images/svg/applications-internet-5.svg")));

  webView = new QWebView();
  connect(this, SIGNAL(loadStarted(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(this, SIGNAL(loadFinished(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(this, SIGNAL(loadProgress(QString,uint,double)), this, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(webView, SIGNAL(loadStarted()), this, SLOT(loadStartedSlot()));
  connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinishedSlot(bool)));
  connect(webView, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessageSlot(QString)));
  connect(webView, SIGNAL(loadProgress(int)), this, SLOT(loadProgressSlot(int)));
//  connect(webView->page(), SIGNAL(linkHovered(QString,QString,QString)), this, SLOT(statusBarMessage(QString,QString,QString)));
  connect(webView, SIGNAL(urlChanged(QUrl)), SLOT(urlChangedSlot(QUrl)));

  urlLineEdit = new QLineEdit;
  urlLineEdit->setInputMethodHints(Qt::ImhUrlCharactersOnly);
  connect(urlLineEdit, SIGNAL(returnPressed()), SLOT(urlLineEditReturnPressed()));

  urlCompleter = new QCompleter(settings.value("Internet/VisitedURLs", QStringList()).toStringList(), urlLineEdit);
  urlCompleter->setFilterMode(Qt::MatchContains);
  urlCompleter->setCaseSensitivity(Qt::CaseInsensitive);
  urlLineEdit->setCompleter(urlCompleter);

  mainToolBar = new QToolBar(tr("Actions"));
  mainToolBar->addAction(webView->pageAction(QWebPage::Back));
  mainToolBar->addAction(webView->pageAction(QWebPage::Forward));
  mainToolBar->addAction(webView->pageAction(QWebPage::Reload));
  mainToolBar->addWidget(urlLineEdit);
  mainToolBar->addAction(webView->pageAction(QWebPage::Stop));

  showSourceCode = new QAction(this);
  showSourceCode->setIcon(QIcon::fromTheme("text-html", QIcon(":/images/svg/text-html.svg")));
  connect(showSourceCode, SIGNAL(triggered()), this, SLOT(showSourceCodeTriggered()));
  mainToolBar->addAction(showSourceCode);

  openInExternalBrowser = new QAction(this);
  openInExternalBrowser->setIcon(QIcon(":/images/svg/document-export-4.svg"));
  connect(openInExternalBrowser, SIGNAL(triggered()), this, SLOT(openInExternalBrowserTriggered()));
  mainToolBar->addAction(openInExternalBrowser);

  QNetworkProxyFactory::setUseSystemConfiguration(true);
  QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
  QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::AutoLoadImages, true);

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(0, 0, 0, 0);
  mainVLayout->addWidget(mainToolBar);
  mainVLayout->addWidget(webView);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);

  if (url.isEmpty())
    url = QUrl::fromUserInput(QInputDialog::getText(this, tr("URL to load"), tr("URL to load"), QLineEdit::Normal, "http://", 0, 0, Qt::ImhUrlCharactersOnly));

  webView->load(url);
}

QWebPage *DWebView::page()
{
  return webView->page();
}

void DWebView::retranslateUi()
{
  setWindowTitle(title);
  setObjectName(windowTitle());
  showSourceCode->setText(tr("Show page source"));
  showSourceCode->setToolTip(showSourceCode->text());
  openInExternalBrowser->setText(tr("Open in external browser"));
  openInExternalBrowser->setToolTip(openInExternalBrowser->text());
}

void DWebView::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
  qDebug() << "handleSslErrors: ";
  foreach (QSslError e, errors)
  {
    qDebug() << "ssl error: " << e;
  }
  reply->ignoreSslErrors();
}

void DWebView::loadStartedSlot()
{
  emit loadStarted(tr("Loading page..."), 0, 0);
}

void DWebView::loadFinishedSlot(const bool state)
{
  if (state)
    emit loadFinished(tr("Page loaded."), 0, 100);
  else
    emit loadProgress(tr("Could not load page."), 0, 0);
}

void DWebView::statusBarMessageSlot(const QString &message, const int timeout)
{
  emit statusBarMessage(message, QSystemTrayIcon::Information, timeout);
}

void DWebView::loadProgressSlot(const int progress)
{
  emit loadProgress(tr("Loading page..."), 0, progress);
}

void DWebView::urlChangedSlot(const QUrl &url)
{
  urlLineEdit->setText(url.toString());
  QStringList visitedURLs(settings.value("Internet/VisitedURLs", QStringList()).toStringList());
  visitedURLs.append(url.toString());
  visitedURLs.removeDuplicates();
  settings.setValue("Internet/VisitedURLs", visitedURLs);
}

void DWebView::urlLineEditReturnPressed()
{
  if (urlLineEdit->text().startsWith("http://") || urlLineEdit->text().startsWith("https://"))
    webView->load(QUrl(urlLineEdit->text()));
  else
    webView->load(QUrl("http://" + urlLineEdit->text()));
}

void DWebView::statusBarProgressMessageSlot(const QString &message, const unsigned int timeout, const double progress)
{
  emit statusBarProgressMessage(message, timeout, progress);
}

void DWebView::showSourceCodeTriggered()
{
  QNetworkAccessManager* accessManager = webView->page()->networkAccessManager();
  QNetworkRequest request(webView->url());
  QNetworkReply* reply = accessManager->get(request);
  connect(reply, SIGNAL(finished()), this, SLOT(slotSourceDownloaded()));
}

void DWebView::slotSourceDownloaded()
{
  QNetworkReply* reply = qobject_cast<QNetworkReply*>(const_cast<QObject*>(sender()));
  emit showPagesource(reply->readAll());
  reply->deleteLater();
}

void DWebView::openInExternalBrowserTriggered()
{
  QDesktopServices::openUrl(QUrl(urlLineEdit->text(), QUrl::TolerantMode));
}
