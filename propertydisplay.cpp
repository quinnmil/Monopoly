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
    Game *g = ((MainWindow*)parentWidget())->getGame();
    QList<Property*> propertyList = player->getProperty();
    QList<PlayerType*> playerList = g->getPlayerList();

    for (int i = 0; i < propertyList.length(); i++){
        QString name = QString::fromStdString(propertyList[i]->getName());
        ui->PropertyList->addItem(name);
    }
    /*
     *  this generates the list.
        for (int i = 0; i < propertyList.length(); i++){
            QString name = QString::fromstdstring(propertyList[i]->getName())
            ui->PropertyList->addItem(name)
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

void PropertyDisplay::on_PropertyList_itemClicked(QListWidgetItem *item)
{
    QString currPropName = item->text(); //Property name
    Game *g = ((MainWindow*)parentWidget())->getGame(); //Gets game for currentPlayer
    QList<Property*> propertyList = g->getCurrentPlayer()->getProperty(); //Gets currentPlayer's properties
    for(int i = 0; i < propertyList.length(); i++){
        Property *p = propertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){ //If property matches the given "item"s name
            ui->nameString->setText(QString::fromStdString(p->getName()));
            ui->colorString->setText(QString::fromStdString(p->getColor()));
            ui->houseString->setText(QString::number(p->getHouseCount()));
            ui->hotelString->setText(QString::number(p->getHotelCount()));
            ui->mortgageString->setText(QString::number(p->getMortgage()));
            ui->unmortgageString->setText(QString::number(p->getUnmortgage()));

            //Handles which rent is displayed
            if(p->getHotelCount() > 0){
                ui->rentString->setText(QString::number(p->getHotelRent()));
            }
            else if(p->getHouseCount() > 0){
                int count = p->getHouseCount();
                switch(count){
                case 1:
                    ui->rentString->setText(QString::number(p->getOneHouseRent()));
                    break;
                case 2:
                    ui->rentString->setText(QString::number(p->getTwoHouseRent()));
                    break;
                case 3:
                    ui->rentString->setText(QString::number(p->getThreeHouseRent()));
                    break;
                case 4:
                    ui->rentString->setText(QString::number(p->getFourHouseRent()));
                    break;
                }
            }
            else{ //If no houses/hotels
                ui->rentString->setText(QString::number(p->getRent()));
            }
        }
    }
}
