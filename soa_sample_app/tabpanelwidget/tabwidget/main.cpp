#include "bytaskpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ByTaskPanel w;
    w.show();

    return a.exec();
}
