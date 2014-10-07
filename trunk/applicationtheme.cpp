#include <QTextCharFormat>

#include "applicationtheme.h"

ApplicationTheme::ApplicationTheme()
{
  //https://gitorious.org/dlib/netuno-sandbox/commit/9743e296795038d51e8b26392ab2138ccf173c20

  QTextCharFormat textCharFormatSQLKeywords;
  textCharFormatSQLKeywords.setForeground(Qt::blue);
  settings.setValue("Theme/SQLKeywords-Foreground-ColorName", textCharFormatSQLKeywords.foreground().color().name());
  settings.setValue("Theme/SQLKeywords-Foreground-ColorAlpha", textCharFormatSQLKeywords.foreground().color().alpha());
  settings.setValue("Theme/SQLKeywords-Foreground-FontFamily", textCharFormatSQLKeywords.font().family());
  settings.setValue("Theme/SQLKeywords-Foreground-FontSize", textCharFormatSQLKeywords.font().pointSize());
  settings.setValue("Theme/SQLKeywords-Foreground-FontStyle", textCharFormatSQLKeywords.font().style());
}
