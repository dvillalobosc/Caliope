#ifndef DREPORTVIEWER_H
#define DREPORTVIEWER_H

#include <QSystemTrayIcon>
#include <QSettings>

#include "dmdisubwindow.h"
#include "dbms.h"

class ReportTypes
{
public:
  enum ReportType {PlainText, BarChart, PieChart};
};

class QPlainTextEdit;
class QPushButton;
class DPieChartWidget;

class DReportViewer : public DMdiSubWindow
{
  Q_OBJECT

public:
  DReportViewer(DBMS *serverConnection, QString reportTitle, ReportTypes::ReportType reportType, QString unit = QString());
  void setSqlQuery(QString sqlQuery);
  QString getSqlQuery();

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

protected:
  void retranslateUi();

private slots:
  void pushButtonExportToPDFClicked();
  void pushButtonExportToImageClicked();

signals:
  void statusBarMessage(const QString &message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int timeout = 2000);
};

#endif // DREPORTVIEWER_H
