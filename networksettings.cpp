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

#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QtNetwork/QNetworkProxy>

#include "networksettings.h"
#include "staticfunctions.h"
#include "dmessagelabel.h"

NetworkSettings::NetworkSettings()
{
  formLayout = new QFormLayout;
  checkBoxUseProxy = new QCheckBox;
  checkBoxUseProxy->setCheckState(settings.value("Network/UseProxy", "false") == "true" ? Qt::Checked : Qt::Unchecked);
  connect(checkBoxUseProxy, SIGNAL(stateChanged(int)), this, SLOT(checkBoxUseProxyStateChanged()));
  formLayout->addRow(checkBoxUseProxy);
  serverLineEdit = new QLineEdit(settings.value("Network/ProxyAddress", "example.com").toString());
  connect(serverLineEdit, SIGNAL(textChanged(QString)), this, SLOT(proxyChangedSlot(QString)));
  formLayout->addRow(" ", serverLineEdit);
  spinBoxPort = new QSpinBox;
  spinBoxPort->setRange(1, 65535);
  spinBoxPort->setValue(settings.value("Network/Port", 3128).toInt());
  connect(spinBoxPort, SIGNAL(valueChanged(int)), this, SLOT(portSpinBoxValueChanged(int)));
  formLayout->addRow(" ", spinBoxPort);
  userLineEdit = new QLineEdit(settings.value("Network/User", "").toString());
  connect(userLineEdit, SIGNAL(textChanged(QString)), this, SLOT(userChangedSlot(QString)));
  formLayout->addRow(" ", userLineEdit);
  passwordLineEdit = new QLineEdit(StaticFunctions::password(settings.value("Network/Password").toString()));
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  connect(passwordLineEdit, SIGNAL(textChanged(QString)), this, SLOT(passwordChangedSlot(QString)));
  formLayout->addRow(" ", passwordLineEdit);
  applyProxySettings = new QPushButton;
  connect(applyProxySettings, SIGNAL(clicked()), this, SLOT(proxySettings()));
  formLayout->addWidget(applyProxySettings);
  dMessageLabel = new DMessageLabel(MessageTypes::Information);
  formLayout->addRow(dMessageLabel);
  retranslateUi();
  setLayout(formLayout);
  checkBoxUseProxyStateChanged();
}

void NetworkSettings::retranslateUi()
{
  checkBoxUseProxy->setText(tr("Use proxy for Internet connections."));
  QLabel *label = qobject_cast<QLabel *>(formLayout->labelForField(serverLineEdit));
  label->setText(tr("Proxy address:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(spinBoxPort));
  label->setText(tr("Port:"));
  userLineEdit->setPlaceholderText(tr("Leave it blank if is not needed"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(userLineEdit));
  label->setText(tr("Username:"));
  passwordLineEdit->setPlaceholderText(tr("Leave it blank if is not needed"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(userLineEdit));
  label->setText(tr("Username:"));
  label = qobject_cast<QLabel *>(formLayout->labelForField(passwordLineEdit));
  label->setText(tr("Password:"));
  applyProxySettings->setText(tr("Apply changes"));
  dMessageLabel->setText(tr("Settings will be applied when application restarts."));
}

void NetworkSettings::proxySettings()
{
  setProxySettings();
  dMessageLabel->setEnabled(false);
}

void NetworkSettings::setProxySettings()
{
  QSettings settings;
  QNetworkProxy proxy;
  if (settings.value("Network/UseProxy", false).toBool()) {
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName(settings.value("Network/ProxyAddress", "").toString());
    proxy.setPort(settings.value("Network/Port", 0).toInt());
    if (!settings.value("Network/User", "").toString().isEmpty())
      proxy.setUser(settings.value("Network/User", "").toString());
    if (!settings.value("Network/Password", "").toString().isEmpty())
      proxy.setPassword(StaticFunctions::password(settings.value("Network/Password", "").toString()));
  } else {
    proxy.setType(QNetworkProxy::NoProxy);
  }
  QNetworkProxy::setApplicationProxy(proxy);
}

void NetworkSettings::portSpinBoxValueChanged(int value)
{
  settings.setValue("Network/Port", value);
  dMessageLabel->setEnabled(true);
}

void NetworkSettings::proxyChangedSlot(const QString proxy)
{
  settings.setValue("Network/ProxyAddress", proxy);
  dMessageLabel->setEnabled(true);
}

void NetworkSettings::checkBoxUseProxyStateChanged()
{
  settings.setValue("Network/UseProxy", checkBoxUseProxy->isChecked());
  serverLineEdit->setEnabled(checkBoxUseProxy->isChecked());
  spinBoxPort->setEnabled(checkBoxUseProxy->isChecked());
  userLineEdit->setEnabled(checkBoxUseProxy->isChecked());
  passwordLineEdit->setEnabled(checkBoxUseProxy->isChecked());
  if (!checkBoxUseProxy->isChecked())
    settings.setValue("Network/UseProxy", false);
  dMessageLabel->setEnabled(true);
}

void NetworkSettings::passwordChangedSlot(const QString password)
{
  settings.setValue("Network/Password", StaticFunctions::password(password, true));
  dMessageLabel->setEnabled(true);
}

void NetworkSettings::userChangedSlot(const QString user)
{
  settings.setValue("Network/User", user);
  dMessageLabel->setEnabled(true);
}
