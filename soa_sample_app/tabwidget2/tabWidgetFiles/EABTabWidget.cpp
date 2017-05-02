#include "EABTabWidget.h"

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

#include "OldCode/qsidepanelcontainertabwidget.h"
#include "Containers_Panels/bytasksidepanelcontainer.h"
#include "Containers_Panels/byrobotsidepanelcontainer.h"
#include "Containers_Panels/robotstatussidepanelcontainer.h"
#include "Containers_Panels/icifharpanel.h"
#include "Containers_Panels/bytaskpanel.h"
#include "Containers_Panels/byrobotpanel.h"
#include "Containers_Panels/robotstatuspanel.h"

EABTabWidget::EABTabWidget(QWidget * parent) : QWidget(parent){
	//ByTaskPanel * pByTaskPanel;
	//ByRobotPanel * pByRobotPanel;
	//Robot Status Panel disabled for RSGVA evaluation
	//RobotStatusPanel * pRobotStatusPanel;
	QList<QPair<QSidePanelContainer *, QString>> containers;

	m_pByTaskSidePanelContainer = new ByTaskSidePanelContainer;
	m_pByRobotSidePanelContainer = new ByRobotSidePanelContainer;
	//Robot Status Panel disabled for RSGVA evaluation
	//m_pRobotStatusSidePanelContainer = new RobotStatusSidePanelContainer;
	containers.push_back(qMakePair((QSidePanelContainer*)m_pByTaskSidePanelContainer, tr("By Task")));
	containers.push_back(qMakePair((QSidePanelContainer*)m_pByRobotSidePanelContainer, tr("By Robot")));
	//Robot Status Panel disabled for RSGVA evaluation
	//containers.push_back(qMakePair((QSidePanelContainer*)m_pRobotStatusSidePanelContainer, tr("Robot Status")));
	m_pSidePanelContainerTabWidget = new QSidePanelContainerTabWidget(containers);

	QObject::connect(m_pByTaskSidePanelContainer, SIGNAL(CenterMapRequest(void *)), this, SLOT(CenterMapOnTask(void *)));
	QObject::connect(m_pByTaskSidePanelContainer, SIGNAL(SelectionChanged(QSidePanel *)), this, SLOT(taskSelected(QSidePanel *)));
	QObject::connect(m_pByRobotSidePanelContainer, SIGNAL(CenterMapRequest(void *)), this, SLOT(CenterMapOnRobot(void *)));
	QObject::connect(m_pByRobotSidePanelContainer, SIGNAL(SelectionChanged(QSidePanel *)), this, SLOT(robotSelected(QSidePanel *)));
	//Robot Status Panel disabled for RSGVA evaluation
	//QObject::connect(m_pRobotStatusSidePanelContainer, SIGNAL(CenterMapRequest(void *)), this, SLOT(CenterMapOnRobot(void *)));

	m_pByTaskPanelContextMenu = new QMenu;
	m_pPauseTaskAction = m_pByTaskPanelContextMenu->addAction(tr("Pause"));
	m_pCancelTaskAction = m_pByTaskPanelContextMenu->addAction(tr("Cancel"));
	
	
	//Remove *** buttons disabled for RSGVA evaluation
	//CreateGeneralActions();
	//CreateGeneralToolBar();

	QVBoxLayout * pLayout = new QVBoxLayout;
	//Remove *** buttons disabled for RSGVA evaluation
	//pLayout->addWidget(m_pGeneralToolBar);
	pLayout->addWidget(m_pSidePanelContainerTabWidget);
	setLayout(pLayout);
}

EABTabWidget::~EABTabWidget() {}

void EABTabWidget::CreateGeneralActions(){

	m_pRemovePanelActionGroup = new QActionGroup(this);
	m_pRemoveByTaskPanelAction = m_pRemovePanelActionGroup->addAction(tr("Remove ByTask"));
	m_pRemoveByRobotPanelAction = m_pRemovePanelActionGroup->addAction(tr("Remove ByRobot"));
	//Robot Status Panel disabled for RSGVA evaluation
	//m_pRemoveRobotStatusPanelAction = m_pRemovePanelActionGroup->addAction(tr("Remove RobotStatus"));
	QObject::connect(m_pRemovePanelActionGroup, SIGNAL(triggered(QAction *)), this, SLOT(RemovePanel(QAction *)));
}

void EABTabWidget::CreateGeneralToolBar(){

	m_pGeneralToolBar = new QToolBar(tr("General"));
	m_pGeneralToolBar->addAction(m_pRemoveByTaskPanelAction);
	m_pGeneralToolBar->addAction(m_pRemoveByRobotPanelAction);
	//Robot Status Panel disabled for RSGVA evaluation
	//m_pGeneralToolBar->addAction(m_pRemoveRobotStatusPanelAction);
}

void EABTabWidget::RemovePanel(QAction * pAction){
	QSidePanel * pPanel;
	QSidePanelContainer * pContainer;

	if(pAction == m_pRemoveByTaskPanelAction){
		pContainer = m_pByTaskSidePanelContainer;
	}
	else if(pAction == m_pRemoveByRobotPanelAction){
		pContainer = m_pByRobotSidePanelContainer;
	}
	//Robot Status Panel disabled for RSGVA evaluation
	//else if(pAction == m_pRemoveRobotStatusPanelAction){
	//	pContainer = m_pRobotStatusSidePanelContainer;
	//}
	else{
		assert(0);
	}

	pPanel = pContainer->Selected();
	if(pPanel == NULL) return;
	pContainer->RemovePanel(pPanel);
	delete(pPanel);
}

void EABTabWidget::CenterMapOnTask(void * pId){
	int *intPtr = (int *)pId;		
	int temp = *intPtr;
	Q_EMIT centerOnTask(temp);
}

void EABTabWidget::CenterMapOnRobot(void * pId){
	int *intPtr = (int *)pId;		
	int temp = *intPtr;
	Q_EMIT centerOnRobot(temp);
}

void EABTabWidget::SidePanelContextMenuActionTriggered(QAction * pAction){

	QMessageBox::information(this, tr("Event"), tr("Context menu action triggered: %1").arg(pAction->text()));
}


void EABTabWidget::taskSelected(QSidePanel * pPanel)
{
	Q_EMIT taskActive(pPanel->m_Id);
	for (int i = 0; i < pPanel->m_RobotIds.size(); i++)
	{
		Q_EMIT robotActive(pPanel->m_RobotIds[i]);
	}
}
void EABTabWidget::robotSelected(QSidePanel * pPanel)
{
	Q_EMIT robotActive(pPanel->m_Id);
}

void EABTabWidget::taskEdit(QSidePanel * pPanel)
{
	Q_EMIT editTask(pPanel->m_Id);
}


void EABTabWidget::addTask(taskData * ttask)
{
//	addTask(ttask->tempId, ttask->name, ttask->leader, ttask->division, xxx);
	// Create a ByTask panel for the new task
	ByTaskPanel * pByTaskPanel;
	pByTaskPanel = new ByTaskPanel(ttask, this);
	pByTaskPanel->SetContextMenu(m_pByTaskPanelContextMenu);
	connect(pByTaskPanel, SIGNAL(ContextMenuActionTriggered(QAction *)), SLOT(SidePanelContextMenuActionTriggered(QAction *)));

	// Load the ByTask panel in the ByTask panel container
	m_pByTaskSidePanelContainer->AddPanel(pByTaskPanel);
}


void EABTabWidget::addRobot(robotData * tRobot)
{
	ByRobotPanel * pByRobotPanel;
	pByRobotPanel = new ByRobotPanel(tRobot, this);

	// Load the ByTask panel in the ByTask panel container
	m_pByRobotSidePanelContainer->AddPanel(pByRobotPanel);
}