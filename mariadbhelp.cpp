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

#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>
#include <QTreeWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QSettings>

#include "mariadbhelp.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "dlineedit.h"

MariaDBHelp::MariaDBHelp(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);

  helpTreeWidget = new QTreeWidget;
  helpTreeWidget->setColumnCount(1);
  connect(helpTreeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(showTopicSlot(QTreeWidgetItem*,int)));
  connect(helpTreeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(showTopicSlot(QTreeWidgetItem*,int)));

  fillHelpTreeWidget();

  lineEditFilter = new DLineEdit(QIcon(":/images/svg/view-filter.svg"));
  connect(lineEditFilter, SIGNAL(textChangedSignal(QString)), this, SLOT(fillHelpTreeWidget(QString)));
  connect(lineEditFilter, SIGNAL(returnPressed(QString)), this, SLOT(fillHelpTreeWidget(QString)));

  QVBoxLayout *treeHelpLayout = new QVBoxLayout;
  treeHelpLayout->addWidget(lineEditFilter);
  treeHelpLayout->addWidget(helpTreeWidget);
  treeHelpLayout->setContentsMargins(0, 0, 0, 0);
  QWidget *widTreeHelp = new QWidget;
  widTreeHelp->setLayout(treeHelpLayout);
  widTreeHelp->setMaximumWidth(250);

  helpView = new QTextEdit;
  helpView->setFont(StaticFunctions::fixedWidthFont());

  mainSplitter = new QSplitter(Qt::Horizontal);
  mainSplitter->addWidget(widTreeHelp);
  mainSplitter->addWidget(helpView);

  connect(mainSplitter, SIGNAL(splitterMoved(int,int)), this, SLOT(saveSizesSlot(int,int)));

  mainVLayout->addWidget(mainSplitter);
  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
}

void MariaDBHelp::retranslateUi()
{
  setWindowTitle(tr("MariaDB Help"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  helpTreeWidget->setHeaderLabel(tr("Topics"));
  lineEditFilter->setPlaceholderText(tr("Enter a Keyword"));
}

void MariaDBHelp::fillHelpTreeWidget(QString filter)
{
  helpTreeWidget->clear();
  QList<QTreeWidgetItem *> items;
  QTreeWidgetItem *item;
  QTreeWidgetItem *itemChild;
  QStringList rows2;
  rows = serverConnection->runQuery("SELECT `help_category_id`, `name` FROM `mysql`.`help_category` ORDER BY `name`");
  rows->takeLast(); //Remove the "Affected rows" line.
  for (int counter = 0; counter < rows->count(); counter++) {
    item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(rows->at(counter).at(1)));
    if (filter.isEmpty())
      rows2 = serverConnection->runQuerySingleColumn("SELECT `name` FROM `mysql`.`help_topic` WHERE `help_category_id` = "
                                                                   + rows->at(counter).at(0) + " ORDER BY `name`");
    else
      rows2 = serverConnection->runQuerySingleColumn("SELECT `name` FROM `mysql`.`help_topic` WHERE `help_category_id` = "
                                                                   + rows->at(counter).at(0) + " AND `name` LIKE '%"+ filter
                                                                   + "%' ORDER BY `name`");
    for (int counter2 = 0; counter2 < rows2.count(); counter2++) {
      itemChild = new QTreeWidgetItem(item, QStringList(rows2.at(counter2)));
      itemChild->setIcon(0, QIcon(":/images/svg/server-database.svg"));
    }
    item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
    items.append(item);
  }
  helpTreeWidget->insertTopLevelItems(0, items);
}

void MariaDBHelp::showTopicSlot(QTreeWidgetItem *item, int column)
{
  rows = serverConnection->runQuery("SELECT `description`, `example`, `url` FROM `mysql`.`help_topic` WHERE `name` = '" + item->text(column) + "'");
  rows->takeLast(); //Remove the "Affected rows" line.
  if (rows->count() > 0)
    helpView->setHtml("<H1>" + tr("Syntax:") + "</H1>" + QString(rows->at(0).at(0)).replace("\n", "<BR />")
                      + "<H1>" + tr("Example:") + "</H1>"
                      + rows->at(0).at(1)
                      + "<H1>" + tr("URL:") + "</H1>"
                      + "<A href='" + rows->at(0).at(2) + "'>" + rows->at(0).at(2) + "</A>");
}

void MariaDBHelp::saveSizesSlot(int pos, int index)
{
  Q_UNUSED(index);
  QSettings settings;
  settings.beginGroup("MySQLHelp");
  settings.setValue("Sizes", QString("%1").arg(pos));
  settings.endGroup();
}
