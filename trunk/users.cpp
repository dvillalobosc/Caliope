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
#include <QFormLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDialogButtonBox>

#include "users.h"
#include "dtitlelabel.h"

Users::Users()
{
  setWindowIcon(QIcon(":/images/svg/system-users-4.svg"));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);

//  | Alter                   | Tables                                | To alter the table                                    |
//  | Alter routine           | Functions,Procedures                  | To alter or drop stored functions/procedures          |
//  | Create                  | Databases,Tables,Indexes              | To create new databases and tables                    |
//  | Create routine          | Databases                             | To use CREATE FUNCTION/PROCEDURE                      |
//  | Create temporary tables | Databases                             | To use CREATE TEMPORARY TABLE                         |
//  | Create view             | Tables                                | To create new views                                   |
//  | Delete                  | Tables                                | To delete existing rows                               |
//  | Drop                    | Databases,Tables                      | To drop databases, tables, and views                  |
//  | Execute                 | Functions,Procedures                  | To execute stored routines                            |
//  | File                    | File access on server                 | To read and write files on the server                 |
//  | Grant option            | Databases,Tables,Functions,Procedures | To give to other users those privileges you possess   |
//  | Index                   | Tables                                | To create or drop indexes                             |
//  | Insert                  | Tables                                | To insert data into tables                            |
//  | Lock tables             | Databases                             | To use LOCK TABLES (together with SELECT privilege)   |
//  | References              | Databases,Tables                      | To have references on tables                          |
//  | Select                  | Tables                                | To retrieve rows from table                           |
//  | Show view               | Tables                                | To see views with SHOW CREATE VIEW                    |
//  | Trigger                 | Tables                                | To use triggers                                       |
//  | Update                  | Tables                                | To update existing rows                               |

  loginGroupBox = new QGroupBox;
  loginLayput = new QFormLayout;
  usernameLineEdit = new QLineEdit;
  loginLayput->addRow(" ", usernameLineEdit);
  passwordLineEdit = new QLineEdit;
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  loginLayput->addRow(" ", passwordLineEdit);
  loginGroupBox->setLayout(loginLayput);
  mainVLayout->addWidget(loginGroupBox);

//  createUserCheckBox = new QCheckBox(tr("Create user"));
//  processCheckBox = new QCheckBox(tr("Process"));
//  reloadCheckBox = new QCheckBox(tr("Reload"));
//  replicationClientCheckBox = new QCheckBox(tr("Replication client"));
//  replicationSlaveCheckBox = new QCheckBox(tr("Replication slave"));
//  showDatabasesCheckBox = new QCheckBox(tr("Show databases"));
//  shutdownCheckBox = new QCheckBox(tr("Shutdown"));
//  superCheckBox = new QCheckBox(tr("Super"));
//  usageCheckBox = new QCheckBox(tr("Usage"));
//  eventCheckBox = new QCheckBox(tr("Event"));
//  QFormLayout *admPrivLayput = new QFormLayout;
//  admPrivLayput->addRow(createUserCheckBox, new QLabel(tr("To create new users")));
//  admPrivLayput->addRow(processCheckBox, new QLabel(tr("To view the plain text of currently executing queries")));
//  admPrivLayput->addRow(reloadCheckBox, new QLabel(tr("To reload or refresh tables, logs and privileges")));
//  admPrivLayput->addRow(replicationClientCheckBox, new QLabel(tr("To ask where the slave or master servers are")));
//  admPrivLayput->addRow(replicationSlaveCheckBox, new QLabel(tr("To read binary log events from the master")));
//  admPrivLayput->addRow(showDatabasesCheckBox, new QLabel(tr("To see all databases with SHOW DATABASES")));
//  admPrivLayput->addRow(shutdownCheckBox, new QLabel(tr("To shut down the server")));
//  admPrivLayput->addRow(superCheckBox, new QLabel(tr("To use KILL thread, SET GLOBAL, CHANGE MASTER, etc.")));
//  admPrivLayput->addRow(usageCheckBox, new QLabel(tr("No privileges - allow connect only")));
//  admPrivLayput->addRow(eventCheckBox, new QLabel(tr("To create, alter, drop and execute events")));
//  QGroupBox *admPrivGroupBox = new QGroupBox(tr("Server Admin"));
//  admPrivGroupBox->setLayout(admPrivLayput);
//  mainVLayout->addWidget(admPrivGroupBox);

  buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Help);
//  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  mainVLayout->addStretch();
  mainVLayout->addWidget(buttonBox);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
}

void Users::retranslateUi()
{
  setWindowTitle(tr("User Administration"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  dTitleLabel->setToolTip(dTitleLabel->text());
  loginGroupBox->setTitle(tr("Login informaction"));
  loginGroupBox->setToolTip(loginGroupBox->title());
  QLabel *label = qobject_cast<QLabel *>(loginLayput->labelForField(usernameLineEdit));
  label->setText(tr("Username:"));
  label->setToolTip(label->text());
  label = qobject_cast<QLabel *>(loginLayput->labelForField(passwordLineEdit));
  label->setText(tr("Password:"));
  label->setToolTip(label->text());
}

void Users::userInfo(QString user)
{
  usernameLineEdit->setText(user);
  usernameLineEdit->setToolTip(usernameLineEdit->text());
}
