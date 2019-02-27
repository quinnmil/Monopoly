#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>

int dieRoll(){
    int roll;
    roll = rand()%6+1;
    return roll;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


//    scene.addText("hello world");

//    ui-QGraphicsView view(&scene);
//    view.show();


    ui->setupUi(this);
    srand(time(NULL));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);

    rect = scene->addRect(10,10,100,100,blackPen,redBrush);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);


//    view->setGeometry(QRect(50, 50, 400, 200));
//    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked(){
    int v1 = dieRoll();
    int v2 = dieRoll();

    ui->label_die1->setText(QString::number(v1));
    ui->label_die2->setText(QString::number(v2));



}
