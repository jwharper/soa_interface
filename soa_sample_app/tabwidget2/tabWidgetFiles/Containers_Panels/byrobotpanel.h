#ifndef __ByRobotPanel__
#define __ByRobotPanel__

class QLabel;
class QVBoxLayout;
class QHBoxLayout;

#include <QTime>
#include "../OldCode/qsidepanel.h"
#include "../../../eabmapwidget/eabmapwidget/EABMapItems/EABMapBase.h"

class ByRobotPanel : public QSidePanel{
	Q_OBJECT

public:
	ByRobotPanel(robotData * tRobot, QWidget * parent = 0);
	virtual ~ByRobotPanel();
public:
	QString m_RobotType;

	QString Name() {return(m_pNameLabel->text());}

public Q_SLOTS:
	virtual void ChangeMode(PanelMode mode, bool resort = false);
	void ChangeName(QString name, bool resort = false);

protected Q_SLOTS:
	virtual void DecreaseMode();
	virtual void IncreaseMode();

protected:
	void ByRobotInit();
	void ByRobotShutdown();

	virtual bool PlusPresent(PanelMode mode);
	virtual bool MinusPresent(PanelMode mode);

protected:
	QVBoxLayout * m_pMainLayout;
	QHBoxLayout * m_pLine1Layout;
	QHBoxLayout * m_pLine2Layout;
	QHBoxLayout * m_pBottomLayout;

	QLabel * m_pNameLabel;
	PanelStatus m_Status;
	QLabel * m_pTaskLabel;
	QLabel * m_pOwnerLabel;
	QLabel * m_pDivisionLabel;
	QLabel * m_pRobotIcon;
	QLabel * m_pRobotLatLng;
	QLabel * m_pLine1;
	QLabel * m_pLine2;

	int m_RobotId;


	static int m_ByRobotInstanceCount;
};

#endif
