#include "propertydisplay.h"
#include "ui_propertydisplay.h"
#include "mainwindow.h"
#include "game.hpp"

//********************
//
//CONSTRUCTOR/DESTRUCTOR
//
//********************
PropertyDisplay::PropertyDisplay(QWidget *parent, PlayerType* player) :
    QDialog(parent),
    ui(new Ui::PropertyDisplay)
{
    ui->setupUi(this);
    this->setWindowTitle("Properties");

    // get game from parent
    // get propertyList from player
    Game *g = ((MainWindow*)parentWidget())->getGame();
    PropertyList = player->getProperty();
    PlayerList = g->getPlayerList();

    for (int i = 0; i < PropertyList.length(); i++){
        QString name = QString::fromStdString(PropertyList[i]->getName());
        ui->PropertyList->addItem(name);
    }

    ui->hotelButton->setEnabled(false); //Always grey until 4 houses
    if(player->getName().compare(g->getCurrentPlayerName()) != 0){
        ui->houseButton->setEnabled(false);
        ui->mortgageButton->setEnabled(false);
        ui->unmortgageButton->setEnabled(false);
    }
    else{
        ui->houseButton->setEnabled(true);
        ui->mortgageButton->setEnabled(true);
        ui->unmortgageButton->setEnabled(true);
    }
}

PropertyDisplay::~PropertyDisplay()
{
    delete ui;
}

//********************
//
//SLOTS
//
//********************

//CLICKING A PROPERTY IN PROPERTYLIST
void PropertyDisplay::on_PropertyList_itemClicked(QListWidgetItem *item)
{
    Game *g = ((MainWindow*)parentWidget())->getGame();
    PlayerType *cp = g->getCurrentPlayer();
    QString currPropName = item->text(); //Property name
    for(int i = 0; i < PropertyList.length(); i++){
        Property *p = PropertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){ //If property matches the given "item"s name

            //Turns bool->QString, if active==true -> "False" is displayed and vice versa
            bool active = p->getIsActive();
            QString is_mortgaged = active ? "False" : "True";

            //Sets display
            ui->nameString->setText(QString::fromStdString(p->getName()));
            ui->colorString->setText(QString::fromStdString(p->getColor()));
            ui->houseString->setText(QString::number(p->getHouseCount()));
            ui->hotelString->setText(QString::number(p->getHotelCount()));
            ui->mortgageString->setText(is_mortgaged);

            //Sets labels on addHouse/addHotel buttons
            ui->houseButton->setText(QString("Add house: $%1").arg(p->getHouseCost()));
            ui->hotelButton->setText(QString("Add hotel: $%1").arg(p->getHotelCost()));
            ui->mortgageButton->setText(QString("Mortgage Property: $%1").arg(p->getMortgage()));
            ui->unmortgageButton->setText(QString("Unmortgage Property: $%1").arg(p->getUnmortgage()));

            ui->houseButton->setDisabled(true);
            // if the player has a monopoly, can buy houses.
            if (g->countColors(cp,p->getColor()) == 3){
                qDebug() << "count colors return 3";
                ui->houseButton->setEnabled(true);
            }

            //Handles mortgage/unmortgage button availability
            if(p->getIsActive() == true){
                //If current player owns this property
                if(cp->getName().compare(p->getOwnedBy()) == 0){
                    ui->mortgageButton->setEnabled(true);
                }
                ui->unmortgageButton->setEnabled(false);
            }
            else{
                //Shows mortgaged properties as RED
                QListWidgetItem *currItem = ui->PropertyList->currentItem();
                currItem->setTextColor(Qt::red);
                //If current player owns this property
                if(cp->getName().compare(p->getOwnedBy()) == 0){
                    ui->unmortgageButton->setEnabled(true);
                }
                ui->mortgageButton->setEnabled(false);
                ui->houseButton->setEnabled(false);
                ui->hotelButton->setEnabled(false);
            }

            //Handles which rent is displayed
            if(p->getHotelCount() > 0){
                ui->hotelButton->setEnabled(false);
                ui->rentString->setText(QString::number(p->getHotelRent()));
            }
            else if(p->getHouseCount() > 0){
                int count = p->getHouseCount();
                //If property has 4 houses and the current player owns it
                if(count == 4 && cp->getName().compare(p->getOwnedBy()) == 0){
                    ui->houseButton->setEnabled(false);
                    ui->hotelButton->setEnabled(true);
                }
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

//CLICKING ADD A HOUSE BUTTON
void PropertyDisplay::on_houseButton_clicked()
{
    Game *g = ((MainWindow*)parentWidget())->getGame();
    PlayerType *cp = g->getCurrentPlayer();
    QString currPropName = ui->PropertyList->currentItem()->text();
    for(int i = 0; i < PropertyList.length(); i++){
        Property *p = PropertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){
            int houses = p->getHouseCount();
            switch(houses){
            case 0:
                p->setRent(p->getOneHouseRent());
                p->setHouseCount(1);
                cp->setMoney(cp->getMoney() - p->getHouseCost());
                break;
            case 1:
                p->setRent(p->getTwoHouseRent());
                p->setHouseCount(2);
                cp->setMoney(cp->getMoney() - p->getHouseCost());
                break;
            case 2:
                p->setRent(p->getThreeHouseRent());
                p->setHouseCount(3);
                cp->setMoney(cp->getMoney() - p->getHouseCost());
                break;
            case 3:
                p->setRent(p->getFourHouseRent());
                p->setHouseCount(4);
                cp->setMoney(cp->getMoney() - p->getHouseCost());
                break;
            default:
                //Shouldn't matter
                break;
            }
        }
    }
}

//CLICKING ADD A HOTEL BUTTON
void PropertyDisplay::on_hotelButton_clicked()
{
    Game *g = ((MainWindow*)parentWidget())->getGame();
    PlayerType *cp = g->getCurrentPlayer();
    QString currPropName = ui->PropertyList->currentItem()->text();
    for(int i = 0; i < PropertyList.length(); i++){
        Property *p = PropertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){
            int hotel = p->getHotelCount();
            if(hotel == 0){
                p->setRent(p->getHotelRent());
                p->setHotelCount(1);
                cp->setMoney(cp->getMoney() - p->getHotelCost());
            }
        }
    }
}

//CLICKING MORTGAGE BUTTON
void PropertyDisplay::on_mortgageButton_clicked()
{
    Game *g = ((MainWindow*)parentWidget())->getGame();
    PlayerType *cp = g->getCurrentPlayer();
    QString currPropName = ui->PropertyList->currentItem()->text();
    for(int i = 0; i < PropertyList.length(); i++){
        Property *p = PropertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){
            p->setActive(false);
            cp->setMoney(cp->getMoney() + p->getMortgage());
        }
    }
}

//CLICKING UNMORTGAGE BUTTON
void PropertyDisplay::on_unmortgageButton_clicked()
{
    Game *g = ((MainWindow*)parentWidget())->getGame();
    PlayerType *cp = g->getCurrentPlayer();
    QString currPropName = ui->PropertyList->currentItem()->text();
    for(int i = 0; i < PropertyList.length(); i++){
        Property *p = PropertyList.at(i);
        if(p->getName().compare(currPropName.toStdString()) == 0){
            p->setActive(true);
            cp->setMoney(cp->getMoney() - p->getUnmortgage());
        }
    }
}

