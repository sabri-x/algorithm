QT += quick

win32 {
LIBDIR = ../../build/lib_win/
}
else {
LIBDIR = ../../build/lib/
}

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS
LIBS += -L$$LIBDIR -l$$qtLibraryTarget(sabricore)

SOURCES += \
        main.cpp \
        minterfacemag.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ../core

HEADERS += \
    minterfacemag.h
