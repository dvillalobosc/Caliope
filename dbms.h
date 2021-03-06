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

#ifndef DBMS_H
#define DBMS_H

#include <QList>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QtSql/QSqlDatabase>
#include <QDateTime>

#if defined(Q_OS_WIN)
  #include "mysql.h"
#elif defined(Q_OS_LINUX)
  #include "mysql/mysql.h"
#elif defined(Q_OS_MAC)
  #include "mysql.h"
#endif

#include "stdio.h"
#include "staticfunctions.h"

class QStringList;
class QVariant;
class QString;
class DBMS;
class QErrorMessage;
class QSqlTableModel;
class QSqlQueryModel;

class Databases : public QObject
{
  Q_OBJECT

public:
  Databases(DBMS *serverConnection);
  QStringList list();
  QString getDefinition(QString formalDatabaseName);

private:
  DBMS *serverConnection;
};

class Procedures : public QObject
{
  Q_OBJECT

public:
  Procedures(DBMS *serverConnection);
  QStringList list(QString databaseName = QString());
  QString getDefinition(QString formalProcedureName);

private:
  DBMS *serverConnection;
};

class Fucntions : public QObject
{
  Q_OBJECT

public:
  Fucntions(DBMS *serverConnection);
  QStringList list(QString databaseName = QString());
  QString getDefinition(QString formalFunctionName);

private:
  DBMS *serverConnection;
};

class Events : public QObject
{
  Q_OBJECT

public:
  Events(DBMS *serverConnection);
  QStringList list(QString databaseName = QString());
  QString getDefinition(QString formalEventName);

private:
  DBMS *serverConnection;
};

class Views : public QObject
{
  Q_OBJECT

public:
  Views(DBMS *serverConnection);
  QStringList list(QString databaseName = QString());
  QString getDefinition(QString formalViewName);

private:
  DBMS *serverConnection;
};

class Tables : public QObject
{
  Q_OBJECT

public:
  Tables(DBMS *serverConnection);
  QStringList list(QString databaseName = QString());
  QString getDefinition(QString formalTableName);
  QStringList getTableDataToInsert(QString formalTableName);

private:
  DBMS *serverConnection;
};

class Triggers : public QObject
{
  Q_OBJECT

public:
  Triggers(DBMS *serverConnection);
  QStringList list(QString databaseName = QString());
  QString getDefinition(QString formalTriggerName);

private:
  DBMS *serverConnection;
};

class Transaction : public QObject
{
  Q_OBJECT

public:
  Transaction(DBMS *serverConnection);

private:
  DBMS *serverConnection;

public slots:
  void beginTransacction();
  void commitTransacction();
  void rollbackTransacction();

};

class Replication : public QObject
{
  Q_OBJECT

public:
  Replication(DBMS *serverConnection);

public slots:
  QString getStatus();
  void changeDefaultMasterConnection(QString masterConnectionName);
  void skipErrors(unsigned int count);
  void stopSlave();
  void startSlave();
  void rebootSlave();
  void resetSlave();
  void purgeBinaryLogs();
  void flushRelayLogs();
  void stopAllSlaves();
  void startAllSlaves();
  QString getStatus(QString connectionName);
  QStringList getSlavesNames();
  void stopSlave(QString connectionName);
  void startSlave(QString connectionName);
  void rebootSlave(QString connectionName);
  void resetSlave(QString connectionName);

private:
  DBMS *serverConnection;
};

class Processes : public QObject
{
  Q_OBJECT

public:
  Processes(DBMS *serverConnection);
  QList<QStringList>* getProcessList(bool useTable = false);
  QStringList getHeaderList(bool useTable = false);
  void killThread(long long int thread);
  void killQuery(long long int thread);

public slots:
  void killIdleThreads(unsigned int limit);

private:
  DBMS *serverConnection;
  QList<QStringList> *result;
};

class ItemTypes
{
public:
  enum ItemType {Database = 1001, Table, User, UserHost, CatalogsTab, UsersTab, Trigger, View, Procedure, Function, Event};
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
  unsigned long getChecksum();
  unsigned long getRowCount();
  unsigned long getDataLength();

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
  Q_OBJECT

public:
  Database(DBMS *serverConnection, QString databaseName);
  bool drop();
  bool create(QString collation = QString());
  QStringList getTables();
  QStringList getViews();
  unsigned long tableCount();
  QStringList info();
  QStringList getLocalTables();

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
  Q_PROPERTY(QString collation READ getConnectionCollation WRITE setCollation)
  Q_PROPERTY(StaticFunctions::dbmsTypes DBMSType READ getDBMSType WRITE setDBMSType)

public:
  DBMS(bool enableQueryLog = true);
  ~DBMS();
  bool operator==(DBMS *serverConnection);
  bool operator!=(DBMS *serverConnection);

  QString getGlobalStatusTable();
  QString getGlobalVariablesTable();
  QString getUserName();
  void setUserName(QString name);

  void setCollation(QString collation);
  QString getConnectionCollation();
  QString getServerCollation();
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
//  QString getVersionComment();
  QString getGlobalStatus(QString filter = QString());
  QString getGlobalVariables(QString filter = QString());
  QString getSessionStatus(QString filter = QString());
  QString getSessionlVariables(QString filter = QString());
  QString getVersion();
  int unsigned getMayorVersion();
  int unsigned getMinorVersion();
  int unsigned getMicroVersion();
//  int getRelease();
  void close();
  bool open();
  bool isOpened();
  QList<QStringList>* runQuery(QString queryToExecute, bool addHeaders = false, bool emitNotificaction = true);
  QList<QStringList>* runQuerySimpleResult(QString queryToExecute);
  QStringList runQuerySingleColumn(QString queryToExecute, bool addHeaders = false);
  QStringList getDatabases(bool skipMetaDatabases = false);
  QStringList getUserHosts(QString user);
  QStringList getUsers();
  QString lastError();
  bool changeDatabase(QString database);
  QString getTriggeredefinition(QString triggers, QString database = QString());
  QString getEventDefinition(QString event, QString database = QString());
  QStringList getEngines();
  QStringList getCollations();
  QList<QStringList>* getCharacterSets();
  QString outputAsTable(QString queryToExecute, bool printExtraInfo = false, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true, bool emitNotificacion = true, QString delimiter = ";", bool alternateOutput = false);
  QString outputAsV(QString queryToExecute, bool printRowsInSet = false, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true, bool removeHeaders = false, QString delimiter = ";");
  QString outputAsVV(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true, QString delimiter = ";");
  QString outputAsHTML(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true, QString delimiter = ";");
  QString outputAsXML(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true, QString delimiter = ";");
  QString outputAsG(QString queryToExecute, bool saveToFile = false, bool replaceReturns = true, bool splitQuery = true, bool emitNotificacion = true, QString delimiter = ";");
  bool testOpened();
  QStringList *executedQueries;
  bool oldVersion;
  QString getCharacterSet();
  void setCharacterSet(QString charset = "utf8");
  bool shutdown();
  QString getStatus();
  bool executeQuery(QString queryToExecute);
  void flushPrivileges();
  QString getTitle();
  QString getStringType();
  inline QString replaceReturnsAndTabs(QString string);
  QString getConnectionString();
  QString getfailedQueries();
  QSqlDatabase dbSQLite;
  void logApplicationStarted();
  void logStatement(QString statement, QString result = QString());
  QSqlTableModel *sqliteTableModel();
  QSqlQueryModel *sqliteFilterQueryModel();
  void clearSQLiteQueryLog();
  void setCharsetAndCollation(QString charset, QString collation);
  QList<QStringList> *getCollationsApplicability();
  void setKeyFile(QString keyFile);
  void setCertFile(QString certFile);
  void setUseSSL(bool useSSL);
  int ping();
  StaticFunctions::dbmsTypes getDBMSType();
  void setDBMSType(StaticFunctions::dbmsTypes type);
  StaticFunctions::dbmsTypes p_DBMSType;
  QStringList getCharsets();

  Table *table(QString tableName, QString database = QString());
  View *view(QString viewName, QString database = QString());
  Routine *routine(QString routineName, QString database = QString());
  Database *database(QString databaseName = QString());
  Event *event(QString eventName, QString database = QString());
  Processes *processes();
  Replication *replication();
  void saveOutputToFile(QString contents, QString filter, QString fileName = QString());
  Transaction *transaction();
  QString lastErrorNumber();
  Triggers *triggers();
  Tables *tables();
  Views *views();
  Events *events();
  Fucntions *functions();
  Procedures *procedures();
  Databases *databases();

signals:
  void errorOccurred();
  void databaseChanged();
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 0);
  void errorMessageAccepted();
  void reconnectionPerformed();

private slots:
  void errorMessageAcceptedSlot();
  void checkIfReconnected();

private:
  MYSQL *mariadbConnection;
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
//  QString outputAsTable(MYSQL_RES *result, QString query, bool replaceReturns);
//  QString outputAsTable(PGresult *result, QString query, bool replaceReturns);
  QString errorOnExecution(const QString message, const QString type);
  QString processOutput;
//  QProcess *proc;
  QSettings settings;
  QList<QStringList>* failedQueries;
  QErrorMessage *errorMessage;
  void logExecutedQueries(QString query, QString result = QString());
  static void printQueryProgress(const MYSQL *mysql, uint stage, uint max_stage, double progress, const char *proc_info, uint proc_info_length);
  QTime queryExecutionTime;
  QString millisecondsToTime(unsigned int milliseconds);
  QString p_collation;
  QString p_charset;
  bool p_useSSL;
  QString p_clientKey;
  QString p_clientCert;
  QTimer *timerCheckIfReconnected;
  ulong p_connectionId;
  static inline QByteArray fromUnicode(QTextCodec *tc, const QString &str);

};

#endif // DBMS_H
