#include <QIcon>

#include "dicon.h"

DIcon::DIcon()
{

}

QIcon DIcon::Next() { return QIcon::fromTheme("find-next", QIcon(":/images/svg/go-next-view.svg")); }
QIcon DIcon::Database() { return DIcon::Database(); }
