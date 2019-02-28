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
#include "boardSpace.hpp"
#include "game.hpp"
#include "board.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList <QLabel *>initalizeBoard();
    QList <QLabel *> spaceList;
    QList <BoardSpace> gameSpaceList;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
