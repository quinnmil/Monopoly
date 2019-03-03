#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>
#include <QDebug>

// VARIBLES FOR TESTING
static int NUMPLAYERS = 2;

//THIS WAS MOVED TO GAME.CPP
//int dieRoll(){
//    int roll;
//    roll = rand()%6+1;
//    return roll;
//}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // todo, this will be called when newGame button is pressed.
    Game *game = new Game();

    ui->setupUi(this);
    srand(time(NULL));

    QList<QLabel *>spaceList = getSpaceList();
    QList<PropertyType *> gameSpaceList = getGameSpaceList();

//    gameSpaceList = game->getGameSpaceList();

    qDebug() << spaceList;
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

QList<QLabel *> MainWindow::getSpaceList(){
// TODO, get number of players from NEWSCREEN
/*
     *
     * creates a list of lables on the board
     * order of board:
     *  5 6 6
     *  4   8
     *  3 2 1
     *
*/

    QList<QLabel *> list = ui->PropertyInfo->findChildren<QLabel *>();

    qSort(list.begin(), list.end(), labelLessThan );
    list.takeFirst();

}

QList<PropertyType*> MainWindow::getGameSpaceList(){
  return game->getGameSpaceList();
}

void MainWindow::on_pushButton_clicked(){
    // int v1 = dieRoll();
    // int v2 = dieRoll();
    // int total = v1 + v2;
    int die1 = game->dieRoll();
    int die2 = game->dieRoll();

    // move player.
    game->movePlayer(die1, die2);


    // update dice
    ui->label_die1->setText(QString::number(die1));
    ui->label_die2->setText(QString::number(die2));

    this->updateDisplay();


//    spaceList[total]->setHidden(false);
}
void MainWindow::displayOptions(){
  // if property is unowned, display offer to buy

  // if property is owned, notify player of rent payment.
}

void MainWindow::updateDisplay(){
  // update board dislay
  PlayerType* currentPlayer = game->getCurrentPlayer();

  int index = game->getPlayerPosition(*currentPlayer);
  spaceList[index]->setText("player here");

  // update information display
  std::string currentProperty = game->getPropertyName();
  int currentPropertyCost = game->getPropertyCost();
  int currentPropertyRent = game->getPropertyRent();
  std::string currentPropertyInfo = game->getPropertyInfo();

}

/* note for later, if we want to get info on a selected propoerty, we could
I really just need the index of that click and then look it up in gameSpaceList

*/

