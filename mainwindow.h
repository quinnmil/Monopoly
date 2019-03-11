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
#include "propertytype.hpp"
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
    void updateDisplay();

    void setSpaceList();
    QList <QLabel *>getSpaceList() { return this->SpaceList; }

    void setGameSpaceList();
    QList<Property*> getGameSpaceList() { return this->GameSpaceList; }

    void setPlayerList();
    QList<PlayerType*> getPlayerList() { return this->PlayerList; }


    void displayOptions();
    void setGame(Game * game) { this->game = game; }
    Game* getGame(){ return this->game; }

    void startGame(QString p1, QString p2);
    void endGame();

private slots:
    void on_pushButton_clicked();

    void on_endTurn_button_clicked();

    void on_p1Property_clicked();

private:
    Ui::MainWindow *ui;
    Game* game;

    QList <QLabel *> SpaceList;
    QList<Property*> GameSpaceList;
    QList<PlayerType*> PlayerList;
};

#endif // MAINWINDOW_H
