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

#ifndef DTABLEVIEW_H
#define DTABLEVIEW_H

#include <QTableView>
#include <QHeaderView>

class QStandardItemModel;
class QStandardItem;
class DItemDelegate;

class DheaderView : public QHeaderView
{
  Q_OBJECT

public:
  DheaderView():QHeaderView(Qt::Horizontal) {
    setSectionsClickable(true);
    //connect(this, SIGNAL(sectionClicked(int)), this, SLOT(sectionClicked(int)));
  }

//signals:
  //void clickedSection(int index);

//public slots:
  //void sectionClicked(int index);
};

class DTableView : public QTableView
{
  Q_OBJECT

public:
  DTableView(QList<QStringList> *headers = new QList<QStringList>(), QAbstractItemView::SelectionMode selectionMode = QAbstractItemView::SingleSelection);
  void setModelData(QList<QStringList> *modelData, bool readOnly = true, unsigned int orderColumn = 0, bool modelDataHasIcons = true);
  QVariant indexData(const QModelIndex &index, int role = Qt::DisplayRole, int column = -1);
  QVariant indexData(const unsigned int row, const unsigned int column, int role = Qt::DisplayRole);
  void setHeaders(QList<QStringList> *headers);
  void setHeaders(QStringList headers);
  void setHeaders();
  QList<QStringList> *getHeaders();
  QModelIndex currentIndexItem();
  void setCurrentItem(QString item, unsigned int column);
  QStandardItem *currentItem();
  QList<QStandardItem *> getRow(int row);
  int sortingColumn;
  Qt::SortOrder sortOrder;

private:
  QStandardItemModel *itemModel;
  QList<QStringList> *headersList; //tablesDTableViewHeaders->append(QStringList() << tr("Version") << NoDelegate << "" << "Right");
  bool readOnly;
  QMenu *mainMenu;
  DheaderView *dheaderView;

public slots:
  void addRow();

private slots:
  void itemChangedSlot(QStandardItem *item);
  void doubleClickedSlot(const QModelIndex &index);
  void sortingColumnSlot(int index);

signals:
  void loadStarted(QString message, unsigned int timeout, double progress);
  void loadFinished(QString message, unsigned int timeout, double progress);
  void loadProgress(QString message, unsigned int timeout, double progress);
  void itemChanged(QStandardItem *item);
  void rowDoubleClicked(QList<QVariant> row);

protected:
  void contextMenuEvent(QContextMenuEvent *event);
};

#endif // DTABLEVIEW_H
