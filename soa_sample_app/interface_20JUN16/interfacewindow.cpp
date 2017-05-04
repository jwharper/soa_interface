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

    /*
     * The JS scripts to place icons through the
     * Google Maps API lives in
     * ~/Downloads/soa_sample_app/blarg2/mapWidget/Scripts/RVA_derived.htm
    */
    m_pLogicWidget = new LogicWidget(this);
    m_pLogicWidget->setFileName("./Scripts/RVA_derived.htm");
    //Map area dimensions
    m_pLogicWidget->setMinimumHeight(800);
    m_pLogicWidget->setMinimumWidth(1000);
    //m_pTabPanelWidget = new TabPanelWidget(this);
    m_pTabPanel2 = new TabPanel2(this);
    m_pTabPanel2->setMinimumHeight(800);
    m_pTaskPanelWidget = new TaskPanelWidget(this);
    //m_pTaskPanelWidget->setMaximumHeight(300);


    //Operator interface dimensions, layout, title, and icon
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(m_pLogicWidget, BorderLayout::Center);
    //layout->addWidget(m_pTabPanelWidget, BorderLayout::East);
    layout->addWidget(m_pTabPanel2, BorderLayout::East);
    layout->addWidget(m_pTaskPanelWidget, BorderLayout::South);
    setLayout(layout);
    //setMinimumHeight(1200);
    //setMinimumWidth(1200);
    setWindowTitle(tr("SOA Operator Interface"));
    setWindowIcon(QIcon("maria2.png"));

    //Connections between the three widgets are made here.

    //Connect TaskPanelWidget's taskShapeAndColor to LogicWidget's enableTaskDraw informing about color and shape for task
    connect(m_pTaskPanelWidget, SIGNAL(taskShapeAndColor(QString, QString)), m_pLogicWidget, SLOT(enableTaskDraw(QString, QString)));

    //Connect LogicWidget's coordinates recvd from JS to taskPanelWidget's mapCoordFromJS
    connect(m_pLogicWidget, SIGNAL(actuallySendCoord(QString)), m_pTaskPanelWidget, SLOT(mapCoordFromJS(QString)));


    //regionTasking *** *** ***
    /*
     * *************
     *
     * If scripting for video use two connects:
     * v1 and v2
     * comment out nv1, nv2, nv3
     *
     * If not scripting use three connects:
     * nv1, nv2, and nv3
     * comment out v1, v2
     *
     * Not elegant on purpose.
     *
     * *************
    */
    //nv1, nv2, nv3:
    //connect(m_pTaskPanelWidget, SIGNAL(sendTaskInfo(taskInfo*)), m_pLogicWidget, SIGNAL(commitTask(taskInfo*))); //nv1
    //connect(m_pTaskPanelWidget, SIGNAL(sendTaskInfo(taskInfo*)), m_pLogicWidget, SLOT(taskSOA(taskInfo*))); //nv2
    //connect(m_pTaskPanelWidget, SIGNAL(sendTaskInfo(taskInfo*)), m_pTabPanel2, SLOT(addTask(taskInfo*))); //nv3
    //v1, v2:
    connect(m_pTaskPanelWidget, SIGNAL(sendTaskInfo(taskInfo*)), m_pLogicWidget, SLOT(tasksForVideo(taskInfo*))); //v1
    connect(m_pLogicWidget, SIGNAL(commitTask(taskInfo*)), m_pTabPanel2, SLOT(addTask(taskInfo*))); //v2
    //endRegionTasking *** *** ***


    //logicWindow's endTask informs tabPanel2 that task has ended
    connect(m_pLogicWidget, SIGNAL(endTask(int)), m_pTabPanel2, SLOT(endTask(int)));

}

void InterfaceWindow::debug(QString msg){
    qDebug()<<msg;
}


