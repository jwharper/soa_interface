#include <QApplication>
#include "blarg2window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Blarg2Window w; //MARK: CHANGE TO boring.html
    //w.setFixedSize(800,800);
    //w.show();
    w.setFixedSize(800, 800);
    w.show();

    return a.exec();
}
