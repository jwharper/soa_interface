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

ByTaskPanel::ByTaskPanel(soa::WorldDataManager* wdm, soa::task::TaskPtr task, QWidget * parent) : QSidePanel(parent), wdm(wdm)
{

	if(m_ByTaskInstanceCount == 0) ByTaskInit();
	m_ByTaskInstanceCount++;

	SidePanelInit();

    m_Division = "Blue";
    m_Paused = false;

	// Create labels
    m_pNameLabel = new QLabel(QString::fromStdString(soa::task::TaskType::name(task->getType())));
    m_pNameLabel->setFont(m_Font);
	m_pNameLabel->setFixedWidth(TASK_NAME_LENGTH * m_FontMetrics.width('W') + 2 * (m_pNameLabel->frameWidth() + 2));
	m_pNameLabel->setFixedHeight(m_FontMetrics.height());
    m_pNameLabel->setAlignment(Qt::AlignLeft);

    m_pLeaderLabel = new QLabel("", this);
	m_pLeaderLabel->setFont(m_Font);
	m_pLeaderLabel->setFixedWidth(LEADER_LENGTH * m_FontMetrics.width('W') + 2 * (m_pLeaderLabel->frameWidth() + 2));
	m_pLeaderLabel->setFixedHeight(m_FontMetrics.height());
    m_pLeaderLabel->setAlignment(Qt::AlignLeft);
    m_pLeaderLabel->setText(QString::fromStdString(""));

    m_pPriorityLabel = new QLabel(QString::number(task->getPriority()), this);
	m_pPriorityLabel->setFont(m_Font2);

    m_pUgvIcon = new QLabel("", this);
	m_pUgvIcon->setPixmap(*m_pUgvPixmap);
    m_pUgvIcon->setFixedSize(10, 10);
    m_pUgvIcon->setScaledContents(true);
	m_pUavIcon = new QLabel("", this);
	m_pUavIcon->setPixmap(*m_pUavPixmap);
    m_pUavIcon->setFixedSize(10, 10);
    m_pUavIcon->setScaledContents(true);
    QGridLayout *tLayoutIcon = new QGridLayout;

    m_pLine1Layout = new QHBoxLayout;
    m_pLine1Layout->addLayout(tLayoutIcon, 0);

    m_pUavIcon->show();
    m_pUgvIcon->show();

    m_pLine1Layout->addWidget(m_pUgvIcon);
    m_pLine1Layout->addWidget(m_pUavIcon);
    m_pLine1Layout->addWidget(m_pNameLabel, 6);
    m_pLine1Layout->addWidget(m_pLeaderLabel, 6);
    m_pLine1Layout->setSpacing(8);

	m_pLine2Layout = new QGridLayout;
	m_pLine2Layout->setContentsMargins(OUTER_CONTENTS_MARGIN, 0, m_pLowerCornerPixmap->width(), 0);
	m_pLine2Layout->addWidget(m_pPriorityLabel, 0, 0);	

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
    m_pLine2->show();

	ChangeStatus(Queued);
    ChangeMode(Mode1);
}

void ByTaskPanel::update(soa::task::TaskPtr task)
{
    std::cout << "Updating ByTaskPanel with new task info" <<  std::endl;
    auto reqs = task->getRequirements();
    bool addComma = false;
    QString text;
    bool isHeavy = false;
    bool isSmall = false;
    for (auto req : reqs)
    {
        if (addComma) {
            text += ", ";
        }
        addComma = true;
        int agentID = req.getAssignedAgent();

        auto actorBelief = wdm->getTypedBelief<soa::Belief_Actor>(soa::Belief::ACTOR, agentID);
        if (actorBelief.get() != NULL)
        {
            isHeavy |= actorBelief->getType() == soa::Belief_Actor::HEAVYLIFT;
            isSmall |= actorBelief->getType() == soa::Belief_Actor::SMALLUAV;
        }

        text += QString::fromStdString(std::to_string(agentID));
    }
    std::cout << "Is heavy? " << (isHeavy ? "Yes" : "No") << std::endl;
    std::cout << "Is small? " << (isSmall ? "Yes" : "No") << std::endl;
    m_pLeaderLabel->setText(text);
    m_pUgvIcon->setVisible(isHeavy);
    m_pUavIcon->setVisible(isSmall);
    m_pMainLayout->update();
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


