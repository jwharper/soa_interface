//
// main.cpp
//
// Created by Musad Haque, 2015
//


#include "interfacewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    InterfaceWindow w;
    w.show();

    return app.exec();
}
