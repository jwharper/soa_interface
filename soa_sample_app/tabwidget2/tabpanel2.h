#ifndef TABPANEL2_H
#define TABPANEL2_H

class QSpinBox;
class QAction;
class QActionGroup;
class QComboBox;
class QToolBar;
class QMenu;
class QSidePanel;
class ByTaskSidePanelContainer;
class QSidePanelContainerTabWidget;

#include <QWidget>
#include <QVariant>
#include "../taskpanelwidget/taskpanelwidget.h"

class TabPanel2 : public QWidget{
    Q_OBJECT

public:
    struct Task;

public:
    TabPanel2(QWidget * parent = 0);
    ~TabPanel2();

    Q_SIGNAL void centerOnTask(int pId);
    Q_SIGNAL void taskActive(int Id);
    Q_SIGNAL void editTask(int Id);

    Q_SLOT void CenterMapOnTask(void * pId);
    Q_SLOT void RemovePanel(QAction * pAction);
    Q_SLOT void SidePanelContextMenuActionTriggered(QAction * pAction);
    Q_SLOT void addTask(taskInfo * ttask);
    Q_SLOT void taskSelected(QSidePanel *);
    Q_SLOT void taskEdit(QSidePanel *);
    Q_SLOT void endTask(int id);



protected:
    void CreateGeneralActions();
    void CreateGeneralToolBar();

    QSidePanelContainerTabWidget * m_pSidePanelContainerTabWidget;
    ByTaskSidePanelContainer * m_pByTaskSidePanelContainer;

    QMenu * m_pByTaskPanelContextMenu;
    QAction * m_pPauseTaskAction;
    QAction * m_pCancelTaskAction;

    QList<Task *> m_TaskList;

    QToolBar * m_pGeneralToolBar;

    QActionGroup * m_pRemovePanelActionGroup;
    QAction * m_pRemoveByTaskPanelAction;
};

#endif
