#ifndef BLARG2WINDOW_H
#define BLARG2WINDOW_H

#include <QMainWindow>
#include "logicwidget.h"

namespace Ui {
class Blarg2Window;
}

class Blarg2Window : public QMainWindow
{
    Q_OBJECT

public:
    Blarg2Window(QWidget *parent = 0);
    ~Blarg2Window();

private:
    Ui::Blarg2Window *ui;
    LogicWidget * m_pLogicWidget;

};

#endif // BLARG2WINDOW_H
