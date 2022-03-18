#ifndef SERVICEDEV_H
#define SERVICEDEV_H

#include "generaldev.h"
#include <QObject>
#include <QMap>

#include "generaldev_global.h"


class QThread;
class ClientDev;


class GENERALDEV_EXPORT ServiceDev : public GeneralDev
{
    Q_OBJECT


public:
    explicit ServiceDev(QObject *parent = nullptr);
    ~ServiceDev();

    virtual void reg(ClientDev *client);

    ClientDev *client(const unsigned int id);

    virtual void InitialClientDev();

private slots:

    void initialProperty();

signals:

private:



    QMap<unsigned int, ClientDev *> clientdevlist;
    QMap<unsigned int, QThread *> threadlist;

};

#endif // SERVICEDEV_H
