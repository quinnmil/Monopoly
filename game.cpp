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

    //Adds properties to gameSpaceList(Instantiated in header)
    for(int i = 0; i < 40; i++){
        PropertyType *property;
        gameSpaceList.push_back(property);
    }

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
    //Adds properties to gameSpaceList(Instantiated in header)
    for(int i = 0; i < 40; i++){
        // MASON -- please make sure you are actually creating these objects, debugging this took almost an hour.
        // ( if you declare a pointer, it needs to actually point to something )
        PropertyType *property = new Property;
        gameSpaceList.push_back(property);
    }

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

// gameSpaceList -> list of BoardSpaces (have a list of players, and property)
// thinking about this, we might not actually need to keep a list of players on that position. Could store property directly here...
QList<PropertyType*> Game::getGameSpaceList(){
    return gameSpaceList;
}

//Gets name of property that current player is on
string Game::getPropertyName(){
    // 'player' could/should be replaced with a CurrentPlayer pointer you keep in this class.
    int position = currentPlayer->getPosition();
    string name = gameSpaceList.at(position)->getName();
    return name;
}

//Gets name of owner of property current player is on
string Game::getPropertyOwner(){
    int position = currentPlayer->getPosition();
    string prop_owner = gameSpaceList.at(position)->getOwnedBy();
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
    //WE NEED:
    //-NAME
    //-COST
    //-COLOR
    //-MORTGAGE
    //-UNMORTGAGE
    //-COST TO ADD HOUSE
    //-COST TO ADD HOTEL
    //-RENT
    //-RENT IF ALL OF SAME COLOR OWNED
    //-FINE FROM 1 HOUSE
    //-FINE FROM 2 HOUSES
    //-FINE FROM 3 HOUSES
    //-FINE FROM 4 HOUSES
    //-FINE FROM HOTEL
}

//Sets new current player
// IF THIS IS BROKEN ITS A SLIGHT LOGIC ERROR
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
    PropertyType *currProp = gameSpaceList.at(pos);
    if(currProp->getOwnedBy().compare("") == 0){
        //IF NOT OWNED
        if(currentPlayer->getMoney() > currProp->getCost()){
            //IF PLAYER HAS ENOUGH MONEY
            currentPlayer->setMoney(currentPlayer->getMoney() - currProp->getCost()); //Subtract cost from player
            bankMoney += currProp->getCost(); //Add cost to bankMoney
            currentPlayer->setProperty(currProp); //Give player the property
        }
    }
    else{
        //ALREADY OWNED
    }
}

//Pay Rent
void Game::payRent(){
    int pos = currentPlayer->getPosition(); //Gets position of current player
    PropertyType *currProp = gameSpaceList.at(pos); //Gets current property
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
        //Do they own properties?
        //Do they want to sell them?
        p2.setMoney(p2.getMoney() + value);
    }
    else{
        p2.setMoney(p2.getMoney() + value);
    }
}

//Start Trade
void Game::startTrade(PlayerType p1, PlayerType p2, PropertyType property){

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
