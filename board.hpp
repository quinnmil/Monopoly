#ifndef BOARD_HPP_
#define BOARD_HPP_
#include <cstdlib>
#include <vector>
#include "boardSpace.hpp"

class Board{
public:
	Board(vector<BoardSpace> board);
	~Board();
    BoardSpace getBoardSpace(PlayerType pl);
    void addPlayer(PlayerType pl);
    const vector<PlayerType> getPlayerList();
    int getPlayerListSize();
    PlayerType* getCurrentPlayer(int i, vector<PlayerType> playerList);
private:
	vector<BoardSpace> gameBoard;
    vector<PlayerType> playerList;
};

#endif /* BOARD_HPP_ */
