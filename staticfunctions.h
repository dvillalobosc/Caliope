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

#ifndef STATICSYMBOLS_H
#define STATICSYMBOLS_H

#include <QStringList>
#include <QHash>
#include <QLocale>

#include "editortypes.h"

class QIcon;
class EditorTypes;
class QFont;

class StaticFunctions : public QObject
{
  Q_OBJECT

public:
  static QFont fixedWidthFont();
  static QStringList mariadbKeywords();
  static QStringList mariadbHelper();
  static QStringList mariadbFunctions();
  static QStringList mariadbDatatypes();
  static QStringList mariadbCharsets();
  static QStringList mariadbCodeErrorsNotCommaBothSides();
  static QStringList mariadbCodeErrorsNotCommaOnLeft();
  static QString bytesConvertor(QString bytes);
  static QString bytesConvertor(qulonglong bytes);
  static QString quoteSymbol(QString text);
  static QString unquoteSymbol(QString text);
  static QString password(QString pass = QString(), bool encrypt = false);
  static QHash<QString, QString> mariadbFunctionsComplete();
  static char rightBracketMatch(const char leftBracket);
  static char leftBracketMatch(const char rightBracket);
  static QList<char> bracketLeftList();
  static QString DelegateTypeNumber();
  static QString DelegateTypeNoDelegate();
  static QString DelegateTypeDateTime();
  static QString DelegateTypeDate();
  static QString DelegateTypePassword();
  static QString DelegateTypeEnum();
  static QIcon iconFromFileName(const QString fileName);
  static EditorTypes::EditorType findEditorType(const QString fileName);
  static QIcon iconFromFileName(const EditorTypes::EditorType editorType);
  static QStringList dbmsEnabled();
  enum dbmsTypes {Undefined, MySQL, MariaDB, PostgreSQL};
  static QString DBMSDateTimeFormat();
  static QString DBMSDateFormat();
  static QString DBMSDefaultDatabase();
  static QStringList explodeConnectionString(QString connectionName);
  static QString randomString(unsigned int length = 1);
  static QStringList currentEditorTypeKeywords(const EditorTypes::EditorType editorType);
  static QLocale currentLocale();
  static QString serverInformationQuery();
  static QString slowQueriesQuery();
};

#endif // STATICSYMBOLS_H
