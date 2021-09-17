#ifndef HOME_H
#define HOME_H
#include <QDebug>
#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
     Home(QObject *controller = nullptr);
     QListWidgetItem* onListWidgetItemClicked_0();
     QListWidgetItem* onListWidgetItemClicked_1();
     QListWidgetItem* onListWidgetItemClicked_2();
     QListWidgetItem* onListWidgetItemClicked_3();
     QListWidgetItem* onListWidgetItemClicked_4();
     QListWidgetItem* onListWidgetItemClicked_5();

    ~Home();


private:
    Ui::Home *ui;
};

#endif // HOME_H
