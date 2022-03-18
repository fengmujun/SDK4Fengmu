#include "candevice.h"
#include <QCanBusFrame>
#include "canservicedev.h"

CanDevice::CanDevice(unsigned int id, QObject *parent)
    : ClientDev{id, parent}
{
    initialProperty();
}

CanDevice::~CanDevice()
{
    delete msgqueue;
    delete msghighpriorityqueue;
}

void CanDevice::msgParser(const QCanBusFrame &msg)
{
    msg.frameId();
    msg.payload();
}

void CanDevice::msgRecieved(const QCanBusFrame &msg)
{
    if (isHighPriorityMsg(msg)) {
        QMutexLocker locker(&mutexhighpriority);
        msghighpriorityqueue->append(msg);

    } else {
        QMutexLocker locker(&mutex);
        msgqueue->append(msg);
    }

    emit toCheckMsgQueue();

}

void CanDevice::checkMsgQueue()
{
    QCanBusFrame msglocal;
    int emptyflag = 0;

    while (true) {
        emptyflag = 0;
        emptyflag += (msgqueue->empty() ? 0 : 1);
        emptyflag += (msghighpriorityqueue->empty() ? 0 : 2);

        if (0 == emptyflag)
            break;

        if (2 == (emptyflag & 2)) {
            QMutexLocker locker(&mutexhighpriority);
            msglocal = msghighpriorityqueue->front();
            msghighpriorityqueue->pop_front();
        } else if (1 == (emptyflag & 1)) {
            QMutexLocker locker(&mutex);
            msglocal = msgqueue->front();
            msgqueue->pop_front();
        } else
            continue;

        emit forward(msglocal);
    }

    return;
}

void CanDevice::initialProperty()
{
    msgqueue = new QList<QCanBusFrame>();
    msghighpriorityqueue = new QList<QCanBusFrame>();

    connect(this, &CanDevice::toCheckMsgQueue, this, &CanDevice::checkMsgQueue);
    connect(this, &CanDevice::forward, this, &CanDevice::msgParser);

    return;
}

bool CanDevice::isHighPriorityMsg(const QCanBusFrame &msg)
{
    Q_UNUSED(msg);
    return false;
}

bool CanDevice::sendmsg(const QCanBusFrame &msg)
{
    CanServiceDev *server = dynamic_cast<CanServiceDev *>(this->server());
    return server->sendmsg(msg);
}
