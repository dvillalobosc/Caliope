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
  case StaticFunctions::PostgreSQL:
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
  case StaticFunctions::PostgreSQL:
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
  case StaticFunctions::PostgreSQL:
    return "postgres";
    break;
  case StaticFunctions::Undefined:
  default:
    return "information_schema";
    break;
  }
}

QStringList StaticFunctions::postgresqlDatatypes()
{
  return QStringList() << "VARCHAR";

}

QStringList StaticFunctions::postgresqlCharsets()
{
  return QStringList()  << "BIG5"
                        << "EUC_CN"
                        << "EUC_JP"
                        << "EUC_KR"
                        << "EUC_TW"
                        << "GB18030"
                        << "GBK"
                        << "ISO_8859_5"
                        << "ISO_8859_6"
                        << "ISO_8859_7"
                        << "ISO_8859_8"
                        << "JOHAB"
                        << "KOI8"
                        << "LATIN1"
                        << "LATIN2"
                        << "LATIN3"
                        << "LATIN4"
                        << "LATIN5"
                        << "LATIN6"
                        << "LATIN7"
                        << "LATIN8"
                        << "LATIN9"
                        << "LATIN10"
                        << "MULE_INTERNAL"
                        << "SJIS"
                        << "SQL_ASCII"
                        << "UHC"
                        << "UTF8"
                        << "WIN866"
                        << "WIN874"
                        << "WIN1250"
                        << "WIN1251"
                        << "WIN1252"
                        << "WIN1256"
                        << "WIN1258";
}

QHash<QString, QString> StaticFunctions::postgresqlFunctionsComplete()
{
  QHash<QString, QString> data;
  //Mathematical Functions and Operators
  data.insert("abs", QString("<u>ABS</u>(<b>numeric</b>) <br />%1").arg(tr("Absolute value of numeric.")));
  data.insert("cbrt", QString("<u>CBRT</u>(<b>numeric</b>) <br />%1").arg(tr("Cube root of numeric.")));
  data.insert("ceil", QString("<u>CEIL</u>(<b>numeric</b>) <br />%1").arg(tr("Smallest integer not less than numeric.")));
  data.insert("ceiling", QString("<u>CEILING</u>(<b>numeric</b>) <br />%1").arg(tr("Smallest integer not less than numeric.")));
  data.insert("degree", QString("<u>DEGREES</u>(<b>numeric</b>) <br />%1").arg(tr("Radians to degrees.")));
  data.insert("div", QString("<u>DIV</u>(<b>y, x </b>) <br />%1").arg(tr("Integer quotient of y/x.")));
  data.insert("exp", QString("<u>EXP</u>(<b>numeric</b>) <br />%1").arg(tr("Exponential.")));
  data.insert("floor", QString("<u>FLOOR</u>(<b>numeric</b>) <br />%1").arg(tr("Largest integer not greater than numeric.")));
  data.insert("ln", QString("<u>LN</u>(<b>numeric</b>) <br />%1").arg(tr("Natural logarithm.")));
  data.insert("log", QString("<u>LOG</u>(<b>[numeric|b numeric, x numeric]</b>) <br />%1").arg(tr("Base 10 logarithm.<br/ >Logarithm to base b.")));
  data.insert("mod", QString("<u>MOD</u>(<b>y, x</b>) <br />%1").arg(tr("Remainder of y/x.")));
  data.insert("pi", QString("<u>PI</u>(<b></b>) <br />%1").arg(tr("PI constant.")));
  data.insert("power", QString("<u>POWER</u>(<b>a numeric, b numeric</b>) <br />%1").arg(tr("a raised to the power of b.")));
  data.insert("radians", QString("<u>RADIANS</u>(<b>numeric</b>) <br />%1").arg(tr("Degrees to radians.")));
  data.insert("random", QString("<u>RANDOM</u>(<b></b>) <br />%1").arg(tr("Random value in the range 0.0 <= x < 1.0.")));
  data.insert("round", QString("<u>ROUND</u>(<b>[dp or numeric|v numeric, s numeric]</b>) <br />%1").arg(tr("Round to nearest integer.<br />Round to s decimal places.")));
  data.insert("setseed", QString("<u>SETSEED</u>(<b>numeric</b>) <br />%1").arg(tr("Set seed for subsequent random() calls (value between -1.0 and 1.0, inclusive).")));
  data.insert("sign", QString("<u>SIGN</u>(<b>numeric</b>) <br />%1").arg(tr("Sign of the argument (-1, 0, +1).")));
  data.insert("sqrt", QString("<u>SQRT</u>(<b>numeric</b>) <br />%1").arg(tr("Square root.")));
  data.insert("trunc", QString("<u>TRUNC</u>(<b>[numeric|v numeric, s numeric]</b>) <br />%1").arg(tr("Truncate toward zero.<br />Truncate to s decimal places.")));
  data.insert("width_bucket", QString("<u>WIDTH_BUCKET</u>(<b>op numeric, b1 numeric, b2 numeric, count numeric</b>) <br />%1").arg(tr("Return the bucket to which operand would be assigned in an equidepth histogram with count buckets, in the range b1 to b2.")));

  //String Functions and Operators
  data.insert("ascii", QString("<u>ascii</u>(<b>string</b>) <br />%1").arg(tr("ASCII code of the first character of the argument.")));
  data.insert("btrim", QString("<u>btrim</u>(<b>string [, string]</b>) <br />%1").arg(tr("Remove the longest string consisting only of characters in characters (a space by default) from the start and end of string.")));
  data.insert("chr", QString("<u>chr</u>(<b>numeric</b>) <br />%1").arg(tr("Character with the given code. bytes.")));
  data.insert("concat", QString("<u>concat</u>(<b>string [, string[, ...]]</b>) <br />%1").arg(tr("Concatenate all arguments. NULL arguments are ignored.")));
  data.insert("concat_ws", QString("<u>concat_ws</u>(<b>string, string [, string[, ...]]</b>) <br />%1").arg(tr("Concatenate all but first arguments with separators. The first parameter is used as a separator. NULL arguments are ignored.")));
  data.insert("convert", QString("<u>convert</u>(<b>string, string src_encoding, string dest_encoding</b>) <br />%1").arg(tr("Convert string to dest_encoding. conversions.")));
  data.insert("convert_from", QString("<u>convert_from</u>(<b>string, string src_encoding</b>) <br />%1").arg(tr("Convert string to the database encoding. The original encoding is specified bysrc_encoding. The string must be valid in this encoding.")));
  data.insert("convert_to", QString("<u>convert_to</u>(<b>string, string dest_encoding</b>) <br />%1").arg(tr("Convert string to dest_encoding.")));
  data.insert("decode", QString("<u>decode</u>(<b>string text, string format</b>) <br />%1").arg(tr("Decode binary data from textual representation in string.")));
  data.insert("encode", QString("<u>encode</u>(<b>string text, string format</b>) <br />%1").arg(tr("Encode binary data into a textual representation.")));
  data.insert("format", QString("<u>format</u>(<b>string [, string[, ...]]</b>) <br />%1").arg(tr("Format a string.")));
  data.insert("initcap", QString("<u>initcap</u>(<b>string</b>) <br />%1").arg(tr("Convert the first letter of each word to upper case and the rest to lower case.")));
  data.insert("left", QString("<u>left</u>(<b>string text, n numeric</b>) <br />%1").arg(tr("Return first n characters in the string. When nis negative, return all but last |n| characters.")));
  data.insert("length", QString("<u>length</u>(<b>string</b>) <br />%1").arg(tr("Number of characters in string.")));
  data.insert("lpad", QString("<u>lpad</u>(<b>string text, numeric length[, string fill]</b>) <br />%1").arg(tr("Fill up the string to length length by prepending the characters fill (a space by default). If the string is already longer thanlength then it is truncated (on the right).")));
  data.insert("ltrim", QString("<u>ltrim</u>(<b>string text [, string characters]</b>) <br />%1").arg(tr("Remove the longest string containing only characters from characters (a space by default) from the start of string.")));
  data.insert("md5", QString("<u>md5</u>(<b>string</b>) <br />%1").arg(tr("Calculates the MD5 hash of string, returning the result in hexadecimal.")));
  data.insert("pg_client_encoding", QString("<u>pg_client_encoding</u>(<b></b>) <br />%1").arg(tr("Current client encoding name.")));
  data.insert("quote_ident", QString("<u>quote_ident</u>(<b>string</b>) <br />%1").arg(tr("Return the given string suitably quoted to be used as an identifier in an SQL statement string.")));
  data.insert("quote_literal", QString("<u>quote_literal</u>(<b>string</b>) <br />%1").arg(tr("Return the given string suitably quoted to be used as a string literal in an SQL statement string.")));
  data.insert("quote_nullable", QString("<u>quote_nullable</u>(<b>value</b>) <br />%1").arg(tr("Return the given string suitably quoted to be used as a string literal in an SQL statement string; or, if the argument is null, return NULL.")));
  data.insert("regexp_matches", QString("<u>regexp_matches</u>(<b>string text, string pattern [, string flags]</b>) <br />%1").arg(tr("Return all captured substrings resulting from matching a POSIX regular expression against the string.")));
  data.insert("regexp_replace", QString("<u>regexp_replace</u>(<b>string text, string pattern, string replacement[, string flags]</b>) <br />%1").arg(tr("Replace substring(s) matching a POSIX regular expression.")));
  data.insert("regexp_split_to_array", QString("<u>regexp_split_to_array</u>(<b>string text, string pattern [, string flags]</b>) <br />%1").arg(tr("Split string using a POSIX regular expression as the delimiter.")));
  data.insert("regexp_split_to_table", QString("<u>regexp_split_to_table</u>(<b>string text, string pattern [, string flags]</b>) <br />%1").arg(tr("Split string using a POSIX regular expression as the delimiter.")));
  data.insert("repeat", QString("<u>repeat</u>(<b>string text, numeric number</b>) <br />%1").arg(tr("Repeat string the specified number of times.")));
  data.insert("replace", QString("<u>replace</u>(<b>string text, string from, string to</b>) <br />%1").arg(tr("Replace all occurrences in string of substring from with substring to.")));
  data.insert("reverse", QString("<u>reverse</u>(<b>string</b>) <br />%1").arg(tr("Return reversed string.")));
  data.insert("right", QString("<u>right</u>(<b>string text, n numeric</b>) <br />%1").arg(tr("Return last n characters in the string. When nis negative, return all but first |n| characters.")));
  data.insert("rpad", QString("<u>rpad</u>(<b>string text, numeric length[, string fill]</b>) <br />%1").arg(tr("Fill up the string to length length by appending the characters fill (a space by default).")));
  data.insert("rtrim", QString("<u>rtrim</u>(<b>string text [, string characters]</b>) <br />%1").arg(tr("Remove the longest string containing only characters from characters (a space by default) from the end of string.")));
  data.insert("split_part", QString("<u>split_part</u>(<b>string text, string delimiter, field numeric</b>) <br />%1").arg(tr("Split string on delimiter and return the given field (counting from one).")));
  data.insert("strpos", QString("<u>strpos</u>(<b>string, substring</b>) <br />%1").arg(tr("Location of specified substring (same as position(substring in string), but note the reversed argument order).")));
  data.insert("substr", QString("<u>substr</u>(<b>string, from [,count]</b>) <br />%1").arg(tr("Extract substring (same as substring(string from from forcount)).")));
  data.insert("to_ascii", QString("<u>to_ascii</u>(<b>string text [, string encoding]</b>) <br />%1").arg(tr("Convert string to ASCII from another encoding.")));
  data.insert("to_hex", QString("<u>to_hex</u>(<b>numeric</b>) <br />%1").arg(tr("Convert number to its equivalent hexadecimal representation.")));
  data.insert("translate", QString("<u>translate</u>(<b>string text, string from, string to</b>) <br />%1").arg(tr("Any character in string that matches a character in the from set is replaced by the corresponding character in the to set.")));
  data.insert("bit_length", QString("<u>bit_length</u>(<b>string</b>) <br />%1").arg(tr("Number of bits in string.")));
  data.insert("char_length", QString("<u>char_length</u>(<b>string</b>) <br />%1").arg(tr("Number of characters in string.")));
  data.insert("lower", QString("<u>lower</u>(<b>string</b>) <br />%1").arg(tr("Convert string to lower case.")));
  data.insert("octet_length", QString("<u>octet_length</u>(<b>string</b>) <br />%1").arg(tr("Number of bytes in string.")));
  data.insert("overlay", QString("<u>overlay</u>(<b>string placing string from numeric [for numeric]</b>) <br />%1").arg(tr("Replace substring.")));
  data.insert("position", QString("<u>position</u>(<b>string</b>) <br />%1").arg(tr("Location of specified substring.")));
  data.insert("substring", QString("<u>substring</u>(<b>string [from numeric] [for numeric]</b>) <br />%1").arg(tr("Extract substring.")));
  data.insert("trim", QString("<u>trim</u>(<b>[leading | trailing | both] [characters] from string</b>) <br />%1").arg(tr("Remove the longest string containing only the characters (a space by default) from the start/end/both ends of the string.")));
  data.insert("upper", QString("<u>upper</u>(<b>string</b>) <br />%1").arg(tr("Convert string to upper case.")));
  return data;
}

QStringList StaticFunctions::postgresqlFunctions()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(postgresqlFunctionsComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}

QStringList StaticFunctions::postgresqlKeywords()
{
  return QStringList() << "A"
                       << "ABORT"
                       << "ABSOLUTE"
                       << "ACCESS"
                       << "ACTION"
                       << "ADA"
                       << "ADD"
                       << "ADMIN"
                       << "AFTER"
                       << "AGGREGATE"
                       << "ALIAS"
                       << "ALL"
                       << "ALLOCATE"
                       << "ALSO"
                       << "ALTER"
                       << "ALWAYS"
                       << "ANALYSE"
                       << "ANALYZE"
                       << "AND"
                       << "ANY"
                       << "ARE"
                       << "ARRAY"
                       << "AS"
                       << "ASC"
                       << "ASENSITIVE"
                       << "ASSERTION"
                       << "ASSIGNMENT"
                       << "ASYMMETRIC"
                       << "AT"
                       << "ATOMIC"
                       << "ATTRIBUTE"
                       << "ATTRIBUTES"
                       << "AUTHORIZATION"
                       << "AVG"
                       << "BACKWARD"
                       << "BEFORE"
                       << "BEGIN"
                       << "BERNOULLI"
                       << "BETWEEN"
                       << "BIGINT"
                       << "BINARY"
                       << "BIT"
                       << "BITVAR"
                       << "BIT_LENGTH"
                       << "BLOB"
                       << "BOOLEAN"
                       << "BOTH"
                       << "BREADTH"
                       << "BY"
                       << "C"
                       << "CACHE"
                       << "CALL"
                       << "CALLED"
                       << "CARDINALITY"
                       << "CASCADE"
                       << "CASCADED"
                       << "CASE"
                       << "CAST"
                       << "CATALOG"
                       << "CATALOG_NAME"
                       << "CHAIN"
                       << "CHAR"
                       << "CHARACTER"
                       << "CHARACTERISTICS"
                       << "CHARACTERS"
                       << "CHARACTER_LENGTH"
                       << "CHARACTER_SET_CATALOG"
                       << "CHARACTER_SET_NAME"
                       << "CHARACTER_SET_SCHEMA"
                       << "CHAR_LENGTH"
                       << "CHECK"
                       << "CHECKED"
                       << "CHECKPOINT"
                       << "CLASS"
                       << "CLASS_ORIGIN"
                       << "CLOB"
                       << "CLOSE"
                       << "CLUSTER"
                       << "COALESCE"
                       << "COBOL"
                       << "COLLATE"
                       << "COLLATION"
                       << "COLLATION_CATALOG"
                       << "COLLATION_NAME"
                       << "COLLATION_SCHEMA"
                       << "COLLECT"
                       << "COLUMN"
                       << "COLUMN_NAME"
                       << "COMMAND_FUNCTION"
                       << "COMMAND_FUNCTION_CODE"
                       << "COMMENT"
                       << "COMMIT"
                       << "COMMITTED"
                       << "COMPLETION"
                       << "CONDITION"
                       << "CONDITION_NUMBER"
                       << "CONNECT"
                       << "CONNECTION"
                       << "CONNECTION_NAME"
                       << "CONSTRAINT"
                       << "CONSTRAINTS"
                       << "CONSTRAINT_CATALOG"
                       << "CONSTRAINT_NAME"
                       << "CONSTRAINT_SCHEMA"
                       << "CONSTRUCTOR"
                       << "CONTAINS"
                       << "CONTINUE"
                       << "CONVERSION"
                       << "CONVERT"
                       << "COPY"
                       << "CORR"
                       << "CORRESPONDING"
                       << "COUNT"
                       << "COVAR_POP"
                       << "COVAR_SAMP"
                       << "CREATE"
                       << "CREATEDB"
                       << "CREATEROLE"
                       << "CREATEUSER"
                       << "CROSS"
                       << "CSV"
                       << "CUBE"
                       << "CUME_DIST"
                       << "CURRENT"
                       << "CURRENT_DATE"
                       << "CURRENT_DEFAULT_TRANSFORM_GROUP"
                       << "CURRENT_PATH"
                       << "CURRENT_ROLE"
                       << "CURRENT_TIME"
                       << "CURRENT_TIMESTAMP"
                       << "CURRENT_TRANSFORM_GROUP_FOR_TYPE"
                       << "CURRENT_USER"
                       << "CURSOR"
                       << "CURSOR_NAME"
                       << "CYCLE"
                       << "DATA"
                       << "DATABASE"
                       << "DATE"
                       << "DATETIME_INTERVAL_CODE"
                       << "DATETIME_INTERVAL_PRECISION"
                       << "DAY"
                       << "DEALLOCATE"
                       << "DEC"
                       << "DECIMAL"
                       << "DECLARE"
                       << "DEFAULT"
                       << "DEFAULTS"
                       << "DEFERRABLE"
                       << "DEFERRED"
                       << "DEFINED"
                       << "DEFINER"
                       << "DEGREE"
                       << "DELETE"
                       << "DELIMITER"
                       << "DELIMITERS"
                       << "DENSE_RANK"
                       << "DEPTH"
                       << "DEREF"
                       << "DERIVED"
                       << "DESC"
                       << "DESCRIBE"
                       << "DESCRIPTOR"
                       << "DESTROY"
                       << "DESTRUCTOR"
                       << "DETERMINISTIC"
                       << "DIAGNOSTICS"
                       << "DICTIONARY"
                       << "DISABLE"
                       << "DISCONNECT"
                       << "DISPATCH"
                       << "DISTINCT"
                       << "DO"
                       << "DOMAIN"
                       << "DOUBLE"
                       << "DROP"
                       << "DYNAMIC"
                       << "DYNAMIC_FUNCTION"
                       << "DYNAMIC_FUNCTION_CODE"
                       << "EACH"
                       << "ELEMENT"
                       << "ELSE"
                       << "ENABLE"
                       << "ENCODING"
                       << "ENCRYPTED"
                       << "END"
                       << "END-EXEC"
                       << "EQUALS"
                       << "ESCAPE"
                       << "EVERY"
                       << "EXCEPT"
                       << "EXCEPTION"
                       << "EXCLUDE"
                       << "EXCLUDING"
                       << "EXCLUSIVE"
                       << "EXEC"
                       << "EXECUTE"
                       << "EXISTING"
                       << "EXISTS"
                       << "EXPLAIN"
                       << "EXTERNAL"
                       << "EXTRACT"
                       << "FALSE"
                       << "FETCH"
                       << "FILTER"
                       << "FINAL"
                       << "FIRST"
                       << "FLOAT"
                       << "FOLLOWING"
                       << "FOR"
                       << "FORCE"
                       << "FOREIGN"
                       << "FORTRAN"
                       << "FORWARD"
                       << "FOUND"
                       << "FREE"
                       << "FREEZE"
                       << "FROM"
                       << "FULL"
                       << "FUNCTION"
                       << "FUSION"
                       << "G"
                       << "GENERAL"
                       << "GENERATED"
                       << "GET"
                       << "GLOBAL"
                       << "GO"
                       << "GOTO"
                       << "GRANT"
                       << "GRANTED"
                       << "GREATEST"
                       << "GROUP"
                       << "GROUPING"
                       << "HANDLER"
                       << "HAVING"
                       << "HEADER"
                       << "HIERARCHY"
                       << "HOLD"
                       << "HOST"
                       << "HOUR"
                       << "IDENTITY"
                       << "IGNORE"
                       << "ILIKE"
                       << "IMMEDIATE"
                       << "IMMUTABLE"
                       << "IMPLEMENTATION"
                       << "IMPLICIT"
                       << "IN"
                       << "INCLUDING"
                       << "INCREMENT"
                       << "INDEX"
                       << "INDICATOR"
                       << "INFIX"
                       << "INHERIT"
                       << "INHERITS"
                       << "INITIALIZE"
                       << "INITIALLY"
                       << "INNER"
                       << "INOUT"
                       << "INPUT"
                       << "INSENSITIVE"
                       << "INSERT"
                       << "INSTANCE"
                       << "INSTANTIABLE"
                       << "INSTEAD"
                       << "INT"
                       << "INTEGER"
                       << "INTERSECT"
                       << "INTERSECTION"
                       << "INTERVAL"
                       << "INTO"
                       << "INVOKER"
                       << "IS"
                       << "ISNULL"
                       << "ISOLATION"
                       << "ITERATE"
                       << "JOIN"
                       << "K"
                       << "KEY"
                       << "KEY_MEMBER"
                       << "KEY_TYPE"
                       << "LANCOMPILER"
                       << "LANGUAGE"
                       << "LARGE"
                       << "LAST"
                       << "LATERAL"
                       << "LEADING"
                       << "LEAST"
                       << "LEFT"
                       << "LENGTH"
                       << "LESS"
                       << "LEVEL"
                       << "LIKE"
                       << "LIMIT"
                       << "LISTEN"
                       << "LOAD"
                       << "LOCAL"
                       << "LOCALTIME"
                       << "LOCALTIMESTAMP"
                       << "LOCATION"
                       << "LOCATOR"
                       << "LOCK"
                       << "LOGIN"
                       << "LOWER"
                       << "M"
                       << "MAP"
                       << "MATCH"
                       << "MATCHED"
                       << "MAX"
                       << "MAXVALUE"
                       << "MEMBER"
                       << "MERGE"
                       << "MESSAGE_LENGTH"
                       << "MESSAGE_OCTET_LENGTH"
                       << "MESSAGE_TEXT"
                       << "METHOD"
                       << "MIN"
                       << "MINUTE"
                       << "MINVALUE"
                       << "MODE"
                       << "MODIFIES"
                       << "MODIFY"
                       << "MODULE"
                       << "MONTH"
                       << "MORE"
                       << "MOVE"
                       << "MULTISET"
                       << "MUMPS"
                       << "NAME"
                       << "NAMES"
                       << "NATIONAL"
                       << "NATURAL"
                       << "NCHAR"
                       << "NCLOB"
                       << "NESTING"
                       << "NEW"
                       << "NEXT"
                       << "NO"
                       << "NOCREATEDB"
                       << "NOCREATEROLE"
                       << "NOCREATEUSER"
                       << "NOINHERIT"
                       << "NOLOGIN"
                       << "NONE"
                       << "NORMALIZE"
                       << "NORMALIZED"
                       << "NOSUPERUSER"
                       << "NOT"
                       << "NOTHING"
                       << "NOTIFY"
                       << "NOTNULL"
                       << "NOWAIT"
                       << "NULL"
                       << "NULLABLE"
                       << "NULLIF"
                       << "NULLS"
                       << "NUMBER"
                       << "NUMERIC"
                       << "OBJECT"
                       << "OCTETS"
                       << "OCTET_LENGTH"
                       << "OF"
                       << "OFF"
                       << "OFFSET"
                       << "OIDS"
                       << "OLD"
                       << "ON"
                       << "ONLY"
                       << "OPEN"
                       << "OPERATION"
                       << "OPERATOR"
                       << "OPTION"
                       << "OPTIONS"
                       << "OR"
                       << "ORDER"
                       << "ORDERING"
                       << "ORDINALITY"
                       << "OTHERS"
                       << "OUT"
                       << "OUTER"
                       << "OUTPUT"
                       << "OVER"
                       << "OVERLAPS"
                       << "OVERLAY"
                       << "OVERRIDING"
                       << "OWNER"
                       << "PAD"
                       << "PARAMETER"
                       << "PARAMETERS"
                       << "PARAMETER_MODE"
                       << "PARAMETER_NAME"
                       << "PARAMETER_ORDINAL_POSITION"
                       << "PARAMETER_SPECIFIC_CATALOG"
                       << "PARAMETER_SPECIFIC_NAME"
                       << "PARAMETER_SPECIFIC_SCHEMA"
                       << "PARTIAL"
                       << "PARTITION"
                       << "PASCAL"
                       << "PASSWORD"
                       << "PATH"
                       << "PERCENTILE_CONT"
                       << "PERCENTILE_DISC"
                       << "PERCENT_RANK"
                       << "PLACING"
                       << "PLI"
                       << "POSITION"
                       << "POSTFIX"
                       << "PRECEDING"
                       << "PRECISION"
                       << "PREFIX"
                       << "PREORDER"
                       << "PREPARE"
                       << "PREPARED"
                       << "PRESERVE"
                       << "PRIMARY"
                       << "PRIOR"
                       << "PRIVILEGES"
                       << "PROCEDURAL"
                       << "PROCEDURE"
                       << "PUBLIC"
                       << "QUOTE"
                       << "RANGE"
                       << "RANK"
                       << "READ"
                       << "READS"
                       << "REAL"
                       << "RECHECK"
                       << "RECURSIVE"
                       << "REF"
                       << "REFERENCES"
                       << "REFERENCING"
                       << "REGR_AVGX"
                       << "REGR_AVGY"
                       << "REGR_COUNT"
                       << "REGR_INTERCEPT"
                       << "REGR_R2"
                       << "REGR_SLOPE"
                       << "REGR_SXX"
                       << "REGR_SXY"
                       << "REGR_SYY"
                       << "REINDEX"
                       << "RELATIVE"
                       << "RELEASE"
                       << "RENAME"
                       << "REPEATABLE"
                       << "REPLACE"
                       << "RESET"
                       << "RESTART"
                       << "RESTRICT"
                       << "RESULT"
                       << "RETURN"
                       << "RETURNED_CARDINALITY"
                       << "RETURNED_LENGTH"
                       << "RETURNED_OCTET_LENGTH"
                       << "RETURNED_SQLSTATE"
                       << "RETURNS"
                       << "REVOKE"
                       << "RIGHT"
                       << "ROLE"
                       << "ROLLBACK"
                       << "ROLLUP"
                       << "ROUTINE"
                       << "ROUTINE_CATALOG"
                       << "ROUTINE_NAME"
                       << "ROUTINE_SCHEMA"
                       << "ROW"
                       << "ROWS"
                       << "ROW_COUNT"
                       << "ROW_NUMBER"
                       << "RULE"
                       << "SAVEPOINT"
                       << "SCALE"
                       << "SCHEMA"
                       << "SCHEMA_NAME"
                       << "SCOPE"
                       << "SCOPE_CATALOG"
                       << "SCOPE_NAME"
                       << "SCOPE_SCHEMA"
                       << "SCROLL"
                       << "SEARCH"
                       << "SECOND"
                       << "SECTION"
                       << "SECURITY"
                       << "SELECT"
                       << "SELF"
                       << "SENSITIVE"
                       << "SEQUENCE"
                       << "SERIALIZABLE"
                       << "SERVER_NAME"
                       << "SESSION"
                       << "SESSION_USER"
                       << "SET"
                       << "SETOF"
                       << "SETS"
                       << "SHARE"
                       << "SHOW"
                       << "SIMILAR"
                       << "SIMPLE"
                       << "SIZE"
                       << "SMALLINT"
                       << "SOME"
                       << "SOURCE"
                       << "SPACE"
                       << "SPECIFIC"
                       << "SPECIFICTYPE"
                       << "SPECIFIC_NAME"
                       << "SQL"
                       << "SQLCODE"
                       << "SQLERROR"
                       << "SQLEXCEPTION"
                       << "SQLSTATE"
                       << "SQLWARNING"
                       << "STABLE"
                       << "START"
                       << "STATE"
                       << "STATEMENT"
                       << "STATIC"
                       << "STATISTICS"
                       << "STDDEV_POP"
                       << "STDDEV_SAMP"
                       << "STDIN"
                       << "STDOUT"
                       << "STORAGE"
                       << "STRICT"
                       << "STRUCTURE"
                       << "STYLE"
                       << "SUBCLASS_ORIGIN"
                       << "SUBLIST"
                       << "SUBMULTISET"
                       << "SUBSTRING"
                       << "SUM"
                       << "SUPERUSER"
                       << "SYMMETRIC"
                       << "SYSID"
                       << "SYSTEM"
                       << "SYSTEM_USER"
                       << "TABLE"
                       << "TABLESAMPLE"
                       << "TABLESPACE"
                       << "TABLE_NAME"
                       << "TEMP"
                       << "TEMPLATE"
                       << "TEMPORARY"
                       << "TERMINATE"
                       << "THAN"
                       << "THEN"
                       << "TIES"
                       << "TIME"
                       << "TIMESTAMP"
                       << "TIMEZONE_HOUR"
                       << "TIMEZONE_MINUTE"
                       << "TO"
                       << "TOAST"
                       << "TOP_LEVEL_COUNT"
                       << "TRAILING"
                       << "TRANSACTION"
                       << "TRANSACTIONS_COMMITTED"
                       << "TRANSACTIONS_ROLLED_BACK"
                       << "TRANSACTION_ACTIVE"
                       << "TRANSFORM"
                       << "TRANSFORMS"
                       << "TRANSLATE"
                       << "TRANSLATION"
                       << "TREAT"
                       << "TRIGGER"
                       << "TRIGGER_CATALOG"
                       << "TRIGGER_NAME"
                       << "TRIGGER_SCHEMA"
                       << "TRIM"
                       << "TRUE"
                       << "TRUNCATE"
                       << "TRUSTED"
                       << "TYPE"
                       << "UESCAPE"
                       << "UNBOUNDED"
                       << "UNCOMMITTED"
                       << "UNDER"
                       << "UNENCRYPTED"
                       << "UNION"
                       << "UNIQUE"
                       << "UNKNOWN"
                       << "UNLISTEN"
                       << "UNNAMED"
                       << "UNNEST"
                       << "UNTIL"
                       << "UPDATE"
                       << "UPPER"
                       << "USAGE"
                       << "USER"
                       << "USER_DEFINED_TYPE_CATALOG"
                       << "USER_DEFINED_TYPE_CODE"
                       << "USER_DEFINED_TYPE_NAME"
                       << "USER_DEFINED_TYPE_SCHEMA"
                       << "USING"
                       << "VACUUM"
                       << "VALID"
                       << "VALIDATOR"
                       << "VALUE"
                       << "VALUES"
                       << "VARIABLE"
                       << "VARYING"
                       << "VAR_POP"
                       << "VAR_SAMP"
                       << "VERBOSE"
                       << "VIEW"
                       << "VOLATILE"
                       << "WHEN"
                       << "WHENEVER"
                       << "WHERE"
                       << "WINDOW"
                       << "WITH"
                       << "WITHIN"
                       << "WITHOUT"
                       << "WORK"
                       << "WRITE"
                       << "YEAR"
                       << "ZONE";
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
  if (settings.value("FileAssociations/PHPFiles", "").toString().split(",").contains(completeSuffix)
      || settings.value("FileAssociations/PHPFiles", "").toString().split(",").contains(suffix))
    return EditorTypes::PHP;
  if (settings.value("FileAssociations/CSSFiles", "").toString().split(",").contains(completeSuffix)
      || settings.value("FileAssociations/CSSFiles", "").toString().split(",").contains(suffix))
    return EditorTypes::CSS;
  if (settings.value("FileAssociations/HTMLFiles", "").toString().split(",").contains(completeSuffix)
      || settings.value("FileAssociations/HTMLFiles", "").toString().split(",").contains(suffix))
    return EditorTypes::HTML;
  if (settings.value("FileAssociations/JavaScriptFiles", "").toString().split(",").contains(completeSuffix)
      || settings.value("FileAssociations/JavaScriptFiles", "").toString().split(",").contains(suffix))
    return EditorTypes::JavaScript;
  return EditorTypes::NoEditor;
}

QIcon StaticFunctions::iconFromFileName(const EditorTypes::EditorType editorType)
{
  switch(editorType) {
  case EditorTypes::SQLQuery:
    return iconFromFileName("file.sql");
    break;
  case EditorTypes::PHP:
    return iconFromFileName("file.php");
    break;
  case EditorTypes::CSS:
    return iconFromFileName("file.css");
    break;
  case EditorTypes::HTML:
    return iconFromFileName("file.html");
    break;
  case EditorTypes::JavaScript:
    return iconFromFileName("file.js");
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
  case EditorTypes::PHP:
    return QIcon(QIcon(":/images/svg/application-x-php.svg"));
    break;
  case EditorTypes::CSS:
    return QIcon(QIcon(":/images/svg/text-css.svg"));
    break;
  case EditorTypes::HTML:
    return QIcon(QIcon(":/images/svg/text-html.svg"));
    break;
  case EditorTypes::JavaScript:
    return QIcon(QIcon(":/images/svg/application-javascript.svg"));
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
  //  data.insert("AES_DECRYPT", QString("<u>AES_DECRYPT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("AES_ENCRYPT", QString("<u>AES_ENCRYPT</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ASCII", QString("<u>ASCII</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ASIN", QString("<u>ASIN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ATAN", QString("<u>ATAN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("ATAN2", QString("<u>ATAN2</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("AVG", QString("<u>AVG</u>(<b>[DISTINCT] expr)</b>) <br />%1").arg(tr("Returns the average value of expr.<br />The DISTINCT option can be used as of MySQL 5.0.3 to return the average of the distinct values of expr.")));
  //  data.insert("BENCHMARK", QString("<u>BENCHMARK</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("BIN", QString("<u>BIN</u>(<b></b>) <br />%1").arg(tr("")));
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
  //  data.insert("CONCAT_WS", QString("<u>CONCAT_WS</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("CONCAT", QString("<u>CONCAT</u>(str1, str2, ...)) <br />%1").arg(tr("Returns the string that results from concatenating the arguments.")));
  //  data.insert("CONNECTION_ID", QString("<u>CONNECTION_ID</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("CONV", QString("<u>CONV</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("CONVERT_TZ", QString("<u>CONVERT_TZ</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COS", QString("<u>COS</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("COT", QString("<u>COT</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("COUNT", QString("<u>COUNT</u>(<b>expr</b>) <br />%1").arg(tr("Returns a count of the number of non-NULL values of expr in the rows retrieved by a SELECT statement.")));
  //  data.insert("CRC32", QString("<u>CRC32</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("CURDATE", QString("<u>CURDATE</u>() <br />%1").arg(tr("Returns the current date as a value in 'YYYY-MM-DD' or YYYYMMDD format, depending on whether the function is used in a string or numeric context.")));
  data.insert("CURRENT_DATE", QString("<u>CURRENT_DATE</u>() <br />%1").arg(tr("Returns the current date as a value in 'YYYY-MM-DD' or YYYYMMDD format, depending on whether the function is used in a string or numeric context.")));
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
  //  data.insert("HEX", QString("<u>HEX</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("HOUR_MICROSECOND", QString("<u>HOUR_MICROSECOND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("HOUR_MINUTE", QString("<u>HOUR_MINUTE</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("HOUR_SECOND", QString("<u>HOUR_SECOND</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("IFNULL", QString("<u>IFNULL</u>(<b>expr1, expr2</b>) <br />%1").arg(tr("If expr1 is not NULL, IFNULL() returns expr1; otherwise it returns expr2.<br />IFNULL() returns a numeric or string value, depending on the context in which it is used.")));
  data.insert("INET_ATON", QString("<u>INET_ATON</u>(<b>expr</b>) <br />%1").arg(tr("Given the dotted-quad representation of an IPv4 network address as a string, returns an integer that represents the numeric value of the address in network byte order (big endian).")));
  //  data.insert("INET_NTOA", QString("<u>INET_NTOA</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("INSTR", QString("<u>INSTR</u>(<b>str, substr</b>) <br />%1").arg(tr("Returns the position of the first occurrence of substring substr in string str.")));
  //  data.insert("INTERVAL", QString("<u>INTERVAL</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("IS_FREE_LOCK", QString("<u>IS_FREE_LOCK</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("IS_USED_LOCK", QString("<u>IS_USED_LOCK</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ISNULL", QString("<u>ISNULL</u>(<b>expr</b>) <br />%1").arg(tr("If expr is NULL, ISNULL() returns 1, otherwise it returns 0.")));
  //  data.insert("LAST_DAY", QString("<u>LAST_DAY</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("LAST_INSERT_ID", QString("<u>LAST_INSERT_ID</u>(<b></b>) <br />%1").arg(tr("")));
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
  //  data.insert("MAKETIME", QString("<u>MAKETIME</u>(<b></b>) <br />%1").arg(tr("")));
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
  //  data.insert("ROUND", QString("<u>ROUND</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ROW_COUNT", QString("<u>ROW_COUNT</u>() <br />%1").arg(tr("Returns the number of rows changed, deleted, or inserted by the last statement.")));
  data.insert("RPAD", QString("<u>RPAD</u>(<b>str, len, padstr</b>) <br />%1").arg(tr("Returns the string str, right-padded with the string padstr to a length of len characters.<br />If str is longer than len, the return value is shortened to len characters.")));
  //  data.insert("RTRIM", QString("<u>RTRIM</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("SEC_TO_TIME", QString("<u>SEC_TO_TIME</u>(<b>seconds</b>) <br />%1").arg(tr("Returns the seconds argument, converted to hours, minutes, and seconds, as a TIME value.")));
  //  data.insert("SECOND_MICROSECOND", QString("<u>SECOND_MICROSECOND</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SHA", QString("<u>SHA</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SHA1", QString("<u>SHA1</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SIGN", QString("<u>SIGN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SIN", QString("<u>SIN</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SLEEP", QString("<u>SLEEP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SOUNDEX", QString("<u>SOUNDEX</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("SOUNDS", QString("<u>SOUNDS</u>(<b></b>) <br />%1").arg(tr("")));
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
  //  data.insert("TIME_FORMAT", QString("<u>TIME_FORMAT</u>(<b></b>) <br />%1").arg(tr("")));
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
  //  data.insert("UUID", QString("<u>UUID</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("VAR_POP", QString("<u>VAR_POP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("VAR_SAMP", QString("<u>VAR_SAMP</u>(<b></b>) <br />%1").arg(tr("")));
  //  data.insert("VARIANCE", QString("<u>VARIANCE</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("VERSION", QString("<u>VERSION</u>(<b></b>) <br />%1").arg(tr("Returns a string that indicates the MySQL server version.")));
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
  case StaticFunctions::PostgreSQL:
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
      << "CLOSE"
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
      << "INFILE"
      << "INNER"
      << "INNODB"
      << "INOUT"
      << "INSENSITIVE"
      << "INSERT"
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
      << "MAXVALUE"
      << "MEDIUM"
      << "MERGE"
      << "MEMORY"
      << "MINUTE"
      << "MOD"
      << "MODE"
      << "MODIFIES"
      << "MODIFY"
      << "MRG_MYISAM"
      << "MYISAM"
      << "NAMES"
      << "NATURAL"
      << "NEW"
      << "NO_WRITE_TO_BINLOG"
      << "NO"
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
      << "PARTITIONS"
      << "PASSWORD"
      << "PERFORMANCE_SCHEMA"
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
      << "RENAME"
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
      << "ROLLBACK"
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
      << "SLAVE"
      << "SLAVES"
      << "SNAPSHOT"
      << "SPATIAL"
      << "SPECIFIC"
      << "SQL_CACHE"
      << "SQL_BIG_RESULT"
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
      << "USING"
      << "VALUES"
      << "VARIABLES"
      << "VARYING"
      << "VIEW"
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
      << "IS NULL"
      << "LIMIT 10"
      << "LIMIT 100"
      << "LIMIT 1000"
      << "LOAD DATA LOCAL INFILE 'localfile' INTO TABLE ``"
      << "NOT NULL DEFAULT"
      << "NOT NULL"
      << "ON DUPLICATE KEY UPDATE"
      << "OPTIMIZE [NO_WRITE_TO_BINLOG | LOCAL] TABLE tbl_name [, tbl_name] REPAIR [NO_WRITE_TO_BINLOG | LOCAL] TABLE tbl_name [, tbl_name] [QUICK] [EXTENDED] [USE_FRM]"
      << "ORDER BY"
      << "PURGE BINARY LOGS BEFORE NOW();"
      << "SELECT * FOR UPDATE"
      << "SELECT * FROM"
      << "SELECT * LOCK IN SHARE MODE"
      << "SELECT COUNT(*) FROM"
      << "SELECT SQL_CACHE"
      << "SELECT SQL_NO_CACHE"
      << "SET GLOBAL"
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
      << "SHOW ENGINE"
      << "SHOW ENGINES"
      << "SHOW ERRORS"
      << "SHOW EVENTS"
      << "SHOW FULL TABLES"
      << "SHOW FUNCTION CODE"
      << "SHOW FUNCTION STATUS"
      << "SHOW GRANTS"
      << "SHOW INDEX"
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
      << "START ALL SLAVES"
      << "START SLAVE IO_THREAD;"
      << "START SLAVE SQL_THREAD;"
      << "START SLAVE;"
      << "STOP ALL SLAVES"
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
  return QStringList() << "armscii8"
      << "armscii8_bin"
      << "armscii8_general_ci"
      << "ascii"
      << "ascii_bin"
      << "ascii_general_ci"
      << "big5"
      << "big5_bin"
      << "big5_chinese_ci"
      << "binary"
      << "binary"
      << "cp1250"
      << "cp1250_bin"
      << "cp1250_croatian_ci"
      << "cp1250_czech_cs"
      << "cp1250_general_ci"
      << "cp1251"
      << "cp1251_bin"
      << "cp1251_bulgarian_ci"
      << "cp1251_general_ci"
      << "cp1251_general_cs"
      << "cp1251_ukrainian_ci"
      << "cp1256"
      << "cp1256_bin"
      << "cp1256_general_ci"
      << "cp1257"
      << "cp1257_bin"
      << "cp1257_general_ci"
      << "cp1257_lithuanian_ci"
      << "cp850"
      << "cp850_bin"
      << "cp850_general_ci"
      << "cp852"
      << "cp852_bin"
      << "cp852_general_ci"
      << "cp866"
      << "cp866_bin"
      << "cp866_general_ci"
      << "cp932"
      << "cp932_bin"
      << "cp932_japanese_ci"
      << "dec8"
      << "dec8_bin"
      << "dec8_swedish_ci"
      << "eucjpms"
      << "eucjpms_bin"
      << "eucjpms_japanese_ci"
      << "euckr"
      << "euckr_bin"
      << "euckr_korean_ci"
      << "gb2312"
      << "gb2312_bin"
      << "gb2312_chinese_ci"
      << "gbk"
      << "gbk_bin"
      << "gbk_chinese_ci"
      << "geostd8"
      << "geostd8_bin"
      << "geostd8_general_ci"
      << "greek"
      << "greek_bin"
      << "greek_general_ci"
      << "hebrew"
      << "hebrew_bin"
      << "hebrew_general_ci"
      << "hp8"
      << "hp8_bin"
      << "hp8_english_ci"
      << "keybcs2"
      << "keybcs2_bin"
      << "keybcs2_general_ci"
      << "koi8r"
      << "koi8r_bin"
      << "koi8r_general_ci"
      << "koi8u"
      << "koi8u_bin"
      << "koi8u_general_ci"
      << "latin1"
      << "latin1_bin"
      << "latin1_danish_ci"
      << "latin1_general_ci"
      << "latin1_general_cs"
      << "latin1_german1_ci"
      << "latin1_german2_ci"
      << "latin1_spanish_ci"
      << "latin1_swedish_ci"
      << "latin2"
      << "latin2_bin"
      << "latin2_croatian_ci"
      << "latin2_czech_cs"
      << "latin2_general_ci"
      << "latin2_hungarian_ci"
      << "latin5"
      << "latin5_bin"
      << "latin5_turkish_ci"
      << "latin7"
      << "latin7_bin"
      << "latin7_estonian_cs"
      << "latin7_general_ci"
      << "latin7_general_cs"
      << "macce"
      << "macce_bin"
      << "macce_general_ci"
      << "macroman"
      << "macroman_bin"
      << "macroman_general_ci"
      << "sjis"
      << "sjis_bin"
      << "sjis_japanese_ci"
      << "swe7"
      << "swe7_bin"
      << "swe7_swedish_ci"
      << "tis620"
      << "tis620_bin"
      << "tis620_thai_ci"
      << "ucs2"
      << "ucs2_bin"
      << "ucs2_czech_ci"
      << "ucs2_danish_ci"
      << "ucs2_esperanto_ci"
      << "ucs2_estonian_ci"
      << "ucs2_general_ci"
      << "ucs2_hungarian_ci"
      << "ucs2_icelandic_ci"
      << "ucs2_latvian_ci"
      << "ucs2_lithuanian_ci"
      << "ucs2_persian_ci"
      << "ucs2_polish_ci"
      << "ucs2_romanian_ci"
      << "ucs2_roman_ci"
      << "ucs2_slovak_ci"
      << "ucs2_slovenian_ci"
      << "ucs2_spanish2_ci"
      << "ucs2_spanish_ci"
      << "ucs2_swedish_ci"
      << "ucs2_turkish_ci"
      << "ucs2_unicode_ci"
      << "ujis"
      << "ujis_bin"
      << "ujis_japanese_ci"
      << "utf8"
      << "utf8_bin"
      << "utf8_czech_ci"
      << "utf8_danish_ci"
      << "utf8_esperanto_ci"
      << "utf8_estonian_ci"
      << "utf8_general_ci"
      << "utf8_hungarian_ci"
      << "utf8_icelandic_ci"
      << "utf8_latvian_ci"
      << "utf8_lithuanian_ci"
      << "utf8_persian_ci"
      << "utf8_polish_ci"
      << "utf8_romanian_ci"
      << "utf8_roman_ci"
      << "utf8_slovak_ci"
      << "utf8_slovenian_ci"
      << "utf8_spanish2_ci"
      << "utf8_spanish_ci"
      << "utf8_swedish_ci"
      << "utf8_turkish_ci"
      << "utf8_unicode_ci";
}

QHash<QString, QString> StaticFunctions::phpFunctionsComplete()
{
  QHash<QString, QString> data;
//  data.insert("Phar", QString("<u>Phar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("PharData", QString("<u>PharData</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("PharException", QString("<u>PharException</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("PharFileInfo", QString("<u>PharFileInfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("abs", QString("<u>abs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("acos", QString("<u>acos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("acosh", QString("<u>acosh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("addcslashes", QString("<u>addcslashes</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("addslashes", QString("string <u>addslashes</u>(<b>string $str</b>) <br />%1").arg(tr("Quote string with slashes")));
//  data.insert("aggregate", QString("<u>aggregate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_info", QString("<u>aggregate_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_methods", QString("<u>aggregate_methods</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_methods_by_list", QString("<u>aggregate_methods_by_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_methods_by_regexp", QString("<u>aggregate_methods_by_regexp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_properties", QString("<u>aggregate_properties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_properties_by_list", QString("<u>aggregate_properties_by_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregate_properties_by_regexp", QString("<u>aggregate_properties_by_regexp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("aggregation_info", QString("<u>aggregation_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("amqpconnection", QString("<u>amqpconnection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("amqpexchange", QString("<u>amqpexchange</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("amqpqueue", QString("<u>amqpqueue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_child_terminate", QString("<u>apache_child_terminate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_get_modules", QString("<u>apache_get_modules</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_get_version", QString("<u>apache_get_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_getenv", QString("<u>apache_getenv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_lookup_uri", QString("<u>apache_lookup_uri</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_note", QString("<u>apache_note</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_request_headers", QString("<u>apache_request_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_reset_timeout", QString("<u>apache_reset_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_response_headers", QString("<u>apache_response_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apache_setenv", QString("<u>apache_setenv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_add", QString("<u>apc_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_bin_dump", QString("<u>apc_bin_dump</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_bin_dumpfile", QString("<u>apc_bin_dumpfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_bin_load", QString("<u>apc_bin_load</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_bin_loadfile", QString("<u>apc_bin_loadfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_cache_info", QString("<u>apc_cache_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_cas", QString("<u>apc_cas</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_clear_cache", QString("<u>apc_clear_cache</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_compile_file", QString("<u>apc_compile_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_dec", QString("<u>apc_dec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_define_constants", QString("<u>apc_define_constants</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_delete", QString("<u>apc_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_delete_file", QString("<u>apc_delete_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_exists", QString("<u>apc_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_fetch", QString("<u>apc_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_inc", QString("<u>apc_inc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_load_constants", QString("<u>apc_load_constants</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_sma_info", QString("<u>apc_sma_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apc_store", QString("<u>apc_store</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apciterator", QString("<u>apciterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_breakpoint", QString("<u>apd_breakpoint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_callstack", QString("<u>apd_callstack</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_clunk", QString("<u>apd_clunk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_continue", QString("<u>apd_continue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_croak", QString("<u>apd_croak</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_dump_function_table", QString("<u>apd_dump_function_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_dump_persistent_resources", QString("<u>apd_dump_persistent_resources</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_dump_regular_resources", QString("<u>apd_dump_regular_resources</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_echo", QString("<u>apd_echo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_get_active_symbols", QString("<u>apd_get_active_symbols</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_set_pprof_trace", QString("<u>apd_set_pprof_trace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_set_session", QString("<u>apd_set_session</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_set_session_trace", QString("<u>apd_set_session_trace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("apd_set_session_trace_socket", QString("<u>apd_set_session_trace_socket</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("appenditerator", QString("<u>appenditerator</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array", QString("array <u>array</u>(<b>[mixed $...]</b>) <br />%1").arg(tr("Create an array")));
//  data.insert("array_change_key_case", QString("<u>array_change_key_case</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_chunk", QString("<u>array_chunk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_combine", QString("<u>array_combine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_count_values", QString("<u>array_count_values</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_diff", QString("array <u>array_diff</u>(<b>array $array1, array $array2 [, array $... ]</b>) <br />%1").arg(tr("Compares array1 against array2 and returns the difference.")));
//  data.insert("array_diff_assoc", QString("<u>array_diff_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_diff_key", QString("<u>array_diff_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_diff_uassoc", QString("<u>array_diff_uassoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_diff_ukey", QString("<u>array_diff_ukey</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_fill", QString("<u>array_fill</u>(<b>int $start_index, int $num , mixed $value</b>) <br />%1").arg(tr("Fills an array with num entries of the value of the value parameter, keys starting at the start_index parameter.")));
//  data.insert("array_fill_keys", QString("<u>array_fill_keys</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_filter", QString("array <u>array_filter</u>(<b>array $input [, callable $callback = ""]</b>) <br />%1").arg(tr("Filters elements of an array using a callback function.")));
  data.insert("array_flip", QString("<u>array_flip</u>(<b>array $trans</b>) <br />%1").arg(tr("Exchanges all keys with their associated values in an array.")));
//  data.insert("array_intersect", QString("<u>array_intersect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_intersect_assoc", QString("<u>array_intersect_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_intersect_key", QString("<u>array_intersect_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_intersect_uassoc", QString("<u>array_intersect_uassoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_intersect_ukey", QString("<u>array_intersect_ukey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_key_exists", QString("<u>array_key_exists</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_keys", QString("array <u>array_keys</u>(<b>array $input [, mixed $search_value = NULL [, bool $strict = false ]]</b>) <br />%1").arg(tr("Returns the keys, numeric and string, from the input array.")));
//  data.insert("array_map", QString("<u>array_map</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_merge", QString("array <u>array_merge</u>(<b>array $array1 [, array $...]</b>) <br />%1").arg(tr("Merge one or more arrays.")));
//  data.insert("array_merge_recursive", QString("<u>array_merge_recursive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_multisort", QString("<u>array_multisort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_pad", QString("<u>array_pad</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_pop", QString("<u>array_pop</u>(<b>array &$array</b>) <br />%1").arg(tr("Pop the element off the end of array")));
//  data.insert("array_product", QString("<u>array_product</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_push", QString("<u>array_push</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_rand", QString("<u>array_rand</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_reduce", QString("<u>array_reduce</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_replace", QString("<u>array_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_replace_recursive", QString("<u>array_replace_recursive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_reverse", QString("<u>array_reverse</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_search", QString("<u>array_search</u>(<b>mixed $needle, array $haystack [, bool $strict = false]</b>) <br />%1").arg(tr("Searches the array for a given value and returns the corresponding key if successful.")));
//  data.insert("array_shift", QString("<u>array_shift</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_slice", QString("array <u>array_slice</u>(<b>array $array, int $offset [, int $length [, bool $preserve_keys = false ]]</b>) <br />%1").arg(tr("Extract a slice of the array")));
  data.insert("array_splice", QString("array <u>array_splice</u>(<b>array &$input, int $offset [, int $length = 0 [, mixed $replacement ]]</b>) <br />%1").arg(tr("Remove a portion of the array and replace it with something else")));
  data.insert("array_sum", QString("<u>array_sum</u>(<b>array $array</b>) <br />%1").arg(tr("Calculate the sum of values in an array.")));
//  data.insert("array_udiff", QString("<u>array_udiff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_udiff_assoc", QString("<u>array_udiff_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_udiff_uassoc", QString("<u>array_udiff_uassoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_uintersect", QString("<u>array_uintersect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_uintersect_assoc", QString("<u>array_uintersect_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_uintersect_uassoc", QString("<u>array_uintersect_uassoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_unique", QString("<u>array_unique</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_unshift", QString("<u>array_unshift</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("array_values", QString("array <u>array_values</u>(<b>array $array</b>) <br />%1").arg(tr("Return all the values of an array.")));
//  data.insert("array_walk", QString("<u>array_walk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("array_walk_recursive", QString("<u>array_walk_recursive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("arrayaccess", QString("<u>arrayaccess</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("arrayiterator", QString("<u>arrayiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("arrayobject", QString("<u>arrayobject</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("arsort", QString("bool <u>arsort</u>(<b>array &$array [, int $sort_flags = SORT_REGULAR ]</b>) <br />%1").arg(tr("Sort an array in reverse order and maintain index association")));
//  data.insert("asin", QString("<u>asin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("asinh", QString("<u>asinh</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("asort", QString("<u>asort</u>(<b>array &$array [, int $sort_flags = SORT_REGULAR]</b>) <br />%1").arg(tr("Sort an array and maintain index association.")));
//  data.insert("assert", QString("<u>assert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("assert_options", QString("<u>assert_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("atan", QString("<u>atan</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("atan2", QString("<u>atan2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("atanh", QString("<u>atanh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("badfunctioncallexception", QString("<u>badfunctioncallexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("badmethodcallexception", QString("<u>badmethodcallexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("base64_decode", QString("<u>base64_decode</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("base64_encode", QString("string <u>base64_encode</u>(<b>string $data</b>) <br />%1").arg(tr("Encodes data with MIME base64")));
//  data.insert("base_convert", QString("<u>base_convert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("basename", QString("<u>basename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_add_element", QString("<u>bbcode_add_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_add_smiley", QString("<u>bbcode_add_smiley</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_create", QString("<u>bbcode_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_destroy", QString("<u>bbcode_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_parse", QString("<u>bbcode_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_set_arg_parser", QString("<u>bbcode_set_arg_parser</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bbcode_set_flags", QString("<u>bbcode_set_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcadd", QString("<u>bcadd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bccomp", QString("<u>bccomp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcdiv", QString("<u>bcdiv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcmod", QString("<u>bcmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcmul", QString("<u>bcmul</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_load", QString("<u>bcompiler_load</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_load_exe", QString("<u>bcompiler_load_exe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_parse_class", QString("<u>bcompiler_parse_class</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_read", QString("<u>bcompiler_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_class", QString("<u>bcompiler_write_class</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_constant", QString("<u>bcompiler_write_constant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_exe_footer", QString("<u>bcompiler_write_exe_footer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_file", QString("<u>bcompiler_write_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_footer", QString("<u>bcompiler_write_footer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_function", QString("<u>bcompiler_write_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_functions_from_file", QString("<u>bcompiler_write_functions_from_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_header", QString("<u>bcompiler_write_header</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcompiler_write_included_filename", QString("<u>bcompiler_write_included_filename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcpow", QString("<u>bcpow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcpowmod", QString("<u>bcpowmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcscale", QString("<u>bcscale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcsqrt", QString("<u>bcsqrt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bcsub", QString("<u>bcsub</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bin2hex", QString("<u>bin2hex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bind_textdomain_codeset", QString("<u>bind_textdomain_codeset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bindec", QString("<u>bindec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bindtextdomain", QString("<u>bindtextdomain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bson_decode", QString("<u>bson_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bson_encode", QString("<u>bson_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bumpValue", QString("<u>bumpValue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzclose", QString("<u>bzclose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzcompress", QString("<u>bzcompress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzdecompress", QString("<u>bzdecompress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzerrno", QString("<u>bzerrno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzerror", QString("<u>bzerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzerrstr", QString("<u>bzerrstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzflush", QString("<u>bzflush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzopen", QString("<u>bzopen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzread", QString("<u>bzread</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("bzwrite", QString("<u>bzwrite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cachingiterator", QString("<u>cachingiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo", QString("<u>cairo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_create", QString("<u>cairo_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_face_get_type", QString("<u>cairo_font_face_get_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_face_status", QString("<u>cairo_font_face_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_create", QString("<u>cairo_font_options_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_equal", QString("<u>cairo_font_options_equal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_get_antialias", QString("<u>cairo_font_options_get_antialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_get_hint_metrics", QString("<u>cairo_font_options_get_hint_metrics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_get_hint_style", QString("<u>cairo_font_options_get_hint_style</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_get_subpixel_order", QString("<u>cairo_font_options_get_subpixel_order</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_hash", QString("<u>cairo_font_options_hash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_merge", QString("<u>cairo_font_options_merge</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_set_antialias", QString("<u>cairo_font_options_set_antialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_set_hint_metrics", QString("<u>cairo_font_options_set_hint_metrics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_set_hint_style", QString("<u>cairo_font_options_set_hint_style</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_set_subpixel_order", QString("<u>cairo_font_options_set_subpixel_order</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_font_options_status", QString("<u>cairo_font_options_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_format_stride_for_width", QString("<u>cairo_format_stride_for_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_create", QString("<u>cairo_image_surface_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_create_for_data", QString("<u>cairo_image_surface_create_for_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_create_from_png", QString("<u>cairo_image_surface_create_from_png</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_get_data", QString("<u>cairo_image_surface_get_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_get_format", QString("<u>cairo_image_surface_get_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_get_height", QString("<u>cairo_image_surface_get_height</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_get_stride", QString("<u>cairo_image_surface_get_stride</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_image_surface_get_width", QString("<u>cairo_image_surface_get_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_create_scale", QString("<u>cairo_matrix_create_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_create_translate", QString("<u>cairo_matrix_create_translate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_invert", QString("<u>cairo_matrix_invert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_multiply", QString("<u>cairo_matrix_multiply</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_rotate", QString("<u>cairo_matrix_rotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_transform_distance", QString("<u>cairo_matrix_transform_distance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_transform_point", QString("<u>cairo_matrix_transform_point</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_matrix_translate", QString("<u>cairo_matrix_translate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_add_color_stop_rgb", QString("<u>cairo_pattern_add_color_stop_rgb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_add_color_stop_rgba", QString("<u>cairo_pattern_add_color_stop_rgba</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_create_for_surface", QString("<u>cairo_pattern_create_for_surface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_create_linear", QString("<u>cairo_pattern_create_linear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_create_radial", QString("<u>cairo_pattern_create_radial</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_create_rgb", QString("<u>cairo_pattern_create_rgb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_create_rgba", QString("<u>cairo_pattern_create_rgba</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_color_stop_count", QString("<u>cairo_pattern_get_color_stop_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_color_stop_rgba", QString("<u>cairo_pattern_get_color_stop_rgba</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_extend", QString("<u>cairo_pattern_get_extend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_filter", QString("<u>cairo_pattern_get_filter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_linear_points", QString("<u>cairo_pattern_get_linear_points</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_matrix", QString("<u>cairo_pattern_get_matrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_radial_circles", QString("<u>cairo_pattern_get_radial_circles</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_rgba", QString("<u>cairo_pattern_get_rgba</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_surface", QString("<u>cairo_pattern_get_surface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_get_type", QString("<u>cairo_pattern_get_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_set_extend", QString("<u>cairo_pattern_set_extend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_set_filter", QString("<u>cairo_pattern_set_filter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_set_matrix", QString("<u>cairo_pattern_set_matrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pattern_status", QString("<u>cairo_pattern_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pdf_surface_create", QString("<u>cairo_pdf_surface_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_pdf_surface_set_size", QString("<u>cairo_pdf_surface_set_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_get_levels", QString("<u>cairo_ps_get_levels</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_level_to_string", QString("<u>cairo_ps_level_to_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_create", QString("<u>cairo_ps_surface_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_dsc_begin_page_setup", QString("<u>cairo_ps_surface_dsc_begin_page_setup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_dsc_begin_setup", QString("<u>cairo_ps_surface_dsc_begin_setup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_dsc_comment", QString("<u>cairo_ps_surface_dsc_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_get_eps", QString("<u>cairo_ps_surface_get_eps</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_restrict_to_level", QString("<u>cairo_ps_surface_restrict_to_level</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_set_eps", QString("<u>cairo_ps_surface_set_eps</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_ps_surface_set_size", QString("<u>cairo_ps_surface_set_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_create", QString("<u>cairo_scaled_font_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_extents", QString("<u>cairo_scaled_font_extents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_get_ctm", QString("<u>cairo_scaled_font_get_ctm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_get_font_face", QString("<u>cairo_scaled_font_get_font_face</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_get_font_matrix", QString("<u>cairo_scaled_font_get_font_matrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_get_font_options", QString("<u>cairo_scaled_font_get_font_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_get_scale_matrix", QString("<u>cairo_scaled_font_get_scale_matrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_get_type", QString("<u>cairo_scaled_font_get_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_glyph_extents", QString("<u>cairo_scaled_font_glyph_extents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_status", QString("<u>cairo_scaled_font_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_scaled_font_text_extents", QString("<u>cairo_scaled_font_text_extents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_copy_page", QString("<u>cairo_surface_copy_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_create_similar", QString("<u>cairo_surface_create_similar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_finish", QString("<u>cairo_surface_finish</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_flush", QString("<u>cairo_surface_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_get_content", QString("<u>cairo_surface_get_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_get_device_offset", QString("<u>cairo_surface_get_device_offset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_get_font_options", QString("<u>cairo_surface_get_font_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_get_type", QString("<u>cairo_surface_get_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_mark_dirty", QString("<u>cairo_surface_mark_dirty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_mark_dirty_rectangle", QString("<u>cairo_surface_mark_dirty_rectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_set_device_offset", QString("<u>cairo_surface_set_device_offset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_set_fallback_resolution", QString("<u>cairo_surface_set_fallback_resolution</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_show_page", QString("<u>cairo_surface_show_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_status", QString("<u>cairo_surface_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_surface_write_to_png", QString("<u>cairo_surface_write_to_png</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_svg_surface_create", QString("<u>cairo_svg_surface_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_svg_surface_restrict_to_version", QString("<u>cairo_svg_surface_restrict_to_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairo_svg_version_to_string", QString("<u>cairo_svg_version_to_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoantialias", QString("<u>cairoantialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairocontent", QString("<u>cairocontent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairocontext", QString("<u>cairocontext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoexception", QString("<u>cairoexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoextend", QString("<u>cairoextend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofillrule", QString("<u>cairofillrule</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofilter", QString("<u>cairofilter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofontface", QString("<u>cairofontface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofontoptions", QString("<u>cairofontoptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofontslant", QString("<u>cairofontslant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofonttype", QString("<u>cairofonttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairofontweight", QString("<u>cairofontweight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoformat", QString("<u>cairoformat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairogradientpattern", QString("<u>cairogradientpattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairohintmetrics", QString("<u>cairohintmetrics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairohintstyle", QString("<u>cairohintstyle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoimagesurface", QString("<u>cairoimagesurface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairolineargradient", QString("<u>cairolineargradient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairolinecap", QString("<u>cairolinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairolinejoin", QString("<u>cairolinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairomatrix", QString("<u>cairomatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairooperator", QString("<u>cairooperator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairopath", QString("<u>cairopath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairopattern", QString("<u>cairopattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairopatterntype", QString("<u>cairopatterntype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairopdfsurface", QString("<u>cairopdfsurface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairopslevel", QString("<u>cairopslevel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairopssurface", QString("<u>cairopssurface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoradialgradient", QString("<u>cairoradialgradient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairoscaledfont", QString("<u>cairoscaledfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosolidpattern", QString("<u>cairosolidpattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairostatus", QString("<u>cairostatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosubpixelorder", QString("<u>cairosubpixelorder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosurface", QString("<u>cairosurface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosurfacepattern", QString("<u>cairosurfacepattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosurfacetype", QString("<u>cairosurfacetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosvgsurface", QString("<u>cairosvgsurface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairosvgversion", QString("<u>cairosvgversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cairotoyfontface", QString("<u>cairotoyfontface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cal_days_in_month", QString("<u>cal_days_in_month</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cal_from_jd", QString("<u>cal_from_jd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cal_info", QString("<u>cal_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cal_to_jd", QString("<u>cal_to_jd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("calcul_hmac", QString("<u>calcul_hmac</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("calculhmac", QString("<u>calculhmac</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("call_user_func", QString("mixed <u>call_user_func</u>(<b>callable $callback [, mixed $parameter [, mixed $... ]]</b>) <br />%1").arg(tr("Calls the callback given by the first parameter and passes the remaining parameters as arguments.")));
//  data.insert("call_user_func_array", QString("<u>call_user_func_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("call_user_method", QString("<u>call_user_method</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("call_user_method_array", QString("<u>call_user_method_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("callbackfilteriterator", QString("<u>callbackfilteriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ceil", QString("<u>ceil</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chdb", QString("<u>chdb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chdb_create", QString("<u>chdb_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chdir", QString("<u>chdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("checkdate", QString("<u>checkdate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("checkdnsrr", QString("<u>checkdnsrr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chgrp", QString("<u>chgrp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chmod", QString("<u>chmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chop", QString("<u>chop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chown", QString("<u>chown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chr", QString("<u>chr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("chroot", QString("<u>chroot</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("chunk_split", QString("string <u>chunk_split</u>(<b>string $body [, int $chunklen = 76 [, string $end = \"\r\n\" ]]</b>) <br />%1").arg(tr("Split a string into smaller chunks")));
//  data.insert("class_alias", QString("<u>class_alias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("class_exists", QString("<u>class_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("class_implements", QString("<u>class_implements</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("class_parents", QString("<u>class_parents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("class_uses", QString("<u>class_uses</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("classkit_import", QString("<u>classkit_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("classkit_method_add", QString("<u>classkit_method_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("classkit_method_copy", QString("<u>classkit_method_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("classkit_method_redefine", QString("<u>classkit_method_redefine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("classkit_method_remove", QString("<u>classkit_method_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("classkit_method_rename", QString("<u>classkit_method_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("clearstatcache", QString("<u>clearstatcache</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("clone", QString("<u>clone</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("closedir", QString("void <u>closedir</u>(<b>[ resource $dir_handle ]</b>) <br />%1").arg(tr("Close directory handle")));
//  data.insert("closelog", QString("<u>closelog</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("closure", QString("<u>closure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("collator", QString("<u>collator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com", QString("<u>com</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_addref", QString("<u>com_addref</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_create_guid", QString("<u>com_create_guid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_event_sink", QString("<u>com_event_sink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_get", QString("<u>com_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_get_active_object", QString("<u>com_get_active_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_invoke", QString("<u>com_invoke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_isenum", QString("<u>com_isenum</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_load", QString("<u>com_load</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_load_typelib", QString("<u>com_load_typelib</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_message_pump", QString("<u>com_message_pump</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_print_typeinfo", QString("<u>com_print_typeinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_propget", QString("<u>com_propget</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_propput", QString("<u>com_propput</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_propset", QString("<u>com_propset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_release", QString("<u>com_release</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("com_set", QString("<u>com_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("compact", QString("<u>compact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("connection_aborted", QString("<u>connection_aborted</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("connection_status", QString("<u>connection_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("connection_timeout", QString("<u>connection_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("constant", QString("<u>constant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("construct", QString("<u>construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("construct", QString("<u>construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("construct", QString("<u>construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("convert_cyr_string", QString("<u>convert_cyr_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("convert_uudecode", QString("<u>convert_uudecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("convert_uuencode", QString("<u>convert_uuencode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("copy", QString("<u>copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cos", QString("<u>cos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cosh", QString("<u>cosh</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("count", QString("<u>count</u>(<b>mixed $var [, int $mode = COUNT_NORMAL]</b>) <br />%1").arg(tr("Counts all elements in an array, or something in an object.")));
//  data.insert("count_chars", QString("<u>count_chars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("countable", QString("<u>countable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_bump", QString("<u>counter_bump</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_bump_value", QString("<u>counter_bump_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_create", QString("<u>counter_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_get", QString("<u>counter_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_get_meta", QString("<u>counter_get_meta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_get_named", QString("<u>counter_get_named</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_get_value", QString("<u>counter_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_reset", QString("<u>counter_reset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("counter_reset_value", QString("<u>counter_reset_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("crack_check", QString("<u>crack_check</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("crack_closedict", QString("<u>crack_closedict</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("crack_getlastmessage", QString("<u>crack_getlastmessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("crack_opendict", QString("<u>crack_opendict</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("crc32", QString("<u>crc32</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("create_function", QString("<u>create_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("crypt", QString("<u>crypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_alnum", QString("<u>ctype_alnum</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_alpha", QString("<u>ctype_alpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_cntrl", QString("<u>ctype_cntrl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_digit", QString("<u>ctype_digit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_graph", QString("<u>ctype_graph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_lower", QString("<u>ctype_lower</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_print", QString("<u>ctype_print</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_punct", QString("<u>ctype_punct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_space", QString("<u>ctype_space</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_upper", QString("<u>ctype_upper</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ctype_xdigit", QString("<u>ctype_xdigit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_affected_rows", QString("<u>cubrid_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_bind", QString("<u>cubrid_bind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_client_encoding", QString("<u>cubrid_client_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_close", QString("<u>cubrid_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_close_prepare", QString("<u>cubrid_close_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_close_request", QString("<u>cubrid_close_request</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_col_get", QString("<u>cubrid_col_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_col_size", QString("<u>cubrid_col_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_column_names", QString("<u>cubrid_column_names</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_column_types", QString("<u>cubrid_column_types</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_commit", QString("<u>cubrid_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_connect", QString("<u>cubrid_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_connect_with_url", QString("<u>cubrid_connect_with_url</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_current_oid", QString("<u>cubrid_current_oid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_data_seek", QString("<u>cubrid_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_db_name", QString("<u>cubrid_db_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_disconnect", QString("<u>cubrid_disconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_drop", QString("<u>cubrid_drop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_errno", QString("<u>cubrid_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_error", QString("<u>cubrid_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_error_code", QString("<u>cubrid_error_code</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_error_code_facility", QString("<u>cubrid_error_code_facility</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_error_msg", QString("<u>cubrid_error_msg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_execute", QString("<u>cubrid_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch", QString("<u>cubrid_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch_array", QString("<u>cubrid_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch_assoc", QString("<u>cubrid_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch_field", QString("<u>cubrid_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch_lengths", QString("<u>cubrid_fetch_lengths</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch_object", QString("<u>cubrid_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_fetch_row", QString("<u>cubrid_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_field_flags", QString("<u>cubrid_field_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_field_len", QString("<u>cubrid_field_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_field_name", QString("<u>cubrid_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_field_seek", QString("<u>cubrid_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_field_table", QString("<u>cubrid_field_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_field_type", QString("<u>cubrid_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_free_result", QString("<u>cubrid_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get", QString("<u>cubrid_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_autocommit", QString("<u>cubrid_get_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_charset", QString("<u>cubrid_get_charset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_class_name", QString("<u>cubrid_get_class_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_client_info", QString("<u>cubrid_get_client_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_db_parameter", QString("<u>cubrid_get_db_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_query_timeout", QString("<u>cubrid_get_query_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_get_server_info", QString("<u>cubrid_get_server_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_insert_id", QString("<u>cubrid_insert_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_is_instance", QString("<u>cubrid_is_instance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_list_dbs", QString("<u>cubrid_list_dbs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_load_from_glo", QString("<u>cubrid_load_from_glo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lob_close", QString("<u>cubrid_lob_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lob_export", QString("<u>cubrid_lob_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lob_get", QString("<u>cubrid_lob_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lob_send", QString("<u>cubrid_lob_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lob_size", QString("<u>cubrid_lob_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lock_read", QString("<u>cubrid_lock_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_lock_write", QString("<u>cubrid_lock_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_move_cursor", QString("<u>cubrid_move_cursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_new_glo", QString("<u>cubrid_new_glo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_next_result", QString("<u>cubrid_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_num_cols", QString("<u>cubrid_num_cols</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_num_fields", QString("<u>cubrid_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_num_rows", QString("<u>cubrid_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_pconnect", QString("<u>cubrid_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_pconnect_with_url", QString("<u>cubrid_pconnect_with_url</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_ping", QString("<u>cubrid_ping</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_prepare", QString("<u>cubrid_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_put", QString("<u>cubrid_put</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_query", QString("<u>cubrid_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_real_escape_string", QString("<u>cubrid_real_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_result", QString("<u>cubrid_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_rollback", QString("<u>cubrid_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_save_to_glo", QString("<u>cubrid_save_to_glo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_schema", QString("<u>cubrid_schema</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_send_glo", QString("<u>cubrid_send_glo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_seq_drop", QString("<u>cubrid_seq_drop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_seq_insert", QString("<u>cubrid_seq_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_seq_put", QString("<u>cubrid_seq_put</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_set_add", QString("<u>cubrid_set_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_set_autocommit", QString("<u>cubrid_set_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_set_db_parameter", QString("<u>cubrid_set_db_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_set_drop", QString("<u>cubrid_set_drop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_set_query_timeout", QString("<u>cubrid_set_query_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_unbuffered_query", QString("<u>cubrid_unbuffered_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cubrid_version", QString("<u>cubrid_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_close", QString("<u>curl_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_copy_handle", QString("<u>curl_copy_handle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_errno", QString("<u>curl_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_error", QString("<u>curl_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_exec", QString("<u>curl_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_getinfo", QString("<u>curl_getinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_init", QString("<u>curl_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_add_handle", QString("<u>curl_multi_add_handle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_close", QString("<u>curl_multi_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_exec", QString("<u>curl_multi_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_getcontent", QString("<u>curl_multi_getcontent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_info_read", QString("<u>curl_multi_info_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_init", QString("<u>curl_multi_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_remove_handle", QString("<u>curl_multi_remove_handle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_multi_select", QString("<u>curl_multi_select</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_setopt", QString("<u>curl_setopt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_setopt_array", QString("<u>curl_setopt_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("curl_version", QString("<u>curl_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("current", QString("<u>current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cyrus_authenticate", QString("<u>cyrus_authenticate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cyrus_bind", QString("<u>cyrus_bind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cyrus_close", QString("<u>cyrus_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cyrus_connect", QString("<u>cyrus_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cyrus_query", QString("<u>cyrus_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("cyrus_unbind", QString("<u>cyrus_unbind</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("date", QString("string <u>date</u>(<b>string $format [, int $timestamp = time()]</b>) <br />%1").arg(tr("Format a local time/date")));
//  data.insert("date_add", QString("<u>date_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_create", QString("<u>date_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_create_from_format", QString("<u>date_create_from_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_date_set", QString("<u>date_date_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_default_timezone_get", QString("<u>date_default_timezone_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_default_timezone_set", QString("<u>date_default_timezone_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_diff", QString("<u>date_diff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_format", QString("<u>date_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_get_last_errors", QString("<u>date_get_last_errors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_interval_create_from_date_string", QString("<u>date_interval_create_from_date_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_interval_format", QString("<u>date_interval_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_isodate_set", QString("<u>date_isodate_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_modify", QString("<u>date_modify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_offset_get", QString("<u>date_offset_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_parse", QString("<u>date_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_parse_from_format", QString("<u>date_parse_from_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_sub", QString("<u>date_sub</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_sun_info", QString("<u>date_sun_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_sunrise", QString("<u>date_sunrise</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_sunset", QString("<u>date_sunset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_time_set", QString("<u>date_time_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_timestamp_get", QString("<u>date_timestamp_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_timestamp_set", QString("<u>date_timestamp_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_timezone_get", QString("<u>date_timezone_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("date_timezone_set", QString("<u>date_timezone_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dateinterval", QString("<u>dateinterval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dateperiod", QString("<u>dateperiod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("datetime", QString("<u>datetime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("datetimezone", QString("<u>datetimezone</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_autocommit", QString("<u>db2_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_bind_param", QString("<u>db2_bind_param</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_client_info", QString("<u>db2_client_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_close", QString("<u>db2_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_column_privileges", QString("<u>db2_column_privileges</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_columns", QString("<u>db2_columns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_commit", QString("<u>db2_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_conn_error", QString("<u>db2_conn_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_conn_errormsg", QString("<u>db2_conn_errormsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_connect", QString("<u>db2_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_cursor_type", QString("<u>db2_cursor_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_escape_string", QString("<u>db2_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_exec", QString("<u>db2_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_execute", QString("<u>db2_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_fetch_array", QString("<u>db2_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_fetch_assoc", QString("<u>db2_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_fetch_both", QString("<u>db2_fetch_both</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_fetch_object", QString("<u>db2_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_fetch_row", QString("<u>db2_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_display_size", QString("<u>db2_field_display_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_name", QString("<u>db2_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_num", QString("<u>db2_field_num</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_precision", QString("<u>db2_field_precision</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_scale", QString("<u>db2_field_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_type", QString("<u>db2_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_field_width", QString("<u>db2_field_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_foreign_keys", QString("<u>db2_foreign_keys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_free_result", QString("<u>db2_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_free_stmt", QString("<u>db2_free_stmt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_get_option", QString("<u>db2_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_last_insert_id", QString("<u>db2_last_insert_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_lob_read", QString("<u>db2_lob_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_next_result", QString("<u>db2_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_num_fields", QString("<u>db2_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_num_rows", QString("<u>db2_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_pclose", QString("<u>db2_pclose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_pconnect", QString("<u>db2_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_prepare", QString("<u>db2_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_primary_keys", QString("<u>db2_primary_keys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_procedure_columns", QString("<u>db2_procedure_columns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_procedures", QString("<u>db2_procedures</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_result", QString("<u>db2_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_rollback", QString("<u>db2_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_server_info", QString("<u>db2_server_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_set_option", QString("<u>db2_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_special_columns", QString("<u>db2_special_columns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_statistics", QString("<u>db2_statistics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_stmt_error", QString("<u>db2_stmt_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_stmt_errormsg", QString("<u>db2_stmt_errormsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_table_privileges", QString("<u>db2_table_privileges</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("db2_tables", QString("<u>db2_tables</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_close", QString("<u>dba_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_delete", QString("<u>dba_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_exists", QString("<u>dba_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_fetch", QString("<u>dba_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_firstkey", QString("<u>dba_firstkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_handlers", QString("<u>dba_handlers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_insert", QString("<u>dba_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_key_split", QString("<u>dba_key_split</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_list", QString("<u>dba_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_nextkey", QString("<u>dba_nextkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_open", QString("<u>dba_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_optimize", QString("<u>dba_optimize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_popen", QString("<u>dba_popen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_replace", QString("<u>dba_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dba_sync", QString("<u>dba_sync</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_add_record", QString("<u>dbase_add_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_close", QString("<u>dbase_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_create", QString("<u>dbase_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_delete_record", QString("<u>dbase_delete_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_get_header_info", QString("<u>dbase_get_header_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_get_record", QString("<u>dbase_get_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_get_record_with_names", QString("<u>dbase_get_record_with_names</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_numfields", QString("<u>dbase_numfields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_numrecords", QString("<u>dbase_numrecords</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_open", QString("<u>dbase_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_pack", QString("<u>dbase_pack</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbase_replace_record", QString("<u>dbase_replace_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_add", QString("<u>dbplus_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_aql", QString("<u>dbplus_aql</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_chdir", QString("<u>dbplus_chdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_close", QString("<u>dbplus_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_curr", QString("<u>dbplus_curr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_errcode", QString("<u>dbplus_errcode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_errno", QString("<u>dbplus_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_find", QString("<u>dbplus_find</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_first", QString("<u>dbplus_first</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_flush", QString("<u>dbplus_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_freealllocks", QString("<u>dbplus_freealllocks</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_freelock", QString("<u>dbplus_freelock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_freerlocks", QString("<u>dbplus_freerlocks</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_getlock", QString("<u>dbplus_getlock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_getunique", QString("<u>dbplus_getunique</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_info", QString("<u>dbplus_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_last", QString("<u>dbplus_last</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_lockrel", QString("<u>dbplus_lockrel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_next", QString("<u>dbplus_next</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_open", QString("<u>dbplus_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_prev", QString("<u>dbplus_prev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rchperm", QString("<u>dbplus_rchperm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rcreate", QString("<u>dbplus_rcreate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rcrtexact", QString("<u>dbplus_rcrtexact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rcrtlike", QString("<u>dbplus_rcrtlike</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_resolve", QString("<u>dbplus_resolve</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_restorepos", QString("<u>dbplus_restorepos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rkeys", QString("<u>dbplus_rkeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_ropen", QString("<u>dbplus_ropen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rquery", QString("<u>dbplus_rquery</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rrename", QString("<u>dbplus_rrename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rsecindex", QString("<u>dbplus_rsecindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_runlink", QString("<u>dbplus_runlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_rzap", QString("<u>dbplus_rzap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_savepos", QString("<u>dbplus_savepos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_setindex", QString("<u>dbplus_setindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_setindexbynumber", QString("<u>dbplus_setindexbynumber</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_sql", QString("<u>dbplus_sql</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_tcl", QString("<u>dbplus_tcl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_tremove", QString("<u>dbplus_tremove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_undo", QString("<u>dbplus_undo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_undoprepare", QString("<u>dbplus_undoprepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_unlockrel", QString("<u>dbplus_unlockrel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_unselect", QString("<u>dbplus_unselect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_update", QString("<u>dbplus_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_xlockrel", QString("<u>dbplus_xlockrel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbplus_xunlockrel", QString("<u>dbplus_xunlockrel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_close", QString("<u>dbx_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_compare", QString("<u>dbx_compare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_connect", QString("<u>dbx_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_error", QString("<u>dbx_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_escape_string", QString("<u>dbx_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_fetch_row", QString("<u>dbx_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_query", QString("<u>dbx_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dbx_sort", QString("<u>dbx_sort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dcgettext", QString("<u>dcgettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dcngettext", QString("<u>dcngettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("deaggregate", QString("<u>deaggregate</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("debug_backtrace", QString("array <u>debug_backtrace</u>(<b>[ int $options = DEBUG_BACKTRACE_PROVIDE_OBJECT [, int $limit = 0 ]]</b>) <br />%1").arg(tr("Generates a backtrace.")));
//  data.insert("debug_print_backtrace", QString("<u>debug_print_backtrace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("debug_zval_dump", QString("<u>debug_zval_dump</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("decbin", QString("<u>decbin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dechex", QString("<u>dechex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("decoct", QString("<u>decoct</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("define", QString("bool <u>define</u>(<b>string $name, mixed $value [, bool $case_insensitive = false ]</b>) <br />%1").arg(tr("Defines a named constant")));
//  data.insert("define_syslog_variables", QString("<u>define_syslog_variables</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("defined", QString("<u>defined</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("deg2rad", QString("<u>deg2rad</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("delete", QString("<u>delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dgettext", QString("<u>dgettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("die", QString("<u>die</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_close", QString("<u>dio_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_fcntl", QString("<u>dio_fcntl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_open", QString("<u>dio_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_read", QString("<u>dio_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_seek", QString("<u>dio_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_stat", QString("<u>dio_stat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_tcsetattr", QString("<u>dio_tcsetattr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_truncate", QString("<u>dio_truncate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dio_write", QString("<u>dio_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dir", QString("<u>dir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("directoryiterator", QString("<u>directoryiterator</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("dirname", QString("string <u>dirname</u>(<b>string $path</b>) <br />%1").arg(tr("Returns parent directory's path")));
//  data.insert("disk_total_space", QString("<u>disk_total_space</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("disk_free_space", QString("<u>disk_free_space</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("diskfreespace", QString("<u>diskfreespace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dl", QString("<u>dl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dngettext", QString("<u>dngettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dns_check_record", QString("<u>dns_check_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dns_get_mx", QString("<u>dns_get_mx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dns_get_record", QString("<u>dns_get_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dom_import_simplexml", QString("<u>dom_import_simplexml</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domainexception", QString("<u>domainexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domattr", QString("<u>domattr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domattribute_name", QString("<u>domattribute_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domattribute_set_value", QString("<u>domattribute_set_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domattribute_specified", QString("<u>domattribute_specified</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domattribute_value", QString("<u>domattribute_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domcdatasection", QString("<u>domcdatasection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domcharacterdata", QString("<u>domcharacterdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domcomment", QString("<u>domcomment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument", QString("<u>domdocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_add_root", QString("<u>domdocument_add_root</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_attribute", QString("<u>domdocument_create_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_cdata_section", QString("<u>domdocument_create_cdata_section</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_comment", QString("<u>domdocument_create_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_element", QString("<u>domdocument_create_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_element_ns", QString("<u>domdocument_create_element_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_entity_reference", QString("<u>domdocument_create_entity_reference</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_processing_instruction", QString("<u>domdocument_create_processing_instruction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_create_text_node", QString("<u>domdocument_create_text_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_doctype", QString("<u>domdocument_doctype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_document_element", QString("<u>domdocument_document_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_dump_file", QString("<u>domdocument_dump_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_dump_mem", QString("<u>domdocument_dump_mem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_get_element_by_id", QString("<u>domdocument_get_element_by_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_get_elements_by_tagname", QString("<u>domdocument_get_elements_by_tagname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_html_dump_mem", QString("<u>domdocument_html_dump_mem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocument_xinclude", QString("<u>domdocument_xinclude</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumentfragment", QString("<u>domdocumentfragment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype", QString("<u>domdocumenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype_entities", QString("<u>domdocumenttype_entities</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype_internal_subset", QString("<u>domdocumenttype_internal_subset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype_name", QString("<u>domdocumenttype_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype_notations", QString("<u>domdocumenttype_notations</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype_public_id", QString("<u>domdocumenttype_public_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domdocumenttype_system_id", QString("<u>domdocumenttype_system_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement", QString("<u>domelement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_get_attribute", QString("<u>domelement_get_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_get_attribute_node", QString("<u>domelement_get_attribute_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_get_elements_by_tagname", QString("<u>domelement_get_elements_by_tagname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_has_attribute", QString("<u>domelement_has_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_remove_attribute", QString("<u>domelement_remove_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_set_attribute", QString("<u>domelement_set_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_set_attribute_node", QString("<u>domelement_set_attribute_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domelement_tagname", QString("<u>domelement_tagname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domentity", QString("<u>domentity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domentityreference", QString("<u>domentityreference</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domexception", QString("<u>domexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domimplementation", QString("<u>domimplementation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnamednodemap", QString("<u>domnamednodemap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode", QString("<u>domnode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_add_namespace", QString("<u>domnode_add_namespace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_append_child", QString("<u>domnode_append_child</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_append_sibling", QString("<u>domnode_append_sibling</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_attributes", QString("<u>domnode_attributes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_child_nodes", QString("<u>domnode_child_nodes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_clone_node", QString("<u>domnode_clone_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_dump_node", QString("<u>domnode_dump_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_first_child", QString("<u>domnode_first_child</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_get_content", QString("<u>domnode_get_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_has_attributes", QString("<u>domnode_has_attributes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_has_child_nodes", QString("<u>domnode_has_child_nodes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_insert_before", QString("<u>domnode_insert_before</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_is_blank_node", QString("<u>domnode_is_blank_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_last_child", QString("<u>domnode_last_child</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_next_sibling", QString("<u>domnode_next_sibling</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_node_name", QString("<u>domnode_node_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_node_type", QString("<u>domnode_node_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_node_value", QString("<u>domnode_node_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_owner_document", QString("<u>domnode_owner_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_parent_node", QString("<u>domnode_parent_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_prefix", QString("<u>domnode_prefix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_previous_sibling", QString("<u>domnode_previous_sibling</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_remove_child", QString("<u>domnode_remove_child</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_replace_child", QString("<u>domnode_replace_child</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_replace_node", QString("<u>domnode_replace_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_set_content", QString("<u>domnode_set_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_set_name", QString("<u>domnode_set_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_set_namespace", QString("<u>domnode_set_namespace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnode_unlink_node", QString("<u>domnode_unlink_node</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnodelist", QString("<u>domnodelist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domnotation", QString("<u>domnotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domprocessinginstruction", QString("<u>domprocessinginstruction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domprocessinginstruction_data", QString("<u>domprocessinginstruction_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domprocessinginstruction_target", QString("<u>domprocessinginstruction_target</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domtext", QString("<u>domtext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_new_doc", QString("<u>domxml_new_doc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_open_file", QString("<u>domxml_open_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_open_mem", QString("<u>domxml_open_mem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_version", QString("<u>domxml_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_xmltree", QString("<u>domxml_xmltree</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_xslt_stylesheet", QString("<u>domxml_xslt_stylesheet</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_xslt_stylesheet_doc", QString("<u>domxml_xslt_stylesheet_doc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_xslt_stylesheet_file", QString("<u>domxml_xslt_stylesheet_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxml_xslt_version", QString("<u>domxml_xslt_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxpath", QString("<u>domxpath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxsltstylesheet_process", QString("<u>domxsltstylesheet_process</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxsltstylesheet_result_dump_file", QString("<u>domxsltstylesheet_result_dump_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("domxsltstylesheet_result_dump_mem", QString("<u>domxsltstylesheet_result_dump_mem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dotnet", QString("<u>dotnet</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("dotnet_load", QString("<u>dotnet_load</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("doubleval", QString("<u>doubleval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("each", QString("<u>each</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("easter_date", QString("<u>easter_date</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("easter_days", QString("<u>easter_days</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("echo", QString("void <u>echo</u>(<b>string $arg1 [, string $... ]</b>) <br />%1").arg(tr("Output one or more strings")));
//  data.insert("eio_busy", QString("<u>eio_busy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_cancel", QString("<u>eio_cancel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_chmod", QString("<u>eio_chmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_chown", QString("<u>eio_chown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_close", QString("<u>eio_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_custom", QString("<u>eio_custom</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_dup2", QString("<u>eio_dup2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_event_loop", QString("<u>eio_event_loop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fallocate", QString("<u>eio_fallocate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fchmod", QString("<u>eio_fchmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fchown", QString("<u>eio_fchown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fdatasync", QString("<u>eio_fdatasync</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fstat", QString("<u>eio_fstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fstatvfs", QString("<u>eio_fstatvfs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_fsync", QString("<u>eio_fsync</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_ftruncate", QString("<u>eio_ftruncate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_futime", QString("<u>eio_futime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_get_eventfd", QString("<u>eio_get_eventfd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_grp", QString("<u>eio_grp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_grp_add", QString("<u>eio_grp_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_grp_cancel", QString("<u>eio_grp_cancel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_grp_limit", QString("<u>eio_grp_limit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_link", QString("<u>eio_link</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_lstat", QString("<u>eio_lstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_mkdir", QString("<u>eio_mkdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_mknod", QString("<u>eio_mknod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_nop", QString("<u>eio_nop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_npending", QString("<u>eio_npending</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_nready", QString("<u>eio_nready</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_nreqs", QString("<u>eio_nreqs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_nthreads", QString("<u>eio_nthreads</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_open", QString("<u>eio_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_poll", QString("<u>eio_poll</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_read", QString("<u>eio_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_readahead", QString("<u>eio_readahead</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_readdir", QString("<u>eio_readdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_readlink", QString("<u>eio_readlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_realpath", QString("<u>eio_realpath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_rename", QString("<u>eio_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_rmdir", QString("<u>eio_rmdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_sendfile", QString("<u>eio_sendfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_set_max_idle", QString("<u>eio_set_max_idle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_set_max_parallel", QString("<u>eio_set_max_parallel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_set_max_poll_reqs", QString("<u>eio_set_max_poll_reqs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_set_max_poll_time", QString("<u>eio_set_max_poll_time</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_set_min_parallel", QString("<u>eio_set_min_parallel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_stat", QString("<u>eio_stat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_statvfs", QString("<u>eio_statvfs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_symlink", QString("<u>eio_symlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_sync", QString("<u>eio_sync</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_sync_file_range", QString("<u>eio_sync_file_range</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_syncfs", QString("<u>eio_syncfs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_truncate", QString("<u>eio_truncate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_unlink", QString("<u>eio_unlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_utime", QString("<u>eio_utime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eio_write", QString("<u>eio_write</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("empty", QString("bool <u>empty</u>(<b>mixed $var</b>) <br />%1").arg(tr("Determine whether a variable is empty")));
//  data.insert("emptyiterator", QString("<u>emptyiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_describe", QString("<u>enchant_broker_describe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_dict_exists", QString("<u>enchant_broker_dict_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_free", QString("<u>enchant_broker_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_free_dict", QString("<u>enchant_broker_free_dict</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_get_error", QString("<u>enchant_broker_get_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_init", QString("<u>enchant_broker_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_list_dicts", QString("<u>enchant_broker_list_dicts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_request_dict", QString("<u>enchant_broker_request_dict</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_request_pwl_dict", QString("<u>enchant_broker_request_pwl_dict</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_broker_set_ordering", QString("<u>enchant_broker_set_ordering</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_add_to_personal", QString("<u>enchant_dict_add_to_personal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_add_to_session", QString("<u>enchant_dict_add_to_session</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_check", QString("<u>enchant_dict_check</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_describe", QString("<u>enchant_dict_describe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_get_error", QString("<u>enchant_dict_get_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_is_in_session", QString("<u>enchant_dict_is_in_session</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_quick_check", QString("<u>enchant_dict_quick_check</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_store_replacement", QString("<u>enchant_dict_store_replacement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("enchant_dict_suggest", QString("<u>enchant_dict_suggest</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("end", QString("<u>end</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ereg", QString("<u>ereg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ereg_replace", QString("<u>ereg_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eregi", QString("<u>eregi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eregi_replace", QString("<u>eregi_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("error_get_last", QString("<u>error_get_last</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("error_log", QString("<u>error_log</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("error_reporting", QString("int <u>error_reporting</u>(<b>[int $level]</b>) <br />%1").arg(tr("Sets which PHP errors are reported.<br />E_ERROR, E_WARNING, E_PARSE, E_NOTICE, E_CORE_ERROR<br />, E_CORE_WARNING, E_COMPILE_ERROR, E_COMPILE_WARNING, E_USER_ERROR, E_USER_WARNING<br />, E_USER_NOTICE, E_STRICT, E_RECOVERABLE_ERROR, E_DEPRECATED, E_USER_DEPRECATED, E_ALL")));
//  data.insert("errorexception", QString("<u>errorexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("escapeshellarg", QString("<u>escapeshellarg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("escapeshellcmd", QString("<u>escapeshellcmd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("eval", QString("<u>eval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_add", QString("<u>event_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_free", QString("<u>event_base_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_loop", QString("<u>event_base_loop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_loopbreak", QString("<u>event_base_loopbreak</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_loopexit", QString("<u>event_base_loopexit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_new", QString("<u>event_base_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_priority_init", QString("<u>event_base_priority_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_base_set", QString("<u>event_base_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_base_set", QString("<u>event_buffer_base_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_disable", QString("<u>event_buffer_disable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_enable", QString("<u>event_buffer_enable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_fd_set", QString("<u>event_buffer_fd_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_free", QString("<u>event_buffer_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_new", QString("<u>event_buffer_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_priority_set", QString("<u>event_buffer_priority_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_read", QString("<u>event_buffer_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_set_callback", QString("<u>event_buffer_set_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_timeout_set", QString("<u>event_buffer_timeout_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_watermark_set", QString("<u>event_buffer_watermark_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_buffer_write", QString("<u>event_buffer_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_del", QString("<u>event_del</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_free", QString("<u>event_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_new", QString("<u>event_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("event_set", QString("<u>event_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exec", QString("<u>exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exif_imagetype", QString("<u>exif_imagetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exif_read_data", QString("<u>exif_read_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exif_tagname", QString("<u>exif_tagname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exif_thumbnail", QString("<u>exif_thumbnail</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exit", QString("<u>exit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("exp", QString("<u>exp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("expect_expectl", QString("<u>expect_expectl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("expect_popen", QString("<u>expect_popen</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("explode", QString("array <u>explode</u>(<b>string $delimiter, string $string [, int $limit ]</b>) <br />%1").arg(tr("Split a string by string")));
//  data.insert("expm1", QString("<u>expm1</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("export", QString("<u>export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("export", QString("<u>export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("extension_loaded", QString("<u>extension_loaded</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("extract", QString("<u>extract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ezmlm_hash", QString("<u>ezmlm_hash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_cancel_monitor", QString("<u>fam_cancel_monitor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_close", QString("<u>fam_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_monitor_collection", QString("<u>fam_monitor_collection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_monitor_directory", QString("<u>fam_monitor_directory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_monitor_file", QString("<u>fam_monitor_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_next_event", QString("<u>fam_next_event</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_open", QString("<u>fam_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_pending", QString("<u>fam_pending</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_resume_monitor", QString("<u>fam_resume_monitor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fam_suspend_monitor", QString("<u>fam_suspend_monitor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_affected_rows", QString("<u>fbsql_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_autocommit", QString("<u>fbsql_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_blob_size", QString("<u>fbsql_blob_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_change_user", QString("<u>fbsql_change_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_clob_size", QString("<u>fbsql_clob_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_close", QString("<u>fbsql_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_commit", QString("<u>fbsql_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_connect", QString("<u>fbsql_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_create_blob", QString("<u>fbsql_create_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_create_clob", QString("<u>fbsql_create_clob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_create_db", QString("<u>fbsql_create_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_data_seek", QString("<u>fbsql_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_database", QString("<u>fbsql_database</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_database_password", QString("<u>fbsql_database_password</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_db_query", QString("<u>fbsql_db_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_db_status", QString("<u>fbsql_db_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_drop_db", QString("<u>fbsql_drop_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_errno", QString("<u>fbsql_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_error", QString("<u>fbsql_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_fetch_array", QString("<u>fbsql_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_fetch_assoc", QString("<u>fbsql_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_fetch_field", QString("<u>fbsql_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_fetch_lengths", QString("<u>fbsql_fetch_lengths</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_fetch_object", QString("<u>fbsql_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_fetch_row", QString("<u>fbsql_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_field_flags", QString("<u>fbsql_field_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_field_len", QString("<u>fbsql_field_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_field_name", QString("<u>fbsql_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_field_seek", QString("<u>fbsql_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_field_table", QString("<u>fbsql_field_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_field_type", QString("<u>fbsql_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_free_result", QString("<u>fbsql_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_get_autostart_info", QString("<u>fbsql_get_autostart_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_hostname", QString("<u>fbsql_hostname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_insert_id", QString("<u>fbsql_insert_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_list_dbs", QString("<u>fbsql_list_dbs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_list_fields", QString("<u>fbsql_list_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_list_tables", QString("<u>fbsql_list_tables</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_next_result", QString("<u>fbsql_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_num_fields", QString("<u>fbsql_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_num_rows", QString("<u>fbsql_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_password", QString("<u>fbsql_password</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_pconnect", QString("<u>fbsql_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_query", QString("<u>fbsql_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_read_blob", QString("<u>fbsql_read_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_read_clob", QString("<u>fbsql_read_clob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_result", QString("<u>fbsql_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_rollback", QString("<u>fbsql_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_rows_fetched", QString("<u>fbsql_rows_fetched</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_select_db", QString("<u>fbsql_select_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_set_characterset", QString("<u>fbsql_set_characterset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_set_lob_mode", QString("<u>fbsql_set_lob_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_set_password", QString("<u>fbsql_set_password</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_set_transaction", QString("<u>fbsql_set_transaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_start_db", QString("<u>fbsql_start_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_stop_db", QString("<u>fbsql_stop_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_table_name", QString("<u>fbsql_table_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_tablename", QString("<u>fbsql_tablename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_username", QString("<u>fbsql_username</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fbsql_warnings", QString("<u>fbsql_warnings</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("fclose", QString("bool <u>fclose</u>(<b>resource $handle</b>) <br />%1").arg(tr("Closes an open file pointer")));
//  data.insert("fdf_add_doc_javascript", QString("<u>fdf_add_doc_javascript</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_add_template", QString("<u>fdf_add_template</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_close", QString("<u>fdf_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_create", QString("<u>fdf_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_enum_values", QString("<u>fdf_enum_values</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_errno", QString("<u>fdf_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_error", QString("<u>fdf_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_ap", QString("<u>fdf_get_ap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_attachment", QString("<u>fdf_get_attachment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_encoding", QString("<u>fdf_get_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_file", QString("<u>fdf_get_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_flags", QString("<u>fdf_get_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_opt", QString("<u>fdf_get_opt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_status", QString("<u>fdf_get_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_value", QString("<u>fdf_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_get_version", QString("<u>fdf_get_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_header", QString("<u>fdf_header</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_next_field_name", QString("<u>fdf_next_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_open", QString("<u>fdf_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_open_string", QString("<u>fdf_open_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_remove_item", QString("<u>fdf_remove_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_save", QString("<u>fdf_save</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_save_string", QString("<u>fdf_save_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_ap", QString("<u>fdf_set_ap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_encoding", QString("<u>fdf_set_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_file", QString("<u>fdf_set_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_flags", QString("<u>fdf_set_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_javascript_action", QString("<u>fdf_set_javascript_action</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_on_import_javascript", QString("<u>fdf_set_on_import_javascript</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_opt", QString("<u>fdf_set_opt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_status", QString("<u>fdf_set_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_submit_form_action", QString("<u>fdf_set_submit_form_action</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_target_frame", QString("<u>fdf_set_target_frame</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_value", QString("<u>fdf_set_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fdf_set_version", QString("<u>fdf_set_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("feof", QString("<u>feof</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fflush", QString("<u>fflush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fgetc", QString("<u>fgetc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fgetcsv", QString("<u>fgetcsv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fgets", QString("<u>fgets</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fgetss", QString("<u>fgetss</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("file", QString("array <u>file</u>(<b>string $filename [, int $flags = 0 [, resource $context ]]</b>) <br />%1").arg(tr("Reads entire file into an array")));
  data.insert("file_exists", QString("bool <u>file_exists</u>(<b>string $filename</b>) <br />%1").arg(tr("Checks whether a file or directory exists")));
  data.insert("file_get_contents", QString("string <u>file_get_contents</u>(<b>string $filename [, bool $use_include_path = false [, resource $context [, int $offset = -1 [, int $maxlen ]]]]</b>) <br />%1").arg(tr("Reads entire file into a string")));
  data.insert("file_put_contents", QString("int <u>file_put_contents</u>(<b>string $filename, mixed $data [, int $flags = 0 [, resource $context ]]</b>) <br />%1").arg(tr("Write a string to a file")));
//  data.insert("fileatime", QString("<u>fileatime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filectime", QString("<u>filectime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filegroup", QString("<u>filegroup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fileinode", QString("<u>fileinode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filemtime", QString("<u>filemtime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fileowner", QString("<u>fileowner</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fileperms", QString("<u>fileperms</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro", QString("<u>filepro</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro_fieldcount", QString("<u>filepro_fieldcount</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro_fieldname", QString("<u>filepro_fieldname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro_fieldtype", QString("<u>filepro_fieldtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro_fieldwidth", QString("<u>filepro_fieldwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro_retrieve", QString("<u>filepro_retrieve</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filepro_rowcount", QString("<u>filepro_rowcount</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("filesize", QString("int <u>filesize</u>(<b>string $filename</b>) <br />%1").arg(tr("Gets file size")));
//  data.insert("filesystemiterator", QString("<u>filesystemiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filetype", QString("<u>filetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filter_has_var", QString("<u>filter_has_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filter_id", QString("<u>filter_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filter_input", QString("<u>filter_input</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filter_input_array", QString("<u>filter_input_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filter_list", QString("<u>filter_list</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("filter_var", QString("mixed <u>filter_var</u>(<b>mixed $variable [, int $filter = FILTER_DEFAULT [, mixed $options ]]</b>) <br />%1").arg(tr("Filters a variable with a specified filter")));
//  data.insert("filter_var_array", QString("<u>filter_var_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("filteriterator", QString("<u>filteriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("finfo_buffer", QString("<u>finfo_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("finfo_close", QString("<u>finfo_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("finfo_file", QString("<u>finfo_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("finfo_open", QString("<u>finfo_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("finfo_set_flags", QString("<u>finfo_set_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("floatval", QString("<u>floatval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("flock", QString("<u>flock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("floor", QString("<u>floor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("flush", QString("<u>flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fmod", QString("<u>fmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fnmatch", QString("<u>fnmatch</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("fopen", QString("resourse <u>fopen</u>(<b>string $filename, string $mode [, bool $use_include_path = false [, resource $context ]]</b>) <br />%1").arg(tr("Opens file or URL")));
//  data.insert("forward_static_call", QString("<u>forward_static_call</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("forward_static_call_array", QString("<u>forward_static_call_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fpassthru", QString("<u>fpassthru</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fprintf", QString("<u>fprintf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fputcsv", QString("<u>fputcsv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fputs", QString("<u>fputs</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("fread", QString("string <u>fread</u>(<b>resource $handle, int $length</b>) <br />%1").arg(tr("Binary-safe file read")));
//  data.insert("frenchtojd", QString("<u>frenchtojd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fribidi_log2vis", QString("<u>fribidi_log2vis</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fscanf", QString("<u>fscanf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fseek", QString("<u>fseek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fsockopen", QString("<u>fsockopen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("fstat", QString("<u>fstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftell", QString("<u>ftell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftok", QString("<u>ftok</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_alloc", QString("<u>ftp_alloc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_cdup", QString("<u>ftp_cdup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_chdir", QString("<u>ftp_chdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_chmod", QString("<u>ftp_chmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_close", QString("<u>ftp_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_connect", QString("<u>ftp_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_delete", QString("<u>ftp_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_exec", QString("<u>ftp_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_fget", QString("<u>ftp_fget</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_fput", QString("<u>ftp_fput</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_get", QString("<u>ftp_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_get_option", QString("<u>ftp_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_login", QString("<u>ftp_login</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_mdtm", QString("<u>ftp_mdtm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_mkdir", QString("<u>ftp_mkdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_nb_continue", QString("<u>ftp_nb_continue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_nb_fget", QString("<u>ftp_nb_fget</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_nb_fput", QString("<u>ftp_nb_fput</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_nb_get", QString("<u>ftp_nb_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_nb_put", QString("<u>ftp_nb_put</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_nlist", QString("<u>ftp_nlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_pasv", QString("<u>ftp_pasv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_put", QString("<u>ftp_put</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_pwd", QString("<u>ftp_pwd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_quit", QString("<u>ftp_quit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_raw", QString("<u>ftp_raw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_rawlist", QString("<u>ftp_rawlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_rename", QString("<u>ftp_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_rmdir", QString("<u>ftp_rmdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_set_option", QString("<u>ftp_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_site", QString("<u>ftp_site</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_size", QString("<u>ftp_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_ssl_connect", QString("<u>ftp_ssl_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftp_systype", QString("<u>ftp_systype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ftruncate", QString("<u>ftruncate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("func_get_arg", QString("<u>func_get_arg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("func_get_args", QString("<u>func_get_args</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("func_num_args", QString("<u>func_num_args</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("function_exists", QString("bool <u>function_exists</u>(<b>string $function_name</b>) <br />%1").arg(tr("Checks the list of defined functions, both built-in (internal) and user-defined, for function_name.")));
  data.insert("fwrite", QString("int <u>fwrite</u>(<b>resource $handle, string $string [, int $length ]</b>) <br />%1").arg(tr("Binary-safe file write.")));
//  data.insert("gc_collect_cycles", QString("<u>gc_collect_cycles</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gc_disable", QString("<u>gc_disable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gc_enable", QString("<u>gc_enable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gc_enabled", QString("<u>gc_enabled</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gd_info", QString("<u>gd_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gearmanclient", QString("<u>gearmanclient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gearmanjob", QString("<u>gearmanjob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gearmantask", QString("<u>gearmantask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gearmanworker", QString("<u>gearmanworker</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_continent_code_by_name", QString("<u>geoip_continent_code_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_country_code3_by_name", QString("<u>geoip_country_code3_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_country_code_by_name", QString("<u>geoip_country_code_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_country_name_by_name", QString("<u>geoip_country_name_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_database_info", QString("<u>geoip_database_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_db_avail", QString("<u>geoip_db_avail</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_db_filename", QString("<u>geoip_db_filename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_db_get_all_info", QString("<u>geoip_db_get_all_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_id_by_name", QString("<u>geoip_id_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_isp_by_name", QString("<u>geoip_isp_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_org_by_name", QString("<u>geoip_org_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_record_by_name", QString("<u>geoip_record_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_region_by_name", QString("<u>geoip_region_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_region_name_by_code", QString("<u>geoip_region_name_by_code</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("geoip_time_zone_by_country_and_region", QString("<u>geoip_time_zone_by_country_and_region</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getMeta", QString("<u>getMeta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getNamed", QString("<u>getNamed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getValue", QString("<u>getValue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_browser", QString("<u>get_browser</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_called_class", QString("<u>get_called_class</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_cfg_var", QString("<u>get_cfg_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_class", QString("<u>get_class</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_class_methods", QString("<u>get_class_methods</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_class_vars", QString("<u>get_class_vars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_current_user", QString("<u>get_current_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_declared_classes", QString("<u>get_declared_classes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_declared_interfaces", QString("<u>get_declared_interfaces</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_defined_constants", QString("<u>get_defined_constants</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_defined_functions", QString("<u>get_defined_functions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_defined_vars", QString("<u>get_defined_vars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_extension_funcs", QString("<u>get_extension_funcs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_headers", QString("<u>get_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_html_translation_table", QString("<u>get_html_translation_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_include_path", QString("<u>get_include_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_included_files", QString("<u>get_included_files</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_loaded_extensions", QString("<u>get_loaded_extensions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_magic_quotes_gpc", QString("<u>get_magic_quotes_gpc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_magic_quotes_runtime", QString("<u>get_magic_quotes_runtime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_meta_tags", QString("<u>get_meta_tags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_object_vars", QString("<u>get_object_vars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_parent_class", QString("<u>get_parent_class</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_required_files", QString("<u>get_required_files</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("get_resource_type", QString("<u>get_resource_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getallheaders", QString("<u>getallheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getclosure", QString("<u>getclosure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getconstant", QString("<u>getconstant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getconstants", QString("<u>getconstants</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getconstructor", QString("<u>getconstructor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getcwd", QString("<u>getcwd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getdate", QString("<u>getdate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getdefaultproperties", QString("<u>getdefaultproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getdoccomment", QString("<u>getdoccomment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getendline", QString("<u>getendline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getenv", QString("<u>getenv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getextension", QString("<u>getextension</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getextensionname", QString("<u>getextensionname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getfilename", QString("<u>getfilename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gethostbyaddr", QString("<u>gethostbyaddr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gethostbyname", QString("<u>gethostbyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gethostbynamel", QString("<u>gethostbynamel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gethostname", QString("<u>gethostname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getimagesize", QString("<u>getimagesize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getinterfacenames", QString("<u>getinterfacenames</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getinterfaces", QString("<u>getinterfaces</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getlastmod", QString("<u>getlastmod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmethod", QString("<u>getmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmethods", QString("<u>getmethods</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmodifiers", QString("<u>getmodifiers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmxrr", QString("<u>getmxrr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmygid", QString("<u>getmygid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmyinode", QString("<u>getmyinode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmypid", QString("<u>getmypid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getmyuid", QString("<u>getmyuid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getname", QString("<u>getname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getnamespacename", QString("<u>getnamespacename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getopt", QString("<u>getopt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getparentclass", QString("<u>getparentclass</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getproperties", QString("<u>getproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getproperty", QString("<u>getproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getprotobyname", QString("<u>getprotobyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getprotobynumber", QString("<u>getprotobynumber</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getrandmax", QString("<u>getrandmax</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getrusage", QString("<u>getrusage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getservbyname", QString("<u>getservbyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getservbyport", QString("<u>getservbyport</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getshortname", QString("<u>getshortname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getstartline", QString("<u>getstartline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getstaticproperties", QString("<u>getstaticproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("getstaticpropertyvalue", QString("<u>getstaticpropertyvalue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gettext", QString("<u>gettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gettimeofday", QString("<u>gettimeofday</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gettraitaliases", QString("<u>gettraitaliases</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gettraitnames", QString("<u>gettraitnames</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gettraits", QString("<u>gettraits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gettype", QString("<u>gettype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("glob", QString("<u>glob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("globiterator", QString("<u>globiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmagick", QString("<u>gmagick</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmagickdraw", QString("<u>gmagickdraw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmagickpixel", QString("<u>gmagickpixel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmdate", QString("<u>gmdate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmmktime", QString("<u>gmmktime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_abs", QString("<u>gmp_abs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_add", QString("<u>gmp_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_and", QString("<u>gmp_and</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_clrbit", QString("<u>gmp_clrbit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_cmp", QString("<u>gmp_cmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_com", QString("<u>gmp_com</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_div", QString("<u>gmp_div</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_div_q", QString("<u>gmp_div_q</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_div_qr", QString("<u>gmp_div_qr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_div_r", QString("<u>gmp_div_r</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_divexact", QString("<u>gmp_divexact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_fact", QString("<u>gmp_fact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_gcd", QString("<u>gmp_gcd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_gcdext", QString("<u>gmp_gcdext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_hamdist", QString("<u>gmp_hamdist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_init", QString("<u>gmp_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_intval", QString("<u>gmp_intval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_invert", QString("<u>gmp_invert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_jacobi", QString("<u>gmp_jacobi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_legendre", QString("<u>gmp_legendre</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_mod", QString("<u>gmp_mod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_mul", QString("<u>gmp_mul</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_neg", QString("<u>gmp_neg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_nextprime", QString("<u>gmp_nextprime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_or", QString("<u>gmp_or</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_perfect_square", QString("<u>gmp_perfect_square</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_popcount", QString("<u>gmp_popcount</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_pow", QString("<u>gmp_pow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_powm", QString("<u>gmp_powm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_prob_prime", QString("<u>gmp_prob_prime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_random", QString("<u>gmp_random</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_scan0", QString("<u>gmp_scan0</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_scan1", QString("<u>gmp_scan1</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_setbit", QString("<u>gmp_setbit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_sign", QString("<u>gmp_sign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_sqrt", QString("<u>gmp_sqrt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_sqrtrem", QString("<u>gmp_sqrtrem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_strval", QString("<u>gmp_strval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_sub", QString("<u>gmp_sub</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_testbit", QString("<u>gmp_testbit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmp_xor", QString("<u>gmp_xor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gmstrftime", QString("<u>gmstrftime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_adddecryptkey", QString("<u>gnupg_adddecryptkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_addencryptkey", QString("<u>gnupg_addencryptkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_addsignkey", QString("<u>gnupg_addsignkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_cleardecryptkeys", QString("<u>gnupg_cleardecryptkeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_clearencryptkeys", QString("<u>gnupg_clearencryptkeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_clearsignkeys", QString("<u>gnupg_clearsignkeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_decrypt", QString("<u>gnupg_decrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_decryptverify", QString("<u>gnupg_decryptverify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_encrypt", QString("<u>gnupg_encrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_encryptsign", QString("<u>gnupg_encryptsign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_export", QString("<u>gnupg_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_geterror", QString("<u>gnupg_geterror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_getprotocol", QString("<u>gnupg_getprotocol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_import", QString("<u>gnupg_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_init", QString("<u>gnupg_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_keyinfo", QString("<u>gnupg_keyinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_setarmor", QString("<u>gnupg_setarmor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_seterrormode", QString("<u>gnupg_seterrormode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_setsignmode", QString("<u>gnupg_setsignmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_sign", QString("<u>gnupg_sign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gnupg_verify", QString("<u>gnupg_verify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gopher_parsedir", QString("<u>gopher_parsedir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_extract", QString("<u>grapheme_extract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_stripos", QString("<u>grapheme_stripos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_stristr", QString("<u>grapheme_stristr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_strlen", QString("<u>grapheme_strlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_strpos", QString("<u>grapheme_strpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_strripos", QString("<u>grapheme_strripos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_strrpos", QString("<u>grapheme_strrpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_strstr", QString("<u>grapheme_strstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("grapheme_substr", QString("<u>grapheme_substr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gregoriantojd", QString("<u>gregoriantojd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_get_host_ip", QString("<u>gupnp_context_get_host_ip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_get_port", QString("<u>gupnp_context_get_port</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_get_subscription_timeout", QString("<u>gupnp_context_get_subscription_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_host_path", QString("<u>gupnp_context_host_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_new", QString("<u>gupnp_context_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_set_subscription_timeout", QString("<u>gupnp_context_set_subscription_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_timeout_add", QString("<u>gupnp_context_timeout_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_context_unhost_path", QString("<u>gupnp_context_unhost_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_control_point_browse_start", QString("<u>gupnp_control_point_browse_start</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_control_point_browse_stop", QString("<u>gupnp_control_point_browse_stop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_control_point_callback_set", QString("<u>gupnp_control_point_callback_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_control_point_new", QString("<u>gupnp_control_point_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_device_action_callback_set", QString("<u>gupnp_device_action_callback_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_device_info_get", QString("<u>gupnp_device_info_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_device_info_get_service", QString("<u>gupnp_device_info_get_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_root_device_get_available", QString("<u>gupnp_root_device_get_available</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_root_device_get_relative_location", QString("<u>gupnp_root_device_get_relative_location</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_root_device_new", QString("<u>gupnp_root_device_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_root_device_set_available", QString("<u>gupnp_root_device_set_available</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_root_device_start", QString("<u>gupnp_root_device_start</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_root_device_stop", QString("<u>gupnp_root_device_stop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_action_get", QString("<u>gupnp_service_action_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_action_return", QString("<u>gupnp_service_action_return</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_action_return_error", QString("<u>gupnp_service_action_return_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_action_set", QString("<u>gupnp_service_action_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_freeze_notify", QString("<u>gupnp_service_freeze_notify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_info_get", QString("<u>gupnp_service_info_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_info_get_introspection", QString("<u>gupnp_service_info_get_introspection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_introspection_get_state_variable", QString("<u>gupnp_service_introspection_get_state_variable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_notify", QString("<u>gupnp_service_notify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_action_get", QString("<u>gupnp_service_proxy_action_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_action_set", QString("<u>gupnp_service_proxy_action_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_add_notify", QString("<u>gupnp_service_proxy_add_notify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_callback_set", QString("<u>gupnp_service_proxy_callback_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_get_subscribed", QString("<u>gupnp_service_proxy_get_subscribed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_remove_notify", QString("<u>gupnp_service_proxy_remove_notify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_proxy_set_subscribed", QString("<u>gupnp_service_proxy_set_subscribed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gupnp_service_thaw_notify", QString("<u>gupnp_service_thaw_notify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzclose", QString("<u>gzclose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzcompress", QString("<u>gzcompress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzdecode", QString("<u>gzdecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzdeflate", QString("<u>gzdeflate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzencode", QString("<u>gzencode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzeof", QString("<u>gzeof</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzfile", QString("<u>gzfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzgetc", QString("<u>gzgetc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzgets", QString("<u>gzgets</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzgetss", QString("<u>gzgetss</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzinflate", QString("<u>gzinflate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzopen", QString("<u>gzopen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzpassthru", QString("<u>gzpassthru</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzputs", QString("<u>gzputs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzread", QString("<u>gzread</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzrewind", QString("<u>gzrewind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzseek", QString("<u>gzseek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gztell", QString("<u>gztell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzuncompress", QString("<u>gzuncompress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("gzwrite", QString("<u>gzwrite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("halt_compiler", QString("<u>halt_compiler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruannotation", QString("<u>haruannotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruannotation_setborderstyle", QString("<u>haruannotation_setborderstyle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruannotation_sethighlightmode", QString("<u>haruannotation_sethighlightmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruannotation_seticon", QString("<u>haruannotation_seticon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruannotation_setopened", QString("<u>haruannotation_setopened</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination", QString("<u>harudestination</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfit", QString("<u>harudestination_setfit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfitb", QString("<u>harudestination_setfitb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfitbh", QString("<u>harudestination_setfitbh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfitbv", QString("<u>harudestination_setfitbv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfith", QString("<u>harudestination_setfith</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfitr", QString("<u>harudestination_setfitr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setfitv", QString("<u>harudestination_setfitv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudestination_setxyz", QString("<u>harudestination_setxyz</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc", QString("<u>harudoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_addpage", QString("<u>harudoc_addpage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_addpagelabel", QString("<u>harudoc_addpagelabel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_construct", QString("<u>harudoc_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_createoutline", QString("<u>harudoc_createoutline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getcurrentencoder", QString("<u>harudoc_getcurrentencoder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getcurrentpage", QString("<u>harudoc_getcurrentpage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getencoder", QString("<u>harudoc_getencoder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getfont", QString("<u>harudoc_getfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getinfoattr", QString("<u>harudoc_getinfoattr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getpagelayout", QString("<u>harudoc_getpagelayout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getpagemode", QString("<u>harudoc_getpagemode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_getstreamsize", QString("<u>harudoc_getstreamsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_insertpage", QString("<u>harudoc_insertpage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_loadjpeg", QString("<u>harudoc_loadjpeg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_loadpng", QString("<u>harudoc_loadpng</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_loadraw", QString("<u>harudoc_loadraw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_loadttc", QString("<u>harudoc_loadttc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_loadttf", QString("<u>harudoc_loadttf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_loadtype1", QString("<u>harudoc_loadtype1</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_output", QString("<u>harudoc_output</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_readfromstream", QString("<u>harudoc_readfromstream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_reseterror", QString("<u>harudoc_reseterror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_resetstream", QString("<u>harudoc_resetstream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_save", QString("<u>harudoc_save</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_savetostream", QString("<u>harudoc_savetostream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setcompressionmode", QString("<u>harudoc_setcompressionmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setcurrentencoder", QString("<u>harudoc_setcurrentencoder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setencryptionmode", QString("<u>harudoc_setencryptionmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setinfoattr", QString("<u>harudoc_setinfoattr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setinfodateattr", QString("<u>harudoc_setinfodateattr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setopenaction", QString("<u>harudoc_setopenaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setpagelayout", QString("<u>harudoc_setpagelayout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setpagemode", QString("<u>harudoc_setpagemode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setpagesconfiguration", QString("<u>harudoc_setpagesconfiguration</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setpassword", QString("<u>harudoc_setpassword</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_setpermission", QString("<u>harudoc_setpermission</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usecnsencodings", QString("<u>harudoc_usecnsencodings</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usecnsfonts", QString("<u>harudoc_usecnsfonts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usecntencodings", QString("<u>harudoc_usecntencodings</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usecntfonts", QString("<u>harudoc_usecntfonts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usejpencodings", QString("<u>harudoc_usejpencodings</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usejpfonts", QString("<u>harudoc_usejpfonts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usekrencodings", QString("<u>harudoc_usekrencodings</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harudoc_usekrfonts", QString("<u>harudoc_usekrfonts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruencoder", QString("<u>haruencoder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruencoder_getbytetype", QString("<u>haruencoder_getbytetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruencoder_gettype", QString("<u>haruencoder_gettype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruencoder_getunicode", QString("<u>haruencoder_getunicode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruencoder_getwritingmode", QString("<u>haruencoder_getwritingmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruexception", QString("<u>haruexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont", QString("<u>harufont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getascent", QString("<u>harufont_getascent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getcapheight", QString("<u>harufont_getcapheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getdescent", QString("<u>harufont_getdescent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getencodingname", QString("<u>harufont_getencodingname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getfontname", QString("<u>harufont_getfontname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_gettextwidth", QString("<u>harufont_gettextwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getunicodewidth", QString("<u>harufont_getunicodewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_getxheight", QString("<u>harufont_getxheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harufont_measuretext", QString("<u>harufont_measuretext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage", QString("<u>haruimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_getbitspercomponent", QString("<u>haruimage_getbitspercomponent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_getcolorspace", QString("<u>haruimage_getcolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_getheight", QString("<u>haruimage_getheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_getsize", QString("<u>haruimage_getsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_getwidth", QString("<u>haruimage_getwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_setcolormask", QString("<u>haruimage_setcolormask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruimage_setmaskimage", QString("<u>haruimage_setmaskimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruoutline", QString("<u>haruoutline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruoutline_setdestination", QString("<u>haruoutline_setdestination</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("haruoutline_setopened", QString("<u>haruoutline_setopened</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage", QString("<u>harupage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_arc", QString("<u>harupage_arc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_begintext", QString("<u>harupage_begintext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_circle", QString("<u>harupage_circle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_closepath", QString("<u>harupage_closepath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_concat", QString("<u>harupage_concat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_createdestination", QString("<u>harupage_createdestination</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_createlinkannotation", QString("<u>harupage_createlinkannotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_createtextannotation", QString("<u>harupage_createtextannotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_createurlannotation", QString("<u>harupage_createurlannotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_curveto", QString("<u>harupage_curveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_curveto2", QString("<u>harupage_curveto2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_curveto3", QString("<u>harupage_curveto3</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_drawimage", QString("<u>harupage_drawimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_ellipse", QString("<u>harupage_ellipse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_endpath", QString("<u>harupage_endpath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_endtext", QString("<u>harupage_endtext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_eofill", QString("<u>harupage_eofill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_eofillstroke", QString("<u>harupage_eofillstroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_fill", QString("<u>harupage_fill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_fillstroke", QString("<u>harupage_fillstroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcharspace", QString("<u>harupage_getcharspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcmykfill", QString("<u>harupage_getcmykfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcmykstroke", QString("<u>harupage_getcmykstroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcurrentfont", QString("<u>harupage_getcurrentfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcurrentfontsize", QString("<u>harupage_getcurrentfontsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcurrentpos", QString("<u>harupage_getcurrentpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getcurrenttextpos", QString("<u>harupage_getcurrenttextpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getdash", QString("<u>harupage_getdash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getfillingcolorspace", QString("<u>harupage_getfillingcolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getflatness", QString("<u>harupage_getflatness</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getgmode", QString("<u>harupage_getgmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getgrayfill", QString("<u>harupage_getgrayfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getgraystroke", QString("<u>harupage_getgraystroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getheight", QString("<u>harupage_getheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gethorizontalscaling", QString("<u>harupage_gethorizontalscaling</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getlinecap", QString("<u>harupage_getlinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getlinejoin", QString("<u>harupage_getlinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getlinewidth", QString("<u>harupage_getlinewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getmiterlimit", QString("<u>harupage_getmiterlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getrgbfill", QString("<u>harupage_getrgbfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getrgbstroke", QString("<u>harupage_getrgbstroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getstrokingcolorspace", QString("<u>harupage_getstrokingcolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gettextleading", QString("<u>harupage_gettextleading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gettextmatrix", QString("<u>harupage_gettextmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gettextrenderingmode", QString("<u>harupage_gettextrenderingmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gettextrise", QString("<u>harupage_gettextrise</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gettextwidth", QString("<u>harupage_gettextwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_gettransmatrix", QString("<u>harupage_gettransmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getwidth", QString("<u>harupage_getwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_getwordspace", QString("<u>harupage_getwordspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_lineto", QString("<u>harupage_lineto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_measuretext", QString("<u>harupage_measuretext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_movetextpos", QString("<u>harupage_movetextpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_moveto", QString("<u>harupage_moveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_movetonextline", QString("<u>harupage_movetonextline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_rectangle", QString("<u>harupage_rectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setcharspace", QString("<u>harupage_setcharspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setcmykfill", QString("<u>harupage_setcmykfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setcmykstroke", QString("<u>harupage_setcmykstroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setdash", QString("<u>harupage_setdash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setflatness", QString("<u>harupage_setflatness</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setfontandsize", QString("<u>harupage_setfontandsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setgrayfill", QString("<u>harupage_setgrayfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setgraystroke", QString("<u>harupage_setgraystroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setheight", QString("<u>harupage_setheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_sethorizontalscaling", QString("<u>harupage_sethorizontalscaling</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setlinecap", QString("<u>harupage_setlinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setlinejoin", QString("<u>harupage_setlinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setlinewidth", QString("<u>harupage_setlinewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setmiterlimit", QString("<u>harupage_setmiterlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setrgbfill", QString("<u>harupage_setrgbfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setrgbstroke", QString("<u>harupage_setrgbstroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setrotate", QString("<u>harupage_setrotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setsize", QString("<u>harupage_setsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setslideshow", QString("<u>harupage_setslideshow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_settextleading", QString("<u>harupage_settextleading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_settextmatrix", QString("<u>harupage_settextmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_settextrenderingmode", QString("<u>harupage_settextrenderingmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_settextrise", QString("<u>harupage_settextrise</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setwidth", QString("<u>harupage_setwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_setwordspace", QString("<u>harupage_setwordspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_showtext", QString("<u>harupage_showtext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_showtextnextline", QString("<u>harupage_showtextnextline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_stroke", QString("<u>harupage_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_textout", QString("<u>harupage_textout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("harupage_textrect", QString("<u>harupage_textrect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hasconstant", QString("<u>hasconstant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash", QString("<u>hash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_algos", QString("<u>hash_algos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_copy", QString("<u>hash_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_file", QString("<u>hash_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_final", QString("<u>hash_final</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_hmac", QString("<u>hash_hmac</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_hmac_file", QString("<u>hash_hmac_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_init", QString("<u>hash_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_update", QString("<u>hash_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_update_file", QString("<u>hash_update_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hash_update_stream", QString("<u>hash_update_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hasmethod", QString("<u>hasmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hasproperty", QString("<u>hasproperty</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("header", QString("void <u>header</u>(<b>string $string [, bool $replace = true [, int $http_response_code ]]</b>) <br />%1").arg(tr("Send a raw HTTP header")));
//  data.insert("header_register_callback", QString("<u>header_register_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("header_remove", QString("<u>header_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("headers_list", QString("<u>headers_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("headers_sent", QString("<u>headers_sent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hebrev", QString("<u>hebrev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hebrevc", QString("<u>hebrevc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hex2bin", QString("<u>hex2bin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hexdec", QString("<u>hexdec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("highlight_file", QString("<u>highlight_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("highlight_string", QString("<u>highlight_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("html_entity_decode", QString("<u>html_entity_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("htmlentities", QString("<u>htmlentities</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("htmlspecialchars", QString("<u>htmlspecialchars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("htmlspecialchars_decode", QString("<u>htmlspecialchars_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_build_cookie", QString("<u>http_build_cookie</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_build_query", QString("<u>http_build_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_build_str", QString("<u>http_build_str</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_build_url", QString("<u>http_build_url</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_cache_etag", QString("<u>http_cache_etag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_cache_last_modified", QString("<u>http_cache_last_modified</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_chunked_decode", QString("<u>http_chunked_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_date", QString("<u>http_date</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_deflate", QString("<u>http_deflate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_get", QString("<u>http_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_get_request_body", QString("<u>http_get_request_body</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_get_request_body_stream", QString("<u>http_get_request_body_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_get_request_headers", QString("<u>http_get_request_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_head", QString("<u>http_head</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_inflate", QString("<u>http_inflate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_match_etag", QString("<u>http_match_etag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_match_modified", QString("<u>http_match_modified</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_match_request_header", QString("<u>http_match_request_header</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_negotiate_charset", QString("<u>http_negotiate_charset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_negotiate_content_type", QString("<u>http_negotiate_content_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_negotiate_language", QString("<u>http_negotiate_language</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_parse_cookie", QString("<u>http_parse_cookie</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_parse_headers", QString("<u>http_parse_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_parse_message", QString("<u>http_parse_message</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_parse_params", QString("<u>http_parse_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_persistent_handles_clean", QString("<u>http_persistent_handles_clean</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_persistent_handles_count", QString("<u>http_persistent_handles_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_persistent_handles_ident", QString("<u>http_persistent_handles_ident</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_post_data", QString("<u>http_post_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_post_fields", QString("<u>http_post_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_put_data", QString("<u>http_put_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_put_file", QString("<u>http_put_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_put_stream", QString("<u>http_put_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_redirect", QString("<u>http_redirect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_request", QString("<u>http_request</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_request_body_encode", QString("<u>http_request_body_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_request_method_exists", QString("<u>http_request_method_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_request_method_name", QString("<u>http_request_method_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_request_method_register", QString("<u>http_request_method_register</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_request_method_unregister", QString("<u>http_request_method_unregister</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_response_code", QString("<u>http_response_code</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_content_disposition", QString("<u>http_send_content_disposition</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_content_type", QString("<u>http_send_content_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_data", QString("<u>http_send_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_file", QString("<u>http_send_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_last_modified", QString("<u>http_send_last_modified</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_status", QString("<u>http_send_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_send_stream", QString("<u>http_send_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_support", QString("<u>http_support</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("http_throttle", QString("<u>http_throttle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpdeflatestream", QString("<u>httpdeflatestream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpdeflatestream_construct", QString("<u>httpdeflatestream_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpdeflatestream_factory", QString("<u>httpdeflatestream_factory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpdeflatestream_finish", QString("<u>httpdeflatestream_finish</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpdeflatestream_flush", QString("<u>httpdeflatestream_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpdeflatestream_update", QString("<u>httpdeflatestream_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpinflatestream", QString("<u>httpinflatestream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpinflatestream_construct", QString("<u>httpinflatestream_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpinflatestream_factory", QString("<u>httpinflatestream_factory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpinflatestream_finish", QString("<u>httpinflatestream_finish</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpinflatestream_flush", QString("<u>httpinflatestream_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpinflatestream_update", QString("<u>httpinflatestream_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage", QString("<u>httpmessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_addheaders", QString("<u>httpmessage_addheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_construct", QString("<u>httpmessage_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_detach", QString("<u>httpmessage_detach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_factory", QString("<u>httpmessage_factory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_fromenv", QString("<u>httpmessage_fromenv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_fromstring", QString("<u>httpmessage_fromstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getbody", QString("<u>httpmessage_getbody</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getheader", QString("<u>httpmessage_getheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getheaders", QString("<u>httpmessage_getheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_gethttpversion", QString("<u>httpmessage_gethttpversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getparentmessage", QString("<u>httpmessage_getparentmessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getrequestmethod", QString("<u>httpmessage_getrequestmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getrequesturl", QString("<u>httpmessage_getrequesturl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getresponsecode", QString("<u>httpmessage_getresponsecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_getresponsestatus", QString("<u>httpmessage_getresponsestatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_gettype", QString("<u>httpmessage_gettype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_guesscontenttype", QString("<u>httpmessage_guesscontenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_prepend", QString("<u>httpmessage_prepend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_reverse", QString("<u>httpmessage_reverse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_send", QString("<u>httpmessage_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_setbody", QString("<u>httpmessage_setbody</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_setheaders", QString("<u>httpmessage_setheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_sethttpversion", QString("<u>httpmessage_sethttpversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_setrequestmethod", QString("<u>httpmessage_setrequestmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_setrequesturl", QString("<u>httpmessage_setrequesturl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_setresponsecode", QString("<u>httpmessage_setresponsecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_setresponsestatus", QString("<u>httpmessage_setresponsestatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_settype", QString("<u>httpmessage_settype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_tomessagetypeobject", QString("<u>httpmessage_tomessagetypeobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpmessage_tostring", QString("<u>httpmessage_tostring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring", QString("<u>httpquerystring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_construct", QString("<u>httpquerystring_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_get", QString("<u>httpquerystring_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_mod", QString("<u>httpquerystring_mod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_set", QString("<u>httpquerystring_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_singleton", QString("<u>httpquerystring_singleton</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_toarray", QString("<u>httpquerystring_toarray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_tostring", QString("<u>httpquerystring_tostring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpquerystring_xlate", QString("<u>httpquerystring_xlate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest", QString("<u>httprequest</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addcookies", QString("<u>httprequest_addcookies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addheaders", QString("<u>httprequest_addheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addpostfields", QString("<u>httprequest_addpostfields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addpostfile", QString("<u>httprequest_addpostfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addputdata", QString("<u>httprequest_addputdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addquerydata", QString("<u>httprequest_addquerydata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addrawpostdata", QString("<u>httprequest_addrawpostdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_addssloptions", QString("<u>httprequest_addssloptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_clearhistory", QString("<u>httprequest_clearhistory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_construct", QString("<u>httprequest_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_enablecookies", QString("<u>httprequest_enablecookies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getcontenttype", QString("<u>httprequest_getcontenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getcookies", QString("<u>httprequest_getcookies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getheaders", QString("<u>httprequest_getheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_gethistory", QString("<u>httprequest_gethistory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getmethod", QString("<u>httprequest_getmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getoptions", QString("<u>httprequest_getoptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getpostfields", QString("<u>httprequest_getpostfields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getpostfiles", QString("<u>httprequest_getpostfiles</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getputdata", QString("<u>httprequest_getputdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getputfile", QString("<u>httprequest_getputfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getquerydata", QString("<u>httprequest_getquerydata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getrawpostdata", QString("<u>httprequest_getrawpostdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getrawrequestmessage", QString("<u>httprequest_getrawrequestmessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getrawresponsemessage", QString("<u>httprequest_getrawresponsemessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getrequestmessage", QString("<u>httprequest_getrequestmessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponsebody", QString("<u>httprequest_getresponsebody</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponsecode", QString("<u>httprequest_getresponsecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponsecookies", QString("<u>httprequest_getresponsecookies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponsedata", QString("<u>httprequest_getresponsedata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponseheader", QString("<u>httprequest_getresponseheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponseinfo", QString("<u>httprequest_getresponseinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponsemessage", QString("<u>httprequest_getresponsemessage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getresponsestatus", QString("<u>httprequest_getresponsestatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_getssloptions", QString("<u>httprequest_getssloptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_geturl", QString("<u>httprequest_geturl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_resetcookies", QString("<u>httprequest_resetcookies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_send", QString("<u>httprequest_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setcontenttype", QString("<u>httprequest_setcontenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setcookies", QString("<u>httprequest_setcookies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setheaders", QString("<u>httprequest_setheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setmethod", QString("<u>httprequest_setmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setoptions", QString("<u>httprequest_setoptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setpostfields", QString("<u>httprequest_setpostfields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setpostfiles", QString("<u>httprequest_setpostfiles</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setputdata", QString("<u>httprequest_setputdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setputfile", QString("<u>httprequest_setputfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setquerydata", QString("<u>httprequest_setquerydata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setrawpostdata", QString("<u>httprequest_setrawpostdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_setssloptions", QString("<u>httprequest_setssloptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequest_seturl", QString("<u>httprequest_seturl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool", QString("<u>httprequestpool</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_attach", QString("<u>httprequestpool_attach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_construct", QString("<u>httprequestpool_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_destruct", QString("<u>httprequestpool_destruct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_detach", QString("<u>httprequestpool_detach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_getattachedrequests", QString("<u>httprequestpool_getattachedrequests</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_getfinishedrequests", QString("<u>httprequestpool_getfinishedrequests</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_reset", QString("<u>httprequestpool_reset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_send", QString("<u>httprequestpool_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_socketperform", QString("<u>httprequestpool_socketperform</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httprequestpool_socketselect", QString("<u>httprequestpool_socketselect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse", QString("<u>httpresponse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_capture", QString("<u>httpresponse_capture</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getbuffersize", QString("<u>httpresponse_getbuffersize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getcache", QString("<u>httpresponse_getcache</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getcachecontrol", QString("<u>httpresponse_getcachecontrol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getcontentdisposition", QString("<u>httpresponse_getcontentdisposition</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getcontenttype", QString("<u>httpresponse_getcontenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getdata", QString("<u>httpresponse_getdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getetag", QString("<u>httpresponse_getetag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getfile", QString("<u>httpresponse_getfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getgzip", QString("<u>httpresponse_getgzip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getheader", QString("<u>httpresponse_getheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getlastmodified", QString("<u>httpresponse_getlastmodified</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getrequestbody", QString("<u>httpresponse_getrequestbody</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getrequestbodystream", QString("<u>httpresponse_getrequestbodystream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getrequestheaders", QString("<u>httpresponse_getrequestheaders</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getstream", QString("<u>httpresponse_getstream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_getthrottledelay", QString("<u>httpresponse_getthrottledelay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_guesscontenttype", QString("<u>httpresponse_guesscontenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_redirect", QString("<u>httpresponse_redirect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_send", QString("<u>httpresponse_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setbuffersize", QString("<u>httpresponse_setbuffersize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setcache", QString("<u>httpresponse_setcache</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setcachecontrol", QString("<u>httpresponse_setcachecontrol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setcontentdisposition", QString("<u>httpresponse_setcontentdisposition</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setcontenttype", QString("<u>httpresponse_setcontenttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setdata", QString("<u>httpresponse_setdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setetag", QString("<u>httpresponse_setetag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setfile", QString("<u>httpresponse_setfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setgzip", QString("<u>httpresponse_setgzip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setheader", QString("<u>httpresponse_setheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setlastmodified", QString("<u>httpresponse_setlastmodified</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setstream", QString("<u>httpresponse_setstream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_setthrottledelay", QString("<u>httpresponse_setthrottledelay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("httpresponse_status", QString("<u>httpresponse_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_array2objrec", QString("<u>hw_array2objrec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_changeobject", QString("<u>hw_changeobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_children", QString("<u>hw_children</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_childrenobj", QString("<u>hw_childrenobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_close", QString("<u>hw_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_connect", QString("<u>hw_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_connection_info", QString("<u>hw_connection_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_cp", QString("<u>hw_cp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_deleteobject", QString("<u>hw_deleteobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_docbyanchor", QString("<u>hw_docbyanchor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_docbyanchorobj", QString("<u>hw_docbyanchorobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_document_attributes", QString("<u>hw_document_attributes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_document_bodytag", QString("<u>hw_document_bodytag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_document_content", QString("<u>hw_document_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_document_setcontent", QString("<u>hw_document_setcontent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_document_size", QString("<u>hw_document_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_dummy", QString("<u>hw_dummy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_edittext", QString("<u>hw_edittext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_error", QString("<u>hw_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_errormsg", QString("<u>hw_errormsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_free_document", QString("<u>hw_free_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getanchors", QString("<u>hw_getanchors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getanchorsobj", QString("<u>hw_getanchorsobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getandlock", QString("<u>hw_getandlock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getchildcoll", QString("<u>hw_getchildcoll</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getchildcollobj", QString("<u>hw_getchildcollobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getchilddoccoll", QString("<u>hw_getchilddoccoll</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getchilddoccollobj", QString("<u>hw_getchilddoccollobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getobject", QString("<u>hw_getobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getobjectbyquery", QString("<u>hw_getobjectbyquery</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getobjectbyquerycoll", QString("<u>hw_getobjectbyquerycoll</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getobjectbyquerycollobj", QString("<u>hw_getobjectbyquerycollobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getobjectbyqueryobj", QString("<u>hw_getobjectbyqueryobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getparents", QString("<u>hw_getparents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getparentsobj", QString("<u>hw_getparentsobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getrellink", QString("<u>hw_getrellink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getremote", QString("<u>hw_getremote</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getremotechildren", QString("<u>hw_getremotechildren</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getsrcbydestobj", QString("<u>hw_getsrcbydestobj</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_gettext", QString("<u>hw_gettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_getusername", QString("<u>hw_getusername</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_identify", QString("<u>hw_identify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_incollections", QString("<u>hw_incollections</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_info", QString("<u>hw_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_inscoll", QString("<u>hw_inscoll</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_insdoc", QString("<u>hw_insdoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_insertanchors", QString("<u>hw_insertanchors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_insertdocument", QString("<u>hw_insertdocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_insertobject", QString("<u>hw_insertobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_mapid", QString("<u>hw_mapid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_modifyobject", QString("<u>hw_modifyobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_mv", QString("<u>hw_mv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_new_document", QString("<u>hw_new_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_objrec2array", QString("<u>hw_objrec2array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_output_document", QString("<u>hw_output_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_pconnect", QString("<u>hw_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_pipedocument", QString("<u>hw_pipedocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_root", QString("<u>hw_root</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_setlinkroot", QString("<u>hw_setlinkroot</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_stat", QString("<u>hw_stat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_unlock", QString("<u>hw_unlock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hw_who", QString("<u>hw_who</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_attribute", QString("<u>hwapi_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_attribute_key", QString("<u>hwapi_attribute_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_attribute_langdepvalue", QString("<u>hwapi_attribute_langdepvalue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_attribute_value", QString("<u>hwapi_attribute_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_attribute_values", QString("<u>hwapi_attribute_values</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_checkin", QString("<u>hwapi_checkin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_checkout", QString("<u>hwapi_checkout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_children", QString("<u>hwapi_children</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_content", QString("<u>hwapi_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_content_mimetype", QString("<u>hwapi_content_mimetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_content_read", QString("<u>hwapi_content_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_copy", QString("<u>hwapi_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_dbstat", QString("<u>hwapi_dbstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_dcstat", QString("<u>hwapi_dcstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_dstanchors", QString("<u>hwapi_dstanchors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_dstofsrcanchor", QString("<u>hwapi_dstofsrcanchor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_error_count", QString("<u>hwapi_error_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_error_reason", QString("<u>hwapi_error_reason</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_find", QString("<u>hwapi_find</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_ftstat", QString("<u>hwapi_ftstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_hgcsp", QString("<u>hwapi_hgcsp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_hwstat", QString("<u>hwapi_hwstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_identify", QString("<u>hwapi_identify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_info", QString("<u>hwapi_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_insert", QString("<u>hwapi_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_insertanchor", QString("<u>hwapi_insertanchor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_insertcollection", QString("<u>hwapi_insertcollection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_insertdocument", QString("<u>hwapi_insertdocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_link", QString("<u>hwapi_link</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_lock", QString("<u>hwapi_lock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_move", QString("<u>hwapi_move</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_new_content", QString("<u>hwapi_new_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object", QString("<u>hwapi_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_assign", QString("<u>hwapi_object_assign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_attreditable", QString("<u>hwapi_object_attreditable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_count", QString("<u>hwapi_object_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_insert", QString("<u>hwapi_object_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_new", QString("<u>hwapi_object_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_remove", QString("<u>hwapi_object_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_title", QString("<u>hwapi_object_title</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_object_value", QString("<u>hwapi_object_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_objectbyanchor", QString("<u>hwapi_objectbyanchor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_parents", QString("<u>hwapi_parents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_reason_description", QString("<u>hwapi_reason_description</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_reason_type", QString("<u>hwapi_reason_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_remove", QString("<u>hwapi_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_replace", QString("<u>hwapi_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_setcommittedversion", QString("<u>hwapi_setcommittedversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_srcanchors", QString("<u>hwapi_srcanchors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_srcsofdst", QString("<u>hwapi_srcsofdst</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_unlock", QString("<u>hwapi_unlock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_user", QString("<u>hwapi_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hwapi_userlist", QString("<u>hwapi_userlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("hypot", QString("<u>hypot</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_add_user", QString("<u>ibase_add_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_affected_rows", QString("<u>ibase_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_backup", QString("<u>ibase_backup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_add", QString("<u>ibase_blob_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_cancel", QString("<u>ibase_blob_cancel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_close", QString("<u>ibase_blob_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_create", QString("<u>ibase_blob_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_echo", QString("<u>ibase_blob_echo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_get", QString("<u>ibase_blob_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_import", QString("<u>ibase_blob_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_info", QString("<u>ibase_blob_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_blob_open", QString("<u>ibase_blob_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_close", QString("<u>ibase_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_commit", QString("<u>ibase_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_commit_ret", QString("<u>ibase_commit_ret</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_connect", QString("<u>ibase_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_db_info", QString("<u>ibase_db_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_delete_user", QString("<u>ibase_delete_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_drop_db", QString("<u>ibase_drop_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_errcode", QString("<u>ibase_errcode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_errmsg", QString("<u>ibase_errmsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_execute", QString("<u>ibase_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_fetch_assoc", QString("<u>ibase_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_fetch_object", QString("<u>ibase_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_fetch_row", QString("<u>ibase_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_field_info", QString("<u>ibase_field_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_free_event_handler", QString("<u>ibase_free_event_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_free_query", QString("<u>ibase_free_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_free_result", QString("<u>ibase_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_gen_id", QString("<u>ibase_gen_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_maintain_db", QString("<u>ibase_maintain_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_modify_user", QString("<u>ibase_modify_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_name_result", QString("<u>ibase_name_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_num_fields", QString("<u>ibase_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_num_params", QString("<u>ibase_num_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_param_info", QString("<u>ibase_param_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_pconnect", QString("<u>ibase_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_prepare", QString("<u>ibase_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_query", QString("<u>ibase_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_restore", QString("<u>ibase_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_rollback", QString("<u>ibase_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_rollback_ret", QString("<u>ibase_rollback_ret</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_server_info", QString("<u>ibase_server_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_service_attach", QString("<u>ibase_service_attach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_service_detach", QString("<u>ibase_service_detach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_set_event_handler", QString("<u>ibase_set_event_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_timefmt", QString("<u>ibase_timefmt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_trans", QString("<u>ibase_trans</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ibase_wait_event", QString("<u>ibase_wait_event</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv", QString("<u>iconv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_get_encoding", QString("<u>iconv_get_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_mime_decode", QString("<u>iconv_mime_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_mime_decode_headers", QString("<u>iconv_mime_decode_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_mime_encode", QString("<u>iconv_mime_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_set_encoding", QString("<u>iconv_set_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_strlen", QString("<u>iconv_strlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_strpos", QString("<u>iconv_strpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_strrpos", QString("<u>iconv_strrpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iconv_substr", QString("<u>iconv_substr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_frame_long_name", QString("<u>id3_get_frame_long_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_frame_short_name", QString("<u>id3_get_frame_short_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_genre_id", QString("<u>id3_get_genre_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_genre_list", QString("<u>id3_get_genre_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_genre_name", QString("<u>id3_get_genre_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_tag", QString("<u>id3_get_tag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_get_version", QString("<u>id3_get_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_remove_tag", QString("<u>id3_remove_tag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("id3_set_tag", QString("<u>id3_set_tag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("idate", QString("<u>idate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("idn_to_ascii", QString("<u>idn_to_ascii</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("idn_to_unicode", QString("<u>idn_to_unicode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("idn_to_utf8", QString("<u>idn_to_utf8</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_affected_rows", QString("<u>ifx_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_blobinfile_mode", QString("<u>ifx_blobinfile_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_byteasvarchar", QString("<u>ifx_byteasvarchar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_close", QString("<u>ifx_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_connect", QString("<u>ifx_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_copy_blob", QString("<u>ifx_copy_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_create_blob", QString("<u>ifx_create_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_create_char", QString("<u>ifx_create_char</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_do", QString("<u>ifx_do</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_error", QString("<u>ifx_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_errormsg", QString("<u>ifx_errormsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_fetch_row", QString("<u>ifx_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_fieldproperties", QString("<u>ifx_fieldproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_fieldtypes", QString("<u>ifx_fieldtypes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_free_blob", QString("<u>ifx_free_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_free_char", QString("<u>ifx_free_char</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_free_result", QString("<u>ifx_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_get_blob", QString("<u>ifx_get_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_get_char", QString("<u>ifx_get_char</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_getsqlca", QString("<u>ifx_getsqlca</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_htmltbl_result", QString("<u>ifx_htmltbl_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_nullformat", QString("<u>ifx_nullformat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_num_fields", QString("<u>ifx_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_num_rows", QString("<u>ifx_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_pconnect", QString("<u>ifx_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_prepare", QString("<u>ifx_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_query", QString("<u>ifx_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_textasvarchar", QString("<u>ifx_textasvarchar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_update_blob", QString("<u>ifx_update_blob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifx_update_char", QString("<u>ifx_update_char</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_close_slob", QString("<u>ifxus_close_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_create_slob", QString("<u>ifxus_create_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_free_slob", QString("<u>ifxus_free_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_open_slob", QString("<u>ifxus_open_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_read_slob", QString("<u>ifxus_read_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_seek_slob", QString("<u>ifxus_seek_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_tell_slob", QString("<u>ifxus_tell_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ifxus_write_slob", QString("<u>ifxus_write_slob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ignore_user_abort", QString("<u>ignore_user_abort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_add_server", QString("<u>iis_add_server</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_get_dir_security", QString("<u>iis_get_dir_security</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_get_script_map", QString("<u>iis_get_script_map</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_get_server_by_comment", QString("<u>iis_get_server_by_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_get_server_by_path", QString("<u>iis_get_server_by_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_get_server_rights", QString("<u>iis_get_server_rights</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_get_service_state", QString("<u>iis_get_service_state</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_remove_server", QString("<u>iis_remove_server</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_set_app_settings", QString("<u>iis_set_app_settings</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_set_dir_security", QString("<u>iis_set_dir_security</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_set_script_map", QString("<u>iis_set_script_map</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_set_server_rights", QString("<u>iis_set_server_rights</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_start_server", QString("<u>iis_start_server</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_start_service", QString("<u>iis_start_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_stop_server", QString("<u>iis_stop_server</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iis_stop_service", QString("<u>iis_stop_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("image2wbmp", QString("<u>image2wbmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("image_type_to_extension", QString("<u>image_type_to_extension</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("image_type_to_mime_type", QString("<u>image_type_to_mime_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagealphablending", QString("<u>imagealphablending</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageantialias", QString("<u>imageantialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagearc", QString("<u>imagearc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagechar", QString("<u>imagechar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecharup", QString("<u>imagecharup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorallocate", QString("<u>imagecolorallocate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorallocatealpha", QString("<u>imagecolorallocatealpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorat", QString("<u>imagecolorat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorclosest", QString("<u>imagecolorclosest</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorclosestalpha", QString("<u>imagecolorclosestalpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorclosesthwb", QString("<u>imagecolorclosesthwb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolordeallocate", QString("<u>imagecolordeallocate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorexact", QString("<u>imagecolorexact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorexactalpha", QString("<u>imagecolorexactalpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolormatch", QString("<u>imagecolormatch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorresolve", QString("<u>imagecolorresolve</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorresolvealpha", QString("<u>imagecolorresolvealpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorset", QString("<u>imagecolorset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorsforindex", QString("<u>imagecolorsforindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolorstotal", QString("<u>imagecolorstotal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecolortransparent", QString("<u>imagecolortransparent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageconvolution", QString("<u>imageconvolution</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecopy", QString("<u>imagecopy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecopymerge", QString("<u>imagecopymerge</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecopymergegray", QString("<u>imagecopymergegray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecopyresampled", QString("<u>imagecopyresampled</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecopyresized", QString("<u>imagecopyresized</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreate", QString("<u>imagecreate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromgd", QString("<u>imagecreatefromgd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromgd2", QString("<u>imagecreatefromgd2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromgd2part", QString("<u>imagecreatefromgd2part</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromgif", QString("<u>imagecreatefromgif</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromjpeg", QString("<u>imagecreatefromjpeg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefrompng", QString("<u>imagecreatefrompng</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromstring", QString("<u>imagecreatefromstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromwbmp", QString("<u>imagecreatefromwbmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromxbm", QString("<u>imagecreatefromxbm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatefromxpm", QString("<u>imagecreatefromxpm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagecreatetruecolor", QString("<u>imagecreatetruecolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagedashedline", QString("<u>imagedashedline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagedestroy", QString("<u>imagedestroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageellipse", QString("<u>imageellipse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefill", QString("<u>imagefill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefilledarc", QString("<u>imagefilledarc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefilledellipse", QString("<u>imagefilledellipse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefilledpolygon", QString("<u>imagefilledpolygon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefilledrectangle", QString("<u>imagefilledrectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefilltoborder", QString("<u>imagefilltoborder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefilter", QString("<u>imagefilter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefontheight", QString("<u>imagefontheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefontwidth", QString("<u>imagefontwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageftbbox", QString("<u>imageftbbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagefttext", QString("<u>imagefttext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagegammacorrect", QString("<u>imagegammacorrect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagegd", QString("<u>imagegd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagegd2", QString("<u>imagegd2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagegif", QString("<u>imagegif</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagegrabscreen", QString("<u>imagegrabscreen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagegrabwindow", QString("<u>imagegrabwindow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageinterlace", QString("<u>imageinterlace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageistruecolor", QString("<u>imageistruecolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagejpeg", QString("<u>imagejpeg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagelayereffect", QString("<u>imagelayereffect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageline", QString("<u>imageline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imageloadfont", QString("<u>imageloadfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepalettecopy", QString("<u>imagepalettecopy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepng", QString("<u>imagepng</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepolygon", QString("<u>imagepolygon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepsbbox", QString("<u>imagepsbbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepsencodefont", QString("<u>imagepsencodefont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepsextendfont", QString("<u>imagepsextendfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepsfreefont", QString("<u>imagepsfreefont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepsloadfont", QString("<u>imagepsloadfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepsslantfont", QString("<u>imagepsslantfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagepstext", QString("<u>imagepstext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagerectangle", QString("<u>imagerectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagerotate", QString("<u>imagerotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesavealpha", QString("<u>imagesavealpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesetbrush", QString("<u>imagesetbrush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesetpixel", QString("<u>imagesetpixel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesetstyle", QString("<u>imagesetstyle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesetthickness", QString("<u>imagesetthickness</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesettile", QString("<u>imagesettile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagestring", QString("<u>imagestring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagestringup", QString("<u>imagestringup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesx", QString("<u>imagesx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagesy", QString("<u>imagesy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagetruecolortopalette", QString("<u>imagetruecolortopalette</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagettfbbox", QString("<u>imagettfbbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagettftext", QString("<u>imagettftext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagetypes", QString("<u>imagetypes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagewbmp", QString("<u>imagewbmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagexbm", QString("<u>imagexbm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick", QString("<u>imagick</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_adaptiveblurimage", QString("<u>imagick_adaptiveblurimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_adaptiveresizeimage", QString("<u>imagick_adaptiveresizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_adaptivesharpenimage", QString("<u>imagick_adaptivesharpenimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_adaptivethresholdimage", QString("<u>imagick_adaptivethresholdimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_addimage", QString("<u>imagick_addimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_addnoiseimage", QString("<u>imagick_addnoiseimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_affinetransformimage", QString("<u>imagick_affinetransformimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_animateimages", QString("<u>imagick_animateimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_annotateimage", QString("<u>imagick_annotateimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_appendimages", QString("<u>imagick_appendimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_averageimages", QString("<u>imagick_averageimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_blackthresholdimage", QString("<u>imagick_blackthresholdimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_blurimage", QString("<u>imagick_blurimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_borderimage", QString("<u>imagick_borderimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_charcoalimage", QString("<u>imagick_charcoalimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_chopimage", QString("<u>imagick_chopimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_clear", QString("<u>imagick_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_clipimage", QString("<u>imagick_clipimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_clippathimage", QString("<u>imagick_clippathimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_clone", QString("<u>imagick_clone</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_clutimage", QString("<u>imagick_clutimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_coalesceimages", QString("<u>imagick_coalesceimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_colorfloodfillimage", QString("<u>imagick_colorfloodfillimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_colorizeimage", QString("<u>imagick_colorizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_combineimages", QString("<u>imagick_combineimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_commentimage", QString("<u>imagick_commentimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_compareimagechannels", QString("<u>imagick_compareimagechannels</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_compareimagelayers", QString("<u>imagick_compareimagelayers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_compareimages", QString("<u>imagick_compareimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_compositeimage", QString("<u>imagick_compositeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_construct", QString("<u>imagick_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_contrastimage", QString("<u>imagick_contrastimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_contraststretchimage", QString("<u>imagick_contraststretchimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_convolveimage", QString("<u>imagick_convolveimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_cropimage", QString("<u>imagick_cropimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_cropthumbnailimage", QString("<u>imagick_cropthumbnailimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_current", QString("<u>imagick_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_cyclecolormapimage", QString("<u>imagick_cyclecolormapimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_decipherimage", QString("<u>imagick_decipherimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_deconstructimages", QString("<u>imagick_deconstructimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_deleteimageartifact", QString("<u>imagick_deleteimageartifact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_despeckleimage", QString("<u>imagick_despeckleimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_destroy", QString("<u>imagick_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_displayimage", QString("<u>imagick_displayimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_displayimages", QString("<u>imagick_displayimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_distortimage", QString("<u>imagick_distortimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_drawimage", QString("<u>imagick_drawimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_edgeimage", QString("<u>imagick_edgeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_embossimage", QString("<u>imagick_embossimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_encipherimage", QString("<u>imagick_encipherimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_enhanceimage", QString("<u>imagick_enhanceimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_equalizeimage", QString("<u>imagick_equalizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_evaluateimage", QString("<u>imagick_evaluateimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_extentimage", QString("<u>imagick_extentimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_flattenimages", QString("<u>imagick_flattenimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_flipimage", QString("<u>imagick_flipimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_floodfillpaintimage", QString("<u>imagick_floodfillpaintimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_flopimage", QString("<u>imagick_flopimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_frameimage", QString("<u>imagick_frameimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_fximage", QString("<u>imagick_fximage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_gammaimage", QString("<u>imagick_gammaimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_gaussianblurimage", QString("<u>imagick_gaussianblurimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getcolorspace", QString("<u>imagick_getcolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getcompression", QString("<u>imagick_getcompression</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getcompressionquality", QString("<u>imagick_getcompressionquality</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getcopyright", QString("<u>imagick_getcopyright</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getfilename", QString("<u>imagick_getfilename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getfont", QString("<u>imagick_getfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getformat", QString("<u>imagick_getformat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getgravity", QString("<u>imagick_getgravity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_gethomeurl", QString("<u>imagick_gethomeurl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimage", QString("<u>imagick_getimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagealphachannel", QString("<u>imagick_getimagealphachannel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageartifact", QString("<u>imagick_getimageartifact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagebackgroundcolor", QString("<u>imagick_getimagebackgroundcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageblob", QString("<u>imagick_getimageblob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageblueprimary", QString("<u>imagick_getimageblueprimary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagebordercolor", QString("<u>imagick_getimagebordercolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechanneldepth", QString("<u>imagick_getimagechanneldepth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechanneldistortion", QString("<u>imagick_getimagechanneldistortion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechanneldistortions", QString("<u>imagick_getimagechanneldistortions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechannelextrema", QString("<u>imagick_getimagechannelextrema</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechannelmean", QString("<u>imagick_getimagechannelmean</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechannelrange", QString("<u>imagick_getimagechannelrange</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagechannelstatistics", QString("<u>imagick_getimagechannelstatistics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageclipmask", QString("<u>imagick_getimageclipmask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagecolormapcolor", QString("<u>imagick_getimagecolormapcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagecolors", QString("<u>imagick_getimagecolors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagecolorspace", QString("<u>imagick_getimagecolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagecompose", QString("<u>imagick_getimagecompose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagecompression", QString("<u>imagick_getimagecompression</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagecompressionquality", QString("<u>imagick_getimagecompressionquality</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagedelay", QString("<u>imagick_getimagedelay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagedepth", QString("<u>imagick_getimagedepth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagedispose", QString("<u>imagick_getimagedispose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagedistortion", QString("<u>imagick_getimagedistortion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageextrema", QString("<u>imagick_getimageextrema</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagefilename", QString("<u>imagick_getimagefilename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageformat", QString("<u>imagick_getimageformat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagegamma", QString("<u>imagick_getimagegamma</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagegeometry", QString("<u>imagick_getimagegeometry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagegravity", QString("<u>imagick_getimagegravity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagegreenprimary", QString("<u>imagick_getimagegreenprimary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageheight", QString("<u>imagick_getimageheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagehistogram", QString("<u>imagick_getimagehistogram</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageindex", QString("<u>imagick_getimageindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageinterlacescheme", QString("<u>imagick_getimageinterlacescheme</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageinterpolatemethod", QString("<u>imagick_getimageinterpolatemethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageiterations", QString("<u>imagick_getimageiterations</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagelength", QString("<u>imagick_getimagelength</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagemagicklicense", QString("<u>imagick_getimagemagicklicense</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagematte", QString("<u>imagick_getimagematte</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagemattecolor", QString("<u>imagick_getimagemattecolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageorientation", QString("<u>imagick_getimageorientation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagepage", QString("<u>imagick_getimagepage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagepixelcolor", QString("<u>imagick_getimagepixelcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageprofile", QString("<u>imagick_getimageprofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageprofiles", QString("<u>imagick_getimageprofiles</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageproperties", QString("<u>imagick_getimageproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageproperty", QString("<u>imagick_getimageproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageredprimary", QString("<u>imagick_getimageredprimary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageregion", QString("<u>imagick_getimageregion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagerenderingintent", QString("<u>imagick_getimagerenderingintent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageresolution", QString("<u>imagick_getimageresolution</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagesblob", QString("<u>imagick_getimagesblob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagescene", QString("<u>imagick_getimagescene</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagesignature", QString("<u>imagick_getimagesignature</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagesize", QString("<u>imagick_getimagesize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagetickspersecond", QString("<u>imagick_getimagetickspersecond</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagetotalinkdensity", QString("<u>imagick_getimagetotalinkdensity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagetype", QString("<u>imagick_getimagetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimageunits", QString("<u>imagick_getimageunits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagevirtualpixelmethod", QString("<u>imagick_getimagevirtualpixelmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagewhitepoint", QString("<u>imagick_getimagewhitepoint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getimagewidth", QString("<u>imagick_getimagewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getinterlacescheme", QString("<u>imagick_getinterlacescheme</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getiteratorindex", QString("<u>imagick_getiteratorindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getnumberimages", QString("<u>imagick_getnumberimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getoption", QString("<u>imagick_getoption</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getpackagename", QString("<u>imagick_getpackagename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getpage", QString("<u>imagick_getpage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getpixeliterator", QString("<u>imagick_getpixeliterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getpixelregioniterator", QString("<u>imagick_getpixelregioniterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getpointsize", QString("<u>imagick_getpointsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getquantumdepth", QString("<u>imagick_getquantumdepth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getquantumrange", QString("<u>imagick_getquantumrange</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getreleasedate", QString("<u>imagick_getreleasedate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getresource", QString("<u>imagick_getresource</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getresourcelimit", QString("<u>imagick_getresourcelimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getsamplingfactors", QString("<u>imagick_getsamplingfactors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getsize", QString("<u>imagick_getsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getsizeoffset", QString("<u>imagick_getsizeoffset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_getversion", QString("<u>imagick_getversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_hasnextimage", QString("<u>imagick_hasnextimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_haspreviousimage", QString("<u>imagick_haspreviousimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_identifyimage", QString("<u>imagick_identifyimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_implodeimage", QString("<u>imagick_implodeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_labelimage", QString("<u>imagick_labelimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_levelimage", QString("<u>imagick_levelimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_linearstretchimage", QString("<u>imagick_linearstretchimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_liquidrescaleimage", QString("<u>imagick_liquidrescaleimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_magnifyimage", QString("<u>imagick_magnifyimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_mapimage", QString("<u>imagick_mapimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_mattefloodfillimage", QString("<u>imagick_mattefloodfillimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_medianfilterimage", QString("<u>imagick_medianfilterimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_mergeimagelayers", QString("<u>imagick_mergeimagelayers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_minifyimage", QString("<u>imagick_minifyimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_modulateimage", QString("<u>imagick_modulateimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_montageimage", QString("<u>imagick_montageimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_morphimages", QString("<u>imagick_morphimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_mosaicimages", QString("<u>imagick_mosaicimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_motionblurimage", QString("<u>imagick_motionblurimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_negateimage", QString("<u>imagick_negateimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_newimage", QString("<u>imagick_newimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_newpseudoimage", QString("<u>imagick_newpseudoimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_nextimage", QString("<u>imagick_nextimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_normalizeimage", QString("<u>imagick_normalizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_oilpaintimage", QString("<u>imagick_oilpaintimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_opaquepaintimage", QString("<u>imagick_opaquepaintimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_optimizeimagelayers", QString("<u>imagick_optimizeimagelayers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_orderedposterizeimage", QString("<u>imagick_orderedposterizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_paintfloodfillimage", QString("<u>imagick_paintfloodfillimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_paintopaqueimage", QString("<u>imagick_paintopaqueimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_painttransparentimage", QString("<u>imagick_painttransparentimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_pingimage", QString("<u>imagick_pingimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_pingimageblob", QString("<u>imagick_pingimageblob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_pingimagefile", QString("<u>imagick_pingimagefile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_polaroidimage", QString("<u>imagick_polaroidimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_posterizeimage", QString("<u>imagick_posterizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_previewimages", QString("<u>imagick_previewimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_previousimage", QString("<u>imagick_previousimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_profileimage", QString("<u>imagick_profileimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_quantizeimage", QString("<u>imagick_quantizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_quantizeimages", QString("<u>imagick_quantizeimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_queryfontmetrics", QString("<u>imagick_queryfontmetrics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_queryfonts", QString("<u>imagick_queryfonts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_queryformats", QString("<u>imagick_queryformats</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_radialblurimage", QString("<u>imagick_radialblurimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_raiseimage", QString("<u>imagick_raiseimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_randomthresholdimage", QString("<u>imagick_randomthresholdimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_readimage", QString("<u>imagick_readimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_readimageblob", QString("<u>imagick_readimageblob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_readimagefile", QString("<u>imagick_readimagefile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_recolorimage", QString("<u>imagick_recolorimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_reducenoiseimage", QString("<u>imagick_reducenoiseimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_removeimage", QString("<u>imagick_removeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_removeimageprofile", QString("<u>imagick_removeimageprofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_render", QString("<u>imagick_render</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_resampleimage", QString("<u>imagick_resampleimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_resetimagepage", QString("<u>imagick_resetimagepage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_resizeimage", QString("<u>imagick_resizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_rollimage", QString("<u>imagick_rollimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_rotateimage", QString("<u>imagick_rotateimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_roundcorners", QString("<u>imagick_roundcorners</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_sampleimage", QString("<u>imagick_sampleimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_scaleimage", QString("<u>imagick_scaleimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_separateimagechannel", QString("<u>imagick_separateimagechannel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_sepiatoneimage", QString("<u>imagick_sepiatoneimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setbackgroundcolor", QString("<u>imagick_setbackgroundcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setcolorspace", QString("<u>imagick_setcolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setcompression", QString("<u>imagick_setcompression</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setcompressionquality", QString("<u>imagick_setcompressionquality</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setfilename", QString("<u>imagick_setfilename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setfirstiterator", QString("<u>imagick_setfirstiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setfont", QString("<u>imagick_setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setformat", QString("<u>imagick_setformat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setgravity", QString("<u>imagick_setgravity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimage", QString("<u>imagick_setimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagealphachannel", QString("<u>imagick_setimagealphachannel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageartifact", QString("<u>imagick_setimageartifact</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagebackgroundcolor", QString("<u>imagick_setimagebackgroundcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagebias", QString("<u>imagick_setimagebias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageblueprimary", QString("<u>imagick_setimageblueprimary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagebordercolor", QString("<u>imagick_setimagebordercolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagechanneldepth", QString("<u>imagick_setimagechanneldepth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageclipmask", QString("<u>imagick_setimageclipmask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagecolormapcolor", QString("<u>imagick_setimagecolormapcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagecolorspace", QString("<u>imagick_setimagecolorspace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagecompose", QString("<u>imagick_setimagecompose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagecompression", QString("<u>imagick_setimagecompression</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagecompressionquality", QString("<u>imagick_setimagecompressionquality</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagedelay", QString("<u>imagick_setimagedelay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagedepth", QString("<u>imagick_setimagedepth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagedispose", QString("<u>imagick_setimagedispose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageextent", QString("<u>imagick_setimageextent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagefilename", QString("<u>imagick_setimagefilename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageformat", QString("<u>imagick_setimageformat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagegamma", QString("<u>imagick_setimagegamma</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagegravity", QString("<u>imagick_setimagegravity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagegreenprimary", QString("<u>imagick_setimagegreenprimary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageindex", QString("<u>imagick_setimageindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageinterlacescheme", QString("<u>imagick_setimageinterlacescheme</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageinterpolatemethod", QString("<u>imagick_setimageinterpolatemethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageiterations", QString("<u>imagick_setimageiterations</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagematte", QString("<u>imagick_setimagematte</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagemattecolor", QString("<u>imagick_setimagemattecolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageopacity", QString("<u>imagick_setimageopacity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageorientation", QString("<u>imagick_setimageorientation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagepage", QString("<u>imagick_setimagepage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageprofile", QString("<u>imagick_setimageprofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageproperty", QString("<u>imagick_setimageproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageredprimary", QString("<u>imagick_setimageredprimary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagerenderingintent", QString("<u>imagick_setimagerenderingintent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageresolution", QString("<u>imagick_setimageresolution</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagescene", QString("<u>imagick_setimagescene</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagetickspersecond", QString("<u>imagick_setimagetickspersecond</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagetype", QString("<u>imagick_setimagetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimageunits", QString("<u>imagick_setimageunits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagevirtualpixelmethod", QString("<u>imagick_setimagevirtualpixelmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setimagewhitepoint", QString("<u>imagick_setimagewhitepoint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setinterlacescheme", QString("<u>imagick_setinterlacescheme</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setiteratorindex", QString("<u>imagick_setiteratorindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setlastiterator", QString("<u>imagick_setlastiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setoption", QString("<u>imagick_setoption</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setpage", QString("<u>imagick_setpage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setpointsize", QString("<u>imagick_setpointsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setresolution", QString("<u>imagick_setresolution</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setresourcelimit", QString("<u>imagick_setresourcelimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setsamplingfactors", QString("<u>imagick_setsamplingfactors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setsize", QString("<u>imagick_setsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_setsizeoffset", QString("<u>imagick_setsizeoffset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_settype", QString("<u>imagick_settype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_shadeimage", QString("<u>imagick_shadeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_shadowimage", QString("<u>imagick_shadowimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_sharpenimage", QString("<u>imagick_sharpenimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_shaveimage", QString("<u>imagick_shaveimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_shearimage", QString("<u>imagick_shearimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_sigmoidalcontrastimage", QString("<u>imagick_sigmoidalcontrastimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_sketchimage", QString("<u>imagick_sketchimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_solarizeimage", QString("<u>imagick_solarizeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_spliceimage", QString("<u>imagick_spliceimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_spreadimage", QString("<u>imagick_spreadimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_steganoimage", QString("<u>imagick_steganoimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_stereoimage", QString("<u>imagick_stereoimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_stripimage", QString("<u>imagick_stripimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_swirlimage", QString("<u>imagick_swirlimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_textureimage", QString("<u>imagick_textureimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_thresholdimage", QString("<u>imagick_thresholdimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_thumbnailimage", QString("<u>imagick_thumbnailimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_tintimage", QString("<u>imagick_tintimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_transformimage", QString("<u>imagick_transformimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_transparentpaintimage", QString("<u>imagick_transparentpaintimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_transposeimage", QString("<u>imagick_transposeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_transverseimage", QString("<u>imagick_transverseimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_trimimage", QString("<u>imagick_trimimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_uniqueimagecolors", QString("<u>imagick_uniqueimagecolors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_unsharpmaskimage", QString("<u>imagick_unsharpmaskimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_valid", QString("<u>imagick_valid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_vignetteimage", QString("<u>imagick_vignetteimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_waveimage", QString("<u>imagick_waveimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_whitethresholdimage", QString("<u>imagick_whitethresholdimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_writeimage", QString("<u>imagick_writeimage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_writeimagefile", QString("<u>imagick_writeimagefile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_writeimages", QString("<u>imagick_writeimages</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagick_writeimagesfile", QString("<u>imagick_writeimagesfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw", QString("<u>imagickdraw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_affine", QString("<u>imagickdraw_affine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_annotation", QString("<u>imagickdraw_annotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_arc", QString("<u>imagickdraw_arc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_bezier", QString("<u>imagickdraw_bezier</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_circle", QString("<u>imagickdraw_circle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_clear", QString("<u>imagickdraw_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_clone", QString("<u>imagickdraw_clone</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_color", QString("<u>imagickdraw_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_comment", QString("<u>imagickdraw_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_composite", QString("<u>imagickdraw_composite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_construct", QString("<u>imagickdraw_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_destroy", QString("<u>imagickdraw_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_ellipse", QString("<u>imagickdraw_ellipse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getclippath", QString("<u>imagickdraw_getclippath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getcliprule", QString("<u>imagickdraw_getcliprule</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getclipunits", QString("<u>imagickdraw_getclipunits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfillcolor", QString("<u>imagickdraw_getfillcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfillopacity", QString("<u>imagickdraw_getfillopacity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfillrule", QString("<u>imagickdraw_getfillrule</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfont", QString("<u>imagickdraw_getfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfontfamily", QString("<u>imagickdraw_getfontfamily</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfontsize", QString("<u>imagickdraw_getfontsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfontstyle", QString("<u>imagickdraw_getfontstyle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getfontweight", QString("<u>imagickdraw_getfontweight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getgravity", QString("<u>imagickdraw_getgravity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokeantialias", QString("<u>imagickdraw_getstrokeantialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokecolor", QString("<u>imagickdraw_getstrokecolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokedasharray", QString("<u>imagickdraw_getstrokedasharray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokedashoffset", QString("<u>imagickdraw_getstrokedashoffset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokelinecap", QString("<u>imagickdraw_getstrokelinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokelinejoin", QString("<u>imagickdraw_getstrokelinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokemiterlimit", QString("<u>imagickdraw_getstrokemiterlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokeopacity", QString("<u>imagickdraw_getstrokeopacity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getstrokewidth", QString("<u>imagickdraw_getstrokewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_gettextalignment", QString("<u>imagickdraw_gettextalignment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_gettextantialias", QString("<u>imagickdraw_gettextantialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_gettextdecoration", QString("<u>imagickdraw_gettextdecoration</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_gettextencoding", QString("<u>imagickdraw_gettextencoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_gettextundercolor", QString("<u>imagickdraw_gettextundercolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_getvectorgraphics", QString("<u>imagickdraw_getvectorgraphics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_line", QString("<u>imagickdraw_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_matte", QString("<u>imagickdraw_matte</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathclose", QString("<u>imagickdraw_pathclose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetoabsolute", QString("<u>imagickdraw_pathcurvetoabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetoquadraticbezierabsolute", QString("<u>imagickdraw_pathcurvetoquadraticbezierabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetoquadraticbezierrelative", QString("<u>imagickdraw_pathcurvetoquadraticbezierrelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetoquadraticbeziersmoothabsolute", QString("<u>imagickdraw_pathcurvetoquadraticbeziersmoothabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetoquadraticbeziersmoothrelative", QString("<u>imagickdraw_pathcurvetoquadraticbeziersmoothrelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetorelative", QString("<u>imagickdraw_pathcurvetorelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetosmoothabsolute", QString("<u>imagickdraw_pathcurvetosmoothabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathcurvetosmoothrelative", QString("<u>imagickdraw_pathcurvetosmoothrelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathellipticarcabsolute", QString("<u>imagickdraw_pathellipticarcabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathellipticarcrelative", QString("<u>imagickdraw_pathellipticarcrelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathfinish", QString("<u>imagickdraw_pathfinish</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathlinetoabsolute", QString("<u>imagickdraw_pathlinetoabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathlinetohorizontalabsolute", QString("<u>imagickdraw_pathlinetohorizontalabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathlinetohorizontalrelative", QString("<u>imagickdraw_pathlinetohorizontalrelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathlinetorelative", QString("<u>imagickdraw_pathlinetorelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathlinetoverticalabsolute", QString("<u>imagickdraw_pathlinetoverticalabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathlinetoverticalrelative", QString("<u>imagickdraw_pathlinetoverticalrelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathmovetoabsolute", QString("<u>imagickdraw_pathmovetoabsolute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathmovetorelative", QString("<u>imagickdraw_pathmovetorelative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pathstart", QString("<u>imagickdraw_pathstart</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_point", QString("<u>imagickdraw_point</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_polygon", QString("<u>imagickdraw_polygon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_polyline", QString("<u>imagickdraw_polyline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pop", QString("<u>imagickdraw_pop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_popclippath", QString("<u>imagickdraw_popclippath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_popdefs", QString("<u>imagickdraw_popdefs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_poppattern", QString("<u>imagickdraw_poppattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_push", QString("<u>imagickdraw_push</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pushclippath", QString("<u>imagickdraw_pushclippath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pushdefs", QString("<u>imagickdraw_pushdefs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_pushpattern", QString("<u>imagickdraw_pushpattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_rectangle", QString("<u>imagickdraw_rectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_render", QString("<u>imagickdraw_render</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_rotate", QString("<u>imagickdraw_rotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_roundrectangle", QString("<u>imagickdraw_roundrectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_scale", QString("<u>imagickdraw_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setclippath", QString("<u>imagickdraw_setclippath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setcliprule", QString("<u>imagickdraw_setcliprule</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setclipunits", QString("<u>imagickdraw_setclipunits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfillalpha", QString("<u>imagickdraw_setfillalpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfillcolor", QString("<u>imagickdraw_setfillcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfillopacity", QString("<u>imagickdraw_setfillopacity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfillpatternurl", QString("<u>imagickdraw_setfillpatternurl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfillrule", QString("<u>imagickdraw_setfillrule</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfont", QString("<u>imagickdraw_setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfontfamily", QString("<u>imagickdraw_setfontfamily</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfontsize", QString("<u>imagickdraw_setfontsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfontstretch", QString("<u>imagickdraw_setfontstretch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfontstyle", QString("<u>imagickdraw_setfontstyle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setfontweight", QString("<u>imagickdraw_setfontweight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setgravity", QString("<u>imagickdraw_setgravity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokealpha", QString("<u>imagickdraw_setstrokealpha</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokeantialias", QString("<u>imagickdraw_setstrokeantialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokecolor", QString("<u>imagickdraw_setstrokecolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokedasharray", QString("<u>imagickdraw_setstrokedasharray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokedashoffset", QString("<u>imagickdraw_setstrokedashoffset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokelinecap", QString("<u>imagickdraw_setstrokelinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokelinejoin", QString("<u>imagickdraw_setstrokelinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokemiterlimit", QString("<u>imagickdraw_setstrokemiterlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokeopacity", QString("<u>imagickdraw_setstrokeopacity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokepatternurl", QString("<u>imagickdraw_setstrokepatternurl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setstrokewidth", QString("<u>imagickdraw_setstrokewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_settextalignment", QString("<u>imagickdraw_settextalignment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_settextantialias", QString("<u>imagickdraw_settextantialias</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_settextdecoration", QString("<u>imagickdraw_settextdecoration</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_settextencoding", QString("<u>imagickdraw_settextencoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_settextundercolor", QString("<u>imagickdraw_settextundercolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setvectorgraphics", QString("<u>imagickdraw_setvectorgraphics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_setviewbox", QString("<u>imagickdraw_setviewbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_skewx", QString("<u>imagickdraw_skewx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_skewy", QString("<u>imagickdraw_skewy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickdraw_translate", QString("<u>imagickdraw_translate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel", QString("<u>imagickpixel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_clear", QString("<u>imagickpixel_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_construct", QString("<u>imagickpixel_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_destroy", QString("<u>imagickpixel_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_getcolor", QString("<u>imagickpixel_getcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_getcolorasstring", QString("<u>imagickpixel_getcolorasstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_getcolorcount", QString("<u>imagickpixel_getcolorcount</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_getcolorvalue", QString("<u>imagickpixel_getcolorvalue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_gethsl", QString("<u>imagickpixel_gethsl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_issimilar", QString("<u>imagickpixel_issimilar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_setcolor", QString("<u>imagickpixel_setcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_setcolorvalue", QString("<u>imagickpixel_setcolorvalue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixel_sethsl", QString("<u>imagickpixel_sethsl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator", QString("<u>imagickpixeliterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_clear", QString("<u>imagickpixeliterator_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_construct", QString("<u>imagickpixeliterator_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_destroy", QString("<u>imagickpixeliterator_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_getcurrentiteratorrow", QString("<u>imagickpixeliterator_getcurrentiteratorrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_getiteratorrow", QString("<u>imagickpixeliterator_getiteratorrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_getnextiteratorrow", QString("<u>imagickpixeliterator_getnextiteratorrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_getpreviousiteratorrow", QString("<u>imagickpixeliterator_getpreviousiteratorrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_newpixeliterator", QString("<u>imagickpixeliterator_newpixeliterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_newpixelregioniterator", QString("<u>imagickpixeliterator_newpixelregioniterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_resetiterator", QString("<u>imagickpixeliterator_resetiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_setiteratorfirstrow", QString("<u>imagickpixeliterator_setiteratorfirstrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_setiteratorlastrow", QString("<u>imagickpixeliterator_setiteratorlastrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_setiteratorrow", QString("<u>imagickpixeliterator_setiteratorrow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imagickpixeliterator_synciterator", QString("<u>imagickpixeliterator_synciterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_8bit", QString("<u>imap_8bit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_alerts", QString("<u>imap_alerts</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_append", QString("<u>imap_append</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_base64", QString("<u>imap_base64</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_binary", QString("<u>imap_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_body", QString("<u>imap_body</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_bodystruct", QString("<u>imap_bodystruct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_check", QString("<u>imap_check</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_clearflag_full", QString("<u>imap_clearflag_full</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_close", QString("<u>imap_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_create", QString("<u>imap_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_createmailbox", QString("<u>imap_createmailbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_delete", QString("<u>imap_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_deletemailbox", QString("<u>imap_deletemailbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_errors", QString("<u>imap_errors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_expunge", QString("<u>imap_expunge</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_fetch_overview", QString("<u>imap_fetch_overview</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_fetchbody", QString("<u>imap_fetchbody</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_fetchheader", QString("<u>imap_fetchheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_fetchmime", QString("<u>imap_fetchmime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_fetchstructure", QString("<u>imap_fetchstructure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_fetchtext", QString("<u>imap_fetchtext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_gc", QString("<u>imap_gc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_get_quota", QString("<u>imap_get_quota</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_get_quotaroot", QString("<u>imap_get_quotaroot</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_getacl", QString("<u>imap_getacl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_getmailboxes", QString("<u>imap_getmailboxes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_getsubscribed", QString("<u>imap_getsubscribed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_header", QString("<u>imap_header</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_headerinfo", QString("<u>imap_headerinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_headers", QString("<u>imap_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_last_error", QString("<u>imap_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_list", QString("<u>imap_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_listmailbox", QString("<u>imap_listmailbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_listscan", QString("<u>imap_listscan</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_listsubscribed", QString("<u>imap_listsubscribed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_lsub", QString("<u>imap_lsub</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_mail", QString("<u>imap_mail</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_mail_compose", QString("<u>imap_mail_compose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_mail_copy", QString("<u>imap_mail_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_mail_move", QString("<u>imap_mail_move</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_mailboxmsginfo", QString("<u>imap_mailboxmsginfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_mime_header_decode", QString("<u>imap_mime_header_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_msgno", QString("<u>imap_msgno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_num_msg", QString("<u>imap_num_msg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_num_recent", QString("<u>imap_num_recent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_open", QString("<u>imap_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_ping", QString("<u>imap_ping</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_qprint", QString("<u>imap_qprint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_rename", QString("<u>imap_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_renamemailbox", QString("<u>imap_renamemailbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_reopen", QString("<u>imap_reopen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_rfc822_parse_adrlist", QString("<u>imap_rfc822_parse_adrlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_rfc822_parse_headers", QString("<u>imap_rfc822_parse_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_rfc822_write_address", QString("<u>imap_rfc822_write_address</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_savebody", QString("<u>imap_savebody</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_scan", QString("<u>imap_scan</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_scanmailbox", QString("<u>imap_scanmailbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_search", QString("<u>imap_search</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_set_quota", QString("<u>imap_set_quota</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_setacl", QString("<u>imap_setacl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_setflag_full", QString("<u>imap_setflag_full</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_sort", QString("<u>imap_sort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_status", QString("<u>imap_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_subscribe", QString("<u>imap_subscribe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_thread", QString("<u>imap_thread</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_timeout", QString("<u>imap_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_uid", QString("<u>imap_uid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_undelete", QString("<u>imap_undelete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_unsubscribe", QString("<u>imap_unsubscribe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_utf7_decode", QString("<u>imap_utf7_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_utf7_encode", QString("<u>imap_utf7_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("imap_utf8", QString("<u>imap_utf8</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("implementsinterface", QString("<u>implementsinterface</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("implode", QString("<u>implode</u>(<b>string $glue, array $pieces</b>) <br />%1").arg(tr("Join array elements with a string")));
//  data.insert("import_request_variables", QString("<u>import_request_variables</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("in_array", QString("bool <u>in_array</u>(<b>mixed $needle, array $haystack [, bool $strict = FALSE]</b>) <br />%1").arg(tr("Searches haystack for needle using loose Comparision unless strict is set.")));
  data.insert("include", QString("void <u>include</u>(<b>string $path</b>) <br />%1").arg(tr("Includes and evaluates the specified file")));
  data.insert("include_once", QString("void <u>include_once</u>(<b>string $path</b>) <br />%1").arg(tr("Includes and evaluates the specified file during the execution of the script")));
//  data.insert("inclued_get_data", QString("<u>inclued_get_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inet_ntop", QString("<u>inet_ntop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inet_pton", QString("<u>inet_pton</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("infiniteiterator", QString("<u>infiniteiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_autocommit", QString("<u>ingres_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_autocommit_state", QString("<u>ingres_autocommit_state</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_charset", QString("<u>ingres_charset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_close", QString("<u>ingres_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_commit", QString("<u>ingres_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_connect", QString("<u>ingres_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_cursor", QString("<u>ingres_cursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_errno", QString("<u>ingres_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_error", QString("<u>ingres_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_errsqlstate", QString("<u>ingres_errsqlstate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_escape_string", QString("<u>ingres_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_execute", QString("<u>ingres_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_fetch_array", QString("<u>ingres_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_fetch_assoc", QString("<u>ingres_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_fetch_object", QString("<u>ingres_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_fetch_proc_return", QString("<u>ingres_fetch_proc_return</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_fetch_row", QString("<u>ingres_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_field_length", QString("<u>ingres_field_length</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_field_name", QString("<u>ingres_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_field_nullable", QString("<u>ingres_field_nullable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_field_precision", QString("<u>ingres_field_precision</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_field_scale", QString("<u>ingres_field_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_field_type", QString("<u>ingres_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_free_result", QString("<u>ingres_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_next_error", QString("<u>ingres_next_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_num_fields", QString("<u>ingres_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_num_rows", QString("<u>ingres_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_pconnect", QString("<u>ingres_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_prepare", QString("<u>ingres_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_query", QString("<u>ingres_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_result_seek", QString("<u>ingres_result_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_rollback", QString("<u>ingres_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_set_environment", QString("<u>ingres_set_environment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ingres_unbuffered_query", QString("<u>ingres_unbuffered_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ini_alter", QString("<u>ini_alter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ini_get", QString("<u>ini_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ini_get_all", QString("<u>ini_get_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ini_restore", QString("<u>ini_restore</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ini_set", QString("string <u>ini_set</u>(<b>string $varname , string $newvalue</b>) <br />%1").arg(tr("Sets the value of a configuration option.")));
//  data.insert("innamespace", QString("<u>innamespace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inotify_add_watch", QString("<u>inotify_add_watch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inotify_init", QString("<u>inotify_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inotify_queue_len", QString("<u>inotify_queue_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inotify_read", QString("<u>inotify_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("inotify_rm_watch", QString("<u>inotify_rm_watch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("interface_exists", QString("<u>interface_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("intl_error_name", QString("<u>intl_error_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("intl_get_error_code", QString("<u>intl_get_error_code</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("intl_get_error_message", QString("<u>intl_get_error_message</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("intl_is_failure", QString("<u>intl_is_failure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("intldateformatter", QString("<u>intldateformatter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("intval", QString("<u>intval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("invalidargumentexception", QString("<u>invalidargumentexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("invoke", QString("<u>invoke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("invokeargs", QString("<u>invokeargs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ip2long", QString("<u>ip2long</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iptcembed", QString("<u>iptcembed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iptcparse", QString("<u>iptcparse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_a", QString("<u>is_a</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("is_array", QString("bool <u>is_array</u>(<b>mixed $var</b>) <br />%1").arg(tr("Finds whether a variable is an array.")));
//  data.insert("is_bool", QString("<u>is_bool</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_callable", QString("<u>is_callable</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("is_dir", QString("bool <u>is_dir</u>(<b>string $filename</b>) <br />%1").arg(tr("Tells whether the filename is a directory")));
//  data.insert("is_double", QString("<u>is_double</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_executable", QString("<u>is_executable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_file", QString("<u>is_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_finite", QString("<u>is_finite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_float", QString("<u>is_float</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_infinite", QString("<u>is_infinite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_int", QString("<u>is_int</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_integer", QString("<u>is_integer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_link", QString("<u>is_link</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_long", QString("<u>is_long</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_nan", QString("<u>is_nan</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("is_null", QString("bool <u>is_null</u>(<b>mixed $var</b>) <br />%1").arg(tr("Finds whether a variable is NULL")));
  data.insert("is_numeric", QString("bool <u>is_numeric</u>(<b>mixed $var</b>) <br />%1").arg(tr("Finds whether a variable is a number or a numeric string")));
//  data.insert("is_object", QString("<u>is_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_readable", QString("<u>is_readable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_real", QString("<u>is_real</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_resource", QString("<u>is_resource</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_scalar", QString("<u>is_scalar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_soap_fault", QString("<u>is_soap_fault</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_string", QString("<u>is_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_subclass_of", QString("<u>is_subclass_of</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_uploaded_file", QString("<u>is_uploaded_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_writable", QString("<u>is_writable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("is_writeable", QString("<u>is_writeable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isabstract", QString("<u>isabstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iscloneable", QString("<u>iscloneable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isdisabled", QString("<u>isdisabled</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isfinal", QString("<u>isfinal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isinstance", QString("<u>isinstance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isinstantiable", QString("<u>isinstantiable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isinterface", QString("<u>isinterface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isinternal", QString("<u>isinternal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isiterateable", QString("<u>isiterateable</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("isset", QString("<u>bool isset</u>(<b>mixed $var [, mixed $... ]</b>) <br />%1").arg(tr("Determine if a variable is set and is not NULL")));
//  data.insert("issubclassof", QString("<u>issubclassof</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("istrait", QString("<u>istrait</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("isuserdefined", QString("<u>isuserdefined</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iterator", QString("<u>iterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iterator_apply", QString("<u>iterator_apply</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iterator_count", QString("<u>iterator_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iterator_to_array", QString("<u>iterator_to_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iteratoraggregate", QString("<u>iteratoraggregate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("iteratoriterator", QString("<u>iteratoriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("java_last_exception_clear", QString("<u>java_last_exception_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("java_last_exception_get", QString("<u>java_last_exception_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jddayofweek", QString("<u>jddayofweek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jdmonthname", QString("<u>jdmonthname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jdtofrench", QString("<u>jdtofrench</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jdtogregorian", QString("<u>jdtogregorian</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jdtojewish", QString("<u>jdtojewish</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jdtojulian", QString("<u>jdtojulian</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jdtounix", QString("<u>jdtounix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jewishtojd", QString("<u>jewishtojd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("join", QString("<u>join</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jpeg2wbmp", QString("<u>jpeg2wbmp</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("json_decode", QString("mixed <u>json_decode</u>(<b>tring $json [, bool $assoc = false [, int $depth = 512 [, int $options = 0 ]]]</b>) <br />%1").arg(tr("Decodes a JSON string")));
//  data.insert("json_encode", QString("<u>json_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("json_last_error", QString("<u>json_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("jsonserializable", QString("<u>jsonserializable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("judy", QString("<u>judy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("judy_type", QString("<u>judy_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("judy_version", QString("<u>judy_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("juliantojd", QString("<u>juliantojd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_chpass_principal", QString("<u>kadm5_chpass_principal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_create_principal", QString("<u>kadm5_create_principal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_delete_principal", QString("<u>kadm5_delete_principal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_destroy", QString("<u>kadm5_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_flush", QString("<u>kadm5_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_get_policies", QString("<u>kadm5_get_policies</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_get_principal", QString("<u>kadm5_get_principal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_get_principals", QString("<u>kadm5_get_principals</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_init_with_password", QString("<u>kadm5_init_with_password</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("kadm5_modify_principal", QString("<u>kadm5_modify_principal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("key", QString("<u>key</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("krsort", QString("bool <u>krsort</u>(<b>array &$array [, int $sort_flags = SORT_REGULAR ]</b>) <br />%1").arg(tr("Sort an array by key in reverse order")));
  data.insert("ksort", QString("bool <u>ksort</u>(<b>array &$array [, int $sort_flags = SORT_REGULAR ]</b>) <br />%1").arg(tr("Sort an array by key")));
//  data.insert("ktaglib_id3v2_attachedpictureframe", QString("<u>ktaglib_id3v2_attachedpictureframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ktaglib_id3v2_frame", QString("<u>ktaglib_id3v2_frame</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ktaglib_id3v2_tag", QString("<u>ktaglib_id3v2_tag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ktaglib_mpeg_audioproperties", QString("<u>ktaglib_mpeg_audioproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ktaglib_mpeg_file", QString("<u>ktaglib_mpeg_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ktaglib_tag", QString("<u>ktaglib_tag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lcfirst", QString("<u>lcfirst</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lcg_value", QString("<u>lcg_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lchgrp", QString("<u>lchgrp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lchown", QString("<u>lchown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_8859_to_t61", QString("<u>ldap_8859_to_t61</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_add", QString("<u>ldap_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_bind", QString("<u>ldap_bind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_close", QString("<u>ldap_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_compare", QString("<u>ldap_compare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_connect", QString("<u>ldap_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_count_entries", QString("<u>ldap_count_entries</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_delete", QString("<u>ldap_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_dn2ufn", QString("<u>ldap_dn2ufn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_err2str", QString("<u>ldap_err2str</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_errno", QString("<u>ldap_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_error", QString("<u>ldap_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_explode_dn", QString("<u>ldap_explode_dn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_first_attribute", QString("<u>ldap_first_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_first_entry", QString("<u>ldap_first_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_first_reference", QString("<u>ldap_first_reference</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_free_result", QString("<u>ldap_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_get_attributes", QString("<u>ldap_get_attributes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_get_dn", QString("<u>ldap_get_dn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_get_entries", QString("<u>ldap_get_entries</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_get_option", QString("<u>ldap_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_get_values", QString("<u>ldap_get_values</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_get_values_len", QString("<u>ldap_get_values_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_list", QString("<u>ldap_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_mod_add", QString("<u>ldap_mod_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_mod_del", QString("<u>ldap_mod_del</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_mod_replace", QString("<u>ldap_mod_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_modify", QString("<u>ldap_modify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_next_attribute", QString("<u>ldap_next_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_next_entry", QString("<u>ldap_next_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_next_reference", QString("<u>ldap_next_reference</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_parse_reference", QString("<u>ldap_parse_reference</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_parse_result", QString("<u>ldap_parse_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_read", QString("<u>ldap_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_rename", QString("<u>ldap_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_sasl_bind", QString("<u>ldap_sasl_bind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_search", QString("<u>ldap_search</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_set_option", QString("<u>ldap_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_set_rebind_proc", QString("<u>ldap_set_rebind_proc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_sort", QString("<u>ldap_sort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_start_tls", QString("<u>ldap_start_tls</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_t61_to_8859", QString("<u>ldap_t61_to_8859</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ldap_unbind", QString("<u>ldap_unbind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lengthexception", QString("<u>lengthexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("levenshtein", QString("<u>levenshtein</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxml_clear_errors", QString("<u>libxml_clear_errors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxml_disable_entity_loader", QString("<u>libxml_disable_entity_loader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxml_get_errors", QString("<u>libxml_get_errors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxml_get_last_error", QString("<u>libxml_get_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxml_set_streams_context", QString("<u>libxml_set_streams_context</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxml_use_internal_errors", QString("<u>libxml_use_internal_errors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("libxmlerror", QString("<u>libxmlerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("limititerator", QString("<u>limititerator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("link", QString("<u>link</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("linkinfo", QString("<u>linkinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("list", QString("<u>list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("locale", QString("<u>locale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("localeconv", QString("<u>localeconv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("localtime", QString("<u>localtime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("log", QString("<u>log</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("log10", QString("<u>log10</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("log1p", QString("<u>log1p</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("logicexception", QString("<u>logicexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("long2ip", QString("<u>long2ip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lstat", QString("<u>lstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ltrim", QString("<u>ltrim</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lua", QString("<u>lua</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("luaclosure", QString("<u>luaclosure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lzf_compress", QString("<u>lzf_compress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lzf_decompress", QString("<u>lzf_decompress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("lzf_optimized_for", QString("<u>lzf_optimized_for</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_checkstatus", QString("<u>m_checkstatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_completeauthorizations", QString("<u>m_completeauthorizations</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_connect", QString("<u>m_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_connectionerror", QString("<u>m_connectionerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_deletetrans", QString("<u>m_deletetrans</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_destroyconn", QString("<u>m_destroyconn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_destroyengine", QString("<u>m_destroyengine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_getcell", QString("<u>m_getcell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_getcellbynum", QString("<u>m_getcellbynum</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_getcommadelimited", QString("<u>m_getcommadelimited</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_getheader", QString("<u>m_getheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_initconn", QString("<u>m_initconn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_initengine", QString("<u>m_initengine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_iscommadelimited", QString("<u>m_iscommadelimited</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_maxconntimeout", QString("<u>m_maxconntimeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_monitor", QString("<u>m_monitor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_numcolumns", QString("<u>m_numcolumns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_numrows", QString("<u>m_numrows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_parsecommadelimited", QString("<u>m_parsecommadelimited</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_responsekeys", QString("<u>m_responsekeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_responseparam", QString("<u>m_responseparam</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_returnstatus", QString("<u>m_returnstatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_setblocking", QString("<u>m_setblocking</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_setdropfile", QString("<u>m_setdropfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_setip", QString("<u>m_setip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_setssl", QString("<u>m_setssl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_setssl_cafile", QString("<u>m_setssl_cafile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_setssl_files", QString("<u>m_setssl_files</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_settimeout", QString("<u>m_settimeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_sslcert_gen_hash", QString("<u>m_sslcert_gen_hash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_transactionssent", QString("<u>m_transactionssent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_transinqueue", QString("<u>m_transinqueue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_transkeyval", QString("<u>m_transkeyval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_transnew", QString("<u>m_transnew</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_transsend", QString("<u>m_transsend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_uwait", QString("<u>m_uwait</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_validateidentifier", QString("<u>m_validateidentifier</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_verifyconnection", QString("<u>m_verifyconnection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("m_verifysslcert", QString("<u>m_verifysslcert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("magic_quotes_runtime", QString("<u>magic_quotes_runtime</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mail", QString("void <u>mail</u>(<b>string $to , string $subject , string $message [, string $additional_headers [, string $additional_parameters ]]</b>) <br />%1").arg(tr("Send mail")));
//  data.insert("mailparse_determine_best_xfer_encoding", QString("<u>mailparse_determine_best_xfer_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_create", QString("<u>mailparse_msg_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_extract_part", QString("<u>mailparse_msg_extract_part</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_extract_part_file", QString("<u>mailparse_msg_extract_part_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_extract_whole_part_file", QString("<u>mailparse_msg_extract_whole_part_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_free", QString("<u>mailparse_msg_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_get_part", QString("<u>mailparse_msg_get_part</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_get_part_data", QString("<u>mailparse_msg_get_part_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_get_structure", QString("<u>mailparse_msg_get_structure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_parse", QString("<u>mailparse_msg_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_msg_parse_file", QString("<u>mailparse_msg_parse_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_rfc822_parse_addresses", QString("<u>mailparse_rfc822_parse_addresses</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_stream_encode", QString("<u>mailparse_stream_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mailparse_uudecode_all", QString("<u>mailparse_uudecode_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("main", QString("<u>main</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("max", QString("<u>max</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_affected_rows", QString("<u>maxdb_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_autocommit", QString("<u>maxdb_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_bind_param", QString("<u>maxdb_bind_param</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_bind_result", QString("<u>maxdb_bind_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_change_user", QString("<u>maxdb_change_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_character_set_name", QString("<u>maxdb_character_set_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_client_encoding", QString("<u>maxdb_client_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_close", QString("<u>maxdb_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_close_long_data", QString("<u>maxdb_close_long_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_commit", QString("<u>maxdb_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_connect", QString("<u>maxdb_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_connect_errno", QString("<u>maxdb_connect_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_connect_error", QString("<u>maxdb_connect_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_data_seek", QString("<u>maxdb_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_debug", QString("<u>maxdb_debug</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_disable_reads_from_master", QString("<u>maxdb_disable_reads_from_master</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_disable_rpl_parse", QString("<u>maxdb_disable_rpl_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_dump_debug_info", QString("<u>maxdb_dump_debug_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_embedded_connect", QString("<u>maxdb_embedded_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_enable_reads_from_master", QString("<u>maxdb_enable_reads_from_master</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_enable_rpl_parse", QString("<u>maxdb_enable_rpl_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_errno", QString("<u>maxdb_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_error", QString("<u>maxdb_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_escape_string", QString("<u>maxdb_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_execute", QString("<u>maxdb_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch", QString("<u>maxdb_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_array", QString("<u>maxdb_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_assoc", QString("<u>maxdb_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_field", QString("<u>maxdb_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_field_direct", QString("<u>maxdb_fetch_field_direct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_fields", QString("<u>maxdb_fetch_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_lengths", QString("<u>maxdb_fetch_lengths</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_object", QString("<u>maxdb_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_fetch_row", QString("<u>maxdb_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_field_count", QString("<u>maxdb_field_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_field_seek", QString("<u>maxdb_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_field_tell", QString("<u>maxdb_field_tell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_free_result", QString("<u>maxdb_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_client_info", QString("<u>maxdb_get_client_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_client_version", QString("<u>maxdb_get_client_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_host_info", QString("<u>maxdb_get_host_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_metadata", QString("<u>maxdb_get_metadata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_proto_info", QString("<u>maxdb_get_proto_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_server_info", QString("<u>maxdb_get_server_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_get_server_version", QString("<u>maxdb_get_server_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_info", QString("<u>maxdb_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_init", QString("<u>maxdb_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_insert_id", QString("<u>maxdb_insert_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_kill", QString("<u>maxdb_kill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_master_query", QString("<u>maxdb_master_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_more_results", QString("<u>maxdb_more_results</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_multi_query", QString("<u>maxdb_multi_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_next_result", QString("<u>maxdb_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_num_fields", QString("<u>maxdb_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_num_rows", QString("<u>maxdb_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_options", QString("<u>maxdb_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_param_count", QString("<u>maxdb_param_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_ping", QString("<u>maxdb_ping</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_prepare", QString("<u>maxdb_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_query", QString("<u>maxdb_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_real_connect", QString("<u>maxdb_real_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_real_escape_string", QString("<u>maxdb_real_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_real_query", QString("<u>maxdb_real_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_report", QString("<u>maxdb_report</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_rollback", QString("<u>maxdb_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_rpl_parse_enabled", QString("<u>maxdb_rpl_parse_enabled</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_rpl_probe", QString("<u>maxdb_rpl_probe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_rpl_query_type", QString("<u>maxdb_rpl_query_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_select_db", QString("<u>maxdb_select_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_send_long_data", QString("<u>maxdb_send_long_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_send_query", QString("<u>maxdb_send_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_server_end", QString("<u>maxdb_server_end</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_server_init", QString("<u>maxdb_server_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_set_opt", QString("<u>maxdb_set_opt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_sqlstate", QString("<u>maxdb_sqlstate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_ssl_set", QString("<u>maxdb_ssl_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stat", QString("<u>maxdb_stat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_affected_rows", QString("<u>maxdb_stmt_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_bind_param", QString("<u>maxdb_stmt_bind_param</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_bind_result", QString("<u>maxdb_stmt_bind_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_close", QString("<u>maxdb_stmt_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_close_long_data", QString("<u>maxdb_stmt_close_long_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_data_seek", QString("<u>maxdb_stmt_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_errno", QString("<u>maxdb_stmt_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_error", QString("<u>maxdb_stmt_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_execute", QString("<u>maxdb_stmt_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_fetch", QString("<u>maxdb_stmt_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_free_result", QString("<u>maxdb_stmt_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_init", QString("<u>maxdb_stmt_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_num_rows", QString("<u>maxdb_stmt_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_param_count", QString("<u>maxdb_stmt_param_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_prepare", QString("<u>maxdb_stmt_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_reset", QString("<u>maxdb_stmt_reset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_result_metadata", QString("<u>maxdb_stmt_result_metadata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_send_long_data", QString("<u>maxdb_stmt_send_long_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_sqlstate", QString("<u>maxdb_stmt_sqlstate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_stmt_store_result", QString("<u>maxdb_stmt_store_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_store_result", QString("<u>maxdb_store_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_thread_id", QString("<u>maxdb_thread_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_thread_safe", QString("<u>maxdb_thread_safe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_use_result", QString("<u>maxdb_use_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("maxdb_warning_count", QString("<u>maxdb_warning_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_check_encoding", QString("<u>mb_check_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_convert_case", QString("<u>mb_convert_case</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_convert_encoding", QString("<u>mb_convert_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_convert_kana", QString("<u>mb_convert_kana</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_convert_variables", QString("<u>mb_convert_variables</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_decode_mimeheader", QString("<u>mb_decode_mimeheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_decode_numericentity", QString("<u>mb_decode_numericentity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_detect_encoding", QString("<u>mb_detect_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_detect_order", QString("<u>mb_detect_order</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_encode_mimeheader", QString("<u>mb_encode_mimeheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_encode_numericentity", QString("<u>mb_encode_numericentity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_encoding_aliases", QString("<u>mb_encoding_aliases</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg", QString("<u>mb_ereg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_match", QString("<u>mb_ereg_match</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_replace", QString("<u>mb_ereg_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search", QString("<u>mb_ereg_search</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search_getpos", QString("<u>mb_ereg_search_getpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search_getregs", QString("<u>mb_ereg_search_getregs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search_init", QString("<u>mb_ereg_search_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search_pos", QString("<u>mb_ereg_search_pos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search_regs", QString("<u>mb_ereg_search_regs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_ereg_search_setpos", QString("<u>mb_ereg_search_setpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_eregi", QString("<u>mb_eregi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_eregi_replace", QString("<u>mb_eregi_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_get_info", QString("<u>mb_get_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_http_input", QString("<u>mb_http_input</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_http_output", QString("<u>mb_http_output</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_internal_encoding", QString("<u>mb_internal_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_language", QString("<u>mb_language</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_list_encodings", QString("<u>mb_list_encodings</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_output_handler", QString("<u>mb_output_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_parse_str", QString("<u>mb_parse_str</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_preferred_mime_name", QString("<u>mb_preferred_mime_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_regex_encoding", QString("<u>mb_regex_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_regex_set_options", QString("<u>mb_regex_set_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_send_mail", QString("<u>mb_send_mail</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_split", QString("<u>mb_split</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strcut", QString("<u>mb_strcut</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strimwidth", QString("<u>mb_strimwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_stripos", QString("<u>mb_stripos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_stristr", QString("<u>mb_stristr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strlen", QString("<u>mb_strlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strpos", QString("<u>mb_strpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strrchr", QString("<u>mb_strrchr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strrichr", QString("<u>mb_strrichr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strripos", QString("<u>mb_strripos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strrpos", QString("<u>mb_strrpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strstr", QString("<u>mb_strstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strtolower", QString("<u>mb_strtolower</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strtoupper", QString("<u>mb_strtoupper</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_strwidth", QString("<u>mb_strwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_substitute_character", QString("<u>mb_substitute_character</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_substr", QString("<u>mb_substr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mb_substr_count", QString("<u>mb_substr_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_cbc", QString("<u>mcrypt_cbc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_cfb", QString("<u>mcrypt_cfb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_create_iv", QString("<u>mcrypt_create_iv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_decrypt", QString("<u>mcrypt_decrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_ecb", QString("<u>mcrypt_ecb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_get_algorithms_name", QString("<u>mcrypt_enc_get_algorithms_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_get_block_size", QString("<u>mcrypt_enc_get_block_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_get_iv_size", QString("<u>mcrypt_enc_get_iv_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_get_key_size", QString("<u>mcrypt_enc_get_key_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_get_modes_name", QString("<u>mcrypt_enc_get_modes_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_get_supported_key_sizes", QString("<u>mcrypt_enc_get_supported_key_sizes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_is_block_algorithm", QString("<u>mcrypt_enc_is_block_algorithm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_is_block_algorithm_mode", QString("<u>mcrypt_enc_is_block_algorithm_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_is_block_mode", QString("<u>mcrypt_enc_is_block_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_enc_self_test", QString("<u>mcrypt_enc_self_test</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_encrypt", QString("<u>mcrypt_encrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_generic", QString("<u>mcrypt_generic</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_generic_deinit", QString("<u>mcrypt_generic_deinit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_generic_end", QString("<u>mcrypt_generic_end</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_generic_init", QString("<u>mcrypt_generic_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_get_block_size", QString("<u>mcrypt_get_block_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_get_cipher_name", QString("<u>mcrypt_get_cipher_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_get_iv_size", QString("<u>mcrypt_get_iv_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_get_key_size", QString("<u>mcrypt_get_key_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_list_algorithms", QString("<u>mcrypt_list_algorithms</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_list_modes", QString("<u>mcrypt_list_modes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_close", QString("<u>mcrypt_module_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_get_algo_block_size", QString("<u>mcrypt_module_get_algo_block_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_get_algo_key_size", QString("<u>mcrypt_module_get_algo_key_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_get_supported_key_sizes", QString("<u>mcrypt_module_get_supported_key_sizes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_is_block_algorithm", QString("<u>mcrypt_module_is_block_algorithm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_is_block_algorithm_mode", QString("<u>mcrypt_module_is_block_algorithm_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_is_block_mode", QString("<u>mcrypt_module_is_block_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_open", QString("<u>mcrypt_module_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_module_self_test", QString("<u>mcrypt_module_self_test</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mcrypt_ofb", QString("<u>mcrypt_ofb</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("md5", QString("string <u>md5</u>(<b>string $str [, bool $raw_output = false ]</b>) <br />%1").arg(tr("Calculate the md5 hash of a string")));
//  data.insert("md5_file", QString("<u>md5_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mdecrypt_generic", QString("<u>mdecrypt_generic</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("memcache", QString("<u>memcache</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("memcache_debug", QString("<u>memcache_debug</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("memcached", QString("<u>memcached</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("memory_get_peak_usage", QString("<u>memory_get_peak_usage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("memory_get_usage", QString("<u>memory_get_usage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("messageformatter", QString("<u>messageformatter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("metaphone", QString("<u>metaphone</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("method_exists", QString("<u>method_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mhash", QString("<u>mhash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mhash_count", QString("<u>mhash_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mhash_get_block_size", QString("<u>mhash_get_block_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mhash_get_hash_name", QString("<u>mhash_get_hash_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mhash_keygen_s2k", QString("<u>mhash_keygen_s2k</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("microtime", QString("mixed <u>microtime</u>(<b>[bool $get_as_float = false]</b>) <br />%1").arg(tr(" Return current Unix timestamp with microseconds.")));
//  data.insert("mime_content_type", QString("<u>mime_content_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("min", QString("<u>min</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ming_keypress", QString("<u>ming_keypress</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ming_setcubicthreshold", QString("<u>ming_setcubicthreshold</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ming_setscale", QString("<u>ming_setscale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ming_setswfcompression", QString("<u>ming_setswfcompression</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ming_useconstants", QString("<u>ming_useconstants</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ming_useswfversion", QString("<u>ming_useswfversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mkdir", QString("<u>mkdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mktime", QString("<u>mktime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("money_format", QString("<u>money_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongo", QString("<u>mongo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongobindata", QString("<u>mongobindata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongocode", QString("<u>mongocode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongocollection", QString("<u>mongocollection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongoconnectionexception", QString("<u>mongoconnectionexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongocursor", QString("<u>mongocursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongocursorexception", QString("<u>mongocursorexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongocursortimeoutexception", QString("<u>mongocursortimeoutexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongodate", QString("<u>mongodate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongodb", QString("<u>mongodb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongodbref", QString("<u>mongodbref</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongoexception", QString("<u>mongoexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongogridfs", QString("<u>mongogridfs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongogridfscursor", QString("<u>mongogridfscursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongogridfsexception", QString("<u>mongogridfsexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongogridfsfile", QString("<u>mongogridfsfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongoid", QString("<u>mongoid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongoint32", QString("<u>mongoint32</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongoint64", QString("<u>mongoint64</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongolog", QString("<u>mongolog</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongomaxkey", QString("<u>mongomaxkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongominkey", QString("<u>mongominkey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongopool", QString("<u>mongopool</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongoregex", QString("<u>mongoregex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mongotimestamp", QString("<u>mongotimestamp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("move_uploaded_file", QString("<u>move_uploaded_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_back", QString("<u>mqseries_back</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_begin", QString("<u>mqseries_begin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_close", QString("<u>mqseries_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_cmit", QString("<u>mqseries_cmit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_conn", QString("<u>mqseries_conn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_connx", QString("<u>mqseries_connx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_disc", QString("<u>mqseries_disc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_get", QString("<u>mqseries_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_inq", QString("<u>mqseries_inq</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_open", QString("<u>mqseries_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_put", QString("<u>mqseries_put</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_put1", QString("<u>mqseries_put1</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_set", QString("<u>mqseries_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mqseries_strerror", QString("<u>mqseries_strerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_connect", QString("<u>msession_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_count", QString("<u>msession_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_create", QString("<u>msession_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_destroy", QString("<u>msession_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_disconnect", QString("<u>msession_disconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_find", QString("<u>msession_find</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_get", QString("<u>msession_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_get_array", QString("<u>msession_get_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_get_data", QString("<u>msession_get_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_inc", QString("<u>msession_inc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_list", QString("<u>msession_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_listvar", QString("<u>msession_listvar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_lock", QString("<u>msession_lock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_plugin", QString("<u>msession_plugin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_randstr", QString("<u>msession_randstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_set", QString("<u>msession_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_set_array", QString("<u>msession_set_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_set_data", QString("<u>msession_set_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_timeout", QString("<u>msession_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_uniq", QString("<u>msession_uniq</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msession_unlock", QString("<u>msession_unlock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_get_queue", QString("<u>msg_get_queue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_queue_exists", QString("<u>msg_queue_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_receive", QString("<u>msg_receive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_remove_queue", QString("<u>msg_remove_queue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_send", QString("<u>msg_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_set_queue", QString("<u>msg_set_queue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msg_stat_queue", QString("<u>msg_stat_queue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql", QString("<u>msql</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_affected_rows", QString("<u>msql_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_close", QString("<u>msql_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_connect", QString("<u>msql_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_create_db", QString("<u>msql_create_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_createdb", QString("<u>msql_createdb</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_data_seek", QString("<u>msql_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_db_query", QString("<u>msql_db_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_dbname", QString("<u>msql_dbname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_drop_db", QString("<u>msql_drop_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_error", QString("<u>msql_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fetch_array", QString("<u>msql_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fetch_field", QString("<u>msql_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fetch_object", QString("<u>msql_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fetch_row", QString("<u>msql_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_field_flags", QString("<u>msql_field_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_field_len", QString("<u>msql_field_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_field_name", QString("<u>msql_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_field_seek", QString("<u>msql_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_field_table", QString("<u>msql_field_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_field_type", QString("<u>msql_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fieldflags", QString("<u>msql_fieldflags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fieldlen", QString("<u>msql_fieldlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fieldname", QString("<u>msql_fieldname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fieldtable", QString("<u>msql_fieldtable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_fieldtype", QString("<u>msql_fieldtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_free_result", QString("<u>msql_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_list_dbs", QString("<u>msql_list_dbs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_list_fields", QString("<u>msql_list_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_list_tables", QString("<u>msql_list_tables</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_num_fields", QString("<u>msql_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_num_rows", QString("<u>msql_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_numfields", QString("<u>msql_numfields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_numrows", QString("<u>msql_numrows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_pconnect", QString("<u>msql_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_query", QString("<u>msql_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_regcase", QString("<u>msql_regcase</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_result", QString("<u>msql_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_select_db", QString("<u>msql_select_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("msql_tablename", QString("<u>msql_tablename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_bind", QString("<u>mssql_bind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_close", QString("<u>mssql_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_connect", QString("<u>mssql_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_data_seek", QString("<u>mssql_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_execute", QString("<u>mssql_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_fetch_array", QString("<u>mssql_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_fetch_assoc", QString("<u>mssql_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_fetch_batch", QString("<u>mssql_fetch_batch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_fetch_field", QString("<u>mssql_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_fetch_object", QString("<u>mssql_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_fetch_row", QString("<u>mssql_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_field_length", QString("<u>mssql_field_length</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_field_name", QString("<u>mssql_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_field_seek", QString("<u>mssql_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_field_type", QString("<u>mssql_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_free_result", QString("<u>mssql_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_free_statement", QString("<u>mssql_free_statement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_get_last_message", QString("<u>mssql_get_last_message</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_guid_string", QString("<u>mssql_guid_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_init", QString("<u>mssql_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_min_error_severity", QString("<u>mssql_min_error_severity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_min_message_severity", QString("<u>mssql_min_message_severity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_next_result", QString("<u>mssql_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_num_fields", QString("<u>mssql_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_num_rows", QString("<u>mssql_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_pconnect", QString("<u>mssql_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_query", QString("<u>mssql_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_result", QString("<u>mssql_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_rows_affected", QString("<u>mssql_rows_affected</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mssql_select_db", QString("<u>mssql_select_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mt_getrandmax", QString("<u>mt_getrandmax</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mt_rand", QString("<u>mt_rand</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("mt_srand", QString("<u>mt_srand</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("multipleiterator", QString("<u>multipleiterator</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_affected_rows", QString("<u>mysql_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_client_encoding", QString("<u>mysql_client_encoding</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_close", QString("<u>mysql_close</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_connect", QString("<u>mysql_connect</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_create_db", QString("<u>mysql_create_db</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_data_seek", QString("<u>mysql_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_db_name", QString("<u>mysql_db_name</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_db_query", QString("<u>mysql_db_query</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_drop_db", QString("<u>mysql_drop_db</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_errno", QString("<u>mysql_errno</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_error", QString("<u>mysql_error</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_escape_string", QString("<u>mysql_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_fetch_array", QString("<u>mysql_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_fetch_assoc", QString("<u>mysql_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_fetch_field", QString("<u>mysql_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_fetch_lengths", QString("<u>mysql_fetch_lengths</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_fetch_object", QString("<u>mysql_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_fetch_row", QString("<u>mysql_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_field_flags", QString("<u>mysql_field_flags</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_field_len", QString("<u>mysql_field_len</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_field_name", QString("<u>mysql_field_name</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_field_seek", QString("<u>mysql_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_field_table", QString("<u>mysql_field_table</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_field_type", QString("<u>mysql_field_type</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_free_result", QString("<u>mysql_free_result</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_get_client_info", QString("<u>mysql_get_client_info</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_get_host_info", QString("<u>mysql_get_host_info</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_get_proto_info", QString("<u>mysql_get_proto_info</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_get_server_info", QString("<u>mysql_get_server_info</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_info", QString("<u>mysql_info</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_insert_id", QString("<u>mysql_insert_id</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_list_dbs", QString("<u>mysql_list_dbs</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_list_fields", QString("<u>mysql_list_fields</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_list_processes", QString("<u>mysql_list_processes</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_list_tables", QString("<u>mysql_list_tables</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_num_fields", QString("<u>mysql_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_num_rows", QString("<u>mysql_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_pconnect", QString("<u>mysql_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_ping", QString("<u>mysql_ping</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_query", QString("<u>mysql_query</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_real_escape_string", QString("<u>mysql_real_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_result", QString("<u>mysql_result</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_select_db", QString("<u>mysql_select_db</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_set_charset", QString("<u>mysql_set_charset</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_stat", QString("<u>mysql_stat</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_tablename", QString("<u>mysql_tablename</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_thread_id", QString("<u>mysql_thread_id</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysql_unbuffered_query", QString("<u>mysql_unbuffered_query</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli", QString("<u>mysqli</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_bind_param", QString("<u>mysqli_bind_param</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_bind_result", QString("<u>mysqli_bind_result</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_client_encoding", QString("<u>mysqli_client_encoding</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_connect", QString("<u>mysqli_connect</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_disable_reads_from_master", QString("<u>mysqli_disable_reads_from_master</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_disable_rpl_parse", QString("<u>mysqli_disable_rpl_parse</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_driver", QString("<u>mysqli_driver</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_enable_reads_from_master", QString("<u>mysqli_enable_reads_from_master</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_enable_rpl_parse", QString("<u>mysqli_enable_rpl_parse</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_escape_string", QString("<u>mysqli_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_execute", QString("<u>mysqli_execute</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_fetch", QString("<u>mysqli_fetch</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_get_metadata", QString("<u>mysqli_get_metadata</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_master_query", QString("<u>mysqli_master_query</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_param_count", QString("<u>mysqli_param_count</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_report", QString("<u>mysqli_report</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_result", QString("<u>mysqli_result</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_rpl_parse_enabled", QString("<u>mysqli_rpl_parse_enabled</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_rpl_probe", QString("<u>mysqli_rpl_probe</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_rpl_query_type", QString("<u>mysqli_rpl_query_type</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_send_long_data", QString("<u>mysqli_send_long_data</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_send_query", QString("<u>mysqli_send_query</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_set_opt", QString("<u>mysqli_set_opt</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_slave_query", QString("<u>mysqli_slave_query</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_stmt", QString("<u>mysqli_stmt</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqli_warning", QString("<u>mysqli_warning</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_ms_get_last_used_connection", QString("<u>mysqlnd_ms_get_last_used_connection</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_ms_get_stats", QString("<u>mysqlnd_ms_get_stats</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_ms_match_wild", QString("<u>mysqlnd_ms_match_wild</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_ms_query_is_select", QString("<u>mysqlnd_ms_query_is_select</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_ms_set_user_pick_server", QString("<u>mysqlnd_ms_set_user_pick_server</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_change_handler", QString("<u>mysqlnd_qc_change_handler</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_clear_cache", QString("<u>mysqlnd_qc_clear_cache</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_get_cache_info", QString("<u>mysqlnd_qc_get_cache_info</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_get_core_stats", QString("<u>mysqlnd_qc_get_core_stats</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_get_handler", QString("<u>mysqlnd_qc_get_handler</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_get_query_trace_log", QString("<u>mysqlnd_qc_get_query_trace_log</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_qc_set_user_handlers", QString("<u>mysqlnd_qc_set_user_handlers</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_uh_convert_to_mysqlnd", QString("<u>mysqlnd_uh_convert_to_mysqlnd</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_uh_set_connection_proxy", QString("<u>mysqlnd_uh_set_connection_proxy</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("mysqlnd_uh_set_statement_proxy", QString("<u>mysqlnd_uh_set_statement_proxy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("natcasesort", QString("<u>natcasesort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("natsort", QString("<u>natsort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_addch", QString("<u>ncurses_addch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_addchnstr", QString("<u>ncurses_addchnstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_addchstr", QString("<u>ncurses_addchstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_addnstr", QString("<u>ncurses_addnstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_addstr", QString("<u>ncurses_addstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_assume_default_colors", QString("<u>ncurses_assume_default_colors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_attroff", QString("<u>ncurses_attroff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_attron", QString("<u>ncurses_attron</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_attrset", QString("<u>ncurses_attrset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_baudrate", QString("<u>ncurses_baudrate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_beep", QString("<u>ncurses_beep</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_bkgd", QString("<u>ncurses_bkgd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_bkgdset", QString("<u>ncurses_bkgdset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_border", QString("<u>ncurses_border</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_bottom_panel", QString("<u>ncurses_bottom_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_can_change_color", QString("<u>ncurses_can_change_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_cbreak", QString("<u>ncurses_cbreak</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_clear", QString("<u>ncurses_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_clrtobot", QString("<u>ncurses_clrtobot</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_clrtoeol", QString("<u>ncurses_clrtoeol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_color_content", QString("<u>ncurses_color_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_color_set", QString("<u>ncurses_color_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_curs_set", QString("<u>ncurses_curs_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_def_prog_mode", QString("<u>ncurses_def_prog_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_def_shell_mode", QString("<u>ncurses_def_shell_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_define_key", QString("<u>ncurses_define_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_del_panel", QString("<u>ncurses_del_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_delay_output", QString("<u>ncurses_delay_output</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_delch", QString("<u>ncurses_delch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_deleteln", QString("<u>ncurses_deleteln</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_delwin", QString("<u>ncurses_delwin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_doupdate", QString("<u>ncurses_doupdate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_echo", QString("<u>ncurses_echo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_echochar", QString("<u>ncurses_echochar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_end", QString("<u>ncurses_end</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_erase", QString("<u>ncurses_erase</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_erasechar", QString("<u>ncurses_erasechar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_filter", QString("<u>ncurses_filter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_flash", QString("<u>ncurses_flash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_flushinp", QString("<u>ncurses_flushinp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_getch", QString("<u>ncurses_getch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_getmaxyx", QString("<u>ncurses_getmaxyx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_getmouse", QString("<u>ncurses_getmouse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_getyx", QString("<u>ncurses_getyx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_halfdelay", QString("<u>ncurses_halfdelay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_has_colors", QString("<u>ncurses_has_colors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_has_ic", QString("<u>ncurses_has_ic</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_has_il", QString("<u>ncurses_has_il</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_has_key", QString("<u>ncurses_has_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_hide_panel", QString("<u>ncurses_hide_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_hline", QString("<u>ncurses_hline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_inch", QString("<u>ncurses_inch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_init", QString("<u>ncurses_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_init_color", QString("<u>ncurses_init_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_init_pair", QString("<u>ncurses_init_pair</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_insch", QString("<u>ncurses_insch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_insdelln", QString("<u>ncurses_insdelln</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_insertln", QString("<u>ncurses_insertln</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_insstr", QString("<u>ncurses_insstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_instr", QString("<u>ncurses_instr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_isendwin", QString("<u>ncurses_isendwin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_keyok", QString("<u>ncurses_keyok</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_keypad", QString("<u>ncurses_keypad</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_killchar", QString("<u>ncurses_killchar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_longname", QString("<u>ncurses_longname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_meta", QString("<u>ncurses_meta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mouse_trafo", QString("<u>ncurses_mouse_trafo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mouseinterval", QString("<u>ncurses_mouseinterval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mousemask", QString("<u>ncurses_mousemask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_move", QString("<u>ncurses_move</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_move_panel", QString("<u>ncurses_move_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvaddch", QString("<u>ncurses_mvaddch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvaddchnstr", QString("<u>ncurses_mvaddchnstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvaddchstr", QString("<u>ncurses_mvaddchstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvaddnstr", QString("<u>ncurses_mvaddnstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvaddstr", QString("<u>ncurses_mvaddstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvcur", QString("<u>ncurses_mvcur</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvdelch", QString("<u>ncurses_mvdelch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvgetch", QString("<u>ncurses_mvgetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvhline", QString("<u>ncurses_mvhline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvinch", QString("<u>ncurses_mvinch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvvline", QString("<u>ncurses_mvvline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_mvwaddstr", QString("<u>ncurses_mvwaddstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_napms", QString("<u>ncurses_napms</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_new_panel", QString("<u>ncurses_new_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_newpad", QString("<u>ncurses_newpad</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_newwin", QString("<u>ncurses_newwin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_nl", QString("<u>ncurses_nl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_nocbreak", QString("<u>ncurses_nocbreak</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_noecho", QString("<u>ncurses_noecho</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_nonl", QString("<u>ncurses_nonl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_noqiflush", QString("<u>ncurses_noqiflush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_noraw", QString("<u>ncurses_noraw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_pair_content", QString("<u>ncurses_pair_content</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_panel_above", QString("<u>ncurses_panel_above</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_panel_below", QString("<u>ncurses_panel_below</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_panel_window", QString("<u>ncurses_panel_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_pnoutrefresh", QString("<u>ncurses_pnoutrefresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_prefresh", QString("<u>ncurses_prefresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_putp", QString("<u>ncurses_putp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_qiflush", QString("<u>ncurses_qiflush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_raw", QString("<u>ncurses_raw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_refresh", QString("<u>ncurses_refresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_replace_panel", QString("<u>ncurses_replace_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_reset_prog_mode", QString("<u>ncurses_reset_prog_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_reset_shell_mode", QString("<u>ncurses_reset_shell_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_resetty", QString("<u>ncurses_resetty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_savetty", QString("<u>ncurses_savetty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_scr_dump", QString("<u>ncurses_scr_dump</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_scr_init", QString("<u>ncurses_scr_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_scr_restore", QString("<u>ncurses_scr_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_scr_set", QString("<u>ncurses_scr_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_scrl", QString("<u>ncurses_scrl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_show_panel", QString("<u>ncurses_show_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_attr", QString("<u>ncurses_slk_attr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_attroff", QString("<u>ncurses_slk_attroff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_attron", QString("<u>ncurses_slk_attron</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_attrset", QString("<u>ncurses_slk_attrset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_clear", QString("<u>ncurses_slk_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_color", QString("<u>ncurses_slk_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_init", QString("<u>ncurses_slk_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_noutrefresh", QString("<u>ncurses_slk_noutrefresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_refresh", QString("<u>ncurses_slk_refresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_restore", QString("<u>ncurses_slk_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_set", QString("<u>ncurses_slk_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_slk_touch", QString("<u>ncurses_slk_touch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_standend", QString("<u>ncurses_standend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_standout", QString("<u>ncurses_standout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_start_color", QString("<u>ncurses_start_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_termattrs", QString("<u>ncurses_termattrs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_termname", QString("<u>ncurses_termname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_timeout", QString("<u>ncurses_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_top_panel", QString("<u>ncurses_top_panel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_typeahead", QString("<u>ncurses_typeahead</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_ungetch", QString("<u>ncurses_ungetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_ungetmouse", QString("<u>ncurses_ungetmouse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_update_panels", QString("<u>ncurses_update_panels</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_use_default_colors", QString("<u>ncurses_use_default_colors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_use_env", QString("<u>ncurses_use_env</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_use_extended_names", QString("<u>ncurses_use_extended_names</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_vidattr", QString("<u>ncurses_vidattr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_vline", QString("<u>ncurses_vline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_waddch", QString("<u>ncurses_waddch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_waddstr", QString("<u>ncurses_waddstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wattroff", QString("<u>ncurses_wattroff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wattron", QString("<u>ncurses_wattron</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wattrset", QString("<u>ncurses_wattrset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wborder", QString("<u>ncurses_wborder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wclear", QString("<u>ncurses_wclear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wcolor_set", QString("<u>ncurses_wcolor_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_werase", QString("<u>ncurses_werase</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wgetch", QString("<u>ncurses_wgetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_whline", QString("<u>ncurses_whline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wmouse_trafo", QString("<u>ncurses_wmouse_trafo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wmove", QString("<u>ncurses_wmove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wnoutrefresh", QString("<u>ncurses_wnoutrefresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wrefresh", QString("<u>ncurses_wrefresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wstandend", QString("<u>ncurses_wstandend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wstandout", QString("<u>ncurses_wstandout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ncurses_wvline", QString("<u>ncurses_wvline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newinstance", QString("<u>newinstance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newinstanceargs", QString("<u>newinstanceargs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newinstancewithoutconstructor", QString("<u>newinstancewithoutconstructor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_bell", QString("<u>newt_bell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_button", QString("<u>newt_button</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_button_bar", QString("<u>newt_button_bar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_centered_window", QString("<u>newt_centered_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox", QString("<u>newt_checkbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_get_value", QString("<u>newt_checkbox_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_set_flags", QString("<u>newt_checkbox_set_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_set_value", QString("<u>newt_checkbox_set_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree", QString("<u>newt_checkbox_tree</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_add_item", QString("<u>newt_checkbox_tree_add_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_find_item", QString("<u>newt_checkbox_tree_find_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_get_current", QString("<u>newt_checkbox_tree_get_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_get_entry_value", QString("<u>newt_checkbox_tree_get_entry_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_get_multi_selection", QString("<u>newt_checkbox_tree_get_multi_selection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_get_selection", QString("<u>newt_checkbox_tree_get_selection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_multi", QString("<u>newt_checkbox_tree_multi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_set_current", QString("<u>newt_checkbox_tree_set_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_set_entry", QString("<u>newt_checkbox_tree_set_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_set_entry_value", QString("<u>newt_checkbox_tree_set_entry_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_checkbox_tree_set_width", QString("<u>newt_checkbox_tree_set_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_clear_key_buffer", QString("<u>newt_clear_key_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_cls", QString("<u>newt_cls</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_compact_button", QString("<u>newt_compact_button</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_component_add_callback", QString("<u>newt_component_add_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_component_takes_focus", QString("<u>newt_component_takes_focus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_create_grid", QString("<u>newt_create_grid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_cursor_off", QString("<u>newt_cursor_off</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_cursor_on", QString("<u>newt_cursor_on</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_delay", QString("<u>newt_delay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_draw_form", QString("<u>newt_draw_form</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_draw_root_text", QString("<u>newt_draw_root_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_entry", QString("<u>newt_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_entry_get_value", QString("<u>newt_entry_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_entry_set", QString("<u>newt_entry_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_entry_set_filter", QString("<u>newt_entry_set_filter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_entry_set_flags", QString("<u>newt_entry_set_flags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_finished", QString("<u>newt_finished</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form", QString("<u>newt_form</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_add_component", QString("<u>newt_form_add_component</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_add_components", QString("<u>newt_form_add_components</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_add_hot_key", QString("<u>newt_form_add_hot_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_destroy", QString("<u>newt_form_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_get_current", QString("<u>newt_form_get_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_run", QString("<u>newt_form_run</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_set_background", QString("<u>newt_form_set_background</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_set_height", QString("<u>newt_form_set_height</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_set_size", QString("<u>newt_form_set_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_set_timer", QString("<u>newt_form_set_timer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_set_width", QString("<u>newt_form_set_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_form_watch_fd", QString("<u>newt_form_watch_fd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_get_screen_size", QString("<u>newt_get_screen_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_add_components_to_form", QString("<u>newt_grid_add_components_to_form</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_basic_window", QString("<u>newt_grid_basic_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_free", QString("<u>newt_grid_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_get_size", QString("<u>newt_grid_get_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_h_close_stacked", QString("<u>newt_grid_h_close_stacked</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_h_stacked", QString("<u>newt_grid_h_stacked</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_place", QString("<u>newt_grid_place</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_set_field", QString("<u>newt_grid_set_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_simple_window", QString("<u>newt_grid_simple_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_v_close_stacked", QString("<u>newt_grid_v_close_stacked</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_v_stacked", QString("<u>newt_grid_v_stacked</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_wrapped_window", QString("<u>newt_grid_wrapped_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_grid_wrapped_window_at", QString("<u>newt_grid_wrapped_window_at</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_init", QString("<u>newt_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_label", QString("<u>newt_label</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_label_set_text", QString("<u>newt_label_set_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox", QString("<u>newt_listbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_append_entry", QString("<u>newt_listbox_append_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_clear", QString("<u>newt_listbox_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_clear_selection", QString("<u>newt_listbox_clear_selection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_delete_entry", QString("<u>newt_listbox_delete_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_get_current", QString("<u>newt_listbox_get_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_get_selection", QString("<u>newt_listbox_get_selection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_insert_entry", QString("<u>newt_listbox_insert_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_item_count", QString("<u>newt_listbox_item_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_select_item", QString("<u>newt_listbox_select_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_set_current", QString("<u>newt_listbox_set_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_set_current_by_key", QString("<u>newt_listbox_set_current_by_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_set_data", QString("<u>newt_listbox_set_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_set_entry", QString("<u>newt_listbox_set_entry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listbox_set_width", QString("<u>newt_listbox_set_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listitem", QString("<u>newt_listitem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listitem_get_data", QString("<u>newt_listitem_get_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_listitem_set", QString("<u>newt_listitem_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_open_window", QString("<u>newt_open_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_pop_help_line", QString("<u>newt_pop_help_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_pop_window", QString("<u>newt_pop_window</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_push_help_line", QString("<u>newt_push_help_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_radio_get_current", QString("<u>newt_radio_get_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_radiobutton", QString("<u>newt_radiobutton</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_redraw_help_line", QString("<u>newt_redraw_help_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_reflow_text", QString("<u>newt_reflow_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_refresh", QString("<u>newt_refresh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_resize_screen", QString("<u>newt_resize_screen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_resume", QString("<u>newt_resume</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_run_form", QString("<u>newt_run_form</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_scale", QString("<u>newt_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_scale_set", QString("<u>newt_scale_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_scrollbar_set", QString("<u>newt_scrollbar_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_set_help_callback", QString("<u>newt_set_help_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_set_suspend_callback", QString("<u>newt_set_suspend_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_suspend", QString("<u>newt_suspend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_textbox", QString("<u>newt_textbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_textbox_get_num_lines", QString("<u>newt_textbox_get_num_lines</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_textbox_reflowed", QString("<u>newt_textbox_reflowed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_textbox_set_height", QString("<u>newt_textbox_set_height</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_textbox_set_text", QString("<u>newt_textbox_set_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_vertical_scrollbar", QString("<u>newt_vertical_scrollbar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_wait_for_key", QString("<u>newt_wait_for_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_win_choice", QString("<u>newt_win_choice</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_win_entries", QString("<u>newt_win_entries</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_win_menu", QString("<u>newt_win_menu</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_win_message", QString("<u>newt_win_message</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_win_messagev", QString("<u>newt_win_messagev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("newt_win_ternary", QString("<u>newt_win_ternary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("next", QString("<u>next</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ngettext", QString("<u>ngettext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("nl2br", QString("<u>nl2br</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("nl_langinfo", QString("<u>nl_langinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("norewinditerator", QString("<u>norewinditerator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("normalizer", QString("<u>normalizer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_body", QString("<u>notes_body</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_copy_db", QString("<u>notes_copy_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_create_db", QString("<u>notes_create_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_create_note", QString("<u>notes_create_note</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_drop_db", QString("<u>notes_drop_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_find_note", QString("<u>notes_find_note</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_header_info", QString("<u>notes_header_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_list_msgs", QString("<u>notes_list_msgs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_mark_read", QString("<u>notes_mark_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_mark_unread", QString("<u>notes_mark_unread</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_nav_create", QString("<u>notes_nav_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_search", QString("<u>notes_search</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_unread", QString("<u>notes_unread</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("notes_version", QString("<u>notes_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("nsapi_request_headers", QString("<u>nsapi_request_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("nsapi_response_headers", QString("<u>nsapi_response_headers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("nsapi_virtual", QString("<u>nsapi_virtual</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("nthmac", QString("<u>nthmac</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("number_format", QString("string <u>number_format</u>(<b>float $number , int $decimals = 0, string $dec_point = '.', string $thousands_sep = ','</b>) <br />%1").arg(tr("Format a number with grouped thousands")));
//  data.insert("numberformatter", QString("<u>numberformatter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oauth", QString("<u>oauth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oauth_get_sbs", QString("<u>oauth_get_sbs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oauth_urlencode", QString("<u>oauth_urlencode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oauthexception", QString("<u>oauthexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oauthprovider", QString("<u>oauthprovider</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_clean", QString("<u>ob_clean</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_deflatehandler", QString("<u>ob_deflatehandler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_end_clean", QString("<u>ob_end_clean</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_end_flush", QString("<u>ob_end_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_etaghandler", QString("<u>ob_etaghandler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_flush", QString("<u>ob_flush</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ob_get_clean", QString("string <u>ob_get_clean</u>(<b></b>) <br />%1").arg(tr("Get current buffer contents and delete current output buffer.")));
//  data.insert("ob_get_contents", QString("<u>ob_get_contents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_get_flush", QString("<u>ob_get_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_get_length", QString("<u>ob_get_length</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_get_level", QString("<u>ob_get_level</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_get_status", QString("<u>ob_get_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_gzhandler", QString("<u>ob_gzhandler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_iconv_handler", QString("<u>ob_iconv_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_implicit_flush", QString("<u>ob_implicit_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_inflatehandler", QString("<u>ob_inflatehandler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ob_list_handlers", QString("<u>ob_list_handlers</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ob_start", QString("bool <u>ob_start</u>(<b>[ callable $output_callback = NULL [, int $chunk_size = 0 [, int $flags = PHP_OUTPUT_HANDLER_STDFLAGS ]]]</b>) <br />%1").arg(tr("Turn on output buffering.")));
//  data.insert("ob_tidyhandler", QString("<u>ob_tidyhandler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_bind_array_by_name", QString("<u>oci_bind_array_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_bind_by_name", QString("<u>oci_bind_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_cancel", QString("<u>oci_cancel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_client_version", QString("<u>oci_client_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_close", QString("<u>oci_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_append", QString("<u>oci_collection_append</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_assign", QString("<u>oci_collection_assign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_element_assign", QString("<u>oci_collection_element_assign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_element_get", QString("<u>oci_collection_element_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_free", QString("<u>oci_collection_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_max", QString("<u>oci_collection_max</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_size", QString("<u>oci_collection_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_collection_trim", QString("<u>oci_collection_trim</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_commit", QString("<u>oci_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_connect", QString("<u>oci_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_define_by_name", QString("<u>oci_define_by_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_error", QString("<u>oci_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_execute", QString("<u>oci_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_fetch", QString("<u>oci_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_fetch_all", QString("<u>oci_fetch_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_fetch_array", QString("<u>oci_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_fetch_assoc", QString("<u>oci_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_fetch_object", QString("<u>oci_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_fetch_row", QString("<u>oci_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_is_null", QString("<u>oci_field_is_null</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_name", QString("<u>oci_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_precision", QString("<u>oci_field_precision</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_scale", QString("<u>oci_field_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_size", QString("<u>oci_field_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_type", QString("<u>oci_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_field_type_raw", QString("<u>oci_field_type_raw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_free_statement", QString("<u>oci_free_statement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_internal_debug", QString("<u>oci_internal_debug</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_append", QString("<u>oci_lob_append</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_close", QString("<u>oci_lob_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_copy", QString("<u>oci_lob_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_eof", QString("<u>oci_lob_eof</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_erase", QString("<u>oci_lob_erase</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_export", QString("<u>oci_lob_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_flush", QString("<u>oci_lob_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_free", QString("<u>oci_lob_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_getbuffering", QString("<u>oci_lob_getbuffering</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_import", QString("<u>oci_lob_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_is_equal", QString("<u>oci_lob_is_equal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_load", QString("<u>oci_lob_load</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_read", QString("<u>oci_lob_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_rewind", QString("<u>oci_lob_rewind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_save", QString("<u>oci_lob_save</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_savefile", QString("<u>oci_lob_savefile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_seek", QString("<u>oci_lob_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_setbuffering", QString("<u>oci_lob_setbuffering</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_size", QString("<u>oci_lob_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_tell", QString("<u>oci_lob_tell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_truncate", QString("<u>oci_lob_truncate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_write", QString("<u>oci_lob_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_writetemporary", QString("<u>oci_lob_writetemporary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_lob_writetofile", QString("<u>oci_lob_writetofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_new_collection", QString("<u>oci_new_collection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_new_connect", QString("<u>oci_new_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_new_cursor", QString("<u>oci_new_cursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_new_descriptor", QString("<u>oci_new_descriptor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_num_fields", QString("<u>oci_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_num_rows", QString("<u>oci_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_parse", QString("<u>oci_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_password_change", QString("<u>oci_password_change</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_pconnect", QString("<u>oci_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_result", QString("<u>oci_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_rollback", QString("<u>oci_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_server_version", QString("<u>oci_server_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_set_action", QString("<u>oci_set_action</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_set_client_identifier", QString("<u>oci_set_client_identifier</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_set_client_info", QString("<u>oci_set_client_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_set_edition", QString("<u>oci_set_edition</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_set_module_name", QString("<u>oci_set_module_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_set_prefetch", QString("<u>oci_set_prefetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("oci_statement_type", QString("<u>oci_statement_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocibindbyname", QString("<u>ocibindbyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicancel", QString("<u>ocicancel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicloselob", QString("<u>ocicloselob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicollappend", QString("<u>ocicollappend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicollassign", QString("<u>ocicollassign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicollassignelem", QString("<u>ocicollassignelem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicollgetelem", QString("<u>ocicollgetelem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicollmax", QString("<u>ocicollmax</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicollsize", QString("<u>ocicollsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolltrim", QString("<u>ocicolltrim</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumnisnull", QString("<u>ocicolumnisnull</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumnname", QString("<u>ocicolumnname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumnprecision", QString("<u>ocicolumnprecision</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumnscale", QString("<u>ocicolumnscale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumnsize", QString("<u>ocicolumnsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumntype", QString("<u>ocicolumntype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicolumntyperaw", QString("<u>ocicolumntyperaw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocicommit", QString("<u>ocicommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocidefinebyname", QString("<u>ocidefinebyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocierror", QString("<u>ocierror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociexecute", QString("<u>ociexecute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifetch", QString("<u>ocifetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifetchinto", QString("<u>ocifetchinto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifetchstatement", QString("<u>ocifetchstatement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifreecollection", QString("<u>ocifreecollection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifreecursor", QString("<u>ocifreecursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifreedesc", QString("<u>ocifreedesc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocifreestatement", QString("<u>ocifreestatement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociinternaldebug", QString("<u>ociinternaldebug</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociloadlob", QString("<u>ociloadlob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocilogoff", QString("<u>ocilogoff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocilogon", QString("<u>ocilogon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocinewcollection", QString("<u>ocinewcollection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocinewcursor", QString("<u>ocinewcursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocinewdescriptor", QString("<u>ocinewdescriptor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocinlogon", QString("<u>ocinlogon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocinumcols", QString("<u>ocinumcols</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociparse", QString("<u>ociparse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociplogon", QString("<u>ociplogon</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociresult", QString("<u>ociresult</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocirollback", QString("<u>ocirollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocirowcount", QString("<u>ocirowcount</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocisavelob", QString("<u>ocisavelob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocisavelobfile", QString("<u>ocisavelobfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociserverversion", QString("<u>ociserverversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocisetprefetch", QString("<u>ocisetprefetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ocistatementtype", QString("<u>ocistatementtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociwritelobtofile", QString("<u>ociwritelobtofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ociwritetemporarylob", QString("<u>ociwritetemporarylob</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("octdec", QString("<u>octdec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_autocommit", QString("<u>odbc_autocommit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_binmode", QString("<u>odbc_binmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_close", QString("<u>odbc_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_close_all", QString("<u>odbc_close_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_columnprivileges", QString("<u>odbc_columnprivileges</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_columns", QString("<u>odbc_columns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_commit", QString("<u>odbc_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_connect", QString("<u>odbc_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_cursor", QString("<u>odbc_cursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_data_source", QString("<u>odbc_data_source</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_do", QString("<u>odbc_do</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_error", QString("<u>odbc_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_errormsg", QString("<u>odbc_errormsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_exec", QString("<u>odbc_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_execute", QString("<u>odbc_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_fetch_array", QString("<u>odbc_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_fetch_into", QString("<u>odbc_fetch_into</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_fetch_object", QString("<u>odbc_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_fetch_row", QString("<u>odbc_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_field_len", QString("<u>odbc_field_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_field_name", QString("<u>odbc_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_field_num", QString("<u>odbc_field_num</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_field_precision", QString("<u>odbc_field_precision</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_field_scale", QString("<u>odbc_field_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_field_type", QString("<u>odbc_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_foreignkeys", QString("<u>odbc_foreignkeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_free_result", QString("<u>odbc_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_gettypeinfo", QString("<u>odbc_gettypeinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_longreadlen", QString("<u>odbc_longreadlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_next_result", QString("<u>odbc_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_num_fields", QString("<u>odbc_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_num_rows", QString("<u>odbc_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_pconnect", QString("<u>odbc_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_prepare", QString("<u>odbc_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_primarykeys", QString("<u>odbc_primarykeys</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_procedurecolumns", QString("<u>odbc_procedurecolumns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_procedures", QString("<u>odbc_procedures</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_result", QString("<u>odbc_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_result_all", QString("<u>odbc_result_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_rollback", QString("<u>odbc_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_setoption", QString("<u>odbc_setoption</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_specialcolumns", QString("<u>odbc_specialcolumns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_statistics", QString("<u>odbc_statistics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_tableprivileges", QString("<u>odbc_tableprivileges</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("odbc_tables", QString("<u>odbc_tables</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_buffer_create", QString("<u>openal_buffer_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_buffer_data", QString("<u>openal_buffer_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_buffer_destroy", QString("<u>openal_buffer_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_buffer_get", QString("<u>openal_buffer_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_buffer_loadwav", QString("<u>openal_buffer_loadwav</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_context_create", QString("<u>openal_context_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_context_current", QString("<u>openal_context_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_context_destroy", QString("<u>openal_context_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_context_process", QString("<u>openal_context_process</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_context_suspend", QString("<u>openal_context_suspend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_device_close", QString("<u>openal_device_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_device_open", QString("<u>openal_device_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_listener_get", QString("<u>openal_listener_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_listener_set", QString("<u>openal_listener_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_create", QString("<u>openal_source_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_destroy", QString("<u>openal_source_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_get", QString("<u>openal_source_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_pause", QString("<u>openal_source_pause</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_play", QString("<u>openal_source_play</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_rewind", QString("<u>openal_source_rewind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_set", QString("<u>openal_source_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_source_stop", QString("<u>openal_source_stop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openal_stream", QString("<u>openal_stream</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("opendir", QString("resource <u>opendir</u>(<b>string $path [, resource $context ]</b>) <br />%1").arg(tr("Open directory handle")));
//  data.insert("openlog", QString("<u>openlog</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_cipher_iv_length", QString("<u>openssl_cipher_iv_length</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_csr_export", QString("<u>openssl_csr_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_csr_export_to_file", QString("<u>openssl_csr_export_to_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_csr_get_public_key", QString("<u>openssl_csr_get_public_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_csr_get_subject", QString("<u>openssl_csr_get_subject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_csr_new", QString("<u>openssl_csr_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_csr_sign", QString("<u>openssl_csr_sign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_decrypt", QString("<u>openssl_decrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_dh_compute_key", QString("<u>openssl_dh_compute_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_digest", QString("<u>openssl_digest</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_encrypt", QString("<u>openssl_encrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_error_string", QString("<u>openssl_error_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_free_key", QString("<u>openssl_free_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_get_cipher_methods", QString("<u>openssl_get_cipher_methods</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_get_md_methods", QString("<u>openssl_get_md_methods</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_get_privatekey", QString("<u>openssl_get_privatekey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_get_publickey", QString("<u>openssl_get_publickey</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_open", QString("<u>openssl_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs12_export", QString("<u>openssl_pkcs12_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs12_export_to_file", QString("<u>openssl_pkcs12_export_to_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs12_read", QString("<u>openssl_pkcs12_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs7_decrypt", QString("<u>openssl_pkcs7_decrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs7_encrypt", QString("<u>openssl_pkcs7_encrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs7_sign", QString("<u>openssl_pkcs7_sign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkcs7_verify", QString("<u>openssl_pkcs7_verify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_export", QString("<u>openssl_pkey_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_export_to_file", QString("<u>openssl_pkey_export_to_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_free", QString("<u>openssl_pkey_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_get_details", QString("<u>openssl_pkey_get_details</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_get_private", QString("<u>openssl_pkey_get_private</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_get_public", QString("<u>openssl_pkey_get_public</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_pkey_new", QString("<u>openssl_pkey_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_private_decrypt", QString("<u>openssl_private_decrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_private_encrypt", QString("<u>openssl_private_encrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_public_decrypt", QString("<u>openssl_public_decrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_public_encrypt", QString("<u>openssl_public_encrypt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_random_pseudo_bytes", QString("<u>openssl_random_pseudo_bytes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_seal", QString("<u>openssl_seal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_sign", QString("<u>openssl_sign</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_verify", QString("<u>openssl_verify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_check_private_key", QString("<u>openssl_x509_check_private_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_checkpurpose", QString("<u>openssl_x509_checkpurpose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_export", QString("<u>openssl_x509_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_export_to_file", QString("<u>openssl_x509_export_to_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_free", QString("<u>openssl_x509_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_parse", QString("<u>openssl_x509_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("openssl_x509_read", QString("<u>openssl_x509_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ord", QString("<u>ord</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("outeriterator", QString("<u>outeriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("outofboundsexception", QString("<u>outofboundsexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("outofrangeexception", QString("<u>outofrangeexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("output_add_rewrite_var", QString("<u>output_add_rewrite_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("output_reset_rewrite_vars", QString("<u>output_reset_rewrite_vars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("overflowexception", QString("<u>overflowexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("overload", QString("<u>overload</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("override_function", QString("<u>override_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_close", QString("<u>ovrimos_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_commit", QString("<u>ovrimos_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_connect", QString("<u>ovrimos_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_cursor", QString("<u>ovrimos_cursor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_exec", QString("<u>ovrimos_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_execute", QString("<u>ovrimos_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_fetch_into", QString("<u>ovrimos_fetch_into</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_fetch_row", QString("<u>ovrimos_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_field_len", QString("<u>ovrimos_field_len</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_field_name", QString("<u>ovrimos_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_field_num", QString("<u>ovrimos_field_num</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_field_type", QString("<u>ovrimos_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_free_result", QString("<u>ovrimos_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_longreadlen", QString("<u>ovrimos_longreadlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_num_fields", QString("<u>ovrimos_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_num_rows", QString("<u>ovrimos_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_prepare", QString("<u>ovrimos_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_result", QString("<u>ovrimos_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_result_all", QString("<u>ovrimos_result_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ovrimos_rollback", QString("<u>ovrimos_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pack", QString("<u>pack</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parentiterator", QString("<u>parentiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parse_ini_file", QString("<u>parse_ini_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parse_ini_string", QString("<u>parse_ini_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parse_str", QString("<u>parse_str</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parse_url", QString("<u>parse_url</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parsekit_compile_file", QString("<u>parsekit_compile_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parsekit_compile_string", QString("<u>parsekit_compile_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("parsekit_func_arginfo", QString("<u>parsekit_func_arginfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("passthru", QString("<u>passthru</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pathinfo", QString("<u>pathinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pclose", QString("<u>pclose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_alarm", QString("<u>pcntl_alarm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_exec", QString("<u>pcntl_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_fork", QString("<u>pcntl_fork</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_getpriority", QString("<u>pcntl_getpriority</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_setpriority", QString("<u>pcntl_setpriority</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_signal", QString("<u>pcntl_signal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_signal_dispatch", QString("<u>pcntl_signal_dispatch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_sigprocmask", QString("<u>pcntl_sigprocmask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_sigtimedwait", QString("<u>pcntl_sigtimedwait</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_sigwaitinfo", QString("<u>pcntl_sigwaitinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wait", QString("<u>pcntl_wait</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_waitpid", QString("<u>pcntl_waitpid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wexitstatus", QString("<u>pcntl_wexitstatus</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wifexited", QString("<u>pcntl_wifexited</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wifsignaled", QString("<u>pcntl_wifsignaled</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wifstopped", QString("<u>pcntl_wifstopped</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wstopsig", QString("<u>pcntl_wstopsig</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pcntl_wtermsig", QString("<u>pcntl_wtermsig</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_activate_item", QString("<u>pdf_activate_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_annotation", QString("<u>pdf_add_annotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_bookmark", QString("<u>pdf_add_bookmark</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_launchlink", QString("<u>pdf_add_launchlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_locallink", QString("<u>pdf_add_locallink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_nameddest", QString("<u>pdf_add_nameddest</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_note", QString("<u>pdf_add_note</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_outline", QString("<u>pdf_add_outline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_pdflink", QString("<u>pdf_add_pdflink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_table_cell", QString("<u>pdf_add_table_cell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_textflow", QString("<u>pdf_add_textflow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_thumbnail", QString("<u>pdf_add_thumbnail</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_add_weblink", QString("<u>pdf_add_weblink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_arc", QString("<u>pdf_arc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_arcn", QString("<u>pdf_arcn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_attach_file", QString("<u>pdf_attach_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_document", QString("<u>pdf_begin_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_font", QString("<u>pdf_begin_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_glyph", QString("<u>pdf_begin_glyph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_item", QString("<u>pdf_begin_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_layer", QString("<u>pdf_begin_layer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_page", QString("<u>pdf_begin_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_page_ext", QString("<u>pdf_begin_page_ext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_pattern", QString("<u>pdf_begin_pattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_template", QString("<u>pdf_begin_template</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_begin_template_ext", QString("<u>pdf_begin_template_ext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_circle", QString("<u>pdf_circle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_clip", QString("<u>pdf_clip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_close", QString("<u>pdf_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_close_image", QString("<u>pdf_close_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_close_pdi", QString("<u>pdf_close_pdi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_close_pdi_page", QString("<u>pdf_close_pdi_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_closepath", QString("<u>pdf_closepath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_closepath_fill_stroke", QString("<u>pdf_closepath_fill_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_closepath_stroke", QString("<u>pdf_closepath_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_concat", QString("<u>pdf_concat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_continue_text", QString("<u>pdf_continue_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_3dview", QString("<u>pdf_create_3dview</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_action", QString("<u>pdf_create_action</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_annotation", QString("<u>pdf_create_annotation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_bookmark", QString("<u>pdf_create_bookmark</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_field", QString("<u>pdf_create_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_fieldgroup", QString("<u>pdf_create_fieldgroup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_gstate", QString("<u>pdf_create_gstate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_pvf", QString("<u>pdf_create_pvf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_create_textflow", QString("<u>pdf_create_textflow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_curveto", QString("<u>pdf_curveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_define_layer", QString("<u>pdf_define_layer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_delete", QString("<u>pdf_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_delete_pvf", QString("<u>pdf_delete_pvf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_delete_table", QString("<u>pdf_delete_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_delete_textflow", QString("<u>pdf_delete_textflow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_encoding_set_char", QString("<u>pdf_encoding_set_char</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_document", QString("<u>pdf_end_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_font", QString("<u>pdf_end_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_glyph", QString("<u>pdf_end_glyph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_item", QString("<u>pdf_end_item</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_layer", QString("<u>pdf_end_layer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_page", QString("<u>pdf_end_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_page_ext", QString("<u>pdf_end_page_ext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_pattern", QString("<u>pdf_end_pattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_end_template", QString("<u>pdf_end_template</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_endpath", QString("<u>pdf_endpath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fill", QString("<u>pdf_fill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fill_imageblock", QString("<u>pdf_fill_imageblock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fill_pdfblock", QString("<u>pdf_fill_pdfblock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fill_stroke", QString("<u>pdf_fill_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fill_textblock", QString("<u>pdf_fill_textblock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_findfont", QString("<u>pdf_findfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fit_image", QString("<u>pdf_fit_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fit_pdi_page", QString("<u>pdf_fit_pdi_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fit_table", QString("<u>pdf_fit_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fit_textflow", QString("<u>pdf_fit_textflow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_fit_textline", QString("<u>pdf_fit_textline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_apiname", QString("<u>pdf_get_apiname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_buffer", QString("<u>pdf_get_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_errmsg", QString("<u>pdf_get_errmsg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_errnum", QString("<u>pdf_get_errnum</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_font", QString("<u>pdf_get_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_fontname", QString("<u>pdf_get_fontname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_fontsize", QString("<u>pdf_get_fontsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_image_height", QString("<u>pdf_get_image_height</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_image_width", QString("<u>pdf_get_image_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_majorversion", QString("<u>pdf_get_majorversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_minorversion", QString("<u>pdf_get_minorversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_parameter", QString("<u>pdf_get_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_pdi_parameter", QString("<u>pdf_get_pdi_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_pdi_value", QString("<u>pdf_get_pdi_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_get_value", QString("<u>pdf_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_info_font", QString("<u>pdf_info_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_info_matchbox", QString("<u>pdf_info_matchbox</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_info_table", QString("<u>pdf_info_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_info_textflow", QString("<u>pdf_info_textflow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_info_textline", QString("<u>pdf_info_textline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_initgraphics", QString("<u>pdf_initgraphics</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_lineto", QString("<u>pdf_lineto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_load_3ddata", QString("<u>pdf_load_3ddata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_load_font", QString("<u>pdf_load_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_load_iccprofile", QString("<u>pdf_load_iccprofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_load_image", QString("<u>pdf_load_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_makespotcolor", QString("<u>pdf_makespotcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_moveto", QString("<u>pdf_moveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_new", QString("<u>pdf_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_ccitt", QString("<u>pdf_open_ccitt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_file", QString("<u>pdf_open_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_gif", QString("<u>pdf_open_gif</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_image", QString("<u>pdf_open_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_image_file", QString("<u>pdf_open_image_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_jpeg", QString("<u>pdf_open_jpeg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_memory_image", QString("<u>pdf_open_memory_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_pdi", QString("<u>pdf_open_pdi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_pdi_document", QString("<u>pdf_open_pdi_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_pdi_page", QString("<u>pdf_open_pdi_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_open_tiff", QString("<u>pdf_open_tiff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_pcos_get_number", QString("<u>pdf_pcos_get_number</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_pcos_get_stream", QString("<u>pdf_pcos_get_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_pcos_get_string", QString("<u>pdf_pcos_get_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_place_image", QString("<u>pdf_place_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_place_pdi_page", QString("<u>pdf_place_pdi_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_process_pdi", QString("<u>pdf_process_pdi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_rect", QString("<u>pdf_rect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_restore", QString("<u>pdf_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_resume_page", QString("<u>pdf_resume_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_rotate", QString("<u>pdf_rotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_save", QString("<u>pdf_save</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_scale", QString("<u>pdf_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_border_color", QString("<u>pdf_set_border_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_border_dash", QString("<u>pdf_set_border_dash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_border_style", QString("<u>pdf_set_border_style</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_char_spacing", QString("<u>pdf_set_char_spacing</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_duration", QString("<u>pdf_set_duration</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_gstate", QString("<u>pdf_set_gstate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_horiz_scaling", QString("<u>pdf_set_horiz_scaling</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_info", QString("<u>pdf_set_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_info_author", QString("<u>pdf_set_info_author</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_info_creator", QString("<u>pdf_set_info_creator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_info_keywords", QString("<u>pdf_set_info_keywords</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_info_subject", QString("<u>pdf_set_info_subject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_info_title", QString("<u>pdf_set_info_title</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_layer_dependency", QString("<u>pdf_set_layer_dependency</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_leading", QString("<u>pdf_set_leading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_parameter", QString("<u>pdf_set_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_text_matrix", QString("<u>pdf_set_text_matrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_text_pos", QString("<u>pdf_set_text_pos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_text_rendering", QString("<u>pdf_set_text_rendering</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_text_rise", QString("<u>pdf_set_text_rise</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_value", QString("<u>pdf_set_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_set_word_spacing", QString("<u>pdf_set_word_spacing</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setcolor", QString("<u>pdf_setcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setdash", QString("<u>pdf_setdash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setdashpattern", QString("<u>pdf_setdashpattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setflat", QString("<u>pdf_setflat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setfont", QString("<u>pdf_setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setgray", QString("<u>pdf_setgray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setgray_fill", QString("<u>pdf_setgray_fill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setgray_stroke", QString("<u>pdf_setgray_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setlinecap", QString("<u>pdf_setlinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setlinejoin", QString("<u>pdf_setlinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setlinewidth", QString("<u>pdf_setlinewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setmatrix", QString("<u>pdf_setmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setmiterlimit", QString("<u>pdf_setmiterlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setpolydash", QString("<u>pdf_setpolydash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setrgbcolor", QString("<u>pdf_setrgbcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setrgbcolor_fill", QString("<u>pdf_setrgbcolor_fill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_setrgbcolor_stroke", QString("<u>pdf_setrgbcolor_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_shading", QString("<u>pdf_shading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_shading_pattern", QString("<u>pdf_shading_pattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_shfill", QString("<u>pdf_shfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_show", QString("<u>pdf_show</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_show_boxed", QString("<u>pdf_show_boxed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_show_xy", QString("<u>pdf_show_xy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_skew", QString("<u>pdf_skew</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_stringwidth", QString("<u>pdf_stringwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_stroke", QString("<u>pdf_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_suspend_page", QString("<u>pdf_suspend_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_translate", QString("<u>pdf_translate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_utf16_to_utf8", QString("<u>pdf_utf16_to_utf8</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_utf32_to_utf16", QString("<u>pdf_utf32_to_utf16</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdf_utf8_to_utf16", QString("<u>pdf_utf8_to_utf16</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo", QString("<u>pdo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo_cubrid_schema", QString("<u>pdo_cubrid_schema</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo_pgsqllobcreate", QString("<u>pdo_pgsqllobcreate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo_pgsqllobopen", QString("<u>pdo_pgsqllobopen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo_pgsqllobunlink", QString("<u>pdo_pgsqllobunlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo_sqlitecreateaggregate", QString("<u>pdo_sqlitecreateaggregate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdo_sqlitecreatefunction", QString("<u>pdo_sqlitecreatefunction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdoexception", QString("<u>pdoexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pdostatement", QString("<u>pdostatement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pfsockopen", QString("<u>pfsockopen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_affected_rows", QString("<u>pg_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_cancel_query", QString("<u>pg_cancel_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_client_encoding", QString("<u>pg_client_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_close", QString("<u>pg_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_connect", QString("<u>pg_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_connection_busy", QString("<u>pg_connection_busy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_connection_reset", QString("<u>pg_connection_reset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_connection_status", QString("<u>pg_connection_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_convert", QString("<u>pg_convert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_copy_from", QString("<u>pg_copy_from</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_copy_to", QString("<u>pg_copy_to</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_dbname", QString("<u>pg_dbname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_delete", QString("<u>pg_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_end_copy", QString("<u>pg_end_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_escape_bytea", QString("<u>pg_escape_bytea</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_escape_identifier", QString("<u>pg_escape_identifier</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_escape_literal", QString("<u>pg_escape_literal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_escape_string", QString("<u>pg_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_execute", QString("<u>pg_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_all", QString("<u>pg_fetch_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_all_columns", QString("<u>pg_fetch_all_columns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_array", QString("<u>pg_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_assoc", QString("<u>pg_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_object", QString("<u>pg_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_result", QString("<u>pg_fetch_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_fetch_row", QString("<u>pg_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_is_null", QString("<u>pg_field_is_null</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_name", QString("<u>pg_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_num", QString("<u>pg_field_num</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_prtlen", QString("<u>pg_field_prtlen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_size", QString("<u>pg_field_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_table", QString("<u>pg_field_table</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_type", QString("<u>pg_field_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_field_type_oid", QString("<u>pg_field_type_oid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_free_result", QString("<u>pg_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_get_notify", QString("<u>pg_get_notify</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_get_pid", QString("<u>pg_get_pid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_get_result", QString("<u>pg_get_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_host", QString("<u>pg_host</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_insert", QString("<u>pg_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_last_error", QString("<u>pg_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_last_notice", QString("<u>pg_last_notice</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_last_oid", QString("<u>pg_last_oid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_close", QString("<u>pg_lo_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_create", QString("<u>pg_lo_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_export", QString("<u>pg_lo_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_import", QString("<u>pg_lo_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_open", QString("<u>pg_lo_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_read", QString("<u>pg_lo_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_read_all", QString("<u>pg_lo_read_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_seek", QString("<u>pg_lo_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_tell", QString("<u>pg_lo_tell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_unlink", QString("<u>pg_lo_unlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_lo_write", QString("<u>pg_lo_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_meta_data", QString("<u>pg_meta_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_num_fields", QString("<u>pg_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_num_rows", QString("<u>pg_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_options", QString("<u>pg_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_parameter_status", QString("<u>pg_parameter_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_pconnect", QString("<u>pg_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_ping", QString("<u>pg_ping</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_port", QString("<u>pg_port</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_prepare", QString("<u>pg_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_put_line", QString("<u>pg_put_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_query", QString("<u>pg_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_query_params", QString("<u>pg_query_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_result_error", QString("<u>pg_result_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_result_error_field", QString("<u>pg_result_error_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_result_seek", QString("<u>pg_result_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_result_status", QString("<u>pg_result_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_select", QString("<u>pg_select</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_send_execute", QString("<u>pg_send_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_send_prepare", QString("<u>pg_send_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_send_query", QString("<u>pg_send_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_send_query_params", QString("<u>pg_send_query_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_set_client_encoding", QString("<u>pg_set_client_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_set_error_verbosity", QString("<u>pg_set_error_verbosity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_trace", QString("<u>pg_trace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_transaction_status", QString("<u>pg_transaction_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_tty", QString("<u>pg_tty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_unescape_bytea", QString("<u>pg_unescape_bytea</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_untrace", QString("<u>pg_untrace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_update", QString("<u>pg_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pg_version", QString("<u>pg_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_check_syntax", QString("<u>php_check_syntax</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_ini_loaded_file", QString("<u>php_ini_loaded_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_ini_scanned_files", QString("<u>php_ini_scanned_files</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_logo_guid", QString("<u>php_logo_guid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_sapi_name", QString("<u>php_sapi_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_strip_whitespace", QString("<u>php_strip_whitespace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("php_uname", QString("<u>php_uname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("phpcredits", QString("<u>phpcredits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("phpinfo", QString("<u>phpinfo</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("phpversion", QString("string <u>phpversion</u>(<b>[ string $extension ]</b>) <br />%1").arg(tr("Gets the current PHP version")));
//  data.insert("pi", QString("<u>pi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("png2wbmp", QString("<u>png2wbmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("popen", QString("<u>popen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pos", QString("<u>pos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_access", QString("<u>posix_access</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_ctermid", QString("<u>posix_ctermid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_errno", QString("<u>posix_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_get_last_error", QString("<u>posix_get_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getcwd", QString("<u>posix_getcwd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getegid", QString("<u>posix_getegid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_geteuid", QString("<u>posix_geteuid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getgid", QString("<u>posix_getgid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getgrgid", QString("<u>posix_getgrgid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getgrnam", QString("<u>posix_getgrnam</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getgroups", QString("<u>posix_getgroups</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getlogin", QString("<u>posix_getlogin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getpgid", QString("<u>posix_getpgid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getpgrp", QString("<u>posix_getpgrp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getpid", QString("<u>posix_getpid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getppid", QString("<u>posix_getppid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getpwnam", QString("<u>posix_getpwnam</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getpwuid", QString("<u>posix_getpwuid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getrlimit", QString("<u>posix_getrlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getsid", QString("<u>posix_getsid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_getuid", QString("<u>posix_getuid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_initgroups", QString("<u>posix_initgroups</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_isatty", QString("<u>posix_isatty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_kill", QString("<u>posix_kill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_mkfifo", QString("<u>posix_mkfifo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_mknod", QString("<u>posix_mknod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_setegid", QString("<u>posix_setegid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_seteuid", QString("<u>posix_seteuid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_setgid", QString("<u>posix_setgid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_setpgid", QString("<u>posix_setpgid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_setsid", QString("<u>posix_setsid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_setuid", QString("<u>posix_setuid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_strerror", QString("<u>posix_strerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_times", QString("<u>posix_times</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_ttyname", QString("<u>posix_ttyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("posix_uname", QString("<u>posix_uname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pow", QString("<u>pow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("preg_filter", QString("<u>preg_filter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("preg_grep", QString("<u>preg_grep</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("preg_last_error", QString("<u>preg_last_error</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("preg_match", QString("int <u>preg_match</u>(<b>string $pattern, string $subject [, array &$matches [, int $flags = 0 [, int $offset = 0 ]]]</b>) <br />%1").arg(tr("Searches subject for a match to the regular expression given in pattern.")));
//  data.insert("preg_match_all", QString("<u>preg_match_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("preg_quote", QString("<u>preg_quote</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("preg_replace", QString("mixed <u>preg_replace</u>(<b>mixed $pattern, mixed $replacement, mixed $subject [, int $limit = -1 [, int &$count ]]</b>) <br />%1").arg(tr("Perform a regular expression search and replace")));
//  data.insert("preg_replace_callback", QString("<u>preg_replace_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("preg_split", QString("<u>preg_split</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("prev", QString("<u>prev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("print", QString("<u>print</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("print_r", QString("mixed <u>print_r</u>(<b>mixed $expression [, bool $return = false ]</b>) <br />%1").arg(tr("Prints human-readable information about a variable")));
//  data.insert("printer_abort", QString("<u>printer_abort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_close", QString("<u>printer_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_create_brush", QString("<u>printer_create_brush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_create_dc", QString("<u>printer_create_dc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_create_font", QString("<u>printer_create_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_create_pen", QString("<u>printer_create_pen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_delete_brush", QString("<u>printer_delete_brush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_delete_dc", QString("<u>printer_delete_dc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_delete_font", QString("<u>printer_delete_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_delete_pen", QString("<u>printer_delete_pen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_bmp", QString("<u>printer_draw_bmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_chord", QString("<u>printer_draw_chord</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_elipse", QString("<u>printer_draw_elipse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_line", QString("<u>printer_draw_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_pie", QString("<u>printer_draw_pie</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_rectangle", QString("<u>printer_draw_rectangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_roundrect", QString("<u>printer_draw_roundrect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_draw_text", QString("<u>printer_draw_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_end_doc", QString("<u>printer_end_doc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_end_page", QString("<u>printer_end_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_get_option", QString("<u>printer_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_list", QString("<u>printer_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_logical_fontheight", QString("<u>printer_logical_fontheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_open", QString("<u>printer_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_select_brush", QString("<u>printer_select_brush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_select_font", QString("<u>printer_select_font</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_select_pen", QString("<u>printer_select_pen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_set_option", QString("<u>printer_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_start_doc", QString("<u>printer_start_doc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_start_page", QString("<u>printer_start_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printer_write", QString("<u>printer_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("printf", QString("<u>printf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("proc_close", QString("<u>proc_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("proc_get_status", QString("<u>proc_get_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("proc_nice", QString("<u>proc_nice</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("proc_open", QString("<u>proc_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("proc_terminate", QString("<u>proc_terminate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("property_exists", QString("<u>property_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_add_bookmark", QString("<u>ps_add_bookmark</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_add_launchlink", QString("<u>ps_add_launchlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_add_locallink", QString("<u>ps_add_locallink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_add_note", QString("<u>ps_add_note</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_add_pdflink", QString("<u>ps_add_pdflink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_add_weblink", QString("<u>ps_add_weblink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_arc", QString("<u>ps_arc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_arcn", QString("<u>ps_arcn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_begin_page", QString("<u>ps_begin_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_begin_pattern", QString("<u>ps_begin_pattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_begin_template", QString("<u>ps_begin_template</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_circle", QString("<u>ps_circle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_clip", QString("<u>ps_clip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_close", QString("<u>ps_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_close_image", QString("<u>ps_close_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_closepath", QString("<u>ps_closepath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_closepath_stroke", QString("<u>ps_closepath_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_continue_text", QString("<u>ps_continue_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_curveto", QString("<u>ps_curveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_delete", QString("<u>ps_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_end_page", QString("<u>ps_end_page</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_end_pattern", QString("<u>ps_end_pattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_end_template", QString("<u>ps_end_template</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_fill", QString("<u>ps_fill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_fill_stroke", QString("<u>ps_fill_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_findfont", QString("<u>ps_findfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_get_buffer", QString("<u>ps_get_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_get_parameter", QString("<u>ps_get_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_get_value", QString("<u>ps_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_hyphenate", QString("<u>ps_hyphenate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_include_file", QString("<u>ps_include_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_lineto", QString("<u>ps_lineto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_makespotcolor", QString("<u>ps_makespotcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_moveto", QString("<u>ps_moveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_new", QString("<u>ps_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_open_file", QString("<u>ps_open_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_open_image", QString("<u>ps_open_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_open_image_file", QString("<u>ps_open_image_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_open_memory_image", QString("<u>ps_open_memory_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_place_image", QString("<u>ps_place_image</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_rect", QString("<u>ps_rect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_restore", QString("<u>ps_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_rotate", QString("<u>ps_rotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_save", QString("<u>ps_save</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_scale", QString("<u>ps_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_border_color", QString("<u>ps_set_border_color</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_border_dash", QString("<u>ps_set_border_dash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_border_style", QString("<u>ps_set_border_style</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_info", QString("<u>ps_set_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_parameter", QString("<u>ps_set_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_text_pos", QString("<u>ps_set_text_pos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_set_value", QString("<u>ps_set_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setcolor", QString("<u>ps_setcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setdash", QString("<u>ps_setdash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setflat", QString("<u>ps_setflat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setfont", QString("<u>ps_setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setgray", QString("<u>ps_setgray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setlinecap", QString("<u>ps_setlinecap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setlinejoin", QString("<u>ps_setlinejoin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setlinewidth", QString("<u>ps_setlinewidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setmiterlimit", QString("<u>ps_setmiterlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setoverprintmode", QString("<u>ps_setoverprintmode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_setpolydash", QString("<u>ps_setpolydash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_shading", QString("<u>ps_shading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_shading_pattern", QString("<u>ps_shading_pattern</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_shfill", QString("<u>ps_shfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_show", QString("<u>ps_show</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_show2", QString("<u>ps_show2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_show_boxed", QString("<u>ps_show_boxed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_show_xy", QString("<u>ps_show_xy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_show_xy2", QString("<u>ps_show_xy2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_string_geometry", QString("<u>ps_string_geometry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_stringwidth", QString("<u>ps_stringwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_stroke", QString("<u>ps_stroke</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_symbol", QString("<u>ps_symbol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_symbol_name", QString("<u>ps_symbol_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_symbol_width", QString("<u>ps_symbol_width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ps_translate", QString("<u>ps_translate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_add_to_personal", QString("<u>pspell_add_to_personal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_add_to_session", QString("<u>pspell_add_to_session</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_check", QString("<u>pspell_check</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_clear_session", QString("<u>pspell_clear_session</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_create", QString("<u>pspell_config_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_data_dir", QString("<u>pspell_config_data_dir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_dict_dir", QString("<u>pspell_config_dict_dir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_ignore", QString("<u>pspell_config_ignore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_mode", QString("<u>pspell_config_mode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_personal", QString("<u>pspell_config_personal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_repl", QString("<u>pspell_config_repl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_runtogether", QString("<u>pspell_config_runtogether</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_config_save_repl", QString("<u>pspell_config_save_repl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_new", QString("<u>pspell_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_new_config", QString("<u>pspell_new_config</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_new_personal", QString("<u>pspell_new_personal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_save_wordlist", QString("<u>pspell_save_wordlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_store_replacement", QString("<u>pspell_store_replacement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("pspell_suggest", QString("<u>pspell_suggest</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("putenv", QString("<u>putenv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_close", QString("<u>px_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_create_fp", QString("<u>px_create_fp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_date2string", QString("<u>px_date2string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_delete", QString("<u>px_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_delete_record", QString("<u>px_delete_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_get_field", QString("<u>px_get_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_get_info", QString("<u>px_get_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_get_parameter", QString("<u>px_get_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_get_record", QString("<u>px_get_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_get_schema", QString("<u>px_get_schema</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_get_value", QString("<u>px_get_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_insert_record", QString("<u>px_insert_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_new", QString("<u>px_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_numfields", QString("<u>px_numfields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_numrecords", QString("<u>px_numrecords</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_open_fp", QString("<u>px_open_fp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_put_record", QString("<u>px_put_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_retrieve_record", QString("<u>px_retrieve_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_set_blob_file", QString("<u>px_set_blob_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_set_parameter", QString("<u>px_set_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_set_tablename", QString("<u>px_set_tablename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_set_targetencoding", QString("<u>px_set_targetencoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_set_value", QString("<u>px_set_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_timestamp2string", QString("<u>px_timestamp2string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("px_update_record", QString("<u>px_update_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("qdom_error", QString("<u>qdom_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("qdom_tree", QString("<u>qdom_tree</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quickhashinthash", QString("<u>quickhashinthash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quickhashintset", QString("<u>quickhashintset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quickhashintstringhash", QString("<u>quickhashintstringhash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quickhashstringinthash", QString("<u>quickhashstringinthash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quoted_printable_decode", QString("<u>quoted_printable_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quoted_printable_encode", QString("<u>quoted_printable_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("quotemeta", QString("<u>quotemeta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rad2deg", QString("<u>rad2deg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_acct_open", QString("<u>radius_acct_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_add_server", QString("<u>radius_add_server</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_auth_open", QString("<u>radius_auth_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_close", QString("<u>radius_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_config", QString("<u>radius_config</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_create_request", QString("<u>radius_create_request</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_cvt_addr", QString("<u>radius_cvt_addr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_cvt_int", QString("<u>radius_cvt_int</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_cvt_string", QString("<u>radius_cvt_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_demangle", QString("<u>radius_demangle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_demangle_mppe_key", QString("<u>radius_demangle_mppe_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_get_attr", QString("<u>radius_get_attr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_get_vendor_attr", QString("<u>radius_get_vendor_attr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_addr", QString("<u>radius_put_addr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_attr", QString("<u>radius_put_attr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_int", QString("<u>radius_put_int</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_string", QString("<u>radius_put_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_vendor_addr", QString("<u>radius_put_vendor_addr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_vendor_attr", QString("<u>radius_put_vendor_attr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_vendor_int", QString("<u>radius_put_vendor_int</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_put_vendor_string", QString("<u>radius_put_vendor_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_request_authenticator", QString("<u>radius_request_authenticator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_send_request", QString("<u>radius_send_request</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_server_secret", QString("<u>radius_server_secret</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("radius_strerror", QString("<u>radius_strerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rand", QString("<u>rand</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("range", QString("<u>range</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rangeexception", QString("<u>rangeexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rar_wrapper_cache_stats", QString("<u>rar_wrapper_cache_stats</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rararchive", QString("<u>rararchive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rarentry", QString("<u>rarentry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rarexception", QString("<u>rarexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rawurldecode", QString("<u>rawurldecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rawurlencode", QString("<u>rawurlencode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("read_exif_data", QString("<u>read_exif_data</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("readdir", QString("string <u>readdir</u>(<b>[ resource $dir_handle ]</b>) <br />%1").arg(tr("Read entry from directory handle")));
  data.insert("readfile", QString("int <u>readfile</u>(<b>string $filename [, bool $use_include_path = false [, resource $context ]]</b>) <br />%1").arg(tr("Outputs a file")));
//  data.insert("readgzfile", QString("<u>readgzfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline", QString("<u>readline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_add_history", QString("<u>readline_add_history</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_callback_handler_install", QString("<u>readline_callback_handler_install</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_callback_handler_remove", QString("<u>readline_callback_handler_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_callback_read_char", QString("<u>readline_callback_read_char</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_clear_history", QString("<u>readline_clear_history</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_completion_function", QString("<u>readline_completion_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_info", QString("<u>readline_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_list_history", QString("<u>readline_list_history</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_on_new_line", QString("<u>readline_on_new_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_read_history", QString("<u>readline_read_history</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_redisplay", QString("<u>readline_redisplay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readline_write_history", QString("<u>readline_write_history</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("readlink", QString("<u>readlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("realpath", QString("<u>realpath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("realpath_cache_get", QString("<u>realpath_cache_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("realpath_cache_size", QString("<u>realpath_cache_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recode", QString("<u>recode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recode_file", QString("<u>recode_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recode_string", QString("<u>recode_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursivearrayiterator", QString("<u>recursivearrayiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursivecachingiterator", QString("<u>recursivecachingiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursivecallbackfilteriterator", QString("<u>recursivecallbackfilteriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursivedirectoryiterator", QString("<u>recursivedirectoryiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursivefilteriterator", QString("<u>recursivefilteriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursiveiterator", QString("<u>recursiveiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursiveiteratoriterator", QString("<u>recursiveiteratoriterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursiveregexiterator", QString("<u>recursiveregexiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("recursivetreeiterator", QString("<u>recursivetreeiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflection", QString("<u>reflection</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionclass", QString("<u>reflectionclass</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionexception", QString("<u>reflectionexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionextension", QString("<u>reflectionextension</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionfunction", QString("<u>reflectionfunction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionfunctionabstract", QString("<u>reflectionfunctionabstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionmethod", QString("<u>reflectionmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionobject", QString("<u>reflectionobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionparameter", QString("<u>reflectionparameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflectionproperty", QString("<u>reflectionproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("reflector", QString("<u>reflector</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("regexiterator", QString("<u>regexiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("register_shutdown_function", QString("<u>register_shutdown_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("register_tick_function", QString("<u>register_tick_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rename", QString("<u>rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rename_function", QString("<u>rename_function</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("require", QString("void <u>require</u>(<b>string path</b>) <br />%1").arg(tr("Includes and evaluates the specified file. Halt the script whereas include() emits a warning")));
  data.insert("require_once", QString("void <u>require_once</u>(<b>string path</b>) <br />%1").arg(tr("Identical to require() except PHP will check if the file has already been included, and if so, not include (require) it again")));
//  data.insert("reset", QString("<u>reset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("resetValue", QString("<u>resetValue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("resourcebundle", QString("<u>resourcebundle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("restore_error_handler", QString("<u>restore_error_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("restore_exception_handler", QString("<u>restore_exception_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("restore_include_path", QString("<u>restore_include_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rewind", QString("<u>rewind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rewinddir", QString("<u>rewinddir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rmdir", QString("<u>rmdir</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("round", QString("float <u>round</u>(<b>float $val [, int $precision = 0 [, int $mode = PHP_ROUND_HALF_UP ]]</b>) <br />%1").arg(tr("Rounds a float")));
//  data.insert("rpm_close", QString("<u>rpm_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rpm_get_tag", QString("<u>rpm_get_tag</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rpm_is_valid", QString("<u>rpm_is_valid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rpm_open", QString("<u>rpm_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rpm_version", QString("<u>rpm_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_create", QString("<u>rrd_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_error", QString("<u>rrd_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_fetch", QString("<u>rrd_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_first", QString("<u>rrd_first</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_graph", QString("<u>rrd_graph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_info", QString("<u>rrd_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_last", QString("<u>rrd_last</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_lastupdate", QString("<u>rrd_lastupdate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_restore", QString("<u>rrd_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_tune", QString("<u>rrd_tune</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_update", QString("<u>rrd_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_version", QString("<u>rrd_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrd_xport", QString("<u>rrd_xport</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrdcreator", QString("<u>rrdcreator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrdgraph", QString("<u>rrdgraph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rrdupdater", QString("<u>rrdupdater</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("rsort", QString("<u>rsort</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("rtrim", QString("string <u>rtrim</u>(<b>string $str [, string $character_mask]</b>) <br />%1").arg(tr("Strip whitespace (or other characters) from the end of a string.")));
//  data.insert("runkit_class_adopt", QString("<u>runkit_class_adopt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_class_emancipate", QString("<u>runkit_class_emancipate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_constant_add", QString("<u>runkit_constant_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_constant_redefine", QString("<u>runkit_constant_redefine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_constant_remove", QString("<u>runkit_constant_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_function_add", QString("<u>runkit_function_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_function_copy", QString("<u>runkit_function_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_function_redefine", QString("<u>runkit_function_redefine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_function_remove", QString("<u>runkit_function_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_function_rename", QString("<u>runkit_function_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_import", QString("<u>runkit_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_lint", QString("<u>runkit_lint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_lint_file", QString("<u>runkit_lint_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_method_add", QString("<u>runkit_method_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_method_copy", QString("<u>runkit_method_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_method_redefine", QString("<u>runkit_method_redefine</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_method_remove", QString("<u>runkit_method_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_method_rename", QString("<u>runkit_method_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_return_value_used", QString("<u>runkit_return_value_used</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_sandbox_output_handler", QString("<u>runkit_sandbox_output_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runkit_superglobals", QString("<u>runkit_superglobals</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("runtimeexception", QString("<u>runtimeexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_commit", QString("<u>samconnection_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_connect", QString("<u>samconnection_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_constructor", QString("<u>samconnection_constructor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_disconnect", QString("<u>samconnection_disconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_errno", QString("<u>samconnection_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_error", QString("<u>samconnection_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_isconnected", QString("<u>samconnection_isconnected</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_peek", QString("<u>samconnection_peek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_peekall", QString("<u>samconnection_peekall</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_receive", QString("<u>samconnection_receive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_remove", QString("<u>samconnection_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_rollback", QString("<u>samconnection_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_send", QString("<u>samconnection_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_setDebug", QString("<u>samconnection_setDebug</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_subscribe", QString("<u>samconnection_subscribe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("samconnection_unsubscribe", QString("<u>samconnection_unsubscribe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sammessage_body", QString("<u>sammessage_body</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sammessage_constructor", QString("<u>sammessage_constructor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sammessage_header", QString("<u>sammessage_header</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sca_createdataobject", QString("<u>sca_createdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sca_getservice", QString("<u>sca_getservice</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sca_localproxy_createdataobject", QString("<u>sca_localproxy_createdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sca_soapproxy_createdataobject", QString("<u>sca_soapproxy_createdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("scandir", QString("<u>scandir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_beginlogging", QString("<u>sdo_das_changesummary_beginlogging</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_endlogging", QString("<u>sdo_das_changesummary_endlogging</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_getchangeddataobjects", QString("<u>sdo_das_changesummary_getchangeddataobjects</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_getchangetype", QString("<u>sdo_das_changesummary_getchangetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_getoldcontainer", QString("<u>sdo_das_changesummary_getoldcontainer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_getoldvalues", QString("<u>sdo_das_changesummary_getoldvalues</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_changesummary_islogging", QString("<u>sdo_das_changesummary_islogging</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_datafactory_addpropertytotype", QString("<u>sdo_das_datafactory_addpropertytotype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_datafactory_addtype", QString("<u>sdo_das_datafactory_addtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_datafactory_getdatafactory", QString("<u>sdo_das_datafactory_getdatafactory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_dataobject_getchangesummary", QString("<u>sdo_das_dataobject_getchangesummary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_relational_applychanges", QString("<u>sdo_das_relational_applychanges</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_relational_construct", QString("<u>sdo_das_relational_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_relational_createrootdataobject", QString("<u>sdo_das_relational_createrootdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_relational_executepreparedquery", QString("<u>sdo_das_relational_executepreparedquery</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_relational_executequery", QString("<u>sdo_das_relational_executequery</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_setting_getlistindex", QString("<u>sdo_das_setting_getlistindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_setting_getpropertyindex", QString("<u>sdo_das_setting_getpropertyindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_setting_getpropertyname", QString("<u>sdo_das_setting_getpropertyname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_setting_getvalue", QString("<u>sdo_das_setting_getvalue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_setting_isset", QString("<u>sdo_das_setting_isset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_addtypes", QString("<u>sdo_das_xml_addtypes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_create", QString("<u>sdo_das_xml_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_createdataobject", QString("<u>sdo_das_xml_createdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_createdocument", QString("<u>sdo_das_xml_createdocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_document_getrootdataobject", QString("<u>sdo_das_xml_document_getrootdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_document_getrootelementname", QString("<u>sdo_das_xml_document_getrootelementname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_document_getrootelementuri", QString("<u>sdo_das_xml_document_getrootelementuri</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_document_setencoding", QString("<u>sdo_das_xml_document_setencoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_document_setxmldeclaration", QString("<u>sdo_das_xml_document_setxmldeclaration</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_document_setxmlversion", QString("<u>sdo_das_xml_document_setxmlversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_loadfile", QString("<u>sdo_das_xml_loadfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_loadstring", QString("<u>sdo_das_xml_loadstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_savefile", QString("<u>sdo_das_xml_savefile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_das_xml_savestring", QString("<u>sdo_das_xml_savestring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_datafactory_create", QString("<u>sdo_datafactory_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_dataobject_clear", QString("<u>sdo_dataobject_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_dataobject_createdataobject", QString("<u>sdo_dataobject_createdataobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_dataobject_getcontainer", QString("<u>sdo_dataobject_getcontainer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_dataobject_getsequence", QString("<u>sdo_dataobject_getsequence</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_dataobject_gettypename", QString("<u>sdo_dataobject_gettypename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_dataobject_gettypenamespaceuri", QString("<u>sdo_dataobject_gettypenamespaceuri</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_exception_getcause", QString("<u>sdo_exception_getcause</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_list_insert", QString("<u>sdo_list_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_property_getcontainingtype", QString("<u>sdo_model_property_getcontainingtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_property_getdefault", QString("<u>sdo_model_property_getdefault</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_property_getname", QString("<u>sdo_model_property_getname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_property_gettype", QString("<u>sdo_model_property_gettype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_property_iscontainment", QString("<u>sdo_model_property_iscontainment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_property_ismany", QString("<u>sdo_model_property_ismany</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_reflectiondataobject_construct", QString("<u>sdo_model_reflectiondataobject_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_reflectiondataobject_export", QString("<u>sdo_model_reflectiondataobject_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_reflectiondataobject_getcontainmentproperty", QString("<u>sdo_model_reflectiondataobject_getcontainmentproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_reflectiondataobject_getinstanceproperties", QString("<u>sdo_model_reflectiondataobject_getinstanceproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_reflectiondataobject_gettype", QString("<u>sdo_model_reflectiondataobject_gettype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_getbasetype", QString("<u>sdo_model_type_getbasetype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_getname", QString("<u>sdo_model_type_getname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_getnamespaceuri", QString("<u>sdo_model_type_getnamespaceuri</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_getproperties", QString("<u>sdo_model_type_getproperties</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_getproperty", QString("<u>sdo_model_type_getproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_isabstracttype", QString("<u>sdo_model_type_isabstracttype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_isdatatype", QString("<u>sdo_model_type_isdatatype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_isinstance", QString("<u>sdo_model_type_isinstance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_isopentype", QString("<u>sdo_model_type_isopentype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_model_type_issequencedtype", QString("<u>sdo_model_type_issequencedtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_sequence_getproperty", QString("<u>sdo_sequence_getproperty</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_sequence_insert", QString("<u>sdo_sequence_insert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sdo_sequence_move", QString("<u>sdo_sequence_move</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("seekableiterator", QString("<u>seekableiterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sem_acquire", QString("<u>sem_acquire</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sem_get", QString("<u>sem_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sem_release", QString("<u>sem_release</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sem_remove", QString("<u>sem_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("serializable", QString("<u>serializable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("serialize", QString("<u>serialize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_cache_expire", QString("<u>session_cache_expire</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_cache_limiter", QString("<u>session_cache_limiter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_commit", QString("<u>session_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_decode", QString("<u>session_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_destroy", QString("<u>session_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_encode", QString("<u>session_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_get_cookie_params", QString("<u>session_get_cookie_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_id", QString("<u>session_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_is_registered", QString("<u>session_is_registered</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_module_name", QString("<u>session_module_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_name", QString("<u>session_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_pgsql_add_error", QString("<u>session_pgsql_add_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_pgsql_get_error", QString("<u>session_pgsql_get_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_pgsql_get_field", QString("<u>session_pgsql_get_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_pgsql_reset", QString("<u>session_pgsql_reset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_pgsql_set_field", QString("<u>session_pgsql_set_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_pgsql_status", QString("<u>session_pgsql_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_regenerate_id", QString("<u>session_regenerate_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_register", QString("<u>session_register</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_save_path", QString("<u>session_save_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_set_cookie_params", QString("<u>session_set_cookie_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_set_save_handler", QString("<u>session_set_save_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_start", QString("<u>session_start</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_status", QString("<u>session_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_unregister", QString("<u>session_unregister</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_unset", QString("<u>session_unset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("session_write_close", QString("<u>session_write_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("setCounterClass", QString("<u>setCounterClass</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("set_error_handler", QString("<u>set_error_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("set_exception_handler", QString("<u>set_exception_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("set_file_buffer", QString("<u>set_file_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("set_include_path", QString("<u>set_include_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("set_magic_quotes_runtime", QString("<u>set_magic_quotes_runtime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("set_socket_blocking", QString("<u>set_socket_blocking</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("set_time_limit", QString("void <u>set_time_limit</u>(<b>int $seconds</b>) <br />%1").arg(tr("Limits the maximum execution time.")));
//  data.insert("setcookie", QString("<u>setcookie</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("setlocale", QString("<u>setlocale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("setproctitle", QString("<u>setproctitle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("setrawcookie", QString("<u>setrawcookie</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("setstaticpropertyvalue", QString("<u>setstaticpropertyvalue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("setthreadtitle", QString("<u>setthreadtitle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("settype", QString("<u>settype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sha1", QString("<u>sha1</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sha1_file", QString("<u>sha1_file</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("shell_exec", QString("string <u>shell_exec</u>(<b>string $cmd</b>) <br />%1").arg(tr("Execute command via shell and return the complete output as a string")));
//  data.insert("shm_attach", QString("<u>shm_attach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shm_detach", QString("<u>shm_detach</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shm_get_var", QString("<u>shm_get_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shm_has_var", QString("<u>shm_has_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shm_put_var", QString("<u>shm_put_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shm_remove", QString("<u>shm_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shm_remove_var", QString("<u>shm_remove_var</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shmop_close", QString("<u>shmop_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shmop_delete", QString("<u>shmop_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shmop_open", QString("<u>shmop_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shmop_read", QString("<u>shmop_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shmop_size", QString("<u>shmop_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shmop_write", QString("<u>shmop_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("show_source", QString("<u>show_source</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("shuffle", QString("<u>shuffle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("signeurlpaiement", QString("<u>signeurlpaiement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("similar_text", QString("<u>similar_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("simplexml_import_dom", QString("<u>simplexml_import_dom</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("simplexml_load_file", QString("<u>simplexml_load_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("simplexml_load_string", QString("<u>simplexml_load_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("simplexmlelement", QString("<u>simplexmlelement</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("simplexmliterator", QString("<u>simplexmliterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sin", QString("<u>sin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sinh", QString("<u>sinh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sizeof", QString("<u>sizeof</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sleep", QString("<u>sleep</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp", QString("<u>snmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp2_get", QString("<u>snmp2_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp2_getnext", QString("<u>snmp2_getnext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp2_real_walk", QString("<u>snmp2_real_walk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp2_set", QString("<u>snmp2_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp2_walk", QString("<u>snmp2_walk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp3_get", QString("<u>snmp3_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp3_getnext", QString("<u>snmp3_getnext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp3_real_walk", QString("<u>snmp3_real_walk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp3_set", QString("<u>snmp3_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp3_walk", QString("<u>snmp3_walk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_get_quick_print", QString("<u>snmp_get_quick_print</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_get_valueretrieval", QString("<u>snmp_get_valueretrieval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_read_mib", QString("<u>snmp_read_mib</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_set_enum_print", QString("<u>snmp_set_enum_print</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_set_oid_numeric_print", QString("<u>snmp_set_oid_numeric_print</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_set_oid_output_format", QString("<u>snmp_set_oid_output_format</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_set_quick_print", QString("<u>snmp_set_quick_print</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmp_set_valueretrieval", QString("<u>snmp_set_valueretrieval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmpexception", QString("<u>snmpexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmpget", QString("<u>snmpget</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmpgetnext", QString("<u>snmpgetnext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmprealwalk", QString("<u>snmprealwalk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmpset", QString("<u>snmpset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmpwalk", QString("<u>snmpwalk</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("snmpwalkoid", QString("<u>snmpwalkoid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("soapclient", QString("<u>soapclient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("soapfault", QString("<u>soapfault</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("soapheader", QString("<u>soapheader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("soapparam", QString("<u>soapparam</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("soapserver", QString("<u>soapserver</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("soapvar", QString("<u>soapvar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_accept", QString("<u>socket_accept</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_bind", QString("<u>socket_bind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_clear_error", QString("<u>socket_clear_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_close", QString("<u>socket_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_connect", QString("<u>socket_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_create", QString("<u>socket_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_create_listen", QString("<u>socket_create_listen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_create_pair", QString("<u>socket_create_pair</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_get_option", QString("<u>socket_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_get_status", QString("<u>socket_get_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_getpeername", QString("<u>socket_getpeername</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_getsockname", QString("<u>socket_getsockname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_last_error", QString("<u>socket_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_listen", QString("<u>socket_listen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_read", QString("<u>socket_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_recv", QString("<u>socket_recv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_recvfrom", QString("<u>socket_recvfrom</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_select", QString("<u>socket_select</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_send", QString("<u>socket_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_sendto", QString("<u>socket_sendto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_set_block", QString("<u>socket_set_block</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_set_blocking", QString("<u>socket_set_blocking</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_set_nonblock", QString("<u>socket_set_nonblock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_set_option", QString("<u>socket_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_set_timeout", QString("<u>socket_set_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_shutdown", QString("<u>socket_shutdown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_strerror", QString("<u>socket_strerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("socket_write", QString("<u>socket_write</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solr_get_version", QString("<u>solr_get_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrclient", QString("<u>solrclient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrclientexception", QString("<u>solrclientexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrdocument", QString("<u>solrdocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrdocumentfield", QString("<u>solrdocumentfield</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrexception", QString("<u>solrexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrgenericresponse", QString("<u>solrgenericresponse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrillegalargumentexception", QString("<u>solrillegalargumentexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrillegaloperationexception", QString("<u>solrillegaloperationexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrinputdocument", QString("<u>solrinputdocument</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrmodifiableparams", QString("<u>solrmodifiableparams</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrobject", QString("<u>solrobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrparams", QString("<u>solrparams</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrpingresponse", QString("<u>solrpingresponse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrquery", QString("<u>solrquery</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrqueryresponse", QString("<u>solrqueryresponse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrresponse", QString("<u>solrresponse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrupdateresponse", QString("<u>solrupdateresponse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("solrutils", QString("<u>solrutils</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("sort", QString("<u>sort</u>(<b>array &$array [, int $sort_flags = SORT_REGULAR]</b>) <br />%1").arg(tr("This function sorts an array. Elements will be arranged from lowest to highest when this function has completed.")));
//  data.insert("soundex", QString("<u>soundex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sphinxclient", QString("<u>sphinxclient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_autoload", QString("<u>spl_autoload</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_autoload_call", QString("<u>spl_autoload_call</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_autoload_extensions", QString("<u>spl_autoload_extensions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_autoload_functions", QString("<u>spl_autoload_functions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_autoload_register", QString("<u>spl_autoload_register</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_autoload_unregister", QString("<u>spl_autoload_unregister</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_classes", QString("<u>spl_classes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spl_object_hash", QString("<u>spl_object_hash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splbool", QString("<u>splbool</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spldoublylinkedlist", QString("<u>spldoublylinkedlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splenum", QString("<u>splenum</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splfileinfo", QString("<u>splfileinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splfileobject", QString("<u>splfileobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splfixedarray", QString("<u>splfixedarray</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splfloat", QString("<u>splfloat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splheap", QString("<u>splheap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splint", QString("<u>splint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("split", QString("<u>split</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spliti", QString("<u>spliti</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splmaxheap", QString("<u>splmaxheap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splminheap", QString("<u>splminheap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splobjectstorage", QString("<u>splobjectstorage</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splobserver", QString("<u>splobserver</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splpriorityqueue", QString("<u>splpriorityqueue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splqueue", QString("<u>splqueue</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splstack", QString("<u>splstack</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splstring", QString("<u>splstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("splsubject", QString("<u>splsubject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spltempfileobject", QString("<u>spltempfileobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spltype", QString("<u>spltype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("spoofchecker", QString("<u>spoofchecker</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sprintf", QString("<u>sprintf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sql_regcase", QString("<u>sql_regcase</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite3", QString("<u>sqlite3</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite3result", QString("<u>sqlite3result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite3stmt", QString("<u>sqlite3stmt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_array_query", QString("<u>sqlite_array_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_busy_timeout", QString("<u>sqlite_busy_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_changes", QString("<u>sqlite_changes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_close", QString("<u>sqlite_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_column", QString("<u>sqlite_column</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_create_aggregate", QString("<u>sqlite_create_aggregate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_create_function", QString("<u>sqlite_create_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_current", QString("<u>sqlite_current</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_error_string", QString("<u>sqlite_error_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_escape_string", QString("<u>sqlite_escape_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_exec", QString("<u>sqlite_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_factory", QString("<u>sqlite_factory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_fetch_all", QString("<u>sqlite_fetch_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_fetch_array", QString("<u>sqlite_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_fetch_column_types", QString("<u>sqlite_fetch_column_types</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_fetch_object", QString("<u>sqlite_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_fetch_single", QString("<u>sqlite_fetch_single</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_fetch_string", QString("<u>sqlite_fetch_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_field_name", QString("<u>sqlite_field_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_has_more", QString("<u>sqlite_has_more</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_has_prev", QString("<u>sqlite_has_prev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_key", QString("<u>sqlite_key</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_last_error", QString("<u>sqlite_last_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_last_insert_rowid", QString("<u>sqlite_last_insert_rowid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_libencoding", QString("<u>sqlite_libencoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_libversion", QString("<u>sqlite_libversion</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_next", QString("<u>sqlite_next</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_num_fields", QString("<u>sqlite_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_num_rows", QString("<u>sqlite_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_open", QString("<u>sqlite_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_popen", QString("<u>sqlite_popen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_prev", QString("<u>sqlite_prev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_query", QString("<u>sqlite_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_rewind", QString("<u>sqlite_rewind</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_seek", QString("<u>sqlite_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_single_query", QString("<u>sqlite_single_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_udf_decode_binary", QString("<u>sqlite_udf_decode_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_udf_encode_binary", QString("<u>sqlite_udf_encode_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_unbuffered_query", QString("<u>sqlite_unbuffered_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlite_valid", QString("<u>sqlite_valid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_begin_transaction", QString("<u>sqlsrv_begin_transaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_cancel", QString("<u>sqlsrv_cancel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_client_info", QString("<u>sqlsrv_client_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_close", QString("<u>sqlsrv_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_commit", QString("<u>sqlsrv_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_configure", QString("<u>sqlsrv_configure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_connect", QString("<u>sqlsrv_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_errors", QString("<u>sqlsrv_errors</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_execute", QString("<u>sqlsrv_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_fetch", QString("<u>sqlsrv_fetch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_fetch_array", QString("<u>sqlsrv_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_fetch_object", QString("<u>sqlsrv_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_field_metadata", QString("<u>sqlsrv_field_metadata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_free_stmt", QString("<u>sqlsrv_free_stmt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_get_config", QString("<u>sqlsrv_get_config</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_get_field", QString("<u>sqlsrv_get_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_has_rows", QString("<u>sqlsrv_has_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_next_result", QString("<u>sqlsrv_next_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_num_fields", QString("<u>sqlsrv_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_num_rows", QString("<u>sqlsrv_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_prepare", QString("<u>sqlsrv_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_query", QString("<u>sqlsrv_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_rollback", QString("<u>sqlsrv_rollback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_rows_affected", QString("<u>sqlsrv_rows_affected</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_send_stream_data", QString("<u>sqlsrv_send_stream_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqlsrv_server_info", QString("<u>sqlsrv_server_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sqrt", QString("<u>sqrt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("srand", QString("<u>srand</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sscanf", QString("<u>sscanf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssdeep_fuzzy_compare", QString("<u>ssdeep_fuzzy_compare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssdeep_fuzzy_hash", QString("<u>ssdeep_fuzzy_hash</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssdeep_fuzzy_hash_filename", QString("<u>ssdeep_fuzzy_hash_filename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_auth_hostbased_file", QString("<u>ssh2_auth_hostbased_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_auth_none", QString("<u>ssh2_auth_none</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_auth_password", QString("<u>ssh2_auth_password</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_auth_pubkey_file", QString("<u>ssh2_auth_pubkey_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_connect", QString("<u>ssh2_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_exec", QString("<u>ssh2_exec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_fetch_stream", QString("<u>ssh2_fetch_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_fingerprint", QString("<u>ssh2_fingerprint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_methods_negotiated", QString("<u>ssh2_methods_negotiated</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_publickey_add", QString("<u>ssh2_publickey_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_publickey_init", QString("<u>ssh2_publickey_init</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_publickey_list", QString("<u>ssh2_publickey_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_publickey_remove", QString("<u>ssh2_publickey_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_scp_recv", QString("<u>ssh2_scp_recv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_scp_send", QString("<u>ssh2_scp_send</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp", QString("<u>ssh2_sftp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_lstat", QString("<u>ssh2_sftp_lstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_mkdir", QString("<u>ssh2_sftp_mkdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_readlink", QString("<u>ssh2_sftp_readlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_realpath", QString("<u>ssh2_sftp_realpath</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_rename", QString("<u>ssh2_sftp_rename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_rmdir", QString("<u>ssh2_sftp_rmdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_stat", QString("<u>ssh2_sftp_stat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_symlink", QString("<u>ssh2_sftp_symlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_sftp_unlink", QString("<u>ssh2_sftp_unlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_shell", QString("<u>ssh2_shell</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ssh2_tunnel", QString("<u>ssh2_tunnel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stat", QString("<u>stat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_absolute_deviation", QString("<u>stats_absolute_deviation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_beta", QString("<u>stats_cdf_beta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_binomial", QString("<u>stats_cdf_binomial</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_cauchy", QString("<u>stats_cdf_cauchy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_chisquare", QString("<u>stats_cdf_chisquare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_exponential", QString("<u>stats_cdf_exponential</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_f", QString("<u>stats_cdf_f</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_gamma", QString("<u>stats_cdf_gamma</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_laplace", QString("<u>stats_cdf_laplace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_logistic", QString("<u>stats_cdf_logistic</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_negative_binomial", QString("<u>stats_cdf_negative_binomial</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_noncentral_chisquare", QString("<u>stats_cdf_noncentral_chisquare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_noncentral_f", QString("<u>stats_cdf_noncentral_f</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_poisson", QString("<u>stats_cdf_poisson</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_t", QString("<u>stats_cdf_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_uniform", QString("<u>stats_cdf_uniform</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_cdf_weibull", QString("<u>stats_cdf_weibull</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_covariance", QString("<u>stats_covariance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_den_uniform", QString("<u>stats_den_uniform</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_beta", QString("<u>stats_dens_beta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_cauchy", QString("<u>stats_dens_cauchy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_chisquare", QString("<u>stats_dens_chisquare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_exponential", QString("<u>stats_dens_exponential</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_f", QString("<u>stats_dens_f</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_gamma", QString("<u>stats_dens_gamma</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_laplace", QString("<u>stats_dens_laplace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_logistic", QString("<u>stats_dens_logistic</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_negative_binomial", QString("<u>stats_dens_negative_binomial</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_normal", QString("<u>stats_dens_normal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_pmf_binomial", QString("<u>stats_dens_pmf_binomial</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_pmf_hypergeometric", QString("<u>stats_dens_pmf_hypergeometric</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_pmf_poisson", QString("<u>stats_dens_pmf_poisson</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_t", QString("<u>stats_dens_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_dens_weibull", QString("<u>stats_dens_weibull</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_harmonic_mean", QString("<u>stats_harmonic_mean</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_kurtosis", QString("<u>stats_kurtosis</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_beta", QString("<u>stats_rand_gen_beta</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_chisquare", QString("<u>stats_rand_gen_chisquare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_exponential", QString("<u>stats_rand_gen_exponential</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_f", QString("<u>stats_rand_gen_f</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_funiform", QString("<u>stats_rand_gen_funiform</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_gamma", QString("<u>stats_rand_gen_gamma</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_ibinomial", QString("<u>stats_rand_gen_ibinomial</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_ibinomial_negative", QString("<u>stats_rand_gen_ibinomial_negative</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_int", QString("<u>stats_rand_gen_int</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_ipoisson", QString("<u>stats_rand_gen_ipoisson</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_iuniform", QString("<u>stats_rand_gen_iuniform</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_noncenral_chisquare", QString("<u>stats_rand_gen_noncenral_chisquare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_noncentral_f", QString("<u>stats_rand_gen_noncentral_f</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_noncentral_t", QString("<u>stats_rand_gen_noncentral_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_normal", QString("<u>stats_rand_gen_normal</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_gen_t", QString("<u>stats_rand_gen_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_get_seeds", QString("<u>stats_rand_get_seeds</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_phrase_to_seeds", QString("<u>stats_rand_phrase_to_seeds</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_ranf", QString("<u>stats_rand_ranf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_rand_setall", QString("<u>stats_rand_setall</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_skew", QString("<u>stats_skew</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_standard_deviation", QString("<u>stats_standard_deviation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_binomial_coef", QString("<u>stats_stat_binomial_coef</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_correlation", QString("<u>stats_stat_correlation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_gennch", QString("<u>stats_stat_gennch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_independent_t", QString("<u>stats_stat_independent_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_innerproduct", QString("<u>stats_stat_innerproduct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_noncentral_t", QString("<u>stats_stat_noncentral_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_paired_t", QString("<u>stats_stat_paired_t</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_percentile", QString("<u>stats_stat_percentile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_stat_powersum", QString("<u>stats_stat_powersum</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stats_variance", QString("<u>stats_variance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stomp", QString("<u>stomp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stomp_connect_error", QString("<u>stomp_connect_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stomp_version", QString("<u>stomp_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stompexception", QString("<u>stompexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stompframe", QString("<u>stompframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_getcsv", QString("<u>str_getcsv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_ireplace", QString("<u>str_ireplace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_pad", QString("<u>str_pad</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_repeat", QString("<u>str_repeat</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("str_replace", QString("mixed <u>str_replace</u>(<b>mixed $search, mixed $replace, mixed $subject [, int &$count ]</b>) <br />%1").arg(tr("Replace all occurrences of the search string with the replacement string")));
//  data.insert("str_rot13", QString("<u>str_rot13</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_shuffle", QString("<u>str_shuffle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_split", QString("<u>str_split</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("str_word_count", QString("<u>str_word_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strcasecmp", QString("<u>strcasecmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strchr", QString("<u>strchr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strcmp", QString("<u>strcmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strcoll", QString("<u>strcoll</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strcspn", QString("<u>strcspn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_bucket_append", QString("<u>stream_bucket_append</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_bucket_make_writeable", QString("<u>stream_bucket_make_writeable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_bucket_new", QString("<u>stream_bucket_new</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_bucket_prepend", QString("<u>stream_bucket_prepend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_create", QString("<u>stream_context_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_get_default", QString("<u>stream_context_get_default</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_get_options", QString("<u>stream_context_get_options</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_get_params", QString("<u>stream_context_get_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_set_default", QString("<u>stream_context_set_default</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_set_option", QString("<u>stream_context_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_context_set_params", QString("<u>stream_context_set_params</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_copy_to_stream", QString("<u>stream_copy_to_stream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_encoding", QString("<u>stream_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_filter_append", QString("<u>stream_filter_append</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_filter_prepend", QString("<u>stream_filter_prepend</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_filter_register", QString("<u>stream_filter_register</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_filter_remove", QString("<u>stream_filter_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_get_contents", QString("<u>stream_get_contents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_get_filters", QString("<u>stream_get_filters</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_get_line", QString("<u>stream_get_line</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_get_meta_data", QString("<u>stream_get_meta_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_get_transports", QString("<u>stream_get_transports</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_get_wrappers", QString("<u>stream_get_wrappers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_is_local", QString("<u>stream_is_local</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_notification_callback", QString("<u>stream_notification_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_register_wrapper", QString("<u>stream_register_wrapper</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_resolve_include_path", QString("<u>stream_resolve_include_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_select", QString("<u>stream_select</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_set_blocking", QString("<u>stream_set_blocking</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_set_read_buffer", QString("<u>stream_set_read_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_set_timeout", QString("<u>stream_set_timeout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_set_write_buffer", QString("<u>stream_set_write_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_accept", QString("<u>stream_socket_accept</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_client", QString("<u>stream_socket_client</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_enable_crypto", QString("<u>stream_socket_enable_crypto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_get_name", QString("<u>stream_socket_get_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_pair", QString("<u>stream_socket_pair</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_recvfrom", QString("<u>stream_socket_recvfrom</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_sendto", QString("<u>stream_socket_sendto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_server", QString("<u>stream_socket_server</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_socket_shutdown", QString("<u>stream_socket_shutdown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_supports_lock", QString("<u>stream_supports_lock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_wrapper_register", QString("<u>stream_wrapper_register</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_wrapper_restore", QString("<u>stream_wrapper_restore</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stream_wrapper_unregister", QString("<u>stream_wrapper_unregister</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("streamwrapper", QString("<u>streamwrapper</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strftime", QString("<u>strftime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strip_tags", QString("<u>strip_tags</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stripcslashes", QString("<u>stripcslashes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stripos", QString("<u>stripos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stripslashes", QString("<u>stripslashes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("stristr", QString("<u>stristr</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("strlen", QString("int <u>strlen</u>(<b>string $string</b>) <br />%1").arg(tr("Get string length")));
//  data.insert("strnatcasecmp", QString("<u>strnatcasecmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strnatcmp", QString("<u>strnatcmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strncasecmp", QString("<u>strncasecmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strncmp", QString("<u>strncmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strpbrk", QString("<u>strpbrk</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("strpos", QString("int <u>strpos</u>(<b>string $haystack, mixed $needle [, int $offset = 0 ]</b>) <br />%1").arg(tr("Find the position of the first occurrence of a substring in a string")));
//  data.insert("strptime", QString("<u>strptime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strrchr", QString("<u>strrchr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strrev", QString("<u>strrev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strripos", QString("<u>strripos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strrpos", QString("<u>strrpos</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strspn", QString("<u>strspn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strstr", QString("<u>strstr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strtok", QString("<u>strtok</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strtolower", QString("<u>strtolower</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strtotime", QString("<u>strtotime</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strtoupper", QString("<u>strtoupper</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strtr", QString("<u>strtr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("strval", QString("<u>strval</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("substr", QString("string <u>substr</u>(<b>string $string, int $start [, int $length ]</b>) <br />%1").arg(tr("Return part of a string")));
//  data.insert("substr_compare", QString("<u>substr_compare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("substr_count", QString("<u>substr_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("substr_replace", QString("<u>substr_replace</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svm", QString("<u>svm</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svmmodel", QString("<u>svmmodel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_add", QString("<u>svn_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_auth_get_parameter", QString("<u>svn_auth_get_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_auth_set_parameter", QString("<u>svn_auth_set_parameter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_blame", QString("<u>svn_blame</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_cat", QString("<u>svn_cat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_checkout", QString("<u>svn_checkout</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_cleanup", QString("<u>svn_cleanup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_client_version", QString("<u>svn_client_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_commit", QString("<u>svn_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_delete", QString("<u>svn_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_diff", QString("<u>svn_diff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_export", QString("<u>svn_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_abort_txn", QString("<u>svn_fs_abort_txn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_apply_text", QString("<u>svn_fs_apply_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_begin_txn2", QString("<u>svn_fs_begin_txn2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_change_node_prop", QString("<u>svn_fs_change_node_prop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_check_path", QString("<u>svn_fs_check_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_contents_changed", QString("<u>svn_fs_contents_changed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_copy", QString("<u>svn_fs_copy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_delete", QString("<u>svn_fs_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_dir_entries", QString("<u>svn_fs_dir_entries</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_file_contents", QString("<u>svn_fs_file_contents</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_file_length", QString("<u>svn_fs_file_length</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_is_dir", QString("<u>svn_fs_is_dir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_is_file", QString("<u>svn_fs_is_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_make_dir", QString("<u>svn_fs_make_dir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_make_file", QString("<u>svn_fs_make_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_node_created_rev", QString("<u>svn_fs_node_created_rev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_node_prop", QString("<u>svn_fs_node_prop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_props_changed", QString("<u>svn_fs_props_changed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_revision_prop", QString("<u>svn_fs_revision_prop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_revision_root", QString("<u>svn_fs_revision_root</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_txn_root", QString("<u>svn_fs_txn_root</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_fs_youngest_rev", QString("<u>svn_fs_youngest_rev</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_import", QString("<u>svn_import</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_log", QString("<u>svn_log</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_ls", QString("<u>svn_ls</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_mkdir", QString("<u>svn_mkdir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_create", QString("<u>svn_repos_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_fs", QString("<u>svn_repos_fs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_fs_begin_txn_for_commit", QString("<u>svn_repos_fs_begin_txn_for_commit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_fs_commit_txn", QString("<u>svn_repos_fs_commit_txn</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_hotcopy", QString("<u>svn_repos_hotcopy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_open", QString("<u>svn_repos_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_repos_recover", QString("<u>svn_repos_recover</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_revert", QString("<u>svn_revert</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_status", QString("<u>svn_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("svn_update", QString("<u>svn_update</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actiongeturl", QString("<u>swf_actiongeturl</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actiongotoframe", QString("<u>swf_actiongotoframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actiongotolabel", QString("<u>swf_actiongotolabel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actionnextframe", QString("<u>swf_actionnextframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actionplay", QString("<u>swf_actionplay</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actionprevframe", QString("<u>swf_actionprevframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actionsettarget", QString("<u>swf_actionsettarget</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actionstop", QString("<u>swf_actionstop</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actiontogglequality", QString("<u>swf_actiontogglequality</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_actionwaitforframe", QString("<u>swf_actionwaitforframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_addbuttonrecord", QString("<u>swf_addbuttonrecord</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_addcolor", QString("<u>swf_addcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_closefile", QString("<u>swf_closefile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_definebitmap", QString("<u>swf_definebitmap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_definefont", QString("<u>swf_definefont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_defineline", QString("<u>swf_defineline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_definepoly", QString("<u>swf_definepoly</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_definerect", QString("<u>swf_definerect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_definetext", QString("<u>swf_definetext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_endbutton", QString("<u>swf_endbutton</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_enddoaction", QString("<u>swf_enddoaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_endshape", QString("<u>swf_endshape</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_endsymbol", QString("<u>swf_endsymbol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_fontsize", QString("<u>swf_fontsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_fontslant", QString("<u>swf_fontslant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_fonttracking", QString("<u>swf_fonttracking</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_getbitmapinfo", QString("<u>swf_getbitmapinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_getfontinfo", QString("<u>swf_getfontinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_getframe", QString("<u>swf_getframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_labelframe", QString("<u>swf_labelframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_lookat", QString("<u>swf_lookat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_modifyobject", QString("<u>swf_modifyobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_mulcolor", QString("<u>swf_mulcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_nextid", QString("<u>swf_nextid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_oncondition", QString("<u>swf_oncondition</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_openfile", QString("<u>swf_openfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_ortho", QString("<u>swf_ortho</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_ortho2", QString("<u>swf_ortho2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_perspective", QString("<u>swf_perspective</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_placeobject", QString("<u>swf_placeobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_polarview", QString("<u>swf_polarview</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_popmatrix", QString("<u>swf_popmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_posround", QString("<u>swf_posround</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_pushmatrix", QString("<u>swf_pushmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_removeobject", QString("<u>swf_removeobject</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_rotate", QString("<u>swf_rotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_scale", QString("<u>swf_scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_setfont", QString("<u>swf_setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_setframe", QString("<u>swf_setframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapearc", QString("<u>swf_shapearc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapecurveto", QString("<u>swf_shapecurveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapecurveto3", QString("<u>swf_shapecurveto3</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapefillbitmapclip", QString("<u>swf_shapefillbitmapclip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapefillbitmaptile", QString("<u>swf_shapefillbitmaptile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapefilloff", QString("<u>swf_shapefilloff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapefillsolid", QString("<u>swf_shapefillsolid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapelinesolid", QString("<u>swf_shapelinesolid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapelineto", QString("<u>swf_shapelineto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_shapemoveto", QString("<u>swf_shapemoveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_showframe", QString("<u>swf_showframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_startbutton", QString("<u>swf_startbutton</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_startdoaction", QString("<u>swf_startdoaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_startshape", QString("<u>swf_startshape</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_startsymbol", QString("<u>swf_startsymbol</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_textwidth", QString("<u>swf_textwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_translate", QString("<u>swf_translate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swf_viewport", QString("<u>swf_viewport</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfaction", QString("<u>swfaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfaction.construct", QString("<u>swfaction.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbitmap", QString("<u>swfbitmap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbitmap.construct", QString("<u>swfbitmap.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbitmap.getheight", QString("<u>swfbitmap.getheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbitmap.getwidth", QString("<u>swfbitmap.getwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton", QString("<u>swfbutton</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.addaction", QString("<u>swfbutton.addaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.addasound", QString("<u>swfbutton.addasound</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.addshape", QString("<u>swfbutton.addshape</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.construct", QString("<u>swfbutton.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.setaction", QString("<u>swfbutton.setaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.setdown", QString("<u>swfbutton.setdown</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.sethit", QString("<u>swfbutton.sethit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.setmenu", QString("<u>swfbutton.setmenu</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.setover", QString("<u>swfbutton.setover</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfbutton.setup", QString("<u>swfbutton.setup</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem", QString("<u>swfdisplayitem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.addaction", QString("<u>swfdisplayitem.addaction</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.addcolor", QString("<u>swfdisplayitem.addcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.endmask", QString("<u>swfdisplayitem.endmask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.getrot", QString("<u>swfdisplayitem.getrot</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.getx", QString("<u>swfdisplayitem.getx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.getxscale", QString("<u>swfdisplayitem.getxscale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.getxskew", QString("<u>swfdisplayitem.getxskew</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.gety", QString("<u>swfdisplayitem.gety</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.getyscale", QString("<u>swfdisplayitem.getyscale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.getyskew", QString("<u>swfdisplayitem.getyskew</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.move", QString("<u>swfdisplayitem.move</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.moveto", QString("<u>swfdisplayitem.moveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.multcolor", QString("<u>swfdisplayitem.multcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.remove", QString("<u>swfdisplayitem.remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.rotate", QString("<u>swfdisplayitem.rotate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.rotateto", QString("<u>swfdisplayitem.rotateto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.scale", QString("<u>swfdisplayitem.scale</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.scaleto", QString("<u>swfdisplayitem.scaleto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.setdepth", QString("<u>swfdisplayitem.setdepth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.setmasklevel", QString("<u>swfdisplayitem.setmasklevel</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.setmatrix", QString("<u>swfdisplayitem.setmatrix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.setname", QString("<u>swfdisplayitem.setname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.setratio", QString("<u>swfdisplayitem.setratio</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.skewx", QString("<u>swfdisplayitem.skewx</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.skewxto", QString("<u>swfdisplayitem.skewxto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.skewy", QString("<u>swfdisplayitem.skewy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfdisplayitem.skewyto", QString("<u>swfdisplayitem.skewyto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffill", QString("<u>swffill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffill.moveto", QString("<u>swffill.moveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffill.rotateto", QString("<u>swffill.rotateto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffill.scaleto", QString("<u>swffill.scaleto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffill.skewxto", QString("<u>swffill.skewxto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffill.skewyto", QString("<u>swffill.skewyto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont", QString("<u>swffont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.construct", QString("<u>swffont.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.getascent", QString("<u>swffont.getascent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.getdescent", QString("<u>swffont.getdescent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.getleading", QString("<u>swffont.getleading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.getshape", QString("<u>swffont.getshape</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.getutf8width", QString("<u>swffont.getutf8width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffont.getwidth", QString("<u>swffont.getwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffontchar", QString("<u>swffontchar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffontchar.addchars", QString("<u>swffontchar.addchars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swffontchar.addutf8chars", QString("<u>swffontchar.addutf8chars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfgradient", QString("<u>swfgradient</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfgradient.addentry", QString("<u>swfgradient.addentry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfgradient.construct", QString("<u>swfgradient.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmorph", QString("<u>swfmorph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmorph.construct", QString("<u>swfmorph.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmorph.getshape1", QString("<u>swfmorph.getshape1</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmorph.getshape2", QString("<u>swfmorph.getshape2</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie", QString("<u>swfmovie</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.add", QString("<u>swfmovie.add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.addexport", QString("<u>swfmovie.addexport</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.addfont", QString("<u>swfmovie.addfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.construct", QString("<u>swfmovie.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.importchar", QString("<u>swfmovie.importchar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.importfont", QString("<u>swfmovie.importfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.labelframe", QString("<u>swfmovie.labelframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.nextframe", QString("<u>swfmovie.nextframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.output", QString("<u>swfmovie.output</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.remove", QString("<u>swfmovie.remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.save", QString("<u>swfmovie.save</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.savetofile", QString("<u>swfmovie.savetofile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.setbackground", QString("<u>swfmovie.setbackground</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.setdimension", QString("<u>swfmovie.setdimension</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.setframes", QString("<u>swfmovie.setframes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.setrate", QString("<u>swfmovie.setrate</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.startsound", QString("<u>swfmovie.startsound</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.stopsound", QString("<u>swfmovie.stopsound</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.streammp3", QString("<u>swfmovie.streammp3</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfmovie.writeexports", QString("<u>swfmovie.writeexports</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfprebuiltclip", QString("<u>swfprebuiltclip</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfprebuiltclip.construct", QString("<u>swfprebuiltclip.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape", QString("<u>swfshape</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.addfill", QString("<u>swfshape.addfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.construct", QString("<u>swfshape.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawarc", QString("<u>swfshape.drawarc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawcircle", QString("<u>swfshape.drawcircle</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawcubic", QString("<u>swfshape.drawcubic</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawcubicto", QString("<u>swfshape.drawcubicto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawcurve", QString("<u>swfshape.drawcurve</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawcurveto", QString("<u>swfshape.drawcurveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawglyph", QString("<u>swfshape.drawglyph</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawline", QString("<u>swfshape.drawline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.drawlineto", QString("<u>swfshape.drawlineto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.movepen", QString("<u>swfshape.movepen</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.movepento", QString("<u>swfshape.movepento</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.setleftfill", QString("<u>swfshape.setleftfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.setline", QString("<u>swfshape.setline</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfshape.setrightfill", QString("<u>swfshape.setrightfill</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsound", QString("<u>swfsound</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsound.construct", QString("<u>swfsound.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsoundinstance", QString("<u>swfsoundinstance</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsoundinstance.loopcount", QString("<u>swfsoundinstance.loopcount</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsoundinstance.loopinpoint", QString("<u>swfsoundinstance.loopinpoint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsoundinstance.loopoutpoint", QString("<u>swfsoundinstance.loopoutpoint</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsoundinstance.nomultiple", QString("<u>swfsoundinstance.nomultiple</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite", QString("<u>swfsprite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.add", QString("<u>swfsprite.add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.construct", QString("<u>swfsprite.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.labelframe", QString("<u>swfsprite.labelframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.nextframe", QString("<u>swfsprite.nextframe</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.remove", QString("<u>swfsprite.remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.setframes", QString("<u>swfsprite.setframes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.startsound", QString("<u>swfsprite.startsound</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfsprite.stopsound", QString("<u>swfsprite.stopsound</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext", QString("<u>swftext</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.addstring", QString("<u>swftext.addstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.addutf8string", QString("<u>swftext.addutf8string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.construct", QString("<u>swftext.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.getascent", QString("<u>swftext.getascent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.getdescent", QString("<u>swftext.getdescent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.getleading", QString("<u>swftext.getleading</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.getutf8width", QString("<u>swftext.getutf8width</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.getwidth", QString("<u>swftext.getwidth</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.moveto", QString("<u>swftext.moveto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.setcolor", QString("<u>swftext.setcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.setfont", QString("<u>swftext.setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.setheight", QString("<u>swftext.setheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftext.setspacing", QString("<u>swftext.setspacing</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield", QString("<u>swftextfield</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.addchars", QString("<u>swftextfield.addchars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.addstring", QString("<u>swftextfield.addstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.align", QString("<u>swftextfield.align</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.construct", QString("<u>swftextfield.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setbounds", QString("<u>swftextfield.setbounds</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setcolor", QString("<u>swftextfield.setcolor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setfont", QString("<u>swftextfield.setfont</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setheight", QString("<u>swftextfield.setheight</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setindentation", QString("<u>swftextfield.setindentation</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setleftmargin", QString("<u>swftextfield.setleftmargin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setlinespacing", QString("<u>swftextfield.setlinespacing</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setmargins", QString("<u>swftextfield.setmargins</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setname", QString("<u>swftextfield.setname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setpadding", QString("<u>swftextfield.setpadding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swftextfield.setrightmargin", QString("<u>swftextfield.setrightmargin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfvideostream", QString("<u>swfvideostream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfvideostream.construct", QString("<u>swfvideostream.construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfvideostream.getnumframes", QString("<u>swfvideostream.getnumframes</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swfvideostream.setdimension", QString("<u>swfvideostream.setdimension</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swish_construct", QString("<u>swish_construct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swish_getmetalist", QString("<u>swish_getmetalist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swish_getpropertylist", QString("<u>swish_getpropertylist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swish_prepare", QString("<u>swish_prepare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swish_query", QString("<u>swish_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishresult_getmetalist", QString("<u>swishresult_getmetalist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishresult_stem", QString("<u>swishresult_stem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishresults_getparsedwords", QString("<u>swishresults_getparsedwords</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishresults_getremovedstopwords", QString("<u>swishresults_getremovedstopwords</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishresults_nextresult", QString("<u>swishresults_nextresult</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishresults_seekresult", QString("<u>swishresults_seekresult</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishsearch_execute", QString("<u>swishsearch_execute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishsearch_resetlimit", QString("<u>swishsearch_resetlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishsearch_setlimit", QString("<u>swishsearch_setlimit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishsearch_setphrasedelimiter", QString("<u>swishsearch_setphrasedelimiter</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishsearch_setsort", QString("<u>swishsearch_setsort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("swishsearch_setstructure", QString("<u>swishsearch_setstructure</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_affected_rows", QString("<u>sybase_affected_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_close", QString("<u>sybase_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_connect", QString("<u>sybase_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_data_seek", QString("<u>sybase_data_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_deadlock_retry_count", QString("<u>sybase_deadlock_retry_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_fetch_array", QString("<u>sybase_fetch_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_fetch_assoc", QString("<u>sybase_fetch_assoc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_fetch_field", QString("<u>sybase_fetch_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_fetch_object", QString("<u>sybase_fetch_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_fetch_row", QString("<u>sybase_fetch_row</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_field_seek", QString("<u>sybase_field_seek</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_free_result", QString("<u>sybase_free_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_get_last_message", QString("<u>sybase_get_last_message</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_min_client_severity", QString("<u>sybase_min_client_severity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_min_error_severity", QString("<u>sybase_min_error_severity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_min_message_severity", QString("<u>sybase_min_message_severity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_min_server_severity", QString("<u>sybase_min_server_severity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_num_fields", QString("<u>sybase_num_fields</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_num_rows", QString("<u>sybase_num_rows</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_pconnect", QString("<u>sybase_pconnect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_query", QString("<u>sybase_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_result", QString("<u>sybase_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_select_db", QString("<u>sybase_select_db</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_set_message_handler", QString("<u>sybase_set_message_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sybase_unbuffered_query", QString("<u>sybase_unbuffered_query</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("symlink", QString("<u>symlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sys_get_temp_dir", QString("<u>sys_get_temp_dir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("sys_getloadavg", QString("<u>sys_getloadavg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("syslog", QString("<u>syslog</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("system", QString("<u>system</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tan", QString("<u>tan</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tanh", QString("<u>tanh</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tcpwrap_check", QString("<u>tcpwrap_check</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tempnam", QString("<u>tempnam</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("textdomain", QString("<u>textdomain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy", QString("<u>tidy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_access_count", QString("<u>tidy_access_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_config_count", QString("<u>tidy_config_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_diagnose", QString("<u>tidy_diagnose</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_error_count", QString("<u>tidy_error_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_get_error_buffer", QString("<u>tidy_get_error_buffer</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_get_output", QString("<u>tidy_get_output</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_load_config", QString("<u>tidy_load_config</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_reset_config", QString("<u>tidy_reset_config</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_save_config", QString("<u>tidy_save_config</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_set_encoding", QString("<u>tidy_set_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_setopt", QString("<u>tidy_setopt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidy_warning_count", QString("<u>tidy_warning_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tidynode", QString("<u>tidynode</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("time", QString("int <u>time</u>(<b>void</b>) <br />%1").arg(tr("Return current Unix timestamp")));
//  data.insert("time_nanosleep", QString("<u>time_nanosleep</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("time_sleep_until", QString("<u>time_sleep_until</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_abbreviations_list", QString("<u>timezone_abbreviations_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_identifiers_list", QString("<u>timezone_identifiers_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_location_get", QString("<u>timezone_location_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_name_from_abbr", QString("<u>timezone_name_from_abbr</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_name_get", QString("<u>timezone_name_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_offset_get", QString("<u>timezone_offset_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_open", QString("<u>timezone_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_transitions_get", QString("<u>timezone_transitions_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("timezone_version_get", QString("<u>timezone_version_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tmpfile", QString("<u>tmpfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("token_get_all", QString("<u>token_get_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("token_name", QString("<u>token_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tokyotyrant", QString("<u>tokyotyrant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tokyotyrantquery", QString("<u>tokyotyrantquery</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tokyotyranttable", QString("<u>tokyotyranttable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tostring", QString("<u>tostring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("tostring", QString("<u>tostring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("touch", QString("<u>touch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("transliterator", QString("<u>transliterator</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("traversable", QString("<u>traversable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("trigger_error", QString("<u>trigger_error</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("trim", QString("<u>trim</u>(<b>string $str [, string $charlist]</b>) <br />%1").arg(tr("Strip whitespace (or other characters) from the beginning and end of a string.")));
//  data.insert("uasort", QString("<u>uasort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ucfirst", QString("<u>ucfirst</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ucwords", QString("string <u>ucwords</u>(<b>string $str</b>) <br />%1").arg(tr("Uppercase the first character of each word in a string.")));
//  data.insert("udm_add_search_limit", QString("<u>udm_add_search_limit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_alloc_agent", QString("<u>udm_alloc_agent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_alloc_agent_array", QString("<u>udm_alloc_agent_array</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_api_version", QString("<u>udm_api_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_cat_list", QString("<u>udm_cat_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_cat_path", QString("<u>udm_cat_path</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_check_charset", QString("<u>udm_check_charset</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_check_stored", QString("<u>udm_check_stored</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_clear_search_limits", QString("<u>udm_clear_search_limits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_close_stored", QString("<u>udm_close_stored</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_crc32", QString("<u>udm_crc32</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_errno", QString("<u>udm_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_error", QString("<u>udm_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_find", QString("<u>udm_find</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_free_agent", QString("<u>udm_free_agent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_free_ispell_data", QString("<u>udm_free_ispell_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_free_res", QString("<u>udm_free_res</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_get_doc_count", QString("<u>udm_get_doc_count</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_get_res_field", QString("<u>udm_get_res_field</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_get_res_param", QString("<u>udm_get_res_param</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_hash32", QString("<u>udm_hash32</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_load_ispell_data", QString("<u>udm_load_ispell_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_open_stored", QString("<u>udm_open_stored</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("udm_set_agent_param", QString("<u>udm_set_agent_param</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("uksort", QString("<u>uksort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("umask", QString("<u>umask</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("underflowexception", QString("<u>underflowexception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("unexpectedvalueexception", QString("<u>unexpectedvalueexception</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("uniqid", QString("string <u>uniqid</u>(<b>[ string $prefix = "" [, bool $more_entropy = false ]] </b>) <br />%1").arg(tr("Generate a unique ID")));
//  data.insert("unixtojd", QString("<u>unixtojd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("unlink", QString("<u>unlink</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("unpack", QString("<u>unpack</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("unregister_tick_function", QString("<u>unregister_tick_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("unserialize", QString("<u>unserialize</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("unset", QString("void <u>unset</u>(<b>mixed $var [, mixed $... ]</b>) <br />%1").arg(tr("Unset a given variable")));
//  data.insert("urldecode", QString("<u>urldecode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("urlencode", QString("<u>urlencode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("use_soap_error_handler", QString("<u>use_soap_error_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("user_error", QString("<u>user_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("usleep", QString("<u>usleep</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("usort", QString("bool <u>usort</u>(<b>array &$array, callback $cmp_function</b>) <br />%1").arg(tr("Sort an array by values using a user-defined Comparision function")));
  data.insert("utf8_decode", QString("string <u>utf8_decode</u>(<b>string $data</b>) <br />%1").arg(tr("Converts a string with ISO-8859-1 characters encoded with UTF-8 to single-byte ISO-8859-1")));
//  data.insert("utf8_encode", QString("<u>utf8_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("v8js", QString("<u>v8js</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("v8jsexception", QString("<u>v8jsexception</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("var_dump", QString("void <u>var_dump</u>(<b>mixed $expression [, mixed $... ]</b>) <br />%1").arg(tr("Dumps information about a variable")));
//  data.insert("var_export", QString("<u>var_export</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant", QString("<u>variant</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_abs", QString("<u>variant_abs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_add", QString("<u>variant_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_and", QString("<u>variant_and</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_cast", QString("<u>variant_cast</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_cat", QString("<u>variant_cat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_cmp", QString("<u>variant_cmp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_date_from_timestamp", QString("<u>variant_date_from_timestamp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_date_to_timestamp", QString("<u>variant_date_to_timestamp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_div", QString("<u>variant_div</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_eqv", QString("<u>variant_eqv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_fix", QString("<u>variant_fix</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_get_type", QString("<u>variant_get_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_idiv", QString("<u>variant_idiv</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_imp", QString("<u>variant_imp</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_int", QString("<u>variant_int</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_mod", QString("<u>variant_mod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_mul", QString("<u>variant_mul</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_neg", QString("<u>variant_neg</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_not", QString("<u>variant_not</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_or", QString("<u>variant_or</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_pow", QString("<u>variant_pow</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_round", QString("<u>variant_round</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_set", QString("<u>variant_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_set_type", QString("<u>variant_set_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_sub", QString("<u>variant_sub</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("variant_xor", QString("<u>variant_xor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("varnishadmin", QString("<u>varnishadmin</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("varnishlog", QString("<u>varnishlog</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("varnishstat", QString("<u>varnishstat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("version_compare", QString("<u>version_compare</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vfprintf", QString("<u>vfprintf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("virtual", QString("<u>virtual</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_add_alias_domain", QString("<u>vpopmail_add_alias_domain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_add_alias_domain_ex", QString("<u>vpopmail_add_alias_domain_ex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_add_domain", QString("<u>vpopmail_add_domain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_add_domain_ex", QString("<u>vpopmail_add_domain_ex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_add_user", QString("<u>vpopmail_add_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_alias_add", QString("<u>vpopmail_alias_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_alias_del", QString("<u>vpopmail_alias_del</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_alias_del_domain", QString("<u>vpopmail_alias_del_domain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_alias_get", QString("<u>vpopmail_alias_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_alias_get_all", QString("<u>vpopmail_alias_get_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_auth_user", QString("<u>vpopmail_auth_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_del_domain", QString("<u>vpopmail_del_domain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_del_domain_ex", QString("<u>vpopmail_del_domain_ex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_del_user", QString("<u>vpopmail_del_user</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_error", QString("<u>vpopmail_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_passwd", QString("<u>vpopmail_passwd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vpopmail_set_user_quota", QString("<u>vpopmail_set_user_quota</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vprintf", QString("<u>vprintf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("vsprintf", QString("<u>vsprintf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("w32api_deftype", QString("<u>w32api_deftype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("w32api_init_dtype", QString("<u>w32api_init_dtype</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("w32api_invoke_function", QString("<u>w32api_invoke_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("w32api_register_function", QString("<u>w32api_register_function</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("w32api_set_call_method", QString("<u>w32api_set_call_method</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wddx_add_vars", QString("<u>wddx_add_vars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wddx_deserialize", QString("<u>wddx_deserialize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wddx_packet_end", QString("<u>wddx_packet_end</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wddx_packet_start", QString("<u>wddx_packet_start</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wddx_serialize_value", QString("<u>wddx_serialize_value</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wddx_serialize_vars", QString("<u>wddx_serialize_vars</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("weakref", QString("<u>weakref</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_continue_service", QString("<u>win32_continue_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_create_service", QString("<u>win32_create_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_delete_service", QString("<u>win32_delete_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_get_last_control_message", QString("<u>win32_get_last_control_message</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_pause_service", QString("<u>win32_pause_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_ps_list_procs", QString("<u>win32_ps_list_procs</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_ps_stat_mem", QString("<u>win32_ps_stat_mem</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_ps_stat_proc", QString("<u>win32_ps_stat_proc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_query_service_status", QString("<u>win32_query_service_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_set_service_status", QString("<u>win32_set_service_status</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_start_service", QString("<u>win32_start_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_start_service_ctrl_dispatcher", QString("<u>win32_start_service_ctrl_dispatcher</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("win32_stop_service", QString("<u>win32_stop_service</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_fcache_fileinfo", QString("<u>wincache_fcache_fileinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_fcache_meminfo", QString("<u>wincache_fcache_meminfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_lock", QString("<u>wincache_lock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ocache_fileinfo", QString("<u>wincache_ocache_fileinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ocache_meminfo", QString("<u>wincache_ocache_meminfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_refresh_if_changed", QString("<u>wincache_refresh_if_changed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_rplist_fileinfo", QString("<u>wincache_rplist_fileinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_rplist_meminfo", QString("<u>wincache_rplist_meminfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_scache_info", QString("<u>wincache_scache_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_scache_meminfo", QString("<u>wincache_scache_meminfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_add", QString("<u>wincache_ucache_add</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_cas", QString("<u>wincache_ucache_cas</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_clear", QString("<u>wincache_ucache_clear</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_dec", QString("<u>wincache_ucache_dec</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_delete", QString("<u>wincache_ucache_delete</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_exists", QString("<u>wincache_ucache_exists</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_get", QString("<u>wincache_ucache_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_inc", QString("<u>wincache_ucache_inc</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_info", QString("<u>wincache_ucache_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_meminfo", QString("<u>wincache_ucache_meminfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_ucache_set", QString("<u>wincache_ucache_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wincache_unlock", QString("<u>wincache_unlock</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("wordwrap", QString("<u>wordwrap</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xattr_get", QString("<u>xattr_get</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xattr_list", QString("<u>xattr_list</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xattr_remove", QString("<u>xattr_remove</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xattr_set", QString("<u>xattr_set</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xattr_supported", QString("<u>xattr_supported</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_bdiff", QString("<u>xdiff_file_bdiff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_bdiff_size", QString("<u>xdiff_file_bdiff_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_bpatch", QString("<u>xdiff_file_bpatch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_diff", QString("<u>xdiff_file_diff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_diff_binary", QString("<u>xdiff_file_diff_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_merge3", QString("<u>xdiff_file_merge3</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_patch", QString("<u>xdiff_file_patch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_patch_binary", QString("<u>xdiff_file_patch_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_file_rabdiff", QString("<u>xdiff_file_rabdiff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_bdiff", QString("<u>xdiff_string_bdiff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_bdiff_size", QString("<u>xdiff_string_bdiff_size</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_bpatch", QString("<u>xdiff_string_bpatch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_diff", QString("<u>xdiff_string_diff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_diff_binary", QString("<u>xdiff_string_diff_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_merge3", QString("<u>xdiff_string_merge3</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_patch", QString("<u>xdiff_string_patch</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_patch_binary", QString("<u>xdiff_string_patch_binary</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xdiff_string_rabdiff", QString("<u>xdiff_string_rabdiff</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xhprof_disable", QString("<u>xhprof_disable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xhprof_enable", QString("<u>xhprof_enable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xhprof_sample_disable", QString("<u>xhprof_sample_disable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xhprof_sample_enable", QString("<u>xhprof_sample_enable</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_error_string", QString("<u>xml_error_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_get_current_byte_index", QString("<u>xml_get_current_byte_index</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_get_current_column_number", QString("<u>xml_get_current_column_number</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_get_current_line_number", QString("<u>xml_get_current_line_number</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_get_error_code", QString("<u>xml_get_error_code</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parse", QString("<u>xml_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parse_into_struct", QString("<u>xml_parse_into_struct</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parser_create", QString("<u>xml_parser_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parser_create_ns", QString("<u>xml_parser_create_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parser_free", QString("<u>xml_parser_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parser_get_option", QString("<u>xml_parser_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_parser_set_option", QString("<u>xml_parser_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_character_data_handler", QString("<u>xml_set_character_data_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_default_handler", QString("<u>xml_set_default_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_element_handler", QString("<u>xml_set_element_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_end_namespace_decl_handler", QString("<u>xml_set_end_namespace_decl_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_external_entity_ref_handler", QString("<u>xml_set_external_entity_ref_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_notation_decl_handler", QString("<u>xml_set_notation_decl_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_object", QString("<u>xml_set_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_processing_instruction_handler", QString("<u>xml_set_processing_instruction_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_start_namespace_decl_handler", QString("<u>xml_set_start_namespace_decl_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xml_set_unparsed_entity_decl_handler", QString("<u>xml_set_unparsed_entity_decl_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlreader", QString("<u>xmlreader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_decode", QString("<u>xmlrpc_decode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_decode_request", QString("<u>xmlrpc_decode_request</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_encode", QString("<u>xmlrpc_encode</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_encode_request", QString("<u>xmlrpc_encode_request</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_get_type", QString("<u>xmlrpc_get_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_is_fault", QString("<u>xmlrpc_is_fault</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_parse_method_descriptions", QString("<u>xmlrpc_parse_method_descriptions</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_server_add_introspection_data", QString("<u>xmlrpc_server_add_introspection_data</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_server_call_method", QString("<u>xmlrpc_server_call_method</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_server_create", QString("<u>xmlrpc_server_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_server_destroy", QString("<u>xmlrpc_server_destroy</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_server_register_introspection_callback", QString("<u>xmlrpc_server_register_introspection_callback</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_server_register_method", QString("<u>xmlrpc_server_register_method</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlrpc_set_type", QString("<u>xmlrpc_set_type</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_attribute", QString("<u>xmlwriter_end_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_cdata", QString("<u>xmlwriter_end_cdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_comment", QString("<u>xmlwriter_end_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_document", QString("<u>xmlwriter_end_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_dtd", QString("<u>xmlwriter_end_dtd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_dtd_attlist", QString("<u>xmlwriter_end_dtd_attlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_dtd_element", QString("<u>xmlwriter_end_dtd_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_dtd_entity", QString("<u>xmlwriter_end_dtd_entity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_element", QString("<u>xmlwriter_end_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_end_pi", QString("<u>xmlwriter_end_pi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_flush", QString("<u>xmlwriter_flush</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_full_end_element", QString("<u>xmlwriter_full_end_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_open_memory", QString("<u>xmlwriter_open_memory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_open_uri", QString("<u>xmlwriter_open_uri</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_output_memory", QString("<u>xmlwriter_output_memory</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_set_indent", QString("<u>xmlwriter_set_indent</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_set_indent_string", QString("<u>xmlwriter_set_indent_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_attribute", QString("<u>xmlwriter_start_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_attribute_ns", QString("<u>xmlwriter_start_attribute_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_cdata", QString("<u>xmlwriter_start_cdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_comment", QString("<u>xmlwriter_start_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_document", QString("<u>xmlwriter_start_document</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_dtd", QString("<u>xmlwriter_start_dtd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_dtd_attlist", QString("<u>xmlwriter_start_dtd_attlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_dtd_element", QString("<u>xmlwriter_start_dtd_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_dtd_entity", QString("<u>xmlwriter_start_dtd_entity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_element", QString("<u>xmlwriter_start_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_element_ns", QString("<u>xmlwriter_start_element_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_start_pi", QString("<u>xmlwriter_start_pi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_text", QString("<u>xmlwriter_text</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_attribute", QString("<u>xmlwriter_write_attribute</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_attribute_ns", QString("<u>xmlwriter_write_attribute_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_cdata", QString("<u>xmlwriter_write_cdata</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_comment", QString("<u>xmlwriter_write_comment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_dtd", QString("<u>xmlwriter_write_dtd</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_dtd_attlist", QString("<u>xmlwriter_write_dtd_attlist</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_dtd_element", QString("<u>xmlwriter_write_dtd_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_dtd_entity", QString("<u>xmlwriter_write_dtd_entity</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_element", QString("<u>xmlwriter_write_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_element_ns", QString("<u>xmlwriter_write_element_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_pi", QString("<u>xmlwriter_write_pi</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xmlwriter_write_raw", QString("<u>xmlwriter_write_raw</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xpath_eval", QString("<u>xpath_eval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xpath_eval_expression", QString("<u>xpath_eval_expression</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xpath_new_context", QString("<u>xpath_new_context</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xpath_register_ns", QString("<u>xpath_register_ns</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xpath_register_ns_auto", QString("<u>xpath_register_ns_auto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xptr_eval", QString("<u>xptr_eval</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xptr_new_context", QString("<u>xptr_new_context</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_backend_info", QString("<u>xslt_backend_info</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_backend_name", QString("<u>xslt_backend_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_backend_version", QString("<u>xslt_backend_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_create", QString("<u>xslt_create</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_errno", QString("<u>xslt_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_error", QString("<u>xslt_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_free", QString("<u>xslt_free</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_getopt", QString("<u>xslt_getopt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_process", QString("<u>xslt_process</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_base", QString("<u>xslt_set_base</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_encoding", QString("<u>xslt_set_encoding</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_error_handler", QString("<u>xslt_set_error_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_log", QString("<u>xslt_set_log</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_object", QString("<u>xslt_set_object</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_sax_handler", QString("<u>xslt_set_sax_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_sax_handlers", QString("<u>xslt_set_sax_handlers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_scheme_handler", QString("<u>xslt_set_scheme_handler</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_set_scheme_handlers", QString("<u>xslt_set_scheme_handlers</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xslt_setopt", QString("<u>xslt_setopt</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("xsltprocessor", QString("<u>xsltprocessor</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_action_abstract", QString("<u>yaf_action_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_application", QString("<u>yaf_application</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_bootstrap_abstract", QString("<u>yaf_bootstrap_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_config_abstract", QString("<u>yaf_config_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_config_ini", QString("<u>yaf_config_ini</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_config_simple", QString("<u>yaf_config_simple</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_controller_abstract", QString("<u>yaf_controller_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_dispatcher", QString("<u>yaf_dispatcher</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception", QString("<u>yaf_exception</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_dispatchfailed", QString("<u>yaf_exception_dispatchfailed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_loadfailed", QString("<u>yaf_exception_loadfailed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_loadfailed_action", QString("<u>yaf_exception_loadfailed_action</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_loadfailed_controller", QString("<u>yaf_exception_loadfailed_controller</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_loadfailed_module", QString("<u>yaf_exception_loadfailed_module</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_loadfailed_view", QString("<u>yaf_exception_loadfailed_view</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_routerfailed", QString("<u>yaf_exception_routerfailed</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_startuperror", QString("<u>yaf_exception_startuperror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_exception_typeerror", QString("<u>yaf_exception_typeerror</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_loader", QString("<u>yaf_loader</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_plugin_abstract", QString("<u>yaf_plugin_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_registry", QString("<u>yaf_registry</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_request_abstract", QString("<u>yaf_request_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_request_http", QString("<u>yaf_request_http</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_request_simple", QString("<u>yaf_request_simple</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_response_abstract", QString("<u>yaf_response_abstract</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_interface", QString("<u>yaf_route_interface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_map", QString("<u>yaf_route_map</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_regex", QString("<u>yaf_route_regex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_rewrite", QString("<u>yaf_route_rewrite</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_simple", QString("<u>yaf_route_simple</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_static", QString("<u>yaf_route_static</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_route_supervar", QString("<u>yaf_route_supervar</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_router", QString("<u>yaf_router</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_session", QString("<u>yaf_session</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_view_interface", QString("<u>yaf_view_interface</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaf_view_simple", QString("<u>yaf_view_simple</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaml_emit", QString("<u>yaml_emit</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaml_emit_file", QString("<u>yaml_emit_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaml_parse", QString("<u>yaml_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaml_parse_file", QString("<u>yaml_parse_file</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaml_parse_url", QString("<u>yaml_parse_url</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_addinfo", QString("<u>yaz_addinfo</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_ccl_conf", QString("<u>yaz_ccl_conf</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_ccl_parse", QString("<u>yaz_ccl_parse</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_close", QString("<u>yaz_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_connect", QString("<u>yaz_connect</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_database", QString("<u>yaz_database</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_element", QString("<u>yaz_element</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_errno", QString("<u>yaz_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_error", QString("<u>yaz_error</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_es", QString("<u>yaz_es</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_es_result", QString("<u>yaz_es_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_get_option", QString("<u>yaz_get_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_hits", QString("<u>yaz_hits</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_itemorder", QString("<u>yaz_itemorder</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_present", QString("<u>yaz_present</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_range", QString("<u>yaz_range</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_record", QString("<u>yaz_record</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_scan", QString("<u>yaz_scan</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_scan_result", QString("<u>yaz_scan_result</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_schema", QString("<u>yaz_schema</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_search", QString("<u>yaz_search</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_set_option", QString("<u>yaz_set_option</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_sort", QString("<u>yaz_sort</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_syntax", QString("<u>yaz_syntax</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yaz_wait", QString("<u>yaz_wait</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_all", QString("<u>yp_all</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_cat", QString("<u>yp_cat</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_err_string", QString("<u>yp_err_string</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_errno", QString("<u>yp_errno</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_first", QString("<u>yp_first</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_get_default_domain", QString("<u>yp_get_default_domain</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_master", QString("<u>yp_master</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_match", QString("<u>yp_match</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_next", QString("<u>yp_next</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("yp_order", QString("<u>yp_order</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zend_logo_guid", QString("<u>zend_logo_guid</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zend_thread_id", QString("<u>zend_thread_id</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zend_version", QString("<u>zend_version</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_close", QString("<u>zip_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_close", QString("<u>zip_entry_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_compressedsize", QString("<u>zip_entry_compressedsize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_compressionmethod", QString("<u>zip_entry_compressionmethod</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_filesize", QString("<u>zip_entry_filesize</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_name", QString("<u>zip_entry_name</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_open", QString("<u>zip_entry_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_entry_read", QString("<u>zip_entry_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_open", QString("<u>zip_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zip_read", QString("<u>zip_read</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive", QString("<u>ziparchive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_addemptydir", QString("<u>ziparchive_addemptydir</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_addfile", QString("<u>ziparchive_addfile</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_addfromstring", QString("<u>ziparchive_addfromstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_close", QString("<u>ziparchive_close</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_deleteindex", QString("<u>ziparchive_deleteindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_deletename", QString("<u>ziparchive_deletename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_extractto", QString("<u>ziparchive_extractto</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getarchivecomment", QString("<u>ziparchive_getarchivecomment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getcommentindex", QString("<u>ziparchive_getcommentindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getcommentname", QString("<u>ziparchive_getcommentname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getfromindex", QString("<u>ziparchive_getfromindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getfromname", QString("<u>ziparchive_getfromname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getnameindex", QString("<u>ziparchive_getnameindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getstatusstring", QString("<u>ziparchive_getstatusstring</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_getstream", QString("<u>ziparchive_getstream</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_locatename", QString("<u>ziparchive_locatename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_open", QString("<u>ziparchive_open</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_renameindex", QString("<u>ziparchive_renameindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_renamename", QString("<u>ziparchive_renamename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_setCommentName", QString("<u>ziparchive_setCommentName</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_setarchivecomment", QString("<u>ziparchive_setarchivecomment</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_setcommentindex", QString("<u>ziparchive_setcommentindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_statindex", QString("<u>ziparchive_statindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_statname", QString("<u>ziparchive_statname</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_unchangeall", QString("<u>ziparchive_unchangeall</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_unchangearchive", QString("<u>ziparchive_unchangearchive</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_unchangeindex", QString("<u>ziparchive_unchangeindex</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("ziparchive_unchangename", QString("<u>ziparchive_unchangename</u>(<b></b>) <br />%1").arg(tr("")));
//  data.insert("zlib_get_coding_type", QString("<u>zlib_get_coding_type</u>(<b></b>) <br />%1").arg(tr("")));
  return data;
}

QStringList StaticFunctions::phpFunctions()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(phpFunctionsComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}

QStringList StaticFunctions::phpKeywords()
{
  return QStringList() << "abs"
      << "abstract"
      << "__CLASS__"
      << "__construct"
      << "__DIR__"
      << "__destruct"
      << "__FILE__"
      << "__FUNCTION__"
      << "__LINE__"
      << "__METHOD__"
      << "__NAMESPACE__"
      << "and"
      << "array"
      << "as"
      << "break"
      << "case"
      << "catch"
      << "class"
      << "clone"
      << "const"
      << "continue"
      << "declare"
      << "default"
      << "do"
      << "else"
      << "elseif"
      << "endeclare"
      << "endfoeach"
      << "endfor"
      << "endif"
      << "endswitch"
      << "endwhile"
      << "exception"
      << "extends"
      << "false"
      << "final"
      << "for"
      << "foreach"
      << "function"
      << "global"
      << "goto"
      << "if"
      << "implements"
      << "instanceof"
      << "interface"
      << "LC_ALL"
      << "LC_COLLATE"
      << "LC_CTYPE"
      << "LC_MONETARY"
      << "LC_NUMERIC"
      << "LC_TIME"
      << "LC_MESSAGES"
      << "MYSQL_ASSOC"
      << "MYSQL_NUM"
      << "namespace"
      << "new"
      << "null"
      << "or"
      << "parent"
      << "PATHINFO_DIRNAME"
      << "PATHINFO_FILENAME"
      << "PHP_URL_HOST"
      << "PHP_URL_PASS"
      << "PHP_URL_PATH"
      << "PHP_URL_USER"
      << "private"
      << "protected"
      << "public"
      << "return"
      << "static"
      << "switch"
      << "thow"
      << "true"
      << "try"
      << "use"
      << "var"
      << "while"
      << "xor";
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

QHash<QString, QString> StaticFunctions::cssPropertiesComplete()
{
  QHash<QString, QString> data;
  data.insert("@font-face", QString("<u>@font-face</u><br />%1").arg(tr("A rule that allows websites to download and use fonts other than the 'web-safe' fonts")));
  data.insert("@keyframes", QString("<u>@keyframes</u><br />%1").arg(tr("Specifies the animation")));
  data.insert("alignment-adjust", QString("<u>alignment-adjust</u><br />%1").arg(tr("Allows more precise alignment of elements")));
  data.insert("alignment-baseline", QString("<u>alignment-baseline</u><br />%1").arg(tr("Specifies how an inline-level element is aligned with respect to its parent")));
  data.insert("animation", QString("<u>animation</u><br />%1").arg(tr("A shorthand property for all the animation properties below, except the animation-play-state property")));
  data.insert("animation-delay", QString("<u>animation-delay</u><br />%1").arg(tr("Specifies when the animation will start")));
  data.insert("animation-direction", QString("<u>animation-direction</u><br />%1").arg(tr("Specifies whether or not the animation should play in reverse on alternate cycles")));
  data.insert("animation-duration", QString("<u>animation-duration</u><br />%1").arg(tr("Specifies how many seconds or milliseconds an animation takes to complete one cycle")));
  data.insert("animation-iteration-count", QString("<u>animation-iteration-count</u><br />%1").arg(tr("Specifies the number of times an animation should be played")));
  data.insert("animation-name", QString("<u>animation-name</u><br />%1").arg(tr("Specifies a name for the @keyframes animation")));
  data.insert("animation-play-state", QString("<u>animation-play-state</u><br />%1").arg(tr("Specifies whether the animation is running or paused")));
  data.insert("animation-timing-function", QString("<u>animation-timing-function</u><br />%1").arg(tr("Specifies the speed curve of the animation")));
  data.insert("appearance", QString("<u>appearance</u><br />%1").arg(tr("Allows you to make an element look like a standard user interface element")));
  data.insert("backface-visibility", QString("<u>backface-visibility</u><br />%1").arg(tr("Defines whether or not an element should be visible when not facing the screen")));
  data.insert("background", QString("<u>background</u><br />%1").arg(tr("Sets all the background properties in one declaration")));
  data.insert("background-attachment", QString("<u>background-attachment</u><br />%1").arg(tr("Sets whether a background image is fixed or scrolls with the rest of the page")));
  data.insert("background-clip", QString("<u>background-clip</u><br />%1").arg(tr("Specifies the painting area of the background")));
  data.insert("background-color", QString("<u>background-color</u><br />%1").arg(tr("Sets the background color of an element")));
  data.insert("background-image", QString("<u>background-image</u><br />%1").arg(tr("Sets the background image for an element")));
  data.insert("background-origin", QString("<u>background-origin</u><br />%1").arg(tr("Specifies the positioning area of the background images")));
  data.insert("background-position", QString("<u>background-position</u><br />%1").arg(tr("Sets the starting position of a background image")));
  data.insert("background-repeat", QString("<u>background-repeat</u><br />%1").arg(tr("Sets how a background image will be repeated")));
  data.insert("background-size", QString("<u>background-size</u><br />%1").arg(tr("Specifies the size of the background images")));
  data.insert("baseline-shift", QString("<u>baseline-shift</u><br />%1").arg(tr("Allows repositioning of the dominant-baseline relative to the dominant-baseline")));
  data.insert("bookmark-label", QString("<u>bookmark-label</u><br />%1").arg(tr("Specifies the label of the bookmark")));
  data.insert("bookmark-level", QString("<u>bookmark-level</u><br />%1").arg(tr("Specifies the level of the bookmark")));
  data.insert("bookmark-target", QString("<u>bookmark-target</u><br />%1").arg(tr("Specifies the target of the bookmark link")));
  data.insert("border", QString("<u>border</u><br />%1").arg(tr("Sets all the border properties in one declaration")));
  data.insert("border-bottom", QString("<u>border-bottom</u><br />%1").arg(tr("Sets all the bottom border properties in one declaration")));
  data.insert("border-bottom-color", QString("<u>border-bottom-color</u><br />%1").arg(tr("Sets the color of the bottom border")));
  data.insert("border-bottom-left-radius", QString("<u>border-bottom-left-radius</u><br />%1").arg(tr("Defines the shape of the border of the bottom-left corner")));
  data.insert("border-bottom-right-radius", QString("<u>border-bottom-right-radius</u><br />%1").arg(tr("Defines the shape of the border of the bottom-right corner")));
  data.insert("border-bottom-style", QString("<u>border-bottom-style</u><br />%1").arg(tr("Sets the style of the bottom border")));
  data.insert("border-bottom-width", QString("<u>border-bottom-width</u><br />%1").arg(tr("Sets the width of the bottom border")));
  data.insert("border-collapse", QString("<u>border-collapse</u><br />%1").arg(tr("Specifies whether or not table borders should be collapsed")));
  data.insert("border-color", QString("<u>border-color</u><br />%1").arg(tr("Sets the color of the four borders")));
  data.insert("border-image", QString("<u>border-image</u><br />%1").arg(tr("A shorthand property for setting all the border-image-* properties")));
  data.insert("border-image-outset", QString("<u>border-image-outset</u><br />%1").arg(tr("Specifies the amount by which the border image area extends beyond the border box")));
  data.insert("border-image-repeat", QString("<u>border-image-repeat</u><br />%1").arg(tr("Specifies whether the image-border should be repeated, rounded or stretched")));
  data.insert("border-image-slice", QString("<u>border-image-slice</u><br />%1").arg(tr("Specifies the inward offsets of the image-border")));
  data.insert("border-image-source", QString("<u>border-image-source</u><br />%1").arg(tr("Specifies an image to be used as a border")));
  data.insert("border-image-width", QString("<u>border-image-width</u><br />%1").arg(tr("Specifies the widths of the image-border")));
  data.insert("border-left", QString("<u>border-left</u><br />%1").arg(tr("Sets all the left border properties in one declaration")));
  data.insert("border-left-color", QString("<u>border-left-color</u><br />%1").arg(tr("Sets the color of the left border")));
  data.insert("border-left-style", QString("<u>border-left-style</u><br />%1").arg(tr("Sets the style of the left border")));
  data.insert("border-left-width", QString("<u>border-left-width</u><br />%1").arg(tr("Sets the width of the left border")));
  data.insert("border-radius", QString("<u>border-radius</u><br />%1").arg(tr("A shorthand property for setting all the four border-*-radius properties")));
  data.insert("border-right", QString("<u>border-right</u><br />%1").arg(tr("Sets all the right border properties in one declaration")));
  data.insert("border-right-color", QString("<u>border-right-color</u><br />%1").arg(tr("Sets the color of the right border")));
  data.insert("border-right-style", QString("<u>border-right-style</u><br />%1").arg(tr("Sets the style of the right border")));
  data.insert("border-right-width", QString("<u>border-right-width</u><br />%1").arg(tr("Sets the width of the right border")));
  data.insert("border-spacing", QString("<u>border-spacing</u><br />%1").arg(tr("Specifies the distance between the borders of adjacent cells")));
  data.insert("border-style", QString("<u>border-style</u><br />%1").arg(tr("Sets the style of the four borders")));
  data.insert("border-top", QString("<u>border-top</u><br />%1").arg(tr("Sets all the top border properties in one declaration")));
  data.insert("border-top-color", QString("<u>border-top-color</u><br />%1").arg(tr("Sets the color of the top border")));
  data.insert("border-top-left-radius", QString("<u>border-top-left-radius</u><br />%1").arg(tr("Defines the shape of the border of the top-left corner")));
  data.insert("border-top-right-radius", QString("<u>border-top-right-radius</u><br />%1").arg(tr("Defines the shape of the border of the top-right corner")));
  data.insert("border-top-style", QString("<u>border-top-style</u><br />%1").arg(tr("Sets the style of the top border")));
  data.insert("border-top-width", QString("<u>border-top-width</u><br />%1").arg(tr("Sets the width of the top border")));
  data.insert("border-width", QString("<u>border-width</u><br />%1").arg(tr("Sets the width of the four borders")));
  data.insert("bottom", QString("<u>bottom</u><br />%1").arg(tr("Specifies the bottom position of a positioned element")));
  data.insert("box-align", QString("<u>box-align</u><br />%1").arg(tr("Specifies how to align the child elements of a box")));
  data.insert("box-decoration-break", QString("<u>box-decoration-break</u><br />%1").arg(tr(" ")));
  data.insert("box-direction", QString("<u>box-direction</u><br />%1").arg(tr("Specifies in which direction the children of a box are displayed")));
  data.insert("box-flex", QString("<u>box-flex</u><br />%1").arg(tr("Specifies whether the children of a box is flexible or inflexible in size")));
  data.insert("box-flex-group", QString("<u>box-flex-group</u><br />%1").arg(tr("Assigns flexible elements to flex groups")));
  data.insert("box-lines", QString("<u>box-lines</u><br />%1").arg(tr("Specifies whether columns will go onto a new line whenever it runs out of space in the parent box")));
  data.insert("box-ordinal-group", QString("<u>box-ordinal-group</u><br />%1").arg(tr("Specifies the display order of the child elements of a box")));
  data.insert("box-orient", QString("<u>box-orient</u><br />%1").arg(tr("Specifies whether the children of a box should be laid out horizontally or vertically")));
  data.insert("box-pack", QString("<u>box-pack</u><br />%1").arg(tr("Specifies the horizontal position in horizontal boxes and the vertical position in vertical boxes")));
  data.insert("box-shadow", QString("<u>box-shadow</u><br />%1").arg(tr("Attaches one or more drop-shadows to the box")));
  data.insert("box-sizing", QString("<u>box-sizing</u><br />%1").arg(tr("Allows you to define certain elements to fit an area in a certain way")));
  data.insert("caption-side", QString("<u>caption-side</u><br />%1").arg(tr("Specifies the placement of a table caption")));
  data.insert("clear", QString("<u>clear</u><br />%1").arg(tr("Specifies which sides of an element where other floating elements are not allowed")));
  data.insert("clip", QString("<u>clip</u><br />%1").arg(tr("Clips an absolutely positioned element")));
  data.insert("color", QString("<u>color</u><br />%1").arg(tr("Sets the color of text")));
  data.insert("color-profile", QString("<u>color-profile</u><br />%1").arg(tr("Permits the specification of a source color profile other than the default")));
  data.insert("column-count", QString("<u>column-count</u><br />%1").arg(tr("Specifies the number of columns an element should be divided into")));
  data.insert("column-fill", QString("<u>column-fill</u><br />%1").arg(tr("Specifies how to fill columns")));
  data.insert("column-gap", QString("<u>column-gap</u><br />%1").arg(tr("Specifies the gap between the columns")));
  data.insert("column-rule", QString("<u>column-rule</u><br />%1").arg(tr("A shorthand property for setting all the column-rule-* properties")));
  data.insert("column-rule-color", QString("<u>column-rule-color</u><br />%1").arg(tr("Specifies the color of the rule between columns")));
  data.insert("column-rule-style", QString("<u>column-rule-style</u><br />%1").arg(tr("Specifies the style of the rule between columns")));
  data.insert("column-rule-width", QString("<u>column-rule-width</u><br />%1").arg(tr("Specifies the width of the rule between columns")));
  data.insert("column-span", QString("<u>column-span</u><br />%1").arg(tr("Specifies how many columns an element should span across")));
  data.insert("column-width", QString("<u>column-width</u><br />%1").arg(tr("Specifies the width of the columns")));
  data.insert("columns", QString("<u>columns</u><br />%1").arg(tr("A shorthand property for setting column-width and column-count")));
  data.insert("content", QString("<u>content</u><br />%1").arg(tr("Used with the :before and :after pseudo-elements, to insert generated content")));
  data.insert("counter-increment", QString("<u>counter-increment</u><br />%1").arg(tr("Increments one or more counters")));
  data.insert("counter-reset", QString("<u>counter-reset</u><br />%1").arg(tr("Creates or resets one or more counters")));
  data.insert("crop", QString("<u>crop</u><br />%1").arg(tr("Allows a replaced element to be just a rectangular area of an object, instead of the whole object")));
  data.insert("cursor", QString("<u>cursor</u><br />%1").arg(tr("Specifies the type of cursor to be displayed")));
  data.insert("direction", QString("<u>direction</u><br />%1").arg(tr("Specifies the text direction/writing direction")));
  data.insert("display", QString("<u>display</u><br />%1").arg(tr("Specifies how a certain HTML element should be displayed")));
  data.insert("dominant-baseline", QString("<u>dominant-baseline</u><br />%1").arg(tr("Specifies a scaled-baseline-table")));
  data.insert("drop-initial-after-adjust", QString("<u>drop-initial-after-adjust</u><br />%1").arg(tr("Sets the alignment point of the drop initial for the primary connection point")));
  data.insert("drop-initial-after-align", QString("<u>drop-initial-after-align</u><br />%1").arg(tr("Sets which alignment line within the initial line box is used at the primary connection point with the initial letter box")));
  data.insert("drop-initial-before-adjust", QString("<u>drop-initial-before-adjust</u><br />%1").arg(tr("Sets the alignment point of the drop initial for the secondary connection point")));
  data.insert("drop-initial-before-align", QString("<u>drop-initial-before-align</u><br />%1").arg(tr("Sets which alignment line within the initial line box is used at the secondary connection point with the initial letter box")));
  data.insert("drop-initial-size", QString("<u>drop-initial-size</u><br />%1").arg(tr("Controls the partial sinking of the initial letter")));
  data.insert("drop-initial-value", QString("<u>drop-initial-value</u><br />%1").arg(tr("Activates a drop-initial effect")));
  data.insert("empty-cells", QString("<u>empty-cells</u><br />%1").arg(tr("Specifies whether or not to display borders and background on empty cells in a table")));
  data.insert("fit", QString("<u>fit</u><br />%1").arg(tr("Gives a hint for how to scale a replaced element if neither its width nor its height property is auto")));
  data.insert("fit-position", QString("<u>fit-position</u><br />%1").arg(tr("Determines the alignment of the object inside the box")));
  data.insert("float", QString("<u>float</u><br />%1").arg(tr("Specifies whether or not a box should float")));
  data.insert("float-offset", QString("<u>float-offset</u><br />%1").arg(tr("Pushes floated elements in the opposite direction of the where they have been floated with float")));
  data.insert("font", QString("<u>font</u><br />%1").arg(tr("Sets all the font properties in one declaration")));
  data.insert("font-family", QString("<u>font-family</u><br />%1").arg(tr("Specifies the font family for text")));
  data.insert("font-size", QString("<u>font-size</u><br />%1").arg(tr("Specifies the font size of text")));
  data.insert("font-size-adjust", QString("<u>font-size-adjust</u><br />%1").arg(tr("Preserves the readability of text when font fallback occurs")));
  data.insert("font-stretch", QString("<u>font-stretch</u><br />%1").arg(tr("Selects a normal, condensed, or expanded face from a font family")));
  data.insert("font-style", QString("<u>font-style</u><br />%1").arg(tr("Specifies the font style for text")));
  data.insert("font-variant", QString("<u>font-variant</u><br />%1").arg(tr("Specifies whether or not a text should be displayed in a small-caps font")));
  data.insert("font-weight", QString("<u>font-weight</u><br />%1").arg(tr("Specifies the weight of a font")));
  data.insert("grid-columns", QString("<u>grid-columns</u><br />%1").arg(tr("Specifies the width of each column in a grid")));
  data.insert("grid-rows", QString("<u>grid-rows</u><br />%1").arg(tr("Specifies the height of each column in a grid")));
  data.insert("hanging-punctuation", QString("<u>hanging-punctuation</u><br />%1").arg(tr("Specifies whether a punctuation character may be placed outside the line box")));
  data.insert("height", QString("<u>height</u><br />%1").arg(tr("Sets the height of an element")));
  data.insert("hyphenate-after", QString("<u>hyphenate-after</u><br />%1").arg(tr("Specifies the minimum number of characters in a hyphenated word after the hyphenation character")));
  data.insert("hyphenate-before", QString("<u>hyphenate-before</u><br />%1").arg(tr("Specifies the minimum number of characters in a hyphenated word before the hyphenation character")));
  data.insert("hyphenate-character", QString("<u>hyphenate-character</u><br />%1").arg(tr("Specifies a string that is shown when a hyphenate-break occurs")));
  data.insert("hyphenate-lines", QString("<u>hyphenate-lines</u><br />%1").arg(tr("Indicates the maximum number of successive hyphenated lines in an element")));
  data.insert("hyphenate-resource", QString("<u>hyphenate-resource</u><br />%1").arg(tr("Specifies a comma-separated list of external resources that can help the browser determine hyphenation points")));
  data.insert("hyphens", QString("<u>hyphens</u><br />%1").arg(tr("Sets how to split words to improve the layout of paragraphs")));
  data.insert("icon", QString("<u>icon</u><br />%1").arg(tr("Provides the author the ability to style an element with an iconic equivalent")));
  data.insert("image-orientation", QString("<u>image-orientation</u><br />%1").arg(tr("Specifies a rotation in the right or clockwise direction that a user agent applies to an image")));
  data.insert("image-resolution", QString("<u>image-resolution</u><br />%1").arg(tr("Specifies the correct resolution of images")));
  data.insert("inline-box-align", QString("<u>inline-box-align</u><br />%1").arg(tr("Sets which line of a multi-line inline block align with the previous and next inline elements within a line")));
  data.insert("left", QString("<u>left</u><br />%1").arg(tr("Specifies the left position of a positioned element")));
  data.insert("letter-spacing", QString("<u>letter-spacing</u><br />%1").arg(tr("Increases or decreases the space between characters in a text")));
  data.insert("line-height", QString("<u>line-height</u><br />%1").arg(tr("Sets the line height")));
  data.insert("line-stacking", QString("<u>line-stacking</u><br />%1").arg(tr("A shorthand property for setting the line-stacking-strategy, line-stacking-ruby, and line-stacking-shift properties")));
  data.insert("line-stacking-ruby", QString("<u>line-stacking-ruby</u><br />%1").arg(tr("Sets the line stacking method for block elements containing ruby annotation elements")));
  data.insert("line-stacking-shift", QString("<u>line-stacking-shift</u><br />%1").arg(tr("Sets the line stacking method for block elements containing elements with base-shift")));
  data.insert("line-stacking-strategy", QString("<u>line-stacking-strategy</u><br />%1").arg(tr("Sets the line stacking strategy for stacked line boxes within a containing block element")));
  data.insert("list-style", QString("<u>list-style</u><br />%1").arg(tr("Sets all the properties for a list in one declaration")));
  data.insert("list-style-image", QString("<u>list-style-image</u><br />%1").arg(tr("Specifies an image as the list-item marker")));
  data.insert("list-style-position", QString("<u>list-style-position</u><br />%1").arg(tr("Specifies if the list-item markers should appear inside or outside the content flow")));
  data.insert("list-style-type", QString("<u>list-style-type</u><br />%1").arg(tr("Specifies the type of list-item marker")));
  data.insert("margin", QString("<u>margin</u><br />%1").arg(tr("Sets all the margin properties in one declaration")));
  data.insert("margin-bottom", QString("<u>margin-bottom</u><br />%1").arg(tr("Sets the bottom margin of an element")));
  data.insert("margin-left", QString("<u>margin-left</u><br />%1").arg(tr("Sets the left margin of an element")));
  data.insert("margin-right", QString("<u>margin-right</u><br />%1").arg(tr("Sets the right margin of an element")));
  data.insert("margin-top", QString("<u>margin-top</u><br />%1").arg(tr("Sets the top margin of an element")));
  data.insert("mark", QString("<u>mark</u><br />%1").arg(tr("A shorthand property for setting the mark-before and mark-after properties")));
  data.insert("mark-after", QString("<u>mark-after</u><br />%1").arg(tr("Allows named markers to be attached to the audio stream")));
  data.insert("mark-before", QString("<u>mark-before</u><br />%1").arg(tr("Allows named markers to be attached to the audio stream")));
  data.insert("marks", QString("<u>marks</u><br />%1").arg(tr("Adds crop and/or cross marks to the document")));
  data.insert("marquee-direction", QString("<u>marquee-direction</u><br />%1").arg(tr("Sets the direction of the moving content")));
  data.insert("marquee-play-count", QString("<u>marquee-play-count</u><br />%1").arg(tr("Sets how many times the content move")));
  data.insert("marquee-speed", QString("<u>marquee-speed</u><br />%1").arg(tr("Sets how fast the content scrolls")));
  data.insert("marquee-style", QString("<u>marquee-style</u><br />%1").arg(tr("Sets the style of the moving content")));
  data.insert("max-height", QString("<u>max-height</u><br />%1").arg(tr("Sets the maximum height of an element")));
  data.insert("max-width", QString("<u>max-width</u><br />%1").arg(tr("Sets the maximum width of an element")));
  data.insert("min-height", QString("<u>min-height</u><br />%1").arg(tr("Sets the minimum height of an element")));
  data.insert("min-width", QString("<u>min-width</u><br />%1").arg(tr("Sets the minimum width of an element")));
  data.insert("move-to", QString("<u>move-to</u><br />%1").arg(tr("Causes an element to be removed from the flow and reinserted at a later point in the document")));
  data.insert("nav-down", QString("<u>nav-down</u><br />%1").arg(tr("Specifies where to navigate when using the arrow-down navigation key")));
  data.insert("nav-index", QString("<u>nav-index</u><br />%1").arg(tr("Specifies the tabbing order for an element")));
  data.insert("nav-left", QString("<u>nav-left</u><br />%1").arg(tr("Specifies where to navigate when using the arrow-left navigation key")));
  data.insert("nav-right", QString("<u>nav-right</u><br />%1").arg(tr("Specifies where to navigate when using the arrow-right navigation key")));
  data.insert("nav-up", QString("<u>nav-up</u><br />%1").arg(tr("Specifies where to navigate when using the arrow-up navigation key")));
  data.insert("opacity", QString("<u>opacity</u><br />%1").arg(tr("Sets the opacity level for an element")));
  data.insert("orphans", QString("<u>orphans</u><br />%1").arg(tr("Sets the minimum number of lines that must be left at the bottom of a page when a page break occurs inside an element")));
  data.insert("outline", QString("<u>outline</u><br />%1").arg(tr("Sets all the outline properties in one declaration")));
  data.insert("outline-color", QString("<u>outline-color</u><br />%1").arg(tr("Sets the color of an outline")));
  data.insert("outline-offset", QString("<u>outline-offset</u><br />%1").arg(tr("Offsets an outline, and draws it beyond the border edge")));
  data.insert("outline-style", QString("<u>outline-style</u><br />%1").arg(tr("Sets the style of an outline")));
  data.insert("outline-width", QString("<u>outline-width</u><br />%1").arg(tr("Sets the width of an outline")));
  data.insert("overflow", QString("<u>overflow</u><br />%1").arg(tr("Specifies what happens if content overflows an element's box")));
  data.insert("overflow-style", QString("<u>overflow-style</u><br />%1").arg(tr("Specifies the preferred scrolling method for elements that overflow")));
  data.insert("overflow-x", QString("<u>overflow-x</u><br />%1").arg(tr("Specifies whether or not to clip the left/right edges of the content, if it overflows the element's content area")));
  data.insert("overflow-y", QString("<u>overflow-y</u><br />%1").arg(tr("Specifies whether or not to clip the top/bottom edges of the content, if it overflows the element's content area")));
  data.insert("padding", QString("<u>padding</u><br />%1").arg(tr("Sets all the padding properties in one declaration")));
  data.insert("padding-bottom", QString("<u>padding-bottom</u><br />%1").arg(tr("Sets the bottom padding of an element")));
  data.insert("padding-left", QString("<u>padding-left</u><br />%1").arg(tr("Sets the left padding of an element")));
  data.insert("padding-right", QString("<u>padding-right</u><br />%1").arg(tr("Sets the right padding of an element")));
  data.insert("padding-top", QString("<u>padding-top</u><br />%1").arg(tr("Sets the top padding of an element")));
  data.insert("page", QString("<u>page</u><br />%1").arg(tr("Specifies a particular type of page where an element SHOULD be displayed")));
  data.insert("page-break-after", QString("<u>page-break-after</u><br />%1").arg(tr("Sets the page-breaking behavior after an element")));
  data.insert("page-break-before", QString("<u>page-break-before</u><br />%1").arg(tr("Sets the page-breaking behavior before an element")));
  data.insert("page-break-inside", QString("<u>page-break-inside</u><br />%1").arg(tr("Sets the page-breaking behavior inside an element")));
  data.insert("page-policy", QString("<u>page-policy</u><br />%1").arg(tr("Determines which page-based occurance of a given element is applied to a counter or string value")));
  data.insert("perspective", QString("<u>perspective</u><br />%1").arg(tr("Specifies the perspective on how 3D elements are viewed")));
  data.insert("perspective-origin", QString("<u>perspective-origin</u><br />%1").arg(tr("Specifies the bottom position of 3D elements")));
  data.insert("phonemes", QString("<u>phonemes</u><br />%1").arg(tr("Specifies a phonetic pronunciation for the text contained by the corresponding element")));
  data.insert("position", QString("<u>position</u><br />%1").arg(tr("Specifies the type of positioning method used for an element (static, relative, absolute or fixed)")));
  data.insert("punctuation-trim", QString("<u>punctuation-trim</u><br />%1").arg(tr("Specifies whether a punctuation character should be trimmed")));
  data.insert("quotes", QString("<u>quotes</u><br />%1").arg(tr("Sets the type of quotation marks for embedded quotations")));
  data.insert("rendering-intent", QString("<u>rendering-intent</u><br />%1").arg(tr("Permits the specification of a color profile rendering intent other than the default")));
  data.insert("resize", QString("<u>resize</u><br />%1").arg(tr("Specifies whether or not an element is resizable by the user")));
  data.insert("rest", QString("<u>rest</u><br />%1").arg(tr("A shorthand property for setting the rest-before and rest-after properties")));
  data.insert("rest-after", QString("<u>rest-after</u><br />%1").arg(tr("Specifies a rest or prosodic boundary to be observed after speaking an element's content")));
  data.insert("rest-before", QString("<u>rest-before</u><br />%1").arg(tr("Specifies a rest or prosodic boundary to be observed before speaking an element's content")));
  data.insert("right", QString("<u>right</u><br />%1").arg(tr("Specifies the right position of a positioned element")));
  data.insert("rotation", QString("<u>rotation</u><br />%1").arg(tr("Rotates an element around a given point defined by the rotation-point property")));
  data.insert("rotation-point", QString("<u>rotation-point</u><br />%1").arg(tr("Defines a point as an offset from the top left border edge")));
  data.insert("ruby-align", QString("<u>ruby-align</u><br />%1").arg(tr("Controls the text alignment of the ruby text and ruby base contents relative to each other")));
  data.insert("ruby-overhang", QString("<u>ruby-overhang</u><br />%1").arg(tr("Determines whether, and on which side, ruby text is allowed to partially overhang any adjacent text in addition to its own base, when the ruby text is wider than the ruby base")));
  data.insert("ruby-position", QString("<u>ruby-position</u><br />%1").arg(tr("Controls the position of the ruby text with respect to its base")));
  data.insert("ruby-span", QString("<u>ruby-span</u><br />%1").arg(tr("Controls the spanning behavior of annotation elements")));
  data.insert("size", QString("<u>size</u><br />%1").arg(tr("Specifies the size and orientation of the containing box for page content")));
  data.insert("string-set", QString("<u>string-set</u><br />%1").arg(tr(" ")));
  data.insert("table-layout", QString("<u>table-layout</u><br />%1").arg(tr("Sets the layout algorithm to be used for a table")));
  data.insert("target", QString("<u>target</u><br />%1").arg(tr("A shorthand property for setting the target-name, target-new, and target-position properties")));
  data.insert("target-name", QString("<u>target-name</u><br />%1").arg(tr("Specifies where to open links (target destination)")));
  data.insert("target-new", QString("<u>target-new</u><br />%1").arg(tr("Specifies whether new destination links should open in a new window or in a new tab of an existing window")));
  data.insert("target-position", QString("<u>target-position</u><br />%1").arg(tr("Specifies where new destination links should be placed")));
  data.insert("text-align", QString("<u>text-align</u><br />%1").arg(tr("Specifies the horizontal alignment of text")));
  data.insert("text-align-last", QString("<u>text-align-last</u><br />%1").arg(tr("Describes how the last line of a block or a line right before a forced line break is aligned when text-align is 'justify'")));
  data.insert("text-decoration", QString("<u>text-decoration</u><br />%1").arg(tr("Specifies the decoration added to text")));
  data.insert("text-height", QString("<u>text-height</u><br />%1").arg(tr("Sets the block-progression dimension of the text content area of an inline box")));
  data.insert("text-indent", QString("<u>text-indent</u><br />%1").arg(tr("Specifies the indentation of the first line in a text-block")));
  data.insert("text-justify", QString("<u>text-justify</u><br />%1").arg(tr("Specifies the justification method used when text-align is 'justify'")));
  data.insert("text-outline", QString("<u>text-outline</u><br />%1").arg(tr("Specifies a text outline")));
  data.insert("text-overflow", QString("<u>text-overflow</u><br />%1").arg(tr("Specifies what should happen when text overflows the containing element")));
  data.insert("text-shadow", QString("<u>text-shadow</u><br />%1").arg(tr("Adds shadow to text")));
  data.insert("text-transform", QString("<u>text-transform</u><br />%1").arg(tr("Controls the capitalization of text")));
  data.insert("text-wrap", QString("<u>text-wrap</u><br />%1").arg(tr("Specifies line breaking rules for text")));
  data.insert("top", QString("<u>top</u><br />%1").arg(tr("Specifies the top position of a positioned element")));
  data.insert("transform", QString("<u>transform</u><br />%1").arg(tr("Applies a 2D or 3D transformation to an element")));
  data.insert("transform-origin", QString("<u>transform-origin</u><br />%1").arg(tr("Allows you to change the position on transformed elements")));
  data.insert("transform-style", QString("<u>transform-style</u><br />%1").arg(tr("Specifies how nested elements are rendered in 3D space")));
  data.insert("transition", QString("<u>transition</u><br />%1").arg(tr("A shorthand property for setting the four transition properties")));
  data.insert("transition-delay", QString("<u>transition-delay</u><br />%1").arg(tr("Specifies when the transition effect will start")));
  data.insert("transition-duration", QString("<u>transition-duration</u><br />%1").arg(tr("Specifies how many seconds or milliseconds a transition effect takes to complete")));
  data.insert("transition-property", QString("<u>transition-property</u><br />%1").arg(tr("Specifies the name of the CSS property the transition effect is for")));
  data.insert("transition-timing-function", QString("<u>transition-timing-function</u><br />%1").arg(tr("Specifies the speed curve of the transition effect")));
  data.insert("unicode-bidi", QString("<u>unicode-bidi</u><br />%1").arg(tr(" ")));
  data.insert("vertical-align", QString("<u>vertical-align</u><br />%1").arg(tr("Sets the vertical alignment of an element")));
  data.insert("visibility", QString("<u>visibility</u><br />%1").arg(tr("Specifies whether or not an element is visible")));
  data.insert("voice-balance", QString("<u>voice-balance</u><br />%1").arg(tr("Specifies the balance between left and right channels")));
  data.insert("voice-duration", QString("<u>voice-duration</u><br />%1").arg(tr("Specifies how long it should take to render the selected element's content")));
  data.insert("voice-pitch", QString("<u>voice-pitch</u><br />%1").arg(tr("Specifies the average pitch (a frequency) of the speaking voice")));
  data.insert("voice-pitch-range", QString("<u>voice-pitch-range</u><br />%1").arg(tr("Specifies variation in average pitch")));
  data.insert("voice-rate", QString("<u>voice-rate</u><br />%1").arg(tr("Controls the speaking rate")));
  data.insert("voice-stress", QString("<u>voice-stress</u><br />%1").arg(tr("Indicates the strength of emphasis to be applied")));
  data.insert("voice-volume", QString("<u>voice-volume</u><br />%1").arg(tr("Refers to the amplitude of the waveform output by the speech synthesises")));
  data.insert("white-space", QString("<u>white-space</u><br />%1").arg(tr("Specifies how white-space inside an element is handled")));
  data.insert("widows", QString("<u>widows</u><br />%1").arg(tr("Sets the minimum number of lines that must be left at the top of a page when a page break occurs inside an element")));
  data.insert("width", QString("<u>width</u><br />%1").arg(tr("Sets the width of an element")));
  data.insert("word-break", QString("<u>word-break</u><br />%1").arg(tr("Specifies line breaking rules for non-CJK scripts")));
  data.insert("word-spacing", QString("<u>word-spacing</u><br />%1").arg(tr("Increases or decreases the space between words in a text")));
  data.insert("word-wrap", QString("<u>word-wrap</u><br />%1").arg(tr("Allows long, unbreakable words to be broken and wrap to the next line")));
  data.insert("z-index", QString("<u>z-index</u><br />%1").arg(tr("Sets the stack order of a positioned element")));
  return data;
}

QStringList StaticFunctions::cssProperties()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(cssPropertiesComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}

QStringList StaticFunctions::cssKeywords()
{
  return QStringList() << "AliceBlue"
                       << "above"
                       << "absolute"
                       << "always"
                       << "AntiqueWhite"
                       << "Aqua"
                       << "Aquamarine"
                       << "armenian"
                       << "auto"
                       << "autoinherit"
                       << "avoid"
                       << "Azure"
                       << "baseline"
                       << "behind"
                       << "Beige"
                       << "below"
                       << "bidi-override"
                       << "Bisque"
                       << "Black"
                       << "BlanchedAlmond"
                       << "blink"
                       << "block"
                       << "Blue"
                       << "BlueViolet"
                       << "bold"
                       << "bolder"
                       << "both"
                       << "Brown"
                       << "BurlyWood"
                       << "CadetBlue"
                       << "capitalize"
                       << "caption"
                       << "center-left"
                       << "center-right"
                       << "center"
                       << "Chartreuse"
                       << "Chocolate"
                       << "circle"
                       << "close-quote"
                       << "code"
                       << "collapse"
                       << "continuous"
                       << "Coral"
                       << "CornflowerBlue"
                       << "Cornsilk"
                       << "Crimson"
                       << "crosshair"
                       << "cue-after"
                       << "cue-before"
                       << "Cyan"
                       << "DarkBlue"
                       << "DarkCyan"
                       << "DarkGoldenRod"
                       << "DarkGray"
                       << "DarkGreen"
                       << "DarkKhaki"
                       << "DarkMagenta"
                       << "DarkOliveGreen"
                       << "Darkorange"
                       << "DarkOrchid"
                       << "DarkRed"
                       << "DarkSalmon"
                       << "DarkSeaGreen"
                       << "DarkSlateBlue"
                       << "DarkSlateGray"
                       << "DarkTurquoise"
                       << "DarkViolet"
                       << "dashed"
                       << "decimal-leading-zero"
                       << "decimal"
                       << "DeepPink"
                       << "DeepSkyBlue"
                       << "default"
                       << "digits"
                       << "DimGray"
                       << "DimGrey"
                       << "disc"
                       << "DodgerBlue"
                       << "e-resize"
                       << "embed"
                       << "far-left"
                       << "far-right"
                       << "fast"
                       << "faster"
                       << "FireBrick"
                       << "fixed"
                       << "FloralWhite"
                       << "ForestGreen"
                       << "Fuchsia"
                       << "Gainsboro"
                       << "georgian"
                       << "GhostWhite"
                       << "Gold"
                       << "GoldenRod"
                       << "Gray"
                       << "Green"
                       << "GreenYellow"
                       << "help"
                       << "hidden"
                       << "hide"
                       << "high"
                       << "higher"
                       << "HoneyDew"
                       << "HotPink"
                       << "IndianRed"
                       << "Indigo"
                       << "inherit"
                       << "inline-block"
                       << "inline-table"
                       << "inline"
                       << "inside"
                       << "italic"
                       << "Ivory"
                       << "justify"
                       << "Khaki"
                       << "Lavender"
                       << "LavenderBlush"
                       << "LawnGreen"
                       << "left-side"
                       << "left"
                       << "leftright"
                       << "leftwards"
                       << "LemonChiffon"
                       << "level"
                       << "LightBlue"
                       << "LightCoral"
                       << "LightCyan"
                       << "lighter"
                       << "LightGoldenRodYellow"
                       << "LightGray"
                       << "LightGreen"
                       << "LightPink"
                       << "LightSalmon"
                       << "LightSeaGreen"
                       << "LightSkyBlue"
                       << "LightSlateGray"
                       << "LightSteelBlue"
                       << "LightYellow"
                       << "Lime"
                       << "LimeGreen"
                       << "line-through"
                       << "Linen"
                       << "list-item"
                       << "loud"
                       << "low"
                       << "lower-alpha"
                       << "lower-greek"
                       << "lower-latin"
                       << "lower-roman"
                       << "lower"
                       << "lowercase"
                       << "ltr"
                       << "Magenta"
                       << "Maroon"
                       << "medium"
                       << "MediumAquaMarine"
                       << "MediumBlue"
                       << "MediumOrchid"
                       << "MediumPurple"
                       << "MediumSeaGreen"
                       << "MediumSlateBlue"
                       << "MediumSpringGreen"
                       << "MediumTurquoise"
                       << "MediumVioletRed"
                       << "menu"
                       << "message-box"
                       << "middle"
                       << "MidnightBlue"
                       << "MintCream"
                       << "MistyRose"
                       << "mix"
                       << "Moccasin"
                       << "move"
                       << "n-resize"
                       << "NavajoWhite"
                       << "Navy"
                       << "ne-resize"
                       << "no-close-quote"
                       << "no-open-quote"
                       << "no-repeat"
                       << "none"
                       << "normal"
                       << "nowrap"
                       << "nw-resize"
                       << "oblique"
                       << "OldLace"
                       << "Olive"
                       << "OliveDrab"
                       << "once"
                       << "open-quote"
                       << "Orange"
                       << "OrangeRed"
                       << "Orchid"
                       << "outside"
                       << "overline"
                       << "PaleGoldenRod"
                       << "PaleGreen"
                       << "PaleTurquoise"
                       << "PaleVioletRed"
                       << "PapayaWhip"
                       << "PeachPuff"
                       << "Peru"
                       << "Pink"
                       << "Plum"
                       << "pointer"
                       << "PowderBlue"
                       << "pre-line"
                       << "pre-wrap"
                       << "pre"
                       << "progress"
                       << "Purple"
                       << "Red"
                       << "relative"
                       << "repeat-x"
                       << "repeat-y"
                       << "repeat"
                       << "right-side"
                       << "right"
                       << "rightwards"
                       << "RosyBrown"
                       << "RoyalBlue"
                       << "rtl"
                       << "s-resize"
                       << "SaddleBrown"
                       << "Salmon"
                       << "SandyBrown"
                       << "scroll"
                       << "se-resize"
                       << "SeaGreen"
                       << "SeaShell"
                       << "separate"
                       << "show"
                       << "Sienna"
                       << "silent"
                       << "Silver"
                       << "SkyBlue"
                       << "SlateBlue"
                       << "SlateGray"
                       << "slow"
                       << "slower"
                       << "small-caps"
                       << "small-caption"
                       << "Snow"
                       << "soft"
                       << "solid"
                       << "spell-out"
                       << "SpringGreen"
                       << "square"
                       << "static"
                       << "status-bar"
                       << "SteelBlue"
                       << "sub"
                       << "super"
                       << "sw-resize"
                       << "table-caption"
                       << "table-cell"
                       << "table-column-group"
                       << "table-column"
                       << "table-footer-group"
                       << "table-header-group"
                       << "table-row-group"
                       << "table-row"
                       << "table"
                       << "Tan"
                       << "Teal"
                       << "text-bottom"
                       << "text-top"
                       << "text"
                       << "Thistle"
                       << "Tomato"
                       << "top"
                       << "transparent"
                       << "Turquoise"
                       << "underline"
                       << "upper-alpha"
                       << "upper-latin"
                       << "upper-roman"
                       << "uppercase"
                       << "url"
                       << "Violet"
                       << "visible"
                       << "w-resize"
                       << "wait"
                       << "Wheat"
                       << "White"
                       << "WhiteSmoke"
                       << "x-fast"
                       << "x-high"
                       << "x-loud"
                       << "x-low"
                       << "x-slow"
                       << "x-soft"
                       << "Yellow"
                       << "YellowGreen";
}

QStringList StaticFunctions::htmlAttributes()
{
  return QStringList() << "abbr"
                       << "accept-charset"
                       << "accept"
                       << "accesskey"
                       << "action"
                       << "align"
                       << "alink"
                       << "alt"
                       << "archive"
                       << "axis"
                       << "background"
                       << "bgcolor"
                       << "border"
                       << "cellpadding"
                       << "cellspacing"
                       << "char"
                       << "charoff"
                       << "charset"
                       << "checked"
                       << "cite"
                       << "class"
                       << "classid"
                       << "clear"
                       << "code"
                       << "codebase"
                       << "codetype"
                       << "color"
                       << "cols"
                       << "colspan"
                       << "compact"
                       << "content"
                       << "coords"
                       << "data"
                       << "datetime"
                       << "declare"
                       << "defer"
                       << "dir"
                       << "disabled"
                       << "enctype"
                       << "face"
                       << "for"
                       << "frame"
                       << "frameborder"
                       << "headers"
                       << "height"
                       << "href"
                       << "hreflang"
                       << "hspace"
                       << "http-equiv"
                       << "id"
                       << "ismap"
                       << "label"
                       << "lang"
                       << "language"
                       << "link"
                       << "longdesc"
                       << "marginheight"
                       << "marginwidth"
                       << "maxlength"
                       << "media"
                       << "method"
                       << "multiple"
                       << "name"
                       << "nohref"
                       << "noresize"
                       << "noshade"
                       << "nowrap"
                       << "object"
                       << "onblur"
                       << "onchange"
                       << "onclick"
                       << "ondblclick"
                       << "onfocus"
                       << "onkeydown"
                       << "onkeypress"
                       << "onkeyup"
                       << "onload"
                       << "onmousedown"
                       << "onmousemove"
                       << "onmouseout"
                       << "onmouseover"
                       << "onmouseup"
                       << "onreset"
                       << "onselect"
                       << "onsubmit"
                       << "onunload"
                       << "profile"
                       << "prompt"
                       << "readonly"
                       << "rel"
                       << "rev"
                       << "rows"
                       << "rowspan"
                       << "rules"
                       << "scheme"
                       << "scope"
                       << "scrolling"
                       << "selected"
                       << "shape"
                       << "size"
                       << "span"
                       << "src"
                       << "standby"
                       << "start"
                       << "style"
                       << "summary"
                       << "tabindex"
                       << "target"
                       << "text"
                       << "title"
                       << "type"
                       << "usemap"
                       << "valign"
                       << "value"
                       << "valuetype"
                       << "version"
                       << "vlink"
                       << "xml"
                       << "xml:.*"
                       << "xmlns"
                       << "xmlns:.*"
                       << "vspace"
                       << "width";
}

QHash<QString, QString> StaticFunctions::htmlTagsComplete()
{
  QHash<QString, QString> data;
  data.insert("!DOCTYPE", QString("<u>!DOCTYPE</u> <br />%1").arg(tr("Defines the document type")));
  data.insert("a", QString("<u>a</u> <br />%1").arg(tr("Defines a hyperlink")));
  data.insert("abbr", QString("<u>abbr</u> <br />%1").arg(tr("Defines an abbreviation")));
  data.insert("acronym", QString("<u>acronym</u> <br />%1").arg(tr("Not supported in HTML5. Defines an acronym")));
  data.insert("address", QString("<u>address</u> <br />%1").arg(tr("Defines contact information for the author/owner of a document")));
  data.insert("applet", QString("<u>applet</u> <br />%1").arg(tr("Not supported in HTML5. Deprecated in HTML 4.01. Defines an embedded applet")));
  data.insert("area", QString("<u>area</u> <br />%1").arg(tr("Defines an area inside an image-map")));
  data.insert("article", QString("<u>article</u> <br />%1").arg(tr("Defines an article")));
  data.insert("aside", QString("<u>aside</u> <br />%1").arg(tr("Defines content aside from the page content")));
  data.insert("audio", QString("<u>audio</u> <br />%1").arg(tr("Defines sound content")));
  data.insert("b", QString("<u>b</u> <br />%1").arg(tr("Defines bold text")));
  data.insert("base", QString("<u>base</u> <br />%1").arg(tr("Specifies the base URL/target for all relative URLs in a document")));
  data.insert("basefont", QString("<u>basefont</u> <br />%1").arg(tr("Not supported in HTML5. Deprecated in HTML 4.01. Specifies a default color, size, and font for all text in a document")));
  data.insert("bdi", QString("<u>bdi</u> <br />%1").arg(tr("Isolates a part of text that might be formatted in a different direction from other text outside it")));
  data.insert("bdo", QString("<u>bdo</u> <br />%1").arg(tr("Overrides the current text direction")));
  data.insert("big", QString("<u>big</u> <br />%1").arg(tr("Not supported in HTML5. Defines big text")));
  data.insert("blockquote", QString("<u>blockquote</u> <br />%1").arg(tr("Defines a section that is quoted from another source")));
  data.insert("body", QString("<u>body</u> <br />%1").arg(tr("Defines the document's body")));
  data.insert("br", QString("<u>br</u> <br />%1").arg(tr("Defines a single line break")));
  data.insert("button", QString("<u>button</u> <br />%1").arg(tr("Defines a clickable button")));
  data.insert("canvas", QString("<u>canvas</u> <br />%1").arg(tr("Used to draw graphics, on the fly, via scripting (usually JavaScript)")));
  data.insert("caption", QString("<u>caption</u> <br />%1").arg(tr("Defines a table caption")));
  data.insert("center", QString("<u>center</u> <br />%1").arg(tr("Not supported in HTML5. Deprecated in HTML 4.01. Defines centered text")));
  data.insert("cite", QString("<u>cite</u> <br />%1").arg(tr("Defines the title of a work")));
  data.insert("code", QString("<u>code</u> <br />%1").arg(tr("Defines a piece of computer code")));
  data.insert("col", QString("<u>col</u> <br />%1").arg(tr("Specifies column properties for each column within a <colgroup> element ")));
  data.insert("colgroup", QString("<u>colgroup</u> <br />%1").arg(tr("Specifies a group of one or more columns in a table for formatting")));
  data.insert("command", QString("<u>command</u> <br />%1").arg(tr("Defines a command button that a user can invoke")));
  data.insert("datalist", QString("<u>datalist</u> <br />%1").arg(tr("Specifies a list of pre-defined options for input controls")));
  data.insert("dd", QString("<u>dd</u> <br />%1").arg(tr("Defines a description of an item in a definition list")));
  data.insert("del", QString("<u>del</u> <br />%1").arg(tr("Defines text that has been deleted from a document")));
  data.insert("details", QString("<u>details</u> <br />%1").arg(tr("Defines additional details that the user can view or hide")));
  data.insert("dfn", QString("<u>dfn</u> <br />%1").arg(tr("Defines a definition term")));
  data.insert("dialog", QString("<u>dialog</u> <br />%1").arg(tr("Defines a dialog box or window")));
  data.insert("dir", QString("<u>dir</u> <br />%1").arg(tr("Not supported in HTML5. Deprecated in HTML 4.01. Defines a directory list")));
  data.insert("div", QString("<u>div</u> <br />%1").arg(tr("Defines a section in a document")));
  data.insert("dl", QString("<u>dl</u> <br />%1").arg(tr("Defines a definition list")));
  data.insert("dt", QString("<u>dt</u> <br />%1").arg(tr("Defines a term (an item) in a definition list")));
  data.insert("em", QString("<u>em</u> <br />%1").arg(tr("Defines emphasized text ")));
  data.insert("embed", QString("<u>embed</u> <br />%1").arg(tr("Defines a container for an external (non-HTML) application")));
  data.insert("fieldset", QString("<u>fieldset</u> <br />%1").arg(tr("Groups related elements in a form")));
  data.insert("figcaption", QString("<u>figcaption</u> <br />%1").arg(tr("Defines a caption for a <figure> element")));
  data.insert("figure", QString("<u>figure</u> <br />%1").arg(tr("Specifies self-contained content")));
  data.insert("font", QString("<u>font</u> <br />%1").arg(tr("Not supported in HTML5. Deprecated in HTML 4.01. Defines font, color, and size for text")));
  data.insert("footer", QString("<u>footer</u> <br />%1").arg(tr("Defines a footer for a document or section")));
  data.insert("form", QString("<u>form</u> <br />%1").arg(tr("Defines an HTML form for user input")));
  data.insert("frame", QString("<u>frame</u> <br />%1").arg(tr("Not supported in HTML5. Defines a window (a frame) in a frameset")));
  data.insert("frameset", QString("<u>frameset</u> <br />%1").arg(tr("Not supported in HTML5. Defines a set of frames")));
  data.insert("h1", QString("<u>h1</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("h2", QString("<u>h2</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("h3", QString("<u>h3</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("h4", QString("<u>h4</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("h5", QString("<u>h5</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("h6", QString("<u>h6</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("h7", QString("<u>h7</u> <br />%1").arg(tr("Defines HTML headings")));
  data.insert("head", QString("<u>head</u> <br />%1").arg(tr("Defines information about the document")));
  data.insert("header", QString("<u>header</u> <br />%1").arg(tr("Defines a header for a document or section")));
  data.insert("hgroup", QString("<u>hgroup</u> <br />%1").arg(tr("Groups heading (<h1> to <h6>) elements")));
  data.insert("hr", QString("<u>hr</u> <br />%1").arg(tr("Defines a thematic change in the content")));
  data.insert("html", QString("<u>html</u> <br />%1").arg(tr("Defines the root of an HTML document")));
  data.insert("i", QString("<u>i</u> <br />%1").arg(tr("Defines a part of text in an alternate voice or mood")));
  data.insert("iframe", QString("<u>iframe</u> <br />%1").arg(tr("Defines an inline frame")));
  data.insert("img", QString("<u>img</u> <br />%1").arg(tr("Defines an image")));
  data.insert("input", QString("<u>input</u> <br />%1").arg(tr("Defines an input control")));
  data.insert("ins", QString("<u>ins</u> <br />%1").arg(tr("Defines a text that has been inserted into a document")));
  data.insert("kbd", QString("<u>kbd</u> <br />%1").arg(tr("Defines keyboard input")));
  data.insert("keygen", QString("<u>keygen</u> <br />%1").arg(tr("Defines a key-pair generator field (for forms)")));
  data.insert("label", QString("<u>label</u> <br />%1").arg(tr("Defines a label for an <input> element")));
  data.insert("legend", QString("<u>legend</u> <br />%1").arg(tr("Defines a caption for a <fieldset>, < figure>, or <details> element")));
  data.insert("li", QString("<u>li</u> <br />%1").arg(tr("Defines a list item")));
  data.insert("link", QString("<u>link</u> <br />%1").arg(tr("Defines the relationship between a document and an external resource (most used to link to style sheets)")));
  data.insert("map", QString("<u>map</u> <br />%1").arg(tr("Defines a client-side image-map")));
  data.insert("mark", QString("<u>mark</u> <br />%1").arg(tr("Defines marked/highlighted text")));
  data.insert("menu", QString("<u>menu</u> <br />%1").arg(tr("Defines a list/menu of commands")));
  data.insert("meta", QString("<u>meta</u> <br />%1").arg(tr("Defines metadata about an HTML document")));
  data.insert("meter", QString("<u>meter</u> <br />%1").arg(tr("Defines a scalar measurement within a known range (a gauge)")));
  data.insert("nav", QString("<u>nav</u> <br />%1").arg(tr("Defines navigation links")));
  data.insert("noframes", QString("<u>noframes</u> <br />%1").arg(tr("Not supported in HTML5. Defines an alternate content for users that do not support frames")));
  data.insert("noscript", QString("<u>noscript</u> <br />%1").arg(tr("Defines an alternate content for users that do not support client-side scripts")));
  data.insert("object", QString("<u>object</u> <br />%1").arg(tr("Defines an embedded object")));
  data.insert("ol", QString("<u>ol</u> <br />%1").arg(tr("Defines an ordered list")));
  data.insert("optgroup", QString("<u>optgroup</u> <br />%1").arg(tr("Defines a group of related options in a drop-down list")));
  data.insert("option", QString("<u>option</u> <br />%1").arg(tr("Defines an option in a drop-down list")));
  data.insert("output", QString("<u>output</u> <br />%1").arg(tr("Defines the result of a calculation")));
  data.insert("p", QString("<u>p</u> <br />%1").arg(tr("Defines a paragraph")));
  data.insert("param", QString("<u>param</u> <br />%1").arg(tr("Defines a parameter for an object")));
  data.insert("pre", QString("<u>pre</u> <br />%1").arg(tr("Defines preformatted text")));
  data.insert("progress", QString("<u>progress</u> <br />%1").arg(tr("Represents the progress of a task")));
  data.insert("q", QString("<u>q</u> <br />%1").arg(tr("Defines a short quotation")));
  data.insert("rp", QString("<u>rp</u> <br />%1").arg(tr("Defines what to show in browsers that do not support ruby annotations")));
  data.insert("rt", QString("<u>rt</u> <br />%1").arg(tr("Defines an explanation/pronunciation of characters (for East Asian typography)")));
  data.insert("ruby", QString("<u>ruby</u> <br />%1").arg(tr("Defines a ruby annotation (for East Asian typography)")));
  data.insert("s", QString("<u>s</u> <br />%1").arg(tr("Defines text that is no longer correct")));
  data.insert("samp", QString("<u>samp</u> <br />%1").arg(tr("Defines sample output from a computer program")));
  data.insert("script", QString("<u>script</u> <br />%1").arg(tr("Defines a client-side script")));
  data.insert("section", QString("<u>section</u> <br />%1").arg(tr("Defines a section in a document")));
  data.insert("select", QString("<u>select</u> <br />%1").arg(tr("Defines a drop-down list")));
  data.insert("small", QString("<u>small</u> <br />%1").arg(tr("Defines smaller text")));
  data.insert("source", QString("<u>source</u> <br />%1").arg(tr("Defines multiple media resources for media elements (<video> and <audio>)")));
  data.insert("span", QString("<u>span</u> <br />%1").arg(tr("Defines a section in a document")));
  data.insert("strike", QString("<u>strike</u> <br />%1").arg(tr("Not supported in HTML5. Deprecated in HTML 4.01. Defines strikethrough text")));
  data.insert("strong", QString("<u>strong</u> <br />%1").arg(tr("Defines important text")));
  data.insert("style", QString("<u>style</u> <br />%1").arg(tr("Defines style information for a document")));
  data.insert("sub", QString("<u>sub</u> <br />%1").arg(tr("Defines subscripted text")));
  data.insert("summary", QString("<u>summary</u> <br />%1").arg(tr("Defines a visible heading for a <details> element")));
  data.insert("sup", QString("<u>sup</u> <br />%1").arg(tr("Defines superscripted text")));
  data.insert("table", QString("<u>table</u> <br />%1").arg(tr("Defines a table")));
  data.insert("tbody", QString("<u>tbody</u> <br />%1").arg(tr("Groups the body content in a table")));
  data.insert("td", QString("<u>td</u> <br />%1").arg(tr("Defines a cell in a table")));
  data.insert("textarea", QString("<u>textarea</u> <br />%1").arg(tr("Defines a multiline input control (text area)")));
  data.insert("tfoot", QString("<u>tfoot</u> <br />%1").arg(tr("Groups the footer content in a table")));
  data.insert("th", QString("<u>th</u> <br />%1").arg(tr("Defines a header cell in a table")));
  data.insert("thead", QString("<u>thead</u> <br />%1").arg(tr("Groups the header content in a table")));
  data.insert("time", QString("<u>time</u> <br />%1").arg(tr("Defines a date/time")));
  data.insert("title", QString("<u>title</u> <br />%1").arg(tr("Defines a title for the document")));
  data.insert("tr", QString("<u>tr</u> <br />%1").arg(tr("Defines a row in a table")));
  data.insert("track", QString("<u>track</u> <br />%1").arg(tr("Defines text tracks for media elements (<video> and <audio>)")));
  data.insert("tt", QString("<u>tt</u> <br />%1").arg(tr("Not supported in HTML5. Defines teletype text")));
  data.insert("u", QString("<u>u</u> <br />%1").arg(tr("Defines text that should be stylistically different from normal text")));
  data.insert("ul", QString("<u>ul</u> <br />%1").arg(tr("Defines an unordered list")));
  data.insert("var", QString("<u>var</u> <br />%1").arg(tr("Defines a variable")));
  data.insert("video", QString("<u>video</u> <br />%1").arg(tr("Defines a video or movie")));
  data.insert("wbr", QString("<u>wbr</u> <br />%1").arg(tr("Defines a possible line-break")));
  return data;
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
  //7 - Password
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
  case EditorTypes::PHP:
    return phpKeywords();
    break;
  case EditorTypes::CSS:
    return cssKeywords();
    break;
  case EditorTypes::HTML:
    break;
  case EditorTypes::JavaScript:
    return javascriptKeywords();
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
    return "SELECT '" + tr("Uptime in days") + "' AS `" + tr("Variable") + "`,  LPAD(FORMAT(`VARIABLE_VALUE` / 60 /60 / 24, 2), 12, ' ') AS `" + tr("Value") + "`, '" + tr("The number of days that the server has been up.") + "' AS `" + tr("Description")+ "` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME'"
        " UNION"
        " SELECT '" + tr("Aborted clients") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of connections that were aborted because the client died without closing the connection properly.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CLIENTS'"
        " UNION"
        " SELECT '" + tr("Aborted clients per day") + "', LPAD(FORMAT("
        "  (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CLIENTS')"
        "   / (SELECT `VARIABLE_VALUE` / 60 /60 / 24 AS `Value` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME'), 2), 12, ' ')"
        " , '" + tr("Rate of aborted clients per day.") + "'"
        " UNION"
        " SELECT '" + tr("Aborted connections") + "', LPAD(`VARIABLE_VALUE`, 12, ' '), '" + tr("The number of failed attempts to connect to the database server.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'ABORTED_CONNECTS'"
        " UNION"
        " SELECT '" + tr("Executed rollbacks") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of times each rollback statement has been executed.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_ROLLBACK'"
        " UNION"
        " SELECT '" + tr("Executed queries") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of statements executed by the server.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'QUERIES'"
        " UNION"
        " SELECT '" + tr("Rollbacks per second") + "', LPAD(FORMAT("
        "   ((SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'COM_ROLLBACK')"
        "   / (SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'UPTIME')), 2), 12, ' ')"
        " , '" + tr("Rate of rollbacks per second.") + "'"
        " UNION"
        " SELECT '" + tr("Temporary disk tables created") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of internal on-disk temporary tables created by the server while executing statements.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'CREATED_TMP_DISK_TABLES'"
        " UNION"
        " SELECT '" + tr("Free cache memory") + "', LPAD(FORMAT(`VARIABLE_VALUE` / 1024, 0), 12, ' '), '" + tr("The amount of free memory for the query cache.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'QCACHE_FREE_MEMORY'"
        " UNION"
        " SELECT '" + tr("Joins with full table scan") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of joins that perform table scans because they do not use indexes.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'SELECT_FULL_JOIN'"
        " UNION"
        " SELECT '" + tr("Log slow queries") + "', LPAD(`VARIABLE_VALUE`, 12, ' '), '" + tr("Is the slow queries logging enabled?") + "' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'LOG_SLOW_QUERIES'"
        " UNION"
        " SELECT '" + tr("Slow queries time in seconds") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of seconds that determinate a slow query.") + "' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'LONG_QUERY_TIME'"
        " UNION"
        " SELECT '" + tr("Count of slow queries") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The number of queries that have taken more than the allowed time.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'SLOW_QUERIES'"
        " UNION"
        " SELECT '" + tr("Idle connections") + "', LPAD(COUNT(*), 12, ' '), '" + tr("The number of connections that has been idle for more than 30 seconds.") + "' FROM `information_schema`.`PROCESSLIST` WHERE `TIME` >  30 AND `COMMAND` NOT IN ('Daemon', 'Binlog Dump')"
        " UNION"
        " SELECT '" + tr("Active connections") + "', LPAD(COUNT(*), 12, ' '), '" + tr("The number of connections that has been idle for less than 30 seconds.") + "' FROM `information_schema`.`PROCESSLIST` WHERE `TIME` <  30 AND `COMMAND` NOT IN ('Daemon', 'Binlog Dump')"
        " UNION"
        " SELECT '" + tr("Total connections") + "', LPAD(COUNT(*), 12, ' '), '" + tr("The number of active connections on the server.") + "' FROM `information_schema`.`PROCESSLIST` WHERE `COMMAND` NOT IN ('Daemon', 'Binlog Dump')"
        " UNION"
        " SELECT '" + tr("Max connections aviable") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The maximum permitted number of simultaneous client connections.") + "' FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'MAX_CONNECTIONS'"
        " UNION"
        " SELECT '" + tr("Used connections") + "', LPAD(FORMAT(`VARIABLE_VALUE`, 0), 12, ' '), '" + tr("The maximum number of connections that have been in use simultaneously since the server started.") + "' FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` = 'MAX_USED_CONNECTIONS'";
    break;
  case StaticFunctions::PostgreSQL:
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
  case StaticFunctions::PostgreSQL:
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QString();
}

QStringList StaticFunctions::htmlTags()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(htmlTagsComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}

QStringList StaticFunctions::javascriptKeywords()
{
  return QStringList() << "abstract"
                       << "alert"
                       << "Anchor"
                       << "Area"
                       << "arguments"
                       << "Array"
                       << "assign"
                       << "blur"
                       << "boolean"
                       << "break"
                       << "Button"
                       << "byte"
                       << "callee"
                       << "caller"
                       << "captureEvents"
                       << "case"
                       << "catch"
                       << "char"
                       << "Checkbox"
                       << "class"
                       << "clearInterval"
                       << "clearTimeout"
                       << "close"
                       << "closed"
                       << "comment"
                       << "confirm"
                       << "const"
                       << "constructor"
                       << "continue"
                       << "Date"
                       << "debugger"
                       << "default"
                       << "defaultStatus"
                       << "delete"
                       << "do"
                       << "document"
                       << "double"
                       << "Element"
                       << "else"
                       << "enum"
                       << "escape"
                       << "eval"
                       << "export"
                       << "extends"
                       << "false"
                       << "FileUpload"
                       << "final"
                       << "finally"
                       << "find"
                       << "float"
                       << "focus"
                       << "for"
                       << "Form"
                       << "Frame"
                       << "frames"
                       << "function"
                       << "getClass"
                       << "goto"
                       << "Hidden"
                       << "history"
                       << "History"
                       << "hom"
                       << "if"
                       << "Image"
                       << "implements"
                       << "import"
                       << "in"
                       << "Infinity"
                       << "innerHeight"
                       << "innerWidt"
                       << "instanceOf"
                       << "int"
                       << "interface"
                       << "isFinite"
                       << "isNan"
                       << "java"
                       << "JavaArray"
                       << "JavaClass"
                       << "JavaObject"
                       << "JavaPackage"
                       << "label"
                       << "length"
                       << "Link"
                       << "location"
                       << "locationbar"
                       << "long"
                       << "Math"
                       << "menubar"
                       << "MimeType"
                       << "moveBy"
                       << "moveTo"
                       << "name"
                       << "NaN"
                       << "native"
                       << "navigate"
                       << "navigator"
                       << "netscape"
                       << "new"
                       << "null"
                       << "Number"
                       << "Object"
                       << "onBlur"
                       << "onError"
                       << "onFocus"
                       << "onLoad"
                       << "onUnload"
                       << "open"
                       << "opener"
                       << "Option"
                       << "outerHeight"
                       << "outerWidth"
                       << "package"
                       << "Packages"
                       << "pageXoffset"
                       << "pageYoffset"
                       << "parseFloat"
                       << "parseInt"
                       << "Password"
                       << "personalbar"
                       << "Plugin"
                       << "print"
                       << "private"
                       << "prompt"
                       << "protected"
                       << "prototype"
                       << "public"
                       << "Radio"
                       << "ref"
                       << "RegExp"
                       << "releaseEvents"
                       << "Reset"
                       << "resizeBy"
                       << "resizeTo"
                       << "return"
                       << "routeEvent"
                       << "scroll"
                       << "scrollbars"
                       << "scrollBy"
                       << "scrollTo"
                       << "Select"
                       << "self"
                       << "setInterval"
                       << "setTimeout"
                       << "short"
                       << "static"
                       << "statusbar"
                       << "stop"
                       << "String"
                       << "Submit"
                       << "sun"
                       << "super"
                       << "switch"
                       << "synchronized"
                       << "taint"
                       << "Text"
                       << "Textarea"
                       << "this"
                       << "throw"
                       << "throws"
                       << "toolbar"
                       << "top"
                       << "transient"
                       << "true"
                       << "try"
                       << "typeof"
                       << "unescape"
                       << "untaint"
                       << "unwatch"
                       << "valueOf"
                       << "var"
                       << "void"
                       << "watch"
                       << "while"
                       << "window"
                       << "with";
}

QHash<QString, QString> StaticFunctions::javascriptFunctionsComplete()
{
  QHash<QString, QString> data;
  data.insert("abs", QString("<u>abs</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("acos", QString("<u>acos</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("anchor", QString("<u>anchor</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("asin", QString("<u>asin</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("atan", QString("<u>atan</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("atan2", QString("<u>atan2</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("big", QString("<u>big</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("blink", QString("<u>blink</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("bold", QString("<u>bold</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("ceil", QString("<u>ceil</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("charAt", QString("<u>charAt</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("charCodeAt", QString("<u>charCodeAt</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("concat", QString("<u>concat</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("constructor", QString("<u>constructor</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("cos", QString("<u>cos</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("Date", QString("<u>Date</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("every", QString("<u>every</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("exec", QString("<u>exec</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("exp", QString("<u>exp</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("filter", QString("<u>filter</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("fixed", QString("<u>fixed</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("floor", QString("<u>floor</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("fontcolor", QString("<u>fontcolor</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("fontsize", QString("<u>fontsize</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("forEach", QString("<u>forEach</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getDate", QString("<u>getDate</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getDay", QString("<u>getDay</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getFullYear", QString("<u>getFullYear</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getHours", QString("<u>getHours</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getMilliseconds", QString("<u>getMilliseconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getMinutes", QString("<u>getMinutes</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getMonth", QString("<u>getMonth</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getSeconds", QString("<u>getSeconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getTime", QString("<u>getTime</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getTimezoneOffset", QString("<u>getTimezoneOffset</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCDate", QString("<u>getUTCDate</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCDay", QString("<u>getUTCDay</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCFullYear", QString("<u>getUTCFullYear</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCHours", QString("<u>getUTCHours</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCMilliseconds", QString("<u>getUTCMilliseconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCMinutes", QString("<u>getUTCMinutes</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCMonth", QString("<u>getUTCMonth</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("getUTCSeconds", QString("<u>getUTCSeconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("indexOf", QString("<u>indexOf</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("italics", QString("<u>italics</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("join", QString("<u>join</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("lastIndexOf", QString("<u>lastIndexOf</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("length", QString("<u>length</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("link", QString("<u>link</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("localeCompare", QString("<u>localeCompare</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("log", QString("<u>log</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("map", QString("<u>map</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("match", QString("<u>match</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("max", QString("<u>max</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("min", QString("<u>min</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("pop", QString("<u>pop</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("pow", QString("<u>pow</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("push", QString("<u>push</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("random", QString("<u>random</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("reduce", QString("<u>reduce</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("reduceRight", QString("<u>reduceRight</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("replace", QString("<u>replace</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("reverse", QString("<u>reverse</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("round", QString("<u>round</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("search", QString("<u>search</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setDate", QString("<u>setDate</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setFullYear", QString("<u>setFullYear</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setHours", QString("<u>setHours</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setMilliseconds", QString("<u>setMilliseconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setMinutes", QString("<u>setMinutes</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setMonth", QString("<u>setMonth</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setSeconds", QString("<u>setSeconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setTime", QString("<u>setTime</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCDate", QString("<u>setUTCDate</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCFullYear", QString("<u>setUTCFullYear</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCHours", QString("<u>setUTCHours</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCMilliseconds", QString("<u>setUTCMilliseconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCMinutes", QString("<u>setUTCMinutes</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCMonth", QString("<u>setUTCMonth</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("setUTCSeconds", QString("<u>setUTCSeconds</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("shift", QString("<u>shift</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("sin", QString("<u>sin</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("slice", QString("<u>slice</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("small", QString("<u>small</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("some", QString("<u>some</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("sort", QString("<u>sort</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("splice", QString("<u>splice</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("split", QString("<u>split</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("sqrt", QString("<u>sqrt</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("strike", QString("<u>strike</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("sub", QString("<u>sub</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("substr", QString("<u>substr</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("substring", QString("<u>substring</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("sup", QString("<u>sup</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("tan", QString("<u>tan</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("test", QString("<u>test</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toDateString", QString("<u>toDateString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toExponential", QString("<u>toExponential</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toFixed", QString("<u>toFixed</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLocaleDateString", QString("<u>toLocaleDateString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLocaleFormat", QString("<u>toLocaleFormat</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLocaleLowerCase", QString("<u>toLocaleLowerCase</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLocaleString", QString("<u>toLocaleString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLocaleTimeString", QString("<u>toLocaleTimeString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLocaleUpperCase", QString("<u>toLocaleUpperCase</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toLowerCase", QString("<u>toLowerCase</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toPrecision", QString("<u>toPrecision</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toSource", QString("<u>toSource</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toString", QString("<u>toString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toTimeString", QString("<u>toTimeString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toUpperCase", QString("<u>toUpperCase</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("toUTCString", QString("<u>toUTCString</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("unshift", QString("<u>unshift</u>(<b></b>) <br />%1").arg(tr("")));
  data.insert("valueOf", QString("<u>valueOf</u>(<b></b>) <br />%1").arg(tr("")));
  return data;
}

QStringList StaticFunctions::javascriptFunctions()
{
  QStringList list = QStringList();
  QHashIterator<QString, QString> hashIterator(javascriptFunctionsComplete());
  while (hashIterator.hasNext()) {
    hashIterator.next();
    list.append(hashIterator.key());
  }
  return list;
}
