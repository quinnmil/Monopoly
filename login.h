#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString getPlayerOne();
    QString getPlayerTwo();

private slots:
    void on_enterNameButton_clicked();

private:
    Ui::Login *ui;
    QString playerOne;
    QString playerTwo;
};

#endif // LOGIN_H
