#ifndef __QSIDEPANELCONTAINERTABWIDGET__
#define __QSIDEPANELCONTAINERTABWIDGET__

class QSidePanelContainer;

#include <QTabWidget>
#include <QList>
#include <QPair>

class QSidePanelContainerTabWidget : public QTabWidget{
	Q_OBJECT

public:
	QSidePanelContainerTabWidget(QList<QPair<QSidePanelContainer *, QString> > containerList, QWidget * parent = 0);

protected:
	QList<QSidePanelContainer *> m_ContainerList;
};

#endif
