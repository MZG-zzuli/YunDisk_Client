#ifndef FILEWID_H
#define FILEWID_H

#include<QPushButton>
#include<QWidget>
#include<QJsonObject>
#include<QJsonDocument>
#include<QFile>
#include<QFileDialog>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include"user.h"
class FileWid : public QWidget
{
    Q_OBJECT
public:
    explicit FileWid(QJsonObject obj,QWidget *parent = nullptr);

public slots:
    void down();
signals:
private:
    QPushButton *but;
    int size;
    QString url;
    QString filename;
    QString md5;
};

#endif // FILEWID_H
