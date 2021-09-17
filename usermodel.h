#ifndef USERMODEL_H
#define USERMODEL_H

#include <QSqlQueryModel>
#include "simplecrypt.h"
#include "dbaccess.h"
#include <user.h>

class UserModel : public QSqlQueryModel
{
private:
    DBAccess *dbAccess;

public:
    UserModel(DBAccess *dbAccess);
    ~UserModel();

    void clear();

    // CRUD methods
    void create(User user);
    void update(User user);
    void remove(uint identifiant);
    bool readBy(QString login);
    bool readBy(QString tel, QString password, User *user);

    QSqlQueryModel* readAll();
    QSqlQueryModel* readAll(QString rech);
    QSqlQueryModel* readAll(uint Id);
    void ModifierPassword(User user);


};

#endif // USERMODEL_H
