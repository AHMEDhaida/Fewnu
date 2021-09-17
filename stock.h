#ifndef STOCK_H
#define STOCK_H
#include "QSqlQueryModel"
#include <QMainWindow>
#include "service.h"
#include <QListWidgetItem>

namespace Ui {
class Stock;
}

class Stock : public QMainWindow
{
    Q_OBJECT
    Service* service;

public:
    explicit Stock(QWidget *parent = nullptr);
    Stock(QObject *controller = nullptr);
    ~Stock();
    void AfficherProduit(QSqlQueryModel* model);
    QListWidgetItem* onListWidgetItemClicked_0();
    QListWidgetItem* onListWidgetItemClicked_1();
    QListWidgetItem* onListWidgetItemClicked_2();
    QListWidgetItem* onListWidgetItemClicked_3();
    QListWidgetItem* onListWidgetItemClicked_4();
    QListWidgetItem* onListWidgetItemClicked_5();

private slots:
    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Stock *ui;
};

#endif // STOCK_H
