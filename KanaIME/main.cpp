#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include "kbdgrabber.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    KbdGrabber kdbGrabber;

    QDeclarativeView view;
    view.rootContext()->setContextProperty( "kdbGrabber", &kdbGrabber );
    view.setSource( QUrl( "main.qml" ) );
    view.show();

    return app.exec();
}

