#include <QVBoxLayout>
#include <QIcon>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QApplication>
#include <QSettings>
#include <QPrinter>
#include <QImageWriter>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QCompleter>

#include "dreportviewer.h"
#include "dtitlelabel.h"
#include "staticfunctions.h"
#include "dpiechartwidget.h"
#include "basetexteditor.h"

#include <QDebug>

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

void DReportViewer::addCustomReport()
{
  dialog = new QDialog(this);

  QVBoxLayout *verticalLayout = new QVBoxLayout;
  verticalLayout->addWidget(new DTitleLabel(windowTitle()));

  comboReportName = new QComboBox();
  connect(comboReportName, SIGNAL(activated(QString)), this, SLOT(fillCustomReportwidgets(QString)));
  comboReportName->setEditable(true);
  settings.beginGroup("CustomReports");
  QStringList reports = settings.allKeys();
  foreach (QString report, reports)
    comboReportName->addItem(report);

  completer = new QCompleter(reports, comboReportName);
#if QT_VERSION > 0x040801
    completer->setFilterMode(Qt::MatchContains);
#endif
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  comboReportName->setCompleter(completer);

  lineEditUnit = new QLineEdit;

  comboReportType = new QComboBox();
  //PlainText, BarChart, PieChart
  comboReportType->addItem(tr("Plain text"), ReportTypes::PlainText);
  //comboReportType->addItem(tr("Bar chart"), ReportTypes::BarChart);
  comboReportType->addItem(tr("Pie chart"), ReportTypes::PieChart);

  baseTextEditor = new BaseTextEditor(EditorTypes::SQLQuery);

  QFormLayout *formLayout = new QFormLayout;
  formLayout->addRow(tr("&Report Name:"), comboReportName);
  formLayout->addRow(tr("&Unit:"), lineEditUnit);
  formLayout->addRow(tr("&Type:"), comboReportType);
  formLayout->addRow(baseTextEditor);
  verticalLayout->addLayout(formLayout);

  QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::Discard | QDialogButtonBox::Help);
  connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
  connect(buttonBox->button(QDialogButtonBox::Discard), SIGNAL(clicked()), this, SLOT(discardReportSlot()));
  verticalLayout->addWidget(buttonBox);

  fillCustomReportwidgets(comboReportName->currentText());
  comboReportName->lineEdit()->selectAll();

  dialog->setLayout(verticalLayout);
  if (dialog->exec() == QDialog::Accepted) {
    settings.setValue(comboReportName->currentText(), QString("#Unit:%1#Type:%2#SQLQuery:%3")
                      .arg(lineEditUnit->text())
                      .arg(comboReportType->currentData().toString())
                      .arg(baseTextEditor->toPlainText()));
  }
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

void DReportViewer::fillCustomReportwidgets(QString reportName)
{
  QStringList data = settings.value(reportName).toString().split("#", QString::SkipEmptyParts);
  lineEditUnit->setText(data.at(0).split(":").at(1));
  comboReportType->setCurrentIndex(comboReportType->findData(data.at(1).split(":").at(1).toInt()));
  baseTextEditor->setPlainText(data.at(2).split(":").at(1));
}

void DReportViewer::discardReportSlot()
{
  settings.remove(comboReportName->currentText());
  dialog->close();
}
