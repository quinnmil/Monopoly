#include <cstdlib>
#include <string>
#include "property.hpp"

//Constructor
Property::Property() : PropertyType(){
    color = "brown";
	houseCost = 50;
	hotelCost = 100;
	houseCount = 0;
	hotelCount = 0;
}

//Overloaded Constructor
Property::Property(string name, string color, int cost, int rent, int colorRent, int houseRent, int houseCost, int hotelCost) : PropertyType(){
    this->name = name;
    this->color = color;
    this->houseCost = houseCost;
    this->hotelCost = hotelCost;
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

//Get Name
string Property::getName(){
    return name;
}

//Get Color
string Property::getColor(){
	return color;
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

//********************
//
//SET FUNCTIONS
//
//********************

//Set # of Houses
void Property::setHouseCount(int houseCount){
    this->houseCount = houseCount;
}

//Set # of Hotels
void Property::setHotelCount(int hotelCount){
    this->hotelCount = hotelCount;
}
