#ifndef REGIST_H
#define REGIST_H
class Login;
#include"login.h"
#include <QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QMessageBox>
#include<QNetworkAccessManager>


class regist : public QWidget
{
    Q_OBJECT

public:
    explicit regist(QWidget *parent = nullptr);

signals:

public slots:
    void zhuce();

private:
    Login* fu;
    QLineEdit* name;
    QLineEdit* nc;
    QLineEdit* password;
    QLineEdit* pw2;
    QLineEdit* email;
    QLineEdit* phone;
};

#endif // REGIST_H
