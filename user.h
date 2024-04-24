#ifndef USER_H
#define USER_H

#include<QString>
class User
{
public:
    User();
    void setName(QString name);
    QString getName();
    void setToken(QString token);
    QString getToken();
    static User* getUser();
    QString getIp() const;
    void setIp(const QString &newIp);

    QString getPort() const;
    void setPort(const QString &newPort);

private:
    QString name;
    QString token;
    QString ip;
    QString port;
};

#endif // USER_H
