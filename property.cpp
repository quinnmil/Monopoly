#include <cstdlib>
#include <string>
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

//********************
//
//SET FUNCTIONS
//
//********************

//Set Owned By
void Property::setOwnedBy(string &name){
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
