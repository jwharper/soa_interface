#include "byrobotpanel.h"

#include <QLabel>
#include <QRect>
#include <QStyle>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <assert.h>

const long ROBOT_NAME_LENGTH = 20;
const long COUNT_LENGTH = 1;
const QSidePanel::PanelMode MAX_MODE = QSidePanel::Mode2;

ByRobotPanel::ByRobotPanel(robotData * tRobot, QWidget * parent) : QSidePanel(parent){

	//IDEKWTF this is about.
	if(m_ByRobotInstanceCount == 0) ByRobotInit();
	m_ByRobotInstanceCount++;


	SidePanelInit();

	//
	m_pTaskLabel = new QLabel("", this);
	m_pTaskLabel->setTextFormat(Qt::RichText);
	QString tLabel = "<i>task:</i> " + tRobot->rTask;
	m_pTaskLabel->setText(tLabel);
	m_pRobotLatLng = new QLabel("", this);
	m_pRobotLatLng->setTextFormat(Qt::RichText);
	QString ttLabel = "<i>locatiom:</i> (" + QString::number(tRobot->lat) + ", " + QString::number(tRobot->lng) + ")";
	m_pRobotLatLng->setText(ttLabel);
	//m_pDivisionLabel = new QLabel(tRobot->div, this);
	m_pRobotIcon = new QLabel("", this);
	if (tRobot->rType.toLower() == "uav")
		m_pRobotIcon->setPixmap(* m_pUavPixmap);
	else
		m_pRobotIcon->setPixmap(* m_pUgvPixmap);

	m_RobotId = tRobot->Id;
	m_Division = "";
	m_RobotType = tRobot->rType;

	// Create labels
	m_pNameLabel = new QLabel(tRobot->rName, this);

	m_pNameLabel->setFont(m_Font);
	m_pNameLabel->setFixedWidth(ROBOT_NAME_LENGTH * m_FontMetrics.width('W') + 2 * (m_pNameLabel->frameWidth() + 2));
	m_pNameLabel->setFixedHeight(m_FontMetrics.height());
	m_pNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	m_pLine1Layout = new QHBoxLayout;
	m_pLine1Layout->addWidget(m_pRobotIcon);
	m_pLine1Layout->addWidget(m_pNameLabel);//, 0, Qt::AlignCenter);
	m_pLine1Layout->addStretch(1);
	m_pLine1 = new QLabel("", this);
	m_pLine1->setLayout(m_pLine1Layout);

	m_pLine2Layout = new QHBoxLayout;
	m_pLine2Layout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);
	m_pLine2Layout->addWidget(m_pTaskLabel);	
	m_pLine2Layout->addWidget(m_pRobotLatLng);	
	m_pLine2 = new QLabel("", this);
	m_pLine2->setLayout(m_pLine2Layout);

	m_pMainLayout = new QVBoxLayout;
	m_pMainLayout->setContentsMargins(0, OUTER_CONTENTS_MARGIN, 0, m_pBorderPixmap->height() + OUTER_CONTENTS_MARGIN);
	m_pMainLayout->setSpacing(0);
	m_pMainLayout->addWidget(m_pLine1, Qt::AlignVCenter);
	m_pMainLayout->addWidget(m_pLine2);
	setLayout(m_pMainLayout);

	ChangeStatus(Queued);
	ChangeMode(Mode1);
}

ByRobotPanel::~ByRobotPanel(){

	m_ByRobotInstanceCount--;
	if(m_ByRobotInstanceCount <= 0){
		m_ByRobotInstanceCount = 0;
		ByRobotShutdown();
	}
}

void ByRobotPanel::ChangeMode(PanelMode mode, bool resort){

	assert(mode >= Mode1 && mode <= MAX_MODE);

	m_Mode = mode;
	setUpdatesEnabled(false);

	if(m_Mode == Mode1){
		m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, m_pSmallLowerCornerPixmap->width(), 0);
	}
	else{
		m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, OUTER_CONTENTS_MARGIN, 0);
	}

	if(m_Mode == Mode1){
	}
	else{
	}

	PositionPlusMinus();
	if(parent()) ((QWidget*)parent())->adjustSize();
	if(resort) Q_EMIT(ResortRequested());
	setUpdatesEnabled(true);
}

void ByRobotPanel::DecreaseMode(){

	long requested = m_Mode - 1;
	PanelMode mode = (requested < Mode1) ? Mode1 : (PanelMode)requested;
	ChangeMode(mode);
}

void ByRobotPanel::IncreaseMode(){

	long requested = m_Mode + 1;
	PanelMode mode = (requested > MAX_MODE) ? MAX_MODE : (PanelMode)requested;
	ChangeMode(mode);
}

void ByRobotPanel::ChangeName(QString name, bool resort){

	m_pNameLabel->setText(name);
	if(resort) Q_EMIT(ResortRequested());
}

bool ByRobotPanel::PlusPresent(PanelMode mode){

	if(mode == MAX_MODE) return(false);
	else return(true);
}

bool ByRobotPanel::MinusPresent(PanelMode mode){

	if(mode == Mode1) return(false);
	else return(true);
}

void ByRobotPanel::ByRobotInit() {}

void ByRobotPanel::ByRobotShutdown() {}

int ByRobotPanel::m_ByRobotInstanceCount = 0;
