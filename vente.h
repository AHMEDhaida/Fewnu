#ifndef VENTE_H
#define VENTE_H
#include <QListWidgetItem>
#include <QMainWindow>

namespace Ui {
class Vente;
}

class Vente : public QMainWindow
{
    Q_OBJECT

public:
    explicit Vente(QWidget *parent = nullptr);
     Vente(QObject *controller = nullptr);
     QListWidgetItem* onListWidgetItemClicked_0();
     QListWidgetItem* onListWidgetItemClicked_1();
     QListWidgetItem* onListWidgetItemClicked_2();
     QListWidgetItem* onListWidgetItemClicked_3();
     QListWidgetItem* onListWidgetItemClicked_4();
     QListWidgetItem* onListWidgetItemClicked_5();
    ~Vente();

private:
    Ui::Vente *ui;
};

#endif // VENTE_H
