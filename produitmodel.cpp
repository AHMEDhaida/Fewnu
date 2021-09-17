#include "produitmodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

ProduitModel::ProduitModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;

    ProduitModel::clear();
}

ProduitModel::~ProduitModel()
{
    qDebug() << "ProduitModel Object has been deleted!";
}

void ProduitModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM Produits WHERE Id=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Id"));
    this->setHeaderData(1, Qt::Horizontal, tr("Designation"));


    dbAccess->close();
}

void ProduitModel::createProduit(ClassProduit Produit)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO Produits (Designation, Qantite, Prix_Unitaire) "
                    "VALUES (:Designation,:Qantite, :Prix_Unitaire)");

    query.bindValue(":Designation", Produit.getDesignation());
    query.bindValue(":Qantite", Produit.getQantite());
    query.bindValue(":Prix_Unitaire", Produit.getPrix_unitaire());
    query.exec();

    readAll();

    qDebug () << "PRODUIT" << Produit.getDesignation() << "created successfully!";
    dbAccess->close();
}

QSqlQueryModel* ProduitModel::readAll()
{
    QSqlQueryModel* model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT Designation, Prix_Unitaire FROM Produits", database);


   // model->setHeaderData(1, Qt::Horizontal, tr("Id"));
    model->setHeaderData(0, Qt::Horizontal, tr(""));
    model->setHeaderData(1, Qt::Horizontal, tr(""));
   // model->setHeaderData(3, Qt::Horizontal, tr("Prix_Unitaire"));



    qDebug () << "Produit displayed successfully!";
    dbAccess->close();
    return model;
}
