#include "user.h"

User::User()
{


}

void User::setName(QString name)
{
    this->name=name;
}

QString User::getName()
{
    return name;
}

void User::setToken(QString token)
{
    this->token=token;
}

QString User::getToken()
{
    return token;
}

User *User::getUser()
{
    static User* user=new User();
    return user;
}

QString User::getIp() const
{
    return ip;
}

void User::setIp(const QString &newIp)
{
    ip = newIp;
}

QString User::getPort() const
{
    return port;
}

void User::setPort(const QString &newPort)
{
    port = newPort;
}
