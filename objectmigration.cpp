#include <QVBoxLayout>

#include "objectmigration.h"
#include "dtitlelabel.h"

ObjectMigration::ObjectMigration(DBMS *serverConnection)
{
  this->serverConnection = serverConnection;
  setWindowIcon(QIcon::fromTheme("find-next", QIcon(":/images/svg/go-next-view.svg")));
  QWidget *widMain = new QWidget;
  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->setContentsMargins(3, 0, 3, 0);
  dTitleLabel = new DTitleLabel;
  mainVLayout->addWidget(dTitleLabel);

  retranslateUi();
  widMain->setLayout(mainVLayout);
  setWidget(widMain);
}

void ObjectMigration::retranslateUi()
{
  setWindowTitle(tr("Object Migration"));
  setObjectName(windowTitle());
  dTitleLabel->setText(windowTitle());
}

