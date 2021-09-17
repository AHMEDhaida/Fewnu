#include "simplecrypt.h"

simplecrypt::simplecrypt()
{

}

namespace
{
    const QByteArray printables()
    {
        QByteArray list;
        for(int i = 0; i < 256; ++i)
        {
            if (QChar(char(i)).isPrint())
                list+= char(i);
        }
        return list;
    }
}

QString simplecrypt::crypter(QString chaineACrypter)
{
    // Pour éviter de décoder en "%xx" les caractères affichables
       static const QByteArray exclude = printables();

       QByteArray texteEnOctet = QByteArray::fromPercentEncoding(chaineACrypter.toUtf8());
       static const QByteArray clef = "cle12";
       QByteArray codeFinal;
       int tailleClef = clef.length();

       for (int i = 0; i < texteEnOctet.length(); ++i) {
           codeFinal += char(texteEnOctet[i] ^ clef[i % tailleClef]);
       }

       return codeFinal.toPercentEncoding(exclude);
}

QString simplecrypt::decrypter(QString chaineADecrypter)
{
   return crypter(chaineADecrypter);
    /****
    QByteArray texte = chaineADecrypter.toUtf8();
       QByteArray texteEnOctets = QByteArray::fromHex(texte);
       QByteArray clef = "clé, pas tricher !$";
       QByteArray codeFinal = "";
       int tailleClef = clef.length();

       for (int i = 0; i < texteEnOctets.length(); ++i) {
           codeFinal += char(texteEnOctets[i] ^ clef[i % tailleClef]);
       }
       return QString::fromLatin1(codeFinal);

       *********/
}
