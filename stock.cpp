#include "stock.h"
#include "ui_stock.h"

Stock::Stock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stock)
{
    ui->setupUi(this);
}

Stock::Stock(QObject *controller)
    : ui(new Ui::Stock)
    {
         ui->setupUi(this);

          connect(ui->Retour, SIGNAL(clicked()), controller, SLOT(onStock_Retour_Clicked()));

          connect(ui->power, SIGNAL(clicked()), controller, SLOT(onStock_Power_Clicked()));
          connect(ui->pushButton_Ajoute, SIGNAL(clicked()), controller, SLOT(onStock_AjourProduit_Clicked()));
          connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), controller ,SLOT(onListWidgetItemClickedProduit(QListWidgetItem*)));

           AfficherProduit(service->listerProduit());

}

QListWidgetItem *Stock::onListWidgetItemClicked_0()
{

     return ui->listWidget->item(0);
}

QListWidgetItem *Stock::onListWidgetItemClicked_1()
{
     return ui->listWidget->item(1);
}

QListWidgetItem *Stock::onListWidgetItemClicked_2()
{
     return ui->listWidget->item(2);
}

QListWidgetItem *Stock::onListWidgetItemClicked_3()
{
     return ui->listWidget->item(3);
}

QListWidgetItem *Stock::onListWidgetItemClicked_4()
{
     return ui->listWidget->item(4);
}

QListWidgetItem *Stock::onListWidgetItemClicked_5()
{
    return ui->listWidget->item(5);
}



Stock::~Stock()
{
    delete ui;
}

void Stock::AfficherProduit(QSqlQueryModel *model)
{
     ui->tableView->setModel(model);

}



void Stock::on_tableView_activated(const QModelIndex &index)
{
     QString val =  ui->tableView->model()->data(index).toString();
}
