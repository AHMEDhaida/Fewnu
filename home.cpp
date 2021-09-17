#include "home.h"
#include "ui_home.h"


Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);


}

Home::Home(QObject *controller)
    : ui(new Ui::Home)
    {
         ui->setupUi(this);
         connect(ui->pushButton_Stock, SIGNAL(clicked()), controller, SLOT(onHome_Stock_Clicked()));
         connect(ui->pushButton_Vente, SIGNAL(clicked()), controller, SLOT(onHome_Vente_Clicked()));

         connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), controller ,SLOT(onListWidgetItemClicked(QListWidgetItem*)));





}
QListWidgetItem *Home::onListWidgetItemClicked_0()
{

     return ui->listWidget->item(0);
}

QListWidgetItem *Home::onListWidgetItemClicked_1()
{
     return ui->listWidget->item(1);
}

QListWidgetItem *Home::onListWidgetItemClicked_2()
{
     return ui->listWidget->item(2);
}

QListWidgetItem *Home::onListWidgetItemClicked_3()
{
     return ui->listWidget->item(3);
}

QListWidgetItem *Home::onListWidgetItemClicked_4()
{
     return ui->listWidget->item(4);
}

QListWidgetItem *Home::onListWidgetItemClicked_5()
{
    return ui->listWidget->item(5);
}



Home::~Home()
{
    delete ui;
}



