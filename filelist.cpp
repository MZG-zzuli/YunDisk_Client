#include "filelist.h"

fileList::fileList(int st,QWidget *parent)
    : QWidget{parent}
{

    vlay=new QVBoxLayout;
    setLayout(vlay);
    upbut=new QPushButton(QStringLiteral("上传文件"));
    vlay->addWidget(upbut);
    connect(upbut,&QPushButton::clicked,this,[=]{
            UploadFile *upload=new UploadFile();
            upload->show();

    });
    //hlay->addWidget(but);
    getnum();
}

void fileList::show1(int st)
{
    qDebug()<<"--------------\n";
    User *user=User::getUser();

    QNetworkAccessManager *manger=new QNetworkAccessManager;
    QString url=QString("http://%1:%2/myfiles?cmd=normal").arg(user->getIp()).arg(user->getPort());
    QNetworkRequest req;//=new QNetworkRequest;
    req.setUrl(url);
    qDebug()<<url;
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QJsonObject obj;
    obj.insert("user",user->getName());
    obj.insert("token",user->getToken());
    obj.insert("start",st+3);
    obj.insert("count",1);
    QJsonDocument doc(obj);
    QByteArray body=doc.toJson();
    QNetworkReply *reply=manger->post(req,body);
    qDebug()<<"---------==-----\n";
    connect(reply,&QNetworkReply::finished,[=]{
        if (reply->error() != QNetworkReply::NoError) //有错误
        {
            qDebug() << reply->errorString();
            reply->deleteLater(); //释放资源
            return;
        }
        qDebug()<<"========";
        QByteArray re=reply->readAll();
        qDebug()<<"-0----";
        QJsonDocument doc1=QJsonDocument::fromJson(re);
        QJsonObject obj=doc1.object();
        qDebug()<<obj;
        QJsonArray arr=obj.value("files").toArray();
        QJsonObject obj1=arr.at(0).toObject();
        qDebug()<<obj1;
//        fileName=obj1.value("filename").toString();
//        pathName=obj1.value("url").toString();
//        but->setText(fileName);
        vlay->addWidget(new FileWid(obj1));
    });


}

int fileList::getnum()
{
    User *user=User::getUser();

    QNetworkAccessManager *manger=new QNetworkAccessManager;
    QString url=QString("http://%1:%2/myfiles?cmd=count").arg(user->getIp()).arg(user->getPort());
    QNetworkRequest req;//=new QNetworkRequest;
    req.setUrl(url);
    qDebug()<<url;
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QJsonObject obj;
    obj.insert("user",user->getName());
    obj.insert("token",user->getToken());
    QJsonDocument doc(obj);
    QByteArray body=doc.toJson();
    QNetworkReply *reply=manger->post(req,body);
    connect(reply,&QNetworkReply::readyRead,this,[=]{

        QByteArray re=reply->readAll();
        qDebug()<<"-0----";
        QJsonDocument doc1=QJsonDocument::fromJson(re);
        QJsonObject obj1=doc1.object();
        qDebug()<<obj1;
        int num=obj1.value("num").toString().toInt();
        for(int i=0;i<num;i++)
        {
            show1(i);
        }
    });
}
