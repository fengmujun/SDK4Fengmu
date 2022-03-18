#include "generaldev.h"

GeneralDev::GeneralDev(QObject *parent)
    : QObject{parent}
{
    initialProperty();
}

GeneralDev::~GeneralDev()
{

}

void GeneralDev::Initial()
{

}

void GeneralDev::print()
{

}

void GeneralDev::initialProperty()
{
    m_name = QString("general device");
    m_hardwareversion = QString("0.0.0");
    m_softwareversion = QString("0.0.0");
    m_used = false;

}

const QString &GeneralDev::name() const
{
    return m_name;
}

void GeneralDev::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

const QString &GeneralDev::hardwareversion() const
{
    return m_hardwareversion;
}

void GeneralDev::setHardwareversion(const QString &newHardwareversion)
{
    if (m_hardwareversion == newHardwareversion)
        return;
    m_hardwareversion = newHardwareversion;
    emit hardwareversionChanged();
}

const QString &GeneralDev::softwareversion() const
{
    return m_softwareversion;
}

void GeneralDev::setSoftwareversion(const QString &newSoftwareversion)
{
    if (m_softwareversion == newSoftwareversion)
        return;
    m_softwareversion = newSoftwareversion;
    emit softwareversionChanged();
}

bool GeneralDev::used() const
{
    return m_used;
}

void GeneralDev::setUsed(bool newUsed)
{
    if (m_used == newUsed)
        return;
    m_used = newUsed;
    emit usedChanged();
}
