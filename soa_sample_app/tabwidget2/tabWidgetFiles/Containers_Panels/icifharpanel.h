#ifndef __iCiFHaRPanel__
#define __iCiFHaRPanel__

class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QTaskProgress;

#include <QTime>
#include "../OldCode/qsidepanel.h"

class iCiFHaRPanel : public QSidePanel{
	Q_OBJECT

public:
	struct iCiFHaRResult{
		QString algorithm;
		double utility;
	};

public:
	iCiFHaRPanel(void * pId = NULL, QWidget * parent = 0);
	~iCiFHaRPanel();

	QList <iCiFHaRResult> m_ResultList;
	QString Name() {return(m_pNameLabel->text());}
	QString Utility() {return(m_pUtilityLabel->text());}

public Q_SLOTS:
	virtual void ChangeMode(PanelMode mode, bool resort = false);
	void ChangeName(QString name, bool resort = false);
	void ChangeUtility(QString utility, bool resort = false);

protected Q_SLOTS:
	virtual void DecreaseMode();
	virtual void IncreaseMode();

protected:
	void iCiFHaRInit();
	void iCiFHaRShutdown();

	virtual bool PlusPresent(PanelMode mode);
	virtual bool MinusPresent(PanelMode mode);

protected:
	QVBoxLayout * m_pMainLayout;
	QHBoxLayout * m_pLine1Layout;
	QHBoxLayout * m_pLine2Layout;
	QHBoxLayout * m_pBottomLayout;

	QLabel * m_pNameLabel;
	QLabel * m_pUtilityLabel;

	static int m_iCiFHaRInstanceCount;
};

#endif
