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
#include <QIcon>
#include <QFileInfo>

#include "difffile.h"
#include "basedifffile.h"
#include "dtitlelabel.h"

DiffFile::DiffFile(QString file)
{
  svnFile = new QFileInfo(file);

  setAttribute(Qt::WA_DeleteOnClose);
  setWindowIcon(QIcon(":/images/svg/server-database.svg"));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setMargin(0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);

  BaseDiffFile *baseDiffFile = new BaseDiffFile(file);
  mainVLayout->addWidget(baseDiffFile);

  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
}

void DiffFile::retranslateUi()
{
  setWindowTitle(tr("Diff file") + ": " + svnFile->completeBaseName() + "." + svnFile->completeSuffix());
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  dTitleLabel->setToolTip(dTitleLabel->text());
}
