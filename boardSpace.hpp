#ifndef BOARDSPACE_HPP_
#define BOARDSPACE_HPP_
#include <cstdlib>
#include <vector>
#include "player.hpp"
#include "property.hpp"

using namespace std;

class BoardSpace{
public:
	BoardSpace(vector<PlayerType> who, PropertyType *prop);
	~BoardSpace();
	vector<PlayerType> getWhoIsHere();
	PropertyType * getProperty();
private:
	vector<PlayerType> whosHere;
	PropertyType *property;
};

#endif /* BOARDSPACE_HPP_ */
