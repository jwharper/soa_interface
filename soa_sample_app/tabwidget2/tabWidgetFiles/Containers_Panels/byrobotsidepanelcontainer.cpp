#include "byrobotsidepanelcontainer.h"

#include <QLabel>
#include <QString>
#include <QComboBox>
#include <assert.h>

#include "byrobotpanel.h"

ByRobotSidePanelContainer::ByRobotSidePanelContainer(QWidget * parent) : QSidePanelContainer(parent){

	m_pSortComboBox->insertItem(SortNameAscending, tr("Sort by Name (Ascending)"));	
	m_pSortComboBox->insertItem(SortNameDescending, tr("Sort by Name (Descending)"));
}

int ByRobotSidePanelContainer::MinimumWidth(){
	robotData * tRobot = new robotData;
	tRobot->div = "EMS";
	tRobot->Id = 100;
	tRobot->lat = 36.875757572;
	tRobot->lng = -87.123123123123;
	tRobot->rName = "EMS UAV 100";
	tRobot->rTask = "Available";
	tRobot->rType = "uav";
	ByRobotPanel panel (tRobot, this);
	int minimumWidth;

	panel.ChangeMode(QSidePanel::Mode1);
	minimumWidth = panel.minimumSizeHint().width();
	panel.ChangeMode(QSidePanel::Mode2);
	if(minimumWidth < panel.minimumSizeHint().width()) minimumWidth = panel.minimumSizeHint().width();

	return(minimumWidth);
}

bool ByRobotSidePanelContainer::SortNameDescendingLessThan(QSidePanel * a, QSidePanel * b){
	ByRobotPanel * pPanelA = (ByRobotPanel *)a;
	ByRobotPanel * pPanelB = (ByRobotPanel *)b;

	if(pPanelA->Name() > pPanelB->Name()) return(true);
	return(false);
}

bool ByRobotSidePanelContainer::SortNameAscendingLessThan(QSidePanel * a, QSidePanel * b){
	ByRobotPanel * pPanelA = (ByRobotPanel *)a;
	ByRobotPanel * pPanelB = (ByRobotPanel *)b;

	if(pPanelA->Name() < pPanelB->Name()) return(true);
	return(false);
}

void ByRobotSidePanelContainer::SortPanels(int method){
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
