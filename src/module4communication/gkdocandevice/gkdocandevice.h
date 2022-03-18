#ifndef GKDOCANDEVICE_H
#define GKDOCANDEVICE_H

#include "candevice.h"
#include <QObject>

class GKDOCanDevice : public CanDevice
{
    Q_OBJECT
public:
    explicit GKDOCanDevice(const unsigned int id, QObject *parent = nullptr);
};

#endif // GKDOCANDEVICE_H
