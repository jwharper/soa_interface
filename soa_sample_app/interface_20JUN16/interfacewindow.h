// interfacewindow.h
//
// Created by Musad Haque
// 2016


#ifndef INTERFACEWINDOW_H
#define INTERFACEWINDOW_H


#include <QWidget>
#include <../blarg2/logicwidget.h>
#include <../taskpanelwidget/taskpanelwidget.h>
#include <../tabpanelwidget/tabpanelwidget.h>
#include <../tabwidget2/tabpanel2.h>


class InterfaceWindow : public QWidget
{
    Q_OBJECT

public:
    InterfaceWindow(QWidget * parent = 0);

    // InterfaceWindow holds three widgets
    // 1 A map area (LogicWidget)
    // 2 A tasking panel below the map (TaskPanelWidget)
    // 3 A tab panel to display info to the map's right (TabPanel2)
private:
    TabPanel2 * m_pTabPanel2; //OR: TabPanelWidget * m_pTabPanelWidget;
    TaskPanelWidget * m_pTaskPanelWidget;
    LogicWidget * m_pLogicWidget;

    //A logger-type method
    Q_SLOT void debug(QString msg);
};


#endif // INTERFACEWINDOW_H


