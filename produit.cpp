#include "produit.h"
#include "ui_produit.h"
#include "QMessageBox"

Produit::Produit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Produit)
{
    ui->setupUi(this);
}

Produit::Produit(QObject *controller)
    : ui(new Ui::Produit)
    {
         ui->setupUi(this);

         connect(ui->Retour, SIGNAL(clicked()), controller, SLOT(onProduit_Retour_Clicked()));

         connect(ui->pushButton_Valider, SIGNAL(clicked()), controller, SLOT(onProduit_Valider_Clicked()));

}

bool Produit::getInput(QString &Designation, int *Qantite, int *prix_unitaire)
{
    Designation = ui->Input_DES->text();
    *Qantite = ui->Input_Q->text().toInt();
    *prix_unitaire = ui->Input_P->text().toInt();

    if(Designation.compare("") == 0 ||  ui->Input_Q->text().compare("") ==0 || ui->Input_P->text().compare("")==0 ){
         QString sm= "Code Secret et Code Confirmer différent";
        this->notificationInfo(sm);
        return false;
    }

    return true;
}

void Produit::notificationInfo(QString message)
{
    QMessageBox m_MsgBox;
       m_MsgBox.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
       m_MsgBox.setIcon(QMessageBox::Warning);
       m_MsgBox.setText(message);
       m_MsgBox.setStandardButtons(QMessageBox::Ok);
       m_MsgBox.setStyleSheet("QLabel{min-width:250 px; font-size: 12px;} QPushButton{ width:25px; font-size: 12px; }");
       if(m_MsgBox.exec() == QMessageBox::Ok)
           m_MsgBox.close();
}

Produit::~Produit()
{
    delete ui;
}
