#include <cstdlib>
#include <string>
#include <iostream>
#include "player.hpp"
#include "property.hpp"
#include "propertytype.hpp"
#include "boardSpace.hpp"
#include "game.hpp"
#include "board.hpp"
#include "mainwindow.h"
#include <QApplication>

//GAME FUNCTION
void runGame(){
    vector<PlayerType> players(4); //Amount of players on a boardSpace

    Property *prop = new Property(); //New default property

    BoardSpace space (players, prop); // creates space with "4" players on it and property placeholder

    vector<BoardSpace> spaceList; //Creates object used to instantiate "board"

    for(int i = 0; i < 40; i++){
        spaceList.push_back(space); //Fills spaceList with default boardSpaces
    }

    Board board(spaceList); //Creates board instance

    bool win = false;
    int num_players = 0;
    cout << "Welcome to Monopoly!" << endl;
    cout << "How many players will be playing?: " << endl;
    cin >> num_players;
    for(int i = 0; i < num_players; i++){
        //Ask for all inputs for player vars
        PlayerType pl;
        board.addPlayer(pl);
    }
    unsigned int die1;
    unsigned int die2;
    int turn = 0;
    bool playing = true; //WILL BE LINKED TO A PLAYER BUTTON
    PlayerType *currPlayer; //Current player pointer
    while(!win){
        num_players = num_players % board.getPlayerListSize();
        currPlayer = board.getCurrentPlayer(turn, board.getPlayerList());
        while(playing){
            //Roll dice and assign to die1/die2
            //
        }
    }
}

//MAIN
int main(int argc, char *argv[]){
    runGame();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

	return 0;
}
