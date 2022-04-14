#include <iostream>
#include"./inc/Mainwindow.h"
#include"./inc/Server.h"
#include"./inc/Stru.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();

    return a.exec();
}

