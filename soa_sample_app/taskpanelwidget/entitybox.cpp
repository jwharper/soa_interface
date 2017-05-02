#include "entitybox.h"



EntityBox::EntityBox(QWidget * parent) : QGroupBox("Entity", parent)
{
    QLabel * pLabel;
    QComboBox * pComboBox;
    //QGroupBox * pGroupBox;
    QGridLayout * pGridS = new QGridLayout;


    pLabel = new QLabel("UGV:", this);
    pGridS->addWidget(pLabel, 0, 0);
    pComboBox = new QComboBox(this);
    pComboBox->addItem("No");
    pComboBox->addItem("Yes");
    pGridS->addWidget(pComboBox, 0, 1);
    m_pUGVBox = pComboBox;

    pLabel = new QLabel("UAV:", this);
    pGridS->addWidget(pLabel, 1, 0);
    pComboBox = new QComboBox(this);
    pComboBox->addItem("No");
    pComboBox->addItem("Yes");
    pGridS->addWidget(pComboBox, 1, 1);
    m_pUAVBox = pComboBox;

    pLabel = new QLabel("Human:", this);
    pGridS->addWidget(pLabel, 2, 0);
    pComboBox = new QComboBox(this);
    pComboBox->addItem("No");
    pComboBox->addItem("Yes");
    pGridS->addWidget(pComboBox, 2, 1);
    m_pHumanBox = pComboBox;
    m_pHumanBox->setDisabled(true);

    this->setLayout(pGridS);
}

QString EntityBox::boxInfo2()
{
    QString retMe = "Entities: \n\tUGV: ";
    retMe += m_pUGVBox->currentText();
    retMe += "\n\tUAV: ";
    retMe += m_pUAVBox->currentText();
    retMe += "\n\tHuman: ";
    retMe += m_pHumanBox->currentText();
    retMe += "\n";

    return retMe;
}

void EntityBox::resetMe()
{
    m_pUGVBox->setCurrentIndex(0);
    m_pUAVBox->setCurrentIndex(0);
    m_pHumanBox->setCurrentIndex(0);
}

QStringList EntityBox::boxInfo()
{
    m_Entities.append(m_pUGVBox->currentText());
    m_Entities.append(m_pUAVBox->currentText());
    m_Entities.append(m_pHumanBox->currentText());

    return m_Entities;
}
