#ifndef SETTINGDB_H
#define SETTINGDB_H

#include <QObject>

#include "settingdb_global.h"

class SettingDB : public QObject
{
    Q_OBJECT
public:
    explicit SettingDB(QObject *parent = nullptr);

    SettingDB(QString fileName);


    virtual int setValue(const QString &groupKey, const QString &key, const QString &value);


    virtual int getValue(const QString &groupKey, const QString &key, QString &value,
                         const QString &defaultValue);


    virtual int setValue(const QString &groupKey, const QString &key, const int &value);


    virtual int getValue(const QString &groupKey, const QString &key, int &value,
                         const int &defaultValue);
signals:

};

#endif // SETTINGDB_H
