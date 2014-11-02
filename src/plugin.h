#ifndef _PLUGINS_H_
#define _PLUGINS_H_

#include <QtCore/QtGlobal>
#include <QtQml/QQmlExtensionPlugin>

class Plugins : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "QML-DBUS")

public:
    void registerTypes(const char *uri);
};

#endif /* _PLUGINS_H_ */
