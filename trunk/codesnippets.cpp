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
#include <QPlainTextEdit>
#include <QDialogButtonBox>

#include "codesnippets.h"

#include <qdebug.h>

CodeSnippets::CodeSnippets()
{
  QVBoxLayout *codeSnippetsVLayout = new QVBoxLayout;
  codeSnippetsPlainTextEdit = new QPlainTextEdit;
  codeSnippetsPlainTextEdit->setPlainText(loadCodeSnippets());
  codeSnippetsVLayout->addWidget(codeSnippetsPlainTextEdit);
  buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Help);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(saveCodeSnippets()));
  codeSnippetsVLayout->addWidget(buttonBox);
  connect(buttonBox, SIGNAL(helpRequested()), this, SLOT(helpCodeSnippets()));
  //connect(licensePlainTextEdit, SIGNAL(textChanged()), this, SLOT(validateText()));

  retranslateUi();
  setLayout(codeSnippetsVLayout);
}

void CodeSnippets::retranslateUi()
{

}

QStringList CodeSnippets::getCodeSnippets()
{
  settings.beginGroup("CodeSnippets");
  QStringList codeSnippets = settings.allKeys();
  codeSnippets.removeAt(codeSnippets.indexOf("Snippets"));
  settings.endGroup();
  return codeSnippets;
}

QString CodeSnippets::getCodeSnippet(const QString key)
{
  return settings.value("CodeSnippets/" + key, "").toString();
}

void CodeSnippets::addSnippet(QString snippet, QString title)
{
  QStringList data;
  QString out(loadCodeSnippets() + "\n\n###" + title + "$$$\n" + snippet);
  settings.beginGroup("CodeSnippets");
  settings.group().clear();
  foreach (QString snippet, out.split("###", QString::SkipEmptyParts)) {
    data = snippet.split("$$$", QString::SkipEmptyParts);
    settings.setValue(data.at(0), data.at(1).trimmed());
  }
  settings.endGroup();
}

QString CodeSnippets::loadCodeSnippets()
{
  QString out;
  settings.beginGroup("CodeSnippets");
  QStringList codeSnippets = settings.allKeys();
  codeSnippets.removeAt(codeSnippets.indexOf("Snippets"));
  settings.endGroup();
  foreach (QString snippet, codeSnippets)
    out += "###" + snippet + "$$$\n" + getCodeSnippet(snippet) + "\n\n";
  return out.trimmed();
}

void CodeSnippets::helpCodeSnippets()
{
  codeSnippetsPlainTextEdit->setPlainText(
        "###SQLCreateTable1$$$"
        "\n-- -----------------------------------------------------"
        "\n-- Tabla `Database`.`Module_TableName`"
        "\n-- -----------------------------------------------------"
        "\nDROP TABLE IF EXISTS `Drupal`.`SEVRI_Magnitudes`;"
        "\n"
        "\nCREATE TABLE IF NOT EXISTS `Drupal`.`SEVRI_Magnitudes` ("
        "\n  `MagnitudId` TINYINT UNSIGNED NOT NULL AUTO_INCREMENT COMMENT 'Llave primaria de la tabla',"
        "\n  `Nombre` VARCHAR(200) COLLATE utf8_spanish_ci NOT NULL DEFAULT '-' COMMENT 'Nombre de la magnitud',"
        "\n  `Descripcion` VARCHAR(750) COLLATE utf8_spanish_ci NOT NULL DEFAULT '-' COMMENT 'Descripción de la magnitud del riesgo',"
        "\n  `ValorNumerico` TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT 'Valor numérico asignado a la descripción de la magnitud del riesgo',"
        "\n  `Estado` BOOLEAN NOT NULL DEFAULT FALSE COMMENT 'Valores TRUE = Habilitada, FALSE = Deshabilitada',"
        "\n  `LastUpdate` TIMESTAMP(4) NOT NULL DEFAULT CURRENT_TIMESTAMP(4) ON UPDATE CURRENT_TIMESTAMP(4) COMMENT 'Fecha de la última actualización de la fila',"
        "\n  `LastUser` VARCHAR(200) COLLATE utf8_spanish_ci NOT NULL DEFAULT '-' COMMENT 'Último usuario que modificó la fila',"
        "\n  PRIMARY KEY (`MagnitudId`)"
        "\n) ENGINE = InnoDB DEFAULT CHARSET = utf8 COLLATE = utf8_spanish_ci  COMMENT = 'Almacena las opciones que se muestran para evaluar la magnitud de cada riesgo identificado';"
        );
}

void CodeSnippets::saveCodeSnippets()
{
  QStringList data;
  settings.beginGroup("CodeSnippets");
  settings.group().clear();
  foreach (QString snippet, codeSnippetsPlainTextEdit->toPlainText().split("###", QString::SkipEmptyParts)) {
    data = snippet.split("$$$", QString::SkipEmptyParts);
    settings.setValue(data.at(0), data.at(1).trimmed());
  }
  settings.endGroup();
}
