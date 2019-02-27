#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <cstdlib>
#include <string>
#include <vector>
#include "property.hpp"
using namespace std;

class PlayerType{
public:
	PlayerType();
	PlayerType(string &name, string &piece, int money);
	~PlayerType();

	string getName();
	void setName(string &name);

	string getPiece();
	void setPiece(string &piece);
	
	int getMoney();
	void setMoney(int money);
	
    vector<PropertyType> getProperty();
    void setProperty(PropertyType property);

	//vector<SpecialCard> getSpecial();
	void setSpecial();
	
    unsigned int getPosition();
    void setPosition(unsigned int position);
	
	bool getJailStatus();
	void setJailStatus(bool jailStatus);
private:
	string name;
	string piece;
	int money;
    vector<PropertyType> ownedProperty;
	//vector<SpecialCard> ownedSpecial;
    unsigned int position;
	bool jailStatus;
};

#endif /* PLAYER_HPP_ */
