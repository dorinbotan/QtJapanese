#ifndef OPENWNNINPUTMETHOD_H
#define OPENWNNINPUTMETHOD_H

#include "abstractinputmethod.h"

namespace QtVirtualKeyboard {

class OpenWnnInputMethodPrivate;

class OpenWnnInputMethod : public AbstractInputMethod
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(OpenWnnInputMethod)

public:
    explicit OpenWnnInputMethod(QObject *parent = 0);
    ~OpenWnnInputMethod();

    QList<InputEngine::InputMode> inputModes(const QString &locale);
    bool setInputMode(const QString &locale, InputEngine::InputMode inputMode);
    bool setTextCase(InputEngine::TextCase textCase);

    bool keyEvent(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers);

    QList<SelectionListModel::Type> selectionLists();
    int selectionListItemCount(SelectionListModel::Type type);
    QVariant selectionListData(SelectionListModel::Type type, int index, int role);
    void selectionListItemSelected(SelectionListModel::Type type, int index);

    void reset();
    void update();
};

} // namespace QtVirtualKeyboard

#endif
