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

#if QT_VERSION > 0x040801
  #include <QtWebKitWidgets/QWebView>
#else
  #include <QtWebKit/QWebView>
#endif
#include <QVBoxLayout>
#include <QCompleter>
#include <QLineEdit>
#include <QToolBar>
#include <QAction>
//#include <QWebFrame>
#include <QDesktopServices>

#include "dwebview.h"

DWebView::DWebView(QString title, QUrl url)
{
  this->title = title;
  setWindowIcon(QIcon::fromTheme("applications-internet", QIcon(":/images/svg/applications-internet-5.svg")));

  webView = new QWebView;
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
#if QT_VERSION > 0x040801
    urlCompleter->setFilterMode(Qt::MatchContains);
#endif
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

//  QNetworkProxyFactory::setUseSystemConfiguration(true);
  QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
  QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
  QWebSettings::globalSettings()->enablePersistentStorage();

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(0, 0, 0, 0);
  mainVLayout->addWidget(mainToolBar);
  mainVLayout->addWidget(webView);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);

//  if (url.isEmpty())
//    url = QUrl(QInputDialog::getText(this, tr("URL to load"), tr("URL to load"), QLineEdit::Normal, "http://", 0, 0, Qt::ImhUrlCharactersOnly));

  webView->load(url);
}

void DWebView::retranslateUi()
{
  setWindowTitle(title);
  setObjectName(windowTitle());
  showSourceCode->setText(tr("Show page source"));
  openInExternalBrowser->setText(tr("Open in external browser"));
}

void DWebView::loadStartedSlot()
{
  emit loadStarted(tr("Loading page..."), 2000, 0);
}

void DWebView::loadFinishedSlot(const bool state)
{
  if (state)
    emit loadFinished(tr("Page loaded."), 2000, 100);
  else
    emit loadProgress(tr("Could not load page."), 2000, 0);
}

void DWebView::statusBarMessageSlot(const QString &message, const int timeout)
{
  emit statusBarMessage(message, QSystemTrayIcon::Information, timeout);
}

//void DWebView::statusBarMessage(const QString &message1, const QString &message2, const QString &message3, const int timeout)
//{
//  Q_UNUSED(message2);
//  Q_UNUSED(message3);
//  parentWidget->statusBarMessage(message1, QSystemTrayIcon::Information, timeout);
//}

void DWebView::loadProgressSlot(const int progress)
{
  emit loadProgress(tr("Loading page..."), 2000, progress);
}

void DWebView::urlChangedSlot(const QUrl &url)
{
  urlLineEdit->setText(url.toString());
  QStringList visitedURLs(settings.value("Internet/VisitedURLs", QStringList()).toStringList());
  visitedURLs.append(url.toString());
  visitedURLs.removeDuplicates();
  settings.setValue("Internet/VisitedURLs", visitedURLs);
//  QAbstractItemModel *model = new QAbstractItemModel;
//  model->setItemData()
//  urlCompleter->set->setModel(visitedURLs);
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
  //qDebug() << webView->page()->currentFrame()->toHtml();
  //emit returnPagesource(webView->page()->currentFrame()->toHtml());
  emit showPagesource("asdf");
}

void DWebView::openInExternalBrowserTriggered()
{
  QDesktopServices::openUrl(QUrl(urlLineEdit->text(), QUrl::TolerantMode));
}
