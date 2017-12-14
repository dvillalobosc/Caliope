#ifndef OBJECTMIGRATION_H
#define OBJECTMIGRATION_H

class QTreeWidget;
class BaseTextEditor;
class QTreeWidgetItem;
class QCheckBox;
class QRadioButton;
class DTitleLabel;
class QGroupBox;
class QPushButton;

#include "dbms.h"
#include "dmdisubwindow.h"

class ObjectMigration : public DMdiSubWindow
{
  Q_OBJECT

public:
  ObjectMigration(DBMS *serverConnection);

protected:
  void retranslateUi();

private:
  DBMS *serverConnection;
  DBMS *secondaryServerConnection;
  DTitleLabel *dTitleLabel;
  QTreeWidget *objectsListWidget;
  BaseTextEditor *resultEditor;
  QPushButton *migratePushButton;
  QList<QTreeWidgetItem *> databases;
  QCheckBox *optionDROP;
  QGroupBox *groupBoxAction;
  QCheckBox *optionExportData;
  QStringList *statementsToExecute;
  int counter;
  QCheckBox *optionFOREIGN_KEY_CHECKS;

private slots:
  void fillDatabasesSlot();
  void itemActivatedSlot(QTreeWidgetItem *item, int column);
  void migratePushButtonSlot();
  void statementsToExecuteSlot();

signals:
  void loadProgress(const int progress);
};

#endif // OBJECTMIGRATION_H
