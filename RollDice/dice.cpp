#include "dice.h"
#include "ui_dice.h"
#include <cstdlib>
#include <ctime>

/*
 * Small program to practice with Qt.
 * This will eventually be a utility.
 * Author: Quinn Milionis
*/

dice::dice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dice)
{
    srand(time(NULL));
    ui->setupUi(this);
}

dice::~dice()
{
    delete ui;
}

int dieRoll(){
    int roll;
    roll = rand()%6+1;
    return roll;
}

void dice::on_pushButton_roll_clicked()
{
    int v1 = dieRoll();
    int v2 = dieRoll();
    int total = v1 + v2;
    ui->label_die1->setText(QString::number(v1));
    ui->label_die2->setText(QString::number(v2));

}
