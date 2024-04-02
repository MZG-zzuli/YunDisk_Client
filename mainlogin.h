#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <QWidget>
class Login;
#include"login.h"
#include<QLineEdit>

class mainLogin : public QWidget
{
    Q_OBJECT
public:
    explicit mainLogin(QWidget *parent = nullptr);
    void setNamePs(QString name,QString ps);
signals:
    void regWid();
    void successLogin();
public slots:
    void mylogin();

private:
    Login* fu;
    QLineEdit* name;
    QLineEdit* password;
};

#endif // MAINLOGIN_H
