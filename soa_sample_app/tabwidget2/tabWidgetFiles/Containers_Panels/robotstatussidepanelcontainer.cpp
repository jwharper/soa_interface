#include "robotstatussidepanelcontainer.h"

#include <QLabel>
#include <QString>
#include <QComboBox>
#include <assert.h>

#include "robotstatuspanel.h"

RobotStatusSidePanelContainer::RobotStatusSidePanelContainer(QWidget * parent) : QSidePanelContainer(parent){

	m_pSortComboBox->insertItem(SortNameAscending, tr("Sort by Name (Ascending)"));	
	m_pSortComboBox->insertItem(SortNameDescending, tr("Sort by Name (Descending)"));
}

int RobotStatusSidePanelContainer::MinimumWidth(){
	RobotStatusPanel panel;
	int minimumWidth;

	panel.ChangeMode(QSidePanel::Mode1);
	minimumWidth = panel.minimumSizeHint().width();

	return(minimumWidth);
}

bool RobotStatusSidePanelContainer::SortNameDescendingLessThan(QSidePanel * a, QSidePanel * b){
	RobotStatusPanel * pPanelA = (RobotStatusPanel *)a;
	RobotStatusPanel * pPanelB = (RobotStatusPanel *)b;

	if(pPanelA->Name() > pPanelB->Name()) return(true);
	return(false);
}

bool RobotStatusSidePanelContainer::SortNameAscendingLessThan(QSidePanel * a, QSidePanel * b){
	RobotStatusPanel * pPanelA = (RobotStatusPanel *)a;
	RobotStatusPanel * pPanelB = (RobotStatusPanel *)b;

	if(pPanelA->Name() < pPanelB->Name()) return(true);
	return(false);
}

void RobotStatusSidePanelContainer::SortPanels(int method){
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
