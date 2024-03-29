#include "shezhi.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
Shezhi::Shezhi(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainlayout=new QVBoxLayout;
    this->setLayout(mainlayout);
    QLabel* ipLab=new QLabel(" Ip ");
    QLabel* portLab=new QLabel("Port");
    ip=new QLineEdit;
    port=new QLineEdit;
    QHBoxLayout* hlay1=new QHBoxLayout;
    hlay1->addWidget(ipLab);
    hlay1->addWidget(ip);
    mainlayout->addLayout(hlay1);

    QHBoxLayout* hlay2=new QHBoxLayout;
    hlay2->addWidget(portLab);
    hlay2->addWidget(port);
    mainlayout->addLayout(hlay2);

    QPushButton* but=new QPushButton(QStringLiteral("确认"));
    mainlayout->addWidget(but);



}
