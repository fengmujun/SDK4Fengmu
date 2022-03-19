#include "basicobject.h"

BasicObject::BasicObject(QObject *parent)
    : QObject{parent}
{
    initialProperty();
}

BasicObject::~BasicObject()
{

}

bool BasicObject::zero()
{

}

bool BasicObject::move(const int &pos, MOVEMODE movemode)
{
    Q_UNUSED(movemode)

    bool RTN = false;

    if (RTN) {
        int tmpvalue = currentpos();
        setLastpos(tmpvalue);
        setCurrentpos(pos);
    }
    return RTN;
}

int BasicObject::addcmd(int cmd, int value, QString strcmd)
{

}

bool BasicObject::removecomd(QString strcmd)
{

}

int BasicObject::sendcmd(QString strcmd, int value)
{

}

int BasicObject::currentpos() const
{
    return m_currentpos;
}

void BasicObject::setCurrentpos(int newCurrentpos)
{
    if (m_currentpos == newCurrentpos)
        return;

    if ((newCurrentpos < min()) || (newCurrentpos > max()))
        return;

    m_currentpos = newCurrentpos;
    emit currentposChanged();
}

int BasicObject::lastpos() const
{
    return m_lastpos;
}

void BasicObject::setLastpos(int newLastpos)
{
    if (m_lastpos == newLastpos)
        return;
    m_lastpos = newLastpos;
    emit lastposChanged();
}

void BasicObject::initialProperty()
{
    m_currentpos = 0;
    m_lastpos = 0;
    m_max = 100;
    m_min = 0;
    m_name = "";
    m_ID = 0;

}

int BasicObject::max() const
{
    return m_max;
}

void BasicObject::setMax(int newMax)
{
    if (m_max == newMax)
        return;
    m_max = newMax;
    emit maxChanged();
}

int BasicObject::min() const
{
    return m_min;
}

void BasicObject::setMin(int newMin)
{
    if (m_min == newMin)
        return;
    m_min = newMin;
    emit minChanged();
}

const QString &BasicObject::name() const
{
    return m_name;
}

void BasicObject::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

int BasicObject::ID() const
{
    return m_ID;
}

void BasicObject::setID(int newID)
{
    if (m_ID == newID)
        return;
    m_ID = newID;
    emit IDChanged();
}

