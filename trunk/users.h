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

#ifndef USERS_H
#define USERS_H

class QCheckBox;
class QLineEdit;
class QDialogButtonBox;
class DTitleLabel;
class QGroupBox;
class QFormLayout;

#include "dmdisubwindow.h"

class Users : public DMdiSubWindow
{
  Q_OBJECT

public:
  Users();
  void userInfo(QString user);

protected:
  void retranslateUi();

private:
//  QCheckBox *createUserCheckBox;
//  QCheckBox *processCheckBox;
//  QCheckBox *reloadCheckBox;
//  QCheckBox *replicationClientCheckBox;
//  QCheckBox *replicationSlaveCheckBox;
//  QCheckBox *showDatabasesCheckBox;
//  QCheckBox *shutdownCheckBox;
//  QCheckBox *superCheckBox;
//  QCheckBox *usageCheckBox;
//  QCheckBox *eventCheckBox;
  QLineEdit *usernameLineEdit;
  QLineEdit *passwordLineEdit;
  QDialogButtonBox *buttonBox;
  DTitleLabel *dTitleLabel;
  QGroupBox *loginGroupBox;
  QFormLayout *loginLayput;
};

#endif // USERS_H
