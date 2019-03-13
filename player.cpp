#include <cstdlib>
#include <string>
#include <vector>
#include "player.hpp"
#include "property.hpp"

//********************
//
//Constructors/Deconstructor
//
//********************

//Constructor
PlayerType::PlayerType(){
	name = "Player1";
    piece = 1;
    money = 1500;
    position = 0;
    jailTime = 0;
}

//Overloaded Constructor
PlayerType::PlayerType(string &name, string &piece, int money){
    this->name = name;
    this->money = money;
    setPiece(piece);
	position = 0;
    jailTime = 0;
}

//Deconstructor
PlayerType::~PlayerType(){

}

//********************
//
//GET FUNCTIONS
//
//********************

//Get Name
string PlayerType::getName(){
    return name;
}

//Get Piece
int PlayerType::getPiece(){
    return piece;
}

//Get Money
int PlayerType::getMoney(){
    return money;
}

//Get Jail Status
int PlayerType::getJailTime(){
    return jailTime;
}

//Get Position
unsigned int PlayerType::getPosition(){
    return position;
}

//Get Property
QList<Property*> PlayerType::getProperty(){
    return ownedProperty;
}

//Get Special Cards
QList<SpecialCard*> PlayerType::getSpecialCards(){
    return ownedSpecialCards;
}

//********************
//
//SET FUNCTIONS
//
//********************

//Set Name
void PlayerType::setName(string &name){
	name = this->name;
}

//Set Piece
void PlayerType::setPiece(string &piece){
    if (piece == "shoe"){
        this->piece = 1;
    }
    else {
        this->piece = 2;
    }
}

//Set Money
void PlayerType::setMoney(int money){
    this->money = money;
}

//Add property to propertyList
void PlayerType::setProperty(Property *property){
    ownedProperty.push_back(property);
}

//Add special card to list
void PlayerType::setSpecial(SpecialCard *special){
    ownedSpecialCards.push_back(special);
}

//Set Position
void PlayerType::setPosition(int die1, int die2){
    position += (die1 + die2);
    if(position > 39){
        // if passes go, pays 200.
        this->setMoney(this->getMoney()+200);
        position = position % 39;
    }
}

//Set Jail Status
void PlayerType::setJailTime(int jailTime){
    this->jailTime = jailTime;
}
