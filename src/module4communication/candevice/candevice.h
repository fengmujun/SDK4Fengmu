#ifndef CANDEVICE_H
#define CANDEVICE_H

#include "clientdev.h"
#include <QObject>
#include <QList>
#include <QMutex>

#include "candevice_global.h"

class CanServiceDev;
class QCanBusFrame;

class CANDEVICE_EXPORT CanDevice : public ClientDev
{
    Q_OBJECT
public:
    explicit CanDevice(unsigned int id, QObject *parent = nullptr);
    ~CanDevice();

    virtual void msgParser(const QCanBusFrame &msg);
    virtual void msgRecieved(const QCanBusFrame &msg);

signals:

    void toCheckMsgQueue();
    void forward(const QCanBusFrame &msg);

private slots:

    void checkMsgQueue();

    void initialProperty();

private:

    virtual bool isHighPriorityMsg(const QCanBusFrame &msg);

//protected:

public:

    bool sendmsg(const QCanBusFrame &msg);

private:

    QList<QCanBusFrame> *msgqueue;
    QList<QCanBusFrame> *msghighpriorityqueue;

    QMutex mutex;
    QMutex mutexhighpriority;

};

#endif // CANDEVICE_H
