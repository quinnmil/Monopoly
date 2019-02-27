#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

int dieRoll(){
    int roll;
    roll = rand()%6+1;
    return roll;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
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

//    ui->graphicsView->addRect(5,5)


}
