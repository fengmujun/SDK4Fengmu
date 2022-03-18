#ifndef QSETTINGDB_H
#define QSETTINGDB_H

#include "settingdb.h"
#include <QObject>
#include <QSettings>
#include "settingdb_global.h"

class qSettingDB : public SettingDB
{
public:
    explicit qSettingDB(QObject *parent = nullptr);
    qSettingDB(QString fileName);

    virtual ~qSettingDB();


    virtual int setValue(const QString &groupKey, const QString &key, const QString &value);


    virtual int getValue(const QString &groupKey, const QString &key, QString &value,
                         const QString &defaultValue);


private:
    QSettings *db;
    QTextCodec *tc;
};

#endif // QSETTINGDB_H
