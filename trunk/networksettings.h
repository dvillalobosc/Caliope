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

#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QWidget>
#include <QSettings>

class QLineEdit;
class QCheckBox;
class QSpinBox;
class QPushButton;
class DMessageLabel;
class QFormLayout;

class NetworkSettings : public QWidget
{
  Q_OBJECT

public:
  NetworkSettings();
  static void setProxySettings();
  void retranslateUi();

private:
  QLineEdit *serverLineEdit;
  QLineEdit *userLineEdit;
  QLineEdit *passwordLineEdit;
  QCheckBox *checkBoxUseProxy;
  QSpinBox *spinBoxPort;
  QPushButton *applyProxySettings;
  DMessageLabel *dMessageLabel;
  QSettings settings;
  QFormLayout *formLayout;

private slots:
  void proxyChangedSlot(const QString proxy);
  void checkBoxUseProxyStateChanged();
  void portSpinBoxValueChanged(int value);
  void proxySettings();
  void userChangedSlot(const QString user);
  void passwordChangedSlot(const QString password);
};

#endif // NETWORKSETTINGS_H
