TEMPLATE = app

QT += qml quick \
        multimedia
CONFIG += c++11

SOURCES += main.cpp \
    shape.cpp \
    game.cpp \
    directionenumqml.cpp \
    shapetypeenumqml.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    shape.h \
    game.h \
    directionenumqml.h \
    shapetypeenumqml.h

DISTFILES +=
