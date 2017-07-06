#include "kanaconverter.h"

#include <QMap>
#include <QString>

class KanaConverterPrivate
{
public:
    static QMap<QString, QString> initHalfKatakanaMap()
    {
        QMap<QString, QString> map;
        map.insert( QLatin1String( "\u3042" ), QLatin1String( "\uff71" ) ); /// あ ｱ
        map.insert( QLatin1String( "\u3044" ), QLatin1String( "\uff72" ) ); /// い ｲ
        map.insert( QLatin1String( "\u3046" ), QLatin1String( "\uff73" ) ); /// う ｳ
        map.insert( QLatin1String( "\u3048" ), QLatin1String( "\uff74" ) ); /// え ｴ
        map.insert( QLatin1String( "\u304a" ), QLatin1String( "\uff75" ) ); /// お ｵ
        map.insert( QLatin1String( "\u3041" ), QLatin1String( "\uff67" ) ); /// ぁ ｧ
        map.insert( QLatin1String( "\u3043" ), QLatin1String( "\uff68" ) ); /// ぃ ｨ
        map.insert( QLatin1String( "\u3045" ), QLatin1String( "\uff69" ) ); /// ぅ ｩ
        map.insert( QLatin1String( "\u3047" ), QLatin1String( "\uff6a" ) ); /// ぇ ｪ
        map.insert( QLatin1String( "\u3049" ), QLatin1String( "\uff6b" ) ); /// ぉ ｫ
//        map.insert( QLatin1String( "\u30f4\u3041" ), QLatin1String( "\uff73\uff9e\uff67" ) );
//        map.insert( QLatin1String( "\u30f4\u3043" ), QLatin1String( "\uff73\uff9e\uff68" ) );
        map.insert( QLatin1String( "\u30f4" ), QLatin1String( "\uff73\uff9e" ) ); /// ヴ ｳﾞ
//        map.insert( QLatin1String( "\u30f4\u3047" ), QLatin1String( "\uff73\uff9e\uff6a" ) );
//        map.insert( QLatin1String( "\u30f4\u3049" ), QLatin1String( "\uff73\uff9e\uff6b" ) );
        map.insert( QLatin1String( "\u304b" ), QLatin1String( "\uff76" ) ); /// か ｶ
        map.insert( QLatin1String( "\u304d" ), QLatin1String( "\uff77" ) ); /// き ｷ
        map.insert( QLatin1String( "\u304f" ), QLatin1String( "\uff78" ) ); /// く ｸ
        map.insert( QLatin1String( "\u3051" ), QLatin1String( "\uff79" ) ); /// け ｹ
        map.insert( QLatin1String( "\u3053" ), QLatin1String( "\uff7a" ) );
        map.insert( QLatin1String( "\u304c" ), QLatin1String( "\uff76\uff9e" ) );
        map.insert( QLatin1String( "\u304e" ), QLatin1String( "\uff77\uff9e" ) );
        map.insert( QLatin1String( "\u3050" ), QLatin1String( "\uff78\uff9e" ) );
        map.insert( QLatin1String( "\u3052" ), QLatin1String( "\uff79\uff9e" ) );
        map.insert( QLatin1String( "\u3054" ), QLatin1String( "\uff7a\uff9e" ) );
        map.insert( QLatin1String( "\u3055" ), QLatin1String( "\uff7b" ) );
        map.insert( QLatin1String( "\u3057" ), QLatin1String( "\uff7c" ) );
        map.insert( QLatin1String( "\u3059" ), QLatin1String( "\uff7d" ) );
        map.insert( QLatin1String( "\u305b" ), QLatin1String( "\uff7e" ) );
        map.insert( QLatin1String( "\u305d" ), QLatin1String( "\uff7f" ) );
        map.insert( QLatin1String( "\u3056" ), QLatin1String( "\uff7b\uff9e" ) );
        map.insert( QLatin1String( "\u3058" ), QLatin1String( "\uff7c\uff9e" ) );
        map.insert( QLatin1String( "\u305a" ), QLatin1String( "\uff7d\uff9e" ) );
        map.insert( QLatin1String( "\u305c" ), QLatin1String( "\uff7e\uff9e" ) );
        map.insert( QLatin1String( "\u305e" ), QLatin1String( "\uff7f\uff9e" ) );
        map.insert( QLatin1String( "\u305f" ), QLatin1String( "\uff80" ) );
        map.insert( QLatin1String( "\u3061" ), QLatin1String( "\uff81" ) );
        map.insert( QLatin1String( "\u3064" ), QLatin1String( "\uff82" ) );
        map.insert( QLatin1String( "\u3066" ), QLatin1String( "\uff83" ) );
        map.insert( QLatin1String( "\u3068" ), QLatin1String( "\uff84" ) );
        map.insert( QLatin1String( "\u3063" ), QLatin1String( "\uff6f" ) );
        map.insert( QLatin1String( "\u3060" ), QLatin1String( "\uff80\uff9e" ) );
        map.insert( QLatin1String( "\u3062" ), QLatin1String( "\uff81\uff9e" ) );
        map.insert( QLatin1String( "\u3065" ), QLatin1String( "\uff82\uff9e" ) );
        map.insert( QLatin1String( "\u3067" ), QLatin1String( "\uff83\uff9e" ) );
        map.insert( QLatin1String( "\u3069" ), QLatin1String( "\uff84\uff9e" ) );
        map.insert( QLatin1String( "\u306a" ), QLatin1String( "\uff85" ) );
        map.insert( QLatin1String( "\u306b" ), QLatin1String( "\uff86" ) );
        map.insert( QLatin1String( "\u306c" ), QLatin1String( "\uff87" ) );
        map.insert( QLatin1String( "\u306d" ), QLatin1String( "\uff88" ) );
        map.insert( QLatin1String( "\u306e" ), QLatin1String( "\uff89" ) );
        map.insert( QLatin1String( "\u306f" ), QLatin1String( "\uff8a" ) );
        map.insert( QLatin1String( "\u3072" ), QLatin1String( "\uff8b" ) );
        map.insert( QLatin1String( "\u3075" ), QLatin1String( "\uff8c" ) );
        map.insert( QLatin1String( "\u3078" ), QLatin1String( "\uff8d" ) );
        map.insert( QLatin1String( "\u307b" ), QLatin1String( "\uff8e" ) );
        map.insert( QLatin1String( "\u3070" ), QLatin1String( "\uff8a\uff9e" ) );
        map.insert( QLatin1String( "\u3073" ), QLatin1String( "\uff8b\uff9e" ) );
        map.insert( QLatin1String( "\u3076" ), QLatin1String( "\uff8c\uff9e" ) );
        map.insert( QLatin1String( "\u3079" ), QLatin1String( "\uff8d\uff9e" ) );
        map.insert( QLatin1String( "\u307c" ), QLatin1String( "\uff8e\uff9e" ) );
        map.insert( QLatin1String( "\u3071" ), QLatin1String( "\uff8a\uff9f" ) );
        map.insert( QLatin1String( "\u3074" ), QLatin1String( "\uff8b\uff9f" ) );
        map.insert( QLatin1String( "\u3077" ), QLatin1String( "\uff8c\uff9f" ) );
        map.insert( QLatin1String( "\u307a" ), QLatin1String( "\uff8d\uff9f" ) );
        map.insert( QLatin1String( "\u307d" ), QLatin1String( "\uff8e\uff9f" ) );
        map.insert( QLatin1String( "\u307e" ), QLatin1String( "\uff8f" ) );
        map.insert( QLatin1String( "\u307f" ), QLatin1String( "\uff90" ) );
        map.insert( QLatin1String( "\u3080" ), QLatin1String( "\uff91" ) );
        map.insert( QLatin1String( "\u3081" ), QLatin1String( "\uff92" ) );
        map.insert( QLatin1String( "\u3082" ), QLatin1String( "\uff93" ) );
        map.insert( QLatin1String( "\u3084" ), QLatin1String( "\uff94" ) );
        map.insert( QLatin1String( "\u3086" ), QLatin1String( "\uff95" ) );
        map.insert( QLatin1String( "\u3088" ), QLatin1String( "\uff96" ) );
        map.insert( QLatin1String( "\u3083" ), QLatin1String( "\uff6c" ) );
        map.insert( QLatin1String( "\u3085" ), QLatin1String( "\uff6d" ) );
        map.insert( QLatin1String( "\u3087" ), QLatin1String( "\uff6e" ) );
        map.insert( QLatin1String( "\u3089" ), QLatin1String( "\uff97" ) );
        map.insert( QLatin1String( "\u308a" ), QLatin1String( "\uff98" ) );
        map.insert( QLatin1String( "\u308b" ), QLatin1String( "\uff99" ) );
        map.insert( QLatin1String( "\u308c" ), QLatin1String( "\uff9a" ) );
        map.insert( QLatin1String( "\u308d" ), QLatin1String( "\uff9b" ) );
        map.insert( QLatin1String( "\u308f" ), QLatin1String( "\uff9c" ) );
        map.insert( QLatin1String( "\u3092" ), QLatin1String( "\uff66" ) );
        map.insert( QLatin1String( "\u3093" ), QLatin1String( "\uff9d" ) );
        map.insert( QLatin1String( "\u308e" ), QLatin1String( "\uff9c" ) );
        map.insert( QLatin1String( "\u30fc" ), QLatin1String( "\uff70" ) );
        return map;
    }
};


KanaConverter::KanaConverter()
{
}
