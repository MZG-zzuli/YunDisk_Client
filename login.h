#ifndef LOGIN_H
#define LOGIN_H
class regist;
#include "regist.h"
#include"title.h"
#include"shezhi.h"
class mainLogin;
#include"mainlogin.h"
#include<QVBoxLayout>
#include<QDebug>
#include <QWidget>
#include<QStackedWidget>
class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    title *topTitle;
    QStackedWidget *stackWid;
    Shezhi* sz;
    regist* reg;
    mainLogin* dl;
signals:
private:
    int szid,regid,dlid;
};

#endif // LOGIN_H
