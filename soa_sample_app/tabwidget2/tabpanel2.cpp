//
// tabpanel2.cpp
//
// Created by EAB, HMT lab
// Tweaked by Musad Haque
//

#include "tabpanel2.h"

#include <QSpinBox>
#include <QComboBox>
#include <QAction>
#include <QActionGroup>
#include <QInputDialog>
#include <QToolBar>
#include <QHBoxLayout>
#include <QMenu>
#include <QStringList>
#include <QMessageBox>
#include <assert.h>
#include <stdlib.h>
#include <QDebug>

#include "../tabwidget2/tabWidgetFiles/OldCode/qsidepanelcontainertabwidget.h"
#include "../tabwidget2/tabWidgetFiles/Containers_Panels/bytasksidepanelcontainer.h"
#include "../tabwidget2/tabWidgetFiles/Containers_Panels/bytaskpanel.h"


TabPanel2::TabPanel2(QWidget * parent, soa::WorldDataManager* wdm) : QWidget(parent), wdm(wdm){
    QList<QPair<QSidePanelContainer *, QString> > containers;

    m_pByTaskSidePanelContainer = new ByTaskSidePanelContainer;
    containers.push_back(qMakePair((QSidePanelContainer*)m_pByTaskSidePanelContainer, tr("By Task")));
    m_pSidePanelContainerTabWidget = new QSidePanelContainerTabWidget(containers);

    //connect(m_pByTaskSidePanelContainer, SIGNAL(CenterMapRequest(void *)), this, SLOT(CenterMapOnTask(void *)));
    connect(m_pByTaskSidePanelContainer, SIGNAL(SelectionChanged(QSidePanel *)), this, SLOT(taskSelected(QSidePanel *)));

    m_pByTaskPanelContextMenu = new QMenu;
    m_pPauseTaskAction = m_pByTaskPanelContextMenu->addAction(tr("Pause"));
    m_pCancelTaskAction = m_pByTaskPanelContextMenu->addAction(tr("Cancel"));

    QVBoxLayout * pLayout = new QVBoxLayout;
    //Remove *** buttons disabled for RSGVA evaluation
    //pLayout->addWidget(m_pGeneralToolBar);
    pLayout->addWidget(m_pSidePanelContainerTabWidget);
    setLayout(pLayout);
}

TabPanel2::~TabPanel2() {}

void TabPanel2::CreateGeneralActions(){

    m_pRemovePanelActionGroup = new QActionGroup(this);
    m_pRemoveByTaskPanelAction = m_pRemovePanelActionGroup->addAction(tr("Remove ByTask"));
    QObject::connect(m_pRemovePanelActionGroup, SIGNAL(triggered(QAction *)), this, SLOT(RemovePanel(QAction *)));
}

void TabPanel2::CreateGeneralToolBar(){

    m_pGeneralToolBar = new QToolBar(tr("General"));
    m_pGeneralToolBar->addAction(m_pRemoveByTaskPanelAction);
}

void TabPanel2::RemovePanel(QAction * pAction){
    QSidePanel * pPanel;
    QSidePanelContainer * pContainer;

    if(pAction == m_pRemoveByTaskPanelAction){
        pContainer = m_pByTaskSidePanelContainer;
    }
    else{
        assert(0);
    }

    pPanel = pContainer->Selected();
    if(pPanel == NULL) return;
    pContainer->RemovePanel(pPanel);
    delete(pPanel);
}

void TabPanel2::CenterMapOnTask(void * pId){
    int *intPtr = (int *)pId;
    int temp = *intPtr;
    Q_EMIT centerOnTask(temp);
}

void TabPanel2::SidePanelContextMenuActionTriggered(QAction * pAction){

    QMessageBox::information(this, tr("Event"), tr("Context menu action triggered: %1").arg(pAction->text()));
}


void TabPanel2::taskSelected(QSidePanel * pPanel)
{
    Q_EMIT taskActive(pPanel->m_Id);

}

void TabPanel2::taskEdit(QSidePanel * pPanel)
{
    Q_EMIT editTask(pPanel->m_Id);
}


void TabPanel2::addTask(taskInfo * ttask)
{/*
    // Create a ByTask panel for the new task
    ByTaskPanel * pByTaskPanel;
    pByTaskPanel = new ByTaskPanel(ttask, this);
    pByTaskPanel->SetContextMenu(m_pByTaskPanelContextMenu);
    connect(pByTaskPanel, SIGNAL(ContextMenuActionTriggered(QAction *)), SLOT(SidePanelContextMenuActionTriggered(QAction *)));

    // Load the ByTask panel in the ByTask panel container
    m_pByTaskSidePanelContainer->AddPanel(pByTaskPanel);

    // Task ID used here
    m_pByTaskSidePanelContainer->m_ByTaskPanelHash.insert(ttask->id, pByTaskPanel);*/
}

void TabPanel2::handleTaskUpdate(int taskID)
{
   soa_shared_ptr<soa::Belief_Task> taskBelief = wdm->getTypedBelief<soa::Belief_Task>(soa::Belief::Key(soa::Belief_Task::Type), taskID);
   if (taskBelief.get() == NULL) {
       std::cerr << "Expected to find a task with ID: " << taskID << " but none was found." << std::endl;
       return;
   }
   std::cout << "Handling task update" << std::endl;
   auto key = taskBelief->getBeliefKey();
   auto pairIt = taskPanelMap.find(key);

   if (pairIt != taskPanelMap.end())
   {
        std::cout << "Updating old task panel" << std::endl;
        if (taskBelief->getTask()->isFinished()) {
            auto panel = pairIt->second;
            taskPanelMap.erase(key);
            m_pByTaskSidePanelContainer->RemovePanel(panel);
            delete panel;
        } else {
            pairIt->second->update(taskBelief->getTask());
        }
   }
   else
   {
        std::cout << "Creating new panel" << std::endl;
        ByTaskPanel* taskPanel = new ByTaskPanel(wdm, taskBelief->getTask(), this);
        taskPanel->SetContextMenu(m_pByTaskPanelContextMenu);
        connect(taskPanel, SIGNAL(ContextMenuActionTriggered(QAction *)), SLOT(SidePanelContextMenuActionTriggered(QAction *)));
        taskPanelMap[key] = taskPanel;
        m_pByTaskSidePanelContainer->AddPanel(taskPanel);
   }

}

void TabPanel2::endTask(int id)
{
//    if (!m_pByTaskSidePanelContainer->m_ByTaskPanelHash.contains(id))
//        return;
//    ByTaskPanel * pByTaskPanel = m_pByTaskSidePanelContainer->m_ByTaskPanelHash.value(id);
//    m_pByTaskSidePanelContainer->m_ByTaskPanelHash.remove(id);
//    m_pByTaskSidePanelContainer->RemovePanel(pByTaskPanel);
}


