#include "propertydisplay.h"
#include "ui_propertydisplay.h"
#include "mainwindow.h"
#include "game.hpp"

PropertyDisplay::PropertyDisplay(QWidget *parent, PlayerType* player) :
    QDialog(parent),
    ui(new Ui::PropertyDisplay)
{
    ui->setupUi(this);


    // get game from parent
    // get propertyList from player

    /*
     *  this generates the list.
        for (int i = 0; i < propetyList.length(); i ++){
            QString name = QString::fromstdstring(propertyList[i]->getName())
            ui->PropertyList->addItem(Qstring)
        }

    then, when property is clicked on. -> get actual property object from name string

    *** yt tutorial: https://www.youtube.com/watch?v=4nyM1_TGXbE&t=368s ***

    ui->nameString = property->getname()
    ui->rentString = property->getRent()
    etc...

    if (player == game->getcurrentPlayer()){
        //then allow them to click on mortage buttons etc
        ui->buttons.setEnabled(true)
        etc...

*/
}

PropertyDisplay::~PropertyDisplay()
{
    delete ui;
}
