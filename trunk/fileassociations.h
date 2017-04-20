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

#ifndef FILEASSOCIATIONS_H
#define FILEASSOCIATIONS_H

#include <QWidget>
#include <QSettings>

class QLineEdit;
class QFormLayout;

class FileAssociations : public QWidget
{
  Q_OBJECT

public:
  FileAssociations();
  void retranslateUi();
  static QString FileAssociationsList();

private:
  QLineEdit *sqlLineEdit;
  QLineEdit *phpLineEdit;
  QLineEdit *cssLineEdit;
  QLineEdit *htmlLineEdit;
  QLineEdit *javascriptLineEdit;
  QSettings settings;
  QString textTransformation(QString text);
  QFormLayout *formLayout;

private slots:
  void sqlLineEditTextChangedSlot(QString newText);
  void phpLineEditTextChangedSlot(QString newText);
  void cssLineEditTextChangedSlot(QString newText);
  void htmlLineEditTextChangedSlot(QString newText);
  void javascriptLineEditTextChangedSlot(QString newText);

};

#endif // FILEASSOCIATIONS_H
