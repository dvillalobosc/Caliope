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

#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QSettings>

#include "dbms.h"

class QDialogButtonBox;
class QLineEdit;
class QSpinBox;
class QComboBox;
class QCheckBox;
class QMenu;
class QSignalMapper;
class QCompleter;

class ConnectDialog : public QDialog
{
  Q_OBJECT

public:
  ConnectDialog(DBMS *serverConnection);
  QList<QString> getValues();
  bool getConnectionPerformed();

private slots:
  void validateInputs();
  void fillLineEdits(const QString &text);
  void comboConnectionTypeSlot(const QString &text);
  void databasesMenuSlot();
  void changeDatabaseSlot(QString database);
  void collatoinsMenuSlot();
  void changeCollationSlot(QString collation);

private:
  QDialogButtonBox *buttonBox;
  QLineEdit *lineEditServer;
  QSpinBox *spinBoxPort;
  QLineEdit *lineEditUser;
  QLineEdit *lineEditPassword;
  QLineEdit *lineEditDatabase;
  QComboBox *comboConnectionName;
  QCheckBox *storePasswords;
  QSettings settings;
  QComboBox *comboConnectionType;
  QPushButton *databasesPushButton;
  QMenu *databasesMenu;
  QSignalMapper *databasesMapper;
  bool connectionPerformed;
  DBMS *serverConnection;
  QCompleter *completer;
  void setDBMS();
  unsigned int count;
  QCheckBox *sortConnectionList;
  QMenu *collationsMenu;
  QLineEdit *lineEditCollation;
  QPushButton *collationPushButton;
  QSignalMapper *collationsMapper;
};

#endif // CONNECTDIALOG_H
