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
#include <QPlainTextEdit>
#include <QDialogButtonBox>
#include <QPushButton>

#include "licensetemplate.h"
#include "fileselector.h"

LicenseTemplate::LicenseTemplate()
{
  QVBoxLayout *licenseTemplateVLayout = new QVBoxLayout;
  licensePlainTextEdit = new QPlainTextEdit;
  licensePlainTextEdit->setPlainText(settings.value("License/Template", "").toString());
  licenseTemplateVLayout->addWidget(licensePlainTextEdit);
  fileSelector = new FileSelector(FileSelectorContexts::LicenseFile);
  fileSelector->setFileName(settings.value("License/File", "").toString());
  connect(fileSelector, SIGNAL(changed()), this, SLOT(fileSelectorSlot())),
  licenseTemplateVLayout->addWidget(fileSelector);
  buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Help);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(saveLicenseTemplateText()));
  licenseTemplateVLayout->addWidget(buttonBox);
  connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(helpLicenseTemplate()));
  connect(licensePlainTextEdit, SIGNAL(textChanged()), this, SLOT(validateText()));
  retranslateUi();
  setLayout(licenseTemplateVLayout);
  validateText();
}

void LicenseTemplate::retranslateUi()
{
  fileSelector->setText(tr("From a file"));
  fileSelector->retranslateUi();
}

void LicenseTemplate::saveLicenseTemplateText()
{
  settings.setValue("License/Template", licensePlainTextEdit->toPlainText());
}

void LicenseTemplate::helpLicenseTemplate()
{
  licensePlainTextEdit->setPlainText(
        "/***************************************************************************\n"
        "*    <one line to give the program's name and a brief idea of what it does.>\n"
        "*    Copyright (C) <year>  <name of author>\n"
        "*\n"
        "*    This program is free software: you can redistribute it and/or modify\n"
        "*    it under the terms of the GNU General Public License as published by\n"
        "*    the Free Software Foundation, either version 3 of the License, or\n"
        "*    (at your option) any later version.\n"
        "*\n"
        "*    This program is distributed in the hope that it will be useful,\n"
        "*    but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
        "*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
        "*    GNU General Public License for more details.\n"
        "*\n"
        "*    You should have received a copy of the GNU General Public License\n"
        "*    along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
        "***************************************************************************/\n"
        );
  settings.value("License/File", "").clear();
  fileSelector->setFileName();
}

void LicenseTemplate::fileSelectorSlot()
{
  settings.setValue("License/File", fileSelector->getFileName());
  licensePlainTextEdit->setPlainText(fileSelector->fileText());
}

QString LicenseTemplate::License()
{
//  return settings.value("License/Template", "").toString();
  return "";
}

void LicenseTemplate::validateText()
{
  buttonBox->button(QDialogButtonBox::Save)->setEnabled(!licensePlainTextEdit->toPlainText().isEmpty());
}
