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

    // hide features before newgame is created.
    ui->Board->setHidden(true);
    ui->Dice->setHidden(true);
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


// ROLL DICE BUTTON
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

    // TODO, MAKE ENDTURN BUTTON AND FUNCTION.
//    game->endturn();
    // disable button after dice rolled.
    ui->pushButton->setEnabled(false);

//    spaceList[total]->setHidden(false);
}
void MainWindow::displayOptions(){
  // if property is unowned, display offer to buy

  // if property is owned, notify player of rent payment.
}

void MainWindow::updateDisplay(){

    // reset the board first
    for (int i=0; i<SpaceList.length(); i++) {
        SpaceList[i]->setStyleSheet("");
        SpaceList[i]->clear();
    }

  // update board dislay
  PlayerType* currentPlayer = game->getCurrentPlayer();
  for (int j=0; j< PlayerList.length(); j++){
      int index = game->getPlayerPosition(*PlayerList[j]);
      if (PlayerList[j] == currentPlayer){
          // update current player position
          SpaceList[index]->setStyleSheet("background: rgba(62, 162, 47,.5)");
      }

      // TODO, add special case where players are on the same spot.
      // implemented for two players. can add more pieces later.
      qDebug() << "update location for player : " << QString::fromStdString(PlayerList[j]->getName());
      switch (PlayerList[j]->getPiece()){
      case 1:
          SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/shoe.png"));
          break;
      case 2:
          SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/car.png"));
          break;

      }

  }

  // update information display
  QString currentProperty = QString::fromStdString(game->getPropertyName());
  int currentPropertyCost = game->getPropertyCost();
  int currentPropertyRent = game->getPropertyRent();

  ui->PropertyString->setText(currentProperty);
//  std::string currentPropertyInfo = game->getPropertyInfo();
  ui->PriceString->setNum(currentPropertyCost);
  ui->RentString->setNum(currentPropertyRent);
}

/*
note for later, if we want to get info on a selected property, we could
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
    this->GameSpaceList = game->getGameSpaceList();
    this->PlayerList = game->getPlayerList();

}

// NEWGAME BUTTON
void MainWindow::on_pushButton_2_clicked()
{
    int pCount = ui->playerCount->value();
    startGame(pCount);

    ui->NewGame->setHidden(true);
    ui->Board->setHidden(false);
    ui->Dice->setHidden(false);
}

void MainWindow::on_endTurn_button_clicked()
// hacky for now, will just call an endTurn() function.
{

    game->endturn();
    updateDisplay();

    ui->pushButton->setEnabled(true);
}
