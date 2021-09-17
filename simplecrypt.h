#ifndef SIMPLECRYPT_H
#define SIMPLECRYPT_H
#include <QString>
#include <QVector>
#include <QFlags>

class simplecrypt
{
public:
    simplecrypt();
    QString crypter(QString chaineACrypter);
    QString decrypter(QString chaineADecrypter);
};




#endif // SIMPLECRYPT_H
