#ifndef PROPERTYTYPE_HPP_
#define PROPERTYTYPE_HPP_
#include <cstdlib>
#include <string>
using namespace std;

class PropertyType{
public:
	PropertyType();
	~PropertyType();
	string getName();
	int getCost();
	int getRent();
	string getOwnedBy();
private:
	string name;
	int cost;
	int rent;
    string ownedBy; //PlayerType?
};

#endif /* PROPERTYTYPE_HPP_ */
