
#include "login.h"

Login::Login(QWidget *parent)
    : QWidget{parent}
{
    //this->setWindowState(Qt::WindowFullScreen);
    topTitle=new  title(this);
    stackWid=new QStackedWidget;
    dl=new mainLogin(this);
    dlid=stackWid->addWidget(dl);

    sz=new Shezhi(this);
    szid=stackWid->addWidget(sz);
    reg=new regist(this);
    regid=stackWid->addWidget(reg);
    QVBoxLayout* vlayout=new QVBoxLayout;
    vlayout->addWidget(topTitle);
    vlayout->addWidget(stackWid);

    this->setLayout(vlayout);
    connect(topTitle,&title::closeWin,[&]{
        if(stackWid->currentIndex()==dlid)
        {
            this->close();
        }
        stackWid->setCurrentIndex(dlid);

    });
    connect(topTitle,&title::she,[&]{
        stackWid->setCurrentIndex(szid);
    });
    connect(dl,&mainLogin::regWid,[&]{
        stackWid->setCurrentIndex(regid);
    });

}
