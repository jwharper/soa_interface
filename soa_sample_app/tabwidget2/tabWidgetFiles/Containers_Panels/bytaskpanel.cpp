#include "bytaskpanel.h"

#include <QLabel>
#include <QRect>
#include <QStyle>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <assert.h>

const long TASK_NAME_LENGTH = 25;
const long LEADER_LENGTH = 25;
const QSidePanel::PanelMode MAX_MODE = QSidePanel::Mode2;

ByTaskPanel::ByTaskPanel(taskInfo * ttask, QWidget * parent) : QSidePanel(parent)
{

	if(m_ByTaskInstanceCount == 0) ByTaskInit();
	m_ByTaskInstanceCount++;

	SidePanelInit();

    m_TaskId = ttask->id;
    m_Division = "Blue";
    m_ActorId = ttask->actorId;
	m_Paused = false;

	// Create labels

	//m_pRunningBar = new runningBar;
	//m_pRunningBar->init();

//	m_pRunningBar = new QProgressBar(this);
//	m_pRunningBar->setFormat("Queued");
//	m_pRunningBar->setMaximumWidth(90);
//	m_pRunningBar->setMaximumHeight(10);
//	m_pRunningLabel = new QLabel("Queued", this);
//	QFont tfont = m_Font;
//	tfont.setWeight(QFont::Light);
//	m_pRunningLabel->setFont(tfont);
//	m_pRunningLabel->setFixedHeight(m_FontMetrics.height()-2);
//	QVBoxLayout * tBar = new QVBoxLayout;
//	tBar->addWidget(m_pRunningLabel);
//	tBar->addWidget(m_pRunningBar);


    m_pNameLabel = new QLabel(ttask->task);
    m_pNameLabel->setFont(m_Font);
	m_pNameLabel->setFixedWidth(TASK_NAME_LENGTH * m_FontMetrics.width('W') + 2 * (m_pNameLabel->frameWidth() + 2));
	m_pNameLabel->setFixedHeight(m_FontMetrics.height());
    m_pNameLabel->setAlignment(Qt::AlignLeft);

    m_pLeaderLabel = new QLabel(ttask->actor, this);
	m_pLeaderLabel->setFont(m_Font);
	m_pLeaderLabel->setFixedWidth(LEADER_LENGTH * m_FontMetrics.width('W') + 2 * (m_pLeaderLabel->frameWidth() + 2));
	m_pLeaderLabel->setFixedHeight(m_FontMetrics.height());
    m_pLeaderLabel->setAlignment(Qt::AlignLeft);

//	m_pUavCount = new QLabel(QString::number(ttask->uavCount), this);
//	m_pUavCount->setFont(m_Font);
	//m_pUavCount->setFixedSize(m_FontMetrics.height(), m_FontMetrics.height());
	//m_pUavCount->setFixedWidth(LEADER_LENGTH * m_FontMetrics.width('W') + 2 * (m_pUavCount->frameWidth() + 2));
	//m_pUavCount->setFixedHeight(m_FontMetrics.height());
	//m_pUavCount->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

//	m_pUgvCount = new QLabel(QString::number(ttask->ugvCount), this);
//	m_pUgvCount->setFont(m_Font);
//	m_pUgvCount->setFixedSize(19, 19);
	//m_pUgvCount->setFixedWidth(LEADER_LENGTH * m_FontMetrics.width('W') + 2 * (m_pUgvCount->frameWidth() + 2));
	//m_pUgvCount->setFixedHeight(m_FontMetrics.height());
	//m_pUgvCount->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);


    m_pPriorityLabel = new QLabel(QString::number(ttask->priority), this);
	m_pPriorityLabel->setFont(m_Font2);
	//m_pPriorityLabel->setFixedSize(19, 19);
	//m_pPriorityLabel->setFixedWidth(LEADER_LENGTH * m_FontMetrics2.width('W') + 2 * (m_pPriorityLabel->frameWidth() + 2));
	//m_pPriorityLabel->setFixedHeight(m_FontMetrics2.height());
	//m_pPriorityLabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

//	m_pInterruptIcon = new QLabel("", this);
//	m_pInterruptIcon->setPixmap(*m_pInterruptPixmap);
//	m_pInterruptIcon->setFixedSize(19, 19);
	m_pUgvIcon = new QLabel("", this);
	m_pUgvIcon->setPixmap(*m_pUgvPixmap);
    m_pUgvIcon->setFixedSize(10, 10);
    m_pUgvIcon->setScaledContents(true);
	m_pUavIcon = new QLabel("", this);
	m_pUavIcon->setPixmap(*m_pUavPixmap);
    m_pUavIcon->setFixedSize(10, 10);
    m_pUavIcon->setScaledContents(true);
    QGridLayout *tLayoutIcon = new QGridLayout;
    tLayoutIcon->addWidget(m_pUgvIcon, 0, 0);
    tLayoutIcon->addWidget(m_pUavIcon, 0, 0);
//    m_pPausePlay = new QPushButton("", this);
//    m_pPausePlay->setIcon(QIcon(*m_pPausePixmap));
//    m_pPausePlay->setMinimumWidth(60);
//    m_pPausePlay->setFixedSize(m_pPausePixmap->height()+2, m_pPausePixmap->width()+2);
//    if (ttask)
//        m_pPausePlay->setEnabled(true);
//    else
//        m_pPausePlay->setEnabled(false);



	//setLayout(m_pMaxLayout);

    m_pLine1Layout = new QHBoxLayout;
    m_pLine1Layout->addLayout(tLayoutIcon, 0);
    if (ttask->actorId < 102)
    {
        m_pUavIcon->hide();
    }
    else
    {
        m_pUgvIcon->hide();
    }
    m_pLine1Layout->addWidget(m_pNameLabel, 6);
    m_pLine1Layout->addWidget(m_pLeaderLabel, 6);
    m_pLine1Layout->setSpacing(8);


    /*m_pLine1Layout->setColumnStretch(0, 0);
    m_pLine1Layout->setColumnStretch(1, 3);
    m_pLine1Layout->setColumnStretch(2, 3);*/
	//m_pLine1Layout->addWidget(m_pRunningLabel, 0, 1, Qt::AlignRight);
	//m_pLine1Layout->addWidget(m_pRunningBar, 1, 1, Qt::AlignRight);
    //m_pLine1Layout->addLayout(tBar, 0, 1, Qt::AlignRight);
    //m_pLine1Layout->setColumnStretch(0,4);

	m_pLine2Layout = new QGridLayout;
	m_pLine2Layout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);
	m_pLine2Layout->addWidget(m_pPriorityLabel, 0, 0);	
    //m_pLine2Layout->addWidget(m_pInterruptIcon, 0, 1);
    //m_pLine2Layout->addWidget(m_pUavIcon, 0, 2);
    //m_pLine2Layout->addWidget(m_pUavCount, 0, 3);
    //m_pLine2Layout->addWidget(m_pUgvIcon, 0, 4);
    //m_pLine2Layout->addWidget(m_pUgvCount, 0, 5);
    //m_pLine2Layout->addWidget(m_pPausePlay, 0, 7);
//	m_pLine2Layout->setRowMinimumHeight(0, 44);
//	m_pLine2Layout->setColumnStretch(6, 4);
//	m_pLine2Layout->setColumnStretch(0, 1);
//	m_pLine2Layout->setColumnStretch(3, 1);
//	m_pLine2Layout->setColumnStretch(5, 1);
	m_pBottomLayout = new QHBoxLayout;
	m_pBottomLayout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);

	m_pLine1 = new QLabel;
	m_pLine1->setLayout(m_pLine1Layout);
	
	m_pLine2 = new QLabel;
	m_pLine2->setLayout(m_pLine2Layout);

	m_pMainLayout = new QVBoxLayout;
	m_pMainLayout->setContentsMargins(0, 0, 0, m_pBorderPixmap->height() + OUTER_CONTENTS_MARGIN);
	m_pMainLayout->setSpacing(0);
	m_pMainLayout->addWidget(m_pLine1);
	m_pMainLayout->addWidget(m_pLine2);
	m_pMainLayout->addLayout(m_pBottomLayout);
	setLayout(m_pMainLayout);
	m_pLine1->show();
	m_pLine2->hide();

	ChangeStatus(Queued);
	ChangeMode(Mode1);
//	connect(m_pPausePlay, SIGNAL(clicked()), this, SLOT(togglePausePlay()));
}

ByTaskPanel::~ByTaskPanel(){

	m_ByTaskInstanceCount--;
	if(m_ByTaskInstanceCount <= 0){
		m_ByTaskInstanceCount = 0;
		ByTaskShutdown();
	}
}

void ByTaskPanel::ChangeMode(PanelMode mode, bool resort){

	assert(mode >= Mode1 && mode <= MAX_MODE);

	m_Mode = mode;
	setUpdatesEnabled(false);

	//m_pLeaderLabel->hide();

	if(m_Mode == Mode1){
		m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, m_pSmallLowerCornerPixmap->width(), 0);
		m_pLine2->hide();
		this->setMinimumHeight(30);

	}
	else{
		m_pLine1Layout->setContentsMargins(m_pUpperCornerPixmap->width(), 0, OUTER_CONTENTS_MARGIN, 0);
		m_pLine2->show();
		this->setMinimumHeight(65);
	}

	//if(m_Mode != Mode1){
	//	setLayout(m_pMaxLayout);
	//}

	PositionPlusMinus();
	if(parent()) ((QWidget*)parent())->adjustSize();
	if(resort) Q_EMIT(ResortRequested());
	setUpdatesEnabled(true);
}

void ByTaskPanel::DecreaseMode(){

	long requested = m_Mode - 1;
	PanelMode mode = (requested < Mode1) ? Mode1 : (PanelMode)requested;
	ChangeMode(mode);
}

void ByTaskPanel::IncreaseMode(){

	long requested = m_Mode + 1;
	PanelMode mode = (requested > MAX_MODE) ? MAX_MODE : (PanelMode)requested;
	ChangeMode(mode);
}

void ByTaskPanel::ChangeName(QString name, bool resort){

	m_pNameLabel->setText(name);
	if(resort) Q_EMIT(ResortRequested());
}

void ByTaskPanel::ChangeLeader(QString leader, bool resort){

	m_pLeaderLabel->setText(leader);
	if(resort) Q_EMIT(ResortRequested());
}

bool ByTaskPanel::PlusPresent(PanelMode mode){

	if(mode != MAX_MODE) return(true);
	else return(false);
}

bool ByTaskPanel::MinusPresent(PanelMode mode){

	if(mode != Mode1) return(true);
	else return(false);
}

void ByTaskPanel::ByTaskInit() {}

void ByTaskPanel::ByTaskShutdown() {}

int ByTaskPanel::m_ByTaskInstanceCount = 0;

//void ByTaskPanel::togglePausePlay()
//{
//	if(m_Paused)
//	{
//		m_pPausePlay->setIcon(QIcon(*m_pPlayPixmap));
//		Q_EMIT(taskPlay(m_TaskId));
//	}
//	else
//	{
//		m_pPausePlay->setIcon(QIcon(*m_pPausePixmap));
//		Q_EMIT(taskPause(m_TaskId));
//	}
//}
