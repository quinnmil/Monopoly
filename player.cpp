#include <cstdlib>
#include <string>
#include <vector>
#include "player.hpp"
#include "property.hpp"

//Constructor
PlayerType::PlayerType(){
	name = "Player1";
    piece = 1;
    money = 1500;
    //ownedProperty(0); Unnecessary?
    //ownedSpecial(0); Unnecessary?
    position = 0;
    jailStatus = false;
}

//Overloaded Constructor
PlayerType::PlayerType(string &name, string &piece, int money){
    this->name = name;
    // MASON -- I changed this so I could test with two players.
    setPiece(piece);
    this->money = money;
    //ownedProperty(0); Unnecessary?
    //ownedSpecial(0); Unnecessary?
	position = 0;
	jailStatus = false;
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
bool PlayerType::getJailStatus(){
    return jailStatus;
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
//vector<SpecialCard> PlayerType::getSpecial(){
//	return ownedSpecial;
//}

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
	money = this->money;
}

//Set Property
void PlayerType::setProperty(Property *property){
    ownedProperty.push_back(property);
}

//Set Special Cards
void PlayerType::setSpecial(){

}

//Set Position
void PlayerType::setPosition(int die1, int die2){
    position += (die1 + die2);
    if(position > 40){
        position = position % 40;
    }
}

//Set Jail Status
void PlayerType::setJailStatus(bool jailStatus){
	jailStatus = this->jailStatus;
}
