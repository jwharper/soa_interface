#ifndef __RobotStatusSidePanelContainer__
#define __RobotStatusSidePanelContainer__

class RobotStatusPanel;

#include "../OldCode/qsidepanelcontainer.h"

class RobotStatusSidePanelContainer : public QSidePanelContainer{
	Q_OBJECT

public:
	enum RobotStatusSortMethods {SortNameDescending, SortNameAscending};

public:
	RobotStatusSidePanelContainer(QWidget * parent = 0);

	int MinimumWidth();

public Q_SLOTS:
	virtual void SortPanels(int method = -1);

protected:
	static bool SortNameDescendingLessThan(QSidePanel * a, QSidePanel * b);
	static bool SortNameAscendingLessThan(QSidePanel * a, QSidePanel * b);
};

#endif
