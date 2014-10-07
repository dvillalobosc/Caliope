#ifndef APPLICATIONTHEME_H
#define APPLICATIONTHEME_H

#include <QWidget>
#include <QSettings>

class ApplicationTheme : public QWidget
{
  Q_OBJECT

public:
  ApplicationTheme();

private:
  QSettings settings;
};

#endif // APPLICATIONTHEME_H
