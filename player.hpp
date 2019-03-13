#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <cstdlib>
#include <string>
#include <QApplication>
#include "property.hpp"
using namespace std;

class PlayerType{
public:
    //********************
    //
    //Constructors/Deconstructors
    //
    //********************
    PlayerType();
	PlayerType(string &name, string &piece, int money);
	~PlayerType();

    //********************
    //
    //Getters
    //
    //********************
    string getName(); //Gets player name
    int getPiece(); //Gets the piece the player uses
    int getMoney(); //Gets a player's money
    QList<Property*> getProperty(); //Gets the player's owned property list
    QList<SpecialCard*> getSpecialCards(); //Gets the player's stored special cards
    unsigned int getPosition(); //Gets the player's position on the board
    int getJailTime(); //Gets the amount of turns the player is left in jail

    //********************
    //
    //Setters
    //
    //********************
    void setName(string &name); //Set player name
    void setPiece(string &piece); //Set player piece
    void setMoney(int money); //Set player money amount
    void setProperty(Property *property); //Add to player property list
    void setSpecial(SpecialCard* special); //Add special card to special card list
    void setPosition(int die1, int die2); //Set player position on board
    void setJailTime(int jailTime); //Set time player is in jail

private:
	string name;
    int piece;
	int money;
    QList<Property*> ownedProperty;
    QList<SpecialCard*> ownedSpecialCards;
    unsigned int position;
    int jailTime;

};

#endif /* PLAYER_HPP_ */
