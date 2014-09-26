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

#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QLineEdit>
#include <QFormLayout>

#include "newdatabase.h"
#include "dtitlelabel.h"

NewDatabase::NewDatabase(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon::fromTheme("document-new", QIcon(":/images/svg/document-new-6.svg")));
  setWindowTitle(tr("New database"));
  setObjectName(windowTitle());
  setAttribute(Qt::WA_DeleteOnClose);
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->addWidget(new DTitleLabel(windowTitle()));
  lineEditName = new QLineEdit;
  comboCharacterset = new QComboBox;
  comboCharacterset->addItems(serverConnection->getCollations());
  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("Name:"), lineEditName);
  formLayout->addRow(tr("Collation"), comboCharacterset);
  mainVLayout->addLayout(formLayout);
  QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(applyStatement()));
  mainVLayout->addWidget(buttonBox);
  setLayout(mainVLayout);
}

void NewDatabase::applyStatement()
{
  serverConnection->database(lineEditName->text())->create(comboCharacterset->currentText());
  serverConnection->changeDatabase(comboCharacterset->currentText());
  close();
}
