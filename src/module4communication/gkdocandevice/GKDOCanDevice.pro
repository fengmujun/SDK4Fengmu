include(../../../SDK4Fengmu.pri)
QT -= gui

TEMPLATE = lib
DEFINES += GKDOCANDEVICE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gkdocandevice.cpp

HEADERS += \
    GKDOCanDevice_global.h \
    gkdocandevice.h

INCLUDEPATH += ../candevice
LIBS += -lcandevice

INCLUDEPATH += ../generaldev
LIBS += -lgeneraldev
