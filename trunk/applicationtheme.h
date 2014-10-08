#ifndef APPLICATIONTHEME_H
#define APPLICATIONTHEME_H

#include <QWidget>
#include <QSettings>

class QPlainTextEdit;

class ApplicationTheme : public QWidget
{
  Q_OBJECT

public:
  ApplicationTheme();

private:
  QSettings settings;
  QPlainTextEdit *themePlainTextEdit;
};

#endif // APPLICATIONTHEME_H
