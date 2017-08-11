// bytasksidepanelcontainer.cpp
//
// Created by EAB, HMT Lab
// Modified by Musad Haque
// 2016

#include "bytasksidepanelcontainer.h"
#include "task/TaskBuilder.h"

#include <QLabel>
#include <QString>
#include <QComboBox>
#include <assert.h>

#include "bytaskpanel.h"

ByTaskSidePanelContainer::ByTaskSidePanelContainer(QWidget * parent) : QSidePanelContainer(parent){

	m_pSortComboBox->insertItem(SortNameAscending, tr("Sort by Name (Ascending)"));	
	m_pSortComboBox->insertItem(SortNameDescending, tr("Sort by Name (Descending)"));
}

int ByTaskSidePanelContainer::MinimumWidth(){
    auto builder = soa::task::TaskType::builder_for(soa::task::TaskID(0,0), soa::task::TaskType::GOTO);
    auto taskPtr = builder->getTask();
    taskInfo *tData = new taskInfo;	tData->id = 2;
    tData->task = "Move To Location";
    tData->actor = "Heavy UAV 101";
    tData->actorId = 101;
    ByTaskPanel panel(taskPtr);
		int minimumWidth;

	panel.ChangeMode(QSidePanel::Mode1);
	minimumWidth = panel.minimumSizeHint().width();
	panel.ChangeMode(QSidePanel::Mode2);
	if(minimumWidth < panel.minimumSizeHint().width()) minimumWidth = panel.minimumSizeHint().width();

	return(minimumWidth);
}

bool ByTaskSidePanelContainer::SortNameDescendingLessThan(QSidePanel * a, QSidePanel * b){
	ByTaskPanel * pPanelA = (ByTaskPanel *)a;
	ByTaskPanel * pPanelB = (ByTaskPanel *)b;

	if(pPanelA->Name() > pPanelB->Name()) return(true);
	return(false);
}

bool ByTaskSidePanelContainer::SortNameAscendingLessThan(QSidePanel * a, QSidePanel * b){
	ByTaskPanel * pPanelA = (ByTaskPanel *)a;
	ByTaskPanel * pPanelB = (ByTaskPanel *)b;

	if(pPanelA->Name() < pPanelB->Name()) return(true);
	return(false);
}

void ByTaskSidePanelContainer::SortPanels(int method){
	int sortMethod = method;

	(void)method;

	if(method == -1){
		sortMethod = m_pSortComboBox->currentIndex();
	}

	switch(sortMethod){
		case SortNameDescending:
			qSort(m_PanelList.begin(), m_PanelList.end(), SortNameDescendingLessThan);
			RelayoutPanels();
			break;
		
		case SortNameAscending:
			qSort(m_PanelList.begin(), m_PanelList.end(), SortNameAscendingLessThan);
			RelayoutPanels();
			break;

		default:
			assert(0);
	};
}


