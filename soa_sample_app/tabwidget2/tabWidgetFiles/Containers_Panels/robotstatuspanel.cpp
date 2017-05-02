#include "robotstatuspanel.h"

#include <QLabel>
#include <QRect>
#include <QStyle>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <assert.h>

const long ROBOT_NAME_LENGTH = 20;
const long REGION_LENGTH = 4;
const long TASK_NAME_LENGTH = 25;
const long LOCATION_LENGTH = strlen("Location: xxx.xx xxx.xx xxx.xx");
const long MAXIMUM_PRIORITY_LEVEL = 7;
const long COUNT_LENGTH = 1;
const QSidePanel::PanelMode MAX_MODE = QSidePanel::Mode3;

RobotStatusPanel::RobotStatusPanel(void * pId, QWidget * parent) : QSidePanel(pId, parent){

	if(m_RobotStatusInstanceCount == 0) RobotStatusInit();
	m_RobotStatusInstanceCount++;

	// Create labels
	m_pNameLabel = new QLabel(tr("Wall*E"), this);
	m_pRegionLabel = new QLabel(tr("R3"), this);
	m_pLocationLabel = new QLabel(tr("wef"), this);
	m_pNotesLabel = new QLabel("Notes:", this);

	m_pNameLabel->setFont(m_Font);
	m_pNameLabel->setFixedWidth(ROBOT_NAME_LENGTH * m_FontMetrics.width('W') + 2 * (m_pNameLabel->frameWidth() + 2));
	m_pNameLabel->setFixedHeight(m_FontMetrics.height());
	m_pNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	m_pRegionLabel->setFont(m_Font);
	m_pRegionLabel->setFixedWidth(REGION_LENGTH * m_FontMetrics.width('W') + 2 * (m_pRegionLabel->frameWidth() + 2));
	m_pRegionLabel->setFixedHeight(m_FontMetrics.height());
	m_pRegionLabel->setAlignment(Qt::AlignCenter);

	m_pLocationLabel->setFont(m_Font);
	m_pLocationLabel->setFixedHeight(m_FontMetrics.height());
	m_pLocationLabel->setAlignment(Qt::AlignCenter);

	m_pLine1Layout = new QHBoxLayout;
	m_pLine1Layout->addWidget(m_pNameLabel, 0, Qt::AlignCenter);
	m_pLine1Layout->addStretch(1);
	m_pLine1Layout->addWidget(m_pRegionLabel, 0, Qt::AlignVCenter);

	m_pLine2Layout = new QHBoxLayout;
	m_pLine2Layout->addWidget(m_pLocationLabel);
	m_pLine2Layout->addStretch(1);

	m_pBottomLayout = new QHBoxLayout;
	m_pBottomLayout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);
	m_pBottomLayout->addWidget(m_pNotesLabel);

	m_pMainLayout = new QVBoxLayout;
	m_pMainLayout->setContentsMargins(0, OUTER_CONTENTS_MARGIN, 0, m_pBorderPixmap->height() + OUTER_CONTENTS_MARGIN);
	m_pMainLayout->setSpacing(0);
	m_pMainLayout->addLayout(m_pLine1Layout);
	m_pMainLayout->addLayout(m_pLine2Layout);
	m_pMainLayout->addLayout(m_pBottomLayout);
	setLayout(m_pMainLayout);

	ChangeStatus(Normal);
	ChangeMode(Mode1);
	ChangeLocation(m_Location);
}

RobotStatusPanel::~RobotStatusPanel(){

	m_RobotStatusInstanceCount--;
	if(m_RobotStatusInstanceCount <= 0){
		m_RobotStatusInstanceCount = 0;
		RobotStatusShutdown();
	}
}

void RobotStatusPanel::ChangeStatus(PanelStatus status, bool resort){
	
	QSidePanel::ChangeStatus(status, resort);
}

void RobotStatusPanel::ChangeMode(PanelMode mode, bool resort){

	assert(mode >= Mode1 && mode <= MAX_MODE);

	m_Mode = mode;
	setUpdatesEnabled(false);

	m_pLocationLabel->hide();
	m_pNotesLabel->hide();

	if(m_Mode == Mode1){
		m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, m_pSmallLowerCornerPixmap->width(), 0);
	}
	else{
		m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, OUTER_CONTENTS_MARGIN, 0);
	}

	if(m_Mode > Mode1) m_pLocationLabel->show();
	if(m_Mode > Mode2) m_pNotesLabel->show();

	PositionPlusMinus();
	if(parent()) ((QWidget*)parent())->adjustSize();
	if(resort) Q_EMIT(ResortRequested());
	setUpdatesEnabled(true);
}

void RobotStatusPanel::DecreaseMode(){

	long requested = m_Mode - 1;
	PanelMode mode = (requested < Mode1) ? Mode1 : (PanelMode)requested;
	ChangeMode(mode);
}

void RobotStatusPanel::IncreaseMode(){

	long requested = m_Mode + 1;
	PanelMode mode = (requested > MAX_MODE) ? MAX_MODE : (PanelMode)requested;
	ChangeMode(mode);
}

void RobotStatusPanel::ChangeName(QString name, bool resort){

	m_pNameLabel->setText(name);
	if(resort) Q_EMIT(ResortRequested());
}

void RobotStatusPanel::ChangeRegion(QString region, bool resort){

	m_pRegionLabel->setText(region);
	if(resort) Q_EMIT(ResortRequested());
}

void RobotStatusPanel::ChangeNotes(QString notes, bool resort){

	m_pNotesLabel->setText(notes);
	if(resort) Q_EMIT(ResortRequested());
}

bool RobotStatusPanel::PlusPresent(PanelMode mode){

	if(mode == MAX_MODE) return(false);
	else return(true);
}

bool RobotStatusPanel::MinusPresent(PanelMode mode){

	if(mode == Mode1) return(false);
	else return(true);
}

void RobotStatusPanel::ChangeLocation(QPointF point){

	QString text;
	text.sprintf("Location: %3.2f %3.2f ", point.rx(), point.ry());
	m_pLocationLabel->setText(text);
}

void RobotStatusPanel::RobotStatusInit() {}
void RobotStatusPanel::RobotStatusShutdown() {}

int RobotStatusPanel::m_RobotStatusInstanceCount = 0;
