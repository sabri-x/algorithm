QT -= gui

win32 {
    LIBDIR = ../../build/lib_win/
}
else {
    LIBDIR = ../../build/lib/
}

TEMPLATE = lib
TARGET = $$qtLibraryTarget(sabricore)
DESTDIR = $$LIBDIR
DEFINES += CORE_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    core.cpp

HEADERS += \
    core_global.h \
    core.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
