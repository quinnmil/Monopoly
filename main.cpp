#include <cstdlib>
#include <string>
#include <iostream>
#include "player.hpp"
#include "property.hpp"
#include "propertytype.hpp"
#include "game.hpp"
#include "mainwindow.h"
#include <QApplication>
#include "login.h"


//MAIN
int main(int argc, char *argv[]){
//    runGame();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    srand(time(NULL)); // for random rools.
    return a.exec();

	return 0;
}
