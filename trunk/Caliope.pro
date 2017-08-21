HEADERS += \
    connectdialog.h \
    serverInformation.h \
    catalogs.h \
    dstatusbar.h \
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
    dquerylog.h \
    applicationtheme.h \
    dreportviewer.h \
    dpiechartwidget.h \
    mariadbhelp.h \
    codesnippets.h \
    objectmigration.h
SOURCES += \
    main.cpp \
    connectdialog.cpp \
    serverInformation.cpp \
    catalogs.cpp \
    dstatusbar.cpp \
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
    dquerylog.cpp \
    applicationtheme.cpp \
    dreportviewer.cpp \
    dpiechartwidget.cpp \
    mariadbhelp.cpp \
    codesnippets.cpp \
    objectmigration.cpp
FORMS +=
RESOURCES += icons.qrc \
    styles.qrc \
    translations.qrc \
    styles.qrc \
    qmls.qrc \
    documentation.qrc
TRANSLATIONS += translations/caliope_es_cr.ts
SUBDIRS += images

#Linux
unix:LIBS += -L/usr/lib64 -lmysqlclient
#Windows
win32:LIBS += -Lc:/mariadb/lib -llibmariadb
win32:INCLUDEPATH += $$quote(c:/mariadb/include)
win32:DEFINES += __LCC__

#Mac
#unix:LIBS += -L/opt/local/lib/mysql5/mysql -lmysqlclient
#unix:INCLUDEPATH += /opt/local/include/mysql5/mysql

OTHER_FILES += \
    TODO.txt \
    styles/mainStyle.css \
    messageBox.qml

TARGET = Caliope

QT += qml quick
QT += network
QT += svg
QT += sql
QT += printsupport
QT += xml
QT += webenginewidgets
CONFIG += qscintilla2

#cd html; for file in *; do echo "/html/"$file >> ../filelist.txt; done; cd search; for file in *; do echo "/html/search/"$file >> ../../filelist.txt; done; cd ..; cd ..;
#!contains(QT_MAJOR_VERSION, 4)
#{ error("you are using an old version of Qt") }
