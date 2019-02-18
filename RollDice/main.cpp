#include "dice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dice w;
    w.show();

    return a.exec();
}
