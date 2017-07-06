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

#ifndef SELECTIONLISTMODEL_H
#define SELECTIONLISTMODEL_H

#include <QAbstractListModel>

namespace QtVirtualKeyboard {

class AbstractInputMethod;
class InputEngine;
class SelectionListModelPrivate;

class SelectionListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(Type)
    Q_ENUMS(Role)
    Q_DECLARE_PRIVATE(SelectionListModel)

    explicit SelectionListModel(QObject *parent = 0);

public:
    enum Type
    {
        WordCandidateList = 0
    };
    enum Role
    {
        DisplayRole = Qt::DisplayRole,
        WordCompletionLengthRole = Qt::UserRole + 1
    };

    ~SelectionListModel();
    void setDataSource(AbstractInputMethod *dataSource, Type type);
    AbstractInputMethod *dataSource() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int,QByteArray> roleNames() const;

    Q_INVOKABLE void selectItem(int index);
    Q_INVOKABLE QVariant dataAt(int index, int role = Qt::DisplayRole) const;

signals:
    void activeItemChanged(int index);
    void itemSelected(int index);

protected slots:
    void selectionListChanged(int type);
    void selectionListActiveItemChanged(int type, int index);

private:
    friend class InputEngine;
};

} // namespace QtVirtualKeyboard

Q_DECLARE_METATYPE(QtVirtualKeyboard::SelectionListModel::Type)
Q_DECLARE_METATYPE(QtVirtualKeyboard::SelectionListModel::Role)

#endif // SELECTIONLISTMODEL_H
