#ifndef USER_H
#define USER_H

#include <QString>



class User
{
private:
   // uint identifiant;
    QString login;
    QString password;
    QString Tel;
    QString email;


public:
    User();
   // User(uint, QString, QString, QString,QString);
    User(QString, QString, QString,QString);

   // uint getIdentifiant() { return identifiant; }
    QString getTel() { return Tel; }
    QString getLogin() { return login; }
    QString getPassword() { return password; }
    QString getEmail() { return email; }

   // void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setLogin(QString login) {  this->login = login; }
    void setPassword(QString password) { this->password = password; }
    void setTel(QString Tel) { this->Tel = Tel; }
     void setEmail(QString email) { this->email = email; }



};

#endif // USER_H
