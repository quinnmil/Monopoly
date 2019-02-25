#ifndef GAME_HPP_
#define GAME_HPP_
#include <cstdlib>
#include <string>
#include <vector>
#include "boardSpace.hpp"

class Game{
public:
	Game();
	~Game();
	void newGame();
	int getTurn();
	void rollDice();
	void buyProperty();
	void payRent();
	void payPlayer();
	void startTrade();
	void jailPlayer();
	void movePlayer();
	void addHouse(BoardSpace boardSpace);
	void addHotel(BoardSpace boardSpace);
private:
	int turn;
	int die1, die2;
	int bankMoney;
};
#endif /* GAME_HPP_ */
