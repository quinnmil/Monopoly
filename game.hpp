#ifndef GAME_HPP_
#define GAME_HPP_
#include <cstdlib>
#include <string>
#include <vector>
#include <QApplication>
#include "player.hpp"



class Game{
public:
    //Constructors and Deconstructor

    Game(); // DONE: either use this constructor or use newGame() to create playerList and gameSpaceList
    Game(int pl); //DONE: overloaded for #players parameter
    ~Game(); //DONE

    // These functions are called by MainWindow::Update() and used to update the displays.

    QList<int> getAllPositions(); //DONE: returns list of all player position indexies. (4,37,10)
    int getDieOne();
    int getDieTwo();

    // These give me info relative to a player.

    PlayerType* getCurrentPlayer(); //DONE: gets current player
    QList<PlayerType*> getPlayerList(); //DONE: return qlist of players
    int getPlayerPosition(PlayerType player); //DONE: returns a number 0-40 that i'll use to display location on board
    string getCurrentPlayerName();  //DONE: returns name of current player "player 1" is fine for now
    int getCurrentPlayerIndex(); //DONE: returns index of current player in playerList

    // QUINN-TODO: These are property related AND MAY BE IN MAINWINDOW.CPP

    QList<Property*> getGameSpaceList(); //DONE: returns entire list of properties
    string getPropertyName();   //DONE: name of property ie: "Boardwalk"
    string getPropertyOwner();  //DONE: name of owner or "unowned"
    int getPropertyCost(); //DONE
    int getPropertyRent(); //DONE
    string getPropertyInfo(); // property description if special property, otherwise empty string is fine.


    // These are essential game functions.

    void newGame();  //OUTDATED--USED CONSTRUCTOR: either use this or the constructor to create playerList and gameSpaceList
    void incrementCurrentPlayer();   //DONE: getting the current player is really important. I would keep a CurrentPlayer pointer. Probably rename this function. ("incrementCurrentPlayer()"?)
    int dieRoll(); //DONE: this probably shouldn't return void, maybe an int or a tuple of each roll? However you want to implement. Should also call MainWindow::update();
    void movePlayer(int die1, int die2); //DONE: adds roll to to previous position and calls currentplayer::setposition(int x)
    void endturn();  //HALF-DONE--NEEDS UPDATE FUNCTION: 1. switches CurrentPlayer to next player. 2. Calls MainWindow::update() to update graphics.
    void addBoardSpaces();

    // I would have these next three all use a banker(p1,p2). buyProperty and payRent would just have playerX pay a "banker player" with inf money.

    void buyProperty(); //DONE
    void payRent(); //DONE
    void payPlayer(PlayerType p1, PlayerType p2, int value); //DONE

    // lower priority functions, don't worry about these for now.

    void startTrade(PlayerType p1, PlayerType p2, PropertyType property);
    void jailPlayer(); //DONE
    void addHouse();
    void addHotel();

private:
    PlayerType *currentPlayer;   // this is key, as most of the functions above act relative to the currentPlayer.
    int turn; //is this necessary?
	int die1, die2;
	int bankMoney;

    QList<PlayerType*> playerList;       // a list of playerType objects
    QList<Property*> gameSpaceList;  // a list of PropertyType objects. gameSpaceList[0]->getName() = "Go"  gameSpaceList[40]->getName() = "BoardWalk"
};
#endif /* GAME_HPP_ */
