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

#include "inputmethod.h"
#include "trace.h"
#include <QVariant>

namespace QtVirtualKeyboard {

/*!
    \qmltype InputMethod
    \instantiates QtVirtualKeyboard::InputMethod
    \inqmlmodule QtQuick.Enterprise.VirtualKeyboard
    \ingroup qtvirtualkeyboard-qml
    \brief Base type for creating input method in QML.

    The InputMethod type lets you create a custom input method
    which can be assigned to InputEngine.
*/

/*!
    \qmlproperty InputContext InputMethod::inputContext

    The input context.
*/

/*!
    \qmlproperty InputEngine InputMethod::inputEngine

    The input engine.
*/

/*!
    \qmlmethod list<int> InputMethod::inputModes(string locale)

    Returns a list of input modes for \a locale.
*/

/*!
    \qmlmethod bool InputMethod::setInputMode(string locale, int inputMode)

    Changes \a inputMode and \a locale for this input method. The method returns
    \c true if successful.
*/

/*!
    \qmlmethod bool InputMethod::setTextCase(int textCase)

    Updates \a textCase for this input method. The method returns \c true if
    successful.

    The possible values for the text case are:

    \list
        \li \c InputEngine.Lower Lower case text.
        \li \c InputEngine.Upper Upper case text.
    \endlist
*/

/*!
    \qmlmethod bool InputMethod::keyEvent(int key, string text, int modifiers)

    The purpose of this method is to handle the key events generated by the the
    input engine.

    The \a key parameter specifies the code of the key to handle. The key code
    does not distinguish between capital and non-capital letters. The \a
    text parameter contains the Unicode text for the key. The \a modifiers
    parameter contains the key modifiers that apply to \a key.

    This method returns \c true if the key event was successfully handled.
    If the return value is \c false, the key event is redirected to the default
    input method for futher processing.
*/

/*!
    \qmlmethod InputMethod::reset()

    This method is called by the input engine when this input method needs to be
    reset. The input method must reset its internal state only. The main
    difference to the update() method is that reset() modifies only
    the input method state; it must not modify the input context.
*/

/*!
    \qmlmethod InputMethod::update()

    This method is called by the input engine when the input method needs to be
    updated. The input method must close the current pre-edit text and
    restore the internal state to the default.
*/

/*!
    \qmlmethod list<int> InputMethod::selectionLists()

    Returns the list of selection types used for this input method.

    This method is called by the input engine when the input method is being
    activated. The input method can reserve the selection lists for its use
    by returning a list of selection list types required.
*/

/*!
    \qmlmethod int InputMethod::selectionListItemCount(int type)

    Returns the number of items in the selection list identified by \a type.
*/

/*!
    \qmlmethod var InputMethod::selectionListData(int type, int index, int role)

    Returns item data for a selection list identified by \a type. The \a role
    parameter specifies which data is requested. The \a index parameter is a
    zero based index into the selecteion list.
*/

/*!
    \qmlmethod void InputMethod::selectionListItemSelected(int type, int index)

    This method is called when an item at \a index has been selected by the
    user. The selection list is identified by the \a type parameter.
*/

/*!
    \qmlsignal InputMethod::selectionListChanged(int type)

    The input method emits this signal when the contents of the selection list
    are changed. The \a type parameter specifies which selection list has
    changed.
*/

/*!
    \qmlsignal InputMethod::selectionListActiveItemChanged(int type, int index)

    The input method emits this signal when the current \a index has changed
    in the selection list identified by \a type.
*/

/*!
    \qmlmethod list<int> InputMethod::patternRecognitionModes()
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    Returns list of supported pattern recognition modes.

    This method is invoked by the input engine to query the list of
    supported pattern recognition modes.
*/

/*!
    \qmlmethod Trace InputMethod::traceBegin(int traceId, int patternRecognitionMode, var traceCaptureDeviceInfo, var traceScreenInfo)
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    This method is called when a trace interaction starts with the specified \a patternRecognitionMode.
    The trace is uniquely identified by the \a traceId.
    The \a traceCaptureDeviceInfo provides information about the source device and the
    \a traceScreenInfo provides information about the screen context.

    If the input method accepts the event and wants to capture the trace input, it must return
    a new Trace object. This object must remain valid until the \l {InputMethod::traceEnd()}
    {InputMethod.traceEnd()} method is called. If the Trace is rendered on screen, it remains there
    until the Trace object is destroyed.
*/

/*!
    \qmlmethod bool InputMethod::traceEnd(Trace trace)
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    This method is called when the trace interaction ends. The input method should destroy the \a trace object
    at some point after this function is called. See the \l Trace API how to access the gathered
    data.
*/

/*!
    \qmlmethod bool InputMethod::reselect(int cursorPosition, int reselectFlags)
    \since QtQuick.Enterprise.VirtualKeyboard 2.0

    This method attempts to reselect a word located at the \a cursorPosition.
    The \a reselectFlags define the rules for how the word should be selected in
    relation to the cursor position.

    \list
        \li \c InputEngine.WordBeforeCursor Activate the word before the cursor. When this flag is used exclusively, the word must end exactly at the cursor.
        \li \c InputEngine.WordAfterCursor Activate the word after the cursor. When this flag is used exclusively, the word must start exactly at the cursor.
        \li \c InputEngine.WordAtCursor Activate the word at the cursor. This flag is a combination of the above flags with the exception that the word cannot start or stop at the cursor.
    \endlist

    The method returns \c true if the word was successfully reselected.
*/

/*!
    \class QtVirtualKeyboard::InputMethod
    \internal
*/

InputMethod::InputMethod(QObject *parent) :
    AbstractInputMethod(parent)
{
}

InputMethod::~InputMethod()
{
}

QList<InputEngine::InputMode> InputMethod::inputModes(const QString &locale)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "inputModes",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, locale));
    QList<InputEngine::InputMode> inputModeList;
    foreach (const QVariant &inputMode, result.toList()) {
        inputModeList.append(static_cast<InputEngine::InputMode>(inputMode.toInt()));
    }
    return inputModeList;
}

bool InputMethod::setInputMode(const QString &locale, InputEngine::InputMode inputMode)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "setInputMode",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, locale),
                              Q_ARG(QVariant, static_cast<int>(inputMode)));
    return result.toBool();
}

bool InputMethod::setTextCase(InputEngine::TextCase textCase)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "setTextCase",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, static_cast<int>(textCase)));
    return result.toBool();
}

bool InputMethod::keyEvent(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "keyEvent",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, key),
                              Q_ARG(QVariant, text),
                              Q_ARG(QVariant, (int)modifiers));
    return result.toBool();
}

QList<SelectionListModel::Type> InputMethod::selectionLists()
{
    QVariant result;
    QMetaObject::invokeMethod(this, "selectionLists",
                              Q_RETURN_ARG(QVariant, result));
    QList<SelectionListModel::Type> selectionListsList;
    foreach (const QVariant &selectionListType, result.toList()) {
        selectionListsList.append(static_cast<SelectionListModel::Type>(selectionListType.toInt()));
    }
    return selectionListsList;
}

int InputMethod::selectionListItemCount(SelectionListModel::Type type)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "selectionListItemCount",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, static_cast<int>(type)));
    return result.toInt();
}

QVariant InputMethod::selectionListData(SelectionListModel::Type type, int index, int role)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "selectionListData",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, static_cast<int>(type)),
                              Q_ARG(QVariant, index),
                              Q_ARG(QVariant, role));
    if (result.isNull()) {
        result = AbstractInputMethod::selectionListData(type, index, role);
    }
    return result;
}

void InputMethod::selectionListItemSelected(SelectionListModel::Type type, int index)
{
    QMetaObject::invokeMethod(this, "selectionListItemSelected",
                              Q_ARG(QVariant, static_cast<int>(type)),
                              Q_ARG(QVariant, index));
}

QList<InputEngine::PatternRecognitionMode> InputMethod::patternRecognitionModes() const
{
    QVariant result;
    QMetaObject::invokeMethod(const_cast<InputMethod *>(this), "patternRecognitionModes",
                              Q_RETURN_ARG(QVariant, result));
    QList<InputEngine::PatternRecognitionMode> patterRecognitionModeList;
    foreach (const QVariant &patterRecognitionMode, result.toList()) {
        patterRecognitionModeList.append(static_cast<InputEngine::PatternRecognitionMode>(patterRecognitionMode.toInt()));
    }
    return patterRecognitionModeList;
}

Trace *InputMethod::traceBegin(int traceId, InputEngine::PatternRecognitionMode patternRecognitionMode,
                               const QVariantMap &traceCaptureDeviceInfo, const QVariantMap &traceScreenInfo)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "traceBegin",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(int, traceId),
                              Q_ARG(int, (int)patternRecognitionMode),
                              Q_ARG(QVariant, traceCaptureDeviceInfo),
                              Q_ARG(QVariant, traceScreenInfo));
    return result.value<Trace *>();
}

bool InputMethod::traceEnd(Trace *trace)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "traceEnd",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(QVariant, QVariant::fromValue(trace)));
    return result.toBool();
}

bool InputMethod::reselect(int cursorPosition, const InputEngine::ReselectFlags &reselectFlags)
{
    QVariant result;
    QMetaObject::invokeMethod(this, "reselect",
                              Q_RETURN_ARG(QVariant, result),
                              Q_ARG(int, cursorPosition),
                              Q_ARG(int, (int)reselectFlags));
    return result.toBool();
}

void InputMethod::reset()
{
    QMetaObject::invokeMethod(this, "reset");
}

void InputMethod::update()
{
    QMetaObject::invokeMethod(this, "update");
}

} // namespace QtVirtualKeyboard
