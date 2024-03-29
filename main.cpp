#include<QApplication>

#include"login.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    Login w;
    w.show();

    return app.exec();
}
