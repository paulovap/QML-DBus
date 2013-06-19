/****************************************************************************************
**
** Copyright (C) 2013 Jolla Ltd.
** Contact: Andrew den Exter <andrew.den.exter@jollamobile.com>
** All rights reserved.
**
** You may use this file under the terms of the GNU Lesser General
** Public License version 2.1 as published by the Free Software Foundation
** and appearing in the file license.lgpl included in the packaging
** of this file.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file license.lgpl included in the packaging
** of this file.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Lesser General Public License for more details.
** 
****************************************************************************************/

#ifndef DECLARATIVEDBUSINTERFACE_H
#define DECLARATIVEDBUSINTERFACE_H

#include <QObject>
#include <QMap>
#include <QPair>
#include <QPointer>

QT_BEGIN_NAMESPACE
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
class QJSValue;
#define QScriptValue QJSValue
#else
class QScriptValue;
#endif

class QUrl;
class QDBusPendingCallWatcher;
QT_END_NAMESPACE

class DeclarativeDBusInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString iface READ interface WRITE setInterface NOTIFY interfaceChanged)
    Q_PROPERTY(BusType busType READ busType WRITE setBusType NOTIFY busTypeChanged)

    Q_ENUMS(BusType)

public:
    DeclarativeDBusInterface(QObject *parent = 0);
    ~DeclarativeDBusInterface();

    QString destination() const;
    void setDestination(const QString &destination);

    QString path() const;
    void setPath(const QString &path);

    QString interface() const;
    void setInterface(const QString &interface);

    enum BusType {
        SystemBus,
        SessionBus
    };

    BusType busType() const;
    void setBusType(BusType busType);

    Q_INVOKABLE void call(const QString &method, const QScriptValue &arguments);
    Q_INVOKABLE void typedCall(const QString &method, const QScriptValue &arguments);

    Q_INVOKABLE void typedCallWithReturn(const QString &method, const QScriptValue &arguments,
                                         const QScriptValue &callback);

signals:
    void destinationChanged();
    void pathChanged();
    void interfaceChanged();
    void busTypeChanged();

private slots:
    void pendingCallFinished(QDBusPendingCallWatcher *watcher);

private:
    QString m_destination;
    QString m_path;
    QString m_interface;
    BusType m_busType;
    QMap<QDBusPendingCallWatcher *, QScriptValue> m_pendingCalls;
};

#endif
