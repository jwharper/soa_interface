// bytasksidepanelcontainer.h
//
// Created by EAB
// 2016

#ifndef __ByTaskSidePanelContainer__
#define __ByTaskSidePanelContainer__

class ByTaskPanel;

#include "../OldCode/qsidepanelcontainer.h"
#include <QHash>

class ByTaskSidePanelContainer : public QSidePanelContainer{
	Q_OBJECT

public:
	enum ByTaskSortMethods {SortNameDescending, SortNameAscending};

public:
	ByTaskSidePanelContainer(QWidget * parent = 0);

    QHash <int, ByTaskPanel*> m_ByTaskPanelHash;
	int MinimumWidth();

public Q_SLOTS:
	virtual void SortPanels(int method = -1);

protected:
	static bool SortNameDescendingLessThan(QSidePanel * a, QSidePanel * b);
	static bool SortNameAscendingLessThan(QSidePanel * a, QSidePanel * b);

};

#endif
