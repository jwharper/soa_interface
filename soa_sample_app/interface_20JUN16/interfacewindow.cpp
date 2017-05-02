// interfacewindow.cpp
//
// Created by Musad Haque
// 2016

#include "interfacewindow.h"
#include "ui_interfacewindow.h"
#include "borderlayout.h"
#include <QTabWidget>


InterfaceWindow::InterfaceWindow(QWidget * parent) :
    QWidget(parent)
{

    QString file = "../build/SampleAutonomy";

    m_pLogicWidget = new LogicWidget(this);
    m_pLogicWidget->setFileName("./Scripts/RVA_derived.htm");
    //Map area dimensions
    m_pLogicWidget->setMinimumHeight(880);
    m_pLogicWidget->setMinimumWidth(1000);
    //m_pTabPanelWidget = new TabPanelWidget(this);
    m_pTabPanel2 = new TabPanel2(this);
    m_pTabPanel2->setMinimumHeight(1000);
    m_pTaskPanelWidget = new TaskPanelWidget(this);
    //m_pTaskPanelWidget->setMinimumWidth(1000);


    //Operator interface dimensions, layout, title, and icon
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(m_pLogicWidget, BorderLayout::Center);
    //layout->addWidget(m_pTabPanelWidget, BorderLayout::East);
    layout->addWidget(m_pTabPanel2, BorderLayout::East);
    layout->addWidget(m_pTaskPanelWidget, BorderLayout::South);
    setLayout(layout);
    setMinimumHeight(1000);
    setMinimumWidth(1000);
    setWindowTitle(tr("SOA User Interface"));
    setWindowIcon(QIcon("maria2.png"));

    //Connections between the three widgets are made here.
    //

    //Connect selectTaskArea to enableTaskDraw
    connect(m_pTaskPanelWidget, SIGNAL(selectTaskArea(QString, QString)), m_pLogicWidget, SLOT(enableTaskDraw(QString, QString)));

    //Connect coordinates recvd from JS to taskPanelWidget for processing
    connect(m_pLogicWidget, SIGNAL(actuallySendCoord(QString)), m_pTaskPanelWidget, SLOT(mapCoordFromJS(QString)));

    //!!!!!!!!!!!!NEXT FOUR LINES DISABLED FOR VIDEO. PUT THEM BACK!!!!!!!!!!!!!!!!!!
    //connect(m_pTaskPanelWidget, SIGNAL(sendTask(taskInfo*)), m_pLogicWidget, SIGNAL(commitTask(taskInfo*)));
    ////Task the API
    //connect(m_pTaskPanelWidget, SIGNAL(sendTask(taskInfo*)), m_pLogicWidget, SLOT(taskSOA(taskInfo*)));
    //connect(m_pTaskPanelWidget, SIGNAL(sendTask(taskInfo*)), m_pTabPanel2, SLOT(addTask(taskInfo*)));

    //!!!!!!!!!!!FOR THE VIDEO. MAKE IT GO AWAY!!!!!!!!!!!!!!!!!!
    connect(m_pTaskPanelWidget, SIGNAL(sendTask(taskInfo*)), m_pLogicWidget, SLOT(tasksForVideo(taskInfo*)));
    connect(m_pLogicWidget, SIGNAL(commitTask(taskInfo*)), m_pTabPanel2, SLOT(addTask(taskInfo*)));

    connect(m_pLogicWidget, SIGNAL(endTask(int)), m_pTabPanel2, SLOT(endTask(int)));

}

void InterfaceWindow::debug(QString msg){
    qDebug()<<msg;
}


