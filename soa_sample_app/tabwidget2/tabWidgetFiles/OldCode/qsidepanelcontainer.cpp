#include "qsidepanelcontainer.h"

#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <assert.h>

#include "qsidepanel.h"

QSidePanelContainer::QSidePanelContainer(QWidget *parent) : QWidget(parent){

	m_pSelected = NULL;
    //m_pCounts = new QLabel("Update Counts was not called");
	m_pSortLabel = new QLabel(tr("Sort:"));
	m_pAlgName = new QLabel(tr("Algorithm"));
	m_pAlgUtility = new QLabel(tr("Utility"));
	m_pSortComboBox = new QComboBox;
    //m_pCenterMapButton = new QPushButton(QIcon("qsp-centermap.png"), "");
	m_pSelectButton = new QPushButton("Select");
	m_pResetButton = new QPushButton("Reset");

    //connect(m_pCenterMapButton, SIGNAL(clicked()), this, SLOT(MapButtonClicked()));

	m_pScrollArea = new QScrollArea;
	m_pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	QWidget * pScrollWidget = new QWidget;

	QVBoxLayout * pScrollLayout = new QVBoxLayout(pScrollWidget);
	pScrollLayout->setSpacing(0);
	pScrollLayout->setContentsMargins(0, 0, 0, 0);
	pScrollLayout->addStretch();
	pScrollWidget->setLayout(pScrollLayout);
	m_pScrollArea->setWidget(pScrollWidget);
	m_pScrollArea->setWidgetResizable(true);
	m_pScrollArea->show();

	QGridLayout * pGridLayout = new QGridLayout;
    //pGridLayout->addWidget(m_pCounts, 0, 0, 1, 3, Qt::AlignCenter);
	pGridLayout->addWidget(m_pResetButton, 0, 0, 2, 1, Qt::AlignLeft);
	pGridLayout->addWidget(m_pSelectButton, 0, 1, 2, 1, Qt::AlignRight);
	pGridLayout->addWidget(m_pAlgName, 2, 0, 1, 1, Qt::AlignLeft);
	pGridLayout->addWidget(m_pAlgUtility, 2, 1, 1, 1, Qt::AlignRight);
	pGridLayout->addWidget(m_pSortLabel, 1, 0, 1, 1, Qt::AlignRight);
	pGridLayout->addWidget(m_pSortComboBox, 1, 1, 1, 1);
    //pGridLayout->addWidget(m_pCenterMapButton, 1, 2, 2, 1, Qt::AlignCenter);
	pGridLayout->setColumnStretch(1, 100);
	//pGridLayout->setColumnMinimumWidth(0, 40);
	//pGridLayout->setColumnMinimumWidth(1, 40);
	QWidget * pMenuBarWidget = new QWidget;
	pMenuBarWidget->setLayout(pGridLayout);

	QVBoxLayout * pLayout = new QVBoxLayout;
	pLayout->setContentsMargins(0, 0, 0, 0);
	pLayout->setMenuBar(pMenuBarWidget);
	pLayout->addWidget(m_pScrollArea);
	setLayout(pLayout);

	m_pSelectButton->hide();
	m_pResetButton->hide();
	m_pAlgName->hide();
	m_pAlgUtility->hide();

//	UpdateCounts();
//	QObject::connect(this, SIGNAL(PanelAdded(QSidePanel *)), this, SLOT(UpdateCounts(QSidePanel *)));
	QObject::connect(m_pSortComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SortPanels(int)));
}

void QSidePanelContainer::AddPanel(QSidePanel *pPanel){
	QVBoxLayout * pLayout;

	if(pPanel == NULL) return;
	pLayout = (QVBoxLayout*)m_pScrollArea->widget()->layout();
	
	if(pPanel->IsPinned()){
		m_PinnedPanelList.push_back(pPanel);
		pLayout->insertWidget(m_PinnedPanelList.size() - 1, pPanel);		
	}
	else{
		m_PanelList.push_back(pPanel);	
		pLayout->insertWidget(pLayout->count() - 1, pPanel);
	}
	
	pPanel->show();
	m_pScrollArea->widget()->adjustSize();
    connect(pPanel, SIGNAL(Clicked()), this, SLOT(PanelClicked()));
    //connect(pPanel, SIGNAL(StatusChanged()), this, SLOT(UpdateCounts()));
    connect(pPanel, SIGNAL(Pinned(bool)), this, SLOT(PanelPinned(bool)));
    connect(pPanel, SIGNAL(ResortRequested()), this, SLOT(SortPanels()));

	SortPanels(m_pSortComboBox->currentIndex());

	Q_EMIT(PanelAdded(pPanel));
}

void QSidePanelContainer::RemovePanel(QSidePanel * pPanel){
	QVBoxLayout * pLayout;
	long index = 0;

	if(pPanel == NULL) return;

	pLayout = (QVBoxLayout*)m_pScrollArea->widget()->layout();

	if(m_pSelected == pPanel) m_pSelected = NULL;

	index = m_PinnedPanelList.indexOf(pPanel);
	if(index != -1)  m_PinnedPanelList.removeAt(index);

	index = m_PanelList.indexOf(pPanel);
	if(index != -1)  m_PanelList.removeAt(index);

	pLayout->removeWidget(pPanel);
    pPanel->hide();
    //setLayout(pLayout);
    //UpdateCounts();
}

void QSidePanelContainer::RelayoutPanels(){
	QVBoxLayout * pLayout;
	long index = 0;

	pLayout = (QVBoxLayout*)m_pScrollArea->widget()->layout();
	
	setUpdatesEnabled(false);
	for(long iter = 0; iter < m_PinnedPanelList.size(); iter++){
		pLayout->insertWidget(index, m_PinnedPanelList[iter]);
		index++;
	}

	for(long iter = 0; iter < m_PanelList.size(); iter++){
		pLayout->insertWidget(index, m_PanelList[iter]);
		index++;
	}
	setUpdatesEnabled(true);
}

void QSidePanelContainer::SetPanelSelection(QSidePanel * pSelectedPanel) {
	
	if(pSelectedPanel != m_pSelected) {
		m_pSelected = pSelectedPanel;
		Q_EMIT(SelectionChanged(pSelectedPanel));
	}
	UpdatePanelSelection(pSelectedPanel);
}

void QSidePanelContainer::PanelClicked(){

	SetPanelSelection(static_cast<QSidePanel *>(sender()));	
}

void QSidePanelContainer::UpdatePanelSelection(QSidePanel * pSelectedPanel){

	for(long iter = 0; iter < m_PinnedPanelList.size(); iter++){
		if(pSelectedPanel == m_PinnedPanelList[iter] && !pSelectedPanel->IsSelected()){
			m_PinnedPanelList[iter]->ChangeSelection(true);
		}
		else{
			m_PinnedPanelList[iter]->ChangeSelection(false);
		}
	}

	for(long iter = 0; iter < m_PanelList.size(); iter++){
		if(pSelectedPanel == m_PanelList[iter] && !pSelectedPanel->IsSelected()){
			m_PanelList[iter]->ChangeSelection(true);
		}
		else{
			m_PanelList[iter]->ChangeSelection(false);
		}
	}
	update();
}

void QSidePanelContainer::PanelPinned(bool pinned){
	int index;
	QVBoxLayout * pLayout;
	QSidePanel * pPanel = (QSidePanel *)sender();

	pLayout = (QVBoxLayout*)m_pScrollArea->widget()->layout();

	index = m_PinnedPanelList.indexOf(pPanel);
	if(index != -1)  m_PinnedPanelList.removeAt(index);

	index = m_PanelList.indexOf(pPanel);
	if(index != -1)  m_PanelList.removeAt(index);

	if(pinned){
		m_PinnedPanelList.push_back(pPanel);
		pLayout->insertWidget(m_PinnedPanelList.size() - 1, pPanel);
	}
	else{
		m_PanelList.push_back(pPanel);
		pLayout->insertWidget(pLayout->count() - 2, pPanel);
		SortPanels(m_pSortComboBox->currentIndex());
	}
}

//void QSidePanelContainer::MapButtonClicked(){
//	void * pId = NULL;

//    if(m_pSelected)
//    {
//        pId = m_pSelected->Id();
//        Q_EMIT(CenterMapRequest(pId));
//    }
//}

//void QSidePanelContainer::UpdateCounts(QSidePanel * pNotUsed){
//	QSidePanel * pPanel;

//	(void)pNotUsed;

//	m_UnknownCount = 0;
//	m_NormalCount = 0;
//	m_PausedCount = 0;
//	m_QueuedCount = 0;
//	m_CanceledCount = 0;
//	m_FailedCount = 0;
//	m_DoneCount = 0;

//	for(long iter = 0; iter < m_PanelList.size(); iter++){
	
//		pPanel = m_PanelList[iter];
//		switch(pPanel->Status()){
//			case QSidePanel::Unknown:
//				m_UnknownCount++;
//				break;

//			case QSidePanel::Normal:
//				m_NormalCount++;
//				break;

//			case QSidePanel::Paused:
//				m_PausedCount++;
//				break;

//			case QSidePanel::Queued:
//				m_QueuedCount++;
//				break;

//			case QSidePanel::Canceled:
//				m_CanceledCount++;
//				break;

//			case QSidePanel::Failed:
//				m_FailedCount++;
//				break;
			
//			case QSidePanel::Done:
//				m_DoneCount++;
//				break;
			
//			case QSidePanel::Alg:
//				break;

//			default:
//				assert(0);
//				break;
//		};
//	}

//	QString text = QString("Unknown: %1 Normal: %2 Paused: %3 Queued: %4 Canceled: %5 Failed: %6 Done: %7").arg(m_UnknownCount).arg(m_NormalCount).arg(m_PausedCount).arg(m_QueuedCount).arg(m_CanceledCount).arg(m_FailedCount).arg(m_DoneCount);
//	m_pCounts->setText(text);
//}
