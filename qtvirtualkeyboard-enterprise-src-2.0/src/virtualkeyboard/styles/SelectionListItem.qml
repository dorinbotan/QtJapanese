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

import QtQuick 2.0

/*!
    \qmltype SelectionListItem
    \inqmlmodule QtQuick.Enterprise.VirtualKeyboard.Styles
    \brief A base type for selection list item delegates.
    \ingroup qtvirtualkeyboard-styles-qml

    The SelectionListItem enables mouse handling for the selection list item
    delegates.
*/

Item {
    id: selectionListItem
    height: parent.height

    /*!
        \since QtQuick.Enterprise.VirtualKeyboard.Styles 1.1

        Sets the sound effect to be played on touch event.
    */
    property url soundEffect

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            if (index === -1)
                return
            selectionListItem.ListView.view.currentIndex = index
            selectionListItem.ListView.view.model.selectItem(index)
        }
    }
}
