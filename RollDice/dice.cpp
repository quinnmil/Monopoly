#include "dice.h"
#include "ui_dice.h"

dice::dice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dice)
{
    ui->setupUi(this);
}

dice::~dice()
{
    delete ui;
}
