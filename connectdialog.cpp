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
#include <QMessageBox>

#include "connectdialog.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "fileselector.h"

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
  connections.removeAt(connections.indexOf("SortConnectionList"));

  sortConnectionList = new QCheckBox(tr("Sort connection list by used times"));
  sortConnectionList->setCheckState(settings.value("SortConnectionList", "false") == "true" ? Qt::Checked : Qt::Unchecked);

  if (sortConnectionList->isChecked()) {
    QMap<int, QString> connectionsMap;
    foreach (QString connection, connections)
      connectionsMap.insertMulti(StaticFunctions::explodeConnectionString(connection).at(5).toUInt() * -1, connection);
    comboConnectionName->insertItems(0, connectionsMap.values());
    connect(comboConnectionName, SIGNAL(activated(QString)), this, SLOT(fillLineEdits(QString)));
  } else {
    comboConnectionName->insertItems(0, connections);
  }

  completer = new QCompleter(connections, comboConnectionName);
  completer->setFilterMode(Qt::MatchContains);
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
  QHBoxLayout *passwordHlLayout = new QHBoxLayout;
  passwordHlLayout->addWidget(lineEditPassword);
  maskPassword = new QPushButton(QIcon(":/images/svg/object-locked-2.svg"), "", this);
  maskPassword->setCheckable(true);
  connect(maskPassword, SIGNAL(toggled(bool)), this, SLOT(maskPasswordToggled(bool)));
  passwordHlLayout->addWidget(maskPassword);

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

  collationsMenu = new QMenu(this);
  collationsMenu->setIcon(QIcon(":/images/svg/character-set.svg"));
  connect(collationsMenu, SIGNAL(aboutToShow()), this, SLOT(collatoinsMenuSlot()));
  lineEditCollation = new QLineEdit;
  collationPushButton = new QPushButton(QIcon(":/images/svg/character-set.svg"), "", this);
  collationPushButton->setMenu(collationsMenu);
  QHBoxLayout *collationHlLayout = new QHBoxLayout;
  collationHlLayout->addWidget(lineEditCollation);
  collationHlLayout->addWidget(collationPushButton);

  collationsMapper = new QSignalMapper(this);
  connect(collationsMapper, SIGNAL(mapped(QString)), this, SLOT(changeCollationSlot(QString)));

  useASSLConnection = new QCheckBox(tr("Use a SSL connection"));
  useASSLConnection->setCheckState(settings.value("SSLConnection", "false") == "true" ? Qt::Checked : Qt::Unchecked);
  connect(useASSLConnection, SIGNAL(stateChanged(int)), this, SLOT(useASSLConnectionStateChanged(int)));

  fileSelectorClientKey = new FileSelector(FileSelectorContexts::PEMFile, tr("SSL Client Key file:"), false, QIcon(":/images/svg/application-x-pem-key.svg"));
  fileSelectorClientCert = new FileSelector(FileSelectorContexts::PEMFile, tr("SSL Client Cert file:"), false, QIcon(":/images/svg/application-x-pem-key.svg"));
  useASSLConnectionStateChanged(settings.value("SSLConnection", 0).toInt());

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("&Connection Name:"), comboConnectionName);
  formLayout->addRow(sortConnectionList);
  formLayout->addRow(tr("Connection &Type:"), comboConnectionType);
  formLayout->addRow(tr("&Server:"), lineEditServer);
  formLayout->addRow(tr("&Port:"), spinBoxPort);
  formLayout->addRow(tr("&User:"), lineEditUser);
  formLayout->addRow(tr("Password:"), passwordHlLayout);
  formLayout->addRow(tr("Database:"), databaseHlLayout);
  formLayout->addRow(tr("Collation:"), collationHlLayout);
  formLayout->addRow(storePasswords);
  formLayout->addRow(useASSLConnection);
  formLayout->addRow(fileSelectorClientKey);
  formLayout->addRow(fileSelectorClientCert);
  QGroupBox *mainGroupBox = new QGroupBox(windowTitle());
  mainGroupBox->setLayout(formLayout);

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  buttonBox->addButton(tr("Ping"), QDialogButtonBox::ActionRole);
  buttonBox->addButton(tr("New connection"), QDialogButtonBox::ActionRole);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
  connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(actionRoleSlot(QAbstractButton*)));

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
  comboConnectionType->setCurrentIndex(comboConnectionType->findText(params.at(0)));
  lineEditUser->setText(params.at(1));
  lineEditUser->setToolTip(lineEditUser->text());
  lineEditServer->setText(params.at(2));
  lineEditServer->setToolTip(lineEditServer->text());
  spinBoxPort->setValue(params.at(3).toUInt());
  lineEditDatabase->setText(params.at(4));
  lineEditDatabase->setToolTip(lineEditDatabase->text());
  if (storePasswords->isChecked())
    lineEditPassword->setText(StaticFunctions::password(params.at(10)));
  setDBMS();
  count = params.at(5).toInt();
  lineEditCollation->setText(params.at(6));
  lineEditCollation->setToolTip(lineEditCollation->text());
  useASSLConnection->setCheckState(params.at(7) == "1" ? Qt::Checked : Qt::Unchecked);
  fileSelectorClientKey->setFileName(params.at(8));
  fileSelectorClientCert->setFileName(params.at(9));
}

void ConnectDialog::comboConnectionTypeSlot(const QString &text)
{
  setDBMS();
  if (text == "--")
    spinBoxPort->setValue(0);
  if (text == "MySQL" || text == "MariaDB")
    spinBoxPort->setValue(3306);
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
    serverConnection->setCharacterSet(lineEditCollation->text().split("|").at(0));
    serverConnection->setCollation(lineEditCollation->text().split("|").at(1));
    serverConnection->setUseSSL(useASSLConnection->isChecked());
    serverConnection->setKeyFile(fileSelectorClientKey->getFileName());
    serverConnection->setCertFile(fileSelectorClientCert->getFileName());
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
  lineEditDatabase->setToolTip(lineEditDatabase->text());
  serverConnection->changeDatabase(database);
  getValues();
}

void ConnectDialog::collatoinsMenuSlot()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  collationsMenu->clear();
  if (!serverConnection->isOpened()) {
    serverConnection->setUserName(lineEditUser->text());
    serverConnection->setHostName(lineEditServer->text());
    serverConnection->setPassword(lineEditPassword->text());
    serverConnection->setDatabase(StaticFunctions::DBMSDefaultDatabase());
    serverConnection->setPort(spinBoxPort->value());
    serverConnection->setCharacterSet(lineEditCollation->text().split("|").at(0));
    serverConnection->setCollation(lineEditCollation->text().split("|").at(1));
    serverConnection->setUseSSL(useASSLConnection->isChecked());
    serverConnection->setKeyFile(fileSelectorClientKey->getFileName());
    serverConnection->setCertFile(fileSelectorClientCert->getFileName());
    serverConnection->open();
    connectionPerformed = true;
  }
  QList<QStringList> *collations = serverConnection->getCollationsApplicability();
  for (int row = 0; row < collations->count() - 1; row++) {
    QAction *action = collationsMenu->addAction(collations->at(row).at(1) + "|" + collations->at(row).at(0));
    action->setCheckable(true);
    action->setChecked(action->text() == lineEditCollation->text());
    connect(action, SIGNAL(triggered()), collationsMapper, SLOT(map()));
    collationsMapper->setMapping(action, collations->at(row).at(1) + "|" + collations->at(row).at(0));
  }
  QApplication::restoreOverrideCursor();
}

void ConnectDialog::changeCollationSlot(QString collation)
{
  lineEditCollation->setText(collation);
  lineEditCollation->setToolTip(lineEditCollation->text());
  serverConnection->setCharsetAndCollation(collation.split("|").at(0), collation.split("|").at(1));
  getValues();
}

void ConnectDialog::useASSLConnectionStateChanged(int state)
{
  fileSelectorClientKey->setEnabled(state);
  fileSelectorClientCert->setEnabled(state);
}

void ConnectDialog::maskPasswordToggled(bool checked)
{
  lineEditPassword->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
  maskPassword->setIcon(checked ? QIcon(":/images/svg/object-unlocked-2.svg") : QIcon(":/images/svg/object-locked-2.svg"));
}

void ConnectDialog::actionRoleSlot(QAbstractButton *button)
{
  if (button->text() == tr("Ping")) {
    if (!serverConnection->isOpened()) {
      serverConnection->setUserName(lineEditUser->text());
      serverConnection->setHostName(lineEditServer->text());
      serverConnection->setPassword(lineEditPassword->text());
      serverConnection->setDatabase(StaticFunctions::DBMSDefaultDatabase());
      serverConnection->setPort(spinBoxPort->value());
      serverConnection->setCharacterSet(lineEditCollation->text().split("|").at(0));
      serverConnection->setCollation(lineEditCollation->text().split("|").at(1));
      serverConnection->setUseSSL(useASSLConnection->isChecked());
      serverConnection->setKeyFile(fileSelectorClientKey->getFileName());
      serverConnection->setCertFile(fileSelectorClientCert->getFileName());
      serverConnection->open();
      connectionPerformed = true;
    }
    if (serverConnection->ping() == 0)
      QMessageBox::information(this, tr("Ping successful to: %1").arg(serverConnection->getHostName()), tr("Ping successful"));
  } else if (button->text() == tr("New connection")) {
    comboConnectionName->setCurrentText("");
    comboConnectionType->setCurrentIndex(0);
    lineEditUser->clear();
    lineEditServer->clear();
    spinBoxPort->setValue(3306);
    lineEditDatabase->clear();
    lineEditCollation->clear();
    useASSLConnection->setCheckState(Qt::Checked);
    fileSelectorClientKey->setFileName("");
    fileSelectorClientCert->setFileName("");
    lineEditPassword->clear();
  }
}

void ConnectDialog::setDBMS()
{
  if (comboConnectionType->currentText() == "--")
    serverConnection->setDBMSType(StaticFunctions::Undefined);
  if (comboConnectionType->currentText() == "MySQL")
    serverConnection->setDBMSType(StaticFunctions::MySQL);
  if (comboConnectionType->currentText() == "MariaDB")
    serverConnection->setDBMSType(StaticFunctions::MariaDB);
}

QList<QString> ConnectDialog::getValues()
{
  QList<QString> listValues;
  //0 - Connection name
  //1 - User
  //2 - Host
  //3 - Port
  //4 - Database
  //5 - Conexion count -- No parsed but keeped the space.
  //6 - Collation
  //7 - UseSSL
  //8 - KeyFile
  //9 - CertFile
  //10 - Password
  listValues.append(comboConnectionName->currentText());
  listValues.append(lineEditUser->text());
  listValues.append(lineEditServer->text());
  listValues.append(QString("%1").arg(spinBoxPort->value()));
  listValues.append(lineEditDatabase->text());
  listValues.append("");
  listValues.append(lineEditCollation->text());
  listValues.append(QString("%1").arg(useASSLConnection->isChecked()));
  listValues.append(fileSelectorClientKey->getFileName().isEmpty() ? "-" : fileSelectorClientKey->getFileName());
  listValues.append(fileSelectorClientCert->getFileName().isEmpty() ? "-" : fileSelectorClientCert->getFileName());
  listValues.append(lineEditPassword->text());
  //listValues.append(comboConnectionType->currentText());

  //Using the ServerConnections
  settings.setValue(comboConnectionName->currentText()
                    , QString("%1:%2@%3:%4/%5 Count:%6 Collation:%7 UseSSL:%8 KeyFile:%9 CertFile:%10 Password:%11")
                    .arg(comboConnectionType->currentText())
                    .arg(lineEditUser->text())
                    .arg(lineEditServer->text())
                    .arg(spinBoxPort->value())
                    .arg(lineEditDatabase->text())
                    .arg(++count)
                    .arg(lineEditCollation->text())
                    .arg(useASSLConnection->isChecked())
                    .arg(fileSelectorClientKey->getFileName().isEmpty() ? "-" : fileSelectorClientKey->getFileName())
                    .arg(fileSelectorClientCert->getFileName().isEmpty() ? "-" : fileSelectorClientCert->getFileName())
                    .arg(storePasswords->isChecked() ? StaticFunctions::password(lineEditPassword->text(), true) : "")
                    );
  settings.setValue("StorePassword", storePasswords->isChecked());
  settings.setValue("SortConnectionList", sortConnectionList->isChecked());
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
