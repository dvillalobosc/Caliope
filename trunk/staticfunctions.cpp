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

#include <QFontDatabase>
#include <QTime>
#include <QIcon>
#include <QFileInfo>
#include <QSettings>
#include <QApplication>

#include "staticfunctions.h"

#include <QDebug>

QString StaticFunctions::DelegateTypeNumber() { return "DelegateTypeNumber"; }
QString StaticFunctions::DelegateTypeNoDelegate() { return "DelegateTypeNoDelegate"; }
QString StaticFunctions::DelegateTypeDateTime() { return "DelegateTypeDateTime"; }
QString StaticFunctions::DelegateTypeDate() { return "DelegateTypeDate"; }
QString StaticFunctions::DelegateTypePassword() { return "DelegateTypePassword"; }
QString StaticFunctions::DelegateTypeEnum() { return "DelegateTypeEnum"; }

QString StaticFunctions::DBMSDateTimeFormat() {

  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
  case StaticFunctions::Undefined:
  default:
    return "yyyy-MM-dd hh:mm:ss";
    break;
  }
}

QString StaticFunctions::DBMSDateFormat() {

  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
  case StaticFunctions::Undefined:
  default:
    return "yyyy-MM-dd";
    break;
  }
}

QString StaticFunctions::DBMSDefaultDatabase()
{

  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return "mysql";
    break;
  case StaticFunctions::Undefined:
  default:
    return "information_schema";
    break;
  }
}

EditorTypes::EditorType StaticFunctions::findEditorType(const QString fileName)
{
  QFileInfo fileInfo(fileName);
  QString completeSuffix(fileInfo.completeSuffix().toLower());
  QString suffix(fileInfo.suffix().toLower());
  QSettings settings;
  if (settings.value("FileAssociations/SQLFiles", "").toString().split(",").contains(completeSuffix)
      || settings.value("FileAssociations/SQLFiles", "").toString().split(",").contains(suffix))
    return EditorTypes::SQLQuery;
  return EditorTypes::NoEditor;
}

QIcon StaticFunctions::iconFromFileName(const EditorTypes::EditorType editorType)
{
  switch(editorType) {
  case EditorTypes::SQLQuery:
    return iconFromFileName("file.sql");
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
    //  case EditorTypes::NoEditor:
    //    return iconFromFileName("file.");
    //    break;
  // case EditorTypes::Diff:
  // default: Q_ASSERT(false);
  }
  return iconFromFileName("");
}

QStringList StaticFunctions::dbmsEnabled()
{
  return QStringList() << "--" << "MySQL" << "MariaDB";// << "PostgreSQL";
}

QIcon StaticFunctions::iconFromFileName(const QString fileName)
{
  switch(findEditorType(fileName)) {
  case EditorTypes::SQLQuery:
    return QIcon(":/images/svg/text-x-sql.svg");
    break;
  case EditorTypes::NoEditor:
    return QIcon(QIcon::fromTheme("document-new", QIcon(":/images/svg/document-new-6.svg")));
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
    break;
  // case EditorTypes::Diff:
  // default: Q_ASSERT(false);
  }

  return QIcon();
}

char StaticFunctions::rightBracketMatch(const char leftBracket)
{
  if (leftBracket == '(')
    return ')';
  if (leftBracket == '{')
    return '}';
  if (leftBracket == '[')
    return ']';
  return '(';
}

char StaticFunctions::leftBracketMatch(const char rightBracket)
{
  if (rightBracket == ')')
    return '(';
  if (rightBracket == '}')
    return '{';
  if (rightBracket == ']')
    return '[';
  return ')';
}

QList<char> StaticFunctions::bracketLeftList()
{
  QList<char> list;
  list << '(' << '[' << '{';
  return list;

}

QHash<QString, QString> StaticFunctions::mariadbFunctionsComplete()
{
  QHash<QString, QString> data;
  data.insert("ABS", QString("<u>ABS</u>(<b>X</b>) <br />%1").arg(tr("Returns the absolute value of <b>X</b>")));
  //  data.insert("ACOS", QString("<u>ACOS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ADDDATE", QString("<u>ADDDATE</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("")));
  data.insert("ADDTIME", QString("<u>ADDTIME</u>(<b></b>) <br />%1").arg(tr("Adds expr2 to expr1 and returns the result.<br />expr1 is a time or datetime expression, and expr2 is a time expression.")));
  data.insert("AES_DECRYPT", QString("binary <u>AES_DECRYPT</u>(<b>crypt_str, key_str</b>) <br />%1").arg(tr("This function decrypts data using the official AES (Advanced Encryption Standard) algorithm.")));
  data.insert("AES_ENCRYPT", QString("binary <u>AES_ENCRYPT</u>(<b>crypt_str, key_str</b>) <br />%1").arg(tr("This function encrypts data using the official AES (Advanced Encryption Standard) algorithm.")));
  //  data.insert("ASCII", QString("<u>ASCII</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ASIN", QString("<u>ASIN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ATAN", QString("<u>ATAN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ATAN2", QString("<u>ATAN2</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("AVG", QString("<u>AVG</u>(<b>[DISTINCT] expr)</b>) <br />%1").arg(tr("Returns the average value of expr.<br />The DISTINCT option can be used as of MySQL 5.0.3 to return the average of the distinct values of expr.")));
  //  data.insert("BENCHMARK", QString("<u>BENCHMARK</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("BIN", QString("<u>BIN</u>(<b>N</b>) <br />%1").arg(tr("Returns a string representation of the binary value of N.")));
  //  data.insert("BIT_AND", QString("<u>BIT_AND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("BIT_COUNT", QString("<u>BIT_COUNT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("BIT_LENGTH", QString("<u>BIT_LENGTH</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("BIT_OR", QString("<u>BIT_OR</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("BIT_XOR", QString("<u>BIT_XOR</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("CAST", QString("<u>CAST</u>(<b>expr AS type)</b>) <br />%1").arg(tr("Takes an expression of any type and produces a result value of a specified type.")));
  data.insert("CEIL", QString("<u>CEIL</u>(<b>x</b>) <br />%1").arg(tr("Returns the smallest integer value not less than X")));
  data.insert("CEILING", QString("<u>CEILING</u>(<b>x</b>) <br />%1").arg(tr("Returns the smallest integer value not less than X")));
  data.insert("CHAR_LENGTH", QString("<u>CHAR_LENGTH</u>(<b>str</b>) <br />%1").arg(tr("Returns the length of the string str, measured in characters. A multi-byte character counts as a single character.")));
  //  data.insert("CHARACTER_LENGTH", QString("<u>CHARACTER_LENGTH</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COALESCE", QString("<u>COALESCE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COERCIBILITY", QString("<u>COERCIBILITY</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COLLATION", QString("<u>COLLATION</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COMPRESS", QString("<u>COMPRESS</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("CONCAT_WS", QString("string <u>CONCAT_WS</u>(<b>separator, str1[,str2,...])</b>) <br />%1").arg(tr("Concatenate the strings with the given separator.")));
  data.insert("CONCAT", QString("<u>CONCAT</u>(str1, str2, ...)) <br />%1").arg(tr("Returns the string that results from concatenating the arguments.")));
  data.insert("CONNECTION_ID", QString("<u>CONNECTION_ID</u>(<b></b>) <br />%1").arg(tr("Returns the connection ID (thread ID) for the connection.")));
  //  data.insert("CONV", QString("<u>CONV</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("CONVERT_TZ", QString("<u>CONVERT_TZ</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COS", QString("<u>COS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COT", QString("<u>COT</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("COUNT", QString("<u>COUNT</u>(<b>expr</b>) <br />%1").arg(tr("Returns a count of the number of non-NULL values of expr in the rows retrieved by a SELECT statement.")));
  //  data.insert("CRC32", QString("<u>CRC32</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("CURDATE", QString("<u>CURDATE</u>() <br />%1").arg(tr("Returns the current date as a value in 'YYYY-MM-DD' or YYYYMMDD format, depending on whether the function is used in a string or numeric context.")));
  data.insert("CURRENT_DATE", QString("<u>CURRENT_DATE</u>() <br />%1").arg(tr("Returns the current date as a value in 'YYYY-MM-DD' or YYYYMMDD format, depending on whether the function is used in a string or numeric context.")));
  data.insert("CURRENT_ROLE", QString("<u>CURRENT_ROLE</u>() <br />%1").arg(tr("Returns the current role name. ")));
  //  data.insert("CURRENT_TIME", QString("<u>CURRENT_TIME</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("CURRENT_TIMESTAMP", QString("<u>CURRENT_TIMESTAMP</u>() <br />%1").arg(tr("Returns the current date and time as a value in 'YYYY-MM-DD HH:MM:SS' or YYYYMMDDHHMMSS.uuuuuu format, <br />depending on whether the function is used in a string or numeric context.<br />The value is expressed in the current time zone.")));
  data.insert("CURRENT_USER", QString("<u>CURRENT_USER</u>() <br />%1").arg(tr("Returns the user name and host name combination for the MySQL account that the server used to authenticate the current client.")));
  //  data.insert("CURTIME", QString("<u>CURTIME</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("DATE_ADD", QString("<u>DATE_ADD</u>(<b>date, INTERVAL expr unit</b>) <br />%1").arg(tr("These functions perform date arithmetic.<br />The date argument specifies the starting date or datetime value.<br />expr is an expression specifying the interval value to be added or subtracted from the starting date.<br />expr is a string; it may start with a “-” for negative intervals.<br />unit is a keyword indicating the units in which the expression should be interpreted.")));
  data.insert("DATE_FORMAT", QString("<u>DATE_FORMAT</u>(<b>date, format</b>) <br />%1").arg(tr("Returns a string containing the date in the specified format.")));
  data.insert("DATE_SUB", QString("<u>DATE_SUB</u>(<b>date, INTERVAL expr unit</b>) <br />%1").arg(tr("These functions perform date arithmetic.<br />The date argument specifies the starting date or datetime value.<br />expr is an expression specifying the interval value to be added or subtracted from the starting date.<br />expr is a string; it may start with a “-” for negative intervals.<br />unit is a keyword indicating the units in which the expression should be interpreted.")));
  data.insert("DATEDIFF", QString("<u>DATEDIFF</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("Returns expr1 - expr2 expressed as a value in days from one date to the other.")));
  //  data.insert("DAY_HOUR", QString("<u>DAY_HOUR</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DAY_MICROSECOND", QString("<u>DAY_MICROSECOND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DAY_MINUTE", QString("<u>DAY_MINUTE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DAY_SECOND", QString("<u>DAY_SECOND</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("DAYNAME", QString("<u>DAYNAME</u>(<b>date</b>) <br />%1").arg(tr("Returns the name of the weekday for date.<br />The language used for the name is controlled by the value of the lc_time_names system variable.")));
  //  data.insert("DAYOFMONTH", QString("<u>DAYOFMONTH</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DAYOFWEEK", QString("<u>DAYOFWEEK</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DAYOFYEAR", QString("<u>DAYOFYEAR</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DECODE", QString("<u>DECODE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DEGREES", QString("<u>DEGREES</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DES_DECRYPT", QString("<u>DES_DECRYPT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DES_ENCRYPT", QString("<u>DES_ENCRYPT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("DIV", QString("<u>DIV</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ELT", QString("<u>ELT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ENCODE", QString("<u>ENCODE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ENCRYPT", QString("<u>ENCRYPT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ESSION_USER", QString("<u>ESSION_USER</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("EXP", QString("<u>EXP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("EXPORT_SET", QString("<u>EXPORT_SET</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("EXTRACT", QString("<u>EXTRACT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("EXTRACTVALUE", QString("<u>EXTRACTVALUE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("FIELD", QString("<u>FIELD</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("FIND_IN_SET", QString("<u>FIND_IN_SET</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("FLOOR", QString("<u>FLOOR</u>(<b>x</b>) <br />%1").arg(tr("Returns the largest integer value not greater than x.")));
  data.insert("FORMAT", QString("<u>FORMAT</u>(<b>X, D</b>) <br />%1").arg(tr("Formats the number X to a format like '#,###,###.##', rounded to D decimal places, and returns the result as a string.")));
  //  data.insert("FOUND_ROWS", QString("<u>FOUND_ROWS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("FROM_DAYS", QString("<u>FROM_DAYS</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("FROM_UNIXTIME", QString("date <u>FROM_UNIXTIME</u>(<b>unix_timestamp [, format])</b>) <br />%1").arg(tr("Returns a representation of the unix_timestamp argument as a value in 'YYYY-MM-DD HH:MM:SS' or YYYYMMDDHHMMSS.uuuuuu format,<br />depending on whether the function is used in a string or numeric context.<br />If format is given, the result is formatted according to the format string")));
  //  data.insert("GET_FORMAT", QString("<u>GET_FORMAT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("GET_LOCK", QString("<u>GET_LOCK</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("GREATEST", QString("<u>GREATEST</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("GROUP_CONCAT", QString("<u>GROUP_CONCAT</u>(<b>expr</b>) <br />%1").arg(tr("This function returns a string result with the concatenated non-NULL values from a group. It returns NULL if there are no non-NULL values.")));
  data.insert("HEX", QString("string <u>HEX</u>(<b>str</b>) <br />%1").arg(tr("For a string argument str, HEX() returns a hexadecimal string representation of str where each byte of each character in str is converted to two hexadecimal digits.")));
  //  data.insert("HOUR_MICROSECOND", QString("<u>HOUR_MICROSECOND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("HOUR_MINUTE", QString("<u>HOUR_MINUTE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("HOUR_SECOND", QString("<u>HOUR_SECOND</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("IFNULL", QString("<u>IFNULL</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("If expr1 is not NULL, IFNULL() returns expr1; otherwise it returns expr2.<br />IFNULL() returns a numeric or string value, depending on the context in which it is used.")));
  data.insert("INET_ATON", QString("<u>INET_ATON</u>(<b>expr</b>) <br />%1").arg(tr("Given the dotted-quad representation of an IPv4 network address as a string, returns an integer that represents the numeric value of the address in network byte order (big endian).")));
  data.insert("INET_NTOA", QString("<u>INET_NTOA</u>(<b>expr</b>) <br />%1").arg(tr("Given a numeric IPv4 network address in network byte order, returns the dotted-quad representation of the address as a binary string.")));
  data.insert("INSTR", QString("<u>INSTR</u>(<b>str, substr</b>) <br />%1").arg(tr("Returns the position of the first occurrence of substring substr in string str.")));
  //  data.insert("INTERVAL", QString("<u>INTERVAL</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("IS_FREE_LOCK", QString("<u>IS_FREE_LOCK</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("IS_USED_LOCK", QString("<u>IS_USED_LOCK</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ISNULL", QString("<u>ISNULL</u>(<b>expr</b>) <br />%1").arg(tr("If expr is NULL, ISNULL() returns 1, otherwise it returns 0.")));
  //  data.insert("LAST_DAY", QString("<u>LAST_DAY</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("LAST_INSERT_ID", QString("<u>LAST_INSERT_ID</u>(<b>expr</b>) <br />%1").arg(tr("Returns a value representing the first automatically generated value successfully inserted for an AUTO_INCREMENT column as a result of the most recently executed INSERT statement.")));
  data.insert("LCASE", QString("<u>LCASE</u>(<b>str</b>) <br />%1").arg(tr("Returns the string str with all characters changed to lowercase according to the current character set mapping.")));
  //  data.insert("LEAST", QString("<u>LEAST</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("LEFT", QString("<u>LEFT</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("LENGTH", QString("<u>LENGTH</u>(<b>str)</b>) <br />%1").arg(tr("Returns the length of the string str, measured in bytes. <br />A multi-byte character counts as multiple bytes.")));
  //  data.insert("LN", QString("<u>LN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("LOAD_FILE", QString("<u>LOAD_FILE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("LOCALTIMESTAMP", QString("<u>LOCALTIMESTAMP</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("LOCATE", QString("<u>LOCATE</u>(<b>substr, str[, pos])</b>) <br />%1").arg(tr("Returns the position of the first occurrence of substring substr in string str, starting at position pos.")));
  //  data.insert("LOG", QString("<u>LOG</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("LOG10", QString("<u>LOG10</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("LOG2", QString("<u>LOG2</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("LOWER", QString("<u>LOWER</u>(<b>str</b>) <br />%1").arg(tr("Returns the string str with all characters changed to lowercase according to the current character set mapping. ")));
  data.insert("LPAD", QString("<u>LPAD</u>(<b>str, len, padstr</b>) <br />%1").arg(tr("Returns the string str, left-padded with the string padstr to a length of len characters.<br />If str is longer than len, the return value is shortened to len characters.")));
  //  data.insert("LTRIM", QString("<u>LTRIM</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("MAKE_SET", QString("<u>MAKE_SET</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("MAKEDATE", QString("<u>MAKEDATE</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("MAKETIME", QString("<u>MAKETIME</u>(<b>hour, minute, second</b>) <br />%1").arg(tr("Returns a time value calculated from the hour, minute, and second arguments. ")));
  //  data.insert("MASTER_POS_WAIT", QString("<u>MASTER_POS_WAIT</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("MAX", QString("<u>MAX</u>(<b>[DISTINCT] expr)</b>) <br />%1").arg(tr("Returns the maximum value of expr.")));
  data.insert("MD5", QString("<u>MD5</u>(<b>str</b>) <br />%1").arg(tr("Calculates an MD5 128-bit checksum for the string. The value is returned as a string of 32 hex digits, or NULL if the argument was NULL.")));
  data.insert("MICROSECOND", QString("<u>MICROSECOND</u>(<b>expr</b>) <br />%1").arg(tr("Returns the microseconds from the time or datetime expression expr as a number in the range from 0 to 999999.")));
  data.insert("MID", QString("<u>MID</u>(<b>str, pos ([str FROM pos], [str, pos, len], [str FROM pos FOR len])</b>) <br />%1").arg(tr("The forms without a len argument return a substring from string str starting at position pos. <br />The forms with a len argument return a substring len characters long from string str, starting at position pos.")));
  data.insert("MIN", QString("<u>MIN</u>(<b>MIN([DISTINCT] expr)</b>) <br />%1").arg(tr("Returns the minimum value of expr.")));
  //  data.insert("MINUTE_MICROSECOND", QString("<u>MINUTE_MICROSECOND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("MINUTE_SECOND", QString("<u>MINUTE_SECOND</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("MONTH", QString("<u>MONTH</u>(<b>date</b>) <br />%1").arg(tr("Returns the month for date, in the range 1 to 12 for January to December.")));
  //  data.insert("MONTHNAME", QString("<u>MONTHNAME</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("NAME_CONST", QString("<u>NAME_CONST</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("NOW", QString("<u>NOW</u>() <br />%1").arg(tr("Returns the current date and time as a value in 'YYYY-MM-DD HH:MM:SS' or YYYYMMDDHHMMSS.uuuuuu format, <br />depending on whether the function is used in a string or numeric context.<br />The value is expressed in the current time zone.")));
  data.insert("NULLIF", QString("<u>NULLIF</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("Returns NULL if expr1 = expr2 is true, otherwise returns expr1.<br />This is the same as CASE WHEN expr1 = expr2 THEN NULL ELSE expr1 END.")));
  //  data.insert("OCT", QString("<u>OCT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("OCTET_LENGTH", QString("<u>OCTET_LENGTH</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("OLD_PASSWORD", QString("<u>OLD_PASSWORD</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ORD", QString("<u>ORD</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("PASSWORD", QString("<u>PASSWORD</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("PERIOD_ADD", QString("<u>PERIOD_ADD</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("PERIOD_DIFF", QString("<u>PERIOD_DIFF</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("PI", QString("<u>PI</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("PLUGINS", QString("<u>PLUGINS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("POSITION", QString("<u>POSITION</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("POW", QString("<u>POW</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("POWER", QString("<u>POWER</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("QUOTE", QString("<u>QUOTE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("RADIANS", QString("<u>RADIANS</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("RAND", QString("<u>RAND</u>(<b>[N]</b>) <br />%1").arg(tr("Returns a random floating-point value v in the range 0 <= v < 1.0. If a constant integer argument N is specified, it is used as the seed value, which produces a repeatable sequence of column values.")));
  //  data.insert("RELEASE_LOCK", QString("<u>RELEASE_LOCK</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("REVERSE", QString("<u>REVERSE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("RIGHT", QString("<u>RIGHT</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ROUND", QString("<u>ROUND</u>(<b>X [, D]</b>) <br />%1").arg(tr("Rounds the argument X to D decimal places.")));
  data.insert("ROW_COUNT", QString("<u>ROW_COUNT</u>() <br />%1").arg(tr("Returns the number of rows changed, deleted, or inserted by the last statement.")));
  data.insert("RPAD", QString("<u>RPAD</u>(<b>str, len, padstr</b>) <br />%1").arg(tr("Returns the string str, right-padded with the string padstr to a length of len characters.<br />If str is longer than len, the return value is shortened to len characters.")));
  //  data.insert("RTRIM", QString("<u>RTRIM</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("SEC_TO_TIME", QString("<u>SEC_TO_TIME</u>(<b>seconds</b>) <br />%1").arg(tr("Returns the seconds argument, converted to hours, minutes, and seconds, as a TIME value.")));
  //  data.insert("SECOND_MICROSECOND", QString("<u>SECOND_MICROSECOND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SHA", QString("<u>SHA</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SHA1", QString("<u>SHA1</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SIGN", QString("<u>SIGN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SIN", QString("<u>SIN</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("SLEEP", QString("0 <u>SLEEP</u>(<b>duration</b>) <br />%1").arg(tr("Sleeps (pauses) for the number of seconds given by the duration argument, then returns 0.")));
  //  data.insert("SOUNDEX", QString("<u>SOUNDEX</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SPACE", QString("<u>SPACE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SQL_CALC_FOUND_ROWS", QString("<u>SQL_CALC_FOUND_ROWS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SQR", QString("<u>SQR</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("STD", QString("<u>STD</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("STDDEV_POP", QString("<u>STDDEV_POP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("STDDEV_SAMP", QString("<u>STDDEV_SAMP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("STDDEV", QString("<u>STDDEV</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("STR_TO_DATE", QString("<u>STR_TO_DATE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("STRCMP", QString("<u>STRCMP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SUBDATE", QString("<u>SUBDATE</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("SUBSTR", QString("<u>SUBSTR</u>(<b>str, pos ([str FROM pos], [str, pos, len], [str FROM pos FOR len])</b>) <br />%1").arg(tr("The forms without a len argument return a substring from string str starting at position pos. <br />The forms with a len argument return a substring len characters long from string str, starting at position pos.")));
  data.insert("SUBSTRING_INDEX", QString("<u>SUBSTRING_INDEX</u>(<b>str, delim, count</b>) <br />%1").arg(tr("Returns the substring from string str before count occurrences of the delimiter delim. <br />If count is positive, everything to the left of the final delimiter (counting from the left) is returned. <br />If count is negative, everything to the right of the final delimiter (counting from the right) is returned.")));
  data.insert("SUBSTRING", QString("<u>SUBSTRING</u>(<b>str, pos ([str FROM pos], [str, pos, len], [str FROM pos FOR len])</b>) <br />%1").arg(tr("The forms without a len argument return a substring from string str starting at position pos. <br />The forms with a len argument return a substring len characters long from string str, starting at position pos.")));
  data.insert("SUBTIME", QString("<u>SUBTIME</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("Returns expr1 – expr2 expressed as a value in the same format as expr1.<br />expr1 is a time or datetime expression, and expr2 is a time expression.")));
  //  data.insert("SYSDATE", QString("<u>SYSDATE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SYSTEM_USER", QString("<u>SYSTEM_USER</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("TAN", QString("<u>TAN</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("TIME_FORMAT", QString("<u>TIME_FORMAT</u>(<b>time, format</b>) <br />%1").arg(tr("Returns a string containing the time in the specified format.")));
  data.insert("TIME_TO_SEC", QString("<u>TIME_TO_SEC</u>(<b>time</b>) <br />%1").arg(tr("Returns the time argument, converted to seconds.")));
  data.insert("TIMEDIFF", QString("<u>TIMEDIFF</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("Returns expr1 - expr2 expressed as a time value.<br />expr1 and expr2 are time or date-and-time expressions, but both must be of the same type.")));
  //  data.insert("TIMESTAMPADD", QString("<u>TIMESTAMPADD</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("TIMESTAMPDIFF", QString("<u>TIMESTAMPDIFF</u>(<b>unit, datetime_expr1, datetime_expr2</b>) <br />%1").arg(tr("Returns datetime_expr2 - datetime_expr1, where datetime_expr1 and datetime_expr2 are date or datetime expressions.")));
  data.insert("TO_DAYS", QString("<u>TO_DAYS</u>(<b>date</b>) <br />%1").arg(tr("Returns a day number (the number of days since year 0).")));
  data.insert("TRIM", QString("<u>TRIM</u>(<b>[{BOTH | LEADING | TRAILING} [remstr] FROM] str)</b>) <br />%1").arg(tr("Returns the string str with all remstr prefixes or suffixes removed.<br />If none of the specifiers BOTH, LEADING, or TRAILING is given, BOTH is assumed. remstr is optional and, if not specified, spaces are removed.")));
  data.insert("TRUNCATE", QString("<u>TO_DAYS</u>(<b>X, D</b>) <br />%1").arg(tr("Returns the number X, truncated to D decimal places.<br />If D is 0, the result has no decimal point or fractional part.<br />D can be negative to cause D digits left of the decimal point of the value X to become zero.")));
  data.insert("UCASE", QString("<u>UCASE</u>(<b>str</b>) <br />%1").arg(tr("Returns the string str with all characters changed to uppercase according to the current character set mapping.")));
  //  data.insert("UNCOMPRESS", QString("<u>UNCOMPRESS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("UNCOMPRESSED_LENGTH", QString("<u>UNCOMPRESSED_LENGTH</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("UNHEX", QString("<u>UNHEX</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("UNIX_TIMESTAMP", QString("<u>UNIX_TIMESTAMP</u>(<b>[date]</b>) <br />%1").arg(tr("If called with no argument, returns a Unix timestamp (seconds since '1970-01-01 00:00:00' UTC) as an unsigned integer.<br />If UNIX_TIMESTAMP() is called with a date argument, it returns the value of the argument as seconds since '1970-01-01 00:00:00' UTC.")));
  //  data.insert("UpdateXML", QString("<u>UpdateXML</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("UPPER", QString("<u>UPPER</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("USER", QString("<u>USER</u>(<b></b>) <br />%1").arg(tr("Returns the current MySQL user name and host name.")));
  //  data.insert("UTC_DATE", QString("<u>UTC_DATE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("UTC_TIME", QString("<u>UTC_TIME</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("UTC_TIMESTAMP", QString("<u>UTC_TIMESTAMP</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("UUID", QString("string <u>UUID</u>(<b></b>) <br />%1").arg(tr("Returns a Universal Unique Identifier (UUID) generated according to RFC 4122")));
  //  data.insert("VAR_POP", QString("<u>VAR_POP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("VAR_SAMP", QString("<u>VAR_SAMP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("VARIANCE", QString("<u>VARIANCE</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("VERSION", QString("<u>VERSION</u>(<b></b>) <br />%1").arg(tr("Returns a string that indicates the MySQL server version.")));
  data.insert("WEEK", QString("<u>WEEK</u>(<b>date [,mode]</b>) <br />%1").arg(tr("This function returns the week number for date.")));
  //  data.insert("WEEKDAY", QString("<u>WEEKDAY</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("WEEKOFYEAR", QString("<u>WEEKOFYEAR</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("YEAR_MONTH", QString("<u>YEAR_MONTH</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("YEARWEEK", QString("<u>YEARWEEK</u>(<b></b>) <br />%1").arg(tr("")));

  //Descripction for Keywords
  data.insert("BETWEEN", QString("expr BETWEEN min AND max <br />%1").arg(tr("If expr is greater than or equal to min and expr is less than or equal to max, BETWEEN returns 1, otherwise it returns 0.")));
  return data;
}

QString StaticFunctions::password(QString pass, bool encrypt)
{
  QString pas;

  if (encrypt) {
    QChar *data;
    qsrand(QTime::currentTime().second());
    pas = "*";
    data = pass.data();
    while (!data->isNull()) {
      int seed = (int) qrand() % 9;
      pas += QString("%1%2").arg(seed).arg(QChar(data->unicode() + seed));
      ++data;
    }
  } else {
    for (int i = 1; i < pass.length(); i++) {
      pas += QString("%1").arg(QChar(pass.at(i + 1).unicode() - QString(pass.at(i)).toInt()));
      i++;
    }
  }
  return pas;
}

QString StaticFunctions::quoteSymbol(QString text)
{
  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return (text.startsWith("`") ? "" : "`") + text + (text.endsWith("`") ? "" : "`");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return text;
}

QString StaticFunctions::unquoteSymbol(QString text)
{
  if (text.startsWith("`"))
    text = text.right(text.length() - 1);
  if (text.endsWith("`"))
    text = text.left(text.length() - 1);
  return text;
}

QFont StaticFunctions::fixedWidthFont()
{
  QFontDatabase database;
  foreach (QString family, database.families())
    if (database.isFixedPitch(family))
      return QFont(family);
  return QFont();
}

QStringList StaticFunctions::mariadbKeywords()
{
  return QStringList() << "ACCESSIBLE"
      << "ACTION"
      << "ADD"
      << "AFTER"
      << "ALGORITHM"
      << "ALL"
      << "ALTER"
      << "ANALYSE"
      << "ANALYZE"
      << "AND"
      << "ARCHIVE"
      << "AS"
      << "ASC"
      << "ASENSITIVE"
      << "AT"
      << "AUTHORS"
      << "AUTO_INCREMENT"
      << "AUTOCOMMIT"
      << "BEFORE"
      << "BEGIN"
      << "BETWEEN"
      << "BINARY"
      << "BINLOG"
      << "BOTH"
      << "BTREE"
      << "BY"
      << "CACHE"
      << "CALL"
      << "CASCADE"
      << "CASCADED"
      << "CASE"
      << "CHAIN"
      << "CHANGE"
      << "CHANGED"
      << "CHARACTER_SET_CLIENT"
      << "CHARACTER"
      << "CHARSET"
      << "CHECK"
      << "CHECKSUM"
      << "CLIENT"
      << "CLIENT_STATISTICS"
      << "CLOSE"
      << "COALESCE"
      << "CODE"
      << "COLLATE"
      << "COLLATION"
      << "COLUMN"
      << "COLUMNS"
      << "COMMENT"
      << "COMMIT"
      << "COMMITTED"
      << "COMPLETION"
      << "COMPRESSED"
      << "CONDITION"
      << "CONNECTION"
      << "CONSISTENT"
      << "CONSTRAINT"
      << "CONTINUE"
      << "CONTRIBUTORS"
      << "CONVERT"
      << "CREATE"
      << "CROSS"
      << "CURSOR"
      << "CSV"
      << "DATA"
      << "DATABASE"
      << "DATABASES"
      << "DAY"
      << "DEALLOCATE"
      << "DECLARE"
      << "DEFAULT"
      << "DEFINER"
      << "DELAYED"
      << "DELETE"
      << "DELIMITER"
      << "DES_KEY_FILE"
      << "DESC"
      << "DESCRIBE"
      << "DETERMINISTIC"
      << "DIRECTORY"
      << "DISABLE"
      << "DISTINCT"
      << "DISTINCTROW"
      << "DO"
      << "DROP"
      << "DUAL"
      << "DUMPFILE"
      << "DUPLICATE"
      << "DYNAMIC"
      << "EACH"
      << "EDIT"
      << "ELSE"
      << "ELSEIF"
      << "ENABLE"
      << "ENCLOSED"
      << "END"
      << "ENDS"
      << "ENGINE"
      << "ENGINES"
      << "ERRORS"
      << "ESCAPE"
      << "ESCAPED"
      << "EXAMINATED"
      << "EXECUTE"
      << "EVENT"
      << "EVENTS"
      << "EVERY"
      << "EXISTS"
      << "EXIT"
      << "EXPIRE"
      << "EXPLAIN"
      << "EXTENDED"
      << "FALSE"
      << "FEDERATED"
      << "FETCH"
      << "FLUSH"
      << "FAST"
      << "FIELDS"
      << "FILE"
      << "FIRST"
      << "FOR"
      << "FORCE"
      << "FOREIGN_KEY_CHECKS"
      << "FOREIGN"
      << "FOUND"
      << "FROM"
      << "FULL"
      << "FUNCTION"
      << "GLOBAL"
      << "GRANT"
      << "GRANTS"
      << "GROUP"
      << "GROUP BY"
      << "GROUP_CONCAT_MAX_LEN"
      << "HANDLER"
      << "HASH"
      << "HAVING"
      << "HELP"
      << "HIGH_PRIORITY"
      << "HOUR"
      << "HOST"
      << "HOSTS"
      << "IDENTIFIED"
      << "IF"
      << "IGNORE"
      << "IGNORE_SERVER_IDS"
      << "IN"
      << "INDEX"
      << "INDEXES"
      << "INDEX_STATISTICS"
      << "INFILE"
      << "INNER"
      << "INNODB"
      << "INOUT"
      << "INSENSITIVE"
      << "INSERT"
      << "INSTALL"
      << "INTERVAL"
      << "INTO"
      << "INVOKER"
      << "IO_THREAD"
      << "IS"
      << "ISOLATION"
      << "ITERATE"
      << "JOIN"
      << "KEY"
      << "KEYS"
      << "KILL"
      << "LANGUAGE"
      << "LEADING"
      << "LEAVE"
      << "LEFT"
      << "LESS"
      << "LEVEL"
      << "LIKE"
      << "LIMIT"
      << "LINEAR"
      << "LINES"
      << "LIST"
      << "LOAD"
      << "LOCAL"
      << "LOCALTIME"
      << "LOCK"
      << "LOGS"
      << "LOOP"
      << "LOW_PRIORITY"
      << "MASTER"
      << "MASTER_BIND"
      << "MASTER_CONNECT_RETRY"
      << "MASTER_HEARTBEAT_PERIOD"
      << "MASTER_HOST"
      << "MASTER_LOG_FILE"
      << "MASTER_LOG_POS"
      << "MASTER_PASSWORD"
      << "MASTER_PORT"
      << "MASTER_SSL"
      << "MASTER_SSL_CA"
      << "MASTER_SSL_CAPATH"
      << "MASTER_SSL_CERT"
      << "MASTER_SSL_CIPHER"
      << "MASTER_SSL_KEY"
      << "MASTER_SSL_VERIFY_SERVER_CERT"
      << "MASTER_USER"
      << "MATCH"
      << "MAX_QUERIES_PER_HOUR"
      << "MAX_UPDATES_PER_HOUR"
      << "MAX_CONNECTIONS_PER_HOUR"
      << "MAX_USER_CONNECTIONS"
      << "MAXVALUE"
      << "MEDIUM"
      << "MERGE"
      << "MEMORY"
      << "MESSAGE_TEXT"
      << "MINUTE"
      << "MOD"
      << "MODE"
      << "MODIFIES"
      << "MODIFY"
      << "MRG_MYISAM"
      << "MUTEX"
      << "MYISAM"
      << "NAMES"
      << "NATURAL"
      << "NEW"
      << "NO_WRITE_TO_BINLOG"
      << "NO"
      << "NONE"
      << "NOT"
      << "NULL"
      << "OFFSET"
      << "OLD_FOREIGN_KEY_CHECKS"
      << "OLD_SQL_MODE"
      << "OLD_UNIQUE_CHECKS"
      << "OLD"
      << "ON"
      << "OPEN"
      << "OPTIMIZE"
      << "OPTION"
      << "OPTIONS"
      << "OPTIONALLY"
      << "OR"
      << "ORDER"
      << "OUT"
      << "OUTER"
      << "OUTFILE"
      << "PARTITION"
      << "PARTITIONING"
      << "PARTITIONS"
      << "PASSWORD"
      << "PERFORMANCE_SCHEMA"
      << "PERSISTENT"
      << "PLUGIN"
      << "PLUGINS"
      << "PORT"
      << "PRECISION"
      << "PREPARE"
      << "PRESERVE"
      << "PRIMARY"
      << "PRIVILEGES"
      << "PROCEDURE"
      << "PROCESS"
      << "PROCESSLIST"
      << "PROFILE"
      << "PROFILES"
      << "PROGRESS_REPORT_TIME"
      << "PROXY"
      << "PURGE"
      << "QUARTER"
      << "QUERY"
      << "QUICK"
      << "RANGE"
      << "READ_WRITE"
      << "READ"
      << "READS"
      << "REBUILD"
      << "REFERENCES"
      << "REGEXP"
      << "RELAYLOG"
      << "RELAY_LOG_FILE"
      << "RELAY_LOG_POS"
      << "RELEASE"
      << "RELOAD"
      << "REMOVE"
      << "RENAME"
      << "REORGANIZE"
      << "REPAIR"
      << "REPEAT"
      << "REPEATABLE"
      << "REPLACE"
      << "REPLICATION"
      << "REQUIRE"
      << "RESET"
      << "RESTRICT"
      << "RETURN"
      << "RETURNS"
      << "REVOKE"
      << "RIGHT"
      << "RLIKE"
      << "ROLE"
      << "ROLLBACK"
      << "ROLLUP"
      << "ROUTINE"
      << "ROW"
      << "ROWS"
      << "ROW_FORMAT"
      << "SCHEDULE"
      << "SCHEMA"
      << "SCHEMAS"
      << "SECOND"
      << "SECURITY"
      << "SELECT"
      << "SENSITIVE"
      << "SEPARATOR"
      << "SERIALIZABLE"
      << "SERVER"
      << "SESSION"
      << "SET"
      << "SHARE"
      << "SHOW"
      << "SHUTDOWN"
      << "SIGNAL"
      << "SLAVE"
      << "SLAVES"
      << "SNAPSHOT"
      << "SONAME"
      << "SOUNDS"
      << "SPATIAL"
      << "SPECIFIC"
      << "SQL_CACHE"
      << "SQL_BIG_RESULT"
      << "SQL_BUFFER_RESULT"
      << "SQL_CALC_FOUND_ROWS"
      << "SQL_MODE"
      << "SQL_NO_CACHE"
      << "SQL_SLAVE_SKIP_COUNTER"
      << "SQL_SMALL_RESULT"
      << "SQL_THREAD"
      << "SQL"
      << "SQLEXCEPTION"
      << "SQLSTATE"
      << "SQLWARNING"
      << "SSL"
      << "START"
      << "STARTING"
      << "STARTS"
      << "STATUS"
      << "STOP"
      << "STRAIGHT_JOIN"
      << "SUBPARTITION"
      << "SUM"
      << "SUPER"
      << "TABLE"
      << "TABLES"
      << "TABLE_STATISTICS"
      << "TABLESPACE"
      << "TEMPORARY"
      << "TERMINATED"
      << "THAN"
      << "THEN"
      << "TO"
      << "TRAILING"
      << "TRANSACTION"
      << "TRIGGER"
      << "TRIGGERS"
      << "TRUE"
      << "TRUNCATE"
      << "UNCOMMITTED"
      << "UNDEFINED"
      << "UNDO"
      << "UNINSTALL"
      << "UNION"
      << "UNIQUE_CHECKS"
      << "UNIQUE"
      << "UNLOCK"
      << "UNSIGNED"
      << "UNTIL"
      << "UPDATE"
      << "UPGRADE"
      << "USAGE"
      << "USE"
      << "USE_FRM"
      << "USER"
      << "USER_RESOURCES"
      << "USER_STATISTICS"
      << "USING"
      << "VALUES"
      << "VARIABLES"
      << "VARYING"
      << "VIEW"
      << "VIRTUAL"
      << "WARNINGS"
      << "WEEK"
      << "WHEN"
      << "WHERE"
      << "WHILE"
      << "WITH"
      << "WORK"
      << "WRAPPER"
      << "WRITE"
      << "XOR"
      << "ZEROFILL";
}

QStringList StaticFunctions::mariadbHelper()
{

  return QStringList()
      << "ALTER TABLE"
      << "ANALYZE [NO_WRITE_TO_BINLOG | LOCAL] TABLE tbl_name [, tbl_name]"
      << "CHANGE MASTER TO MASTER_BIND = 'interface_name', MASTER_HOST = 'host_name', MASTER_USER = 'user_name', MASTER_PASSWORD = 'password', MASTER_PORT = port_num, MASTER_CONNECT_RETRY = interval, MASTER_HEARTBEAT_PERIOD = interval, MASTER_LOG_FILE = 'master_log_name', MASTER_LOG_POS = master_log_pos, RELAY_LOG_FILE = 'relay_log_name', RELAY_LOG_POS = relay_log_pos, MASTER_SSL = {0|1}, MASTER_SSL_CA = 'ca_file_name', MASTER_SSL_CAPATH = 'ca_directory_name', MASTER_SSL_CERT = 'cert_file_name', MASTER_SSL_KEY = 'key_file_name', MASTER_SSL_CIPHER = 'cipher_list', MASTER_SSL_VERIFY_SERVER_CERT = {0|1}, IGNORE_SERVER_IDS = [server_id [, server_id] ... ]"
      << "CHECK TABLE tbl_name [, tbl_name] {FOR UPGRADE | QUICK | FAST | MEDIUM | EXTENDED | CHANGED}"
      << "CHECKSUM TABLE tbl_name [, tbl_name] [QUICK | EXTENDED]"
      << "CREATE DATABASE `DatabaseName` DEFAULT CHARACTER SET utf8 COLLATE utf8_spanish_ci;"
      << "COMMIT; SET AUTOCOMMIT:= 0; SET FOREIGN_KEY_CHECKS := 0; SET UNIQUE_CHECKS := 0;"
      << "DELETE FROM"
      << "DROP DATABASE IF EXISTS"
      << "DROP DATABASE"
      << "DROP FUNCTION IF EXISTS"
      << "DROP FUNCTION"
      << "DROP TABLE IF EXISTS"
      << "DROP TABLE"
      << "DROP USER"
      << "DROP VIEW IF EXISTS"
      << "DROP VIEW"
      << "EXPORT DATA FOR INSERT"
      << "HELP 'Topic'"
      << "FLUSH DES_KEY_FILE"
      << "FLUSH HOSTS"
      << "FLUSH LOGS"
      << "FLUSH MASTER"
      << "FLUSH PRIVILEGES"
      << "FLUSH QUERY CACHE"
      << "FLUSH SLAVE"
      << "FLUSH STATUS"
      << "FLUSH TABLES tbl_name [, tbl_name]"
      << "FLUSH TABLES WITH READ LOCK"
      << "FLUSH TABLES"
      << "FLUSH USER_RESOURCES"
      << "INSERT INTO"
      << "INSTALL PLUGIN Plugin_Name SONAME 'Plugin_Name.SO'"
      << "IS NULL"
      << "LIMIT 10"
      << "LIMIT 100"
      << "LIMIT 1000"
      << "LOAD DATA LOCAL INFILE 'localfile' INTO TABLE `` FIELDS TERMINATED BY '\t' ENCLOSED BY '' ESCAPED BY '\\';"
      << "LOAD DATA LOCAL INFILE 'localfile' INTO TABLE `` LINES TERMINATED BY '\n' STARTING BY '';"
      << "NOT NULL DEFAULT"
      << "NOT NULL"
      << "ON DUPLICATE KEY UPDATE"
      << "OPTIMIZE [NO_WRITE_TO_BINLOG | LOCAL] TABLE tbl_name [, tbl_name] REPAIR [NO_WRITE_TO_BINLOG | LOCAL] TABLE tbl_name [, tbl_name] [QUICK] [EXTENDED] [USE_FRM]"
      << "ORDER BY"
      << "PROCEDURE ANALYSE()"
      << "PURGE BINARY LOGS BEFORE NOW();"
      << "RESET SLAVE ['connection_name'] [ALL]"
      << "SELECT * FOR UPDATE"
      << "SELECT * FROM"
      << "SELECT * LOCK IN SHARE MODE"
      << "SELECT COUNT(*) FROM"
      << "SELECT SQL_CACHE"
      << "SELECT SQL_NO_CACHE"
      << "SET AUTOCOMMIT:= 0; SET FOREIGN_KEY_CHECKS := 0; SET UNIQUE_CHECKS := 0;"
      << "SET GLOBAL"
      << "SET PASSWORD FOR 'user'@'host' = PASSWORD('cleartext password');"
      << "SHOW ALL SLAVES STATUS"
      << "SHOW AUTHORS"
      << "SHOW BINARY LOGS"
      << "SHOW BINLOG EVENTS"
      << "SHOW CHARACTER SET"
      << "SHOW COLLATION"
      << "SHOW COLUMNS"
      << "SHOW CONTRIBUTORS"
      << "SHOW CREATE DATABASE"
      << "SHOW CREATE EVENT"
      << "SHOW CREATE FUNCTION"
      << "SHOW CREATE PROCEDURE"
      << "SHOW CREATE TABLE"
      << "SHOW CREATE TRIGGER"
      << "SHOW CREATE VIEW"
      << "SHOW DATABASES"
      << "SHOW ENGINE engineName STATUS"
      << "SHOW ENGINE INNODB STATUS"
      << "SHOW ENGINE INNODB MUTEX"
      << "SHOW ENGINE {NDB | NDBCLUSTER} STATUS"
      << "SHOW ENGINE PERFORMANCE_SCHEMA STATUS"
      << "SHOW ENGINE"
      << "SHOW ENGINES"
      << "SHOW ERRORS"
      << "SHOW EVENTS"
      << "SHOW FULL TABLES"
      << "SHOW FUNCTION CODE"
      << "SHOW FUNCTION STATUS"
      << "SHOW GRANTS"
      << "SHOW INDEX"
      << "SHOW INDEXES"
      << "SHOW MASTER STATUS"
      << "SHOW OPEN TABLES"
      << "SHOW PLUGINS"
      << "SHOW PRIVILEGES"
      << "SHOW PROCEDURE CODE"
      << "SHOW PROCEDURE STATUS"
      << "SHOW PROCESSLIST"
      << "SHOW PROFILE"
      << "SHOW PROFILES"
      << "SHOW RELAYLOG EVENTS"
      << "SHOW SLAVE HOSTS"
      << "SHOW SLAVE STATUS"
      << "SHOW STATUS"
      << "SHOW TABLE STATUS"
      << "SHOW TABLES"
      << "SHOW TRIGGERS"
      << "SHOW VARIABLES"
      << "SHOW WARNINGS"
      << "START ALL SLAVES;"
      << "START SLAVE IO_THREAD;"
      << "START SLAVE SQL_THREAD;"
      << "START SLAVE;"
      << "STOP ALL SLAVES;"
      << "STOP SLAVE IO_THREAD;"
      << "STOP SLAVE SQL_THREAD;"
      << "STOP SLAVE; SET GLOBAL SQL_SLAVE_SKIP_COUNTER = 1; START SLAVE;"
      << "STOP SLAVE;"
      << "TRIM COLUMNS IN"
      << "TRUNCATE TABLE"
      << "UNIQUE KEY";
}

QStringList StaticFunctions::mariadbFunctions()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(mariadbFunctionsComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}

QStringList StaticFunctions::mariadbDatatypes()
{
  return QStringList() << "BIGINT"
      << "BIT"
      << "BLOB"
      << "BOOL"
      << "BOOLEAN"
      << "CHAR"
      << "DATE"
      << "DATETIME"
      << "DEC"
      << "DECIMAL"
      << "DOUBLE"
      << "DOUBLEPRECISION"
      << "ENUM"
      << "FLOAT"
      << "FLOAT4"
      << "FLOAT8"
      << "FULLTEXT"
      << "INT"
      << "INT1"
      << "INT2"
      << "INT3"
      << "INT4"
      << "INT8"
      << "INTEGER"
      << "LONG"
      << "LONGBLOB"
      << "LONGTEXT"
      << "MEDIUMBLOB"
      << "MEDIUMINT"
      << "MEDIUMTEXT"
      << "MIDDLEINT"
      << "NUMERIC"
      << "REAL"
      << "SERIAL"
      << "SMALLINT"
      << "TEXT"
      << "TIME"
      << "TIMESTAMP"
      << "TINYBLOB"
      << "TINYINT"
      << "TINYTEXT"
      << "VARBINARY"
      << "VARCHAR"
      << "VARCHARACTER"
      << "YEAR";
}

QStringList StaticFunctions::mariadbCharsets()
{
  //Must be updated once in a while
  return QStringList() << "armscii8_bin"
                       << "armscii8_general_ci"
                       << "armscii8_general_nopad_ci"
                       << "armscii8_nopad_bin"
                       << "ascii_bin"
                       << "ascii_general_ci"
                       << "ascii_general_nopad_ci"
                       << "ascii_nopad_bin"
                       << "big5_bin"
                       << "big5_chinese_ci"
                       << "big5_chinese_nopad_ci"
                       << "big5_nopad_bin"
                       << "binary"
                       << "cp1250_bin"
                       << "cp1250_croatian_ci"
                       << "cp1250_czech_cs"
                       << "cp1250_general_ci"
                       << "cp1250_general_nopad_ci"
                       << "cp1250_nopad_bin"
                       << "cp1250_polish_ci"
                       << "cp1251_bin"
                       << "cp1251_bulgarian_ci"
                       << "cp1251_general_ci"
                       << "cp1251_general_cs"
                       << "cp1251_general_nopad_ci"
                       << "cp1251_nopad_bin"
                       << "cp1251_ukrainian_ci"
                       << "cp1256_bin"
                       << "cp1256_general_ci"
                       << "cp1256_general_nopad_ci"
                       << "cp1256_nopad_bin"
                       << "cp1257_bin"
                       << "cp1257_general_ci"
                       << "cp1257_general_nopad_ci"
                       << "cp1257_lithuanian_ci"
                       << "cp1257_nopad_bin"
                       << "cp850_bin"
                       << "cp850_general_ci"
                       << "cp850_general_nopad_ci"
                       << "cp850_nopad_bin"
                       << "cp852_bin"
                       << "cp852_general_ci"
                       << "cp852_general_nopad_ci"
                       << "cp852_nopad_bin"
                       << "cp866_bin"
                       << "cp866_general_ci"
                       << "cp866_general_nopad_ci"
                       << "cp866_nopad_bin"
                       << "cp932_bin"
                       << "cp932_japanese_ci"
                       << "cp932_japanese_nopad_ci"
                       << "cp932_nopad_bin"
                       << "dec8_bin"
                       << "dec8_nopad_bin"
                       << "dec8_swedish_ci"
                       << "dec8_swedish_nopad_ci"
                       << "eucjpms_bin"
                       << "eucjpms_japanese_ci"
                       << "eucjpms_japanese_nopad_ci"
                       << "eucjpms_nopad_bin"
                       << "euckr_bin"
                       << "euckr_korean_ci"
                       << "euckr_korean_nopad_ci"
                       << "euckr_nopad_bin"
                       << "gb2312_bin"
                       << "gb2312_chinese_ci"
                       << "gb2312_chinese_nopad_ci"
                       << "gb2312_nopad_bin"
                       << "gbk_bin"
                       << "gbk_chinese_ci"
                       << "gbk_chinese_nopad_ci"
                       << "gbk_nopad_bin"
                       << "geostd8_bin"
                       << "geostd8_general_ci"
                       << "geostd8_general_nopad_ci"
                       << "geostd8_nopad_bin"
                       << "greek_bin"
                       << "greek_general_ci"
                       << "greek_general_nopad_ci"
                       << "greek_nopad_bin"
                       << "hebrew_bin"
                       << "hebrew_general_ci"
                       << "hebrew_general_nopad_ci"
                       << "hebrew_nopad_bin"
                       << "hp8_bin"
                       << "hp8_english_ci"
                       << "hp8_english_nopad_ci"
                       << "hp8_nopad_bin"
                       << "keybcs2_bin"
                       << "keybcs2_general_ci"
                       << "keybcs2_general_nopad_ci"
                       << "keybcs2_nopad_bin"
                       << "koi8r_bin"
                       << "koi8r_general_ci"
                       << "koi8r_general_nopad_ci"
                       << "koi8r_nopad_bin"
                       << "koi8u_bin"
                       << "koi8u_general_ci"
                       << "koi8u_general_nopad_ci"
                       << "koi8u_nopad_bin"
                       << "latin1_bin"
                       << "latin1_danish_ci"
                       << "latin1_general_ci"
                       << "latin1_general_cs"
                       << "latin1_german1_ci"
                       << "latin1_german2_ci"
                       << "latin1_nopad_bin"
                       << "latin1_spanish_ci"
                       << "latin1_swedish_ci"
                       << "latin1_swedish_nopad_ci"
                       << "latin2_bin"
                       << "latin2_croatian_ci"
                       << "latin2_czech_cs"
                       << "latin2_general_ci"
                       << "latin2_general_nopad_ci"
                       << "latin2_hungarian_ci"
                       << "latin2_nopad_bin"
                       << "latin5_bin"
                       << "latin5_nopad_bin"
                       << "latin5_turkish_ci"
                       << "latin5_turkish_nopad_ci"
                       << "latin7_bin"
                       << "latin7_estonian_cs"
                       << "latin7_general_ci"
                       << "latin7_general_cs"
                       << "latin7_general_nopad_ci"
                       << "latin7_nopad_bin"
                       << "macce_bin"
                       << "macce_general_ci"
                       << "macce_general_nopad_ci"
                       << "macce_nopad_bin"
                       << "macroman_bin"
                       << "macroman_general_ci"
                       << "macroman_general_nopad_ci"
                       << "macroman_nopad_bin"
                       << "sjis_bin"
                       << "sjis_japanese_ci"
                       << "sjis_japanese_nopad_ci"
                       << "sjis_nopad_bin"
                       << "swe7_bin"
                       << "swe7_nopad_bin"
                       << "swe7_swedish_ci"
                       << "swe7_swedish_nopad_ci"
                       << "tis620_bin"
                       << "tis620_nopad_bin"
                       << "tis620_thai_ci"
                       << "tis620_thai_nopad_ci"
                       << "ucs2_bin"
                       << "ucs2_croatian_ci"
                       << "ucs2_croatian_mysql561_ci"
                       << "ucs2_czech_ci"
                       << "ucs2_danish_ci"
                       << "ucs2_esperanto_ci"
                       << "ucs2_estonian_ci"
                       << "ucs2_general_ci"
                       << "ucs2_general_mysql500_ci"
                       << "ucs2_general_nopad_ci"
                       << "ucs2_german2_ci"
                       << "ucs2_hungarian_ci"
                       << "ucs2_icelandic_ci"
                       << "ucs2_latvian_ci"
                       << "ucs2_lithuanian_ci"
                       << "ucs2_myanmar_ci"
                       << "ucs2_nopad_bin"
                       << "ucs2_persian_ci"
                       << "ucs2_polish_ci"
                       << "ucs2_romanian_ci"
                       << "ucs2_roman_ci"
                       << "ucs2_sinhala_ci"
                       << "ucs2_slovak_ci"
                       << "ucs2_slovenian_ci"
                       << "ucs2_spanish2_ci"
                       << "ucs2_spanish_ci"
                       << "ucs2_swedish_ci"
                       << "ucs2_thai_520_w2"
                       << "ucs2_turkish_ci"
                       << "ucs2_unicode_520_ci"
                       << "ucs2_unicode_520_nopad_ci"
                       << "ucs2_unicode_ci"
                       << "ucs2_unicode_nopad_ci"
                       << "ucs2_vietnamese_ci"
                       << "ujis_bin"
                       << "ujis_japanese_ci"
                       << "ujis_japanese_nopad_ci"
                       << "ujis_nopad_bin"
                       << "utf16le_bin"
                       << "utf16le_general_ci"
                       << "utf16le_general_nopad_ci"
                       << "utf16le_nopad_bin"
                       << "utf16_bin"
                       << "utf16_croatian_ci"
                       << "utf16_croatian_mysql561_ci"
                       << "utf16_czech_ci"
                       << "utf16_danish_ci"
                       << "utf16_esperanto_ci"
                       << "utf16_estonian_ci"
                       << "utf16_general_ci"
                       << "utf16_general_nopad_ci"
                       << "utf16_german2_ci"
                       << "utf16_hungarian_ci"
                       << "utf16_icelandic_ci"
                       << "utf16_latvian_ci"
                       << "utf16_lithuanian_ci"
                       << "utf16_myanmar_ci"
                       << "utf16_nopad_bin"
                       << "utf16_persian_ci"
                       << "utf16_polish_ci"
                       << "utf16_romanian_ci"
                       << "utf16_roman_ci"
                       << "utf16_sinhala_ci"
                       << "utf16_slovak_ci"
                       << "utf16_slovenian_ci"
                       << "utf16_spanish2_ci"
                       << "utf16_spanish_ci"
                       << "utf16_swedish_ci"
                       << "utf16_thai_520_w2"
                       << "utf16_turkish_ci"
                       << "utf16_unicode_520_ci"
                       << "utf16_unicode_520_nopad_ci"
                       << "utf16_unicode_ci"
                       << "utf16_unicode_nopad_ci"
                       << "utf16_vietnamese_ci"
                       << "utf32_bin"
                       << "utf32_croatian_ci"
                       << "utf32_croatian_mysql561_ci"
                       << "utf32_czech_ci"
                       << "utf32_danish_ci"
                       << "utf32_esperanto_ci"
                       << "utf32_estonian_ci"
                       << "utf32_general_ci"
                       << "utf32_general_nopad_ci"
                       << "utf32_german2_ci"
                       << "utf32_hungarian_ci"
                       << "utf32_icelandic_ci"
                       << "utf32_latvian_ci"
                       << "utf32_lithuanian_ci"
                       << "utf32_myanmar_ci"
                       << "utf32_nopad_bin"
                       << "utf32_persian_ci"
                       << "utf32_polish_ci"
                       << "utf32_romanian_ci"
                       << "utf32_roman_ci"
                       << "utf32_sinhala_ci"
                       << "utf32_slovak_ci"
                       << "utf32_slovenian_ci"
                       << "utf32_spanish2_ci"
                       << "utf32_spanish_ci"
                       << "utf32_swedish_ci"
                       << "utf32_thai_520_w2"
                       << "utf32_turkish_ci"
                       << "utf32_unicode_520_ci"
                       << "utf32_unicode_520_nopad_ci"
                       << "utf32_unicode_ci"
                       << "utf32_unicode_nopad_ci"
                       << "utf32_vietnamese_ci"
                       << "utf8mb4_bin"
                       << "utf8mb4_croatian_ci"
                       << "utf8mb4_croatian_mysql561_ci"
                       << "utf8mb4_czech_ci"
                       << "utf8mb4_danish_ci"
                       << "utf8mb4_esperanto_ci"
                       << "utf8mb4_estonian_ci"
                       << "utf8mb4_general_ci"
                       << "utf8mb4_general_nopad_ci"
                       << "utf8mb4_german2_ci"
                       << "utf8mb4_hungarian_ci"
                       << "utf8mb4_icelandic_ci"
                       << "utf8mb4_latvian_ci"
                       << "utf8mb4_lithuanian_ci"
                       << "utf8mb4_myanmar_ci"
                       << "utf8mb4_nopad_bin"
                       << "utf8mb4_persian_ci"
                       << "utf8mb4_polish_ci"
                       << "utf8mb4_romanian_ci"
                       << "utf8mb4_roman_ci"
                       << "utf8mb4_sinhala_ci"
                       << "utf8mb4_slovak_ci"
                       << "utf8mb4_slovenian_ci"
                       << "utf8mb4_spanish2_ci"
                       << "utf8mb4_spanish_ci"
                       << "utf8mb4_swedish_ci"
                       << "utf8mb4_thai_520_w2"
                       << "utf8mb4_turkish_ci"
                       << "utf8mb4_unicode_520_ci"
                       << "utf8mb4_unicode_520_nopad_ci"
                       << "utf8mb4_unicode_ci"
                       << "utf8mb4_unicode_nopad_ci"
                       << "utf8mb4_vietnamese_ci"
                       << "utf8_bin"
                       << "utf8_croatian_ci"
                       << "utf8_croatian_mysql561_ci"
                       << "utf8_czech_ci"
                       << "utf8_danish_ci"
                       << "utf8_esperanto_ci"
                       << "utf8_estonian_ci"
                       << "utf8_general_ci"
                       << "utf8_general_mysql500_ci"
                       << "utf8_general_nopad_ci"
                       << "utf8_german2_ci"
                       << "utf8_hungarian_ci"
                       << "utf8_icelandic_ci"
                       << "utf8_latvian_ci"
                       << "utf8_lithuanian_ci"
                       << "utf8_myanmar_ci"
                       << "utf8_nopad_bin"
                       << "utf8_persian_ci"
                       << "utf8_polish_ci"
                       << "utf8_romanian_ci"
                       << "utf8_roman_ci"
                       << "utf8_sinhala_ci"
                       << "utf8_slovak_ci"
                       << "utf8_slovenian_ci"
                       << "utf8_spanish2_ci"
                       << "utf8_spanish_ci"
                       << "utf8_swedish_ci"
                       << "utf8_thai_520_w2"
                       << "utf8_turkish_ci"
                       << "utf8_unicode_520_ci"
                       << "utf8_unicode_520_nopad_ci"
                       << "utf8_unicode_ci"
                       << "utf8_unicode_nopad_ci"
                       << "utf8_vietnamese_ci";
}

QStringList StaticFunctions::mariadbCodeErrorsNotCommaBothSides()
{
  return QStringList() << "AND"
                       << "FROM"
                          ;
}

QStringList StaticFunctions::mariadbCodeErrorsNotCommaOnLeft()
{
  return QStringList() << "SELECT"
                          ;
}

QString StaticFunctions::bytesConvertor(QString bytes)
{
  unsigned long long num = bytes.toULongLong();
  if (num <= 1024) {
    return QString("%1 B").arg(num);
  } else {
    num /= 1024;
    if (num <= 1024) {
      return QString("%1 KB").arg(num);
    } else {
      num /= 1024;
      if (num <= 1024) {
        return QString("%1 MB").arg(num);
      } else {
        num /= 1024;
        if (num <= 1024) {
          return QString("%1 GB").arg(num);
        } else {
          num /= 1024;
          if (num <= 1024) {
            return QString("%1 TB").arg(num);
          } else {
            num /= 1024;
            if (num <= 1024) {
              return QString("%1 PB").arg(num);
            } else {
              num /= 1024;
              if (num <= 1024)
                return QString("%1 EB").arg(num);
            }
          }
        }
      }
    }
  }
  return "Not known";
}

QString StaticFunctions::bytesConvertor(qulonglong bytes)
{
  return StaticFunctions::bytesConvertor(QString("%1").arg(bytes));
}

QStringList StaticFunctions::explodeConnectionString(QString connectionName)
{
  QSettings settings;
  QStringList params;
  int startIndex = 0;
  int endIndex = 0;
  QString connection(settings.value("ServerConnections/" + connectionName, "MariaDB:root@localhost:3306/mysql Count:0 Collation:utf8|utf8_general_ci Password:*99").toString());
  endIndex = connection.indexOf(":", startIndex);
  //0 - Connection name
  params.append(connection.mid(startIndex, endIndex));
  startIndex += ++endIndex;
  endIndex = connection.indexOf("@", startIndex) - startIndex;
  //1 - User
  params.append(connection.mid(startIndex, endIndex));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(":", startIndex) - startIndex;
  //2 - Host
  params.append(connection.mid(startIndex, endIndex));
  startIndex += ++endIndex;
  endIndex = connection.indexOf("/", startIndex) - startIndex;
  //3 - Port
  params.append(connection.mid(startIndex, endIndex));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //4 - Database
  params.append(connection.mid(startIndex, endIndex));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //5 - Conexion count
  params.append(connection.mid(startIndex, endIndex).split(":").at(1));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //6 - Collation
  params.append(connection.mid(startIndex, endIndex).split(":").at(1));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //7 - UseSSL
  params.append(connection.mid(startIndex, endIndex).split(":").at(1));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //8 - KeyFile
  params.append(connection.mid(startIndex, endIndex).split(":").at(1));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //9 - CertFile
  params.append(connection.mid(startIndex, endIndex).split(":").at(1));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;
  //10 - Password
  params.append(connection.mid(startIndex, endIndex).mid(9));
  startIndex += ++endIndex;
  endIndex = connection.indexOf(" ", startIndex) - startIndex;

  qApp->setProperty("ConnectionName", connectionName);
  return params;
}

QString StaticFunctions::randomString(unsigned int length)
{
  QString string;
  QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ;.,+¿*-/");
  QTime time = QTime::currentTime();
  qsrand((uint)time.msec());
  for(unsigned int counter = 0; counter < length; ++counter)
    string.append(possibleCharacters.at(qrand() % possibleCharacters.length()));
  return string;
}

QStringList StaticFunctions::currentEditorTypeKeywords(const EditorTypes::EditorType editorType)
{
  switch(editorType) {
  case EditorTypes::SQLQuery:
    return mariadbKeywords();
    break;
  case EditorTypes::Diff:
  case EditorTypes::Commit:
  case EditorTypes::SVNLog:
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
  return QStringList();
}

QLocale StaticFunctions::currentLocale()
{
  QStringList languageData = qApp->property("ApplicationLanguage").toString().split("/");
  QLocale::Language language(QLocale::English);
  if (languageData.at(0) == "es")
    language = QLocale::Spanish;
  QLocale::Country country(QLocale::UnitedStates);
  if (languageData.at(1) == "CR")
    country = QLocale::CostaRica;
  return QLocale(language, country);
}

QString StaticFunctions::serverInformationQuery()
{
  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return "SELECT '" + tr("Uptime in days") + "' AS `" + tr("Variable") + "`,  LPAD(FORMAT(`VARIABLE_VALUE` / 60 / 60 / 24, 2), 15, ' ') AS `" + tr("Value") + "`, '" + tr("Number of days the server has been running.") + "' AS `" + tr("Description") + "`, 'UPTIME' AS `" + tr("Variable mame") + "` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME'"
        " UNION"
        " SELECT '" + tr("Aborted clients") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of aborted client connections.") + "', 'ABORTED_CLIENTS' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CLIENTS'"
        " UNION"
        " SELECT '" + tr("Aborted clients per day") + "', LPAD(FORMAT("
        "  (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CLIENTS')"
        "   / (SELECT `VARIABLE_VALUE` / 60 /60 / 24 AS `Value` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME'), 2), 15, ' ')"
        " , '" + tr("Number of aborted client connections per day.") + "', '-'"
        " UNION"
        " SELECT '" + tr("Aborted connections") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of failed server connection attempts.") + "', 'ABORTED_CONNECTS' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CONNECTS'"
        " UNION"
        " SELECT '" + tr("Aborted connections per day") + "', LPAD(FORMAT("
        "  (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CONNECTS')"
        "   / (SELECT `VARIABLE_VALUE` / 60 /60 / 24 AS `Value` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME'), 2), 15, ' ')"
        " , '" + tr("Number of failed server connection attempts per day.") + "', '-'"
        " UNION"
        " SELECT '" + tr("Executed rollbacks") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of ROLLBACK commands executed.") + "', 'COM_ROLLBACK' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_ROLLBACK'"
        " UNION"
        " SELECT '" + tr("Rollbacks per second") + "', LPAD(FORMAT("
        "   ((SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_ROLLBACK')"
        "   / (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME')), 2), 15, ' ')"
        " , '" + tr("Number of ROLLBACK commands executed every second.") + "', '-'"
        " UNION"
        " SELECT '" + tr("Executed queries") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of statements executed by the server.") + "', 'QUERIES' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'QUERIES'"
        " UNION"
        " SELECT '" + tr("Temporary disk tables created") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of on-disk temporary tables created.") + "', 'CREATED_TMP_DISK_TABLES' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'CREATED_TMP_DISK_TABLES'"
        " UNION"
        " SELECT '" + tr("Free cache memory") + "', LPAD(FORMAT(`VARIABLE_VALUE` / 1024, 0), 15, ' '), '" + tr("Amount of free query cache memory.") + "', 'QCACHE_FREE_MEMORY' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'QCACHE_FREE_MEMORY'"
        " UNION"
        " SELECT '" + tr("Joins with full table scan") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of joins which did not use an index. If not zero, you may need to check table indexes.") + "', 'SELECT_FULL_JOIN' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'SELECT_FULL_JOIN'"
        " UNION"
        " SELECT '" + tr("Log slow queries") + "', LPAD(`VARIABLE_VALUE`, 15, ' '), '" + tr("Is the slow queries logging enabled?") + "', 'LOG_SLOW_QUERIES' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'SLOW_QUERY_LOG'"
        " UNION"
        " SELECT '" + tr("Slow queries time in seconds") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("The number of seconds that determinate a slow query.") + "', 'LONG_QUERY_TIME' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'LONG_QUERY_TIME'"
        " UNION"
        " SELECT '" + tr("Count of slow queries") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of queries which took longer than long_query_time to run.") + "', 'SLOW_QUERIES' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'SLOW_QUERIES'"
        " UNION"
        " SELECT '" + tr("Idle connections") + "', LPAD(COUNT(*), 15, ' '), '" + tr("The number of connections that has been idle for more than 30 seconds.") + "', '-' FROM `information_schema`.`PROCESSLIST` WHERE `TIME` >  30 AND `COMMAND` NOT IN ('Daemon', 'Binlog Dump')"
        " UNION"
        " SELECT '" + tr("Active connections") + "', LPAD(COUNT(*), 15, ' '), '" + tr("The number of connections that has been idle for less than 30 seconds.") + "', '-' FROM `information_schema`.`PROCESSLIST` WHERE `TIME` <  30 AND `COMMAND` NOT IN ('Daemon', 'Binlog Dump')"
        " UNION"
        " SELECT '" + tr("Total connections") + "', LPAD(COUNT(*), 15, ' '), '" + tr("The number of active connections on the server.") + "', '-' FROM `information_schema`.`PROCESSLIST` WHERE `COMMAND` NOT IN ('Daemon', 'Binlog Dump')"
        " UNION"
        " SELECT '" + tr("Max connections aviable") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("The maximum number of simultaneous client connections.") + "', 'MAX_CONNECTIONS' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'MAX_CONNECTIONS'"
        " UNION"
        " SELECT '" + tr("Used connections") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Max number of connections ever open at the same time.") + "', 'MAX_USED_CONNECTIONS' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'MAX_USED_CONNECTIONS'"
        " UNION"
        " SELECT '" + tr("DELETE commands executed") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of DELETE commands executed.") + "', 'COM_DELETE' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_DELETE'"
        " UNION"
        " SELECT '" + tr("INSERT commands executed") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of INSERT commands executed.") + "', 'COM_INSERT' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_INSERT'"
        " UNION"
        " SELECT '" + tr("UPDATE commands executed") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of UPDATE commands executed.") + "', 'COM_UPDATE' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_UPDATE'"
        " UNION"
        " SELECT '" + tr("SELECT commands executed") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of SELECT commands executed.") + "', 'COM_SELECT' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_SELECT'"
        " UNION"
        " SELECT '" + tr("Requests of the first index row") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of requests to read the first row from an index. A high value indicates many full index scans.") + "', 'HANDLER_READ_FIRST' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'HANDLER_READ_FIRST'"
        " UNION"
        " SELECT '" + tr("Rate of SELECTs per full index scans") + "', LPAD(FORMAT((SELECT `VARIABLE_VALUE` * 100 FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'HANDLER_READ_FIRST') / (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_SELECT'), 0), 15, ' '), '" + tr("Rate of SELECTs per full index scans. A value higher than 100 means you do more table scan than SELECTs.") + "', '-'"
        " UNION"
        " SELECT '" + tr("Read requests based on an index value") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Number of row read requests based on an index value. A high value indicates indexes are regularly being used.") + "', 'HANDLER_READ_KEY' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'HANDLER_READ_KEY'"
        " UNION"
        " SELECT '" + tr("Wait timeout") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 15, ' '), '" + tr("Time in seconds that the server waits for a connection to become active before closing it.") + "', 'WAIT_TIMEOUT' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'WAIT_TIMEOUT'"
        ;
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QString();
}

QString StaticFunctions::slowQueriesQuery()
{
  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return "SELECT DATE(`start_time`) AS `" + tr("Date") + "`, DAYNAME(`start_time`) AS `" + tr("Day") + "`, LPAD(FORMAT(COUNT(*), 0), 13, ' ') AS `" + tr("Total queries") + "`"
        ", LPAD(FORMAT(AVG(`query_time`), 2), 20,  ' ') AS `" + tr("Average (in seconds)") + "` FROM `mysql`.`slow_log` WHERE `start_time` >= (SELECT FROM_UNIXTIME("
        " (SELECT UNIX_TIMESTAMP(CURRENT_TIMESTAMP()))"
        " - (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME')))"
        " GROUP BY DATE(`start_time`)";
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QString();
}
