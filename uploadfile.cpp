#include "uploadfile.h"
UploadFile::UploadFile(QWidget *parent)
    : QWidget{parent}
{



    qDebug()<<"=====";
    QVBoxLayout* mainlayout=new QVBoxLayout;
    this->setLayout(mainlayout);
    filePath=new QLineEdit;
    selectFile=new QPushButton(QStringLiteral("选择文件"));
    QHBoxLayout* lay=new QHBoxLayout;
    lay->addWidget(filePath);
    lay->addWidget(selectFile);
    mainlayout->addLayout(lay);
    connect(selectFile,&QPushButton::clicked,this,[=]{
        filePath->setText(QFileDialog::getOpenFileName());
        qDebug()<<File::getMd5(filePath->text());
        qDebug()<<filePath->text();
        if(filePath->text()!=QString(""))uploadMd5();
    });
    message=new QTextEdit;
    mainlayout->addWidget(message);
    jindu=new QProgressBar;
    mainlayout->addWidget(jindu);
}

void UploadFile::upload()
{

    QNetworkAccessManager *networkManger=new QNetworkAccessManager(this);
    QNetworkRequest *head=new QNetworkRequest;
    QFileInfo info=QFileInfo(this->filePath->text());

    User *user=User::getUser();


    QString url = QString("http://%1:%2/upload").arg(user->getIp()).arg(user->getPort());
    head->setUrl(url);
    qDebug()<<url;
    QHttpPart *part=new QHttpPart;
    QString value=QString("form-data; user=\"%1\"; filename=\"%2\"; md5=\"%3\"; size=\"%4")
                        .arg(User::getUser()->getName()).arg(info.fileName()).arg(File::getMd5(filePath->text())).arg(info.size());
    qDebug()<<value;
    part->setHeader(QNetworkRequest::ContentDispositionHeader,value);
    part->setHeader(QNetworkRequest::ContentTypeHeader,"multipart/form-data");
    QFile *file=new QFile(this->filePath->text());
    file->open(QFile::ReadWrite);
    part->setBodyDevice(file);
    QHttpMultiPart *multiPart=new QHttpMultiPart;
    multiPart->append(*part);
    qDebug()<<"start up";
    QNetworkReply *reply=networkManger->post(*head,multiPart);
    connect(reply,&QNetworkReply::uploadProgress,this,[this](qint64 bytesSent, qint64 bytesTotal){
        qDebug()<<bytesSent<<"=="<<bytesTotal;
        if(bytesTotal!=0)this->jindu->setValue(bytesSent*100/bytesTotal);

    });
    connect(reply,&QNetworkReply::readyRead,this,[=]{
        qDebug()<<"-------";
        QByteArray re=reply->readAll();
        QJsonDocument jsonDoc=QJsonDocument::fromJson(re);
        QJsonObject obj=jsonDoc.object();
        qDebug()<<obj;
//        delete head;
//        delete part;
//        delete networkManger;
//        delete reply;
//        delete file;
    });
}

void UploadFile::uploadMd5()
{
    User* user=User::getUser();

    QJsonObject obj;
    QFile file(filePath->text());
    QFileInfo info(filePath->text());
    obj.insert("user",user->getName());
    obj.insert("token",user->getToken());
    obj.insert("md5",File::getMd5(filePath->text()));
    obj.insert("fileName",info.fileName());
    qDebug()<<obj;
    QJsonDocument doc(obj);
    QByteArray body=doc.toJson();
    QNetworkAccessManager *manger=new QNetworkAccessManager(this);
    QNetworkRequest *req=new QNetworkRequest;
    QString url=QString("http://%1:%2/md5").arg(user->getIp()).arg(user->getPort());
    req->setUrl(url);
    qDebug()<<url;
    req->setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply=manger->post(*req,body);
    qDebug()<<"---";
    connect(reply,&QNetworkReply::readyRead,this,[=]{

        QByteArray re=reply->readAll();
        QJsonDocument jsonDoc=QJsonDocument::fromJson(re);
        QJsonObject obj=jsonDoc.object();
        QString code=obj.value("code").toString();
        qDebug()<<code;
        qDebug()<<obj;
        if(code=="005")
        {
            qDebug()<<"file have5";
        }else if(code=="006")
        {
            qDebug()<<"file have6";
        }else
        {
            qDebug()<<"file error"<<code;
            upload();
        }
        this->jindu->setValue(100);
    });
}
