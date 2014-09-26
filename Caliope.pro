HEADERS += \
    connectdialog.h \
    serverInformation.h \
    catalogs.h \
    dstatusbar.h \
    mysqlhelp.h \
    processlist.h \
    dtitlelabel.h \
    staticfunctions.h \
    tablemaintenance.h \
    findreplace.h \
    dtablewidget.h \
    result.h \
    backup.h \
    restore.h \
    users.h \
    preferences.h \
    newdatabase.h \
    texteditor.h \
    editortypes.h \
    basetexteditor.h \
    subversionedfile.h \
    dmessagelabel.h \
    objectsdiagram.h \
    commitdialog.h \
    basedifffile.h \
    difffile.h \
    fileselector.h \
    licensetemplate.h \
    networksettings.h \
    basesvnlog.h \
    svnlog.h \
    projects.h \
    generalhighlighter.h \
    dwebview.h \
    statements.h \
    dtableview.h \
    ditemdelegate.h \
    dlineedit.h \
    fileassociations.h \
    mainwindow.h \
    projectfindreplace.h \
    dbms.h \
    sqlquery.h \
    databasecomparision.h \
    dmdisubwindow.h \
    dstackedwidget.h \
    dquerylog.h
SOURCES += \
    main.cpp \
    connectdialog.cpp \
    serverInformation.cpp \
    catalogs.cpp \
    dstatusbar.cpp \
    mysqlhelp.cpp \
    processlist.cpp \
    dtitlelabel.cpp \
    staticfunctions.cpp \
    tablemaintenance.cpp \
    findreplace.cpp \
    dtablewidget.cpp \
    result.cpp \
    backup.cpp \
    restore.cpp \
    users.cpp \
    preferences.cpp \
    newdatabase.cpp \
    texteditor.cpp \
    editortypes.cpp \
    basetexteditor.cpp \
    subversionedfile.cpp \
    dmessagelabel.cpp \
    objectsdiagram.cpp \
    commitdialog.cpp \
    basedifffile.cpp \
    difffile.cpp \
    fileselector.cpp \
    licensetemplate.cpp \
    networksettings.cpp \
    basesvnlog.cpp \
    svnlog.cpp \
    projects.cpp \
    generalhighlighter.cpp \
    dwebview.cpp \
    statements.cpp \
    dtableview.cpp \
    ditemdelegate.cpp \
    dlineedit.cpp \
    fileassociations.cpp \
    mainwindow.cpp \
    projectfindreplace.cpp \
    dbms.cpp \
    sqlquery.cpp \
    databasecomparision.cpp \
    dmdisubwindow.cpp \
    dstackedwidget.cpp \
    dquerylog.cpp
FORMS +=
RESOURCES += icons.qrc \
    styles.qrc \
    translations.qrc \
    styles.qrc \
    qmls.qrc \
    documentation.qrc
TRANSLATIONS += translations/caliope_es.ts
SUBDIRS += images

UsePostgreSQL = 0

#Linux
unix:LIBS += -L/usr/lib64 -lmysqlclient
#Windows
win32:LIBS += -Lc:/mysql/lib -lmysqlclient
win32:INCLUDEPATH += $$quote(c:/mysql/include)
win32:DEFINES += __LCC__

contains(UsePostgreSQL, 1) {
    win32:LIBS += -Lc:/PostgreSQL/bin -lpq
    win32:INCLUDEPATH += $$quote(c:/PostgreSQL/include)
    unix:LIBS += -L/usr/lib64 -lpq
}
#Mac
unix:LIBS += -L/opt/local/lib/mysql5/mysql -lmysqlclient
unix:INCLUDEPATH += /opt/local/include/mysql5/mysql

OTHER_FILES += \
    TODO.txt \
    styles/mainStyle.css \
    messageBox.qml

TARGET = Caliope

contains(QT_VERSION, 5.2.0) {
    QT += webkitwidgets
}
contains(QT_VERSION, 4.8.1) {
    QT += webkit
}
QT += declarative
QT += network
QT += svg
QT += sql

#!contains(QT_MAJOR_VERSION, 4)
#{ error("you are using an old version of Qt") }
