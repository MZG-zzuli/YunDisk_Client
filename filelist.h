#ifndef FILELIST_H
#define FILELIST_H
#include"user.h"
#include<QWidget>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QPushButton>
#include<QVBoxLayout>
#include"filewid.h"
#include"uploadfile.h"
class fileList : public QWidget
{
    Q_OBJECT
public:
    explicit fileList(int st,QWidget *parent = nullptr);
    void show1(int st);
    int getnum();
signals:
private:
    QString fileName;
    QString pathName;
    QPushButton *upbut;
    QVBoxLayout* vlay;
};

#endif // FILELIST_H
