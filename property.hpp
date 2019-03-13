#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_
#include <cstdlib>
#include <string>
using namespace std;

class Property{
public:
    //********************
    //
    //Constructors/Deconstructors
    //
    //********************
    Property();
    Property(string name, string color, int cost, int rent, int colorSetRent, int perHouseRent, int hotelRent, int houseCost, int hotelCost, int mortgage, int unmortgage);
	~Property();

    //********************
    //
    //Getters
    //
    //********************
    string getOwnedBy();
    string getName();
	string getColor();
    int getCost();
    int getRent();
    int getColorRent();
    int getPerHouseRent();
    int getOneHouseRent();
    int getTwoHouseRent();
    int getThreeHouseRent();
    int getFourHouseRent();
    int getHotelRent();
    int getMortgage();
    int getUnmortgage();
	int getHouseCost();
	int getHotelCost();
	int getHouseCount();
    int getHotelCount();

    //********************
    //
    //Getters
    //
    //********************
    void setOwnedBy(string name);
	void setHouseCount(int houseCount);
	void setHotelCount(int hotelCount);
    void setActive(bool active);
    void setRent(int rent);
    bool canBuy();
    bool getIsActive();

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
    bool isActive;

    int oneHouseRent;
    int twoHouseRent;
    int threeHouseRent;
    int fourHouseRent;
};

class SpecialCard{
public:
    //********************
    //
    //Constructors/Deconstructors
    //
    //********************
    SpecialCard();
    SpecialCard(string message, int move_to, int moneyValue, bool getPaid, bool youPay, bool toGo, bool getOutOfJail, bool toJail);
    ~SpecialCard();

    //********************
    //
    //Getters
    //
    //********************
    string getMessage();
    int getMoveTo();
    int getMoneyValue();
    bool getGetPaid();
    bool getYouPay();
    bool getToGo();
    bool getSprung(); //get out of jail
    bool getToJail(); //go to jail

private:
    string message;
    int move_to; //+ or - position
    int moneyValue;
    bool getPaid;
    bool youPay;
    bool toGo;
    bool getOutOfJail;
    bool toJail;

};

#endif /* PROPERTY_HPP_ */
