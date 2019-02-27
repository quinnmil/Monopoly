#include <cstdlib>
#include <string>
#include <vector>
#include "player.hpp"
#include "property.hpp"

//Constructor
PlayerType::PlayerType(){
	name = "Player1";
        piece = "Shoe";
        money = 1500;
        //ownedProperty(0);
        //ownedSpecial(0);
        position = 0;
        jailStatus = false;
}

//Overloaded Constructor
PlayerType::PlayerType(string &name, string &piece, int money){
	name = this->name;
	piece = this->piece;
	money = this->money;
	//ownedProperty(0);
	//ownedSpecial(0);
	position = 0;
	jailStatus = false;
}

//Deconstructor
PlayerType::~PlayerType(){

}

//Get Name
string PlayerType::getName(){
	return name;
}

//Set Name
void PlayerType::setName(string &name){
	name = this->name;
}

//Get Piece
string PlayerType::getPiece(){
	return piece;
}

//Set Piece
void PlayerType::setPiece(string &piece){
	piece = this->piece;
}

//Get Money
int PlayerType::getMoney(){
	return money;
}

//Set Money
void PlayerType::setMoney(int money){
	money = this->money;
}

//Get Property
//vector<Property> PlayerType::getProperty(){
//	return ownedProperty;
//}

//Set Property
void PlayerType::setProperty(PropertyType property){
    ownedProperty.push_back(property);
}

//Get Special Cards
//vector<SpecialCard> PlayerType::getSpecial(){
//	return ownedSpecial;
//}

//Set Special Cards
void PlayerType::setSpecial(){

}

//Get Position
unsigned int PlayerType::getPosition(){
	return position;
}

//Set Position
void PlayerType::setPosition(unsigned int position){
	position = this->position;
}

//Get Jail Status
bool PlayerType::getJailStatus(){
	return jailStatus;
}

//Set Jail Status
void PlayerType::setJailStatus(bool jailStatus){
	jailStatus = this->jailStatus;
}
