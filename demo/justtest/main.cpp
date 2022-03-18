//#include <QCoreApplication>
#include <QApplication>
#include "candevice.h"
#include "canservicedev.h"
#include <QCanBusDevice>
#include <QCanBus>
#include <QCanBusFrame>
#include <QPair>
#include <QVariant>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CanServiceDev *server = new CanServiceDev();

    QString errorString;
    QCanBusDevice *candevice = QCanBus::instance()->createDevice(
                                   QStringLiteral("virtualcan"),
                                   QStringLiteral("can0"),
                                   &errorString);

    QPair<QCanBusDevice::ConfigurationKey, QVariant> item;
    item.first = QCanBusDevice::ReceiveOwnKey;
    item.second = true;

    candevice->setConfigurationParameter(item.first, item.second);
    candevice->connectDevice();

    server->setCanServicePrivider(candevice);

    CanDevice *can = new CanDevice(0);
    server->reg(can);

    QCanBusFrame msg(12, QByteArray::number(34));

    can->sendmsg(msg);

//    delete candevice;
//    delete server;

    return a.exec();
}
