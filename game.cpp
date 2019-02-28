#include <cstdlib>
#include <string>
#include <vector>
#include "game.hpp"
#include "boardSpace.hpp"

//Constructor
Game::Game(){
    // should take number of players as an argument.
    // should create playerlist and gameSpaceList
    // gameSpaceList needs to contain 40 property entries.

}

//Deconstructor
Game::~Game(){

}
// Playerlist - list of all current players
QList<PlayerType> Game::getPlayerList(){

    return playerList;
}
// gameSpaceList -> list of BoardSpaces (have a list of players, and property)
// thinking about this, we might not actually need to keep a list of players on that position. Could store property directly here...
QList<PropertyType*> Game::getGameSpaceList(){
    return gameSpaceList;
}

string Game::getPropertyName(){
    // 'player' could/should be replaced with a CurrentPlayer pointer you keep in this class.
    PlayerType player = this->getTurn(); // if you use the CurrentPlayer idea, you dont need this line.
    int position = player.getPosition();
    string name = gameSpaceList[position]->getName();
    return name;

}

//New Game
// might not need this function if the constructor does everything, your choice though.
void Game::newGame(){

}

//Get Turn
// probably dont need this either if you instantiate a "currentPlayer" pointer in the constructor and increment it at each call to "endTurn()"
int Game::getTurn(){
	return turn;
}

//Roll Dice
void Game::rollDice(){

}

//Buy Property
void Game::buyProperty(){

}

//Pay Rent
void Game::payRent(){

}

//Pay Player
void Game::payPlayer(PlayerType p1, PlayerType p2){

}

//Start Trade
void Game::startTrade(){

}

//Jail Player
void Game::jailPlayer(){

}

//Move Player
void Game::movePlayer(){

}

//Add House
void Game::addHouse(BoardSpace boardSpace){

}

//Add Hotel
void Game::addHotel(BoardSpace boardSpace){

}

