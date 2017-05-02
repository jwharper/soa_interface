#include "tabpanelwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabPanelWidget w;
    w.show();

    return a.exec();
}
