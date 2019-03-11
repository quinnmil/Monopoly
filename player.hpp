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
	
    QList<Property*> getProperty();
    void setProperty(Property *property);

    QList<SpecialCard*> getSpecialCards();
    void setSpecial(SpecialCard* special);
	
    unsigned int getPosition();
    void setPosition(int die1, int die2);
	
    int getJailTime();
    void setJailTime(int jailTime);
private:
	string name;
    int piece;
	int money;
    QList<Property*> ownedProperty;
    QList<SpecialCard*> ownedSpecialCards;
    unsigned int position;
    int jailTime; //Think about how this will work

};

#endif /* PLAYER_HPP_ */
