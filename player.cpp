#include <cstdlib>
#include <string>
#include <vector>
#include "player.hpp"

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
vector<Property> PlayerType::getProperty(){

}

//Set Property
void PlayerType::setProperty(){

}

//Get Special Cards
vector<SpecialCard> PlayerType::getSpecial(){

}

//Set Special Cards
void PlayerType::setSpecial(){

}

//Get Position
int PlayerType::getPosition(){
	return position;
}

//Set Position
void PlayerType::setPosition(int position){
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

