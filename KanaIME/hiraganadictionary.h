#ifndef HIRAGANADICTIONARY_H
#define HIRAGANADICTIONARY_H

#include <QStringList>
#include <QDebug>
#include <QList>

class HiraganaDictionary
{
public:
    HiraganaDictionary();

    enum vowels {
        a, i, u, e, o
    };

    enum consonants {
        k, s, t
    };

    QString x[2][2] = {
        { "1", "2" },
        { "1" }
    };
};

#endif // HIRAGANADICTIONARY_H
