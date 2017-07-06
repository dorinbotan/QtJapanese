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

#include "plaininputmethod.h"
#include "inputengine.h"
#include "inputcontext.h"

namespace QtVirtualKeyboard {

/*!
    \class QtVirtualKeyboard::PlainInputMethod
    \internal
*/

PlainInputMethod::PlainInputMethod(QObject *parent) :
    AbstractInputMethod(parent)
{
}

PlainInputMethod::~PlainInputMethod()
{
}

QList<InputEngine::InputMode> PlainInputMethod::inputModes(const QString &locale)
{
    Q_UNUSED(locale)
    // Supports all input modes
    return QList<InputEngine::InputMode>()
            << InputEngine::Latin
            << InputEngine::Numeric
            << InputEngine::Dialable
            << InputEngine::Pinyin;
}

bool PlainInputMethod::setInputMode(const QString &locale, InputEngine::InputMode inputMode)
{
    Q_UNUSED(locale)
    Q_UNUSED(inputMode)
    return true;
}

bool PlainInputMethod::setTextCase(InputEngine::TextCase textCase)
{
    Q_UNUSED(textCase)
    return true;
}

bool PlainInputMethod::keyEvent(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers)
{
    Q_UNUSED(key)
    Q_UNUSED(text)
    Q_UNUSED(modifiers)
    bool accept = false;
    return accept;
}

void PlainInputMethod::reset()
{
}

void PlainInputMethod::update()
{
}

} // namespace QtVirtualKeyboard
