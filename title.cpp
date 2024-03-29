#include "title.h"
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QSpacerItem>
#include<QMouseEvent>
title::title(QWidget *parent)
    : QWidget{parent}
{
    fu=parent;
    QHBoxLayout *hlayout=new QHBoxLayout;
    hlayout->setAlignment(Qt::AlignTop);
    QHBoxLayout *hlayoutl=new QHBoxLayout;
    hlayoutl->setAlignment(Qt::AlignLeft);
    QHBoxLayout *hlayoutr=new QHBoxLayout;
    hlayoutr->setAlignment(Qt::AlignRight);

    hlayout->addLayout(hlayoutl);
    hlayout->addStretch(1000);
    hlayout->addStretch(100);

    hlayout->addLayout(hlayoutr);
    QLabel *lab=new QLabel(QStringLiteral("My云盘"));
    hlayoutl->addWidget(lab);

    QPushButton *set=new QPushButton(QStringLiteral("设置"));
    QPushButton* close=new QPushButton(QStringLiteral("关闭"));

    hlayoutr->addWidget(set);
    hlayoutr->addWidget(close);
    this->setLayout(hlayout);
    connect(close,&QPushButton::clicked,this,[this]{
        emit closeWin();
    });
    connect(set,&QPushButton::clicked,this,[this]{
        emit she();
    });

}

void title::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        fu->move(event->globalPos()-pt);
    }
}

void title::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        pt=event->globalPos()-fu->geometry().topLeft();
    }
}
