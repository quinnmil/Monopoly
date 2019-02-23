#define BOARDSPACE_HPP_
#ifndef BOARDSPACE_HPP_
#include <cstdlib>
#include <vector>
using namespace std;

class BoardSpace{
public:
	BoardSpace();
	oBoardSpace();
	vector<PlayerType> getWhoIsHere();
	PropertyType getProperty();
private:
	vector<PlayerType> whosHere;
	PropertyType *prop;
};

#endif /* BOARDSPACE_HPP_ */
