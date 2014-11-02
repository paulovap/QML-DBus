# Include this file in your .pro file to statically compile this Plugin
# plugin into your project.
#
# Basic usage instructions:
#
#  #include <plugin.h>
#
#  int main(int argc, char *argv[])
#  {
#      QApplication app(argc, argv);
#
#      Plugin plugin;
#      plugin.registerTypes("QML-DBus");
#
#      ...
#  }

INCLUDEPATH += $$PWD

DEPENDPATH += .

HEADERS += \
        $$PWD/declarativedbusadaptor.h \
        $$PWD/declarativedbus.h \
        $$PWD/declarativedbusinterface.h \
        $$PWD/plugin.h

SOURCES += \
        $$PWD/declarativedbusadaptor.cpp \
        $$PWD/declarativedbus.cpp \
        $$PWD/declarativedbusinterface.cpp \
        $$PWD/plugin.cpp
