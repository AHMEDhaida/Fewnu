#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
#include <QCryptographicHash>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::login(QObject *controller)
: ui(new Ui::login)
{
     ui->setupUi(this);

     connect(ui->pushButton_Connecter, SIGNAL(clicked()), controller, SLOT(onLoginClicked()));
     connect(ui->label_Creer_Compte, SIGNAL(clicked()), controller, SLOT(onCreerCompteClicked()));
}

login::~login()
{
    delete ui;
}


bool login::getInputs(QString &tel, QString &password){

    tel = ui->Tel->text();

     password = ui->Password->text();
    if(tel.compare("") == 0 || password.compare("") ==0){


        QString sm = "isImptu";
        this->notificationInfo(sm);
        return false;
    }

    return true;
}

void  login::notificationInfo(QString message){


    QMessageBox m_MsgBox;
       m_MsgBox.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
       m_MsgBox.setIcon(QMessageBox::Warning);
       m_MsgBox.setText(message);
       m_MsgBox.setStandardButtons(QMessageBox::Ok);
       m_MsgBox.setStyleSheet("QLabel{min-width:250 px; font-size: 12px;} QPushButton{ width:25px; font-size: 12px; }");
       if(m_MsgBox.exec() == QMessageBox::Ok)
           m_MsgBox.close();
}
