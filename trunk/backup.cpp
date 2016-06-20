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

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QCheckBox>
#include <QProcess>
#include <QMessageBox>

#include "backup.h"
#include "dtitlelabel.h"
#include "dmessagelabel.h"
#include "fileselector.h"
#include "staticfunctions.h"

#include <QDebug>

Backup::Backup(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));
  QWidget *widMain = new QWidget;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  QHBoxLayout *fileLayout = new QHBoxLayout;
  QHBoxLayout *databaseLayout = new QHBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);
  dMessageLabel = new DMessageLabel(MessageTypes::Information);
  mainVLayout->addWidget(dMessageLabel);
  gridChecks = new QGridLayout;
  databasesListWidget = new QListWidget;
  databasesListWidget->setMaximumWidth(200);
  connect(databasesListWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(disbaleBackItIp()));
  foreach (QString database, serverConnection->getDatabases()) {
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/svg/server-database.svg"), database);
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    item->setCheckState(Qt::Unchecked);
    databasesListWidget->addItem(item);
  }
  foreach (QString option, settings.value("Backup/Databases", QStringList()).toStringList())
    if (!option.isEmpty())
      for (int counter = 0; counter < databasesListWidget->count(); counter++)
        if (databasesListWidget->item(counter)->text() == option)
          databasesListWidget->item(counter)->setCheckState(Qt::Checked);
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    createCheckBoxesMariaDB();
    foreach (QString option, settings.value("Backup/Options", QStringList()).toStringList())
      if (!option.isEmpty())
        for (int counter = 0; counter < gridChecks->count(); ++counter) {
          item = qobject_cast<QCheckBox *>(gridChecks->itemAt(counter)->widget());
          if (item->text() == option)
            item->setChecked(true);
        }
    break;
  case StaticFunctions::Undefined:
  default:
    QMessageBox::information(this, tr("Cannot backup this kind of database"), tr("Cannot backup this kind of database"));
    break;
  }
  databaseLayout->addWidget(databasesListWidget);
  databaseLayout->addLayout(gridChecks);
  databaseLayout->addStretch();
  mainVLayout->addLayout(databaseLayout);
  fileSelector = new FileSelector(FileSelectorContexts::BackupFile);
  fileLayout->addWidget(fileSelector);
  connect(fileSelector, SIGNAL(changed()), this, SLOT(disbaleBackItIp()));
  backItUpPushButton = new QPushButton;
  backItUpPushButton->setEnabled(false);
  connect(backItUpPushButton, SIGNAL(clicked()), this, SLOT(backItUpSlot()));
  disbaleBackItIp();
  fileLayout->addWidget(backItUpPushButton);
  mainVLayout->addLayout(fileLayout);
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
}

void Backup::retranslateUi()
{
  setWindowTitle(tr("Backup"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  dMessageLabel->setText(tr("Note that there are options that exclude others."));
  fileSelector->setText(tr("&File:"));
  backItUpPushButton->setText(tr("Create Backup"));
}

void Backup::disbaleBackItIp()
{
  bool itemEnabled = false;
  for (int counter = 0; counter < databasesListWidget->count(); counter++) {
    if (databasesListWidget->item(counter)->checkState() == Qt::Checked) {
      itemEnabled = true;
      break;
    }
  }
  if (fileSelector->isEmpty() || !itemEnabled)
    backItUpPushButton->setEnabled(false);
  else
    backItUpPushButton->setEnabled(true);
}

void Backup::allDatabasesSlot()
{
  foreach(QListWidgetItem *item, databasesListWidget->selectedItems())
    item->setSelected(false);
  databasesListWidget->setEnabled(!allDatabases->isChecked());
}

void Backup::backItUpSlot()
{
  QStringList options;
  proc = new QProcess;
  connect(proc, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardErrorSlot()));
  connect(proc, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finishedSlot(int)));
  QStringList arguments;
  arguments << "--user=" + serverConnection->getUserName();
  arguments << "--host=" + serverConnection->getHostName();
  arguments << "--password=" + serverConnection->getPassword();
//  arguments << "--port=" + serverConnection->getPort();
  arguments << "--default-character-set=utf8";
  //  arguments << "--port=" + serverConnection->getPort();
  arguments << "--result-file=" + fileSelector->getFileName();
  for (int counter = 0; counter < gridChecks->count(); ++counter) {
    item = qobject_cast<QCheckBox *>(gridChecks->itemAt(counter)->widget());
    if (item->isChecked()) {
      arguments << item->text();
      options << item->text();
    }
  }
  settings.setValue("Backup/Options", options);
  options.clear();

  if (allDatabases->isChecked()) {
    arguments << "--all-databases";
  } else {
    arguments << "--databases";
//    foreach(QListWidgetItem *item, databasesListWidget->selectedItems())
//      arguments << item->text();
    for (int counter = 0; counter < databasesListWidget->count(); counter++)
      if (databasesListWidget->item(counter)->checkState() == Qt::Checked)
        arguments << databasesListWidget->item(counter)->text();
  }
  settings.setValue("Backup/Databases", options);
  QApplication::setOverrideCursor(Qt::WaitCursor);
  proc->start("mysqldump", arguments);
  proc->waitForFinished();
  QApplication::restoreOverrideCursor();
}

void Backup::finishedSlot(int exitCode)
{
  if (exitCode == QProcess::NormalExit)
    QMessageBox::information(this, windowTitle(), tr("Backup done."));
}

void Backup::readyReadStandardErrorSlot()
{
  QApplication::restoreOverrideCursor();
  QMessageBox::warning(this, windowTitle(), QString(proc->readAllStandardError()));
  proc->close();
}

void Backup::createCheckBoxesMariaDB()
{
  int column = 0;
  int row = 0;

  addDropDatabase = new QCheckBox("--add-drop-database");
  addDropDatabase->setToolTip(tr("Add a DROP DATABASE statement before each CREATE DATABASE statement"));
  addDropDatabase->setStatusTip(addDropDatabase->toolTip());
  addDropDatabase->setWhatsThis(addDropDatabase->toolTip());
  addDropDatabase->setAttribute(Qt::WA_AlwaysShowToolTips, true);
  gridChecks->addWidget(addDropDatabase, 0, 0, Qt::AlignLeft);

  addDropTable = new QCheckBox("--add-drop-table");
  addDropTable->setToolTip(tr("Add a DROP TABLE statement before each CREATE TABLE statement"));
  gridChecks->addWidget(addDropTable, ++row, column, Qt::AlignLeft);

  addDropTrigger = new QCheckBox("--add-drop-trigger");
  addDropTrigger->setToolTip(tr("Add a DROP TRIGGER statement before each CREATE TRIGGER statement"));
  gridChecks->addWidget(addDropTrigger, ++row, column, Qt::AlignLeft);

  addLocks = new QCheckBox("--add-locks");
  addLocks->setToolTip(tr("Surround each table dump with LOCK TABLES and UNLOCK TABLES statements"));
  gridChecks->addWidget(addLocks, ++row, column, Qt::AlignLeft);

  allDatabases = new QCheckBox("--all-databases");
  allDatabases->setToolTip(tr("Backup all databases"));
  connect(allDatabases, SIGNAL(clicked()), this, SLOT(allDatabasesSlot()));
  gridChecks->addWidget(allDatabases, ++row, column, Qt::AlignLeft);

  allTablespaces = new QCheckBox("--all-tablespaces");
  allTablespaces->setToolTip(tr("Adds to a table dump all SQL statements needed to create any tablespaces used by an NDB Cluster table"));
  gridChecks->addWidget(allTablespaces, ++row, column, Qt::AlignLeft);

  allowKeywords = new QCheckBox("--allow-keywords");
  allowKeywords->setToolTip(tr("Allow creation of column names that are keywords"));
  gridChecks->addWidget(allowKeywords, ++row, column, Qt::AlignLeft);

  //  --bind-address=ip_address Use the specified network interface to connect to the MySQL Server

  comments = new QCheckBox("--comments");
  comments->setToolTip(tr("Add comments to the dump file"));
  gridChecks->addWidget(comments, ++row, column, Qt::AlignLeft);

  compact = new QCheckBox("--compact");
  compact->setToolTip(tr("Produce more compact output"));
  gridChecks->addWidget(compact, ++row, column, Qt::AlignLeft);

  //  --compatible=name[,name,...] Produce output that is more compatible with other database systems or with older MySQL servers

  compliteInsert = new QCheckBox("--complete-insert");
  compliteInsert->setToolTip(tr("Use complete INSERT statements that include column names"));
  gridChecks->addWidget(compliteInsert, ++row, column, Qt::AlignLeft);

  createOptions = new QCheckBox("--create-options");
  createOptions->setToolTip(tr("Include all MySQL-specific table options in CREATE TABLE statements"));
  gridChecks->addWidget(createOptions, ++row, column, Qt::AlignLeft);

  //  --databases Dump several databases
  //  --debug[=debug_options] Write a debugging log
  //  --debug-check Print debugging information when the program exits
  //  --debug-info Print debugging information, memory and CPU statistics when the program exits

  delayedInsert = new QCheckBox("--delayed-insert");
  delayedInsert->setToolTip(tr("Write INSERT DELAYED statements rather than INSERT statements"));
  gridChecks->addWidget(delayedInsert, ++row, column, Qt::AlignLeft);

  deleteMasterLogs = new QCheckBox("--delete-master-logs");
  deleteMasterLogs->setToolTip(tr("On a master replication server, delete the binary logs after performing the dump operation"));
  gridChecks->addWidget(deleteMasterLogs, ++row, column, Qt::AlignLeft);

  disableKeys = new QCheckBox("--disable-keys");
  disableKeys->setToolTip(tr("For each table, surround the INSERT statements with statements to disable and enable keys"));
  gridChecks->addWidget(disableKeys, ++row, column, Qt::AlignLeft);

  dumpDate = new QCheckBox("--dump-date");
  dumpDate->setToolTip(tr("Include dump date as 'Dump completed on' comment if --comments is given"));
  gridChecks->addWidget(dumpDate, ++row, column, Qt::AlignLeft);

  events = new QCheckBox("--events");
  events->setToolTip(tr("Dump events from the dumped databases"));
  gridChecks->addWidget(events, ++row, column, Qt::AlignLeft);

  extendedInsert = new QCheckBox("--extended-insert");
  extendedInsert->setToolTip(tr("Use multiple-row INSERT syntax that include several VALUES lists"));
  gridChecks->addWidget(extendedInsert, ++row, column, Qt::AlignLeft);

  //  --fields-enclosed-by=string This option is used with the --tab option and has the same meaning as the corresponding clause for LOAD DATA INFILE
  //  --fields-escaped-by This option is used with the --tab option and has the same meaning as the corresponding clause for LOAD DATA INFILE
  //  --fields-optionally-enclosed-by=string This option is used with the --tab option and has the same meaning as the corresponding clause for LOAD DATA INFILE
  //  --fields-terminated-by=string This option is used with the --tab option and has the same meaning as the corresponding clause for LOAD DATA INFILE
  //  --first-slave Deprecated; use --lock-all-tables instead

  row = 0;
  flushLogs = new QCheckBox("--flush-logs");
  flushLogs->setToolTip(tr("Flush the MySQL server log files before starting the dump"));
  gridChecks->addWidget(flushLogs, row, ++column, Qt::AlignLeft);

  flushPrivileges = new QCheckBox("--flush-privileges");
  flushPrivileges->setToolTip(tr("Emit a FLUSH PRIVILEGES statement after dumping the mysql database"));
  gridChecks->addWidget(flushPrivileges, ++row, column, Qt::AlignLeft);

  //  --help Display help message and exit

  hexBlob = new QCheckBox("--hex-blob");
  hexBlob->setToolTip(tr("Dump binary columns using hexadecimal notation (for example, 'abc' becomes 0x616263)"));
  gridChecks->addWidget(hexBlob, ++row, column, Qt::AlignLeft);

  //  --host Host to connect to (IP address or hostname)
  //  --ignore-table=db_name.tbl_name Do not dump the given table

  insertIgnore = new QCheckBox("--insert-ignore");
  insertIgnore->setToolTip(tr("Write INSERT IGNORE statements rather than INSERT statements"));
  gridChecks->addWidget(insertIgnore, ++row, column, Qt::AlignLeft);

  //  --lines-terminated-by=string This option is used with the --tab option and has the same meaning as the corresponding clause for LOAD DATA INFILE

  lockAllTables = new QCheckBox("--lock-all-tables");
  lockAllTables->setToolTip(tr("Lock all tables across all databases"));
  gridChecks->addWidget(lockAllTables, ++row, column, Qt::AlignLeft);

  lockTables = new QCheckBox("--lock-tables");
  lockTables->setToolTip(tr("Lock all tables before dumping them"));
  gridChecks->addWidget(lockTables, ++row, column, Qt::AlignLeft);

  //  --log-error=file_name Append warnings and errors to the named file
  //  --master-data[=value] Write the binary log file name and position to the output
  //  --max_allowed_packet=value The maximum packet length to send to or receive from the server
  //  --net_buffer_length=value The buffer size for TCP/IP and socket communication

  noAutocommit = new QCheckBox("--no-autocommit");
  noAutocommit->setToolTip(tr("Enclose the INSERT statements for each dumped table within SET autocommit = 0 and COMMIT statements"));
  gridChecks->addWidget(noAutocommit, ++row, column, Qt::AlignLeft);

  noAutocommit = new QCheckBox("--no-create-db");
  noAutocommit->setToolTip(tr("This option suppresses the CREATE DATABASE statements"));
  gridChecks->addWidget(noAutocommit, ++row, column, Qt::AlignLeft);

  noCreateInfo = new QCheckBox("--no-create-info");
  noCreateInfo->setToolTip(tr("Do not write CREATE TABLE statements that re-create each dumped table"));
  gridChecks->addWidget(noCreateInfo, ++row, column, Qt::AlignLeft);

  noData = new QCheckBox("--no-data");
  noData->setToolTip(tr("Do not dump table contents"));
  gridChecks->addWidget(noData, ++row, column, Qt::AlignLeft);

  noSetNames = new QCheckBox("--no-set-names");
  noSetNames->setToolTip(tr("Same as --skip-set-charset"));
  gridChecks->addWidget(noSetNames, ++row, column, Qt::AlignLeft);

  noTablespaces = new QCheckBox("--no-tablespaces");
  noTablespaces->setToolTip(tr("Do not write any CREATE LOGFILE GROUP or CREATE TABLESPACE statements in output"));
  gridChecks->addWidget(noTablespaces, ++row, column, Qt::AlignLeft);

  opt = new QCheckBox("--opt");
  opt->setToolTip(tr("Shorthand for --add-drop-table --add-locks --create-options --disable-keys --extended-insert --lock-tables --quick --set-charset."));
  gridChecks->addWidget(opt, ++row, column, Qt::AlignLeft);

  orderByPrimary = new QCheckBox("--order-by-primary");
  orderByPrimary->setToolTip(tr("Dump each table's rows sorted by its primary key, or by its first unique index"));
  gridChecks->addWidget(orderByPrimary, ++row, column, Qt::AlignLeft);

  //  --pipe On Windows, connect to server using a named pipe

  quick = new QCheckBox("--quick");
  quick->setToolTip(tr("Retrieve rows for a table from the server a row at a time"));
  gridChecks->addWidget(quick, ++row, column, Qt::AlignLeft);

  quoteNames = new QCheckBox("--quote-names");
  quoteNames->setToolTip(tr("Quote identifiers within backtick characters"));
  gridChecks->addWidget(quoteNames, ++row, column, Qt::AlignLeft);

  row = 0;
  replace = new QCheckBox("--replace");
  replace->setToolTip(tr("Write REPLACE statements rather than INSERT statements"));
  gridChecks->addWidget(replace, row, ++column, Qt::AlignLeft);

  routines = new QCheckBox("--routines");
  routines->setToolTip(tr("Dump stored routines (procedures and functions) from the dumped databases"));
  gridChecks->addWidget(routines, ++row, column, Qt::AlignLeft);

  //  --set-charset Add SET NAMES default_character_set to the output

  singleTransaction = new QCheckBox("--single-transaction");
  singleTransaction->setToolTip(tr("This option issues a BEGIN SQL statement before dumping data from the server"));
  gridChecks->addWidget(singleTransaction, ++row, column, Qt::AlignLeft);

  skipAddDropTable = new QCheckBox("--skip-add-drop-table");
  skipAddDropTable->setToolTip(tr("Do not add a DROP TABLE statement before each CREATE TABLE statement"));
  connect(skipAddDropTable, SIGNAL(stateChanged(int)), this, SLOT(skipAddDropTableSlot(int)));
  gridChecks->addWidget(skipAddDropTable, ++row, column, Qt::AlignLeft);

  skipAddLocks = new QCheckBox("--skip-add-locks");
  skipAddLocks->setToolTip(tr("Do not add comments to the dump file"));
  connect(skipAddLocks, SIGNAL(stateChanged(int)), this, SLOT(skipAddLocksSlot(int)));
  gridChecks->addWidget(skipAddLocks, ++row, column, Qt::AlignLeft);

  skipComments = new QCheckBox("--skip-comments");
  skipComments->setToolTip(tr("Do not add comments to the dump file"));
  connect(skipComments, SIGNAL(stateChanged(int)), this, SLOT(skipCommentsSlot(int)));
  gridChecks->addWidget(skipComments, ++row, column, Qt::AlignLeft);

  skipCompact = new QCheckBox("--skip-compact");
  skipCompact->setToolTip(tr("Do not produce more compact output"));
  connect(skipCompact, SIGNAL(stateChanged(int)), this, SLOT(skipCompactSlot(int)));
  gridChecks->addWidget(skipCompact, ++row, column, Qt::AlignLeft);

  skipDisableKeys = new QCheckBox("--skip-disable-keys");
  skipDisableKeys->setToolTip(tr("Do not disable keys"));
  connect(skipDisableKeys, SIGNAL(stateChanged(int)), this, SLOT(skipDisableKeysSlot(int)));
  gridChecks->addWidget(skipDisableKeys, ++row, column, Qt::AlignLeft);

  skipExtendedInsert = new QCheckBox("--skip-extended-insert");
  skipExtendedInsert->setToolTip(tr("Turn off extended-insert"));
  connect(skipExtendedInsert, SIGNAL(stateChanged(int)), this, SLOT(skipExtendedInsertSlot(int)));
  gridChecks->addWidget(skipExtendedInsert, ++row, column, Qt::AlignLeft);

  skipOpt = new QCheckBox("--skip-opt");
  skipOpt->setToolTip(tr("Turn off the options set by --opt"));
  connect(skipOpt, SIGNAL(stateChanged(int)), this, SLOT(skipOptSlot(int)));
  gridChecks->addWidget(skipOpt, ++row, column, Qt::AlignLeft);

  skipQuick = new QCheckBox("--skip-quick");
  skipQuick->setToolTip(tr("Do not retrieve rows for a table from the server a row at a time"));
  connect(skipQuick, SIGNAL(stateChanged(int)), this, SLOT(skipQuickSlot(int)));
  gridChecks->addWidget(skipQuick, ++row, column, Qt::AlignLeft);

  skipQuoteNames = new QCheckBox("--skip-quote-names");
  skipQuoteNames->setToolTip(tr("Do not quote identifiers"));
  connect(skipQuoteNames, SIGNAL(stateChanged(int)), this, SLOT(skipQuoteNamesSlot(int)));
  gridChecks->addWidget(skipQuoteNames, ++row, column, Qt::AlignLeft);

  skipSetCharset = new QCheckBox("--skip-set-charset");
  skipSetCharset->setToolTip(tr("Suppress the SET NAMES statement"));
  connect(skipSetCharset, SIGNAL(stateChanged(int)), this, SLOT(skipSetCharsetSlot(int)));
  gridChecks->addWidget(skipSetCharset, ++row, column, Qt::AlignLeft);

  skipTriggers = new QCheckBox("--skip-triggers");
  skipTriggers->setToolTip(tr("Do not dump triggers"));
  connect(skipTriggers, SIGNAL(stateChanged(int)), this, SLOT(skipTriggersSlot(int)));
  gridChecks->addWidget(skipTriggers, ++row, column, Qt::AlignLeft);

  skipTzUtc = new QCheckBox("--skip-tz-utc");
  skipTzUtc->setToolTip(tr("Turn off tz-utc"));
  connect(skipTzUtc, SIGNAL(stateChanged(int)), this, SLOT(skipTzUtcSlot(int)));
  gridChecks->addWidget(skipTzUtc, ++row, column, Qt::AlignLeft);

  //  --ssl-ca=file_name The path to a file that contains a list of trusted SSL CAs
  //  --ssl-capath=directory_name The path to a directory that contains trusted SSL CA certificates in PEM format
  //  --ssl-cert=file_name The name of the SSL certificate file to use for establishing a secure connection
  //  --ssl-cipher=cipher_list A list of allowable ciphers to use for SSL encryption
  //  --ssl-key=file_name The name of the SSL key file to use for establishing a secure connection
  //  --ssl-verify-server-cert The server's Common Name value in its certificate is verified against the host name used when connecting to the server

  //  --tab=path Produce tab-separated data files
  //  --tables Override the --databases or -B option

  row = 0;
  triggers = new QCheckBox("--triggers");
  triggers->setToolTip(tr("Dump triggers for each dumped table"));
  gridChecks->addWidget(triggers, row, ++column, Qt::AlignLeft);

  tzUtc = new QCheckBox("--tz-utc");
  tzUtc->setToolTip(tr("Add SET TIME_ZONE='+00:00' to the dump file"));
  gridChecks->addWidget(tzUtc, ++row, column, Qt::AlignLeft);

  verbose = new QCheckBox("--verbose");
  verbose->setToolTip(tr("Verbose mode"));
  gridChecks->addWidget(verbose, ++row, column, Qt::AlignLeft);

  //  --version Display version information and exit
  //  --where='where_condition' Dump only rows selected by the given WHERE condition

  xml = new QCheckBox("--xml");
  xml->setToolTip(tr("Produce XML output"));
  gridChecks->addWidget(xml, ++row, column, Qt::AlignLeft);
}

void Backup::skipAddDropTableSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    addDropTable->setChecked(false);
    addDropTable->setEnabled(false);
    break;
  case Qt::Unchecked:
    addDropTable->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipAddLocksSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    addLocks->setChecked(false);
    addLocks->setEnabled(false);
    break;
  case Qt::Unchecked:
    addLocks->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipCommentsSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    comments->setChecked(false);
    comments->setEnabled(false);
    break;
  case Qt::Unchecked:
    comments->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipCompactSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    compact->setChecked(false);
    compact->setEnabled(false);
    break;
  case Qt::Unchecked:
    compact->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipDisableKeysSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    disableKeys->setChecked(false);
    disableKeys->setEnabled(false);
    break;
  case Qt::Unchecked:
    disableKeys->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipExtendedInsertSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    extendedInsert->setChecked(false);
    extendedInsert->setEnabled(false);
    break;
  case Qt::Unchecked:
    extendedInsert->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipOptSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    opt->setChecked(false);
    opt->setEnabled(false);
    break;
  case Qt::Unchecked:
    opt->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipQuickSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    quick->setChecked(false);
    quick->setEnabled(false);
    break;
  case Qt::Unchecked:
    quick->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipQuoteNamesSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    quoteNames->setChecked(false);
    quoteNames->setEnabled(false);
    break;
  case Qt::Unchecked:
    quoteNames->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipSetCharsetSlot(int state)
{
  Q_UNUSED(state);
//  switch (state) {
//  case Qt::Checked:
//    setCharset->setChecked(false);
//    setCharset->setEnabled(false);
//    break;
//  case Qt::Unchecked:
//    setCharset->setEnabled(true);
//    break;
//  // default: Q_ASSERT(false);
//  }
}

void Backup::skipTriggersSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    triggers->setChecked(false);
    triggers->setEnabled(false);
    break;
  case Qt::Unchecked:
    triggers->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}

void Backup::skipTzUtcSlot(int state)
{
  switch (state) {
  case Qt::Checked:
    tzUtc->setChecked(false);
    tzUtc->setEnabled(false);
    break;
  case Qt::Unchecked:
    tzUtc->setEnabled(true);
    break;
  // default: Q_ASSERT(false);
  }
}
