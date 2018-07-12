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

#include <QSpinBox>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QLineEdit>

#include "ditemdelegate.h"
#include "staticfunctions.h"

#include "QDebug"

DItemDelegate::DItemDelegate(QString delegateType)
{
  this->delegateType = delegateType;
  if (this->delegateType.startsWith(StaticFunctions::DelegateTypeEnum()))
    foreach (QString option, delegateType.remove(QRegExp("('|" + StaticFunctions::DelegateTypeEnum() + "|\\(|\\))")).split(","))
      enumOptions.append(option);
}

QWidget *DItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  Q_UNUSED(option);
  Q_UNUSED(index);
  if (delegateType == StaticFunctions::DelegateTypeNumber()) {
    QSpinBox *widEditor = new QSpinBox(parent);
    widEditor->setMaximum(2147483647);
    widEditor->setMinimum(-2147483648);
    return widEditor;
  }
  if (delegateType == StaticFunctions::DelegateTypeDateTime()) {
    QDateTimeEdit *widEditor = new QDateTimeEdit(parent);
    widEditor->setCalendarPopup(true);
    widEditor->setDisplayFormat("yyyy-MMM-dd hh:mm:ss");
    return widEditor;
  }
  if (delegateType == StaticFunctions::DelegateTypeDate()) {
    QDateEdit *widEditor = new QDateEdit(parent);
    widEditor->setCalendarPopup(true);
    widEditor->setDisplayFormat("yyyy-MMM-dd");
    return widEditor;
  }
  if (delegateType == StaticFunctions::DelegateTypePassword()) {
    QLineEdit *widEditor = new QLineEdit(parent);
    widEditor->setEchoMode(QLineEdit::Password);
    return widEditor;
  }
  if (delegateType.startsWith(StaticFunctions::DelegateTypeEnum())) {
    QComboBox *widEditor = new QComboBox(parent);
    widEditor->addItems(enumOptions);
    return widEditor;
  }
  return new QWidget();
}

void DItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QVariant value = index.model()->data(index, Qt::EditRole);
  if (delegateType == StaticFunctions::DelegateTypeNumber()) {
    QSpinBox *widEditor = static_cast<QSpinBox*>(editor);
    widEditor->setValue(value.toInt());
  }
  if (delegateType.startsWith(StaticFunctions::DelegateTypeEnum())) {
    QComboBox *widEditor = static_cast<QComboBox*>(editor);
    widEditor->setCurrentIndex(widEditor->findText(value.toString()));
  }
  if (delegateType == StaticFunctions::DelegateTypeDateTime()) {
    QDateTimeEdit *widEditor = static_cast<QDateTimeEdit*>(editor);
    widEditor->setCalendarPopup(true);
    widEditor->setDisplayFormat("yyyy-MMM-dd hh:mm:ss");
    widEditor->setDateTime(QDateTime::fromString(value.toString(), StaticFunctions::DBMSDateTimeFormat()));
  }
  if (delegateType == StaticFunctions::DelegateTypeDate()) {
    QDateEdit *widEditor = static_cast<QDateEdit*>(editor);
    widEditor->setCalendarPopup(true);
    widEditor->setDisplayFormat("yyyy-MMM-dd");
    widEditor->setDate(QDate::fromString(value.toString(), StaticFunctions::DBMSDateFormat()));
  }
  if (delegateType == StaticFunctions::DelegateTypePassword()) {
    QLineEdit *widEditor = static_cast<QLineEdit*>(editor);
    widEditor->setText(value.toString());
    widEditor->setToolTip(widEditor->text());
  }
}

void DItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  if (delegateType == StaticFunctions::DelegateTypeNumber()) {
    QSpinBox *widEditor = static_cast<QSpinBox*>(editor);
//    spinBox->interpretText();
    model->setData(index, widEditor->value(), Qt::EditRole);
  }
  if (delegateType.startsWith(StaticFunctions::DelegateTypeEnum())) {
    QComboBox *widEditor = static_cast<QComboBox*>(editor);
    model->setData(index, widEditor->currentText(), Qt::EditRole);
  }
  if (delegateType == StaticFunctions::DelegateTypeDateTime()) {
    QDateTimeEdit *widEditor = static_cast<QDateTimeEdit*>(editor);
    model->setData(index, widEditor->dateTime().toString(StaticFunctions::DBMSDateTimeFormat()), Qt::EditRole);
  }
  if (delegateType == StaticFunctions::DelegateTypeDate()) {
    QDateEdit *widEditor = static_cast<QDateEdit*>(editor);
    model->setData(index, widEditor->date().toString(StaticFunctions::DBMSDateFormat()), Qt::EditRole);
  }
  if (delegateType == StaticFunctions::DelegateTypePassword()) {
    QLineEdit *widEditor = static_cast<QLineEdit*>(editor);
    model->setData(index, widEditor->text());
  }
}

void DItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  Q_UNUSED(index);
  editor->setGeometry(option.rect);
}
