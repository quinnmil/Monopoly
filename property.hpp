#define PROPERTY_HPP_
#ifndef PROPERTY_HPP_
#include <cstdlib>
#include <string>
#include "propertytype.hpp"

class Property : public PropertyType{
public:
	Property();
	~Property();
	string getColor();
	int getHouseCost();
	int getHotelCost();
	int getHouseCount();
	int getHotelCount();
private:
	string color;
	int houseCost;
	int hotelCost;
	int houseCount;
	int hotelCount;
};

class SpecialProperty{
	
};
#endif /* PROPERTY_HPP_ */
