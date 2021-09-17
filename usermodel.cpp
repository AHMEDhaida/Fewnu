#include "usermodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

UserModel::UserModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;

    UserModel::clear();
}

void UserModel::create(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_users (login, password, Tel, email) "
                    "VALUES (:login, :password,:Tel, :email)");
    query.bindValue(":login", user.getLogin());
    query.bindValue(":password", user.getPassword());
    query.bindValue(":Tel", user.getTel());
    query.bindValue(":email", user.getEmail());
    query.exec();

    readAll();

    qDebug () << "User" << user.getLogin() << "created successfully!";
    dbAccess->close();
}

QSqlQueryModel* UserModel::readAll()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT login, Tel, email FROM t_users", database);


    model->setHeaderData(4, Qt::Horizontal, tr("Login"));
    model->setHeaderData(7, Qt::Horizontal, tr("Tel"));



    qDebug () << "Users displayed successfully!";
    dbAccess->close();
    return model;
}





void UserModel::update(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_users SET login=:login, Tel=:Tel, email=:email"
                    "WHERE identifiant=:identifiant");

    query.bindValue(":login", user.getLogin());
    //query.bindValue(":password", user.getPassword());
   // query.bindValue(":identifiant", user.getIdentifiant());
    query.bindValue(":Tel", user.getTel());
    query.bindValue(":email", user.getEmail());

    query.exec();

    readAll();

    qDebug () << "User" << user.getLogin() << " updated successfully!" ;
    dbAccess->close();
}

void  UserModel::ModifierPassword(User user){
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_users SET password=:password "
                    "WHERE identifiant=:identifiant");
    //query.bindValue(":identifiant", user.getIdentifiant());
    query.bindValue(":password", user.getPassword());


    query.exec();

    readAll();

    qDebug () << "User" << user.getLogin() << " updated successfully!" ;
    dbAccess->close();


}


void UserModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_users WHERE identifiant=:identifiant");
    query.bindValue(":identifiant", identifiant);
    query.exec();

    readAll();

    qDebug () << "User with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}

bool UserModel::readBy(QString login)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT login AS Login FROM t_users WHERE login=:login");
    query.bindValue(":login", login);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

   // QSqlRecord record = query.record();
    this->setQuery(query);

    qDebug() << "User with login" << login << "found.";
    dbAccess->close();

    return true;
}

bool UserModel::readBy(QString Tel, QString password, User *user)
{
    dbAccess->open();
    simplecrypt Crypto;

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT Tel, password FROM t_users WHERE Tel=:Tel AND password=:password");
    query.bindValue(":Tel", Tel);
    query.bindValue(":password", Crypto.crypter(password));
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

   // QSqlRecord record = query.record();
    //user->setLogin(login);
    user->setPassword(password);
    //user->setIdentifiant(query.value(record.indexOf("identifiant")).toUInt());
    user->setTel(Tel);


    qDebug() << "User with name" << user->getLogin() << "found.";
    dbAccess->close();

    return true;
}

void UserModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT identifiant, login FROM t_users WHERE identifiant=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    this->setHeaderData(3, Qt::Horizontal, tr("Login"));


    dbAccess->close();
}

UserModel::~UserModel()
{
    qDebug() << "UserModel Object has been deleted!";
}









