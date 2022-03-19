//basicobject with basic command set and get
#ifndef AXISOBJECT_H
#define AXISOBJECT_H

#include "basicobject.h"
#include <QObject>

class AxisObject : public BasicObject
{
    Q_OBJECT

    Q_PROPERTY(int cmdSetABS READ cmSetdABS WRITE setCmdSetABS NOTIFY cmdSetABSChanged)
    Q_PROPERTY(int cmdSetPos READ cmdSetPos WRITE setCmdSetPos NOTIFY cmdSetPosChanged)
    Q_PROPERTY(int cmdGetPos READ cmdGetPos WRITE setCmdGetPos NOTIFY cmdGetPosChanged)
    Q_PROPERTY(int cmdZero READ cmdZero WRITE setCmdZero NOTIFY cmdZeroChanged)
    Q_PROPERTY(int cmdMove READ cmdMove WRITE setCmdMove NOTIFY cmdMoveChanged)
    Q_PROPERTY(int cmdTrigger READ cmdTrigger WRITE setCmdTrigger NOTIFY cmdTriggerChanged)

public:
    explicit AxisObject(QObject *parent = nullptr);

    bool zero();

    bool move(const int &pos, MOVEMODE movemode = ABSOLUTE);

    int cmSetdABS() const;
    void setCmdSetABS(int newCmdSetABS);

    int cmdSetPos() const;
    void setCmdSetPos(int newCmdSetPos);

    int cmdGetPos() const;
    void setCmdGetPos(int newCmdGetPos);

    int cmdZero() const;
    void setCmdZero(int newCmdZero);

    int cmdMove() const;
    void setCmdMove(int newCmdMove);

    int cmdTrigger() const;
    void setCmdTrigger(int newCmdTrigger);

signals:
    void cmdSetABSChanged();

    void cmdSetPosChanged();

    void cmdGetPosChanged();

    void cmdZeroChanged();

    void cmdMoveChanged();

    void cmdTriggerChanged();

private:

    void initialProperty();

    int m_cmdSetABS;
    int m_cmdSetPos;
    int m_cmdGetPos;
    int m_cmdZero;
    int m_cmdMove;
    int m_cmdTrigger;
};

#endif // AXISOBJECT_H
