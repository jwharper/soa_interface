#ifndef SMALLPANEL_H
#define SMALLPANEL_H

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QSpinBox>
#include <QTime>
#include <QTimeEdit>
#include <QToolBar>
#include "entitybox.h"
//#include "EABSamplingBox.h"
//#include "EABDetectionModeBox.h"

struct taskInfo {
    QString destination;
    QString detail;
    QString forcefulness;
    QString pattern;
    QString target;
    QString targetType;
    QString taskType;
    QTime duration;
    double radius;
    int targetID;
    int human;
    int UAV;
    int UGV;
};








class EABSmallPanel : public QLabel
{
    Q_OBJECT

public:
    EABSmallPanel(QWidget * parent = 0);
    Q_SLOT void setLabel(QString task);
    Q_SLOT void taskAreaButton();
    Q_SIGNAL void taskAreaToPanel();
    Q_SIGNAL void resetAll();
    Q_SIGNAL void resetAll(bool tf);
    Q_SIGNAL void resetAll(int zero);
    Q_SIGNAL void resetAll(QTime time);
    Q_SLOT void callReset();
    Q_SLOT void newTaskArea(QString area);
    Q_SIGNAL void syncTaskArea(QString area);

    QLineEdit * m_pGoToTarget;
    QComboBox * m_pGoToTargetId;
    QComboBox * m_pGoToTargetType;
    QTimeEdit * m_pGoToDuration;
    EABEntityBox * m_pGoToEntityBox;



    //Functions to create task boxes

    void createGoToX();
    int column0;
    int column1;
    int column1and2;
    int column2;
    int column3;
    int column4;
    int column5;
    int column5and6;
    int column6;
    int column7;
    int column8;
    int searchForWidth;
    int decontaminationTypeWidth;
    int viewAnglesWidth;
    int hazardTypesWidth;
    int detectionModeWidth;
    int samplingWidth;
    int entityWidth;



 };


#endif // SMALLPANEL_H
