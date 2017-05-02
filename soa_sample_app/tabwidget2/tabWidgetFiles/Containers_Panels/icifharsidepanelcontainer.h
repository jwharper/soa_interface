#ifndef __iCiFHaRSidePanelContainer__
#define __iCiFHaRSidePanelContainer__

class iCiFHaRPanel;

#include <QPushButton>
#include "../OldCode/qsidepanelcontainer.h"

class iCiFHaRSidePanelContainer : public QSidePanelContainer{
	Q_OBJECT
		
public:
	iCiFHaRSidePanelContainer(QWidget * parent = 0);

	int MinimumWidth();

public Q_SLOTS:
	virtual void SortPanels(int method = -1);
};

#endif
