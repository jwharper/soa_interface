#ifndef __RobotStatusPanel__
#define __RobotStatusPanel__

class QLabel;
class QVBoxLayout;
class QHBoxLayout;

#include <QTime>
#include "../OldCode/qsidepanel.h"

//#include "../../../classes/miscclasses/miscclasses/qpoint3f.h"

class RobotStatusPanel : public QSidePanel{
	Q_OBJECT

public:
	enum PanelType {UGV, UAV, Responder};

public:
	RobotStatusPanel(void * pId = NULL, QWidget * parent = 0);
	~RobotStatusPanel();

	QString Name() {return(m_pNameLabel->text());}
	RobotStatusPanel::PanelType Type() {return(m_Type);}
	QString Region() {return(m_pRegionLabel->text());}
	QString Notes() {return(m_pNotesLabel->text());}

public Q_SLOTS:
	virtual void ChangeStatus(PanelStatus status, bool resort = false);
	virtual void ChangeMode(PanelMode mode, bool resort = false);
	void ChangeName(QString name, bool resort = false);
	void ChangeRegion(QString region, bool resort = false);
	void ChangeNotes(QString notes, bool resort = false);
	void ChangeLocation(QPointF point);

protected Q_SLOTS:
	virtual void DecreaseMode();
	virtual void IncreaseMode();

protected:
	void RobotStatusInit();
	void RobotStatusShutdown(); 

	virtual bool PlusPresent(PanelMode mode);
	virtual bool MinusPresent(PanelMode mode);

protected:
	PanelType m_Type;

	QVBoxLayout * m_pMainLayout;
	QHBoxLayout * m_pLine1Layout;
	QHBoxLayout * m_pLine2Layout;
	QHBoxLayout * m_pBottomLayout;

	QLabel * m_pNameLabel;
	QLabel * m_pTypeLabel;
	QLabel * m_pRegionLabel;
	QLabel * m_pLocationLabel;
	QLabel * m_pNotesLabel;

	QPointF m_Location;

	static int m_RobotStatusInstanceCount;
};

#endif
