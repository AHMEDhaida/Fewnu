#include "authentication.h"
#include "ui_authentication.h"
#include "QMessageBox"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>


authentication::authentication(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authentication)
{
    ui->setupUi(this);
}

authentication::authentication(QObject *controller)
    : ui(new Ui::authentication)
    {
         ui->setupUi(this);
         connect(ui->pushButton_Valider, SIGNAL(clicked()), controller, SLOT(onAuthentificationValiderClicked()));
         connect(ui->Retourne_Accueil, SIGNAL(clicked()), controller, SLOT(Retourne_AccueilClicked()));
}

authentication::~authentication()
{
    delete ui;
}

bool authentication::getInputs(QString &login,  QString &password, QString &Tel, QString &email)
{
     simplecrypt Crypto;
    login = ui->Nom_Complet->text();
    password = ui->Code_Secret->text();

    Tel = ui->Tel->text();
    email = ui->Email->text();

    if(password.compare(ui->Confirmer_Code->text()) !=0){

        QString sm= "Les Mots des passes ne sont pas les memes";
       this->notificationInfo(sm);
        return false;
    }


     password = Crypto.crypter(password);


    if(login.compare("") == 0 ||  password.compare("") ==0 || Tel.compare("") ==0){
         QString sm= "Code Secret et Code Confirmer différent";
        this->notificationInfo(sm);
        return false;
    }

    return true;

}


void  authentication::notificationInfo(QString message){

    QMessageBox m_MsgBox;
       m_MsgBox.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
       m_MsgBox.setIcon(QMessageBox::Warning);
       m_MsgBox.setText(message);
       m_MsgBox.setStandardButtons(QMessageBox::Ok);
       m_MsgBox.setStyleSheet("QLabel{min-width:250 px; font-size: 12px;} QPushButton{ width:25px; font-size: 12px; }");
       if(m_MsgBox.exec() == QMessageBox::Ok)
           m_MsgBox.close();
}
