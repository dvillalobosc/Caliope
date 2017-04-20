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

#include <QProcess>
#include <QMessageBox>
#include <QVBoxLayout>

#include "basedifffile.h"
#include "basetexteditor.h"
#include "editortypes.h"

BaseDiffFile::BaseDiffFile(QString file)
{
  QStringList arguments;
  arguments << "diff" << file;
  QProcess *process = new QProcess(this);
  process->start("svn", arguments);
  process->waitForFinished();
  QByteArray output = process->readAll();
  QString result;
  for (int i = 0; i < output.size(); ++i)
    result += output.at(i);
  if (result.isEmpty())
    QMessageBox::information(this, QObject::tr("Version control"), tr("File without changes"));

  BaseTextEditor *diffFile = new BaseTextEditor(EditorTypes::Diff);
  diffFile->setPlainText(result);

  QVBoxLayout *diffVLayout = new QVBoxLayout;
  diffVLayout->addWidget(diffFile);
  setLayout(diffVLayout);
}
