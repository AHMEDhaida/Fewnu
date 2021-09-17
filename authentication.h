#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QMainWindow>
#include "simplecrypt.h"
namespace Ui {
class authentication;
}

class authentication : public QMainWindow
{
    Q_OBJECT

public:
    explicit authentication(QWidget *parent = nullptr);
    authentication(QObject *controller = nullptr);
    ~authentication();
    bool getInputs(QString &login,QString &password,QString &Tel, QString &email);
    void notificationInfo(QString message);


private:
    Ui::authentication *ui;
};

#endif // AUTHENTICATION_H
