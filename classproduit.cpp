#include "classproduit.h"

uint ClassProduit::getId() const
{
    return Id;
}

void ClassProduit::setId(const uint &value)
{
    Id = value;
}

QString ClassProduit::getDesignation() const
{
    return Designation;
}

void ClassProduit::setDesignation(const QString &value)
{
    Designation = value;
}

uint ClassProduit::getQantite() const
{
    return Qantite;
}

void ClassProduit::setQantite(const uint &value)
{
    Qantite = value;
}

uint ClassProduit::getPrix_unitaire() const
{
    return Prix_unitaire;
}

void ClassProduit::setPrix_unitaire(const uint &value)
{
    Prix_unitaire = value;
}

ClassProduit::ClassProduit()
{

}


ClassProduit::ClassProduit(uint _Id, QString _Designation, uint _Qantite, uint _Prix_unitaire):
    Id(_Id),Designation(_Designation),Qantite(_Qantite),Prix_unitaire(_Prix_unitaire)
{

}
