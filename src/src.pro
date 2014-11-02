TARGET = qmldbus
PLUGIN_IMPORT_PATH = qml-dbus
QT += dbus qml

QT -= gui

TEMPLATE = lib
CONFIG += qt plugin hide_symbols

target.path = $$[QT_INSTALL_QML]/$$PLUGIN_IMPORT_PATH
INSTALLS += target

qmldir.files += $$_PRO_FILE_PWD_/qmldir
qmldir.path +=  $$target.path
INSTALLS += qmldir

SOURCES += \
    plugin.cpp \
    declarativedbus.cpp \
    declarativedbusadaptor.cpp \
    declarativedbusinterface.cpp

HEADERS += \
    declarativedbus.h \
    declarativedbusadaptor.h \
    declarativedbusinterface.h

MOC_DIR = $$PWD/.moc
OBJECTS_DIR = $$PWD/.obj
