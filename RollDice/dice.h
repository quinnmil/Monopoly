#ifndef DICE_H
#define DICE_H

#include <QMainWindow>

namespace Ui {
class dice;
}

class dice : public QMainWindow
{
    Q_OBJECT

public:
    explicit dice(QWidget *parent = nullptr);
    ~dice();

private:
    Ui::dice *ui;
};

#endif // DICE_H
