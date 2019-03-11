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

    if(player->getName().compare(g->getCurrentPlayer()->getName()) == 0){
        ui->
    }
}

PropertyDisplay::~PropertyDisplay()
{
    delete ui;
}

void PropertyDisplay::on_PropertyList_itemClicked(QListWidgetItem *item)
{
    QString currPropName = item->text();
    Game *g = ((MainWindow*)parentWidget())->getGame();
    QList<Property*> propertyList = g->getCurrentPlayer()->getProperty();
    for(int i = 0; i < propertyList.length(); i++){
        Property *p = propertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){
            ui->nameString->setText(QString::fromStdString(p->getName()));
            ui->colorString->setText(QString::fromStdString(p->getColor()));
            ui->rentString->setText(QString::number(p->getRent()));
            ui->houseString->setText(QString::number(p->getHouseCount()));
            ui->hotelString->setText(QString::number(p->getHotelCount()));
            ui->mortgageString->setText(QString::number(p->getMortgage()));
            ui->unmortgageString->setText(QString::number(p->getUnmortgage()));
        }
    }
}
