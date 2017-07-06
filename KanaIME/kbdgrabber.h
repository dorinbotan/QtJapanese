#ifndef KBDGRABBER_H
#define KBDGRABBER_H

#include <QWidget>
#include <QKeyEvent>

class KbdGrabber : public QWidget
{
    Q_OBJECT

public:
    KbdGrabber();
    Q_INVOKABLE void keyPressed( QString text );

signals:
    void setText( QString text );
};

#endif // KBDGRABBER_H
