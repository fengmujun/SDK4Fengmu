win32 {
    CompilerFLAG=amd64
    contains(DEFINES, WIN64) {
        SystemFLAG=win64
    } else {
        SystemFLAG=win32
    }

}else:unix {
#    target.path = /usr/lib

    CompilerFLAG=amd64
    SystemFLAG=unix

    linux-g++-32{
        CompilerFLAG=i386
    }

    linux-g++-64{
        CompilerFLAG=amd64
    }

    linux-g++{
        CompilerFLAG=amd64
    }

    linux-g++-mx{
        CompilerFLAG=mx
    }

    linux-arm-gnueabi-g++{
        CompilerFLAG=gnueabi
    }

    linux-oe-g++{
        CompilerFLAG=oe
        equals(QT_VERSION,5.6.2): {
            CompilerFLAG=oe562
        }
    }

    unix{
        SystemFLAG=unix
        QMAKE_CXXFLAGS_RELEASE += -O3
    }

    INCLUDEPATH += /usr/include/libxml2
    LIBS += -L/usr/include/libxml2

}



target.path = $$PWD/output/$$CompilerFLAG/$$SystemFLAG


#INCLUDEPATH += $$PWD/includes/3rd_zlgcan/zlgcan
#LIBS += -L$$PWD/libs/3rd_zlgcan
#win32 {
#    LIBS += -L$$PWD/libs/3rd_zlgcan/kerneldlls
#}
##canfile.files += $$PWD/libs/3rd_zlgcan
##canfile.path += $$target.path

#"build-%{Project:Name}-%{Kit:FileSystemName}-%{BuildConfig:Name}")}
INCLUDEPATH += $$PWD/Log4Qt/src/
#LIBS += -L$$PWD/3rd/build-log4qt-$$FileSystemName-%{BuildConfig:Name}/bin/ -llog4qt
##log4qtfile.files += $$PWD/libs/3rd_log4qt
##log4qtfile.path += $$target.path




#INCLUDEPATH += $$PWD/$$CompilerFLAG/$$SystemFLAG
#LIBS += -L$$PWD/$$CompilerFLAG/$$SystemFLAG
INCLUDEPATH += $$target.path
LIBS +=-L$$target.path
DESTDIR = $$target.path

#!isEmpty(target.path): INSTALLS += target canfile qwtfile log4qtfile gslfile lisfile

#message($$INSTALLS)

#CONFIG += console




