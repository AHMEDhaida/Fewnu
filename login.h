#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    login(QObject *controller = nullptr);
    ~login();
    bool getInputs(QString &tel, QString &password);
    void notificationInfo(QString message);

private:
    Ui::login *ui;
};

#endif // LOGIN_H
