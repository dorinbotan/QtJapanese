#include "kbdgrabber.h"

#include <QDebug>
#include <QTextCodec>

KbdGrabber::KbdGrabber()
{
}

void KbdGrabber::keyPressed( QString text )
{
    QChar x = text.at( text.length() - 1 ).toLower();
    QChar y = text.at( text.length() - 2 ).toLower();

    const wchar_t tmp = 0x4058f8;

    if( x == '.' )
        text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"。" ) );
    else if( x == 'a' )
        if( y == 'k' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"か" ) );
        else if( y == 's' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"さ" ) );
        else if( y == 't' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"た" ) );
        else if( QString::fromWCharArray( L"ん" ).compare( y ) == 0 )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"な" ) );
        else if( y == 'h' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"は" ) );
        else if( y == 'm' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ま" ) );
        else if( y == 'y' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"や" ) );
        else if( y == 'r' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ら" ) );
        else if( y == 'w' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"わ" ) );
        else if( y == 'q' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"くぁ" ) );
        else
            text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"あ" ) );
    else if( x == 'i' )
        if( y == 'k' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"き" ) );
        else if( y == 's' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"し" ) );
        else if( y == 't' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ち" ) );
        else if( QString::fromWCharArray( L"ん" ).compare( y ) == 0 )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"に" ) );
        else if( y == 'h' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ひ" ) );
        else if( y == 'm' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"み" ) );
        else if( y == 'y' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"い" ) );
        else if( y == 'r' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"り" ) );
        else if( y == 'w' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ゐ" ) );
        else if( y == 'q' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"くぃ" ) );
        else
            text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"い" ) );
    else if( x == 'u' )
        if( y == 'k' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"く" ) );
        else if( y == 's' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"す" ) );
        else if( y == 't' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"つ" ) );
        else if( QString::fromWCharArray( L"ん" ).compare( y ) == 0 )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ぬ" ) );
        else if( y == 'h' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ふ" ) );
        else if( y == 'm' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"む" ) );
        else if( y == 'y' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ゆ" ) );
        else if( y == 'r' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"る" ) );
        else if( y == 'w' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"う" ) );
        else if( y == 'q' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"く" ) );
        else
            text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"う" ) );
    else if( x == 'e' )
        if( y == 'k' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"け" ) );
        else if( y == 's' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"せ" ) );
        else if( y == 't' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"て" ) );
        else if( QString::fromWCharArray( L"ん" ).compare( y ) == 0 )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ね" ) );
        else if( y == 'h' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"へ" ) );
        else if( y == 'm' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"め" ) );
        else if( y == 'r' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"れ" ) );
        else if( y == 'w' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ゑ" ) );
        else if( y == 'q' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"くぇ" ) );
        else
            text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"え" ) );
    else if( x == 'o' )
        if( y == 'k' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"こ" ) );
        else if( y == 's' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"そ" ) );
        else if( y == 't' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"と" ) );
        else if( QString::fromWCharArray( L"ん" ).compare( y ) == 0 )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"の" ) );
        else if( y == 'h' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ほ" ) );
        else if( y == 'm' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"も" ) );
        else if( y == 'y' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"よ" ) );
        else if( y == 'r' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"ろ" ) );
        else if( y == 'w' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"を" ) );
        else if( y == 'q' )
            text = text.replace( text.length() - 2, 2, QString::fromWCharArray( L"くぉ" ) );
        else
            text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"お" ) );
    else if( x == 'n' )
        text = text.replace( text.length() - 1, 1, QString::fromWCharArray( L"ん" ) );

    qDebug() << L"ん";
    qDebug() << QString("\u3042");
    qDebug() << tmp;

    emit setText( text );
}
