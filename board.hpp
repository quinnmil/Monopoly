#define BOARD_HPP_
#ifndef BOARD_HPP_
#include <cstdlib>

class Board{
public:
	Board();
	~Board();
private:
	vector<BoardSpace> gameBoard;
}

#endif /* BOARD_HPP_ */
