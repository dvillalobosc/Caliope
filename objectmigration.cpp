#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QTreeWidget>
#include <QTimer>
#include <QApplication>

#include "objectmigration.h"
#include "dtitlelabel.h"
#include "basetexteditor.h"

ObjectMigration::ObjectMigration(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon::fromTheme("find-next", QIcon(":/images/svg/go-next-view.svg")));
  QWidget *widMain = new QWidget;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  groupBoxAction = new QGroupBox(this);
  QVBoxLayout *thirdLayout = new QVBoxLayout;

  migratePushButton = new QPushButton;
  connect(migratePushButton, SIGNAL(clicked()), this, SLOT(migratePushButtonSlot()));
  thirdLayout->addWidget(migratePushButton);
  optionDROP = new QCheckBox;
  thirdLayout->addWidget(optionDROP);

  thirdLayout->addStretch();
  groupBoxAction->setLayout(thirdLayout);
  QHBoxLayout *secondLayout = new QHBoxLayout;
  objectsListWidget = new QTreeWidget;
  objectsListWidget->setFixedWidth(300);
  connect(objectsListWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  connect(objectsListWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  secondLayout->addWidget(objectsListWidget);
  secondLayout->addWidget(groupBoxAction);
  mainVLayout->addLayout(secondLayout);
  resutlEditor = new BaseTextEditor(EditorTypes::NoEditor);
  resutlEditor->setWordWrapMode(QTextOption::NoWrap);
  secondLayout->addWidget(resutlEditor);

  retranslateUi();
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
  QTimer::singleShot(0, this, SLOT(fillDatabasesSlot()));
}

void ObjectMigration::retranslateUi()
{
  setWindowTitle(tr("Object Migration"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  groupBoxAction->setTitle(tr("Options"));
  objectsListWidget->setWindowTitle(tr("Objects"));
  objectsListWidget->setHeaderLabel(objectsListWidget->windowTitle());
  optionDROP->setText(tr("Replace on destination"));
  migratePushButton->setText(tr("Migrate"));
}

void ObjectMigration::fillDatabasesSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  databases.clear();
  foreach (QString database, serverConnection->getDatabases(true)) {
    QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(database), ItemTypes::Database);
    item->setIcon(0, QIcon(":/images/svg/server-database.svg"));
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item->setCheckState(0, Qt::Unchecked);
    databases.append(item);
  }
  objectsListWidget->clear();
  objectsListWidget->insertTopLevelItems(0, databases);
  objectsListWidget->resizeColumnToContents(0);
  QApplication::restoreOverrideCursor();
}

void ObjectMigration::itemActivatedSlot(QTreeWidgetItem *item, int column)
{
  if (item->type() == ItemTypes::Database) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    foreach (QTreeWidgetItem *tableItem, databases)
      if (tableItem->parent() == item)
        tableItem->setCheckState(column, item->checkState(column));
    if (item->childCount() == 0) {
      foreach (QString tables, serverConnection->tables()->list()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Table);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      foreach (QString tables, serverConnection->views()->list()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::View);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/view.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      foreach (QString tables, serverConnection->events()->list()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Event);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon::fromTheme("x-office-calendar", QIcon(":/images/svg/view-calendar-upcoming-events.svg")));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      foreach (QString tables, serverConnection->routines()->list()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Routine);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/server-database.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      foreach (QString tables, serverConnection->triggers()->list()) {
        QTreeWidgetItem *itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Trigger);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/server-database.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
    }
    QApplication::restoreOverrideCursor();
  }
}

void ObjectMigration::migratePushButtonSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  foreach (QTreeWidgetItem *item, databases) {
    if (item->checkState(0) == Qt::Checked && item->parent()) {
      switch (item->type()) {
      case ItemTypes::Table:
        if (optionDROP->isChecked())
          resutlEditor->setPlainText(resutlEditor->toPlainText() += "\nDROP TABLE IF EXISTS " + item->text(0) + ";");
        resutlEditor->setPlainText(resutlEditor->toPlainText() += "\n" + serverConnection->tables()->getDefinition(item->text(0)) + ";");
        break;
      case ItemTypes::View:
        if (optionDROP->isChecked())
          resutlEditor->setPlainText(resutlEditor->toPlainText() += "\nDROP VIEW IF EXISTS " + item->text(0) + ";");
        resutlEditor->setPlainText(resutlEditor->toPlainText() += "\n" + serverConnection->views()->getDefinition(item->text(0)) + ";");
        break;
      default:
        break;
      }
    }
  }
  QApplication::restoreOverrideCursor();
}

