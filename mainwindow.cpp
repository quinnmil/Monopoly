#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>

#include <QDebug>

int dieRoll(){
    int roll;
    roll = rand()%6+1;
    return roll;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    srand(time(NULL));

    spaceList = initalizeBoard();
//    qDebug() << spaceList;
//    spaceList[0]->setHidden(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool labelLessThan (QLabel * L1, QLabel * L2){
    // compares l1 name to l2 name
    return L1->objectName() < L2->objectName();
}

QList<QLabel *> MainWindow::initalizeBoard(){
/*
     *
     * creates a list of lables on the board
     * order of board:
     *  5 6 6
     *  4   8
     *  3 2 1
     *
*/

    QList<QLabel *> list = ui->groupBox_2->findChildren<QLabel *>();

    qSort(list.begin(), list.end(), labelLessThan );

    return list;

}

void MainWindow::on_pushButton_clicked(){
    int v1 = dieRoll();
    int v2 = dieRoll();
    int total = v1 + v2;

    ui->label_die1->setText(QString::number(v1));
    ui->label_die2->setText(QString::number(v2));

    spaceList[total]->setHidden(false);



}
