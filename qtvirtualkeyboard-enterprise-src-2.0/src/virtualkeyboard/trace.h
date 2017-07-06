/******************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Virtual Keyboard module.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
******************************************************************************/

#ifndef TRACE_H
#define TRACE_H

#include <QObject>
#include <QVariant>
#include <QPointF>

namespace QtVirtualKeyboard {

class TracePrivate;

class Trace : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Trace)
    Q_PROPERTY(int traceId READ traceId WRITE setTraceId NOTIFY traceIdChanged)
    Q_PROPERTY(QStringList channels READ channels WRITE setChannels NOTIFY channelsChanged)
    Q_PROPERTY(int length READ length NOTIFY lengthChanged)
    Q_PROPERTY(bool isFinal READ isFinal WRITE setFinal NOTIFY finalChanged)
    Q_PROPERTY(bool isCanceled READ isCanceled WRITE setCanceled NOTIFY canceledChanged)
public:
    explicit Trace(QObject *parent = 0);
    ~Trace();

    int traceId() const;
    void setTraceId(int id);

    QStringList channels() const;
    void setChannels(const QStringList &channels);

    int length() const;

    Q_INVOKABLE QVariantList points(int pos = 0, int count = -1) const;
    Q_INVOKABLE int addPoint(const QPointF &point);

    Q_INVOKABLE void setChannelData(const QString &channel, int index, const QVariant &data);
    Q_INVOKABLE QVariantList channelData(const QString &channel, int pos = 0, int count = -1) const;

    bool isFinal() const;
    void setFinal(bool final);

    bool isCanceled() const;
    void setCanceled(bool canceled);

signals:
    void traceIdChanged(int traceId);
    void channelsChanged();
    void lengthChanged(int length);
    void finalChanged(bool isFinal);
    void canceledChanged(bool isCanceled);
};

} // namespace QtVirtualKeyboard

#endif // TRACE_H
