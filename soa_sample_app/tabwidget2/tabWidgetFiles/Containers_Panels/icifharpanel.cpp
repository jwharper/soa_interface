#include "icifharpanel.h"

#include <QLabel>
#include <QRect>
#include <QStyle>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <assert.h>

const long ALG_NAME_LENGTH = 23;
const long UTILITY_LENGTH = 6;
const QSidePanel::PanelMode MAX_MODE = QSidePanel::Mode2;

iCiFHaRPanel::iCiFHaRPanel(void * pId, QWidget * parent) : QSidePanel(pId, parent){

	if(m_iCiFHaRInstanceCount == 0) iCiFHaRInit();
	m_iCiFHaRInstanceCount++;

	// Create labels
	m_pNameLabel = new QLabel(tr("Dewey, Cheatam , and How"), this);
	m_pUtilityLabel = new QLabel("9278.8", this);
	m_Status = Alg;

	m_pNameLabel->setFont(m_Font);
	m_pNameLabel->setFixedWidth(ALG_NAME_LENGTH * m_FontMetrics.width('W') + 2 * (m_pNameLabel->frameWidth() + 2));
	m_pNameLabel->setFixedHeight(m_FontMetrics.height());
	m_pNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	m_pUtilityLabel->setFont(m_Font);
	m_pUtilityLabel->setFixedWidth(UTILITY_LENGTH * m_FontMetrics.width('W') + 2 * (m_pUtilityLabel->frameWidth() + 2));
	m_pUtilityLabel->setFixedHeight(m_FontMetrics.height());
	m_pUtilityLabel->setAlignment(Qt::AlignCenter);

	m_pLine1Layout = new QHBoxLayout;
	m_pLine1Layout->addWidget(m_pNameLabel, 0, Qt::AlignCenter);
	m_pLine1Layout->addStretch(1);
	m_pLine1Layout->addWidget(m_pUtilityLabel, 0, Qt::AlignVCenter);


	//m_pBottomLayout = new QHBoxLayout;
	//m_pBottomLayout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);
	//m_pBottomLayout->addWidget(m_pNotesLabel);

	m_pMainLayout = new QVBoxLayout;
	m_pMainLayout->setContentsMargins(0, OUTER_CONTENTS_MARGIN, 0, m_pBorderPixmap->height() + OUTER_CONTENTS_MARGIN);
	m_pMainLayout->setSpacing(0);
	m_pMainLayout->addLayout(m_pLine1Layout);
	//m_pMainLayout->addLayout(m_pBottomLayout);
	setLayout(m_pMainLayout);

	//m_pNameLabel->setFont(m_Font);
	//m_pNameLabel->setFixedWidth(TASK_NAME_LENGTH * m_FontMetrics.width('W') + 2 * (m_pNameLabel->frameWidth() + 2));
	//m_pNameLabel->setFixedHeight(m_FontMetrics.height());
	//m_pNameLabel->setAlignment(Qt::AlignLeft);

	//m_pUtilityLabel->setFont(m_Font);
	//m_pUtilityLabel->setFixedWidth(UTILITY_LENGTH * m_FontMetrics.width('W') + 2 * (m_pUtilityLabel->frameWidth() + 2));
	//m_pUtilityLabel->setFixedHeight(m_FontMetrics.height());
	//m_pUtilityLabel->setAlignment(Qt::AlignRight);

	//m_pMainLayout = new QVBoxLayout;
	//m_pMainLayout->setContentsMargins(0, 0, 0, m_pBorderPixmap->height() + OUTER_CONTENTS_MARGIN);
	//m_pMainLayout->setSpacing(0);
	//setLayout(m_pMainLayout);

	//m_pLine1Layout = new QHBoxLayout;
	//m_pLine1Layout->addWidget(m_pNameLabel);
	////m_pLine1Layout->addWidget(m_pUtilityLabel);

	//m_pLine2Layout = new QHBoxLayout;
	//m_pLine2Layout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);
	//m_pLine2Layout->addWidget(m_pUtilityLabel);

	//m_pBottomLayout = new QHBoxLayout;
	//m_pBottomLayout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);

	//m_pMainLayout->addLayout(m_pLine1Layout);
	//m_pMainLayout->addLayout(m_pLine2Layout);
	//m_pMainLayout->addLayout(m_pBottomLayout);

	m_pPin->hide();
	m_pPlus->hide();
	m_pMinus->hide();

	ChangeStatus(Alg);
	ChangeMode(Mode1);
}

iCiFHaRPanel::~iCiFHaRPanel(){

	m_iCiFHaRInstanceCount--;
	if(m_iCiFHaRInstanceCount <= 0){
		m_iCiFHaRInstanceCount = 0;
		iCiFHaRShutdown();
	}
}

void iCiFHaRPanel::ChangeMode(PanelMode mode, bool resort){
	if(resort)
		qDebug()<<mode;
	//assert(mode >= Mode1 && mode <= MAX_MODE);

	//m_Mode = mode;
	//setUpdatesEnabled(false);

	//m_pUtilityLabel->hide();

	//if(m_Mode == Mode1){
	//	m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, m_pSmallLowerCornerPixmap->width(), 0);
	//}
	//else{
	//	m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, OUTER_CONTENTS_MARGIN, 0);
	//}

	//if(m_Mode != Mode1){
	//	m_pUtilityLabel->show();
	//}

	//PositionPlusMinus();
	//if(parent()) ((QWidget*)parent())->adjustSize();
	//if(resort) Q_EMIT(ResortRequested());
	//setUpdatesEnabled(true);
}

void iCiFHaRPanel::DecreaseMode(){
	qDebug()<<"icifhar decrease mode";
	//long requested = m_Mode - 1;
	//PanelMode mode = (requested < Mode1) ? Mode1 : (PanelMode)requested;
	//ChangeMode(mode);
}

void iCiFHaRPanel::IncreaseMode(){
	qDebug()<<"icifhar increase mode";
	//long requested = m_Mode + 1;
	//PanelMode mode = (requested > MAX_MODE) ? MAX_MODE : (PanelMode)requested;
	//ChangeMode(mode);
}

void iCiFHaRPanel::ChangeName(QString name, bool resort){

	m_pNameLabel->setText(name);
	if(resort) 
		qDebug()<<"Re-Sort requested, request denied";
}

void iCiFHaRPanel::ChangeUtility(QString utility, bool resort){

	m_pUtilityLabel->setText(utility);
	if(resort) 
		qDebug()<<"Re-Sort requested, request denied";
}

bool iCiFHaRPanel::PlusPresent(PanelMode mode){

	if(mode != MAX_MODE) 
		qDebug()<<"blarg";
	/*return(true);
	else */return(false);
}

bool iCiFHaRPanel::MinusPresent(PanelMode mode){

	if(mode != Mode1) 
		qDebug()<<"blarg";
	/*return(true);
	else */return(false);
}

void iCiFHaRPanel::iCiFHaRInit() {}

void iCiFHaRPanel::iCiFHaRShutdown() {}

int iCiFHaRPanel::m_iCiFHaRInstanceCount = 0;
