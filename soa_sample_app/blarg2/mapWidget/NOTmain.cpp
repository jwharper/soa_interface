#include "mapwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapWidget w("someFileName");
    w.show();

    return a.exec();
}
