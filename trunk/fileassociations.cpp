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

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

#include "fileassociations.h"

FileAssociations::FileAssociations()
{
  formLayout = new QFormLayout;
  sqlLineEdit = new QLineEdit;
  sqlLineEdit->setText(settings.value("FileAssociations/SQLFiles", "sql").toString());
  connect(sqlLineEdit, SIGNAL(textChanged(QString)), this, SLOT(sqlLineEditTextChangedSlot(QString)));
  formLayout->addRow(" ", sqlLineEdit);
  phpLineEdit = new QLineEdit;
  phpLineEdit->setText(settings.value("FileAssociations/PHPFiles", "php,inc,module").toString());
  connect(phpLineEdit, SIGNAL(textChanged(QString)), this, SLOT(phpLineEditTextChangedSlot(QString)));
  formLayout->addRow(" ", phpLineEdit);
  cssLineEdit = new QLineEdit;
  cssLineEdit->setText(settings.value("FileAssociations/CSSFiles", "css").toString());
  connect(cssLineEdit, SIGNAL(textChanged(QString)), this, SLOT(cssLineEditTextChangedSlot(QString)));
  formLayout->addRow(" ", cssLineEdit);
  htmlLineEdit = new QLineEdit;
  htmlLineEdit->setText(settings.value("FileAssociations/HTMLFiles", "html,htm").toString());
  connect(htmlLineEdit, SIGNAL(textChanged(QString)), this, SLOT(htmlLineEditTextChangedSlot(QString)));
  formLayout->addRow(" ", htmlLineEdit);
  javascriptLineEdit = new QLineEdit;
  javascriptLineEdit->setText(settings.value("FileAssociations/JavaScriptFiles", "js").toString());
  connect(javascriptLineEdit, SIGNAL(textChanged(QString)), this, SLOT(javascriptLineEditTextChangedSlot(QString)));
  formLayout->addRow(" ", javascriptLineEdit);
  setLayout(formLayout);
}

void FileAssociations::retranslateUi()
{
  QLabel *label = qobject_cast<QLabel *>(formLayout->labelForField(sqlLineEdit));
  label->setText(tr("SQL files:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(phpLineEdit));
  label->setText(tr("PHP files:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(cssLineEdit));
  label->setText(tr("CSS files:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(htmlLineEdit));
  label->setText(tr("HTML files:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(javascriptLineEdit));
  label->setText(tr("JavaScript files:"));
}

QString FileAssociations::FileAssociationsList()
{
  QSettings settings;
  QString data(settings.value("FileAssociations/SQLFiles", "sql").toString()
      + "," + settings.value("FileAssociations/PHPFiles", "php,inc,module").toString()
      + "," + settings.value("FileAssociations/CSSFiles", "css").toString()
      + "," + settings.value("FileAssociations/HTMLFiles", "html,htm").toString()
      + "," + settings.value("FileAssociations/JavaScriptFiles", "js").toString());
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

void FileAssociations::phpLineEditTextChangedSlot(QString newText)
{
  settings.setValue("FileAssociations/PHPFiles", textTransformation(newText));
}

void FileAssociations::cssLineEditTextChangedSlot(QString newText)
{
  settings.setValue("FileAssociations/CSSFiles", textTransformation(newText));
}

void FileAssociations::htmlLineEditTextChangedSlot(QString newText)
{
  settings.setValue("FileAssociations/HTMLFiles", textTransformation(newText));
}

void FileAssociations::javascriptLineEditTextChangedSlot(QString newText)
{
  settings.setValue("FileAssociations/JavaScriptFiles", textTransformation(newText));
}

