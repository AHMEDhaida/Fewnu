#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}


MainWindow::MainWindow(QObject *controller)
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_Connecter, SIGNAL(clicked()), controller, SLOT(onMainWindowConnecterClicked()));
    connect(ui->pushButton_Inscrire, SIGNAL(clicked()), controller, SLOT(onMainWindowInscrireClicked()));

}



MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    QSize s(0,0);
       int n = list.count();
       if (n > 0)
           s = QSize(100,70); // commence par une taille par défaut correcte
       int i = 0;
       while (i < n) {
           QWidgetItem *o = list.at(i);
           s = s.expandedTo(o->sizeHint());
           ++i;
       }
       return s + n*QSize(40, 40);
}

QSize MainWindow::minimumSize() const
{
    QSize s(0,0);
        int n = list.count();
        int i = 0;
        while (i < n) {
            QWidgetItem *o = list.at(i);
            s = s.expandedTo(o->minimumSize());
            ++i;
        }
        return s + n*QSize(40, 49);
}

void MainWindow::setGeometry(const QRect &r)
{
    ui->centralwidget->setGeometry(r);

       if (list.size() == 0)
           return;

       int w = r.width() - (list.count() - 1) * 40;
       int h = r.height() - (list.count() - 1) * 40;
       int i = 0;
       while (i < list.size()) {
           QWidgetItem *o = list.at(i);
           QRect geom(r.x() + i * 40, r.y() + i * 40, w, h);
           o->setGeometry(geom);
           ++i;
       }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    //refresh();
       QWidget::resizeEvent(event);
}

