#include "icifharsidepanelcontainer.h"

#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QComboBox>
#include <QDebug>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <assert.h>

#include "icifharpanel.h"

iCiFHaRSidePanelContainer::iCiFHaRSidePanelContainer(QWidget * parent) : QSidePanelContainer(parent){
	qDebug()<<"huh?";
	//m_pSelectButton = new QPushButton("Select", this);
	
	m_pCenterMapButton->hide();
	m_pCounts->hide();
	m_pSortLabel->hide();
	m_pSortComboBox->hide();
	m_pResetButton->show();
	m_pSelectButton->show();
	m_pAlgName->show();
	m_pAlgUtility->show();
}

int iCiFHaRSidePanelContainer::MinimumWidth(){
	iCiFHaRPanel panel;
	int minimumWidth;

	panel.ChangeMode(QSidePanel::Mode1);
	minimumWidth = panel.minimumSizeHint().width();
	panel.ChangeMode(QSidePanel::Mode2);
	if(minimumWidth < panel.minimumSizeHint().width()) minimumWidth = panel.minimumSizeHint().width();

	return(minimumWidth);
}

void iCiFHaRSidePanelContainer::SortPanels(int method){
	qDebug()<<method;
}