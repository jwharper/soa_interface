#include "qsidepanelcontainertabwidget.h"

#include <QScrollArea>
#include <QScrollBar>

#include "qsidepanel.h"
#include "qsidepanelcontainer.h"

QSidePanelContainerTabWidget::QSidePanelContainerTabWidget(QList<QPair<QSidePanelContainer *, QString> > containerList, QWidget * parent) : QTabWidget(parent){
	long requiredWidth = 0;

	if(containerList.empty()) return;

	for(int iter = 0; iter < containerList.size(); iter++){
		m_ContainerList.push_back(containerList[iter].first);
		if(requiredWidth < m_ContainerList[iter]->MinimumWidth()) requiredWidth = m_ContainerList[iter]->MinimumWidth();
	}

	requiredWidth = 390;
	QSidePanel::SetForcedWidth(requiredWidth);
	requiredWidth += m_ContainerList[0]->ScrollArea()->verticalScrollBar()->width() + 2 * m_ContainerList[0]->ScrollArea()->frameWidth();

	QSizePolicy tabSizePolicy = sizePolicy();
	tabSizePolicy.setHorizontalPolicy(QSizePolicy::Fixed);
	setSizePolicy(tabSizePolicy);



	for(int iter = 0; iter < containerList.size(); iter++){
		m_ContainerList[iter]->setFixedWidth(requiredWidth);
		addTab(m_ContainerList[iter], containerList[iter].second);
	}
}
