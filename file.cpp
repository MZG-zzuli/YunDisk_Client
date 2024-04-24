#include "file.h"

File::File()
{

}

QString File::getMd5(QString filePath)
{
    QFile file(filePath);
    file.open(QFile::ReadWrite);
    QCryptographicHash cry(QCryptographicHash::Md5);
    cry.addData(&file);
    return cry.result().toHex();
}
