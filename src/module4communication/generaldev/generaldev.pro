include(../../../SDK4Fengmu.pri)
QT -= gui

TEMPLATE = lib
DEFINES += GENERALDEV_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientdev.cpp \
    generaldev.cpp \
    servicedev.cpp

HEADERS += \
    clientdev.h \
    generaldev_global.h \
    generaldev.h \
    servicedev.h
