#ifndef __EABTABWIDGET__
#define __EABTABWIDGET__

class QSpinBox;
class QAction;
class QActionGroup;
class QComboBox;
class QToolBar;
class QMenu;
class QSidePanel;
class iCiFHaRSidePanelContainer;
class ByTaskSidePanelContainer;
class ByRobotSidePanelContainer;
class RobotStatusSidePanelContainer;
class QSidePanelContainerTabWidget;

#include <QWidget>
#include <QVariant>
#include "../../eabmapwidget/eabmapwidget/EABMapItems/EABMapBase.h"

class EABTabWidget : public QWidget{
	Q_OBJECT

public:
	struct Task;

public:
	EABTabWidget(QWidget * parent = 0);
	~EABTabWidget();

	Q_SIGNAL void centerOnTask(int pId);
	Q_SIGNAL void centerOnRobot(int pId);
	Q_SIGNAL void taskActive(int Id);
	Q_SIGNAL void robotActive(int Id);
	Q_SIGNAL void editTask(int Id);

	Q_SLOT void CenterMapOnTask(void * pId);
	Q_SLOT void CenterMapOnRobot(void * pId);
	Q_SLOT void RemovePanel(QAction * pAction);
	Q_SLOT void SidePanelContextMenuActionTriggered(QAction * pAction);
	//Q_SLOT void addTask(int pId, QString name, QString leader, QString division, QList<int> robotIds);
	Q_SLOT void addTask(taskData * ttask);
	//Q_SLOT void addRobot1(int id, QString division, QString robotType, QString robotName, void * pId = 0);
	Q_SLOT void addRobot(robotData * tRobot);
	Q_SLOT void taskSelected(QSidePanel *);
	Q_SLOT void robotSelected(QSidePanel *);
	Q_SLOT void taskEdit(QSidePanel *);

protected:
	void CreateGeneralActions();
	void CreateGeneralToolBar();

	QSidePanelContainerTabWidget * m_pSidePanelContainerTabWidget;
	iCiFHaRSidePanelContainer * m_piCiFHaRSidePanelContainer;
	ByTaskSidePanelContainer * m_pByTaskSidePanelContainer;
	ByRobotSidePanelContainer * m_pByRobotSidePanelContainer;
	RobotStatusSidePanelContainer * m_pRobotStatusSidePanelContainer;

	QMenu * m_pByTaskPanelContextMenu;
	QAction * m_pPauseTaskAction;
	QAction * m_pCancelTaskAction;

	QList<Task *> m_TaskList;

	QToolBar * m_pGeneralToolBar;

	QActionGroup * m_pRemovePanelActionGroup;
	QAction * m_pRemoveByTaskPanelAction;
	QAction * m_pRemoveByRobotPanelAction;
	QAction * m_pRemoveRobotStatusPanelAction;
};

#endif