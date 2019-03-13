#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propertydisplay.h"
#include "login.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Sets up login screen
    Login login;
    login.setModal(true);
    login.exec();

    // hide features before newgame is created.
    // ui->Board->setHidden(true);
    // ui->Dice->setHidden(true);

    ui->endTurn_button->setText("Roll dice first!");
    ui->endTurn_button->setEnabled(false);

    QString p1Name = login.getPlayerOne();
    QString p2Name = login.getPlayerTwo();

    QFont f("Sans Serif", 14, QFont::Bold);
    ui->p1Money->setAlignment(Qt::AlignCenter);
    ui->p2Money->setAlignment(Qt::AlignCenter);
    ui->p1Money->setFont(f);
    ui->p2Money->setFont(f);

    this->startGame(p1Name, p2Name);
    this->updateDisplay();
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

    int die1 = game->getDieOne();
    int die2 = game->getDieTwo();

    // move player.
    this->game->movePlayer(die1, die2);


    // update dice
    switch(die1){
    case 1: { ui->label_die1->setPixmap(QPixmap(":/graphics/Graphics/die1.png"));} break;
    case 2: { ui->label_die1->setPixmap(QPixmap(":/graphics/Graphics/die2.png"));} break;
    case 3: { ui->label_die1->setPixmap(QPixmap(":/graphics/Graphics/die3.png"));} break;
    case 4: { ui->label_die1->setPixmap(QPixmap(":/graphics/Graphics/die4.png"));} break;
    case 5: { ui->label_die1->setPixmap(QPixmap(":/graphics/Graphics/die5.png"));} break;
    case 6: { ui->label_die1->setPixmap(QPixmap(":/graphics/Graphics/die6.png"));} break;
    }
    switch(die2){
    case 1: { ui->label_die2->setPixmap(QPixmap(":/graphics/Graphics/die1.png"));} break;
    case 2: { ui->label_die2->setPixmap(QPixmap(":/graphics/Graphics/die2.png"));} break;
    case 3: { ui->label_die2->setPixmap(QPixmap(":/graphics/Graphics/die3.png"));} break;
    case 4: { ui->label_die2->setPixmap(QPixmap(":/graphics/Graphics/die4.png"));} break;
    case 5: { ui->label_die2->setPixmap(QPixmap(":/graphics/Graphics/die5.png"));} break;
    case 6: { ui->label_die2->setPixmap(QPixmap(":/graphics/Graphics/die6.png"));} break;
    }

    updateDisplay();
    displayOptions();

    // disable button after dice rolled.
    ui->pushButton->setEnabled(false);

    // now the player can end turn.
    ui->endTurn_button->setText("End turn");
    ui->endTurn_button->setEnabled(true);

}


void MainWindow::displayOptions(){
    PlayerType* currentPlayer = game->getCurrentPlayer();
    Property *currentProperty = GameSpaceList[game->getCurrentPlayer()->getPosition()];
    QString name = QString::fromStdString(currentProperty->getName());

    if (currentProperty->canBuy()){
        // if the spot is a standard property.

        // if unowned
        if (currentProperty->getOwnedBy() == ""){
            if (currentProperty->getCost() < currentPlayer->getMoney()){
                QString title = "Buy " + name;
                QString message = QString("%1 is unowned. Would you like to purchase for $%2?").arg(name).arg(QString::number(currentProperty->getCost()));
                QMessageBox offer;

                offer.setWindowTitle(title);
                offer.setText(message);
                offer.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                offer.setDefaultButton(QMessageBox::Yes);
                int ret = offer.exec();

                switch (ret) {

                case QMessageBox::Yes:{
                    // buy property.
                    game->buyProperty();
                    updateDisplay();

                }
                case QMessageBox::No:{
                    // might implement bidding later.
                }
                }

            }
            else { // if not enough money to purchase
                QString title = "Can't purchase " + name;
                QString message = QString("%1 is unowned, but you don't have enough money to purchase. Price: $%2?").arg(name).arg(QString::number(currentProperty->getCost()));
                QMessageBox offer;

                offer.setWindowTitle(title);
                offer.setText(message);
                offer.setStandardButtons(QMessageBox::Ok);
                offer.exec();
            }
        }
        else { // if property is owned


            if (currentPlayer->getMoney() > currentProperty->getRent()) { // enough money to pay rent

                QString title = name;
                QString message = QString("You landed on %1, and pay $%2 to %3").arg(name).arg(QString::number(currentProperty->getRent())).arg(QString::fromStdString(currentProperty->getOwnedBy()));
                game->transferMoney(game->getCurrentPlayer(),game->getFreeParking(),false);
                QMessageBox info;
                info.setWindowTitle(title);
                info.setText(message);
                info.setStandardButtons(QMessageBox::Ok);
                info.exec();
                game->payRent();
            }
            else { // not enough money to pay
                QMessageBox warning;
                QString title = "insufficient funds!";
                QString message = "You are unable unable to pay rent! \n"
                                  "Either mortage propperty, or declare bankruptcy";
                QAbstractButton* declare = warning.addButton(("I...DECLARE...BANKRUPTCY"),QMessageBox::YesRole);
                warning.exec();

                if (warning.clickedButton()==declare){
                    this->endGame();
                }
            }
        }

    }
    else { // can't buy this property
        // if GO -- could payout some extra money here, depending on house rules.
        if (currentProperty->getName() == "GO"){
            game->transferMoney(game->getCurrentPlayer(), 0, false);
        }


        // if community chest
        if (currentProperty->getName() == "Community Chest"){
            // draw community chest card.
        }

        // if income tax
        if (currentProperty->getName() == "Income Tax"){
            game->transferMoney(game->getCurrentPlayer(), 200, true);

        }

        // if chance
        if (currentProperty->getName() == "Chance"){
            // draw chance card
        }

        // if just visiting jail
        if (currentProperty->getName() == "Jail"){
            // nothin
        }

        // if free parking
        if (currentProperty->getName() == "FreeParking"){
            QString title = "Free Parking!";
            QString message = QString("congratulations, you land on free parking and collect %1").arg(QString::number(game->getFreeParking()));
            game->transferMoney(game->getCurrentPlayer(),game->getFreeParking(),false);
            QMessageBox info;
            info.setWindowTitle(title);
            info.setText(message);
            info.setStandardButtons(QMessageBox::Ok);
            info.exec();
        }


        // if go to jail
        if (currentProperty->getName() == "Go to Jail"){
            game->jailPlayer();
            QString title = "Go to Jail";
            QString message = "Go directly to jail. Do not pass Go. Do not collect $200";
            QMessageBox info;
            info.setWindowTitle(title);
            info.setText(message);
            info.setStandardButtons(QMessageBox::Ok);
            info.exec();
        }

        // if luxury tax
        if (currentProperty->getName() == "Luxury Tax"){
        game->transferMoney(game->getCurrentPlayer(), 100, true);

        }
    }

}

void MainWindow::updateDisplay(){

    // reset the board first
    for (int i=0; i<SpaceList.length(); i++) {
        SpaceList[i]->setStyleSheet("");
        SpaceList[i]->clear();
    }

  // update board dislay
  PlayerType* currentPlayer = game->getCurrentPlayer();
  ui->label_playersTurn->setText(QString::fromStdString(currentPlayer->getName())+ "'s turn");
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
          SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/boot.png"));
          break;
      case 2:
          SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/car.png"));
          break;

      }

  }


  // update information display
  QString currentProperty = QString::fromStdString(game->getPropertyName());
  QString currentPropertyOwner = QString::fromStdString(game->getPropertyOwner());
//  qDebug() << "PropertyOwner: "  <<  currentPropertyOwner ;
  int currentPropertyCost = game->getPropertyCost();
  int currentPropertyRent = game->getPropertyRent();
  int currentPropertyHouses = game->getPropertyHouses();
  int currentPropertyHotels = game->getPropertyHotels();
  int currentOneHouse = game->getPropertyOneHouse();
  int currentTwoHouse = game->getPropertyTwoHouse();
  int currentThreeHouse = game->getPropertyThreeHouse();
  int currentFourHouse = game->getPropertyFourHouse();
  int currentHotel = game->getPropertyHotelRent();

  ui->propertyString->setText(currentProperty);
  ui->ownerString->setText(currentPropertyOwner);
  ui->priceString->setNum(currentPropertyCost);
  ui->rentString->setNum(currentPropertyRent);
  ui->oneHouseString->setNum(currentOneHouse);
  ui->twoHouseString->setNum(currentTwoHouse);
  ui->threeHouseString->setNum(currentThreeHouse);
  ui->fourHouseString->setNum(currentFourHouse);
  ui->hotelString->setNum(currentHotel);
  ui->infoString->setText(QString("%1 houses, %2 hotels").arg(QString::number(currentPropertyHouses), QString::number(currentPropertyHotels)));

  //update game stats
  ui->p1Money->setText(QString::number(PlayerList[0]->getMoney()));
  ui->p2Money->setText(QString::number(PlayerList[1]->getMoney()));
  ui->p1Property->setText(QString("%1 Properties").arg(QString::number(PlayerList[0]->getProperty().length())));
  ui->p2Property->setText(QString("%1 Properties").arg(QString::number(PlayerList[1]->getProperty().length())));

}
//void MainWindow::PassGo(PlayerType *p1){}

/*
note for later, if we want to get info on a selected property, we could
I really just need the index of that click and then look it up in gameSpaceList
*/

void MainWindow::startGame(QString p1, QString p2){
 /*
     * called when start game button is pressed.
     * makes a new game instance and players and lists.
     *
*/

    Game *game = new Game(p1, p2);
    setGame(game);

    setSpaceList();
    this->GameSpaceList = game->getGameSpaceList();
    this->PlayerList = game->getPlayerList();

}

void MainWindow::endGame(){
    qDebug() << "Game over";
    QString name;
    // get winner.
    if (PlayerList[0]->getProperty().length() > PlayerList[1]->getProperty().length()){
        // player 1 wins
       QString name = QString::fromStdString(PlayerList[0]->getName());
    }
    else {
        QString name = QString::fromStdString(PlayerList[0]->getName());
    }
    QString title = "Game Over";
    QString message = QString("%1 is the winner! Watch out for the FCC!").arg(name);
    QMessageBox win;
    win.setWindowTitle(title);
    win.setText(message);
    QAbstractButton* end = win.addButton(("End Game"),QMessageBox::YesRole);
    win.exec();

    if (win.clickedButton()==end){
        // end game

        delete this->getGame();
        delete this;

}

    // announce winner.

    // set game to being over.
}


void MainWindow::on_endTurn_button_clicked()
// hacky for now, will just call an endTurn() function.
{

    game->endturn();
    updateDisplay();

    ui->pushButton->setEnabled(true);
}



void MainWindow::on_p1Property_clicked()
{
    PropertyDisplay *p = new PropertyDisplay(this, PlayerList.at(0));
    p->setModal(true);
    p->exec();
}

void MainWindow::on_p2Property_clicked()
{
    PropertyDisplay *p = new PropertyDisplay(this, PlayerList.at(1));
    p->setModal(true);
    p->exec();
}
