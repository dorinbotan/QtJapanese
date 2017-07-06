import QtQuick 1.1

Item {
    width: 600
    height: 300

    TextEdit {
        id: textEdit
        anchors.fill: parent
        font.pixelSize: 44
        wrapMode: Text.Wrap
        focus: true
        selectByMouse: true

        Keys.onPressed: kdbGrabber.keyPressed( text )
    }

    Connections {
        target: kdbGrabber
        onSetText: {
            textEdit.text = text
            textEdit.cursorPosition = textEdit.text.length
        }
    }
}
