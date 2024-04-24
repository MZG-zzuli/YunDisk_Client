#include "mainlogin.h"
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QDebug>
#include<QJsonObject>
#include<QJsonDocument>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include"user.h"
mainLogin::mainLogin(QWidget *parent)
    : QWidget{parent}
{
    fu=(Login*)parent;
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
    });
    connect(dl,&QPushButton::clicked,[this]{
        mylogin();
    });

    dlZc->addWidget(dl);
    dlZc->addWidget(zc);
    mainLayout->addLayout(dlZc);
    mainLayout->addStretch(10);



}

void mainLogin::setNamePs(QString name, QString ps)
{
    this->name->setText(name);
    this->password->setText(ps);

}

void mainLogin::mylogin()
{
    QJsonObject jsonObj;
    jsonObj.insert("user",this->name->text());
    jsonObj.insert("pwd",this->password->text());
    QJsonDocument doc(jsonObj);
    QByteArray jsonByte=doc.toJson();
    QNetworkAccessManager *netWorkmanage=new QNetworkAccessManager(this);
    QString url=QString("http://%1:%2/login").arg(fu->sz->ip->text()).arg(fu->sz->port->text());
    QNetworkRequest req;
    req.setUrl(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    QNetworkReply* reply=netWorkmanage->post(req,jsonByte);
    connect(reply,&QNetworkReply::readyRead,[=]{
        QByteArray bytes=reply->readAll();
        QJsonDocument doc=QJsonDocument::fromJson(bytes);
        qDebug()<<doc.toJson()<<endl;
        QJsonObject obj=doc.object();
        QString code=obj.value("code").toString();
        if(code=="000")
        {
            //qDebug()<<"登录成功";
            User* user=User::getUser();
            user->setName(this->name->text());
            user->setToken(obj.value("token").toString());
            emit successLogin();
        }else
        {
            QMessageBox::information(this,"error","密码错误,登录失败");
            return;
        }

    });


}
