#ifndef GAME_HPP_
#define GAME_HPP_
#include <cstdlib>
#include <string>
#include <vector>
#include <QApplication>
#include "boardSpace.hpp"
#include "player.hpp"



class Game{
public:
    Game(); // either use this constructor or use newGame() to create playerList and gameSpaceList
    Game(int pl); //overloaded for #players parameter
    ~Game();

    // these functions are called by MainWindow::Update() and used to update the displays.


    QList<int> getAllPositions(); // returns list of all player position indexies. (4,37,10)
    int getDieOne();
    int getDieTwo();

    // These give me info relative to the position of the current player.
    PlayerType* getCurrentPlayer(); //gets current player
    QList<PlayerType*> getPlayerList(); //return qlist of players
    int getPlayerPosition(PlayerType player); // returns a number 0-40 that i'll use to display location on board
    string getCurrentPlayerName();  // returns name of current player "player 1" is fine for now
    int getCurrentPlayerIndex(); //returns index of current player in playerList
    string getPropertyName();   // name of property ie: "Boardwalk"
    string getPropertyOwner();  // name of owner or "unowned"

    QList<PropertyType*> getGameSpaceList(); //returns entire list of properties
    int getPropertyCost();
    int getPropertyRent();
    string getPropertyInfo(); // property description if special property, otherwise empty string is fine.


    // essential game functions.

    void newGame();  // either use this or the constructor to create playerList and gameSpaceList
    void incrementCurrentPlayer();   // getting the current player is really important. I would keep a CurrentPlayer pointer. Probably rename this function. ("incrementCurrentPlayer()"?)
    int dieRoll(); // this probably shouldn't return void, maybe an int or a tuple of each roll? However you want to implement. Should also call MainWindow::update();
    void movePlayer(int die1, int die2); // adds roll to to previous position and calls currentplayer::setposition(int x)
    void endturn();  // 1. switches CurrentPlayer to next player. 2. Calls MainWindow::update() to update graphics.

    // I would have these next three all use a banker(p1,p2). buyProperty and payRent would just have playerX pay a "banker player" with inf money.
    void buyProperty();
	void payRent();
    void payPlayer(PlayerType p1, PlayerType p2, int value);

    // lower priority functions, don't worry about these for now.
    void startTrade(PlayerType p1, PlayerType p2, PropertyType property);
	void jailPlayer();
	void addHouse(BoardSpace boardSpace);
	void addHotel(BoardSpace boardSpace);

private:
    PlayerType *currentPlayer;   // this is key, as most of the functions above act relative to the currentPlayer.
    int turn;
	int die1, die2;
	int bankMoney;

    QList<PlayerType*> playerList;       // a list of playerType objects
    QList<PropertyType*> gameSpaceList;  // a list of PropertyType objects. gameSpaceList[0]->getName() = "Go"  gameSpaceList[40]->getName() = "BoardWalk"

};
#endif /* GAME_HPP_ */
