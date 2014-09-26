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

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QApplication>
#include <QMenu>
#include <QSignalMapper>
#include <QCompleter>

#include "connectdialog.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"

#include "QDebug"

ConnectDialog::ConnectDialog(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  count = 0;
  setWindowTitle(tr("Connect to a Database Server"));
  setObjectName(windowTitle());
  setWindowIcon(QIcon(":/images/svg/network-server-database.svg"));

  comboConnectionName = new QComboBox();
  comboConnectionName->setEditable(true);
  settings.beginGroup("ServerConnections");
  QStringList connections = settings.allKeys();
  connections.removeAt(connections.indexOf("StorePassword"));

  QMap<int, QString> connectionsMap;
  foreach (QString connection, connections)
    connectionsMap.insert(StaticFunctions::explodeConnectionString(connection).at(6).split(":").at(1).toUInt() * -1, connection);
  comboConnectionName->insertItems(0, connectionsMap.values());
  connect(comboConnectionName, SIGNAL(activated(QString)), this, SLOT(fillLineEdits(QString)));

  completer = new QCompleter(connections, comboConnectionName);
#if QT_VERSION > 0x040801
    completer->setFilterMode(Qt::MatchContains);
#endif
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  comboConnectionName->setCompleter(completer);

  comboConnectionType = new QComboBox();
  comboConnectionType->insertItems(0, StaticFunctions::dbmsEnabled());
  connect(comboConnectionType, SIGNAL(activated(QString)), this, SLOT(comboConnectionTypeSlot(QString)));

  lineEditServer = new QLineEdit;
  connect(lineEditServer, SIGNAL(textChanged(QString)), this, SLOT(validateInputs()));

  spinBoxPort = new QSpinBox;
  spinBoxPort->setRange(0, 65535);

  lineEditUser = new QLineEdit;
  connect(lineEditUser, SIGNAL(textChanged(QString)), this, SLOT(validateInputs()));

  lineEditPassword = new QLineEdit;
  lineEditPassword->setEchoMode(QLineEdit::Password);
  connect(lineEditPassword, SIGNAL(textChanged(QString)), this, SLOT(validateInputs()));

  databasesMenu = new QMenu(this);
  databasesMenu->setIcon(QIcon(":/images/svg/server-database.svg"));
  connect(databasesMenu, SIGNAL(aboutToShow()), this, SLOT(databasesMenuSlot()));
  lineEditDatabase = new QLineEdit;
  databasesPushButton = new QPushButton(QIcon(":/images/svg/server-database.svg"), "", this);
  databasesPushButton->setMenu(databasesMenu);
  QHBoxLayout *databaseHlLayout = new QHBoxLayout;
  databaseHlLayout->addWidget(lineEditDatabase);
  databaseHlLayout->addWidget(databasesPushButton);
  databasesMapper = new QSignalMapper(this);
  connect(databasesMapper, SIGNAL(mapped(QString)), this, SLOT(changeDatabaseSlot(QString)));
  connectionPerformed = false;

  storePasswords = new QCheckBox(tr("Store passwords"));
  storePasswords->setCheckState(settings.value("StorePassword", "false") == "true" ? Qt::Checked : Qt::Unchecked);

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("&Connection Name:"), comboConnectionName);
  formLayout->addRow(tr("Connection &Type:"), comboConnectionType);
  formLayout->addRow(tr("&Server:"), lineEditServer);
  formLayout->addRow(tr("&Port:"), spinBoxPort);
  formLayout->addRow(tr("&User:"), lineEditUser);
  formLayout->addRow(tr("&Password:"), lineEditPassword);
  formLayout->addRow(tr("Database:"), databaseHlLayout);
  formLayout->addRow(storePasswords);
  QGroupBox *mainGroupBox = new QGroupBox(windowTitle());
  mainGroupBox->setLayout(formLayout);

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  QVBoxLayout *verticalLayout = new QVBoxLayout;
  verticalLayout->addWidget(new DTitleLabel(windowTitle()));
  verticalLayout->addWidget(mainGroupBox);
  verticalLayout->addWidget(buttonBox);
  setLayout(verticalLayout);

  fillLineEdits(comboConnectionName->currentText());
  comboConnectionName->lineEdit()->selectAll();
}

void ConnectDialog::fillLineEdits(const QString &text)
{
  QStringList params = StaticFunctions::explodeConnectionString(text);
  comboConnectionType->setCurrentIndex(comboConnectionType->findText(params.at(0)));
  lineEditUser->setText(params.at(1));
  lineEditServer->setText(params.at(2));
  spinBoxPort->setValue(params.at(3).toUInt());
  lineEditDatabase->setText(params.at(4));
  if (storePasswords->isChecked())
    lineEditPassword->setText(StaticFunctions::password(params.at(5)));
  setDBMS();
  count = params.at(6).split(":").at(1).toUInt();
}

void ConnectDialog::comboConnectionTypeSlot(const QString &text)
{
  setDBMS();
  if (text == "--")
    spinBoxPort->setValue(0);
  if (text == "MySQL" || text == "MariaDB")
    spinBoxPort->setValue(3306);
  if (text == "PostgreSQL")
    spinBoxPort->setValue(5432);
}

void ConnectDialog::databasesMenuSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  databasesMenu->clear();
  if (!serverConnection->isOpened()) {
    serverConnection->setUserName(lineEditUser->text());
    serverConnection->setHostName(lineEditServer->text());
    serverConnection->setPassword(lineEditPassword->text());
    serverConnection->setDatabase(StaticFunctions::DBMSDefaultDatabase());
    serverConnection->setPort(spinBoxPort->value());
    serverConnection->open();
    connectionPerformed = true;
  }
  foreach (QString database, serverConnection->getDatabases()) {
    QAction *action = databasesMenu->addAction(database);
    action->setCheckable(true);
    action->setChecked(action->text() == lineEditDatabase->text());
    connect(action, SIGNAL(triggered()), databasesMapper, SLOT(map()));
    databasesMapper->setMapping(action, database);
  }
  QApplication::restoreOverrideCursor();
}

void ConnectDialog::changeDatabaseSlot(QString database)
{
  lineEditDatabase->setText(database);
  serverConnection->changeDatabase(database);
  getValues();
}

void ConnectDialog::setDBMS()
{
  if (comboConnectionType->currentText() == "--")
    qApp->setProperty("DBMSType", StaticFunctions::Undefined);
  if (comboConnectionType->currentText() == "MySQL")
    qApp->setProperty("DBMSType", StaticFunctions::MySQL);
  if (comboConnectionType->currentText() == "MariaDB")
    qApp->setProperty("DBMSType", StaticFunctions::MariaDB);
  if (comboConnectionType->currentText() == "PostgreSQL")
    qApp->setProperty("DBMSType", StaticFunctions::PostgreSQL);
}

QList<QString> ConnectDialog::getValues()
{
  QList<QString> listValues;
  listValues.append(comboConnectionType->currentText());
  listValues.append(lineEditServer->text());
  listValues.append(QString("%1").arg(spinBoxPort->value()));
  listValues.append(lineEditUser->text());
  listValues.append(lineEditPassword->text());
  listValues.append(lineEditDatabase->text());
  settings.setValue(comboConnectionName->currentText(), QString("%1:%2@%3:%4/%5 %6 Count:%7").arg(comboConnectionType->currentText()).arg(lineEditUser->text())
                    .arg(lineEditServer->text()).arg(spinBoxPort->value()).arg(lineEditDatabase->text())
                    .arg(storePasswords->isChecked() ? StaticFunctions::password(lineEditPassword->text(), true) : "").arg(++count));
  settings.setValue("StorePassword", storePasswords->isChecked());
  return listValues;
}

bool ConnectDialog::getConnectionPerformed()
{
  if (connectionPerformed)
    serverConnection->setDatabase(lineEditDatabase->text());
  return connectionPerformed;
}

void ConnectDialog::validateInputs()
{
  buttonBox->button(QDialogButtonBox::Ok)->setEnabled((!lineEditServer->text().isEmpty() && !lineEditUser->text().isEmpty()));
}
