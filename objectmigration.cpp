#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QTreeWidget>
#include <QTimer>
#include <QApplication>
#include <QMessageBox>

#include "objectmigration.h"
#include "dtitlelabel.h"
#include "basetexteditor.h"
#include "connectdialog.h"

#include "qdebug.h"

ObjectMigration::ObjectMigration(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;

  secondaryServerConnection = new DBMS(false);
  //connect(secondaryServerConnection, SIGNAL(statusBarMessage(QString)), this, SLOT(statusBarMessageSlot(QString)));

  setWindowIcon(QIcon::fromTheme("find-next", QIcon(":/images/svg/go-next-view.svg")));
  QWidget *widMain = new QWidget;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  groupBoxAction = new QGroupBox(this);
  QHBoxLayout *thirdLayout = new QHBoxLayout;
  groupBoxAction->setLayout(thirdLayout);
  mainVLayout->addWidget(groupBoxAction);

  migratePushButton = new QPushButton;
  connect(migratePushButton, SIGNAL(clicked()), this, SLOT(migratePushButtonSlot()));
  migratePushButton->setIcon(QIcon::fromTheme("find-next", QIcon(":/images/svg/go-next-view.svg")));
  thirdLayout->addWidget(migratePushButton);
  optionDROP = new QCheckBox;
  thirdLayout->addWidget(optionDROP);
  optionExportData = new QCheckBox;
  thirdLayout->addWidget(optionExportData);
  optionFOREIGN_KEY_CHECKS = new QCheckBox;
  thirdLayout->addWidget(optionFOREIGN_KEY_CHECKS);
  optionPreview = new QCheckBox;
  thirdLayout->addWidget(optionPreview);
  stopMigrationPushButton = new QPushButton;
  connect(stopMigrationPushButton, SIGNAL(clicked()), this, SLOT(stopMigrationPushButtonSlot()));
  stopMigrationPushButton->setIcon(QIcon::fromTheme("process-stop", QIcon(":/images/svg/process-stop-7.svg")));
  QFrame* separatorFrame = new QFrame();
  separatorFrame->setFrameShape(QFrame::VLine);
  thirdLayout->addWidget(separatorFrame);
  thirdLayout->addWidget(stopMigrationPushButton);

  thirdLayout->addStretch();
  QHBoxLayout *secondLayout = new QHBoxLayout;
  objectsListWidget = new QTreeWidget;
  objectsListWidget->setFixedWidth(300);
  connect(objectsListWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  connect(objectsListWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(itemActivatedSlot(QTreeWidgetItem*,int)));
  secondLayout->addWidget(objectsListWidget);
  mainVLayout->addLayout(secondLayout);
  resultEditor = new BaseTextEditor(EditorTypes::NoEditor);
  resultEditor->setMaximumBlockCount(5000);
  resultEditor->setWordWrapMode(QTextOption::NoWrap);
  secondLayout->addWidget(resultEditor);

  retranslateUi();
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
  statementsToExecute = new QStringList();
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
  optionExportData->setText(tr("Export data"));
  optionFOREIGN_KEY_CHECKS->setText(tr("Skip Foreign Key checks"));
  optionPreview->setText(tr("Preview"));
  stopMigrationPushButton->setText(tr("Stop migration"));
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
  QTreeWidgetItem *itemChild;
  if (item->type() == ItemTypes::Database) {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    emit loadProgress(0);
    foreach (QTreeWidgetItem *tableItem, databases)
      if (tableItem->parent() == item)
        tableItem->setCheckState(column, item->checkState(column));
    if (item->childCount() == 0) {
      foreach (QString tables, serverConnection->tables()->list(item->text(0))) {
        itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Table);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/table.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      emit loadProgress(16);
      foreach (QString tables, serverConnection->views()->list(item->text(0))) {
        itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::View);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/view.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      emit loadProgress(32);
      foreach (QString tables, serverConnection->events()->list(item->text(0))) {
        itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Event);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon::fromTheme("x-office-calendar", QIcon(":/images/svg/view-calendar-upcoming-events.svg")));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      emit loadProgress(48);
      foreach (QString tables, serverConnection->functions()->list(item->text(0))) {
        itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Function);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/system-run-5.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      emit loadProgress(64);
      foreach (QString tables, serverConnection->procedures()->list(item->text(0))) {
        itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Procedure);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/system-run-5.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      emit loadProgress(80);
      foreach (QString tables, serverConnection->triggers()->list(item->text(0))) {
        itemChild = new QTreeWidgetItem(item, QStringList(tables), ItemTypes::Trigger);
        itemChild->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        itemChild->setIcon(0, QIcon(":/images/svg/server-database.svg"));
        itemChild->setCheckState(0, Qt::Checked);
        databases.append(itemChild);
      }
      emit loadProgress(100);
    }
    QApplication::restoreOverrideCursor();
  }
}

void ObjectMigration::migratePushButtonSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  emit loadProgress(0);
  statementsToExecute->clear();
  counter = 0;
  int counter2 = 0;
  if (optionFOREIGN_KEY_CHECKS->isChecked())
    statementsToExecute->append("SET FOREIGN_KEY_CHECKS := 0");
  foreach (QTreeWidgetItem *item, databases) {
    if (item->checkState(0) == Qt::Checked) {
      switch (item->type()) {
      case ItemTypes::Database:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP DATABASE IF EXISTS " + item->text(0));
        statementsToExecute->append(serverConnection->databases()->getDefinition(item->text(0)));
        break;
      case ItemTypes::Table:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP TABLE IF EXISTS " + item->text(0));
        statementsToExecute->append("USE " + item->text(0).split(".").at(0));
        statementsToExecute->append(serverConnection->tables()->getDefinition(item->text(0)));
        if (optionExportData->isChecked())
          statementsToExecute->append(serverConnection->tables()->getTableDataToInsert(item->text(0)));
        break;
      case ItemTypes::View:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP VIEW IF EXISTS " + item->text(0));
        statementsToExecute->append("USE " + item->text(0).split(".").at(0));
        statementsToExecute->append(serverConnection->views()->getDefinition(item->text(0)));
        break;
      case ItemTypes::Event:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP EVENT IF EXISTS " + item->text(0));
        statementsToExecute->append("USE " + item->text(0).split(".").at(0));
        statementsToExecute->append(serverConnection->events()->getDefinition(item->text(0)));
        break;
      case ItemTypes::Function:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP FUNCTION IF EXISTS " + item->text(0));
        statementsToExecute->append("USE " + item->text(0).split(".").at(0));
        statementsToExecute->append(serverConnection->functions()->getDefinition(item->text(0)));
        break;
      case ItemTypes::Procedure:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP PROCEDURE IF EXISTS " + item->text(0));
        statementsToExecute->append("USE " + item->text(0).split(".").at(0));
        statementsToExecute->append(serverConnection->procedures()->getDefinition(item->text(0)));
        break;
      case ItemTypes::Trigger:
        if (optionDROP->isChecked())
          statementsToExecute->append("DROP TRIGGER IF EXISTS " + item->text(0));
        statementsToExecute->append("USE " + item->text(0).split(".").at(0));
        statementsToExecute->append(serverConnection->triggers()->getDefinition(item->text(0)));
        break;
      default:
        break;
      }
    }
    emit loadProgress((int) (counter2 * 100 / databases.count()));
    counter2++;
  }
  if (optionFOREIGN_KEY_CHECKS->isChecked())
    statementsToExecute->append("SET FOREIGN_KEY_CHECKS := 1");
  emit loadProgress(100);
  QApplication::restoreOverrideCursor();

  ConnectDialog *connectFrom = new ConnectDialog(secondaryServerConnection);
  if (!optionPreview->isChecked()) {
    if (connectFrom->exec() == QDialog::Accepted) {
      if (!connectFrom->getConnectionPerformed()) {
        if (secondaryServerConnection->isOpened())
          secondaryServerConnection->close();
        //0 - Connection name
        //1 - User
        //2 - Host
        //3 - Port
        //4 - Database
        //5 - Conexion count
        //6 - Collation
        //7 - UseSSL
        //8 - KeyFile
        //9 - CertFile
        //10 - Password
        secondaryServerConnection->setUserName(connectFrom->getValues().at(1));
        secondaryServerConnection->setHostName(connectFrom->getValues().at(2));
        secondaryServerConnection->setPassword(connectFrom->getValues().at(10));
        secondaryServerConnection->setDatabase(connectFrom->getValues().at(4));
        secondaryServerConnection->setPort(connectFrom->getValues().at(3).toUInt());
        secondaryServerConnection->setCharacterSet(connectFrom->getValues().at(6).split("|").at(0));
        secondaryServerConnection->setCollation(connectFrom->getValues().at(6).split("|").at(1));
        secondaryServerConnection->setUseSSL(connectFrom->getValues().at(7).toInt());
        secondaryServerConnection->setKeyFile(connectFrom->getValues().at(8));
        secondaryServerConnection->setCertFile(connectFrom->getValues().at(9));
        if (!secondaryServerConnection->open())
          QMessageBox::critical(this, tr("Cannot connect to the server"), secondaryServerConnection->lastError());
      }
    }
  }
  resultEditor->clear();
  QTimer::singleShot(0, this, SLOT(statementsToExecuteSlot()));
}

void ObjectMigration::statementsToExecuteSlot()
{
  if (statementsToExecute->count() > counter) {
    if (optionPreview->isChecked())
      resultEditor->appendPlainText(statementsToExecute->at(counter));
    else
      resultEditor->appendPlainText(secondaryServerConnection->outputAsVV(statementsToExecute->at(counter)));
    emit loadProgress((int) (counter * 100 / statementsToExecute->count()));
    counter++;
    QTimer::singleShot(0, this, SLOT(statementsToExecuteSlot()));
  } else {
    emit loadProgress(100);
  }
}

void ObjectMigration::stopMigrationPushButtonSlot()
{
  counter = statementsToExecute->count() + 1;
  emit loadProgress(0);
}

