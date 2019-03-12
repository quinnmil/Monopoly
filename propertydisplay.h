#ifndef PROPERTYDISPLAY_H
#define PROPERTYDISPLAY_H
#include "mainwindow.h"
#include "game.hpp"

#include <QListWidget>
#include <QDialog>

namespace Ui {
class PropertyDisplay;
}

class PropertyDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit PropertyDisplay(QWidget *parent = nullptr , PlayerType* player = nullptr);
    ~PropertyDisplay();

private slots:
    void on_PropertyList_itemClicked(QListWidgetItem *item);

    void on_houseButton_clicked();

    void on_hotelButton_clicked();

    void on_mortgageButton_clicked();

    void on_unmortgageButton_clicked();

private:
    Ui::PropertyDisplay *ui;
    QList<Property*> PropertyList;
    QList<PlayerType*> PlayerList;
};

#endif // PROPERTYDISPLAY_H
