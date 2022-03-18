#include "qsettingdb.h"
#include <QTextCodec>
#include <QBitArray>

qSettingDB::qSettingDB(QObject *parent)
    : SettingDB{parent}
{

}

qSettingDB::qSettingDB(QString fileName):
    SettingDB(fileName)
{
    tc = QTextCodec::codecForName("UTF-8");

    db = new QSettings(fileName, QSettings::IniFormat);

    db->setIniCodec(tc);

}

qSettingDB::~qSettingDB()
{
    db->sync();
    delete (db);
}

int qSettingDB::setValue(const QString &groupKey, const QString &key, const QString &value)
{
    QString localKey = groupKey;
    localKey.append("/").append(key);

    db->setValue(localKey, value);

    return 0;
}

int qSettingDB::getValue(const QString &groupKey, const QString &key, QString &value,
                         const QString &defaultValue)
{
    QString localKey = groupKey;
    localKey.append("/").append(key);

//    printf("Key = %s\n",localKey.toStdString().data());

    QVariant var = db->value(localKey, defaultValue);

    QByteArray ba = var.toByteArray();

    value = tc->toUnicode(ba);

    return 0;
}
