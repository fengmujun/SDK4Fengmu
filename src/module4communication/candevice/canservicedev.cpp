#include "canservicedev.h"
#include <QThread>
#include "candevice.h"
#include <QCanBusDevice>

bool CanServiceDev::isreading = true;
bool CanServiceDev::iswriting = true;

CanServiceDev::CanServiceDev(QObject *parent)
    : ServiceDev{parent}
{
    initialProperty();
}

CanServiceDev::~CanServiceDev()
{
    runner_->quit();
    runner_->deleteLater();
}

bool CanServiceDev::open()
{
    if (m_canServicePrivider == nullptr)
        return false;

    return m_canServicePrivider->connectDevice();
}

void CanServiceDev::close()
{
    if (m_canServicePrivider != nullptr)
        m_canServicePrivider->disconnectDevice();

}

bool CanServiceDev::sendmsg(const QCanBusFrame &msg)
{
    if (m_canServicePrivider == nullptr)
        return false;

    while (!iswriting) {
        QThread::sleep(1);
        continue;
    }

    if (QCanBusDevice::ConnectedState != m_canServicePrivider->state())
        m_canServicePrivider->connectDevice();

    return m_canServicePrivider->writeFrame(msg);
}

QCanBusDevice *CanServiceDev::canServicePrivider() const
{
    return m_canServicePrivider;
}

void CanServiceDev::setCanServicePrivider(QCanBusDevice *newCanServicePrivider)
{
    if (m_canServicePrivider == newCanServicePrivider)
        return;
    m_canServicePrivider = newCanServicePrivider;
    emit canServicePrividerChanged();
}

void CanServiceDev::receivedmsg(const QCanBusFrame &msg)
{
    int id = GetClientID(msg);
#ifdef FAQPCR_ADAPT

    id = 10 == id ? 7 :
         id; //测量模块id返回帧不是测量模块id，这是个问题，暂且这样应对
    id = 0 == id ? 1 : id; //z轴id返回帧不是1，暂且这样变更
    id = 0x0f == id ? 5 : id; //条杯托返回f，不是5

#endif

    ClientDev *dev = client(id);
    if (dev == nullptr) {
//no id suits that
        return;
    }

    CanDevice *device = dynamic_cast<CanDevice *>(dev);
    if (device == nullptr) {
        //no device suits
        return;
    }

    device->msgRecieved(msg);

}

void CanServiceDev::reading()
{
    QCanBusFrame msg;

#if 1
    while (isreading) {
        if (m_canServicePrivider == nullptr) {
            QThread::msleep(500);
            continue;
        }

        if (QCanBusDevice::ConnectedState !=  m_canServicePrivider->state()) {
            open();
        }

        if (0 == m_canServicePrivider->framesAvailable()) {
            QThread::usleep(100);
            continue;
        }

        msg = m_canServicePrivider->readFrame();
//        emit msgReceived(msg);
        receivedmsg(msg);
    }

#else

    if (m_canServicePrivider == nullptr)
        continue;
    while (m_canServicePrivider->framesAvailable()) {
        const QCanBusFrame msg = m_canServicePrivider->readFrame();
        receivedmsg(msg);
    }

#endif
}

void CanServiceDev::initialProperty()
{
    m_canServicePrivider = nullptr;
    runner_ = new QThread;
    this->moveToThread(runner_);
    connect(runner_, &QThread::started, this, &CanServiceDev::reading);
    runner_->start();


}

int CanServiceDev::GetClientID(const QCanBusFrame &msg)
{
    return msg.frameId()&CANClientDevIDMASK;
}
