#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <cstdlib>
#include <string>
#include <QApplication>
#include "property.hpp"
using namespace std;

class PlayerType{
public:
	PlayerType();
	PlayerType(string &name, string &piece, int money);
	~PlayerType();

	string getName();
	void setName(string &name);

    int getPiece();
    void setPiece(string &piece);
	
	int getMoney();
	void setMoney(int money);
	
    QList<PropertyType*> getProperty();
    void setProperty(PropertyType *property);

	//vector<SpecialCard> getSpecial();
	void setSpecial();
	
    unsigned int getPosition();
    void setPosition(int die1, int die2);
	
	bool getJailStatus();
	void setJailStatus(bool jailStatus);
private:
	string name;
    int piece;
	int money;
    QList<PropertyType*> ownedProperty;
	//vector<SpecialCard> ownedSpecial;
    unsigned int position;
	bool jailStatus;
    int jailTime; //Think about how this will work
};

#endif /* PLAYER_HPP_ */
