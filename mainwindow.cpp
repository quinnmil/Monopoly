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
    /*
     * Constructor:
     * gets player names from login screen,
     * and then calls startGame()
     */
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Sets up login screen
    Login login;
    login.setModal(true);
    login.exec();

    this->setWindowTitle("Monopoly");
    ui->endTurn_button->setText("Roll dice first!");
    ui->endTurn_button->setEnabled(false);
    // get player names.
    QString p1Name = login.getPlayerOne();
    QString p2Name = login.getPlayerTwo();

    QFont f("Sans Serif", 14, QFont::Bold); //Creates bold font to use
    //Beautify player's money label
    ui->p1Money->setAlignment(Qt::AlignCenter);
    ui->p2Money->setAlignment(Qt::AlignCenter);
    ui->p1Money->setFont(f);
    ui->p2Money->setFont(f);

    this->startGame(p1Name, p2Name);
    this->updateDisplay();
}

MainWindow::~MainWindow()
// deconstructor.
{
    delete ui;
}

void MainWindow::startGame(QString p1, QString p2){
 /*
     * called when start game button is pressed.
     * makes a new game instance and gets:
         * GameSpaceList - list of 40 property objects
         * PlayerList - list of playerType objects
*/

    Game *game = new Game(p1, p2);
    setGame(game);

    setSpaceList();
    this->GameSpaceList = game->getGameSpaceList();
    this->PlayerList = game->getPlayerList();

}

void MainWindow::endGame(){
    /* called when one player forfits the game.
     * picks a winner based on amount of money remaining.
     * displayes winner and ends game.
     */
    QString name;
    // get winner.
    if (PlayerList[0]->getMoney() > PlayerList[1]->getMoney()){
        // player 1 wins
       QString name = QString::fromStdString(PlayerList[0]->getName());
    }
    else {
        // player 2 wins
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
        // call game deconstructor and delete mainWindow.
        delete this->getGame();
        delete this;

    }


}

void MainWindow::updateDisplay(){
    /* upDateDisplay updates the board graphics
     * (player piece locations and current spot highlight,
     * and the current property info display,
     */

    // reset the board first. (clears every space)
    for (int i=0; i<SpaceList.length(); i++) {
        SpaceList[i]->setStyleSheet("");
        SpaceList[i]->clear();
    }

    //********************
    //UPDATE BOARD DISPLAY
    //********************


  PlayerType* currentPlayer = game->getCurrentPlayer();
  //
  for (int j=0; j< PlayerList.length(); j++){
      int index = game->getPlayerPosition(*PlayerList[j]);
      if (PlayerList[j] == currentPlayer){
          // highlight current player position
          SpaceList[index]->setStyleSheet("background: rgba(62, 162, 47,.5)");
      }


      // implemented for two players. can add more pieces later.
      qDebug() << "update location for player : " << QString::fromStdString(PlayerList[j]->getName());
      switch (PlayerList[j]->getPiece()){
      case 1:
          SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/hat.png"));
          break;
      case 2:
          SpaceList[index]->setPixmap(QPixmap(":/graphics/Graphics/car.png"));
          break;

      }

  }

    //********************
    //UPDATE INFORMATION
    //********************

  // update information display
  QString currentProperty = QString::fromStdString(game->getPropertyName());
  QString currentPropertyOwner = QString::fromStdString(game->getPropertyOwner());
  int currentPropertyCost = game->getPropertyCost();
  int currentPropertyRent = game->getPropertyRent();
  int currentPropertyHouses = game->getPropertyHouses();
  int currentPropertyHotels = game->getPropertyHotels();
  int currentOneHouse = game->getPropertyOneHouse();
  int currentTwoHouse = game->getPropertyTwoHouse();
  int currentThreeHouse = game->getPropertyThreeHouse();
  int currentFourHouse = game->getPropertyFourHouse();
  int currentHotel = game->getPropertyHotelRent();

  ui->label_playersTurn->setText(QString::fromStdString(currentPlayer->getName())+ "'s turn");
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
  ui->label->setText(QString::fromStdString(PlayerList[0]->getName())+"'s Money");
  ui->label_3->setText(QString::fromStdString(PlayerList[0]->getName())+"'s Property");
  ui->label_2->setText(QString::fromStdString(PlayerList[1]->getName())+"'s Money");
  ui->label_4->setText(QString::fromStdString(PlayerList[1]->getName())+"'s Propery");


  //update game stats
  ui->p1Money->setText(QString::number(PlayerList[0]->getMoney()));
  ui->p2Money->setText(QString::number(PlayerList[1]->getMoney()));
  ui->p1Property->setText(QString("%1 Properties").arg(QString::number(PlayerList[0]->getProperty().length())));
  ui->p2Property->setText(QString("%1 Properties").arg(QString::number(PlayerList[1]->getProperty().length())));

}


void MainWindow::displayOptions(){
    /*
     * displayOptions deals with the actual landing on a position.
     * it will offer to buy property, manage rent paying, handle
     * special property situations.
     * handles majority of "gameplay" functionality.
     */
    PlayerType* currentPlayer = game->getCurrentPlayer();
    Property *currentProperty = GameSpaceList[game->getCurrentPlayer()->getPosition()];
    QString name = QString::fromStdString(currentProperty->getName());

    if (currentProperty->canBuy()){ // if the spot is a standard property.

        // if unowned - offer to purchase
        if (currentProperty->getOwnedBy() == ""){
            if (currentProperty->getCost() < currentPlayer->getMoney()){ // if the player can afford to buy the property
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
                    // later versions could implement a bidding system.
                }
                }

            }
            else { // if the player can't afford the purchase, let them know.
                QString title = "Can't purchase " + name;
                QString message = QString("%1 is unowned, but you don't have enough money to purchase. Price: $%2").arg(name).arg(QString::number(currentProperty->getCost()));
                QMessageBox offer;



                offer.setWindowTitle(title);
                offer.setText(message);
                offer.setStandardButtons(QMessageBox::Ok);
                offer.exec();
            }
        }

        //********************
        //    PAYING RENT
        //********************
        else { // if property is owned
            PlayerType *owner;
            // workaround to get playerType object from propery.
            for(int i = 0; i < PlayerList.length(); i++){
                if(currentProperty->getOwnedBy().compare(PlayerList.at(i)->getName()) == 0){ //If owner of current property == PlayerType.getName()
                    owner = PlayerList.at(i);
                }
            }


            if (currentProperty->getIsActive() && currentProperty->getOwnedBy() != currentPlayer->getName()){ // if not mortaged and owned by someone else
                int rentCost = 0; // initalize rent cost


                // non-standard properties with non-standard rent prices, defined by game rules.
                if (currentProperty->getColor() == "Railroad"){
                    rentCost = 25 * game->countColors(owner, currentProperty->getColor());
                }

                if (currentProperty->getColor() == "Utilities"){
                    int roll = getdie1() + getdie2();
                    if (game->countColors(owner, currentProperty->getColor())==2){
                    rentCost = (roll * 10);
                    }
                    else {
                        rentCost = (roll * 4);
                    }
                }

                // if property has a hotel.
                else if (currentProperty->getHotelCount() != 0){
                    rentCost = currentProperty->getHotelRent();
                }
                // per house rent increase is non-standard and varries property-by-property.
                switch (currentProperty->getHouseCount()) {
                case 0: // if no houses
                    rentCost = currentProperty->getRent();
                    break;
                case 1: // if one house etc..
                    rentCost = currentProperty->getOneHouseRent();
                    break;
                case 2:
                    rentCost = currentProperty->getTwoHouseRent();
                    break;
                case 3:
                    rentCost = currentProperty->getThreeHouseRent();
                    break;
                case 4:
                    rentCost = currentProperty->getFourHouseRent();
                    break;
                default:
                    break;
                }

                if (currentPlayer->getMoney() > currentProperty->getRent()) { // if user has enough money to pay rent
                    // display window notifying of rent payment.
                    QString title = name;
                    QString message = QString("You landed on %1, and pay $%2 to %3.").arg(name).arg(rentCost).arg(QString::fromStdString(currentProperty->getOwnedBy()));
                    game->transferMoney(game->getCurrentPlayer(),game->getFreeParking(),false);
                    QMessageBox info;
                    info.setWindowTitle(title);
                    info.setText(message);
                    info.setStandardButtons(QMessageBox::Ok);
                    info.exec();
                    game->payRent(rentCost);
                }
                else { // not enough money to pay
                    // display window offering options to forfit or mortage property
                    QMessageBox warning;
                    QString title = "Insufficient funds!";
                    QString message = "You are unable unable to pay rent! \n"
                                      "Either mortgage property, or declare bankruptcy.";
                    QAbstractButton* declare = warning.addButton(("I...DECLARE...BANKRUPTCY"),QMessageBox::YesRole);
                    QAbstractButton* mortage = warning.addButton(("Mortgage Property"),QMessageBox::NoRole);
                    warning.exec();

                    if (warning.clickedButton()==declare){
                        this->endGame();
                    }

                    // opens property management window.
                    if (warning.clickedButton()==mortage){
                        PropertyDisplay *p = new PropertyDisplay(this, currentPlayer);
                        p->setModal(true);
                        p->exec();
                    }
                }
            }
        }

    }
    //********************
    // SPECIAL SPACES
    //********************

    else { // space is not purchasable property. - then it is a "special space".
        // if GO -- do nothing. (set up for house rules to pay extra when landing on go.
        if (currentProperty->getName() == "GO"){
            game->transferMoney(game->getCurrentPlayer(), 0, false);
        }


        // if community chest
        if (currentProperty->getName() == "Community Chest"){
            // draw community chest card.
            // note: in current inplemtation, chance and community chest draw from the same deck.
            drawCard();
        }

        // if income tax
        if (currentProperty->getName() == "Income Tax"){
            game->transferMoney(game->getCurrentPlayer(), 200, true);
            QString title = "Income Tax";
            QString message = "You pay $200 for income tax.";
            QMessageBox info;
            info.setWindowTitle(title);
            info.setText(message);
            info.setStandardButtons(QMessageBox::Ok);
            info.exec();
            updateDisplay();
        }

        // if chance
        if (currentProperty->getName() == "Chance"){
            // draw chance card
            drawCard();
            updateDisplay();
        }

        // if just visiting jail
        if (currentProperty->getName() == "Jail"){
            // nothin
        }

        // if free parking - collect money paid in tax so far.
        if (currentProperty->getName() == "Free Parking"){
            // display message announcing the payment and amount.
            QString title = "Free Parking!";
            QString message = QString("Congratulations, you land on free parking and collect $%1!").arg(QString::number(game->getFreeParking()));
            game->transferMoney(game->getCurrentPlayer(),game->getFreeParking(),false);
            QMessageBox info;
            info.setWindowTitle(title);
            info.setText(message);
            info.setStandardButtons(QMessageBox::Ok);
            info.exec();
            updateDisplay();
        }


        // if go to jail
        if (currentProperty->getName() == "Go to Jail"){
            game->jailPlayer();
            QString title = "Go to Jail";
            QString message = "Go directly to jail. Do not pass GO. Do not collect $200.";
            QMessageBox info;
            info.setWindowTitle(title);
            info.setText(message);
            info.setStandardButtons(QMessageBox::Ok);
            info.exec();
            updateDisplay();
        }

        // if luxury tax
        if (currentProperty->getName() == "Luxury Tax"){
            game->transferMoney(game->getCurrentPlayer(), 75, true);
            QString title = "Luxury Tax";
            QString message = "You pay $75 for luxury tax.";
            QMessageBox info;
            info.setWindowTitle(title);
            info.setText(message);
            info.setStandardButtons(QMessageBox::Ok);
            info.exec();
            updateDisplay();
        }
    }

}



//********************
//ROLL DICE BUTTON
//********************
void MainWindow::on_pushButton_clicked(){

    setDie1(game->getDieOne());
    setDie2(game->getDieTwo());

    int die1 = getdie1();
    int die2 = getdie2();

    // update dice display
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
    // if player not in jail
    if (game->getCurrentPlayer()->getJailTime() == 0) {
        // move player.
        this->game->movePlayer(die1, die2);

    }
    else {
        if (die1 == die2){
            // if they roll doubles.
            game->getCurrentPlayer()->setJailTime(0);
            this->game->movePlayer(die1, die2);
            int ret = QMessageBox::information(this, tr("Jail Escape!"),
                                           tr("You roll doubles and and break out of prison!"),
                                           QMessageBox::Ok);

        }
        else {game->getCurrentPlayer()->setJailTime(game->getCurrentPlayer()->getJailTime()-1);
            int ret = QMessageBox::information(this, tr("In Jail"),
                                           tr("You're still in jail, roll doubles or wait %1 more turns!").arg(QString::number(game->getCurrentPlayer()->getJailTime())),
                                           QMessageBox::Ok);
        }

    }

    updateDisplay();
    displayOptions();

    // disable button after dice rolled.
    ui->pushButton->setEnabled(false);

    // now the player can end turn.
    ui->endTurn_button->setText("End turn");
    ui->endTurn_button->setEnabled(true);

}


//********************
//END TURN BUTTON
//********************
void MainWindow::on_endTurn_button_clicked()

{

    game->endturn();
    updateDisplay();
    ui->endTurn_button->setDisabled(true);
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

//********************
//UTILITY FUNCTIONS
//********************

void MainWindow::drawCard(){
    /* draws random card from chance/community chest.
     * not using specialCard class right not to save time.
     * Could get around to implement later.
    */
    int i = rand()%1;
    QList<int> values = {-50, 50, 15, -10, 100, -20}; // game->transferMoney subtracts value (usually used for tax)
    QList<QString> messages = {"You receive first place at the Eugene Luks Programming Contest!\n"
                              "Receive $50 in prize money.", "Celebrate passing 330 at Taylor's, lose $30",
                              "Speeding Fine, pay $15", "You have won second prize in a beauty contest. Collect $10",
                              "Hospital Fees. Pay $100.","Income tax refund. Collect $20."};

    QString title = "Card draw";
    QString message = messages[i];
    QMessageBox win;
    win.setWindowTitle(title);
    win.setText(message);
    game->transferMoney(game->getCurrentPlayer(),values[i],false);
    win.exec();
    updateDisplay();

}


bool labelLessThan (QLabel * L1, QLabel * L2){
    // compares l1 name to l2 name. used for sort in setspaceList()
    return L1->objectName() < L2->objectName();
}

void MainWindow::setSpaceList(){
    /*
     * gets list of labels from mainwindow.ui, sets as spaceList
     *  sorts by object name.
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
