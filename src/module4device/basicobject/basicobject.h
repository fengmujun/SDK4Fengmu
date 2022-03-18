#ifndef BASICOBJECT_H
#define BASICOBJECT_H

#include <QObject>

class BasicObject : public QObject
{
    Q_OBJECT


    Q_PROPERTY(int currentpos READ currentpos WRITE setCurrentpos NOTIFY currentposChanged)
    Q_PROPERTY(int lastpos READ lastpos WRITE setLastpos NOTIFY lastposChanged)
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged)
    Q_PROPERTY(int min READ min WRITE setMin NOTIFY minChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int ID READ ID WRITE setID NOTIFY IDChanged)

    Q_PROPERTY(int cmdSetABS READ cmSetdABS WRITE setCmdSetABS NOTIFY cmdSetABSChanged)
    Q_PROPERTY(int cmdSetPos READ cmdSetPos WRITE setCmdSetPos NOTIFY cmdSetPosChanged)
    Q_PROPERTY(int cmdGetPos READ cmdGetPos WRITE setCmdGetPos NOTIFY cmdGetPosChanged)
    Q_PROPERTY(int cmdZero READ cmdZero WRITE setCmdZero NOTIFY cmdZeroChanged)
    Q_PROPERTY(int cmdMove READ cmdMove WRITE setCmdMove NOTIFY cmdMoveChanged)
    Q_PROPERTY(int cmdTrigger READ cmdTrigger WRITE setCmdTrigger NOTIFY cmdTriggerChanged)


public:
    enum DIRECTION {
        POSITIVE = 0,
        NEGATIVE
    };

    Q_ENUM(DIRECTION)

    enum MOVEMODE {
        ABSOLUTE = 0,
        RELATIVE
    };

    Q_ENUM(MOVEMODE)

    explicit BasicObject(QObject *parent = nullptr);

    virtual ~BasicObject();

    virtual bool zero();

    virtual bool move(const int &pos, MOVEMODE movemode = ABSOLUTE);

    int currentpos() const;
    void setCurrentpos(int newCurrentpos);

    int lastpos() const;
    void setLastpos(int newLastpos);

    int max() const;
    void setMax(int newMax);

    int min() const;
    void setMin(int newMin);

    const QString &name() const;
    void setName(const QString &newName);

    int ID() const;
    void setID(int newID);

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

private:

    virtual void initialProperty();

signals:

    void currentposChanged();

    void lastposChanged();

    void maxChanged();

    void minChanged();

    void nameChanged();

    void IDChanged();

    void cmdSetABSChanged();

    void cmdSetPosChanged();

    void cmdGetPosChanged();

    void cmdZeroChanged();

    void cmdMoveChanged();

    void cmdTriggerChanged();

private:
    int m_currentpos;
    int m_lastpos;
    int m_max;
    int m_min;
    QString m_name;
    int m_ID;
    int m_cmdSetABS;
    int m_cmdSetPos;
    int m_cmdGetPos;
    int m_cmdZero;
    int m_cmdMove;
    int m_cmdTrigger;
};

#endif // BASICOBJECT_H
