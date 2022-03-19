//basicobject with basic params set and get fuction
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

private:

    virtual void initialProperty();

signals:

    void currentposChanged();

    void lastposChanged();

    void maxChanged();

    void minChanged();

    void nameChanged();

    void IDChanged();

private:
    int m_currentpos;
    int m_lastpos;
    int m_max;
    int m_min;
    QString m_name;
    int m_ID;
};

#endif // BASICOBJECT_H
