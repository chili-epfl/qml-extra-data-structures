TEMPLATE = lib
TARGET = qmlextradatastructuresplugin

CONFIG += qt plugin c++11
CONFIG -= android_install

QT += qml quick

unix{
    QMAKE_CXXFLAGS -= -O2
    QMAKE_CXXFLAGS_RELEASE -= -O2

    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS_RELEASE += -O3
}

TARGET = $$qtLibraryTarget($$TARGET)
uri = QMLExtraDataStructures

HEADERS += \
    src/QMLExtraDataStructuresPlugin.h \
    src/CircularBuffer.h \
    src/AssociativeArray.h \
    src/Queue.h

SOURCES += \
    src/QMLExtraDataStructuresPlugin.cpp \
    src/CircularBuffer.cpp \
    src/AssociativeArray.cpp \
    src/Queue.cpp

OTHER_FILES += qmldir qml.files

QML_SOURCES = \
    src/RepeaterList.qml

#Install plugin library, qmldir, qml sources
qmldir.files = qmldir
qml.files = $$QML_SOURCES
installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
qmldir.path = $$installPath
qml.path = $$installPath
target.path = $$installPath
INSTALLS += target qmldir qml
