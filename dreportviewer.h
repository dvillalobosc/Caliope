#ifndef DREPORTVIEWER_H
#define DREPORTVIEWER_H

#include <QSystemTrayIcon>
#include <QSettings>

#include "dmdisubwindow.h"
#include "dbms.h"

class ReportTypes
{
public:
  enum ReportType {PlainText, BarChart, PieChart, None};
};

class QPlainTextEdit;
class QPushButton;
class DPieChartWidget;
class QComboBox;
class QLineEdit;
class BaseTextEditor;
class QCompleter;

class DReportViewer : public DMdiSubWindow
{
  Q_OBJECT

public:
  DReportViewer(DBMS *serverConnection, QString reportTitle, ReportTypes::ReportType reportType, QString unit = QString());
  void setSqlQuery(QString sqlQuery);
  QString getSqlQuery();
  void addCustomReport();

public slots:
  void showReportData();

private:
  DBMS *serverConnection;
  ReportTypes::ReportType reportType;
  QPlainTextEdit *plainTextReport;
  QPushButton *pushButtonExportToPDF;
  QSettings settings;
  QString sqlQuery;
  QPushButton *pushButtonRefresh;
  DPieChartWidget *dPieChart;
  QList<QStringList> *result;
  QPushButton *pushButtonExportToImage;
  QComboBox *comboReportName;
  QLineEdit *lineEditUnit;
  QComboBox *comboReportType;
  BaseTextEditor *baseTextEditor;
  QCompleter *completer;

protected:
  void retranslateUi();

private slots:
  void pushButtonExportToPDFClicked();
  void pushButtonExportToImageClicked();
  void fillCustomReportwidgets(QString reportName);

signals:
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 2000);
};

#endif // DREPORTVIEWER_H
