#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_
#include <cstdlib>
#include <string>
#include "propertytype.hpp"
using namespace std;

class Property : public PropertyType{
public:
	Property();
    Property(string name, string &color, int houseCost, int hotelCost);
	~Property();
    string getName();
	string getColor();
	int getHouseCost();
	int getHotelCost();
	int getHouseCount();
	void setHouseCount(int houseCount);
	int getHotelCount();
	void setHotelCount(int hotelCount);
private:
    string name;
	string color;
	int houseCost;
	int hotelCost;
	int houseCount;
	int hotelCount;
};

class SpecialProperty{
public:
    //SpecialProperty();
    //~SpecialProperty();
private:	
};
#endif /* PROPERTY_HPP_ */
