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
Property::Property(string &color, int houseCost, int hotelCost) : PropertyType(){
	color = this->color;
	houseCost = this->houseCost;
	hotelCost = this->hotelCost;
	houseCount = 0;
	hotelCount = 0;
}
//Deconstructor
Property::~Property(){

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

//Set # of Houses
void Property::setHouseCount(int houseCount){
	houseCount = this->houseCount;
}

//Get # of Hotels
int Property::getHotelCount(){
	return hotelCount;
}

//Set # of Hotels
void Property::setHotelCount(int hotelCount){
	hotelCount = this->hotelCount;
}
