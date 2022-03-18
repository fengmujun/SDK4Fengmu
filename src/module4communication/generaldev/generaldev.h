#ifndef GENERALDEV_H
#define GENERALDEV_H

#include <QObject>
#include "generaldev_global.h"

class GENERALDEV_EXPORT GeneralDev : public QObject
{
    Q_OBJECT
//    LOG4QT_DECLARE_QCLASS_LOGGER
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString hardwareversion READ hardwareversion WRITE setHardwareversion NOTIFY
               hardwareversionChanged)
    Q_PROPERTY(QString softwareversion READ softwareversion WRITE setSoftwareversion NOTIFY
               softwareversionChanged)
    Q_PROPERTY(bool used READ used WRITE setUsed NOTIFY usedChanged)

public:
    explicit GeneralDev(QObject *parent = nullptr);

    virtual ~GeneralDev();

    virtual void Initial();

    virtual void print();
    const QString &name() const;
    void setName(const QString &newName);

    const QString &hardwareversion() const;
    void setHardwareversion(const QString &newHardwareversion);

    const QString &softwareversion() const;
    void setSoftwareversion(const QString &newSoftwareversion);

    bool used() const;
    void setUsed(bool newUsed);

private slots:
    virtual void initialProperty();

signals:

    void nameChanged();

    void hardwareversionChanged();

    void softwareversionChanged();

    void usedChanged();

private:

    QString m_name;
    QString m_hardwareversion;
    QString m_softwareversion;
    bool m_used;
};

#endif // GENERALDEV_H
