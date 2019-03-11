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

private:
    Ui::PropertyDisplay *ui;
};

#endif // PROPERTYDISPLAY_H
