#define PLAYER_HPP_
#ifndef PLAYER_HPP_
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class PlayerType{
public:
	PlayerType();
	~PlayerType();

	string getName();
	void setName(string &name);

	string getPiece();
	void setPiece(string &piece);
	
	int getMoney();
	void setMoney(int money);
	
	vector<Property> getProperty();
	void setProperty();
	
	vector<SpecialCard> getSpecial();
	void setSpecial();
	
	int getPosition();
	void setPosition(int position);
	
	bool getJailStatus();
	void setJailStatus(bool jailStatus);
private:
	string name;
	string piece;
	int money;
	vector<Property> ownedProperty;
	vector<SpecialCard> ownedSpecial;
	int position;
	bool jailStatus;
};

#endif /* PLAYER_HPP_ */
