#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool labelLessThan (QLabel * L1, QLabel * L2){
    // compares l1 name to l2 name
    return L1->objectName() < L2->objectName();
}

void MainWindow::setSpaceList(){
    /*
     * gets list of labels from mainwindow.ui, sets as spaceList
     *
     * order of board:
     *  5 6 6
     *  4   8
     *  3 2 1
     *
*/

    QList<QLabel *> list = ui->Board->findChildren<QLabel *>();

    std::sort(list.begin(), list.end(), labelLessThan );
    list.takeFirst();

    this->SpaceList = list;

}

void MainWindow::setGameSpaceList(){
  this->GameSpaceList = game->getGameSpaceList();
}

void MainWindow::on_pushButton_clicked(){
    // int v1 = dieRoll();
    // int v2 = dieRoll();
    // int total = v1 + v2;
    int die1 = game->dieRoll();
    int die2 = game->dieRoll();

    // move player.
    this->game->movePlayer(die1, die2);


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
  // TODO keep track of previous position and reset on move.
  qDebug() << "setting player position to :" << index;
  SpaceList[index]->setText("player here");
  SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/car.png"));

  // update information display
  std::string currentProperty = game->getPropertyName();
  int currentPropertyCost = game->getPropertyCost();
  int currentPropertyRent = game->getPropertyRent();
//  std::string currentPropertyInfo = game->getPropertyInfo();

}

/* note for later, if we want to get info on a selected property, we could
I really just need the index of that click and then look it up in gameSpaceList

*/

void MainWindow::startGame(int playerCount){
 /*
     * called when start game button is pressed.
     * makes a new game instance and players and lists.
     *
*/

    Game *game = new Game(playerCount);
    setGame(game);

//    srand(time(NULL));

    setSpaceList();
    QList<QLabel *>spaceList = getSpaceList();
    QList<PropertyType *> gameSpaceList = game->getGameSpaceList();

}


void MainWindow::on_pushButton_2_clicked()
{
    int pCount = ui->playerCount->value();
    startGame(pCount);
    ui->NewGame->setHidden(true);
}
