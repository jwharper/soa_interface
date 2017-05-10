#ifndef __SIDE_PANEL_CONTAINER__
#define __SIDE_PANEL_CONTAINER__

class QPushButton;
class QLabel;
class QComboBox;
class QScrollArea;
class QSidePanel;

#include <QWidget>
#include <QList>

class QSidePanelContainer : public QWidget{
	Q_OBJECT

public:
	QSidePanelContainer(QWidget * parent = 0);

	virtual int MinimumWidth() = 0;

	void AddPanel(QSidePanel * pPanel);
	void RemovePanel(QSidePanel * pPanel);

	const QScrollArea * ScrollArea() const {return(m_pScrollArea);}
	const QList<QSidePanel *> * Panels() const {return(&m_PanelList);}
	QSidePanel * Selected() const {return(m_pSelected);}

public Q_SLOTS:
	virtual void SortPanels(int method = -1) = 0;
	void PanelPinned(bool pinned);
//	void MapButtonClicked();

	/**
	 * Sets the SidePanel that is currently selected. If NULL is passed,
	 * the selection is cleared.
	 * @param pSelectedPanel The QSidePanel to be selected.
	 */
	void SetPanelSelection(QSidePanel * pSelectedPanel = NULL);

Q_SIGNALS:
	void SelectionChanged(QSidePanel *);
	void PanelAdded(QSidePanel * pPanel);
//	void CenterMapRequest(void * pId);

protected Q_SLOTS:
	/**
	 * @see QSidePanelContainer::SetPanelSelection()
	 */
	void PanelClicked();

//	void UpdateCounts(QSidePanel * pNotUsed = 0);

protected:
	void UpdatePanelSelection(QSidePanel * pSelectedPanel);
	void RelayoutPanels();

public:
	QSidePanel * m_pSelected;
	QScrollArea * m_pScrollArea;
	QList<QSidePanel *> m_PinnedPanelList;
	QList<QSidePanel *> m_PanelList;

	QPushButton * m_pCenterMapButton;
	QPushButton * m_pResetButton;
	QPushButton * m_pSelectButton;
	QLabel * m_pAlgName;
	QLabel * m_pAlgUtility;
	QLabel * m_pCounts;
	QLabel * m_pSortLabel;
	QComboBox * m_pSortComboBox;
};

#endif
