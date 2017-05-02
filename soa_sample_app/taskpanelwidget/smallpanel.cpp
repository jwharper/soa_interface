#include "smallpanel.h"
#include <QGridLayout>
#include <QDebug>


EABSmallPanel::EABSmallPanel(QWidget * parent) : QLabel(parent)
{
    m_pParent = parent;
    QGridLayout * pGrid = new QGridLayout;

    column0 = 88;
    column1 = 100;
    column2 = column0;
    column3 = column1;
    column4 = column0;
    column5 = column1;
    column6 = column0;
    column7 = column1;
    column8 = column0;
    //searchForWidth = 216;
    decontaminationTypeWidth = 216;
    viewAnglesWidth = 168;
    hazardTypesWidth = 216;
    detectionModeWidth = 324;
    samplingWidth = 324;
    entityWidth = 180;
    createGoToX();


    pGrid->addWidget(m_pGoToX, 0, 0);
    m_pGoToX->hide();


    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::Box);

    this->setLayout(pGrid);
    m_pActiveLabel = m_pGoToX;
    m_pActiveLabel->show();
}


void EABSmallPanel::taskAreaButton()
{
    qDebug()<<"taskAreaButton()";
    Q_EMIT taskAreaToPanel();
}


void EABSmallPanel::setLabel(QString task)
{
    if (task =="Go To X")
    {
        m_pActiveLabel->hide();
        m_pActiveLabel = m_pGoToX;
        m_pActiveLabel->show();
    }
    else
    {
        qDebug("bad task small panel request\n");
    }
}


void EABSmallPanel::createGoToX()
{
    m_pGoToX = new QLabel;

    QGridLayout * pGrid = new QGridLayout;
    for (int i = 0; i < 5; i++){
        pGrid->setRowMinimumHeight(i, 30);
    }

    pGrid->setColumnMinimumWidth(0, column0);
    pGrid->setColumnMinimumWidth(1, column1);
    pGrid->setColumnMinimumWidth(2, column2);
    pGrid->setColumnMinimumWidth(3, column3);
    pGrid->setColumnMinimumWidth(4, entityWidth);
    pGrid->setColumnMinimumWidth(5, 1141-(column0 + column1 + column2 + column3 + entityWidth));

    QComboBox * pComboBox;
    QLabel * pLabel;
    QTimeEdit * pTimeEdit;
    QLineEdit * pLineEdit;
    QPushButton * pPushButton;

    // Row 0
    pLabel = new QLabel("Target:", this);
    pGrid->addWidget(pLabel, 0, 0);
    pLineEdit = new QLineEdit(this);
    connect(this, SIGNAL(resetAll()), pLineEdit, SLOT(clear()));
    connect(pLineEdit, SIGNAL(textChanged(QString)), this, SLOT(newTaskArea(QString)));
    connect(this, SIGNAL(syncTaskArea(QString)), pLineEdit, SLOT(setText(QString)));
    m_pGoToTarget = pLineEdit;
    pGrid->addWidget(pLineEdit, 0, 1, 1, 2);
    pPushButton = new QPushButton("Select");
    connect(pPushButton, SIGNAL(pressed()), this, SLOT(taskAreaButton()));
    pGrid->addWidget(pPushButton, 0, 3);

    //Row 1
    pLabel = new QLabel("Target Id:");
    pGrid->addWidget(pLabel, 1, 0);
    pComboBox = new QComboBox(this);
    connect(this, SIGNAL(resetAll(int)), pComboBox, SLOT(setCurrentIndex(int)));
    pComboBox->addItem("-------");
    pComboBox->addItem("8675309");
    pComboBox->addItem("6682511");
    pComboBox->addItem("3521512");
    m_pGoToTargetId = pComboBox;
    pGrid->addWidget(pComboBox, 1, 1);
    pLabel = new QLabel("Target Type:");
    pGrid->addWidget(pLabel, 1, 2);
    pComboBox = new QComboBox(this);
    connect(this, SIGNAL(resetAll(int)), pComboBox, SLOT(setCurrentIndex(int)));
    pComboBox->addItem("Select");//
    pComboBox->addItem("Stripes");
    pComboBox->addItem("Polka Dots");
    pComboBox->addItem("Plaid");
    pComboBox->addItem("Argyle");
    pGrid->addWidget(pComboBox, 1, 3);
    m_pGoToTargetType = pComboBox;

    //Row 2
    pLabel = new QLabel("Duration:");
    pGrid->addWidget(pLabel, 2, 0);
    pTimeEdit = new QTimeEdit(this);
    connect(this, SIGNAL(resetAll(QTime)), pTimeEdit, SLOT(setTime(QTime)));
    pGrid->addWidget(pTimeEdit, 2, 1);
    m_pGoToDuration = pTimeEdit;

    //Group boxes
    EntityBox * pEntityBox;
    pEntityBox = new EntityBox(this);
    connect(this, SIGNAL(resetAll()), pEntityBox, SLOT(resetMe()));
    pGrid->addWidget(pEntityBox, 0, 4, 5, 1);
    m_pGoToEntityBox = pEntityBox;

    m_pGoToX->setLayout(pGrid);
    m_pGoToX->hide();
}


void EABSmallPanel::callReset()
{
    Q_EMIT(resetAll());
    Q_EMIT(resetAll(false));
    Q_EMIT(resetAll(0));
    Q_EMIT(resetAll(QTime(0,0,0,0)));
}

void EABSmallPanel::newTaskArea(QString area)
{
    Q_EMIT(syncTaskArea(area));
}
