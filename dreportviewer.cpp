#include <QVBoxLayout>
#include <QIcon>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QApplication>
#include <QSettings>
#include <QPrinter>
#include <QImageWriter>

#include "dreportviewer.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "dpiechartwidget.h"

DReportViewer::DReportViewer(DBMS *serverConnection, QString reportTitle, ReportTypes::ReportType reportType, QString unit)
{
  this->serverConnection = serverConnection;
  this->reportType = reportType;
  setWindowTitle(tr("Report:") + " " +reportTitle);
  setObjectName(windowTitle());

  setWindowIcon(QIcon(":/images/svg/view-statistics.svg"));
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  mainVLayout->addWidget(new DTitleLabel(windowTitle()));

  QHBoxLayout *groupBoxHLayout = new QHBoxLayout;

  pushButtonRefresh = new QPushButton;
  pushButtonRefresh->setIcon(QIcon::fromTheme("view-refresh", QIcon(":/images/svg/view-refresh-7.svg")));
  connect(pushButtonRefresh, SIGNAL(clicked()), this, SLOT(showReportData()));
  groupBoxHLayout->addWidget(pushButtonRefresh);

  pushButtonExportToPDF = new QPushButton;
  pushButtonExportToPDF->hide();
  pushButtonExportToPDF->setIcon(QIcon(":/images/svg/application-pdf.svg"));
  connect(pushButtonExportToPDF, SIGNAL(clicked()), this, SLOT(pushButtonExportToPDFClicked()));
  groupBoxHLayout->addWidget(pushButtonExportToPDF);

  pushButtonExportToImage = new QPushButton;
  pushButtonExportToImage->hide();
  pushButtonExportToImage->setIcon(QIcon::fromTheme("image-x-generic", QIcon(":/images/svg/image-png.svg")));
  connect(pushButtonExportToImage, SIGNAL(clicked()), this, SLOT(pushButtonExportToImageClicked()));
  groupBoxHLayout->addWidget(pushButtonExportToImage);

  groupBoxHLayout->addStretch(1);
  mainVLayout->addLayout(groupBoxHLayout);

  switch (reportType) {
  case ReportTypes::PlainText:
    plainTextReport = new QPlainTextEdit;
    plainTextReport->setFont(StaticFunctions::fixedWidthFont());
    plainTextReport->setWordWrapMode(QTextOption::NoWrap);
    mainVLayout->addWidget(plainTextReport);
    pushButtonExportToPDF->show();
    break;
  case ReportTypes::PieChart:
    dPieChart = new DPieChartWidget(unit);
    mainVLayout->addWidget(dPieChart);
    pushButtonExportToImage->show();
    break;
  default:
    break;
  }

  QWidget *widMain = new QWidget;
  retranslateUi();
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
}

void DReportViewer::setSqlQuery(QString sqlQuery)
{
  this->sqlQuery = sqlQuery;
}

QString DReportViewer::getSqlQuery()
{
  return sqlQuery;
}

void DReportViewer::showReportData()
{
  switch (reportType) {
  case ReportTypes::PlainText:
    if (plainTextReport) {
      plainTextReport->setPlainText(serverConnection->outputAsTable(sqlQuery));
    }
    break;
  case ReportTypes::PieChart: {
    QApplication::setOverrideCursor(Qt::WaitCursor);
    switch(qApp->property("DBMSType").toInt()) {
    case StaticFunctions::MySQL:
    case StaticFunctions::MariaDB:
      dPieChart->clear();
      result = serverConnection->runQuery(sqlQuery);
      result->takeLast(); //Remove the "Affected rows" line.
      for (int counter = 0; counter < result->count(); counter++)
        dPieChart->addEntry(result->at(counter).at(0), result->at(counter).at(1).toDouble());
      break;
    case StaticFunctions::PostgreSQL:
    case StaticFunctions::Undefined:
    default:
      break;
    }
    QApplication::restoreOverrideCursor();
  }
    break;
  default:
    break;
  }
}

void DReportViewer::retranslateUi()
{
  pushButtonExportToPDF->setText(tr("Export to PDF"));
  pushButtonRefresh->setText(tr("Refresh"));
  pushButtonExportToImage->setText(tr("Export to Image"));
}

void DReportViewer::pushButtonExportToPDFClicked()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString file = fileDialog.getSaveFileName(this, tr("Save to Pdf"), settings.value("LastFilePdf", QDir::home().absolutePath()).toString(), tr("Pdf & Ps files (*.pdf *.ps)"));
  settings.setValue("LastFilePdf", fileDialog.directory().filePath(file));
  QPrinter printer(QPrinter::HighResolution);
  printer.setOutputFileName(file);
  printer.setOutputFormat(file.endsWith(".pdf") ? QPrinter::PdfFormat : QPrinter::NativeFormat);
  plainTextReport->document()->print(&printer);
  QApplication::restoreOverrideCursor();
  emit statusBarMessage(tr("File saved at: %1").arg(file));
}

void DReportViewer::pushButtonExportToImageClicked()
{
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QFileDialog fileDialog;
  fileDialog.setDirectory(QDir::home());
  QString imageFormats;
  foreach(QString format, QImageWriter::supportedImageFormats())
    imageFormats += "*." + format + " ";
  QString file = fileDialog.getSaveFileName(this, tr("Save to Image"), settings.value("LastFileImg", QDir::home().absolutePath()).toString(), tr("Image files (%1)").arg(imageFormats));
  settings.setValue("LastFileImg", fileDialog.directory().filePath(file));
  QPixmap pixmap(this->size());
  dPieChart->render(&pixmap);
  pixmap.save(file, "PNG", 5);
  QApplication::restoreOverrideCursor();
  statusBarMessage(tr("File saved at: %1").arg(file));
}
