#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_
#include <cstdlib>
#include <string>
using namespace std;

class Property{
public:
	Property();
    Property(string name, string color, int cost, int rent, int colorSetRent, int perHouseRent, int hotelRent, int houseCost, int hotelCost, int mortgage, int unmortgage);
	~Property();
    string getOwnedBy();
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
    void setOwnedBy(string name);
	void setHouseCount(int houseCount);
	int getHotelCount();
	void setHotelCount(int hotelCount);
    bool canBuy();
private:
    string ownedBy;
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
#endif /* PROPERTY_HPP_ */
