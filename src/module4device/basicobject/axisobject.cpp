#include "axisobject.h"

AxisObject::AxisObject(QObject *parent)
    : BasicObject{parent}
{

}

bool AxisObject::zero()
{

}

bool AxisObject::move(const int &pos, MOVEMODE movemode)
{

}

void AxisObject::initialProperty()
{
    m_cmdSetABS = 11;
    m_cmdSetPos = 10;
    m_cmdGetPos = 12;
    m_cmdZero = 1;
    m_cmdMove = 2;
    m_cmdTrigger = 0x401;
}

int AxisObject::cmSetdABS() const
{
    return m_cmdSetABS;
}

void AxisObject::setCmdSetABS(int newCmdSetABS)
{
    if (m_cmdSetABS == newCmdSetABS)
        return;
    m_cmdSetABS = newCmdSetABS;
    emit cmdSetABSChanged();
}

int AxisObject::cmdSetPos() const
{
    return m_cmdSetPos;
}

void AxisObject::setCmdSetPos(int newCmdSetPos)
{
    if (m_cmdSetPos == newCmdSetPos)
        return;
    m_cmdSetPos = newCmdSetPos;
    emit cmdSetPosChanged();
}

int AxisObject::cmdGetPos() const
{
    return m_cmdGetPos;
}

void AxisObject::setCmdGetPos(int newCmdGetPos)
{
    if (m_cmdGetPos == newCmdGetPos)
        return;
    m_cmdGetPos = newCmdGetPos;
    emit cmdGetPosChanged();
}

int AxisObject::cmdZero() const
{
    return m_cmdZero;
}

void AxisObject::setCmdZero(int newCmdZero)
{
    if (m_cmdZero == newCmdZero)
        return;
    m_cmdZero = newCmdZero;
    emit cmdZeroChanged();
}

int AxisObject::cmdMove() const
{
    return m_cmdMove;
}

void AxisObject::setCmdMove(int newCmdMove)
{
    if (m_cmdMove == newCmdMove)
        return;
    m_cmdMove = newCmdMove;
    emit cmdMoveChanged();
}

int AxisObject::cmdTrigger() const
{
    return m_cmdTrigger;
}

void AxisObject::setCmdTrigger(int newCmdTrigger)
{
    if (m_cmdTrigger == newCmdTrigger)
        return;
    m_cmdTrigger = newCmdTrigger;
    emit cmdTriggerChanged();
}
