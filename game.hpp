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

    Game(); //Constructor
    Game(QString p1, QString p2); //Overloaded Constructor
    ~Game(); //Deconstructor

    //********************
    //
    //Get Functions
    //
    //********************

    QList<int> getAllPositions(); //List of indices of players on the board
    int getDieOne(); //Returns result of die roll
    int getDieTwo();

    PlayerType* getCurrentPlayer(); //Returns current player
    QList<PlayerType*> getPlayerList(); //Returns list of all players
    int getPlayerPosition(PlayerType player); //Returns where a given player is on the board
    string getCurrentPlayerName(); //Returns current player's name
    int getCurrentPlayerIndex(); //Returns player's index in player list

    QList<Property*> getGameSpaceList(); //Returns the list of properties
    string getPropertyName(); //Returns property name
    string getPropertyOwner(); //Returns property owner
    int getPropertyCost(); //Returns property cost
    int getPropertyRent(); //Returns property rent
    int getPropertyHouses(); //Returns # houses on property
    int getPropertyHotels(); //Returns # hotels on property
    bool getIsPropertyActive(); //Returns if the property is mortgaged, true = unmortgaged
    int getPropertyOneHouse(); //Returns rent with 1 house
    int getPropertyTwoHouse();
    int getPropertyThreeHouse();
    int getPropertyFourHouse();
    int getPropertyHotelRent(); //Returns rent with a hotel
    int countColors(PlayerType *player, string color); //Returns how many properties a player owns of the same color

    //********************
    //
    //Game Functions
    //
    //********************

    void addBoardSpaces(); //Adds board spaces to property list
    void addSpecialCards(); //Adds special cards to chance/community chest lists
    int dieRoll(); //Rolls dice
    void movePlayer(int die1, int die2); //Moves player
    void incrementCurrentPlayer(); //Changes who's turn it is
    void endturn(); //Ends turn
    void startTrade(PlayerType *p1, PlayerType *p2, Property *property); //Unfinished
    void jailPlayer(); //Sends player to jail

    //********************
    //
    //Money Functions
    //
    //********************

    void buyProperty(); //Buy the property you are currently on
    void payRent(int rent); //Pay rent to owner of property
    void payPlayer(PlayerType *p1, PlayerType *p2, int value); //Pay a player
    void payTax(); //Pays Tax
    int getFreeParking(); //Pays the current player the money that is sitting in free parking
    void transferMoney(PlayerType *p1, int amount, bool ifTax); //Pays tax to free parking

    //********************
    //
    //Special Card Functions
    //
    //********************

    void handleSpecialCard(SpecialCard *special); //Handles cases for special cards

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
