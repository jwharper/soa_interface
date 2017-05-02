#ifndef __ByTaskPanel__
#define __ByTaskPanel__

class QLabel;
class QVBoxLayout;
class QHBoxLayout;

#include <QTime>
#include <QPushButton>
#include <QProgressBar>
#include <QGridLayout>
#include "../OldCode/qsidepanel.h"
#include "../taskpanelwidget/taskpanelwidget.h"

class ByTaskPanel : public QSidePanel{
	Q_OBJECT

public:
    enum ByTaskPanelDivision {Blue, Red};
	struct QSubTask;

public:
    ByTaskPanel(taskInfo* ttask, QWidget * parent = 0);
	~ByTaskPanel();

	QString Name() {return(m_pNameLabel->text());}
    QString Leader() {return(m_pLeaderLabel->text());}
    Q_SIGNAL void taskPause(int taskId);
    Q_SIGNAL void taskPlay(int taskId);

public Q_SLOTS:
	virtual void ChangeMode(PanelMode mode, bool resort = false);
	void ChangeName(QString name, bool resort = false);
	void ChangeLeader(QString leader, bool resort = false);
    /*void togglePausePlay();
	void startTask();
	void cancelTask();
	void pauseTask();*/

protected Q_SLOTS:
	virtual void DecreaseMode();
	virtual void IncreaseMode();

protected:
	void ByTaskInit();
	void ByTaskShutdown();

	virtual bool PlusPresent(PanelMode mode);
	virtual bool MinusPresent(PanelMode mode);

protected:	
	QVBoxLayout * m_pMainLayout;
	//QVBoxLayout * m_pMinLayout;
	//QVBoxLayout * m_pMaxLayout;
    QHBoxLayout * m_pLine1Layout;
	QGridLayout * m_pLine2Layout;
	QHBoxLayout * m_pBottomLayout;
	QLabel * m_pLine1;
	QLabel * m_pLine2;
    int m_ActorId;

	//runningBar * m_pRunningBar;
	QProgressBar * m_pRunningBar;
	QLabel * m_pRunningLabel;
	QLabel * m_pNameLabel;
	QLabel * m_pTaskIcon;
	QLabel * m_pPriorityLabel;
	QLabel * m_pInterruptIcon;
	QLabel * m_pUavIcon;
	QLabel * m_pUavCount;
	QLabel * m_pUgvIcon;
	QLabel * m_pUgvCount;
	QLabel * m_pLeaderLabel;
//	QPushButton * m_pPausePlay;
	bool m_Paused;

	int m_TaskId;

	static int m_ByTaskInstanceCount;
};

#endif
