#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_
#include <cstdlib>
#include <string>
#include "propertytype.hpp"
using namespace std;

class Property : public PropertyType{
public:
	Property();
	Property(string &color, int houseCost, int hotelCost);
	~Property();
	string getColor();
	int getHouseCost();
	int getHotelCost();
	int getHouseCount();
	void setHouseCount(int houseCount);
	int getHotelCount();
	void setHotelCount(int hotelCount);
private:
	string color;
	int houseCost;
	int hotelCost;
	int houseCount;
	int hotelCount;
};

class SpecialProperty{
public:
private:	
};
#endif /* PROPERTY_HPP_ */
