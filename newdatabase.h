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

#ifndef NEWDATABASE_H
#define NEWDATABASE_H

#include <QDialog>

#include "dbms.h"

class QLineEdit;
class QComboBox;

class NewDatabase : public QDialog
{
  Q_OBJECT

public:
  NewDatabase(DBMS *serverConnection);

private:
  DBMS *serverConnection;
  QLineEdit *lineEditName;
  QComboBox *comboCharacterset;

private slots:
  void applyStatement();
};

#endif // NEWDATABASE_H
