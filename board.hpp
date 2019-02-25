#ifndef BOARD_HPP_
#define BOARD_HPP_
#include <cstdlib>
#include <vector>
#include "boardSpace.hpp"

class Board{
public:
	Board(vector<BoardSpace> board);
	~Board();
private:
	vector<BoardSpace> gameBoard;
};

#endif /* BOARD_HPP_ */
