#ifndef PRODUIT_H
#define PRODUIT_H

#include <QMainWindow>

namespace Ui {
class Produit;
}

class Produit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Produit(QWidget *parent = nullptr);
    Produit(QObject *controller = nullptr);
    bool getInput(QString &Designation,int* Qantite, int* prix_unitaire);
    void notificationInfo(QString message);
    ~Produit();

private:
    Ui::Produit *ui;
};

#endif // PRODUIT_H
