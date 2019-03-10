#include <cstdlib>
#include <string>
#include <vector>
#include <QDebug>
#include "game.hpp"

//8 Player Default Constructor
Game::Game(){
    // should take number of players as an argument.
    // should create playerlist and gameSpaceList
    // gameSpaceList needs to contain 40 property entries.

    addBoardSpaces(); //Adds properties to gameSpaceList(Instantiated in header)

    //Adds EIGHT players to playerList(Instantiated in header)
    for(int i = 0; i < 8; i++){
        PlayerType *player = new PlayerType; //Creates new player pointer
        playerList.push_back(player); //Adds new player to playerList
    }

    currentPlayer = playerList.at(0); //Sets current player
    die1 = 1; //Do we need these at all?
    die2 = 1;
    bankMoney = 10000; //Be sure to properly set this
}

//Dynamic Overloaded Constructor
Game::Game(int pl){

    addBoardSpaces(); //SHOULD FILL THE ENTIRE BOARD WITH THE CORRECT SPACES

    //Adds players to playerList(Instantiated in header)
    // PLACEHOLDER VARS
    string PLAYER1 = "Player 1";
    string PLAYER2 = "Player 2";
    string PIECE1 = "car";
    string PIECE2 = "shoe";
    PlayerType * playerOne = new PlayerType(PLAYER1, PIECE1, 1000); //Creates new player object
    PlayerType * playerTwo = new PlayerType(PLAYER2, PIECE2, 1000);

    playerList.push_back(playerOne); //Adds new player to playerList
    playerList.push_back(playerTwo);

//    qDebug() << "current playerlist at game creation: " << playerList;


    currentPlayer = playerList.at(0); //Sets current player
    die1 = 1; //Do we need these at all?
    die2 = 1;
    bankMoney = 10000; //Be sure to properly set this
}

//Deconstructor
Game::~Game(){

}

//********************
//
//GET FUNCTIONS
//
//********************

//Gets positions of all players in the board
QList<int> Game::getAllPositions(){
    QList<int> list; //creates list of positions to return
    QList<PlayerType*> players = getPlayerList(); //list "players" now contains the game's full player list
    for(int i = 0; i < players.length(); i++){
        PlayerType *player = players.at(i); //gets player @ position in list
        const unsigned int pos = player->getPosition(); //gets const version of position
        list.push_back(pos); //adds to list that will be returned
    }
    return list;
}

//Gets Die Roll 1
int Game::getDieOne(){
    return dieRoll();
}

//Gets Die Roll 2
int Game::getDieTwo(){
    return dieRoll();
}

//Gets current player
PlayerType* Game::getCurrentPlayer(){
    return currentPlayer;
}

// Playerlist - list of all current players
QList<PlayerType*> Game::getPlayerList(){
    return playerList;
}

//Gets position of a certain player
int Game::getPlayerPosition(PlayerType player){
    return player.getPosition();
}

//Gets Index of current player
int Game::getCurrentPlayerIndex(){
    int currPos = 0;
    for(int i = 0; i < playerList.length(); i++){
        if(currentPlayer->getName().compare(playerList.at(i)->getName()) == 0){
            currPos = i;
        }
    }
    return currPos;
}

//Gets current player name
string Game::getCurrentPlayerName(){
    return currentPlayer->getName();
}

//Gets the entire list of spaces on the board
QList<Property*> Game::getGameSpaceList(){
    return gameSpaceList;
}

//Gets name of property that current player is on
string Game::getPropertyName(){
    int position = currentPlayer->getPosition();
    string name = gameSpaceList.at(position)->getName();
    return name;
}

//Gets name of owner of property current player is on
string Game::getPropertyOwner(){
    int position = currentPlayer->getPosition();
    Property *prop = gameSpaceList.at(position);
    string prop_owner = prop->getOwnedBy();
    return prop_owner;
}

//Gets cost of current property
int Game::getPropertyCost(){
    int pos = currentPlayer->getPosition();
    int cost = gameSpaceList.at(pos)->getCost();
    return cost;
}

//Gets rent of current property
int Game::getPropertyRent(){
    int pos = currentPlayer->getPosition();
    int rent = gameSpaceList.at(pos)->getRent();
    return rent;
}

//********************
//
//SET FUNCTIONS
//
//********************

//Adds all board spaces to gameSpaceList
void Game::addBoardSpaces(){
    //GO
    Property *p0 = new Property("GO", "", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p0);

    //Mediterranean Avenue
    Property *p1 = new Property("Mediterranean Avenue", "Brown", 60, 2, 4, 10, 250, 50, 50, 30, 33);
    gameSpaceList.push_back(p1);

    //Community Chest
    Property *p2 = new Property("Community Chest", "SpecialCard", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p2);

    //Baltic Avenue
    Property *p3 = new Property("Baltic Avenue", "Brown", 60, 2, 4, 10, 250, 50, 50, 30, 33);
    gameSpaceList.push_back(p3);

    //Income Tax
    Property *p4 = new Property("Income Tax", "", 0, 200, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p4);

    //Reading Railroad
    Property *p5 = new Property("Reading Railroad", "Railroad", 200, 25, 200, 0, 0, 0, 0, 100, 110);
    gameSpaceList.push_back(p5);

    //Oriental Avenue
    Property *p6 = new Property("Oriental Avenue", "LightBlue", 100, 6, 12, 30, 550, 50, 50, 50, 55);
    gameSpaceList.push_back(p6);

    //Chance
    Property *p7 = new Property("Chance", "SpecialCard", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p7);

    //Vermont Avenue
    Property *p8 = new Property("Vermont Avenue", "LightBlue", 100, 6, 12, 30, 550, 50, 50, 50, 55);
    gameSpaceList.push_back(p8);

    //Connecticut Avenue
    Property *p9 = new Property("Connecticut Avenue", "LightBlue", 120, 8, 16, 40, 600, 50, 50, 60, 66);
    gameSpaceList.push_back(p9);

    //Jail
    Property *p10 = new Property("Jail", "Jail", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p10);

    //St. Charles Place
    Property *p11 = new Property("St. Charles Place", "Pink", 140, 10, 20, 50, 750, 100, 100, 70, 77);
    gameSpaceList.push_back(p11);

    //Electric Company
    Property *p12 = new Property("Electric Company", "Utilities", 0, 150, 0, 0, 0, 0, 0, 75, 83);
    gameSpaceList.push_back(p12);

    //States Avenue
    Property *p13 = new Property("States Avenue", "Pink", 140, 10, 20, 50, 750, 100, 100, 70, 77);
    gameSpaceList.push_back(p13);

    //Virginia Avenue
    Property *p14 = new Property("Virginia Avenue", "Pink", 160, 12, 24, 60, 900, 100, 100, 80, 88);
    gameSpaceList.push_back(p14);

    //Pennsylvania Railroad
    Property *p15 = new Property("Pennsylvania Avenue", "Railroad", 200, 25, 200, 0, 0, 0, 0, 100, 110);
    gameSpaceList.push_back(p15);

    //St. James Place
    Property *p16 = new Property("St. James Place", "Orange", 180, 14, 28, 70, 950, 100, 100, 90, 99);
    gameSpaceList.push_back(p16);

    //Community Chest
    Property *p17 = new Property("Community Chest", "SpecialCard", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p17);

    //Tennessee Avenue
    Property *p18 = new Property("Tennessee Avenue", "Orange", 180, 14, 28, 70, 950, 100, 100, 90, 99);
    gameSpaceList.push_back(p18);

    //New York Avenue
    Property *p19 = new Property("New York Avenue", "Orange", 200, 16, 32, 80, 1000, 100, 100, 100, 110);
    gameSpaceList.push_back(p19);

    //Free Parking
    Property *p20 = new Property("Free Parking", "FreeParking", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p20);

    //Kentucky Avenue
    Property *p21 = new Property("Kentucky Avenue", "Red", 220, 18, 36, 90, 1050, 150, 150, 110, 121);
    gameSpaceList.push_back(p21);

    //Chance
    Property *p22 = new Property("Chance", "SpecialCard", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p22);

    //Indiana Avenue
    Property *p23 = new Property("Indiana Avenue", "Red", 220, 18, 36, 90, 1050, 150, 150, 110, 121);
    gameSpaceList.push_back(p23);

    //Illinois Avenue
    Property *p24 = new Property("Illinois Avenue", "Red", 240, 20, 40, 100, 1100, 150, 150, 120, 132);
    gameSpaceList.push_back(p24);

    //B & O Railroad
    Property *p25 = new Property("B. & O. Railroad", "Railroad", 200, 25, 200, 0, 0, 0, 0, 100, 110);
    gameSpaceList.push_back(p25);

    //Atlantic Avenue
    Property *p26 = new Property("Atlantic Avenue", "Yellow", 260, 22, 44, 110, 1150, 150, 150, 130, 143);
    gameSpaceList.push_back(p26);

    //Ventnor Avenue
    Property *p27 = new Property("Ventnor Avenue", "Yellow", 260, 22, 44, 110, 1150, 150, 150, 130, 143);
    gameSpaceList.push_back(p27);

    //Water Works
    Property *p28 = new Property("Water Works", "Utilities", 0, 150, 0, 0, 0, 0, 0, 75, 83);
    gameSpaceList.push_back(p28);

    //Marvin Gardens
    Property *p29 = new Property("Marvin Gardens", "Yellow", 280, 24, 48, 120, 1200, 150, 150, 140, 154);
    gameSpaceList.push_back(p29);

    //Go to Jail
    Property *p30 = new Property("Go to Jail", "", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p30);

    //Pacific Avenue
    Property *p31 = new Property("Pacific Avenue", "Green", 300, 26, 52, 130, 1275, 200, 200, 150, 165);
    gameSpaceList.push_back(p31);

    //North Carolina Avenue
    Property *p32 = new Property("North Carolina Avenue", "Green", 300, 26, 52, 130, 1275, 200, 200, 150, 165);
    gameSpaceList.push_back(p32);

    //Community Chest
    Property *p33 = new Property("Community Chest 3", "SpecialCard", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p33);

    //Pennsylvania Avenue
    Property *p34 = new Property("Pennsylvania Avenue", "Green", 320, 28, 56, 150, 1400, 200, 200, 160, 176);
    gameSpaceList.push_back(p34);

    //Short Line
    Property *p35 = new Property("Short Line", "Railroad", 200, 25, 200, 0, 0, 0, 0, 100, 110);
    gameSpaceList.push_back(p35);

    //Chance
    Property *p36 = new Property("Chance", "SpecialCard", 0, 0, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p36);

    //Park Place
    Property *p37 = new Property("Park Place", "Blue", 350, 35, 70, 175, 1500, 200, 200, 175, 193);
    gameSpaceList.push_back(p37);

    //Luxury Tax
    Property *p38 = new Property("Luxury Tax", "", 0, 100, 0, 0, 0, 0, 0, 0, 0);
    gameSpaceList.push_back(p38);

    //Boardwalk
    Property *p39 = new Property("Boardwalk", "Blue", 400, 50, 100, 200, 2000, 200, 200, 200, 220);
    gameSpaceList.push_back(p39);
}

//Adds all special cards to board
void Game::addSpecialCards(){
    //CHANCE CARDS
    SpecialCard *s1 = new SpecialCard("You have been elected as chairman of the board. Pay each player $50.", 0, 50, false, true, false, false, false);
    chanceList.push_back(s1);

    SpecialCard *s2 = new SpecialCard("Go back 3 spaces.", -3, 0, false, false, false, false, false);
    chanceList.push_back(s2);

    SpecialCard *s3 = new SpecialCard("Speeding fine. Pay $15.", 0, 15, false, true, false, false, false);
    chanceList.push_back(s3);

    SpecialCard *s4 = new SpecialCard("Get out of jail free!", 0, 0, false, false, false, true, false);
    chanceList.push_back(s4);

    SpecialCard *s5 = new SpecialCard("Your building loan matures. Collect $150.", 0, 150, true, false, false, false, false);
    chanceList.push_back(s5);

    SpecialCard *s6 = new SpecialCard("Go to jail. Do not pass go. Do not collect $200.", 0, 0, false, false, false, false, true);
    chanceList.push_back(s6);

    SpecialCard *s7 = new SpecialCard("Advance to GO. Collect $200.", 0, 200, true, false, true, false, false);
    chanceList.push_back(s7);

    //COMMUNITY CHEST CARDS
    SpecialCard *c1 = new SpecialCard("Advance to GO. Collect $200.", 0, 200, true, false, true, false, false);
    communityChestList.push_back(c1);

    SpecialCard *c2 = new SpecialCard("Bank error in your favor. Collect $200.", 0, 200, true, false, false, false, false);
    communityChestList.push_back(c2);

    SpecialCard *c3 = new SpecialCard("You have won second prize in a beauty contest. Collect $10.", 0, 10, true, false, false, false, false);
    communityChestList.push_back(c3);

    SpecialCard *c4 = new SpecialCard("Get out of jail free!", 0, 0, false, false, false, true, false);
    communityChestList.push_back(c4);

    SpecialCard *c5 = new SpecialCard("Doctor's fees. Pay $50.", 0, 50, false, true, false, false, false);
    communityChestList.push_back(c5);

    SpecialCard *c6 = new SpecialCard("From sale of stock, you get $50", 0, 50, true, false, false, false, false);
    communityChestList.push_back(c6);

    SpecialCard *c7 = new SpecialCard("You inherit $100.", 0, 100, true, false, false, false, false);
    communityChestList.push_back(c7);

    SpecialCard *c8 = new SpecialCard("It's your birthday. Collect $10 from each player.", 0, 10, true, false, false, false, false);
    communityChestList.push_back(c8);

    SpecialCard *c9 = new SpecialCard("Collect $25 consultancy fee.", 0, 25, true, false, false, false, false);
    communityChestList.push_back(c9);

    SpecialCard *c10 = new SpecialCard("Go to jail. Do not pass go. Do not collect $200.", 0, 0, false, false, false, false, true);
    communityChestList.push_back(c10);

    SpecialCard *c11 = new SpecialCard("Hospital Fees. Pay $100.", 0, 100, false, true, false, false, false);
    communityChestList.push_back(c11);

    SpecialCard *c12 = new SpecialCard("Income tax refund. Collect $20.", 0, 20, true, false, false, false, false);
    communityChestList.push_back(c12);

    SpecialCard *c13 = new SpecialCard("School fees. Pay $50.", 0, 50, false, true, false, false, false);
    communityChestList.push_back(c13);

    SpecialCard *c14 = new SpecialCard("Life insurance matures. Collect $100.", 0, 100, true, false, false, false, false);
    communityChestList.push_back(c14);

    SpecialCard *c15 = new SpecialCard("Holiday fund matures. Collect $100.", 0, 100, true, false, false, false, false);
    communityChestList.push_back(c15);
}

//Sets new current player
void Game::incrementCurrentPlayer(){
    int pos = getCurrentPlayerIndex();
    if(pos + 1 >= playerList.length()){
        pos = (pos+1) % playerList.length();
        currentPlayer = playerList.at(pos);
    }
    else{
        currentPlayer = playerList.at(pos+1);
    }
}

//********************
//
//ACCESS FUNCTIONS
//
//********************

//End Turn
void Game::endturn(){
    incrementCurrentPlayer();
    //Needs Main Window Update Call
}

//Roll a die
int Game::dieRoll(){
    int roll;
    roll = rand()%6+1;
    return roll;
}

//Buy Property
void Game::buyProperty(){
    int pos = currentPlayer->getPosition();
    Property *currProp = gameSpaceList.at(pos);
    if(currProp->getOwnedBy().compare("") == 0){
        //IF NOT OWNED
        if(currentPlayer->getMoney() > currProp->getCost()){
            //IF PLAYER HAS ENOUGH MONEY
            currentPlayer->setMoney(currentPlayer->getMoney() - currProp->getCost()); //Subtract cost from player
            bankMoney += currProp->getCost(); //Add cost to bankMoney
            currentPlayer->setProperty(currProp); //Give player the property
            currProp->setOwnedBy(currentPlayer->getName());
        }
    }
    else{
        //ALREADY OWNED
    }
}

//Pay Rent
void Game::payRent(){
    int pos = currentPlayer->getPosition(); //Gets position of current player
    Property *currProp = gameSpaceList.at(pos); //Gets current property
    int rent = currProp->getRent(); //Gets rent
    if(currProp->getOwnedBy().compare("") > 0){ //If there is an owner of said property
        PlayerType *owner;
        for(int i = 0; i < playerList.length(); i++){
            if(currProp->getOwnedBy().compare(playerList.at(i)->getName()) == 0){ //If owner of current property == PlayerType.getName()
                owner = playerList.at(i);
                currentPlayer->setMoney(currentPlayer->getMoney() - rent); //Subtract rent from current player
                owner->setMoney(owner->getMoney() + rent); //Add rent to owner
            }
        }
    }
}

//Pay Player
void Game::payPlayer(PlayerType p1, PlayerType p2, int value){ //p1 = who is paying, p2 = who is getting paid
    p1.setMoney(p1.getMoney() - value);
    if(p1.getMoney() < 0){
        if(p1.getProperty().length() > 0){
            //Do they own properties?
            //Do they want to sell/mortgage them?
            //If so, sell them and pay p2
            p2.setMoney(p2.getMoney() + value);
        }
        else{
            //Otherwise player removed from game?
        }
    }
    else{
        //If p1 is not bankrupt
        p2.setMoney(p2.getMoney() + value);
    }
}

void Game::transferMoney(PlayerType *p1, int amount, bool ifTax){
    if (ifTax == true){
        // if paying a tax, take money from player and tranfer to free parking pile.
        p1->setMoney(p1->getMoney() - amount);
        this->freeParkingMoney += amount;
    }
}

int Game::getFreeParking(){
    return this->freeParkingMoney;
}

//Start Trade
void Game::startTrade(PlayerType p1, PlayerType p2, Property *property){

}

//Jail Player
void Game::jailPlayer(){
    currentPlayer->setJailStatus(true);
}

//Move Player
void Game::movePlayer(int die1, int die2){
    currentPlayer->setPosition(die1, die2);
}

//Add House
void Game::addHouse(){

}

//Add Hotel
void Game::addHotel(){

}
