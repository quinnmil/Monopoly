#include "player.hpp"
#include "property.hpp"
#include "propertytype.hpp"
#include "boardSpace.hpp"
#include "game.hpp"
#include "board.hpp"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){

	vector<PlayerType> players(4);
	// initalizes empty property
	Property *prop = new Property();

	// creates space with 4 players on it and property placeholder
	BoardSpace space (players, prop);

	// lists of spaces
	vector<BoardSpace> spaceList;

	// fills spaceList with same space
	for(int i = 0; i < 40; i++){
		spaceList.push_back(space);
	}
	// creates board
	Board board(spaceList);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

	return 0;
}
