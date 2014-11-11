#ifndef DPIECHARTWIDGET_H
#define DPIECHARTWIDGET_H

#include <QWidget>

class DPieChartWidget : public QWidget
{
  Q_OBJECT

public:
  DPieChartWidget(QString unit = QString());
  void addEntry(const QString key, const double value);
  void clear();
  void setUnit(QString unit);
  QString getUnit();

protected:
  void paintEvent(QPaintEvent *event);

private:
  //QHash<QString, int> values;
  QList<QPair<QString, double> > values;
  QString unit;
};

#endif // DPIECHARTWIDGET_H
