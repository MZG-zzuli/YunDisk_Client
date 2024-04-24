#include<QApplication>

#include"login.h"
#include"uploadfile.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    Login w;
    //UploadFile w;
    w.show();

    return app.exec();
}
