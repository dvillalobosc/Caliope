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

#include <QApplication>
#include <QStyleFactory>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QListWidget>
#include <QStandardItemModel>

#include "preferences.h"
#include "dtitlelabel.h"
#include "licensetemplate.h"
#include "networksettings.h"
#include "dtableview.h"
#include "staticfunctions.h"
#include "fileassociations.h"
#include "fileselector.h"
#include "dstackedwidget.h"
#include "applicationtheme.h"

#include "QDebug"

Preferences::Preferences(DBMS *serverConnection)
{
  setWindowIcon(QIcon::fromTheme("preferences-system", QIcon(":/images/svg/preferences-system-4.svg")));

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);

  dStackedWidget = new DStackedWidget;

  //General
  styleFLayout = new QFormLayout;
  stylesCombo = new QComboBox;
  stylesCombo->addItems(QStyleFactory::keys());
  stylesCombo->setCurrentIndex(stylesCombo->findText(settings.value("General/Style", QApplication::style()->objectName()).toString(), Qt::MatchFixedString));
  connect(stylesCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(stylesComboCurrentIndexChanged(QString)));
  styleFLayout->addRow(" ", stylesCombo);
  checkBoxRememberWindows = new QCheckBox;
  checkBoxRememberWindows->setCheckState(settings.value("General/RememberOpenedWindows", false).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(checkBoxRememberWindows, SIGNAL(stateChanged(int)), this, SLOT(checkBoxRememberWindowsStateChanged()));
  styleFLayout->addRow(checkBoxRememberWindows);
  checkBoxOpenLastFile = new QCheckBox;
  checkBoxOpenLastFile->setCheckState(settings.value("General/OpenLastFile", false).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(checkBoxOpenLastFile, SIGNAL(stateChanged(int)), this, SLOT(checkBoxOpenLastFileStateChanged()));
  styleFLayout->addRow(checkBoxOpenLastFile);
  checkBoxSaveQueryBeforeExecution = new QCheckBox;
  checkBoxSaveQueryBeforeExecution->setCheckState(settings.value("General/SaveQueriesBeforeExecution", true).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(checkBoxSaveQueryBeforeExecution, SIGNAL(stateChanged(int)), this, SLOT(checkBoxSaveQueryBeforeExecutionStateChanged()));
  checkBoxEnableQueryLog = new QCheckBox;
  checkBoxEnableQueryLog->setCheckState(settings.value("General/EnableQueryLog", false).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(checkBoxEnableQueryLog, SIGNAL(stateChanged(int)), this, SLOT(checkBoxEnableQueryLogValueChanged(int)));
  styleFLayout->addRow(checkBoxEnableQueryLog);
  styleFLayout->addRow(checkBoxSaveQueryBeforeExecution);
  checkBoxAutoreconnect = new QCheckBox;
  checkBoxAutoreconnect->setCheckState(settings.value("DBMS/Reconnect", 1).toBool() ? Qt::Checked : Qt::Unchecked);
  connect(checkBoxAutoreconnect, SIGNAL(stateChanged(int)), this, SLOT(checkBoxAutoreconnectValueChanged(int)));
  styleFLayout->addRow(checkBoxAutoreconnect);
  styleGroupBox= new QGroupBox;
  styleGroupBox->setLayout(styleFLayout);
  fileSelectorBackgroundImage = new FileSelector(FileSelectorContexts::Image);
  fileSelectorBackgroundImage->setFileName(settings.value("General/BackgroundImage", ":/images/png/512/server-database.png").toString());
  connect(fileSelectorBackgroundImage, SIGNAL(changed()), this, SLOT(fileSelectorBackgroundImageSlot()));
  fileSelectorBackgroundImage->setText(tr("Change default background image"));
  fileSelectorBackgroundImage->retranslateUi();
  styleFLayout->addRow(fileSelectorBackgroundImage);
  QVBoxLayout *generalLayout = new QVBoxLayout;
  generalLayout->addWidget(styleGroupBox);
  generalLayout->addStretch();
  QWidget *widgetGeneral = new QWidget;
  widgetGeneral->setLayout(generalLayout);
  dStackedWidget->addWidget(widgetGeneral, QIcon(":/images/svg/server-database.svg"), tr("General"));

  //Texteditor
  textEditorFLayout = new QFormLayout;
  tabSizeSpinBox = new QSpinBox;
  tabSizeSpinBox->setRange(2, 30);
  tabSizeSpinBox->setValue(settings.value("TextEditor/TabSize", tabSizeSpinBox->minimum()).toInt());
  connect(tabSizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(tabSizeSpinBoxValueChanged(int)));
  textEditorFLayout->addRow(" ", tabSizeSpinBox);
  checkBoxAutomaticIndentation = new QCheckBox;
  checkBoxAutomaticIndentation->setChecked(settings.value("TextEditor/AutomaticIndentation", Qt::Unchecked).toInt());
  connect(checkBoxAutomaticIndentation, SIGNAL(stateChanged(int)), this, SLOT(checkBoxAutomaticIndentationValueChanged(int)));
  textEditorFLayout->addRow(checkBoxAutomaticIndentation);
  checkBoxCleanwhiteSpaces = new QCheckBox;
  checkBoxCleanwhiteSpaces->setChecked(settings.value("TextEditor/CleanWhiteSpaces", Qt::Unchecked).toInt());
  connect(checkBoxCleanwhiteSpaces, SIGNAL(stateChanged(int)), this, SLOT(checkBoxCleanwhiteSpacesValueChanged(int)));
  textEditorFLayout->addRow(checkBoxCleanwhiteSpaces);
  checkBoxSaveABackupFile = new QCheckBox;
  checkBoxSaveABackupFile->setChecked(settings.value("TextEditor/CreateBackupFile", Qt::Checked).toInt());
  connect(checkBoxSaveABackupFile, SIGNAL(stateChanged(int)), this, SLOT(checkBoxSaveABackupFileValueChanged(int)));
  textEditorFLayout->addRow(checkBoxSaveABackupFile);
//  checkBoxShowTabsAndSpaces = new QCheckBox;
//  checkBoxShowTabsAndSpaces->setChecked(settings.value("TextEditor/ShowTabsAndSpaces", Qt::Unchecked).toInt());
//  connect(checkBoxShowTabsAndSpaces, SIGNAL(stateChanged(int)), this, SLOT(checkBoxShowTabsAndSpacesValueChanged(int)));
//  textEditorFLayout->addRow(checkBoxShowTabsAndSpaces);
  QWidget *widgetTextEditor = new QWidget;
  widgetTextEditor->setLayout(textEditorFLayout);
  dStackedWidget->addWidget(widgetTextEditor, QIcon::fromTheme("accessories-text-editor", QIcon(":/images/svg/accessories-text-editor-7.svg")), tr("Text Editor"));

  //License template
  licenseTemplate = new LicenseTemplate;
  dStackedWidget->addWidget(licenseTemplate, QIcon(":/images/svg/server-database.svg"), tr("License Template"));

  //Network Settings
  networkSettings = new NetworkSettings;
  dStackedWidget->addWidget(networkSettings, QIcon::fromTheme("preferences-system-network", QIcon(":/images/svg/preferences-system-network-3.svg")), tr("Network Settings"));

  //Connections settings
  /**
  * Pending translation
  */
  QString NoDelegate = StaticFunctions::DelegateTypeNoDelegate();
  QList<QStringList> *connectionsDTableViewHeaders = new QList<QStringList>;
  //0 - Connection name
  //1 - User
  //2 - Host
  //3 - Port
  //4 - Database
  //5 - Conexion count -- No parsed but keeped the space.
  //6 - Collation
  //7 - UseSSL
  //8 - KeyFile
  //9 - CertFile
  //10 - Password

  QString collationsJoined;
  QList<QStringList> *collations = serverConnection->getCollationsApplicability();
  for (int row = 0; row < collations->count() - 1; row++)
    collationsJoined += collations->at(row).at(1) + "|" + collations->at(row).at(0) + ",";
  collationsJoined = collationsJoined.left(-1);

  connectionsDTableViewHeaders->append(QStringList() << tr("Name") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Type") << (StaticFunctions::DelegateTypeEnum() + "(" + StaticFunctions::dbmsEnabled().join(",") + ")") << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("User") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Server") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Port") << StaticFunctions::DelegateTypeNumber() << "" << "Right");
  connectionsDTableViewHeaders->append(QStringList() << tr("Database") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Count") << StaticFunctions::DelegateTypeNumber() << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Collation") << (StaticFunctions::DelegateTypeEnum() + "(" + collationsJoined + ")") << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Use SSL") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Client Key File") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Client Cert File") << NoDelegate << "" << "Left");
  connectionsDTableViewHeaders->append(QStringList() << tr("Password") << StaticFunctions::DelegateTypePassword() << "" << "Left");
  listConnections = new DTableView(connectionsDTableViewHeaders);
//  connect(listConnections, SIGNAL(loadStarted(QString,uint,double)), parentWidget, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
//  connect(listConnections, SIGNAL(loadFinished(QString,uint,double)), parentWidget, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
//  connect(listConnections, SIGNAL(loadProgress(QString,uint,double)), parentWidget, SLOT(statusBarProgressMessageSlot(QString,uint,double)));
  connect(listConnections, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(connectioItemChangedSlot(QStandardItem*)));
  connectionsData = new QList<QStringList>();
  fillModelData();
  listConnections->setModelData(connectionsData, false);
  dStackedWidget->addWidget(listConnections, QIcon(":/images/svg/wallet-open.svg"), tr("Connections Settings"));

  //File Associations
  fileAssociations = new FileAssociations;
  dStackedWidget->addWidget(fileAssociations, QIcon(":/images/svg/server-database.svg"), tr("File Associations"));

  //PHP Specific Settings
  QVBoxLayout *vLayoutPHP = new QVBoxLayout;
  phpPHPCommand = new FileSelector(FileSelectorContexts::PHPExecutable);
  phpPHPCommand->setFileName(settings.value("PHP/Executable", "/usr/bin/php").toString());
  vLayoutPHP->addWidget(phpPHPCommand);
  vLayoutPHP->addStretch();
  QWidget *phpWid = new QWidget;
  phpWid->setLayout(vLayoutPHP);
  dStackedWidget->addWidget(phpWid, QIcon(":/images/svg/php-logo.svg"), tr("PHP"));

  //Application Theme
  applicationTheme = new ApplicationTheme;
  dStackedWidget->addWidget(applicationTheme, QIcon(":/images/svg/preferences-desktop-theme-5.svg"), tr("Application Theme"));

  mainVLayout->addWidget(dStackedWidget);
  QWidget *widMain = new QWidget;
  widMain->setLayout(mainVLayout);
  retranslateUi();
  setWidget(widMain);
}

void Preferences::fillModelData()
{
  connectionsData->clear();
  settings.beginGroup("ServerConnections");
  QStringList connections = settings.allKeys();
  connections.removeAt(connections.indexOf("StorePassword"));
  connections.removeAt(connections.indexOf("SortConnectionList"));
  foreach (QString connection, connections)
    connectionsData->append(QStringList() << "" << connection << StaticFunctions::explodeConnectionString(connection));
  settings.endGroup();
}

void Preferences::retranslateUi()
{
  setWindowTitle(tr("Preferences"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
  QLabel *label = qobject_cast<QLabel *>(styleFLayout->labelForField(stylesCombo));
  label->setText(tr("Select a style:"));
  checkBoxRememberWindows->setText(tr("Remember opened windows"));
  checkBoxOpenLastFile->setText(tr("Open last file used in the modules"));
  checkBoxSaveQueryBeforeExecution->setText(tr("Save Queries before execution?"));
  styleGroupBox->setTitle(tr("Appilcation Style"));
  tabSizeSpinBox->setSuffix(" " + tr("Spaces"));
  label = qobject_cast<QLabel *>(textEditorFLayout->labelForField(tabSizeSpinBox));
  label->setText(tr("Tab size:"));
  checkBoxAutomaticIndentation->setText(tr("Enable automatic indentation."));
  checkBoxCleanwhiteSpaces->setText(tr("Clean white spaces at the end of the line."));
  checkBoxSaveABackupFile->setText(tr("Save a backup copy before save a file."));
  //checkBoxShowTabsAndSpaces->setText(tr("Show Tabs and Spaces."));
  checkBoxEnableQueryLog->setText(tr("Enable query log"));
  licenseTemplate->retranslateUi();
  networkSettings->retranslateUi();
  fileAssociations->retranslateUi();
  phpPHPCommand->setText(tr("PHP CLI Command:"));
  checkBoxAutoreconnect->setText(tr("Use automatic reconnection"));
}

void Preferences::checkBoxCleanwhiteSpacesValueChanged(int value)
{
  settings.setValue("TextEditor/CleanWhiteSpaces", value);
}

void Preferences::checkBoxSaveABackupFileValueChanged(int value)
{
  settings.setValue("TextEditor/CreateBackupFile", value);
}

void Preferences::connectioItemChangedSlot(QStandardItem *item)
{
  //0 - Connection name
  //1 - User
  //2 - Host
  //3 - Port
  //4 - Database
  //5 - Conexion count -- No parsed but keeped the space.
  //6 - Collation
  //7 - UseSSL
  //8 - KeyFile
  //9 - CertFile
  //10 - Password

  settings.beginGroup("ServerConnections");
//  if ((item->data(Qt::UserRole).toString() != item->data(Qt::DisplayRole).toString()) && (item->column() == 0))
//    settings.remove(item->data(Qt::UserRole).toString());
  settings.setValue(listConnections->indexData(item->row(), 0, Qt::EditRole).toString()
                    , QString("%1:%2@%3:%4/%5 Count:%6 Collation:%7 UseSSL:%8 KeyFile:%9 CertFile:%10 Password:%11")
                    .arg(listConnections->indexData(item->row(), 1, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 2, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 3, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 4, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 5, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 6, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 7, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 8, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 9, Qt::EditRole).toString())
                    .arg(listConnections->indexData(item->row(), 10, Qt::EditRole).toString())
                    .arg(StaticFunctions::password(listConnections->indexData(item->row(), 11, Qt::EditRole).toString(), true))
                    );
  settings.endGroup();
  fillModelData();
  listConnections->setModelData(connectionsData, false);
}

void Preferences::checkBoxSaveQueryBeforeExecutionStateChanged()
{
  settings.setValue("SaveQueriesBeforeExecution", checkBoxSaveQueryBeforeExecution->isChecked());
}

//void Preferences::checkBoxShowTabsAndSpacesValueChanged(int value)
//{
//  settings.setValue("TextEditor/ShowTabsAndSpaces", value);
//}

void Preferences::checkBoxEnableQueryLogValueChanged(int value)
{
  settings.setValue("General/EnableQueryLog", value);
}

void Preferences::fileSelectorBackgroundImageSlot()
{
  settings.setValue("General/BackgroundImage", fileSelectorBackgroundImage->getFileName());
}

void Preferences::checkBoxAutoreconnectValueChanged(int value)
{
  settings.setValue("DBMS/Reconnect", value);
}

void Preferences::checkBoxAutomaticIndentationValueChanged(int value)
{
  settings.setValue("TextEditor/AutomaticIndentation", value);
}

void Preferences::tabSizeSpinBoxValueChanged(int value)
{
  settings.setValue("TextEditor/TabSize", value);
}

void Preferences::checkBoxOpenLastFileStateChanged()
{
  settings.setValue("General/OpenLastFile", checkBoxOpenLastFile->isChecked());
  if (!checkBoxOpenLastFile->isChecked()) {
    settings.setValue("General/LastMariaDBFile", "");
    settings.setValue("General/LastPHPFile", "");
  }
}

void Preferences::checkBoxRememberWindowsStateChanged()
{
  settings.setValue("General/RememberOpenedWindows", checkBoxRememberWindows->isChecked());
}

void Preferences::stylesComboCurrentIndexChanged(const QString &text)
{
  qApp->setStyle(text);
  settings.setValue("General/Style", text);
}
