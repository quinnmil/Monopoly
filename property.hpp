#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_
#include <cstdlib>
#include <string>
#include "propertytype.hpp"
using namespace std;

class Property : public PropertyType{
public:
	Property();
    Property(string name, string color, int cost, int rent, int colorSetRent, int perHouseRent, int hotelRent, int houseCost, int hotelCost, int mortgage, int unmortgage);
	~Property();
    string getName();
	string getColor();
    int getCost();
    int getRent();
    int getColorRent();
    int getPerHouseRent();
    int getHotelRent();
    int getMortgage();
    int getUnmortgage();
	int getHouseCost();
	int getHotelCost();
	int getHouseCount();
	void setHouseCount(int houseCount);
	int getHotelCount();
	void setHotelCount(int hotelCount);
private:
    string name;
	string color;
    int cost;
    int rent;
    int colorSetRent;
    int perHouseRent;
    int hotelRent;
	int houseCost;
	int hotelCost;
	int houseCount;
	int hotelCount;
    int mortgage;
    int unmortgage;
};

class SpecialProperty : public PropertyType{
public:
    SpecialProperty();
    ~SpecialProperty();
private:	
};
#endif /* PROPERTY_HPP_ */
