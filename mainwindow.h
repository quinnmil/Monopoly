#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtGui>
#include <QTCore>
#include <QGraphicsRectItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
};

int dieRoll();
#endif // MAINWINDOW_H
