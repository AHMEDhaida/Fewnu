#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H
#include "vente.h"
#include "login.h"
#include "authentication.h"
#include "service.h"
#include "usermodel.h"
#include "usermodel.h"
#include "mainwindow.h"
#include "home.h"
#include "stock.h"
#include "produit.h"
#include <QListWidgetItem>

#include "classproduit.h"




class FlowController : public QObject
{
    Q_OBJECT

private:
    //les interfaces graphique

    User us;
    login* log;
    MainWindow* mainWindow;
    authentication* authentification;
    Home* home;
    Stock* stock;
    Produit* produit;
    Vente* vente;


   //couche service

    Service* service;


private slots:

    /**
     * @brief onMainWindow buttons clicked
     *
     */
    void onMainWindowConnecterClicked();
    void onMainWindowInscrireClicked();
    void onMainWindowExitClicked();

    /**
     * @brief onAuthentification buttons clicked
     *
     */
    void onAuthentificationValiderClicked();
    void onAuthentificationSignUpClicked();
    void Retourne_AccueilClicked();

    /**
     * @brief login buttons clicked
     *
     */
     void onLoginClicked();
     void onCreerCompteClicked();

     /**
      * @brief Home buttons clicked
      *
      */
      void onHome_Stock_Clicked();
       void onHome_Vente_Clicked();
      void onListWidgetItemClicked(QListWidgetItem* item);

      /**
       * @brief Stock buttons clicked
       *
       */
      void onStock_Retour_Clicked();
      void onStock_Power_Clicked();
      void onStock_AjourProduit_Clicked();
      void onListWidgetItemClickedProduit(QListWidgetItem* item);

      /**
       * @brief Produit buttons clicked
       *
       */

      void onProduit_Retour_Clicked();
      void onProduit_Valider_Clicked();

      /**
       * @brief Vente buttons clicked
       *
       */

      void onVent_Retour_Clicked();
      void onVent_Valider_Clicked();
      void onListWidgetItemClickedVent(QListWidgetItem* item);


public:
    void exec();
    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
