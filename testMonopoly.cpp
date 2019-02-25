#include "player.hpp"
#include "property.hpp"
#include "propertytype.hpp"
#include "boardSpace.hpp"
#include "game.hpp"
#include "board.hpp"

int main(){
	vector<PlayerType> players(4);
	PropertyType *prop;
	BoardSpace x(players, &prop);
	vector<BoardSpace> bs(40);
	for(int i = 0; i < 40; i++){
		bs.push_back(&prop);
	}
	Board board(bs);
	return 0;
}

