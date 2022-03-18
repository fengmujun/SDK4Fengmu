#ifndef CLIENTDEV_H
#define CLIENTDEV_H

#include "generaldev.h"
#include <QObject>

#include "generaldev_global.h"

class ServiceDev;

class GENERALDEV_EXPORT ClientDev : public GeneralDev
{

    Q_OBJECT

    Q_PROPERTY(unsigned int ID READ ID WRITE setID NOTIFY IDChanged)
    Q_PROPERTY(ServiceDev *server READ server WRITE setServer NOTIFY serverChanged)

public:
    explicit ClientDev(unsigned int id, QObject *parent = nullptr);

    unsigned int ID() const;
    void setID(unsigned int newID);

    ServiceDev *server() const;
    void setServer(ServiceDev *newServer);

signals:

    void IDChanged();

    void serverChanged();

private slots:

    void initialProperty();

private:

    unsigned int m_ID;
    ServiceDev *m_server;
};

#endif // CLIENTDEV_H
