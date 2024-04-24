#ifndef FILE_H
#define FILE_H

#include<QString>
#include<QFile>
#include<QCryptographicHash>
class File
{
public:
    File();
    static QString getMd5(QString filePath);
};

#endif // FILE_H
