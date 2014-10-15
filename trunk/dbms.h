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

#ifndef DBMS_H
#define DBMS_H

#include <QList>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QtSql/QSqlDatabase>
#include <QDateTime>

#define USEDBMS 1
#define USEMARIADB 1
#define USEPOSTGRES 0

#if USEDBMS == 1
  #if defined(Q_OS_WIN)
    #if USEMARIADB == 1
      #include "mysql.h"
    #endif
    #if USEPOSTGRES == 1
      #include "libpq-fe.h"
    #endif
  #elif defined(Q_OS_LINUX)
    #if USEMARIADB == 1
      #include "mysql/mysql.h"
    #endif
    #if USEPOSTGRES == 1
      #include "libpq-fe.h"
    #endif
  #elif defined(Q_OS_MAC)
    #if USEMARIADB == 1
      #include "mysql.h"
    #endif
  #endif
#endif

#include "stdio.h"

class QStringList;
class QVariant;
class QString;
class DBMS;
class QErrorMessage;
class QSqlTableModel;
class QSqlQueryModel;

class ItemTypes
{
public:
  enum ItemType {Database = 1001, Table, User, UserHost, CatalogsTab, UsersTab};
};

class Table
{
public:
  Table(DBMS *serverConnection, QString tableName, QString database = QString());
  bool renameTable(QString newName);
  bool changeEngine(QString newEngine);
  bool changeComment(QString newComment);
  bool changeCollation(QString newCollation);
  bool drop();
  QString formalName();
  QString getDefinition();
  QStringList getFields();
  bool dropIndex(QString indexName);
  QList<QStringList>* getIndexes();

private:
  DBMS *serverConnection;
  QString tableName;
  QString database;
};

class View
{
public:
  View(DBMS *serverConnection, QString viewName, QString database = QString());
  bool drop();
  QString formalName();
  QString getDefinition();

private:
  DBMS *serverConnection;
  QString viewName;
  QString database;
};

class Routine
{
public:
  Routine(DBMS *serverConnection, QString routineName, QString database = QString());
  bool drop();
  QString formalName();
  QString routineType();
  QString getDefinition();

private:
  DBMS *serverConnection;
  QString routineName;
  QString database;
};

class Database : public QObject
{
public:
  Database(DBMS *serverConnection, QString databaseName);
  bool drop();
  bool create(QString collation = QString());
  QStringList getTables();
  unsigned long tableCount();
  QStringList info();

private:
  DBMS *serverConnection;
  QString databaseName;
  QString formalName();
};

class Event
{
public:
  Event(DBMS *serverConnection, QString eventName, QString database = QString());
  bool drop();
  QString formalName();
  QString getDefinition();

private:
  DBMS *serverConnection;
  QString eventName;
  QString database;
};

class DBMS : public QObject
{
  Q_OBJECT

  Q_PROPERTY(QString userName READ getUserName WRITE setUserName)
  Q_PROPERTY(QString characterSet READ getCharacterSet WRITE setCharacterSet)
  Q_PROPERTY(QString database READ getDatabase WRITE setDatabase)
  Q_PROPERTY(QString collation READ getCollation WRITE setCollation)

public:
  DBMS(bool enableQueryLog = true);
  ~DBMS();

  QString getUserName();
  void setUserName(QString name);

  void setCollation(QString collation);
  QString getCollation();
  QString getFullUserName();
  QString getHostName();
  void setHostName(QString name);
  QString getPassword();
  void setPassword(QString pass);
  int getPort();
  int getConnectionId();
  void setPort(unsigned int number);
  QString getDatabase();
  void setDatabase(QString name);
  QString getSocket();
  QString getReplicationStatus();
  QString getVersion();
//  QString getVersionComment();
  QString getGlobalStatus(QString filter = QString());
  QString getGlobalVariables(QString filter = QString());
  QString getSessionStatus(QString filter = QString());
  QString getSessionlVariables(QString filter = QString());
  int getMayorVersion();
  int getMinorVersion();
//  int getRelease();
  void close();
  bool open();
  bool isOpened();
  QList<QStringList>* runQuery(QString queryToExecute, bool addHeaders = false);
  QList<QStringList>* runQuerySimpleResult(QString queryToExecute);
  QStringList runQuerySingleColumn(QString queryToExecute, bool addHeaders = false);
  QStringList getDatabases();
  QStringList getUserHosts(QString user);
  QStringList getUsers();
  QString lastError();
  bool changeDatabase(QString database);
  QString getTriggeredefinition(QString trigger, QString database = QString());
  QString getEventDefinition(QString event, QString database = QString());
  QStringList getEngines();
  QStringList getCollations();
  QList<QStringList>* getCharacterSets();
  QString outputAsTable(QString queryToExecute, bool printExtraInfo = false, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true);
  QString outputAsV(QString queryToExecute, bool printRowsInSet = false, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true);
  QString outputAsVV(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true);
  QString outputAsHTML(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true);
  QString outputAsXML(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true);
  QString outputAsG(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true);
  bool testOpened();
  QStringList *executedQueries;
  bool oldVersion;
  QString getCharacterSet();
  void setCharacterSet(QString charset = "utf8");
  bool shutdown();
  QString getStatus();
  bool executeQuery(QString queryToExecute);
  void stopReplicationSlave();
  void startReplicationSlave();
  void rebootReplicationSlave();
  void flushPrivileges();
  void purgeBinaryLogs();
  QString getTitle();
  QString getStringType();
  QString replaceReturnsAndTabs(QString string);
  void resetSlave();
  void flushRelayLogs();
  QString getConnectionString();
  QString getfailedQueries();
  QSqlDatabase dbSQLite;
  QDateTime dateTime;
  void logApplicationStarted();
  void logStatement(QString statement);
  QSqlTableModel *sqliteTableModel();
  QSqlQueryModel *sqliteFilterQueryModel();
  void clearSQLiteQueryLog();
  void setCollation(QString charset, QString collation);
  QList<QStringList> *getCollationsApplicability();

  Table *table(QString tableName, QString database = QString());
  View *view(QString viewName, QString database = QString());
  Routine *routine(QString routineName, QString database = QString());
  Database *database(QString databaseName = QString());
  Event *event(QString eventName, QString database = QString());

signals:
  void errorOccurred();
  void databaseChanged();
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 2000);
  void errorMessageAccepted();

private slots:
  void errorMessageAcceptedSlot();

private:
  MYSQL *mariadbConnection;
#if USEPOSTGRES == 1
  PGconn *postgresqlConnection;
  PGresult *postgresqlResults;
#endif
  MYSQL_RES *mariadbResults;
  MYSQL_FIELD *field;
  MYSQL_ROW record;
  QString p_userName;
  QString hostName;
  QString password;
  unsigned int port;
  QString p_database;
  bool opened;
  int query(QString queryToExecute);
  void saveOutputToFile(QString contents, QString filter, QString fileName = QString());
//  QString outputAsTable(MYSQL_RES *result, QString query, bool replaceReturns);
//  QString outputAsTable(PGresult *result, QString query, bool replaceReturns);
  QString errorOnExecution(const QString message);
  QString processOutput;
//  QProcess *proc;
  QSettings settings;
  QList<QStringList>* failedQueries;
  QErrorMessage *errorMessage;
  void logExecutedQueries(QString query);
  static void printQueryProgress(const MYSQL *mysql, uint stage, uint max_stage, double progress, const char *proc_info, uint proc_info_length);
  QTime queryExecutionTime;
  QString millisecondsToTime(unsigned int milliseconds);
  QString p_collation;
  QString p_charset;
};

#endif // DBMS_H
