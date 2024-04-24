#include "mainwidget.h"
#include<QVBoxLayout>
#include<QLabel>
mainWidget::mainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* layout=new QVBoxLayout;
    this->setLayout(layout);
    layout->addWidget(new QLabel("hello!"));
}
