#include <cstdlib>
#include <vector>
#include "board.hpp"

Board::Board(vector<BoardSpace> board){
	gameBoard = board;
}

Board::~Board(){

}

BoardSpace Board::getBoardSpace(PlayerType pl){
    unsigned int pos = pl.getPosition();
    return gameBoard.at(pos);
}

void Board::addPlayer(PlayerType pl){
    playerList.push_back(pl);
}

int Board::getPlayerListSize(){
    return playerList.size();
}

PlayerType* Board::getCurrentPlayer(int i, vector<PlayerType> playerList){
    return &playerList.at(i);
}

const vector<PlayerType> Board::getPlayerList(){
    return playerList;
}
