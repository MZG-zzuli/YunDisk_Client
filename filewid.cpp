#include "filewid.h"

FileWid::FileWid(QJsonObject obj,QWidget *parent)
    : QWidget{parent}
{
    filename=obj.value("filename").toString();
    url=obj.value("url").toString();
    md5=obj.value("md5").toString();
    size=obj.value("size").toInt();
    but=new QPushButton(filename,this);
    connect(but,SIGNAL(clicked()),this,SLOT(down()));
    qDebug()<<"11";
}

void FileWid::down()
{
    qDebug()<<"2222";
    QString filePath=QFileDialog::getSaveFileName(this,"save file","/"+filename,"");
    if(filePath=="")return;

    qDebug()<<filePath;
    QFile *file=new QFile(filePath);
    file->open(QFile::NewOnly|QFile::WriteOnly);
    QString URL=url;//.append("?cmd=1");

    //QString URL="http://192.168.10.129:13455/group1/M00/00/00/wKgKgWX6r6SAI2hYADcAPnvb_ro315.jpg";
    QNetworkAccessManager *manger=new QNetworkAccessManager;
    QNetworkRequest req;
    req.setUrl(URL);
    qDebug()<<URL;
    QJsonObject obj;
    obj.insert("user",User::getUser()->getName());
    obj.insert("token",User::getUser()->getToken());
    obj.insert("md5",md5);
    obj.insert("filename",filename);
    QJsonDocument doc=QJsonDocument(obj);
    QByteArray body=doc.toJson();
    QNetworkReply *reply=manger->get(req);
    connect(reply,&QNetworkReply::readyRead,this,[=]{
        QByteArray byte=reply->readAll();
        file->write(byte);
        qDebug()<<"----";//<<byte;
        file->flush();
        //file->close();
    });
    connect(reply,&QNetworkReply::finished,this,[=]{
        for(int i=0;i<100000000;i++);
        file->flush();
        file->close();
        qDebug()<<"wancheng";
    });


}
