/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2018 David Villalobos Cambronero (dvillalobosc@yahoo.com).
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

#include <QApplication>

#include "mainwindow.h"

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
  QByteArray localMsg = msg.toLocal8Bit();
  switch (type) {
  case QtDebugMsg:
    fprintf(stderr, "Debug: %s, File: %s, Line:%u, Function: %s. Category: %s, Version: %u.\n", localMsg.constData(), context.file, context.line, context.function, context.category, context.version);
    break;
  case QtWarningMsg:
    fprintf(stderr, "Warning: %s, File: %s, Line:%u, Function: %s. Category: %s, Version: %u.\n", localMsg.constData(), context.file, context.line, context.function, context.category, context.version);
    break;
  case QtCriticalMsg:
    fprintf(stderr, "Critical: %s, File: %s, Line:%u, Function: %s. Category: %s, Version: %u.\n", localMsg.constData(), context.file, context.line, context.function, context.category, context.version);
    break;
  case QtFatalMsg:
    fprintf(stderr, "Fatal: %s, File: %s, Line:%u, Function: %s. Category: %s, Version: %u.\n", localMsg.constData(), context.file, context.line, context.function, context.category, context.version);
    abort();
    break;
#if QT_VERSION >= 0x055000
  case QtInfoMsg:
    fprintf(stderr, "Informatition: %s, File: %s, Line:%u, Function: %s. Category: %s, Version: %u.\n", localMsg.constData(), context.file, context.line, context.function, context.category, context.version);
    break;
#endif
  }
}

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(icons);
  Q_INIT_RESOURCE(translations);
  Q_INIT_RESOURCE(styles);
  qInstallMessageHandler(myMessageOutput);
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication app(argc, argv);
  MainWindow *mainWindow = new MainWindow;
  mainWindow->show();
  return app.exec();
}
