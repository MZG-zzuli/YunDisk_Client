
#include "login.h"
#include"mainwidget.h"
#include"uploadfile.h"
#include<QApplication>
#define TEST
Login::Login(QWidget *parent)
    : QWidget{parent}
{
    QString qss="QPushButton {"
                  "background-color: rgb(35,35,35);"
                  "border:2px solid rgb(35,35,35);"
                  "font: 87 12pt \"Arial Black\";"
                  "color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                  "stop:0 rgba(255, 0, 0, 255),"
                  "stop:0.166 rgba(255, 255, 0, 255),"
                  "stop:0.333 rgba(0, 255, 0, 255),"
                  "stop:0.5 rgba(0, 255, 255, 255),"
                  "stop:0.666 rgba(0, 0, 255, 255),"
                  "stop:0.833 rgba(255, 0, 255, 255),"
                  "stop:1 rgba(255, 0, 0, 255));"
                  "}";
    //this->setStyleSheet(qss);
    qApp->setStyleSheet(qss);
    //this->setWindowState(Qt::WindowFullScreen);
    topTitle=new  title(this);
    stackWid=new QStackedWidget;
    dl=new mainLogin(this);
    dlid=stackWid->addWidget(dl);

    sz=new Shezhi(this);
    szid=stackWid->addWidget(sz);
#ifdef TEST
    sz->ip->setText("192.168.10.129");
    sz->port->setText("80");
#endif


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
    connect(reg,&regist::success,[&]{
        stackWid->setCurrentIndex(dlid);
    });
    connect(dl,&mainLogin::successLogin,[this]{
        qDebug()<<"success login!";//跳转到新窗口，当前窗口关闭
        UploadFile *upload=new UploadFile();
        upload->show();
        this->hide();
    });

}
