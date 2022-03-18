#ifndef DEMOSINGLETON_H
#define DEMOSINGLETON_H

#include "singleton.h"
#include <QString>

class DemoSingleton
{
    SINGLETON(DemoSingleton)

public:
    QString getDatabseName() const;
};

#endif // DEMOSINGLETON_H
