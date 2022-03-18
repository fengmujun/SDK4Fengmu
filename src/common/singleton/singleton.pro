include(../../../SDK4Fengmu.pri)
QT -= gui

TEMPLATE = lib
DEFINES += SINGLETON_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    demosingleton.cpp \
    demosinglettont.cpp

HEADERS += \
    demosingleton.h \
    demosinglettont.h \
    singleton_global.h \
    singleton.h \
    singletont.h

