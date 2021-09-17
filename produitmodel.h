#ifndef PRODUITMODEL_H
#define PRODUITMODEL_H
#include "classproduit.h"
#include <QSqlQueryModel>

#include "dbaccess.h"

class ProduitModel: public QSqlQueryModel
{
private:
    DBAccess *dbAccess;

public:
    ProduitModel(DBAccess *dbAccess);
    ~ProduitModel();

    void clear();

    //  methods
    void createProduit(ClassProduit Produit);
    void updateProduit(ClassProduit Produit);
    void removeProduit(uint Id);
    QSqlQueryModel *readAll();
    QSqlQueryModel* readAll(QString rech);



};

#endif // PRODUITMODEL_H
