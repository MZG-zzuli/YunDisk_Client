#include "mainlogin.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QDebug>
mainLogin::mainLogin(QWidget *parent)
    : QWidget{parent}
{
    name=new QLineEdit;
    password=new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    QLabel* nm=new QLabel("username");
    QLabel* pw=new QLabel("password");
    QVBoxLayout* mainLayout=new QVBoxLayout;
    this->setLayout(mainLayout);
    mainLayout->addStretch(10);
    QHBoxLayout* hbox1=new QHBoxLayout;
    hbox1->addWidget(nm);
    hbox1->addWidget(name);

    mainLayout->addLayout(hbox1);
    mainLayout->addStretch(0);
    QHBoxLayout* hbox2=new QHBoxLayout;
    hbox2->addWidget(pw);
    hbox2->addWidget(password);
    mainLayout->addLayout(hbox2);
    mainLayout->addStretch(20);

    QHBoxLayout* dlZc=new QHBoxLayout;
    QPushButton* dl=new QPushButton(QStringLiteral("登录"));
    QPushButton* zc=new QPushButton(QStringLiteral("注册"));
    connect(zc,&QPushButton::clicked,this,[this]{
        emit regWid();
        qDebug()<<"===aaa==";
    });

    dlZc->addWidget(dl);
    dlZc->addWidget(zc);
    mainLayout->addLayout(dlZc);
    mainLayout->addStretch(10);



}
