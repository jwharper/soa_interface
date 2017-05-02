#ifndef __QSIDEPANEL__
#define __QSIDEPANEL__

#include "../qclicklabel.h"
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QFrame>
#include <QWidget>
#include <QDebug>
#include <QPixmap>


class QMenu;
class QAction;
class QContextMenuEvent;

class runningBar : public QWidget {
	Q_OBJECT

public:
	runningBar(QWidget * parent = 0) : QWidget(parent) 
	{
		qDebug()<<"Buffalo";
	};
	QLabel * label;
	QProgressBar * bar;
	void init()	{
		QVBoxLayout * vbox = new QVBoxLayout;
		label = new QLabel;
		label->setTextFormat(Qt::RichText);
		label->setText("<i>Running</i>");
		label->setMaximumHeight(12);
		bar = new QProgressBar;
		bar->setTextVisible(false);
		bar->setMaximumHeight(10);
		setLayout(vbox);
	};
};




class QSidePanel : public QFrame{
	Q_OBJECT

public:
	enum PanelMode {ModeInvalid = -1, Mode1, Mode2, Mode3, Mode4};
	enum PanelStatus {Unknown, Normal, Paused, Canceled, Queued, Failing, Failed, Done, Alg};

public:
	QSidePanel(void * pId = NULL, QWidget * parent = 0);
	virtual ~QSidePanel();

public:
	int m_Id;
	void setId(int tId){m_Id = tId;}
	QList<int> m_RobotIds;
	void setRobotIds(QList<int> tRobotIds){m_RobotIds = tRobotIds;}
	QString m_Division;
	void setDivision(QString div){m_Division = div;}

	void * Id() const {return(m_pId);}
	QMenu * ContextMenu() const {return(m_pContextMenu);}
	void SetContextMenu(QMenu * pContextMenu) {m_pContextMenu = pContextMenu;}

	static void SetForcedWidth(long width) {m_ForcedWidth = width;}

	const QBrush & FailingBrush() const {return(m_FailingBrush);}
	const QBrush & FailedBrush() const {return(m_FailedBrush);}

	QSidePanel::PanelMode Mode() const {return(m_Mode);}
	QSidePanel::PanelStatus Status() const {return(m_Status);}

	bool IsSelected() const {return(m_Selected);}
	bool IsPinned() const {return(m_Pinned);}

	Q_SLOT void ChangeSelection(bool state);
	Q_SLOT void ChangePinned(bool pinned);
	Q_SLOT void PinClicked();
	Q_SLOT virtual void ChangeMode(PanelMode mode, bool resort = false) = 0;
	Q_SLOT virtual void ChangeStatus(PanelStatus status, bool resort = false);
	Q_SLOT void ChangeFailingBrush(QBrush brush);
	Q_SLOT void ChangeFailedBrush(QBrush brush);

	Q_SIGNAL void Clicked();
	Q_SIGNAL void Pressed();
	Q_SIGNAL void Released();
	Q_SIGNAL void DoubleClicked();
	Q_SIGNAL void SelectionChanged(bool state);
	Q_SIGNAL void StatusChanged();
	Q_SIGNAL void Pinned(bool pinned);
	Q_SIGNAL void ResortRequested();
	Q_SIGNAL void ContextMenuActionTriggered(QAction * pAction);

//protected:
	static const long OUTER_CONTENTS_MARGIN = 2;
	static const long INNER_CONTENTS_MARGIN = 2;

	Q_SLOT virtual void DecreaseMode() = 0;
	Q_SLOT virtual void IncreaseMode() = 0;

	void SidePanelInit();
	void SidePanelShutdown();

	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void mouseDoubleClickEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void contextMenuEvent(QContextMenuEvent * pEvent);
	void paintEvent(QPaintEvent * event);
	void resizeEvent(QResizeEvent * event);
	void PositionPlusMinus();
	virtual bool PlusPresent(PanelMode mode) = 0;
	virtual bool MinusPresent(PanelMode mode) = 0;

	void * m_pId;
	QMenu * m_pContextMenu;

	bool m_Over;
	bool m_Selected;
	bool m_Pinned;

	PanelStatus m_Status;
	PanelMode m_Mode;

	QBrush m_FailingBrush;
	QBrush m_FailedBrush;

	QClickLabel * m_pPin;
	QClickLabel * m_pPlus;
	QClickLabel * m_pMinus;

	static int m_SidePanelInstanceCount;
	static long m_ForcedWidth;
	static QPixmap * m_pPinPixmap;
	static QPixmap * m_pPinnedPixmap;
	static QPixmap * m_pPlusPixmap;
	static QPixmap * m_pMinusPixmap;
	static QPixmap * m_pLowerCornerPixmap;
	static QPixmap * m_pSmallLowerCornerPixmap;
	static QPixmap * m_pUpperCornerPixmap;
	static QPixmap * m_pBorderPixmap;
	static QPixmap * m_pInterruptPixmap;
	static QPixmap * m_pUavPixmap;
	static QPixmap * m_pUgvPixmap;
	static QPixmap * m_pPlayPixmap;
	static QPixmap * m_pPausePixmap;

	static QFont m_Font;
	static QFontMetrics m_FontMetrics;
	static QFont m_Font2;
	static QFontMetrics m_FontMetrics2;


};

#endif
