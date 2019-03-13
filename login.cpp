#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QFont f("Times New Roman", 20); //Creates new font to use
    ui->welcomeLabel->setFont(f); //Sets font
    ui->welcomeLabel->setAlignment(Qt::AlignCenter); //Aligns text to center
    this->setWindowTitle("Login"); //Sets window title
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
    playerOne = ui->p1_lineEdit->text(); //Store usernames
    playerTwo = ui->p2_lineEdit->text();
    ui->buttonBox->setEnabled(true); //Log in with "ok"
}
