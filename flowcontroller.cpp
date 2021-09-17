#include "flowcontroller.h"

#include "QMessageBox"
#include <QDebug>
#include "QDateTime"
FlowController::FlowController() : log(nullptr),mainWindow(nullptr),authentification(nullptr),home(nullptr),stock(nullptr),produit(nullptr),vente(nullptr)
{

     service = Service::getInstance();

}

/**
 * @brief onMainWindow buttons clicked
 *
 */
void FlowController::onMainWindowConnecterClicked(){
    log = new login(this);
    log->show();
    mainWindow->hide();

}
void FlowController::onMainWindowInscrireClicked(){
    authentification = new authentication(this);
    authentification->show();
    mainWindow->hide();
}
void FlowController::onMainWindowExitClicked(){}


/**
 * @brief onAuthentification buttons clicked
 *
 */
void FlowController::onAuthentificationValiderClicked(){

    QString nom;
    QString password;
    QString Tel;
    QString email;


    bool statut = this->authentification->getInputs(nom,password,Tel,email);
    if(statut){

            User user ;

            user.setLogin(nom);
            user.setPassword(password);
            user.setEmail(email);
            user.setTel(Tel);
            QString info{ "User "};
            QString info1{ " created successfully!"};
            QString s =  info + nom + info1;
            service->createUser(user);
            this->authentification->notificationInfo(s);
            log = new login(this);
            log->show();
            authentification->hide();


}

}
void FlowController::onAuthentificationSignUpClicked(){}
void FlowController::Retourne_AccueilClicked(){
    authentification->hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();

}

void FlowController::onLoginClicked()
{
    QString tel ;
    QString password ;
    QString sm;


    if (true == log->getInputs(tel, password))
    {

        if (true == service->authentifier(tel, password, &us))
        {
              this->log->hide();
              home = new Home(this);
              home->show();

        }else{
            sm = "Téléphone ou Mot de passe incorrecte!! ";
           this->log->notificationInfo(sm);
        }
   }




}

void FlowController::onCreerCompteClicked()
{
    this->log->hide();
    authentification = new authentication(this);
    authentification->show();

}

void FlowController::onHome_Stock_Clicked()
{
    this->home->hide();
    stock =new Stock(this);
    stock->show();
}

void FlowController::onHome_Vente_Clicked()
{
    this->home->hide();
    vente =new Vente(this);
    vente->show();
}

void FlowController::onListWidgetItemClicked(QListWidgetItem *item)
{
    if (home->onListWidgetItemClicked_5() == item) {
        this->home->hide();
        stock =new Stock(this);
        stock->show();
       }
    if (home->onListWidgetItemClicked_4() == item) {
        this->home->hide();
        vente =new Vente(this);
        vente->show();
       }



}

void FlowController::onStock_Retour_Clicked()
{
    this->stock->hide();
    home = new Home(this);
    home->show();
}

void FlowController::onStock_Power_Clicked()
{
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(home,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->produit->close();
           this->home->close();
        }
}

void FlowController::onStock_AjourProduit_Clicked()
{
    this->stock->hide();
    produit = new Produit(this);
    produit->show();
}

void FlowController::onListWidgetItemClickedProduit(QListWidgetItem *item)
{
    if (stock->onListWidgetItemClicked_0() == item) {
        this->stock->hide();
        home =new Home(this);
        home->show();
       }
}

void FlowController::onProduit_Retour_Clicked()
{
    this->produit->hide();
    stock = new Stock(this);
    stock->show();
}

void FlowController::onProduit_Valider_Clicked()
{

    QString Designation;
    int Qantite;
    int Prix_unitaire;


    bool statut = this->produit->getInput(Designation,&Qantite,&Prix_unitaire);
    if(statut){

            ClassProduit classproduit ;

          classproduit.setDesignation(Designation);
          classproduit.setQantite(Qantite);
          classproduit.setPrix_unitaire(Prix_unitaire);
            QString info{ "Produit "};
            QString info1{ "Bien Ajouter!"};
            QString s =  info + Designation + info1;
            service->createProdiut(classproduit);
            this->authentification->notificationInfo(s);
    }
}

void FlowController::onVent_Retour_Clicked()
{
    this->vente->hide();
    home = new Home(this);
    home->show();
}

void FlowController::onVent_Valider_Clicked()
{

}

void FlowController::onListWidgetItemClickedVent(QListWidgetItem *item)
{
    if (stock->onListWidgetItemClicked_0() == item) {
        this->stock->hide();
        home =new Home(this);
        home->show();
       }
    if (vente->onListWidgetItemClicked_5() == item) {
        this->vente->hide();
        stock =new Stock(this);
        stock->show();
       }
    if (vente->onListWidgetItemClicked_4() == item) {
        this->vente->hide();
        vente =new Vente(this);
        vente->show();
       }
}



void FlowController::exec()
{
   //mainWindow = new MainWindow(this);
  // mainWindow->show();
    home = new Home(this);
    home->show();
}


FlowController::~FlowController()
{
    if (log != nullptr)
    {
        delete log;
    }
    if (mainWindow != nullptr)
    {
        delete mainWindow;
    }

        if (authentification != nullptr)
        {
            delete authentification;
        }

    if (service != nullptr)
    {
        Service::release();
    }




}




























