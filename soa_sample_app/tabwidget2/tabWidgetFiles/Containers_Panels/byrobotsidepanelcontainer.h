#ifndef __ByRobotSidePanelContainer__
#define __ByRobotSidePanelContainer__

class ByRobotPanel;

#include "../OldCode/qsidepanelcontainer.h"

class ByRobotSidePanelContainer : public QSidePanelContainer{
	Q_OBJECT

public:
	enum ByRobotSortMethods {SortNameDescending, SortNameAscending};

public:
	ByRobotSidePanelContainer(QWidget * parent = 0);
	int MinimumWidth();

public Q_SLOTS:
	virtual void SortPanels(int method = -1);

protected:
	static bool SortNameDescendingLessThan(QSidePanel * a, QSidePanel * b);
	static bool SortNameAscendingLessThan(QSidePanel * a, QSidePanel * b);
};

#endif
