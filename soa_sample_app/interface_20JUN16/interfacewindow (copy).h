#ifndef INTERFACEWINDOW_H
#define INTERFACEWINDOW_H

#include <QMainWindow>
#include <../blarg2/logicwidget.h>
#include <../blarg2/console.h>
#include <../taskpanelwidget/taskpanelwidget.h>
#include <../tabpanelwidget/tabpanelwidget.h>

namespace Ui {
class InterfaceWindow;
}

class InterfaceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterfaceWindow(QWidget *parent = 0);
    ~InterfaceWindow();

private:
    Ui::InterfaceWindow *ui;
    LogicWidget * m_pLogicWidget;
    TaskPanelWidget * m_pTaskPanelWidget;
    Console * m_pConsole;
    TabPanelWidget * m_pTabPanelWidget;
    Q_SLOT void debug(QString msg);
};

#endif // INTERFACEWINDOW_H
