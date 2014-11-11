#include <QPainter>

#include "dpiechartwidget.h"
#include "staticfunctions.h"

DPieChartWidget::DPieChartWidget(QString unit)
{
  this->unit = unit;
}

void DPieChartWidget::addEntry(const QString key, const double value)
{
  values.append(qMakePair(key, value));
}

void DPieChartWidget::clear()
{
  values.clear();
}

void DPieChartWidget::setUnit(QString unit)
{
  this->unit = unit;
}

QString DPieChartWidget::getUnit()
{
  return unit;
}

void DPieChartWidget::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  double totalValues = 0;
  for (int counter = 0; counter < values.count(); counter++)
    totalValues += values.at(counter).second;

  QStringList colorNames = QColor::colorNames();
  int colorPos = 13;
  QRect pieRect(10, 10, rect().height() - 10, rect().height() - 20);

  QRect legendRect = rect();
  legendRect.setLeft(pieRect.width());
  legendRect.adjust(20, 20, -10, -10);
  int lastAngleOffset = 0;
  int currentPos = 0;

  for (int counter = 0; counter < values.count(); counter++) {
    painter.setBrush(QBrush(QColor(colorNames.at(colorPos++ % colorNames.count()))));

    int angle = (int) (16 * 360 * (values.at(counter).second / totalValues));

    painter.drawPie(pieRect, lastAngleOffset, angle);
    lastAngleOffset += angle;

    QRect legendEntryRect(0,(fontMetrics().height() * 2) * currentPos, fontMetrics().height(), fontMetrics().height());
    currentPos++;
    legendEntryRect.translate(legendRect.topLeft());

    painter.drawRect(legendEntryRect);

    QPoint textStart = legendEntryRect.topRight();
    textStart = textStart + QPoint(fontMetrics().width('X'), 0);

    QPoint textEnd(legendRect.right(), legendEntryRect.bottom());
    QRect textEntryRect(textStart, textEnd);
    painter.drawText(textEntryRect, Qt::AlignVCenter, QString("%1: %2. %3%.")
                     .arg(values.at(counter).first)
                     .arg(StaticFunctions::currentLocale().toString(values.at(counter).second, 'f', 2))
                     .arg(QString::number((values.at(counter).second * 100 / totalValues), 'f', 2))
                     );
  }
  QRect legendEntryRect(0,(fontMetrics().height() * 2) * currentPos, fontMetrics().height(), fontMetrics().height());
  currentPos++;
  legendEntryRect.translate(legendRect.topLeft());
  QPoint textStart = legendEntryRect.topRight();
  textStart = textStart + QPoint(fontMetrics().width('X'), 0);
  QPoint textEnd(legendRect.right(), legendEntryRect.bottom());
  QRect textEntryRect(textStart, textEnd);
  painter.drawText(textEntryRect, Qt::AlignVCenter, tr("Total: %1 %2.").arg(StaticFunctions::currentLocale().toString(totalValues, 'f', 2)).arg(unit));
}
