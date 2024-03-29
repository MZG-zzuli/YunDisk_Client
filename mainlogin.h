#ifndef MAINLOGIN_H
#define MAINLOGIN_H

#include <QWidget>
#include<QLineEdit>
class mainLogin : public QWidget
{
    Q_OBJECT
public:
    explicit mainLogin(QWidget *parent = nullptr);
    void setNamePs(QString name,QString ps);
signals:
    void regWid();

private:
    QLineEdit* name;
    QLineEdit* password;
};

#endif // MAINLOGIN_H
