#include "filelist.h"

fileList::fileList(QWidget *parent)
    : QWidget{parent}
{

}

void fileList::show()
{
    QNetworkAccessManager *manger=new QNetworkAccessManager(this);
    QString url=QString("");


}
