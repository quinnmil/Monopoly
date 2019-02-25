#include <cstdlib>
#include <string>
#include <vector>
#include "boardSpace.hpp"
#include "player.hpp"

BoardSpace::BoardSpace(vector<PlayerType> who, PropertyType prop){
	whosHere = who;
	property = prop;
}

BoardSpace::~BoardSpace(){

}

vector<PlayerType> BoardSpace::getWhoIsHere(){
	return whosHere;
}

PropertyType* BoardSpace::getProperty(){
	return property; 
}
