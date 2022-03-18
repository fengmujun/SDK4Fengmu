#include "servicedev.h"
#include <QThread>
#include "clientdev.h"

ServiceDev::ServiceDev(QObject *parent)
    : GeneralDev{parent}
{
    initialProperty();
}

ServiceDev::~ServiceDev()
{
    for (QMap<unsigned int, QThread *>::iterator it = threadlist.begin();
         it != threadlist.end(); it++) {
        it.value()->quit();
        it.value()->deleteLater();
    }

}

void ServiceDev::reg(ClientDev *client)
{
    clientdevlist.insert(client->ID(), client);
    client->setServer(this);

    QThread *thread4client = new QThread;
    client->moveToThread(thread4client);
    thread4client->start();

    threadlist.insert(client->ID(), thread4client);

}

ClientDev *ServiceDev::client(const unsigned int id)
{

    QMap<unsigned int, ClientDev *>::iterator it;
    it = clientdevlist.find(id);
    if (it != clientdevlist.end())
        return it.value();
    else
        return nullptr;
}

void ServiceDev::InitialClientDev()
{
    for (QMap<unsigned int, ClientDev *>::iterator it = clientdevlist.begin();
         it != clientdevlist.end(); it++) {
        it.value()->Initial();
    }
}

void ServiceDev::initialProperty()
{
    setName("service dev");

}
