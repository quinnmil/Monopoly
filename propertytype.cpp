#include <cstdlib>
#include <string>
#include <vector>
#include "propertytype.hpp"

//Constructor
PropertyType::PropertyType(){
	name = "";
	cost = 0;
	rent = 0;
	ownedBy = "";
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
