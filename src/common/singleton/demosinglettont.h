#ifndef DEMOSINGLETTONT_H
#define DEMOSINGLETTONT_H

#include "singletont.h"
#include <QString>

class DemoSinglettonT
{
    SINGLETONT(DemoSinglettonT)

public:
    QString getDatabaseName() const;
};

#endif // DEMOSINGLETTONT_H
