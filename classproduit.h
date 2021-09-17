#ifndef CLASSPRODUIT_H
#define CLASSPRODUIT_H
#include <QString>
class ClassProduit
{

private:
    uint Id;
    QString Designation;
    uint Qantite;
    uint Prix_unitaire;
public:
    ClassProduit();
    ClassProduit(uint,QString,uint,uint);
    uint getId() const;
    void setId(const uint &value);
    QString getDesignation() const;
    void setDesignation(const QString &value);
    uint getQantite() const;
    void setQantite(const uint &value);
    uint getPrix_unitaire() const;
    void setPrix_unitaire(const uint &value);
};

#endif // CLASSPRODUIT_H
