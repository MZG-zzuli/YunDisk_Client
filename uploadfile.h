#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QWidget>
#include<QTextLine>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFileDialog>
#include<QLineEdit>
#include<QTextEdit>
#include<QProgressBar>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QDebug>
#include<QFileInfo>
#include<QHttpPart>
#include<QJsonDocument>
#include<QJsonObject>
#include"file.h"
#include"user.h"
class UploadFile : public QWidget
{
    Q_OBJECT
public:
    explicit UploadFile(QWidget *parent = nullptr);

signals:
private:
    QLineEdit *filePath;
    QPushButton *selectFile;
    QTextEdit *message;
    QProgressBar* jindu;
    void upload();
    void uploadMd5();
};

#endif // UPLOADFILE_H
