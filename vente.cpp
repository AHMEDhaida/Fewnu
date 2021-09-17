#include "vente.h"
#include "ui_vente.h"

Vente::Vente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Vente)
{
    ui->setupUi(this);
}

Vente::Vente(QObject *controller)
    : ui(new Ui::Vente)
    {
         ui->setupUi(this);
         connect(ui->Retour, SIGNAL(clicked()), controller, SLOT(onVent_Retour_Clicked()));
         connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), controller ,SLOT(onListWidgetItemClickedVent(QListWidgetItem*)));



}

QListWidgetItem *Vente::onListWidgetItemClicked_0()
{

     return ui->listWidget->item(0);
}

QListWidgetItem *Vente::onListWidgetItemClicked_1()
{
     return ui->listWidget->item(1);
}

QListWidgetItem *Vente::onListWidgetItemClicked_2()
{
     return ui->listWidget->item(2);
}

QListWidgetItem *Vente::onListWidgetItemClicked_3()
{
     return ui->listWidget->item(3);
}

QListWidgetItem *Vente::onListWidgetItemClicked_4()
{
     return ui->listWidget->item(4);
}

QListWidgetItem *Vente::onListWidgetItemClicked_5()
{
    return ui->listWidget->item(5);
}


Vente::~Vente()
{
    delete ui;
}
