#include "clientdev.h"

ClientDev::ClientDev(unsigned int id, QObject *parent)
    : GeneralDev{parent}, m_ID(id)
{
    initialProperty();
}

unsigned int ClientDev::ID() const
{
    return m_ID;
}

void ClientDev::setID(unsigned int newID)
{
    if (m_ID == newID)
        return;
    m_ID = newID;
    emit IDChanged();
}

ServiceDev *ClientDev::server() const
{
    return m_server;
}

void ClientDev::setServer(ServiceDev *newServer)
{
    if (m_server == newServer)
        return;
    m_server = newServer;
    emit serverChanged();
}

void ClientDev::initialProperty()
{
    m_server = nullptr;
    m_ID = 0;
    setName("client dev");
}
