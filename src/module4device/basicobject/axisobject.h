#ifndef AXISOBJECT_H
#define AXISOBJECT_H

#include "basicobject.h"
#include <QObject>

class AxisObject : public BasicObject
{
public:
    explicit AxisObject(QObject *parent = nullptr);

    bool zero();

    bool move(const int &pos, MOVEMODE movemode = ABSOLUTE);

};

#endif // AXISOBJECT_H
