#ifndef GAME_HPP_
#define GAME_HPP_
#include <cstdlib>
#include <string>
#include <vector>
#include <QApplication>
#include "player.hpp"



class Game{
public:
    //********************
    //
    //Constructors and Deconstructor
    //
    //********************

    Game(); // DONE: either use this constructor or use newGame() to create playerList and gameSpaceList
    Game(QString p1, QString p2); //DONE: overloaded for #players parameter
    ~Game(); //DONE

    //********************
    //
    //Get Functions
    //
    //********************

    QList<int> getAllPositions(); //DONE: returns list of all player position indicies. (4,37,10)
    int getDieOne(); //DONE
    int getDieTwo(); //DONE

    PlayerType* getCurrentPlayer(); //DONE: gets current player
    QList<PlayerType*> getPlayerList(); //DONE: return qlist of players
    int getPlayerPosition(PlayerType player); //DONE: returns a number 0-40 that i'll use to display location on board
    string getCurrentPlayerName();  //DONE: returns name of current player "player 1" is fine for now
    int getCurrentPlayerIndex(); //DONE: returns index of current player in playerList

    QList<Property*> getGameSpaceList(); //DONE: returns entire list of properties
    string getPropertyName();   //DONE: name of property ie: "Boardwalk"
    string getPropertyOwner();  //DONE: name of owner or "unowned"
    int getPropertyCost(); //DONE
    int getPropertyRent(); //DONE
    int getPropertyHouses(); //DONE
    int getPropertyHotels(); //DONE
    bool getIsPropertyActive(); //DONE
    int getPropertyOneHouse();
    int getPropertyTwoHouse();
    int getPropertyThreeHouse();
    int getPropertyFourHouse();
    int getPropertyHotelRent();
    string getPropertyInfo(); // property description if special property, otherwise empty string is fine.

    //********************
    //
    //Game Functions
    //
    //********************

    void addBoardSpaces(); //DONE
    void addSpecialCards(); //WIP
    int dieRoll(); //DONE
    void movePlayer(int die1, int die2); //DONE
    void incrementCurrentPlayer();   //DONE
    void endturn();  //HALF-DONE--NEEDS UPDATE FUNCTION: 1. switches CurrentPlayer to next player. 2. Calls MainWindow::update() to update graphics.
    void startTrade(PlayerType *p1, PlayerType *p2, Property *property); //NEEDS TO BE STARTED, HAS TO WORK WITH INTERFACE.
    void jailPlayer(); //DONE
    void addHouse();
    void addHotel();

    //********************
    //
    //Money Functions
    //
    //********************

    void buyProperty(); //DONE and WORKING
    void payRent(); //DONE and WORKING
    void payPlayer(PlayerType *p1, PlayerType *p2, int value); //NEEDS WORK, NEEDS TO WORK WITH INTERFACE?

    void payTax(); //adds to free parking money
    int getFreeParking(); //gets money in free parking
    void transferMoney(PlayerType *p1, int amount, bool ifTax);

    //********************
    //
    //Special Card Functions
    //
    //********************

    void handleSpecialCard(SpecialCard *special);
    //string getSpecialMessage();


private:
    PlayerType *currentPlayer;   // this is key, as most of the functions above act relative to the currentPlayer.
	int die1, die2;
	int bankMoney;
    int freeParkingMoney;

    QList<PlayerType*> playerList;       // a list of playerType objects
    QList<Property*> gameSpaceList;  // a list of PropertyType objects. gameSpaceList[0]->getName() = "Go"  gameSpaceList[39]->getName() = "BoardWalk"
    QList<SpecialCard*> communityChestList; //--> See that you land on a special card position, pull (and remove) a card from this QList and add it to the PlayerType's special card QList.
    QList<SpecialCard*> chanceList;        // --> After using this card, it will be removed from PlayerType's QList and re-added to the back of the Game Class's QList.
                                           // --> Card will be selected from the Game's QList using a random integer in the .at() function.
};
#endif /* GAME_HPP_ */
