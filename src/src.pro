TARGET = $$qtLibraryTarget(DBus)

TEMPLATE = lib
CONFIG += plugin

TARGETPATH = DBus
PLUGIN_IMPORT_PATH = dbus

QT += dbus qml
QT -= gui

API_VER=1.0

MOC_DIR = .moc
OBJECTS_DIR = .obj

contains(QT_CONFIG, reduce_exports): CONFIG += hide_symbols

INCLUDEPATH += .
include(dbus.pri)

importPath = $$[QT_INSTALL_QML]/$$replace(TARGETPATH, \\., /).$$API_VER
target.path = $${importPath}

qmldir.path = $${importPath}
qmldir.files += $$PWD/qmldir


INSTALLS += target qmldir

