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

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

#include "fileassociations.h"

FileAssociations::FileAssociations()
{
  formLayout = new QFormLayout;
  sqlLineEdit = new QLineEdit;
  sqlLineEdit->setText(settings.value("FileAssociations/SQLFiles", "sql").toString());
  sqlLineEdit->setToolTip(sqlLineEdit->text());
  connect(sqlLineEdit, SIGNAL(textChanged(QString)), this, SLOT(sqlLineEditTextChangedSlot(QString)));
  formLayout->addRow(" ", sqlLineEdit);
  setLayout(formLayout);
}

void FileAssociations::retranslateUi()
{
  QLabel *label = qobject_cast<QLabel *>(formLayout->labelForField(sqlLineEdit));
  label->setText(tr("SQL files:"));
  label->setToolTip(label->text());
}

QString FileAssociations::FileAssociationsList()
{
  QSettings settings;
  QString data(settings.value("FileAssociations/SQLFiles", "sql").toString());
  return data.replace(",", "|");
}

QString FileAssociations::textTransformation(QString text)
{
  return text.replace(" ", "").replace("*", "").replace(".", "").toLower();
}

void FileAssociations::sqlLineEditTextChangedSlot(QString newText)
{
  settings.setValue("FileAssociations/SQLFiles", textTransformation(newText));
}
