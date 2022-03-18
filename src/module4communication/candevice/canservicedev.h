#ifndef CANSERVICEDEV_H
#define CANSERVICEDEV_H

#include "servicedev.h"
#include <QObject>
//#include <QCanBusDevice>
#include "candevice_global.h"
class CanDevice;
class QCanBusDevice;
//class CanBusDeviceInfo;
class QCanBusFrame;

class CANDEVICE_EXPORT CanServiceDev : public ServiceDev
{
    Q_OBJECT

    Q_PROPERTY(QCanBusDevice *canServicePrivider READ canServicePrivider WRITE setCanServicePrivider
               NOTIFY canServicePrividerChanged)
public:
    explicit CanServiceDev(QObject *parent = nullptr);
    ~CanServiceDev();

    bool open();
    void close();

    bool sendmsg(const QCanBusFrame &msg);

    QCanBusDevice *canServicePrivider() const;
    void setCanServicePrivider(QCanBusDevice *newCanServicePrivider);

private slots:

    void receivedmsg(const QCanBusFrame &msg);

    void reading();

    void initialProperty();

private:

    virtual int GetClientID(const QCanBusFrame &msg);

signals:

    void canServicePrividerChanged();

//    void msgReceived(const QCanBusFrame msg);

private:

    QThread *runner_;

    QCanBusDevice *m_canServicePrivider;

    static bool isreading;
    static bool iswriting;

    static constexpr int CANClientDevIDMASK = 0x0F;
};

#endif // CANSERVICEDEV_H
