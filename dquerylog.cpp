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

#include <QVBoxLayout>
#include <QIcon>
#include <QTableView>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QPushButton>
#include <QComboBox>
#include <QFileInfo>
#include <QApplication>

#include "dquerylog.h"
#include "dtitlelabel.h"
#include "dlineedit.h"

DQueryLog::DQueryLog(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  dTitleLabel = new DTitleLabel;
  labelFileSize = new QLabel;
  setWindowIcon(QIcon(":/images/svg/utilities-log-viewer-2.svg"));
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  mainVLayout->addWidget(dTitleLabel);

  buttonBox = new QGroupBox(this);
  QHBoxLayout *groupBoxHLayout = new QHBoxLayout;
  buttonBox->setLayout(groupBoxHLayout);
  mainVLayout->addWidget(buttonBox);

  pushButtonRefresh = new QPushButton;
  pushButtonRefresh->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));
  connect(pushButtonRefresh, SIGNAL(clicked()), this, SLOT(pushButtonRefreshClicked()));
  groupBoxHLayout->addWidget(pushButtonRefresh);
  comboBoxFilter = new QComboBox;
  comboBoxFilter->setModel(serverConnection->sqliteFilterQueryModel());
  connect(comboBoxFilter, SIGNAL(activated(QString)), this, SLOT(comboBoxFilterActivated(QString)));
  groupBoxHLayout->addWidget(comboBoxFilter);
  pushButtonClearQueryLog = new QPushButton;
  pushButtonClearQueryLog->setIcon(QIcon::fromTheme("edit-clear", QIcon(":/images/svg/computerjanitor.svg")));
  connect(pushButtonClearQueryLog, SIGNAL(clicked()), this, SLOT(pushButtonClearQueryLogClicked()));
  groupBoxHLayout->addWidget(pushButtonClearQueryLog);
  groupBoxHLayout->addWidget(labelFileSize);

  lineEditFilter = new DLineEdit(QIcon(":/images/svg/view-filter.svg"));
  connect(lineEditFilter, SIGNAL(textChanged(QString)), this, SLOT(lineEditFilterTextChangedSlot(QString)));
  filterByQuery = new QLabel;
  groupBoxHLayout->addWidget(filterByQuery);
  groupBoxHLayout->addWidget(lineEditFilter);

  queryLogTableView = new QTableView;
  queryLogTableView->setModel(serverConnection->sqliteTableModel());
  getFileInfo();
  mainVLayout->addWidget(queryLogTableView);

  groupBoxHLayout->addStretch(1);

  queryLogTableView->resizeColumnsToContents();
  queryLogTableView->resizeRowsToContents();
  queryLogTableView->setSortingEnabled(true);
  queryLogTableView->sortByColumn(0, Qt::AscendingOrder);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
  retranslateUi();
  comboBoxFilterActivated(comboBoxFilter->currentText());
}

void DQueryLog::getFileInfo()
{
  QFileInfo fileInfo = QFileInfo(qApp->property("LocalDatabase").toString());
  labelFileSize->setText(tr("File size: %1 Mb. File path: %2.").arg(fileInfo.size() / 1024.0 / 1024.0).arg(fileInfo.path()));
  labelFileSize->setToolTip(labelFileSize->text());
}

void DQueryLog::pushButtonRefreshClicked()
{
  QSqlTableModel *model = qobject_cast<QSqlTableModel *>(queryLogTableView->model());
  model->setFilter("");
  getFileInfo();
}

void DQueryLog::comboBoxFilterActivated(QString filter)
{
  QSqlTableModel *model = qobject_cast<QSqlTableModel *>(queryLogTableView->model());
  model->setFilter("sessionid = '" + filter + "'");
  queryLogTableView->resizeColumnsToContents();
  queryLogTableView->resizeRowsToContents();
}

void DQueryLog::pushButtonClearQueryLogClicked()
{
  serverConnection->clearSQLiteQueryLog();
  pushButtonRefreshClicked();
}

void DQueryLog::lineEditFilterTextChangedSlot(QString filter)
{
  QSqlTableModel *model = qobject_cast<QSqlTableModel *>(queryLogTableView->model());
  model->setFilter("query LIKE '%" + filter + "%'");
  queryLogTableView->resizeColumnsToContents();
  queryLogTableView->resizeRowsToContents();
}

void DQueryLog::retranslateUi()
{
  setWindowTitle(tr("Query Log"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  dTitleLabel->setToolTip(dTitleLabel->text());
  buttonBox->setTitle(tr("Actions"));
  buttonBox->setToolTip(buttonBox->title());
  pushButtonRefresh->setText(tr("Refresh"));
  pushButtonRefresh->setToolTip(pushButtonRefresh->text());
  pushButtonClearQueryLog->setText(tr("Clear log"));
  pushButtonClearQueryLog->setToolTip(pushButtonClearQueryLog->text());
  lineEditFilter->setPlaceholderText(tr("Three characters at least"));
  filterByQuery->setText(tr("Filter by query:"));
  filterByQuery->setToolTip(filterByQuery->text());
}
