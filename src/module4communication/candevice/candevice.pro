include(../../../SDK4Fengmu.pri)

QT += core serialbus

TEMPLATE = lib
DEFINES += CANDEVICE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    candevice.cpp \
    canservicedev.cpp

HEADERS += \
    candevice_global.h \
    candevice.h \
    canservicedev.h


INCLUDEPATH += ../generaldev
LIBS += -lgeneraldev
