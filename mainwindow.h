#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QList>
#include <QWidgetItem>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QObject *controller = nullptr);
    ~MainWindow();
    QSize sizeHint() const;
    QSize minimumSize() const;
     void setGeometry(const QRect &rect);

private:
    Ui::MainWindow *ui;
protected:
    void resizeEvent(QResizeEvent *event);
      QList<QWidgetItem*> list;
      QList<QWidgetItem*> listWidget;
};
#endif // MAINWINDOW_H
