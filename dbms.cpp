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

#include <QErrorMessage>
#include <QFileDialog>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQueryModel>
#include <QTimer>
#include <QTextCodec>

#include "dbms.h"
#include "mainwindow.h"
#include "staticfunctions.h"

#include "QDebug"

//switch(p_DBMSType) {
//case StaticFunctions::MySQL:
//case StaticFunctions::MariaDB:
//  break;
//case StaticFunctions::Undefined:
//default:
//  break;
//}

DBMS::DBMS(bool enableQueryLog)
{
  opened = false;
  executedQueries = new QStringList;
  failedQueries = new QList<QStringList>();
  failedQueries->append(QStringList() << tr("Count") << tr("Query") << tr("Error message"));
  oldVersion = false;
  errorMessage = new QErrorMessage;
  errorMessage->setWindowTitle(tr("Error"));
  connect(errorMessage, SIGNAL(accepted()), this, SLOT(errorMessageAcceptedSlot()));

  if (settings.value("General/EnableQueryLog", false).toBool() && enableQueryLog) {
    QFileInfo fileInfo(settings.fileName());
    dbSQLite = QSqlDatabase::addDatabase("QSQLITE");
    qApp->setProperty("LocalDatabase", fileInfo.path() + "/" + QCoreApplication::applicationName() + ".sqlite");
    dbSQLite.setDatabaseName(qApp->property("LocalDatabase").toString());
    if (!dbSQLite.open())
      QMessageBox::critical(0, tr("Cannot open database"), tr("Unable to establish a database connection."), QMessageBox::Cancel);
    if (dbSQLite.open()) {
      QSqlQuery querySQLite;
      if (!querySQLite.exec("CREATE TABLE IF NOT EXISTS executedqueries (LineNumber INTEGER, SessionId TEXT, Date TEXT, Connection TEXT, Query TEXT, PRIMARY KEY(LineNumber DESC))"))
        errorMessage->showMessage(querySQLite.lastError().text(), "LogExecutedQueries");
    }
  }
  queryExecutionTime.start();

  timerCheckIfReconnected = new QTimer(this);
  timerCheckIfReconnected->setInterval(600000);
  connect(timerCheckIfReconnected, SIGNAL(timeout()), this, SLOT(checkIfReconnected()));
  timerCheckIfReconnected->start();
}

bool DBMS::shutdown()
{
  switch(p_DBMSType) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    if (mysql_shutdown(mariadbConnection, SHUTDOWN_DEFAULT) == 0) {
      opened = false;
      return true;
    }
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return false;
}

bool DBMS::open()
{
  //last_progress_report_length = 0;
  my_bool reconnect = settings.value("DBMS/Reconnect", 1).toInt();
  int arg = 1;
  mysql_library_init(0, NULL, NULL);
  mariadbConnection = mysql_init(NULL);
  mysql_options(mariadbConnection, MYSQL_OPT_LOCAL_INFILE, 0);
  mysql_options(mariadbConnection, MYSQL_OPT_RECONNECT, &reconnect);
  mysql_options(mariadbConnection, MYSQL_OPT_CAN_HANDLE_EXPIRED_PASSWORDS, &arg);

  if (p_useSSL && !p_clientCert.isEmpty() && !p_clientKey.isEmpty())
    mysql_ssl_set(mariadbConnection, p_clientKey.toUtf8().data(), p_clientCert.toUtf8().data(), NULL, NULL, NULL);

  switch(p_DBMSType) {
  case StaticFunctions::MySQL:
    opened = mysql_real_connect(mariadbConnection, hostName.toUtf8().data(), p_userName.toUtf8().data()
                                , password.toUtf8().data(), p_database.toUtf8().data(), port, NULL, CLIENT_MULTI_STATEMENTS);
    break;
  case StaticFunctions::MariaDB:
    mysql_options(mariadbConnection, MYSQL_PROGRESS_CALLBACK, (void*) printQueryProgress);
    opened = mysql_real_connect(mariadbConnection, hostName.toUtf8().data(), p_userName.toUtf8().data()
                                , password.toUtf8().data(), p_database.toUtf8().data(), port, NULL, CLIENT_MULTI_STATEMENTS | CLIENT_PROGRESS);
    break;
  case StaticFunctions::Undefined:
  default:
    opened = false;
  }

  switch(p_DBMSType) {
  case StaticFunctions::MySQL:
    if (opened) {
      //setCharacterSet(settings.value("DBMS/CharacterSet", "utf8").toString());
      setCharacterSet(p_charset);
      setCollation(getCharacterSet(), getCollation());
      if (getMinorVersion() < 1 || getMayorVersion() < 5) {
        oldVersion = true;
        QMessageBox::warning(0, tr("MySQL Version"), tr("Your version of MySQL seems to be less than 5.1."));
      }
    }
    break;
  case StaticFunctions::MariaDB:
    if (opened) {
      setCharacterSet(getCharacterSet());
      setCollation(getCharacterSet(), getCollation());
    }
  case StaticFunctions::Undefined:
  default:
    break;
  }
  if (opened)
    p_connectionId = runQuerySingleColumn("SELECT CONNECTION_ID()").at(0).toULong();
  return opened;
}

void DBMS::printQueryProgress(const MYSQL *mysql, uint stage, uint max_stage, double progress, const char *proc_info, uint proc_info_length)
{
  Q_UNUSED(mysql);
  Q_UNUSED(proc_info_length);

  qDebug() << tr("Stage: %1 of %2 '%3'. %4% of stage done.\nTotal progess: %5.").arg(stage).arg(max_stage).arg(proc_info).arg(progress)
              .arg(((stage -1) / (double) max_stage * 100.00 + progress / max_stage) * 2);

//  uint length= printf("Stage: %d of %d '%.*s' %6.3g%% of stage done",
//                        stage, max_stage, proc_info_length, proc_info,
//                        progress);
//    if (length < last_progress_report_length)
//      printf("%*s", last_progress_report_length - length, "");
//    putc('\r', stdout);
//    fflush(stdout);
  //    last_progress_report_length= length;
}

QString DBMS::millisecondsToTime(unsigned int milliseconds)
{
  float seconds = (float) (milliseconds / 1000);
  if (seconds <= 60)
    return tr("%1 seconds").arg(seconds);
  if (seconds > 60 && seconds < 3600)
    return tr("%1 minutes").arg(seconds / 60);
  if (seconds >= 3600)
    return tr("%1 hours").arg(seconds / 3600);
  return "0 seconds";
}

QByteArray DBMS::fromUnicode(QTextCodec *tc, const QString &str)
{
#ifdef QT_NO_TEXTCODEC
    Q_UNUSED(tc);
    return str.toLatin1();
#else
    return tc->fromUnicode(str);
#endif
}

void DBMS::close()
{
  logExecutedQueries(getfailedQueries());
  logExecutedQueries(tr("Application closed"));

  if (isOpened()) {
    opened = false;
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      mysql_close(mariadbConnection);
      mysql_library_end();
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  }
}

DBMS::~DBMS()
{
  close();
}

bool DBMS::testOpened()
{
  if (!isOpened()) {
    emit statusBarMessage(tr("Connection is not opened."));
    errorMessage->showMessage(tr("Connection is not opened."), "Connection");
    return false;
  }
  return true;
}

bool DBMS::isOpened()
{
  return opened;
}

void DBMS::setDatabase(QString name)
{
  p_database = name;
}

void DBMS::setHostName(QString name)
{
  hostName = name;
}

void DBMS::setPassword(QString pass)
{
  password = pass;
}

void DBMS::setPort(unsigned int number)
{
  port = number;
}

void DBMS::setUserName(QString name)
{
  p_userName = name;
}

void DBMS::setCollation(QString collation)
{
  p_collation = collation;
}

QString DBMS::getCollation()
{
  return p_collation;
}

QStringList DBMS::getDatabases(bool skipMetaDatabases)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (skipMetaDatabases)
        return runQuerySingleColumn("SELECT `SCHEMA_NAME` FROM `information_schema`.`SCHEMATA` WHERE `SCHEMA_NAME` NOT IN ('information_schema', 'performance_schema')");
      else
        return runQuerySingleColumn("SELECT `SCHEMA_NAME` FROM `information_schema`.`SCHEMATA`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QStringList();
}

QStringList DBMS::getUsers()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT DISTINCT(`User`) FROM `mysql`.`user`");
      break;
    default:
      break;
    }
  return QStringList();
}

QStringList DBMS::getUserHosts(QString user)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn(QString("SELECT `Host` FROM `mysql`.`user` WHERE `User` = '%1'").arg(user));
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QStringList();
}

QStringList DBMS::runQuerySingleColumn(QString queryToExecute, bool addHeaders)
{
  QStringList rows;

  if (isOpened()) {
    query(queryToExecute);
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      mariadbResults = mysql_store_result(mariadbConnection);
      if (!mariadbResults)
        return QStringList();      
      if (mysql_field_count(mariadbConnection) == 0)
        errorOnExecution(lastError(), lastErrorNumber());
      if (addHeaders)
        while((field = mysql_fetch_field(mariadbResults)))
          rows.append(field->name);
      while((record = mysql_fetch_row(mariadbResults)))
        rows.append(record[0]);
      mysql_free_result(mariadbResults);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  }
  return rows;
}

QList<QStringList>* DBMS::runQuery(QString queryToExecute, bool addHeaders)
{
  queryExecutionTime.restart();
  QList<QStringList> *rows = new QList<QStringList>();
  QStringList row;
  int status = 0;

  //  qDebug() << queryToExecute;

  if (isOpened()) {
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (query(queryToExecute) == 0) {
        do {
          /* did current statement return data? */
          mariadbResults = mysql_store_result(mariadbConnection);
          if (mariadbResults) {
            /* yes; process rows and free the result set */
            if (addHeaders) {
              while((field = mysql_fetch_field(mariadbResults)))
                row.append(field->name);
              rows->append(row);
              row.clear();
            }
            while((record = mysql_fetch_row(mariadbResults))) {
              for (int counter = 0; counter < (int) mysql_num_fields(mariadbResults); counter++)
                row.append(QString::fromUtf8(record[counter]));
              rows->append(row);
              row.clear();
            }
            rows->append(QStringList() << tr("Rows in set: %1. Elapsed time: %2.").arg(mysql_affected_rows(mariadbConnection)).arg(millisecondsToTime(queryExecutionTime.elapsed())));
            mysql_free_result(mariadbResults);
          } else {/* no result set or error */
            if (mysql_field_count(mariadbConnection) == 0) {
              //rows->append(QStringList() <<tr("Rows in set: %1").arg(mysql_affected_rows(mariadbConnection)));
              rows->append(QStringList() << tr("Rows in set: %1. Elapsed time: %2.").arg(mysql_affected_rows(mariadbConnection)).arg(millisecondsToTime(queryExecutionTime.elapsed())));
            } else { /* some error occurred */
              rows->append(QStringList() << errorOnExecution(lastError(), lastErrorNumber()));
              break;
            }
          }
          /* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
          if ((status = mysql_next_result(mariadbConnection)) > 0) {
            rows->append(QStringList() << errorOnExecution(lastError(), lastErrorNumber()));
            //rows->append(QStringList() << tr("Rows in set: %1").arg(0)); //Implement this for PSQL
            rows->append(QStringList() << tr("Rows in set: %1. Elapsed time: %2 seconds.").arg(0).arg(0)); //Implement this for PSQL
          }
        } while (status == 0);
      } else {
        rows->append(QStringList() << errorOnExecution(lastError(), lastErrorNumber()));
        //rows->append(QStringList() << tr("Rows in set: %1").arg(0));
        rows->append(QStringList() << tr("Rows in set: %1. Elapsed time: %2 seconds.").arg(0).arg(0));
      }
      break;
    case StaticFunctions::Undefined:
    default:
      rows->append(QStringList() << tr("Undefined Database driver.") << "-");
      break;
    }
    //  for (int counter = 0; counter < rows->count(); counter++)
    //    qDebug() << "*" << rows->at(counter);
  }
  emit statusBarMessage(rows->last().at(0));
  return rows;
}

QList<QStringList>* DBMS::runQuerySimpleResult(QString queryToExecute)
{
  QList<QStringList> *rows = new QList<QStringList>();
  QStringList row;
  int status = 0;

  //  qDebug() << queryToExecute;

  if (isOpened()) {
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (query(queryToExecute) == 0) {
        do {
          /* did current statement return data? */
          mariadbResults = mysql_store_result(mariadbConnection);
          if (mariadbResults) {
            /* yes; process rows and free the result set */
            //          if (addHeaders) {
            //            while((field = mysql_fetch_field(mariadbResults)))
            //              row.append(field->name);
            //            rows->append(row);
            //            row.clear();
            //          }
            while((record = mysql_fetch_row(mariadbResults))) {
              for (int counter = 0; counter < (int) mysql_num_fields(mariadbResults); counter++)
                row.append(QString::fromUtf8(record[counter]));
              rows->append(row);
              row.clear();
            }
            //          rows->append(QStringList() << tr("Rows in set") << QString("%1").arg(mysql_affected_rows(mariadbConnection)));
            mysql_free_result(mariadbResults);
          } else {/* no result set or error */
            if (mysql_field_count(mariadbConnection) != 0) {
              //            rows->append(QStringList() << tr("Rows in set") << QString("%1").arg(mysql_affected_rows(mariadbConnection)));
              //          } else { /* some error occurred */
              rows->append(QStringList() << errorOnExecution(lastError(), lastErrorNumber()));
              break;
            }
          }
          /* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
          if ((status = mysql_next_result(mariadbConnection)) > 0) {
            rows->append(QStringList() << errorOnExecution(lastError(), lastErrorNumber()));
            //          rows->append(QStringList() << tr("Rows in set") << "0"); //Implement this for PSQL
          }
        } while (status == 0);
      } else {
        rows->append(QStringList() << errorOnExecution(lastError(), lastErrorNumber()));
        //      rows->append(QStringList() << tr("Rows in set") << "0");
      }
      break;
    case StaticFunctions::Undefined:
    default:
      rows->append(QStringList() << tr("Undefined Database driver.") << "-");
      break;
    }
    //  for (int counter = 0; counter < rows->count(); counter++)
    //    qDebug() << "*" << rows->at(counter);
  }
  return rows;
}

QString DBMS::lastError()
{
  QString errorText;
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      errorText = QString("%1 %2 %3").arg(tr("Error:")).arg(mysql_errno(mariadbConnection)).arg(mysql_error(mariadbConnection));
      qDebug() << errorText;
      return errorText;
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return tr("No error code provided.");
}

int DBMS::query(QString queryToExecute)
{
  //qDebug() << queryToExecute;
  int valueToReturn = 0;

  //QSqlQuery querySQLite;
  //dateTime = QDateTime::currentDateTime();
  //querySQLite.exec(QString("INSERT INTO executedqueries VALUES ('%1', '%2', '%3')").arg(dateTime.toString(Qt::ISODate)).arg(queryToExecute).arg(getConnectionString()));

  QTextCodec *tc;
#ifndef QT_NO_TEXTCODEC
    tc = QTextCodec::codecForLocale();
#else
    tc = 0;
#endif
  const QByteArray encQuery(fromUnicode(tc, queryToExecute));
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      valueToReturn = mysql_real_query(mariadbConnection, encQuery.data(), encQuery.length());
      //valueToReturn = mysql_real_query(mariadbConnection, queryToExecute.toUtf8().constData(), queryToExecute.length());
      if (valueToReturn != 0)
        failedQueries->insert(1, QStringList() << QString("%1").arg(failedQueries->count()) << queryToExecute << lastError());
      return valueToReturn;
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return valueToReturn;
}

QString DBMS::outputAsTable(QString queryToExecute, bool printExtraInfo, bool saveToFile, bool replaceReturns, bool splitQuery)
{
  int row = 0;
  int row2 = 0;
  QList<int> maxWidthList;
  QString output;
  QStringList queryList;
  if (splitQuery)
    queryList = queryToExecute.split(QRegExp(";\\s+"), QString::SkipEmptyParts);
  else
    queryList.append(queryToExecute);

  if (isOpened()) {
    foreach (QString statement, queryList) {
      QList<QStringList> *rows = runQuery(statement, true);
      //    for (int i = 0; i <= rows->count(); i++)
      //        qDebug() << rows->at(i);

      //Find the maximum values for the width of the columns
      for (row = 0; row < rows->at(0).count(); row++)
        maxWidthList.append(1);
      for (row = 0; row < (rows->count() - 1); row++)
        for (row2 = 0; row2 < rows->at(row).count(); row2++)
          if (QString(rows->at(row).at(row2)).length() > maxWidthList.at(row2))
            maxWidthList.replace(row2, QString(rows->at(row).at(row2)).length());

      if (printExtraInfo)
        output += "--------------\n" + statement + "\n--------------\n";

      //Prints the headres and theirs borders
      output += "+";
      for (row = 0; row < rows->at(0).count(); row++)
        output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";
      output += "\n|";
      for (row = 0; row < rows->at(0).count(); row++)
        output +=  " " + replaceReturnsAndTabs(rows->at(0).at(row)).leftJustified(maxWidthList.at(row), ' ') + " |";
      output += "\n+";
      for (row = 0; row < rows->at(0).count(); row++)
        output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";

      //Print the data
      if (replaceReturns) {
        for (row = 1; row < rows->count() - 1; row++) {
          output += "\n|";
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  " " + replaceReturnsAndTabs(rows->at(row).at(row2)).leftJustified(maxWidthList.at(row2), ' ') + " |";
        }
      } else {
        for (row = 1; row < rows->count() - 1; row++) {
          output += "\n|";
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  " " + QString::fromUtf8(rows->at(row).at(row2).toUtf8()).leftJustified(maxWidthList.at(row2), ' ') + " |";
        }
      }

      //Print the botton border
      output += "\n+";
      for (row = 0; row < rows->at(0).count(); row++)
        output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";

      output += "\n" +  rows->last().at(0) + "\n";
    }
  }

  if (saveToFile) {
    saveOutputToFile(output, "Text Files (*.txt)", settings.value("General/LastTextFile", "").toString());
    return "";
  }
  return output;
}

void DBMS::saveOutputToFile(QString contents, QString filter, QString fileName)
{
  fileName = QFileDialog::getSaveFileName(0, tr("Select a file"), fileName, filter);
  if (fileName.startsWith("HTML"))
    settings.value("General/LastHTMLFile", fileName);
  if (fileName.startsWith("XML"))
    settings.value("General/LastXMLFile", fileName);
  if (fileName.startsWith("Text"))
    settings.value("General/LastTextLFile", fileName);
  QFile file(fileName);
  if (!file.open(QFile::WriteOnly | QFile::Text))
    emit statusBarMessage(tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
  QTextStream out(&file);
  out << contents.toUtf8();
  file.close();
  emit statusBarMessage(tr("Data exported to %1").arg(fileName));
}

QString DBMS::outputAsHTML(QString queryToExecute, bool saveToFile, bool replaceReturns, bool splitQuery)
{
  QString output("<HTML>\n<BODY>\n");
  int row = 0;
  int row2 = 0;
  QStringList queryList;
  if (splitQuery)
    queryList = queryToExecute.split(QRegExp(";\\s+"), QString::SkipEmptyParts);
  else
    queryList.append(queryToExecute);

  if (isOpened()) {
    foreach (QString statement, queryList) {
      QList<QStringList> *rows = runQuery(statement, true);

      output += "  <TABLE border='1'>\n";
      //Prints the headres and theirs borders
      output += "    <TR>\n";
      for (row = 0; row < rows->at(0).count(); row++)
        output += "      <TH>" + replaceReturnsAndTabs(rows->at(0).at(row)) + "</TH>\n";
      output += "    </TR>\n";

      //Print the data
      if (replaceReturns) {
        for (row = 1; row < (rows->count() - 1); row++) {
          output += "    <TR>\n";
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  "      <TD>" + (QString(rows->at(row).at(row2)).length() == 0 ? "&nbsp;" : replaceReturnsAndTabs(rows->at(row).at(row2)))
                + "</TD>\n";
          output += "    </TR>\n";
        }
      } else {
        for (row = 1; row < (rows->count() - 1); row++) {
          output += "    <TR>\n";
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  "      <TD>" + (QString(rows->at(row).at(row2)).length() == 0 ? "&nbsp;" : rows->at(row).at(row2))
                + "</TD>\n";
          output += "    </TR>\n";
        }
      }
      output += "  </TABLE>\n  <P>" + rows->last().at(0) + "</P>\n";
    }
  }
  output += "</BODY>\n</HTML>\n";
  if (saveToFile) {
    saveOutputToFile(output, "HTML Files (*.html)", settings.value("General/LastHTMLFile", "").toString());
    return "";
  } else {
    return output;
  }
}

QString DBMS::outputAsXML(QString queryToExecute, bool saveToFile, bool replaceReturns, bool splitQuery)
{
  QString output;
  int row = 0;
  int row2 = 0;
  QStringList queryList;
  if (splitQuery)
    queryList = queryToExecute.split(QRegExp(";\\s+"), QString::SkipEmptyParts);
  else
    queryList.append(queryToExecute);

  if (isOpened()) {
    foreach (QString statement, queryList) {
      QList<QStringList> *rows = runQuery(statement, true);

      output += "<resultset statement=\"" + statement + "\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">";
      //Print the data
      if (replaceReturns) {
        for (row = 1; row < rows->count() - 1; row++) {
          output += "  <row>\n";
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  "    <field name=\"" + replaceReturnsAndTabs(rows->at(0).at(row2)) + "\">" + replaceReturnsAndTabs(rows->at(row).at(row2)) + "</field>\n";
          output += "  </row>\n";
        }
      } else {
        for (row = 1; row < rows->count() - 1; row++) {
          output += "  <row>\n";
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  "    <field name=\"" + replaceReturnsAndTabs(rows->at(0).at(row2)) + "\">" + rows->at(row).at(row2) + "</field>\n";
          output += "  </row>\n";
        }
      }
      output += "  <row>\n    <field name=\"" + rows->last().at(0) + "\">" + rows->last().at(1) + "</field>\n  </row>\n";
      output += "</resultset>\n";
    }
  }
  if (saveToFile) {
    saveOutputToFile(output, "XML Files (*.xml)", settings.value("General/LastXMLFile", "").toString());
    return "";
  } else {
    return output;
  }
}

QString DBMS::outputAsV(QString queryToExecute, bool printRowsInSet, bool saveToFile, bool replaceReturns, bool splitQuery, bool removeHeaders)
{
  int row = 0;
  int row2 = 0;
  QString output;
  QStringList queryList;
  if (splitQuery)
    queryList = queryToExecute.split(QRegExp(";\\s+"), QString::SkipEmptyParts);
  else
    queryList.append(queryToExecute);

  if (isOpened()) {
    foreach (QString statement, queryList) {
      QList<QStringList> *rows = runQuery(statement, true);

      if (printRowsInSet)
        output += "--------------\n" + statement + "\n--------------\n";

      if (removeHeaders)
        rows->removeAt(0);

      //Print the data
      if (replaceReturns) {
        for (row = 0; row < rows->count() - 1; row++) {
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  replaceReturnsAndTabs(rows->at(row).at(row2)) + "\t";
          output += "\n";
        }
      } else {
        for (row = 0; row < rows->count() - 1; row++) {
          for (row2 = 0; row2 < rows->at(row).count(); row2++)
            output +=  QString::fromUtf8(rows->at(row).at(row2).toUtf8()) + "\t";
          output += "\n";
        }
      }
      if (printRowsInSet)
        output += "\n" + rows->last().at(0) + "\n";
    }
  }

  if (saveToFile) {
    saveOutputToFile(output, "Text Files (*.txt)", settings.value("General/LastTextFile", "").toString());
    return "";
  } else {
    return output;
  }
}

QString DBMS::outputAsG(QString queryToExecute, bool saveToFile, bool replaceReturns, bool splitQuery)
{
  QString output;
  int maxLength = 0;
  int row = 0;
  int row2 = 0;
  QStringList queryList;
  if (splitQuery)
    queryList = queryToExecute.split(QRegExp(";\\s+"), QString::SkipEmptyParts);
  else
    queryList.append(queryToExecute);

  if (isOpened()) {
    foreach (QString statement, queryList) {
      QList<QStringList> *rows = runQuery(statement, true);

      for (row = 0; row < rows->at(0).count(); row++)
        if (maxLength < rows->at(0).at(row).length())
          maxLength = rows->at(0).at(row).length();

      //Print the data
      if (replaceReturns) {
        for (row = 1; row < rows->count() - 1; row++) {
          for (row2 = 0; row2 < rows->at(row).count(); row2++) {
            output += replaceReturnsAndTabs(rows->at(0).at(row2)).rightJustified(maxLength, ' ') +  ": ";
            output += replaceReturnsAndTabs(rows->at(row).at(row2)).leftJustified(maxLength, ' ') + "\n";
          }
          output += "\n";
        }

      } else {
        for (row = 1; row < rows->count() - 1; row++) {
          for (row2 = 0; row2 < rows->at(row).count(); row2++) {
            output += replaceReturnsAndTabs(rows->at(0).at(row2)).rightJustified(maxLength, ' ') +  ": ";
            output += QString::fromUtf8(rows->at(row).at(row2).toUtf8()).leftJustified(maxLength, ' ') + "\n";
          }
          output += "\n";
        }
      }
      output += "\n" +  rows->last().at(0) + "\n";
    }
  }
  if (saveToFile) {
    saveOutputToFile(output, "Text Files (*.txt)", settings.value("General/LastTextFile", "").toString());
    return "";
  } else {
    return output;
  }
}

QString DBMS::errorOnExecution(const QString message, const QString type)
{
  emit statusBarMessage(message, QSystemTrayIcon::Critical, 0);
  emit errorOccurred();
  errorMessage->showMessage(message, type);
  return tr("Could not execute statement. ") + message;
}

QString DBMS::outputAsVV(QString queryToExecute, bool saveToFile, bool replaceReturns, bool splitQuery)
{
  return outputAsV(queryToExecute, true, saveToFile, replaceReturns, splitQuery);
}

int DBMS::getPort()
{
  return port;
}

int DBMS::getConnectionId()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT CONNECTION_ID()").at(0).toInt();
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return 0;
}

QString DBMS::getSocket()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT `VARIABLE_VALUE` FROM `information_schema`.`SESSION_VARIABLES` WHERE `VARIABLE_NAME` = 'SOCKET'").at(0).at(0);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QString DBMS::getUserName()
{
  return p_userName;
}

QString DBMS::getFullUserName()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT USER()").at(0);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QString DBMS::getPassword()
{
  return password;
}

QString DBMS::getHostName()
{
//  if (isOpened())
//    switch(p_DBMSType) {
//    case StaticFunctions::MySQL:
//    case StaticFunctions::MariaDB:
//      return runQuerySingleColumn("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'HOSTNAME'").at(0);
//      break;
//    case StaticFunctions::Undefined:
//    default:
//      break;
//    }
  return hostName;
}

QString DBMS::getSessionStatus(QString filter)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (!filter.isEmpty())
        return outputAsTable("SELECT * FROM `information_schema`.`SESSION_STATUS` WHERE `VARIABLE_NAME` LIKE '%" + filter + "%' ORDER BY `VARIABLE_NAME`");
      else
        return outputAsTable("SELECT * FROM `information_schema`.`SESSION_STATUS` ORDER BY `VARIABLE_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QString DBMS::getSessionlVariables(QString filter)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (!filter.isEmpty())
        return outputAsTable("SELECT * FROM `information_schema`.`SESSION_VARIABLES` WHERE `VARIABLE_NAME` LIKE '%" + filter + "%' ORDER BY `VARIABLE_NAME`");
      else
        return outputAsTable("SELECT * FROM `information_schema`.`SESSION_VARIABLES` ORDER BY `VARIABLE_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QString DBMS::getGlobalStatus(QString filter)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (!filter.isEmpty())
        return outputAsTable("SELECT * FROM `information_schema`.`GLOBAL_STATUS` WHERE `VARIABLE_NAME` LIKE '%" + filter + "%' ORDER BY `VARIABLE_NAME`");
      else
        return outputAsTable("SELECT * FROM `information_schema`.`GLOBAL_STATUS` ORDER BY `VARIABLE_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QString DBMS::getGlobalVariables(QString filter)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (!filter.isEmpty())
        return outputAsTable("SELECT * FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` LIKE '%" + filter + "%' ORDER BY `VARIABLE_NAME`");
      else
        return outputAsTable("SELECT * FROM `information_schema`.`GLOBAL_VARIABLES` ORDER BY `VARIABLE_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QString DBMS::getStatus()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return QString("%1").arg(mysql_stat(mariadbConnection));
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

bool DBMS::executeQuery(QString queryToExecute)
{
  if (query(queryToExecute) > 0)
    return true;
  else
    return false;
}

void DBMS::flushPrivileges()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      query("FLUSH PRIVILEGES");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

QString DBMS::getTitle()
{
  return " " + getStringType() + "://" + getUserName() + "@" + getHostName() + "/" + getDatabase();
}

QString DBMS::getStringType()
{
  switch(p_DBMSType) {
  case StaticFunctions::MySQL:
    return "MySQL";
  case StaticFunctions::MariaDB:
    return "MariaDB";
    break;
  case StaticFunctions::Undefined:
    return "--";
  default:
    break;
  }
  return QString();
}

QString DBMS::replaceReturnsAndTabs(QString string)
{
  return QString::fromUtf8(string.toUtf8()).replace(QRegExp("(\\r|\\n|\\t)"), " ");
}

QString DBMS::getConnectionString()
{
  //MySQL:root@10.100.20.214:3306/Drupal *Password
  return QString("%1:%2@%3:%4/%5").arg("MariaDB").arg(getUserName()).arg(getHostName()).arg(getPort()).arg(getDatabase());
}

QString DBMS::getfailedQueries()
{
  QString output;
  int row = 0;
  int row2 = 0;
  QList<int> maxWidthList;

  //QList<QStringList> *failedQueries = failedQueries;

  //Find the maximum values for the width of the columns
  for (row = 0; row < failedQueries->at(0).count(); row++)
    maxWidthList.append(1);
  for (row = 0; row < failedQueries->count(); row++)
    for (row2 = 0; row2 < failedQueries->at(row).count(); row2++)
      if (QString(failedQueries->at(row).at(row2)).length() > maxWidthList.at(row2))
        maxWidthList.replace(row2, QString(failedQueries->at(row).at(row2)).length());

  //Prints the headres and theirs borders
  output += "+";
  for (row = 0; row < failedQueries->at(0).count(); row++)
    output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";
  output += "\n|";
  for (row = 0; row < failedQueries->at(0).count(); row++)
    output +=  " " + replaceReturnsAndTabs(failedQueries->at(0).at(row)).leftJustified(maxWidthList.at(row), ' ') + " |";
  output += "\n+";
  for (row = 0; row < failedQueries->at(0).count(); row++)
    output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";

  //Print the data
  for (row = 1; row < failedQueries->count(); row++) {
    output += "\n|";
    for (row2 = 0; row2 < failedQueries->at(row).count(); row2++)
      output +=  " " + replaceReturnsAndTabs(failedQueries->at(row).at(row2)).leftJustified(maxWidthList.at(row2), ' ') + " |";
  }

  //Print the botton border
  output += "\n+";
  for (row = 0; row < failedQueries->at(0).count(); row++)
    output +=  QString('-').repeated(maxWidthList.at(row) + 2) + "+";

  output += "\n";


  return output;
}

void DBMS::logApplicationStarted()
{
  logExecutedQueries(tr("Application started"));
}

void DBMS::logStatement(QString statement)
{
  logExecutedQueries(statement);
}

QSqlTableModel *DBMS::sqliteTableModel()
{
  QSqlTableModel *sqliteModel = new QSqlTableModel;
  if (settings.value("General/EnableQueryLog", false).toBool()) {
    sqliteModel->setTable("executedqueries");
    sqliteModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    sqliteModel->select();
    sqliteModel->setHeaderData(0, Qt::Horizontal, tr("Line Number"));
    sqliteModel->setHeaderData(1, Qt::Horizontal, tr("Session Id"));
    sqliteModel->setHeaderData(2, Qt::Horizontal, tr("Date"));
    sqliteModel->setHeaderData(3, Qt::Horizontal, tr("Connection"));
    sqliteModel->setHeaderData(4, Qt::Horizontal, tr("Query"));
  }
  return sqliteModel;
}

QSqlQueryModel *DBMS::sqliteFilterQueryModel()
{
  QSqlQueryModel *sqlQuery = new QSqlQueryModel;
  if (settings.value("General/EnableQueryLog", false).toBool())
    sqlQuery->setQuery("SELECT DISTINCT sessionid FROM executedqueries ORDER BY date DESC");
  return sqlQuery;
}

void DBMS::clearSQLiteQueryLog()
{
  if (settings.value("General/EnableQueryLog", false).toBool())
    if (dbSQLite.open()) {
      dateTime = QDateTime::currentDateTime();
      QSqlQuery querySQLite;
      if (!querySQLite.exec("DELETE FROM executedqueries"))
        errorMessage->showMessage(querySQLite.lastError().text(), "LogExecutedQueries");
    }
}

void DBMS::setCollation(QString charset, QString collation)
{
  switch(p_DBMSType) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    query("SET NAMES " + charset + " COLLATE " + collation);
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
}

void DBMS::logExecutedQueries(QString query)
{
  if (settings.value("General/EnableQueryLog", false).toBool())
    if (!dbSQLite.isOpen())
      dbSQLite.open();
    if (dbSQLite.isOpen()) {
      dateTime = QDateTime::currentDateTime();
      QSqlQuery querySQLite;
      querySQLite.prepare("INSERT INTO executedqueries (sessionid, date, connection, query) VALUES (:sessionid, :date, :connection, :query)");
      querySQLite.bindValue(":sessionid", qApp->property("SessionId").toString());
      querySQLite.bindValue(":date", dateTime.toString(Qt::ISODate));
      querySQLite.bindValue(":connection", getConnectionString());
      querySQLite.bindValue(":query", query);
      if (!querySQLite.exec())
        errorMessage->showMessage(querySQLite.lastError().text(), "LogExecutedQueries");
    }
}

QString DBMS::getVersion()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT VERSION()").at(0);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

//QString DBMS::getVersionComment()
//{
//  switch(p_DBMSType) {
//  case StaticFunctions::MySQL:
//  case StaticFunctions::MariaDB:
//    return runQuerySingleColumn("SELECT `VARIABLE_VALUE` FROM `information_schema`.`GLOBAL_VARIABLES` WHERE `VARIABLE_NAME` = 'VERSION_COMMENT'").at(0);
//    break;
//  case StaticFunctions::Undefined:
//  default:
//    break;
//  }
//  return QString();
//}

int unsigned DBMS::getMayorVersion()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return QString(runQuerySingleColumn("SELECT SUBSTRING_INDEX(VERSION(), '.', 1)").at(0)).toInt();
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return 0;
}

int unsigned DBMS::getMinorVersion()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return QString(runQuerySingleColumn("SELECT SUBSTRING_INDEX(VERSION(), '.', 2)").at(0)).toInt();
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return 0;
}

int unsigned DBMS::getMicroVersion()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return QString(runQuerySingleColumn("SELECT SUBSTRING_INDEX(VERSION(), '.', 3)").at(0)).toInt();
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return 0;
}

//int DBMS::getRelease()
//{
//  switch(p_DBMSType) {
//  case StaticFunctions::MySQL:
//  case StaticFunctions::MariaDB:
//    return QString(runQuerySingleColumn("SELECT SUBSTRING(VERSION(), 5)").at(0)).toInt();
//    break;
//  default:
//    break;
//  }
//  return 0;
//}

QString DBMS::getDatabase()
{
  return p_database;
}

bool DBMS::changeDatabase(QString database)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (query(QString("USE " + StaticFunctions::quoteSymbol(database))) == 0) {
        setDatabase(database);
        return true;
      } else {
        return false;
      }
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  emit databaseChanged();
  return false;
}

QString DBMS::getTriggeredefinition(QString trigger, QString database)
{
  if (database.isEmpty())
    database = getDatabase();
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuery("SHOW CREATE TRIGGER " + StaticFunctions::quoteSymbol(database) + "." + StaticFunctions::quoteSymbol(trigger))->at(0).at(2);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QStringList DBMS::getEngines()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT `ENGINE` FROM `information_schema`.`ENGINES` ORDER BY `ENGINE`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QStringList();
}

QStringList DBMS::getCollations()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuerySingleColumn("SELECT `COLLATION_NAME` FROM `information_schema`.`COLLATIONS` ORDER BY `COLLATION_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QStringList();
}

QList<QStringList> *DBMS::getCollationsApplicability()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return runQuery("SELECT `COLLATION_NAME`, CHARACTER_SET_NAME FROM `information_schema`.`COLLATIONS` ORDER BY `COLLATION_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return new QList<QStringList>();
}

void DBMS::setKeyFile(QString keyFile)
{
  this->p_clientKey = keyFile;
}

void DBMS::setCertFile(QString certFile)
{
  this->p_clientCert = certFile;
}

void DBMS::setUseSSL(bool useSSL)
{
  this->p_useSSL = useSSL;
}

int DBMS::ping()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return mysql_ping(mariadbConnection);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return -1;
}

StaticFunctions::dbmsTypes DBMS::getDBMSType()
{
  return p_DBMSType;
}

void DBMS::setDBMSType(StaticFunctions::dbmsTypes type)
{
  qApp->setProperty("DBMSType", type);
  p_DBMSType = type;
}

QList<QStringList> *DBMS::getCharacterSets()
{
  QList<QStringList> *rows = new QList<QStringList>();
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      rows = runQuery("SELECT `CHARACTER_SET_NAME`, `DESCRIPTION` FROM `information_schema`.`CHARACTER_SETS` ORDER BY `CHARACTER_SET_NAME`");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  rows->takeLast();
  return rows;
}

QString DBMS::getCharacterSet()
{
//  if (isOpened())
//    switch(p_DBMSType) {
//    case StaticFunctions::MySQL:
//    case StaticFunctions::MariaDB:
//      return QString(mysql_character_set_name(mariadbConnection));
//      break;
//    case StaticFunctions::Undefined:
//    default:
//      break;
//    }
//  return QString();
  return p_charset;
}

void DBMS::setCharacterSet(QString charset)
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      if (mysql_set_character_set(mariadbConnection, charset.toUtf8()) != 0)
        errorOnExecution(tr("Could not change character set to: %1").arg(charset), "SetCharacterSet");
      settings.setValue("DBMS/CharacterSet", charset);
      //query("SET NAMES 'utf8' COLLATE 'utf8_spanish_ci'");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  p_charset = charset;
}

Table *DBMS::table(QString tableName, QString database)
{
  return new Table(this, tableName, database);
}

Database *DBMS::database(QString databaseName)
{
  return new Database(this, databaseName.isEmpty() ? getDatabase() : databaseName);
}

Event *DBMS::event(QString eventName, QString database)
{
  return new Event(this, eventName, database);
}

Processes *DBMS::processes()
{
  return new Processes(this);
}

Replication *DBMS::replication()
{
  return new Replication(this);
}

void DBMS::errorMessageAcceptedSlot()
{
  emit errorMessageAccepted();
}

void DBMS::checkIfReconnected()
{
  if (isOpened())
    if (p_connectionId != runQuerySingleColumn("SELECT CONNECTION_ID()").at(0).toULong())
      emit reconnectionPerformed();
}

View *DBMS::view(QString viewName, QString database)
{
  return new View(this, viewName, database);
}

Routine *DBMS::routine(QString routineName, QString database)
{
  return new Routine(this, routineName, database);
}

Transaction *DBMS::transaction()
{
  return new Transaction(this);
}

QString DBMS::lastErrorNumber()
{
  if (isOpened())
    switch(p_DBMSType) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      return QString("%1").arg(mysql_errno(mariadbConnection));
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return tr("No error code provided.");
}

Triggers *DBMS::triggers()
{
  return new Triggers(this);
}

Tables *DBMS::tables()
{
  return new Tables(this);
}

Views *DBMS::views()
{
  return new Views(this);
}

Events *DBMS::events()
{
  return new Events(this);
}

Routines *DBMS::routines()
{
  return new Routines(this);
}

/***************************************************************************************************************/

Database::Database(DBMS *serverConnection, QString databaseName)
{
  this->serverConnection = serverConnection;
  if (databaseName.isEmpty())
    this->databaseName = serverConnection->getDatabase();
  else
    this->databaseName = databaseName;
}

bool Database::create(QString collation)
{
  if (collation.isEmpty())
    collation = "utf8_general_ci";
  return serverConnection->executeQuery(QString("CREATE DATABASE %1 COLLATE %2").arg(formalName()).arg(collation));
}

QString Database::formalName()
{
  return StaticFunctions::quoteSymbol(databaseName);
}

bool Database::drop()
{
  return serverConnection->executeQuery(QString("DROP DATABASE %1").arg(formalName()));
}

QStringList Database::getTables()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuerySingleColumn("SELECT `TABLE_NAME` FROM `information_schema`.`TABLES` WHERE `TABLE_TYPE` = 'BASE TABLE' AND `TABLE_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

QStringList Database::getViews()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuerySingleColumn("SELECT `TABLE_NAME` FROM `information_schema`.`TABLES` WHERE `TABLE_TYPE` = 'VIEW' AND `TABLE_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

unsigned long Database::tableCount()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuery("SELECT COUNT(*) FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = '" + databaseName + "'")->at(0).at(0).toULong();
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return 0;
}

QStringList Database::info()
{
  return QStringList()
      << tr("Database: %1").arg(databaseName)
      << tr("Total of tables: %1").arg(serverConnection->runQuerySingleColumn("SELECT COUNT(*) FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = '" + databaseName + "'").at(0))
      << tr("Total of views: %1").arg(serverConnection->runQuerySingleColumn("SELECT COUNT(*) FROM `information_schema`.`VIEWS` WHERE `TABLE_SCHEMA` = '" + databaseName + "'").at(0))
      << tr("Total of triggers: %1").arg(serverConnection->runQuerySingleColumn("SELECT COUNT(*) FROM `information_schema`.`TRIGGERS` WHERE `TRIGGER_SCHEMA` = '" + databaseName + "'").at(0))
      << tr("Total of rutines: %1").arg(serverConnection->runQuerySingleColumn("SELECT COUNT(*) FROM `information_schema`.`ROUTINES` WHERE `ROUTINE_SCHEMA` = '" + databaseName + "'").at(0))
      << tr("Total of events: %1").arg(serverConnection->runQuerySingleColumn("SELECT COUNT(*) FROM `information_schema`.`EVENTS` WHERE `EVENT_SCHEMA` = '" + databaseName + "'").at(0))
      << tr("Tables size: %1").arg(serverConnection->runQuerySingleColumn("SELECT CONCAT(FORMAT((SUM(`DATA_LENGTH`) / 1024 / 1024), 2), ' MB.') AS `Data` FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = '" + databaseName + "'").at(0))
      << tr("Idexes: %1").arg(serverConnection->runQuerySingleColumn("SELECT CONCAT(FORMAT((SUM(`INDEX_LENGTH`) / 1024 / 1024), 2), ' MB.') AS `Indexes` FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = '" + databaseName + "'").at(0))
         ;
}

QStringList Database::getLocalTables()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuerySingleColumn("SELECT `TABLE_NAME` FROM `information_schema`.`TABLES` WHERE `TABLE_TYPE` = 'BASE TABLE' AND `ENGINE` NOT IN ('FEDERATED', 'MEMORY') AND `TABLE_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

QString Database::tableChecksum(QString table)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuery("CHECKSUM TABLE `" + databaseName + "`.`" + table + "`")->at(0).at(1);
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QString();
}

/***************************************************************************************************************/

Table::Table(DBMS *serverConnection, QString tableName, QString database)
{
  this->serverConnection = serverConnection;
  this->tableName = StaticFunctions::quoteSymbol(tableName);
  if (database.isEmpty())
    this->database = StaticFunctions::quoteSymbol(serverConnection->getDatabase());
  else
    this->database = StaticFunctions::quoteSymbol(database);
}

bool Table::renameTable(QString newName)
{
  return serverConnection->executeQuery("RENAME TABLE " + formalName()
                                        + " TO " + StaticFunctions::quoteSymbol(database)
                                        + "." + StaticFunctions::quoteSymbol(newName));
}

bool Table::changeEngine(QString newEngine)
{
  return serverConnection->executeQuery("ALTER TABLE " + formalName() + " ENGINE " + newEngine);
}

bool Table::changeComment(QString newComment)
{
  return serverConnection->executeQuery("ALTER TABLE " + formalName() + " COMMENT '" + newComment + "'");
}

bool Table::changeCollation(QString newCollation)
{
  return serverConnection->executeQuery("ALTER TABLE " + formalName() + " COLLATE " + newCollation);
}

bool Table::drop()
{
  return serverConnection->executeQuery("DROP TABLE IF EXISTS " + formalName());
}

QString Table::formalName()
{
  return database + "." + tableName;
}

QString Table::getDefinition()
{
  return serverConnection->runQuery("SHOW CREATE TABLE " + formalName())->at(0).at(1);
}

QStringList Table::getFields()
{
  return serverConnection->runQuerySingleColumn("SHOW COLUMNS FROM " + formalName());
}

bool Table::dropIndex(QString indexName)
{
  return serverConnection->runQuery("DROP INDEX " + StaticFunctions::quoteSymbol(indexName) + " ON " + formalName());
}

QList<QStringList>* Table::getIndexes()
{
  return serverConnection->runQuery("SHOW INDEX FROM " + formalName());
}

/***************************************************************************************************************/

View::View(DBMS *serverConnection, QString viewName, QString database)
{
  this->serverConnection = serverConnection;
  this->viewName = StaticFunctions::quoteSymbol(viewName);;
  if (database.isEmpty())
    this->database = StaticFunctions::quoteSymbol(serverConnection->getDatabase());
  else
    this->database = StaticFunctions::quoteSymbol(database);
}

bool View::drop()
{
  return serverConnection->executeQuery("DROP VIEW IF EXISTS " + formalName());
}

QString View::formalName()
{
  return database + "." + viewName;
}

QString View::getDefinition()
{
  return serverConnection->runQuery("SHOW CREATE VIEW " + formalName())->at(0).at(1);
}

/***************************************************************************************************************/

Routine::Routine(DBMS *serverConnection, QString routineName, QString database)
{
  this->serverConnection = serverConnection;
  this->routineName = StaticFunctions::quoteSymbol(routineName);
  if (database.isEmpty())
    this->database = StaticFunctions::quoteSymbol(serverConnection->getDatabase());
  else
    this->database = StaticFunctions::quoteSymbol(database);
}

bool Routine::drop()
{
  return serverConnection->executeQuery(QString("DROP %1 IF EXIST %2").arg(routineType()).arg(formalName()));
}

QString Routine::formalName()
{
  return database + "." + routineName;
}

QString Routine::routineType()
{
  if (serverConnection->runQuerySingleColumn("SELECT `ROUTINE_TYPE` FROM `information_schema`.`ROUTINES` WHERE `ROUTINE_NAME` = '"
                                             + routineName.mid(1, routineName.length() - 2) + "' AND `ROUTINE_SCHEMA` = '"
                                             + database.mid(1, database.length() - 2) + "'").at(0) == "FUNCTION")
    return "FUNCTION";
  else
    return "PROCEDURE";
}

QString Routine::getDefinition()
{
  return serverConnection->runQuery("SHOW CREATE " + routineType() + " " + formalName())->at(0).at(2);
}

/***************************************************************************************************************/

Event::Event(DBMS *serverConnection, QString eventName, QString database)
{
  this->serverConnection = serverConnection;
  this->eventName = StaticFunctions::quoteSymbol(eventName);
  if (database.isEmpty())
    this->database = StaticFunctions::quoteSymbol(serverConnection->getDatabase());
  else
    this->database = StaticFunctions::quoteSymbol(database);
}

bool Event::drop()
{
  return serverConnection->runQuery("DROP EVENT " + formalName());
}

QString Event::formalName()
{
  return database + "." + eventName;
}

QString Event::getDefinition()
{
  return serverConnection->runQuery("SHOW CREATE EVENT " + formalName())->at(0).at(3);
}

/***************************************************************************************************************/

Processes::Processes(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

QList<QStringList> *Processes::getProcessList()
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
    result = serverConnection->runQuery("SELECT '', `ID`, `USER`, `HOST`, `DB`, `COMMAND`, `TIME`, `STATE`, REPLACE(`INFO`, '\n', ' ') FROM `information_schema`.`PROCESSLIST`");
    break;
  case StaticFunctions::MariaDB:
    if (serverConnection->getMayorVersion() == 10 && serverConnection->getMinorVersion() == 1 && serverConnection->getMicroVersion() >= 5)
      result = serverConnection->runQuery("SELECT '', `ID`, `USER`, `HOST`, `DB`, `COMMAND`, `TIME`, `STATE`, REPLACE(`INFO`, '\n', ' '), `TIME_MS`, `STAGE`, `MAX_STAGE`, `PROGRESS`, `MEMORY_USED`, `EXAMINED_ROWS`, `QUERY_ID`, `INFO_BINARY` FROM `information_schema`.`PROCESSLIST`");
    else
      result = serverConnection->runQuery("SELECT '', `ID`, `USER`, `HOST`, `DB`, `COMMAND`, `TIME`, `STATE`, REPLACE(`INFO`, '\n', ' '), `TIME_MS`, `STAGE`, `MAX_STAGE`, `PROGRESS`, `MEMORY_USED`, `EXAMINED_ROWS`, `QUERY_ID`, '' FROM `information_schema`.`PROCESSLIST`");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  result->takeLast(); //Remove the "Affected rows" line.
  return result;
}

void Processes::killThread(long long thread)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    serverConnection->runQuery(QString("KILL CONNECTION %1").arg(thread));
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
}

void Processes::killIdleThreads(unsigned int limit)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    result = serverConnection->runQuery(QString("SELECT `ID` FROM `information_schema`.`PROCESSLIST` WHERE `TIME` >  %1 AND `COMMAND` NOT IN ('Daemon', 'Binlog Dump') AND `INFO` IS NULL AND `USER` <> 'federated'").arg(limit));
    result->removeLast();
    for (int row = 0; row < result->count(); row++)
      serverConnection->runQuery(QString("KILL CONNECTION %1").arg(result->at(row).at(0)));
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
}

/***************************************************************************************************************/

Replication::Replication(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

void Replication::changeDefaultMasterConnection(QString masterConnectionName)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->runQuery("SET `default_master_connection` := '" + masterConnectionName + "'");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

QString Replication::getStatus()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      return serverConnection->outputAsTable("SHOW MASTER STATUS") + "\n" + serverConnection->outputAsG("SHOW SLAVE STATUS");
      break;
    case StaticFunctions::MariaDB:
      return serverConnection->outputAsTable("SHOW MASTER STATUS") + "\n" + serverConnection->outputAsG("SHOW ALL SLAVES STATUS");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

void Replication::skipErrors(unsigned int count)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery(QString("STOP SLAVE"));
      serverConnection->executeQuery(QString("SET GLOBAL SQL_SLAVE_SKIP_COUNTER = %1").arg(count));
      serverConnection->executeQuery(QString("START SLAVE;"));
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::stopSlave()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      serverConnection->executeQuery("STOP SLAVE");
      break;
    case StaticFunctions::MariaDB:
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::startSlave()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      serverConnection->executeQuery("START SLAVE");
      break;
    case StaticFunctions::MariaDB:
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::rebootSlave()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      serverConnection->executeQuery("STOP SLAVE");
      serverConnection->executeQuery("START SLAVE");
      break;
    case StaticFunctions::MariaDB:
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::resetSlave()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      serverConnection->executeQuery("RESET SLAVE");
      break;
    case StaticFunctions::MariaDB:
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::purgeBinaryLogs()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("PURGE BINARY LOGS BEFORE NOW()");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::flushRelayLogs()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("FLUSH REALY LOGS");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::stopAllSlaves()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("STOP ALL SLAVES");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::startAllSlaves()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("START ALL SLAVES");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

QString Replication::getStatus(QString connectionName)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      return serverConnection->outputAsTable("SHOW MASTER STATUS") + "\n" + serverConnection->outputAsG("SHOW SLAVE '" + connectionName + "' STATUS");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QString();
}

QStringList Replication::getSlavesNames()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      return QStringList();
      break;
    case StaticFunctions::MariaDB:
      return serverConnection->runQuerySingleColumn("SHOW ALL SLAVES STATUS", false);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
  return QStringList();
}

void Replication::stopSlave(QString connectionName)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("STOP SLAVE '" + connectionName + "'");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::startSlave(QString connectionName)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("START SLAVE '" + connectionName + "'");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::rebootSlave(QString connectionName)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("STOP SLAVE '" + connectionName + "'");
      serverConnection->executeQuery("START SLAVE '" + connectionName + "'");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Replication::resetSlave(QString connectionName)
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
      break;
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("RESET SLAVE '" + connectionName + "'");
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

/***************************************************************************************************************/

Transaction::Transaction(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

void Transaction::beginTransacction()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("START TRANSACTION");
      emit serverConnection->statusBarMessage(tr("Transaction started"), QSystemTrayIcon::Information, 0);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Transaction::commitTransacction()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("COMMIT");
      emit serverConnection->statusBarMessage(tr("Transaction commited"), QSystemTrayIcon::Information, 0);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

void Transaction::rollbackTransacction()
{
  if (serverConnection->isOpened())
    switch(serverConnection->getDBMSType()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      serverConnection->executeQuery("ROLLBACK");
      emit serverConnection->statusBarMessage(tr("Transaction rollbacked"), QSystemTrayIcon::Information, 0);
      break;
    case StaticFunctions::Undefined:
    default:
      break;
    }
}

/*******************************************************************************************/

Triggers::Triggers(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

QStringList Triggers::list(QString databaseName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    if (databaseName.isEmpty())
      databaseName = serverConnection->getDatabase();
    return serverConnection->runQuerySingleColumn("SELECT CONCAT('`', `TRIGGER_SCHEMA`, '`.`', `TRIGGER_NAME`, '`')  FROM `information_schema`.`TRIGGERS` WHERE `TRIGGER_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

/*******************************************************************************************/

Tables::Tables(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

QStringList Tables::list(QString databaseName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    if (databaseName.isEmpty())
      databaseName = serverConnection->getDatabase();
    return serverConnection->runQuerySingleColumn("SELECT CONCAT('`', `TABLE_SCHEMA`, '`.`', `TABLE_NAME`, '`') FROM `information_schema`.`TABLES` WHERE `TABLE_SCHEMA` = '" + databaseName + "' AND `TABLE_TYPE` = 'BASE TABLE'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

QString Tables::getDefinition(QString formalTableName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuery("SHOW CREATE TABLE  " + formalTableName)->at(0).at(1);
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QString();
}

/*******************************************************************************************/

Views::Views(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

QStringList Views::list(QString databaseName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    if (databaseName.isEmpty())
      databaseName = serverConnection->getDatabase();
    return serverConnection->runQuerySingleColumn("SELECT CONCAT('`', `TABLE_SCHEMA`, '`.`', `TABLE_NAME`, '`') FROM `information_schema`.`VIEWS` WHERE `TABLE_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

QString Views::getDefinition(QString formalViewName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    return serverConnection->runQuery("SHOW CREATE VIEW  " + formalViewName)->at(0).at(1);
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QString();
}

/*******************************************************************************************/

Events::Events(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

QStringList Events::list(QString databaseName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    if (databaseName.isEmpty())
      databaseName = serverConnection->getDatabase();
    return serverConnection->runQuerySingleColumn("SELECT CONCAT('`', `EVENT_SCHEMA`, '`.`', `EVENT_NAME`, '`') FROM `information_schema`.`EVENTS` WHERE `EVENT_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}

/*******************************************************************************************/

Routines::Routines(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
}

QStringList Routines::list(QString databaseName)
{
  switch(serverConnection->getDBMSType()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    if (databaseName.isEmpty())
      databaseName = serverConnection->getDatabase();
    return serverConnection->runQuerySingleColumn("SELECT CONCAT('`', `ROUTINE_SCHEMA`, '`.`', `ROUTINE_NAME`, '`') FROM `information_schema`.`ROUTINES` WHERE `ROUTINE_SCHEMA` = '" + databaseName + "'");
    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }
  return QStringList();
}
