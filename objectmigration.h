#ifndef OBJECTMIGRATION_H
#define OBJECTMIGRATION_H

class DTitleLabel;

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
  DTitleLabel *dTitleLabel;
};

#endif // OBJECTMIGRATION_H
