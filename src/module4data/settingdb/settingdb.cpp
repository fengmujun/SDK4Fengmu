#include "settingdb.h"

SettingDB::SettingDB(QObject *parent)
    : QObject{parent}
{

}

SettingDB::SettingDB(QString fileName)
{
    Q_UNUSED(fileName)
}

int SettingDB::setValue(const QString &groupKey, const QString &key, const QString &value)
{
    Q_UNUSED(groupKey)
    Q_UNUSED(key)
    Q_UNUSED(value)

    return 0;
}

int SettingDB::getValue(const QString &groupKey, const QString &key, QString &value,
                        const QString &defaultValue)
{
    Q_UNUSED(groupKey)
    Q_UNUSED(key)
    Q_UNUSED(value)
    Q_UNUSED(defaultValue)

    return 0;
}

int SettingDB::setValue(const QString &groupKey, const QString &key, const int &value)
{
    return setValue(groupKey, key, QString::number(value));
}

int SettingDB::getValue(const QString &groupKey, const QString &key, int &value,
                        const int &defaultValue)
{
    QString strValue;
    int rtn = getValue(groupKey, key, strValue, QString::number(defaultValue));
    value = strValue.toInt();
    return rtn;
}
