#ifndef DICON_H
#define DICON_H

#include <QObject>

class DIcon : public QIcon
{
public:
  DIcon();
  static QIcon Next();
  static QIcon Database();
};

#endif // DICON_H
