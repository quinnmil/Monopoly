#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>
#include <QGraphicsRectItem>
#include "property.hpp"
#include "game.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateDisplay(); // updates graphics on board display

    void setSpaceList(); // generates spacelist from elements in the MainWindow.ui
    QList<QLabel*>getSpaceList() { return this->SpaceList; }

    void setGameSpaceList();
    QList<Property*> getGameSpaceList() { return this->GameSpaceList; }

    void setPlayerList();
    QList<PlayerType*> getPlayerList() { return this->PlayerList; }

    void drawCard(); // draws card for community chest / chance
    void displayOptions();
    void setGame(Game * game) { this->game = game; }
    Game* getGame(){ return this->game; }

    void startGame(QString p1, QString p2); // starts game with player name arguments.
    void endGame();

private slots:
    void on_pushButton_clicked(); // roll dice button

    void on_endTurn_button_clicked(); // end turn button

    void on_p1Property_clicked(); // "player 1" property button

    void on_p2Property_clicked(); //  "player 2" property button

private:
    Ui::MainWindow *ui;
    Game* game;

    QList <QLabel *> SpaceList; // list of label elements in the ui
    QList<Property*> GameSpaceList; // list of pointers to Properties
    QList<PlayerType*> PlayerList; // list of pointers to PlayerType
};

#endif // MAINWINDOW_H
