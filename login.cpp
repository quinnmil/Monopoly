#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

QString Login::getPlayerOne(){
    return playerOne;
}

QString Login::getPlayerTwo(){
    return playerTwo;
}

void Login::on_enterNameButton_clicked()
{
    playerOne = ui->p1_lineEdit->text();
    playerTwo = ui->p2_lineEdit->text();
    ui->buttonBox->setEnabled(true);
}
