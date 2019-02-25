#include <cstdlib>
#include <string>
#include <vector>
#include "propertytype.hpp"

//Constructor
PropertyType::PropertyType(){
	string name = "Property1";
	cost = 100;
	rent = 25;
	ownedBy = nullptr;
}

//Decconstructor
PropertyType::~PropertyType(){

}

//Get Name
string PropertyType::getName(){
	return name;
}
//Get Cost
int PropertyType::getCost(){
	return cost;
}
//Get Rent
int PropertyType::getRent(){
	return rent;
}
//Get Owner
string PropertyType::getOwnedBy(){
	return ownedBy;
}
