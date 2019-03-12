#include <cstdlib>
#include <string>
#include <cmath>
#include "property.hpp"

//Constructor
Property::Property(){
    ownedBy = "";
    name = "Property1";
    color = "orange";
    cost = 0;
    rent = 0;
    colorSetRent = 0;
    perHouseRent = 0;
    houseCost = 100;
	hotelCost = 100;
	houseCount = 0;
	hotelCount = 0;
    mortgage = 0;
    unmortgage = 0;
    oneHouseRent = 0;
    twoHouseRent = 0;
    threeHouseRent = 0;
    fourHouseRent = 0;
    hotelRent = 0;
}

//Overloaded Constructor
Property::Property(string name, string color, int cost, int rent, int colorSetRent, int perHouseRent, int hotelRent, int houseCost, int hotelCost, int mortgage, int unmortgage){
    ownedBy = "";
    this->name = name;
    this->color = color;
    this->cost = cost;
    this->rent = rent;
    this->colorSetRent = colorSetRent;
    this->perHouseRent = perHouseRent;
    this->hotelRent = hotelRent;
    this->houseCost = houseCost;
    this->hotelCost = hotelCost;
    this->mortgage = mortgage;
    this->unmortgage = unmortgage;
    houseCount = 0;
	hotelCount = 0;

    oneHouseRent = perHouseRent;
    twoHouseRent = oneHouseRent * 3;
    threeHouseRent = twoHouseRent * 2;
    fourHouseRent = floor(threeHouseRent * 1.25);
}

//Deconstructor
Property::~Property(){

}

//********************
//
//GET FUNCTIONS
//
//********************

//Get Owned By
string Property::getOwnedBy(){
    return ownedBy;
}

//Get Name
string Property::getName(){
    return name;
}

//Get Color
string Property::getColor(){
	return color;
}

//Get Cost
int Property::getCost(){
    return cost;
}

//Get Rent
int Property::getRent(){
    return rent;
}

//Get Color Set Rent
int Property::getColorRent(){
    return colorSetRent;
}

//Get Per House Rent
int Property::getPerHouseRent(){
    return perHouseRent;
}

//Get 1 house rent
int Property::getOneHouseRent(){
    return oneHouseRent;
}

//Get 2 house rent
int Property::getTwoHouseRent(){
    return twoHouseRent;
}

//Get 3 house rent
int Property::getThreeHouseRent(){
    return threeHouseRent;
}

//Get 4 house rent
int Property::getFourHouseRent(){
    return fourHouseRent;
}

//Get Rent w/ Hotel
int Property::getHotelRent(){
    return hotelRent;
}

//Get Mortgage Price
int Property::getMortgage(){
    return mortgage;
}

//Get Unmortgage Price
int Property::getUnmortgage(){
    return unmortgage;
}

//Get House Cost
int Property::getHouseCost(){
    return houseCount;
}

//Get Hotel Cost
int Property::getHotelCost(){
	return hotelCost;
}

//Get # of Houses
int Property::getHouseCount(){
	return houseCount;
}

//Get # of Hotels
int Property::getHotelCount(){
    return hotelCount;
}

//
bool Property::canBuy(){
    if (cost == 0){
        return false;
    }
    else {
        return true;
    }
}

bool Property::getIsActive(){
    return isActive;
}

//********************
//
//SET FUNCTIONS
//
//********************

//Set Owned By
void Property::setOwnedBy(string name){
    ownedBy = name;
}

//Set # of Houses
void Property::setHouseCount(int houseCount){
    this->houseCount = houseCount;
}

//Set # of Hotels
void Property::setHotelCount(int hotelCount){
    this->hotelCount = hotelCount;
}

void Property::setActive(bool active){
    isActive = active;
}

void Property::setRent(int rent){
    this->rent = rent;
}

//**************************************************
//
//SPECIAL CARDS
//
//**************************************************

//Constructor
SpecialCard::SpecialCard(){
    message = "default";
    move_to = 0;
    moneyValue = 0;
    getPaid = false;
    youPay = false;
    toGo = false;
    getOutOfJail = false;
    toJail = false;
}

//Overloaded Constructor
SpecialCard::SpecialCard(string message, int move_to, int moneyValue, bool getPaid, bool youPay, bool toGo, bool getOutOfJail, bool toJail){
    this->message = message;
    this->move_to = move_to;
    this->moneyValue = moneyValue;
    this->getPaid = getPaid;
    this->youPay = youPay;
    this->toGo = toGo;
    this->getOutOfJail = getOutOfJail;
    this->toJail = toJail;
}

//Deconstructor
SpecialCard::~SpecialCard(){

}

string SpecialCard::getMessage(){
    return message;
}

int SpecialCard::getMoveTo(){
    return move_to;
}

int SpecialCard::getMoneyValue(){
    return moneyValue;
}

bool SpecialCard::getGetPaid(){
    return getPaid;
}

bool SpecialCard::getYouPay(){
    return youPay;
}

bool SpecialCard::getToGo(){
    return toGo;
}

bool SpecialCard::getSprung(){
    return getOutOfJail;
}

bool SpecialCard::getToJail(){
    return toJail;
}
