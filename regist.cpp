#include "regist.h"
#include<QJsonObject>
#include<QJsonDocument>
#include<QNetWorkReply>
regist::regist(QWidget *parent)
    : QWidget{parent}
{
    fu=(Login*)parent;
    QVBoxLayout* mainLayout=new QVBoxLayout;
    this->setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignVCenter);

    QLabel* tit=new QLabel(QStringLiteral("用户注册"));
    QHBoxLayout* titlay=new  QHBoxLayout;
    titlay->addStretch(1);
    titlay->addWidget(tit);
    titlay->addStretch(1);

    mainLayout->addStretch(0);

    mainLayout->addLayout(titlay);

    mainLayout->addStretch(1);
    name=new QLineEdit;
    nc=new QLineEdit;
    password=new QLineEdit;
    pw2=new QLineEdit;
    email=new QLineEdit;
    phone=new QLineEdit;

    QHBoxLayout* nmlay=new QHBoxLayout;
    nmlay->addWidget(new QLabel(QStringLiteral("用 户 名")));
    nmlay->addWidget(name);
    mainLayout->addLayout(nmlay);
    mainLayout->addStretch(0);

    QHBoxLayout* nclay=new QHBoxLayout;
    nclay->addWidget(new QLabel(QStringLiteral(" 昵  称 ")));
    nclay->addWidget(nc);
    mainLayout->addLayout(nclay);
    mainLayout->addStretch(0);

    QHBoxLayout* pwlay1=new QHBoxLayout;
    pwlay1->addWidget(new QLabel(QStringLiteral(" 密  码 ")));
    pwlay1->addWidget(password);
    mainLayout->addLayout(pwlay1);
    mainLayout->addStretch(0);


    QHBoxLayout* pwlay2=new QHBoxLayout;
    pwlay2->addWidget(new QLabel(QStringLiteral("确认密码")));
    pwlay2->addWidget(pw2);
    mainLayout->addLayout(pwlay2);
    mainLayout->addStretch(0);

    QHBoxLayout* emlay=new QHBoxLayout;
    emlay->addWidget(new QLabel(QStringLiteral(" 邮  箱 ")));
    emlay->addWidget(email);
    mainLayout->addLayout(emlay);
    mainLayout->addStretch(0);

    QHBoxLayout* phlay=new QHBoxLayout;
    phlay->addWidget(new QLabel(QStringLiteral(" 电  话 ")));
    phlay->addWidget(phone);
    mainLayout->addLayout(phlay);
    mainLayout->addStretch(1);

    QPushButton* regbut=new QPushButton(QStringLiteral("注册"));
    mainLayout->addWidget(regbut);
    mainLayout->addStretch(1);
    connect(regbut,&QPushButton::clicked,this,[this]{
        emit zhuce();
    });


}
void regist::zhuce()
{
    QString userName = name->text();
    QString nickName = nc->text();
    QString passwd = password->text();
    QString confirmPwd = pw2->text();
    QString emailstr = email->text();
    QString phonestr = phone->text();
    QRegExp regexp;
    // 校验用户名,密码
    QString USER_REG   = "^[a-zA-Z0-9_@#-\\*]\\{3,16\\}$";
    regexp.setPattern(USER_REG);
    bool bl = regexp.exactMatch(userName);

    if(passwd!=confirmPwd)
    {
        QMessageBox::information(this,"ERROR",QStringLiteral("两次输入密码不一致!"));
        return;
    }
    QNetworkAccessManager* pManager = new QNetworkAccessManager(this);
    QNetworkRequest request;

    QString url = QString("http://%1:%2/reg").arg(fu->sz->ip->text()).arg(fu->sz->port->text());
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");    // 描述post数据的格式
    /*
        {
            userName:xxxx,
            nickName:xxx,
            firstPwd:xxx,
            phone:xxx,
            email:xxx
        }
    */
    QJsonObject obj;
    obj.insert("username",userName);
    obj.insert("nickName",nickName);
    obj.insert("firstPwd",passwd);
    obj.insert("phone",phonestr);
    obj.insert("email",emailstr);

    QJsonDocument doc(obj);
    QByteArray json=doc.toJson();
    QNetworkReply* reply=pManager->post(request,json);
    connect(reply,&QNetworkReply::readyRead,this,[=]{
        QByteArray all=reply->readAll();
        QJsonDocument doc=QJsonDocument::fromJson(all);
        QJsonObject reObj=doc.object();
        QString status=reObj.value("code").toString();
        qDebug()<<status;
        /*
         * 002      成功
         * 003      用户已存在
         * 其他004   失败
         */
        if(status=="002")
        {
            QMessageBox::information(this, "注册成功", "注册成功，请登录");
            fu->dl->setNamePs(userName,passwd);
            emit success();
        }else if(status=="003")
        {
            QMessageBox::information(this,"ERROR","用户已存在");
        }else
        {
            QMessageBox::information(this,"ERROR","注册失败");
        }

    });


}
