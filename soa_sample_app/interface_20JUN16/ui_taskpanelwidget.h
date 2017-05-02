/********************************************************************************
** Form generated from reading UI file 'taskpanelwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKPANELWIDGET_H
#define UI_TASKPANELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskPanelWidget
{
public:
    QPushButton *m_pCommitButton;
    QPushButton *m_pResetButton;
    QGroupBox *m_pDurationSmallBox;
    QLabel *labelDuration;
    QLabel *labelDuration_6;
    QSpinBox *m_pDDSelect;
    QLabel *labelDuration_7;
    QSpinBox *m_pDSSelect;
    QSpinBox *m_pDMSelect;
    QLabel *labelDuration_4;
    QSpinBox *m_pDHSelect;
    QLabel *labelDuration_8;
    QPushButton *m_pCancelButton;
    QComboBox *m_pTaskSelect;
    QLabel *labelTask;
    QLabel *labelPriority;
    QLabel *labelRisk;
    QComboBox *m_pPrioritySelect;
    QComboBox *m_pRiskSelect;
    QLabel *labelAssocTask;
    QComboBox *m_pAssocTaskSelect;
    QLabel *labelTask_2;
    QLabel *labelTask_3;
    QSlider *m_pSSlider;
    QSlider *m_pHSlider;
    QLabel *m_pSNumLabel;
    QLabel *m_pHNumLabel;
    QLabel *m_pSLabel_2;
    QLabel *m_pSLabel_3;
    QLabel *m_pSNumLabel_2;
    QLabel *m_pSNumLabel_3;

    void setupUi(QWidget *TaskPanelWidget)
    {
        if (TaskPanelWidget->objectName().isEmpty())
            TaskPanelWidget->setObjectName(QStringLiteral("TaskPanelWidget"));
        TaskPanelWidget->resize(1330, 150);
        TaskPanelWidget->setMinimumSize(QSize(1000, 150));
        TaskPanelWidget->setMaximumSize(QSize(16777215, 250));
        m_pCommitButton = new QPushButton(TaskPanelWidget);
        m_pCommitButton->setObjectName(QStringLiteral("m_pCommitButton"));
        m_pCommitButton->setGeometry(QRect(980, 120, 99, 27));
        m_pResetButton = new QPushButton(TaskPanelWidget);
        m_pResetButton->setObjectName(QStringLiteral("m_pResetButton"));
        m_pResetButton->setGeometry(QRect(870, 120, 99, 27));
        m_pDurationSmallBox = new QGroupBox(TaskPanelWidget);
        m_pDurationSmallBox->setObjectName(QStringLiteral("m_pDurationSmallBox"));
        m_pDurationSmallBox->setGeometry(QRect(760, 0, 281, 71));
        m_pDurationSmallBox->setFlat(false);
        labelDuration = new QLabel(m_pDurationSmallBox);
        labelDuration->setObjectName(QStringLiteral("labelDuration"));
        labelDuration->setGeometry(QRect(0, -10, 71, 41));
        labelDuration_6 = new QLabel(m_pDurationSmallBox);
        labelDuration_6->setObjectName(QStringLiteral("labelDuration_6"));
        labelDuration_6->setGeometry(QRect(90, 30, 31, 21));
        m_pDDSelect = new QSpinBox(m_pDurationSmallBox);
        m_pDDSelect->setObjectName(QStringLiteral("m_pDDSelect"));
        m_pDDSelect->setGeometry(QRect(80, 0, 48, 27));
        labelDuration_7 = new QLabel(m_pDurationSmallBox);
        labelDuration_7->setObjectName(QStringLiteral("labelDuration_7"));
        labelDuration_7->setGeometry(QRect(140, 30, 31, 21));
        m_pDSSelect = new QSpinBox(m_pDurationSmallBox);
        m_pDSSelect->setObjectName(QStringLiteral("m_pDSSelect"));
        m_pDSSelect->setGeometry(QRect(230, 0, 48, 27));
        m_pDMSelect = new QSpinBox(m_pDurationSmallBox);
        m_pDMSelect->setObjectName(QStringLiteral("m_pDMSelect"));
        m_pDMSelect->setGeometry(QRect(180, 0, 48, 27));
        labelDuration_4 = new QLabel(m_pDurationSmallBox);
        labelDuration_4->setObjectName(QStringLiteral("labelDuration_4"));
        labelDuration_4->setGeometry(QRect(190, 30, 31, 21));
        m_pDHSelect = new QSpinBox(m_pDurationSmallBox);
        m_pDHSelect->setObjectName(QStringLiteral("m_pDHSelect"));
        m_pDHSelect->setGeometry(QRect(130, 0, 48, 27));
        labelDuration_8 = new QLabel(m_pDurationSmallBox);
        labelDuration_8->setObjectName(QStringLiteral("labelDuration_8"));
        labelDuration_8->setGeometry(QRect(240, 30, 31, 21));
        m_pCancelButton = new QPushButton(TaskPanelWidget);
        m_pCancelButton->setObjectName(QStringLiteral("m_pCancelButton"));
        m_pCancelButton->setGeometry(QRect(760, 120, 99, 27));
        m_pTaskSelect = new QComboBox(TaskPanelWidget);
        m_pTaskSelect->setObjectName(QStringLiteral("m_pTaskSelect"));
        m_pTaskSelect->setGeometry(QRect(110, 0, 221, 27));
        m_pTaskSelect->setAcceptDrops(true);
        labelTask = new QLabel(TaskPanelWidget);
        labelTask->setObjectName(QStringLiteral("labelTask"));
        labelTask->setGeometry(QRect(30, -10, 81, 41));
        labelPriority = new QLabel(TaskPanelWidget);
        labelPriority->setObjectName(QStringLiteral("labelPriority"));
        labelPriority->setGeometry(QRect(30, 20, 81, 41));
        labelRisk = new QLabel(TaskPanelWidget);
        labelRisk->setObjectName(QStringLiteral("labelRisk"));
        labelRisk->setGeometry(QRect(30, 50, 81, 41));
        m_pPrioritySelect = new QComboBox(TaskPanelWidget);
        m_pPrioritySelect->setObjectName(QStringLiteral("m_pPrioritySelect"));
        m_pPrioritySelect->setGeometry(QRect(110, 30, 221, 27));
        m_pPrioritySelect->setAcceptDrops(true);
        m_pRiskSelect = new QComboBox(TaskPanelWidget);
        m_pRiskSelect->setObjectName(QStringLiteral("m_pRiskSelect"));
        m_pRiskSelect->setGeometry(QRect(110, 60, 221, 27));
        m_pRiskSelect->setAcceptDrops(true);
        labelAssocTask = new QLabel(TaskPanelWidget);
        labelAssocTask->setObjectName(QStringLiteral("labelAssocTask"));
        labelAssocTask->setGeometry(QRect(760, 50, 121, 41));
        m_pAssocTaskSelect = new QComboBox(TaskPanelWidget);
        m_pAssocTaskSelect->setObjectName(QStringLiteral("m_pAssocTaskSelect"));
        m_pAssocTaskSelect->setGeometry(QRect(880, 60, 181, 27));
        m_pAssocTaskSelect->setAcceptDrops(true);
        labelTask_2 = new QLabel(TaskPanelWidget);
        labelTask_2->setObjectName(QStringLiteral("labelTask_2"));
        labelTask_2->setGeometry(QRect(430, -10, 81, 41));
        labelTask_3 = new QLabel(TaskPanelWidget);
        labelTask_3->setObjectName(QStringLiteral("labelTask_3"));
        labelTask_3->setGeometry(QRect(430, 50, 81, 41));
        m_pSSlider = new QSlider(TaskPanelWidget);
        m_pSSlider->setObjectName(QStringLiteral("m_pSSlider"));
        m_pSSlider->setGeometry(QRect(510, 0, 160, 29));
        m_pSSlider->setMaximum(9);
        m_pSSlider->setOrientation(Qt::Horizontal);
        m_pSSlider->setTickPosition(QSlider::TicksBothSides);
        m_pHSlider = new QSlider(TaskPanelWidget);
        m_pHSlider->setObjectName(QStringLiteral("m_pHSlider"));
        m_pHSlider->setGeometry(QRect(510, 60, 160, 29));
        m_pHSlider->setMaximum(3);
        m_pHSlider->setOrientation(Qt::Horizontal);
        m_pHSlider->setTickPosition(QSlider::TicksBothSides);
        m_pSNumLabel = new QLabel(TaskPanelWidget);
        m_pSNumLabel->setObjectName(QStringLiteral("m_pSNumLabel"));
        m_pSNumLabel->setGeometry(QRect(550, 20, 31, 41));
        m_pHNumLabel = new QLabel(TaskPanelWidget);
        m_pHNumLabel->setObjectName(QStringLiteral("m_pHNumLabel"));
        m_pHNumLabel->setGeometry(QRect(550, 80, 31, 41));
        m_pSLabel_2 = new QLabel(TaskPanelWidget);
        m_pSLabel_2->setObjectName(QStringLiteral("m_pSLabel_2"));
        m_pSLabel_2->setGeometry(QRect(570, 20, 61, 41));
        m_pSLabel_3 = new QLabel(TaskPanelWidget);
        m_pSLabel_3->setObjectName(QStringLiteral("m_pSLabel_3"));
        m_pSLabel_3->setGeometry(QRect(570, 80, 61, 41));
        m_pSNumLabel_2 = new QLabel(TaskPanelWidget);
        m_pSNumLabel_2->setObjectName(QStringLiteral("m_pSNumLabel_2"));
        m_pSNumLabel_2->setGeometry(QRect(670, -10, 31, 41));
        m_pSNumLabel_3 = new QLabel(TaskPanelWidget);
        m_pSNumLabel_3->setObjectName(QStringLiteral("m_pSNumLabel_3"));
        m_pSNumLabel_3->setGeometry(QRect(670, 50, 31, 41));

        retranslateUi(TaskPanelWidget);

        QMetaObject::connectSlotsByName(TaskPanelWidget);
    } // setupUi

    void retranslateUi(QWidget *TaskPanelWidget)
    {
        TaskPanelWidget->setWindowTitle(QApplication::translate("TaskPanelWidget", "TaskPanelWidget", 0));
        m_pCommitButton->setText(QApplication::translate("TaskPanelWidget", "Commit", 0));
        m_pResetButton->setText(QApplication::translate("TaskPanelWidget", "Reset", 0));
        m_pDurationSmallBox->setTitle(QString());
        labelDuration->setText(QApplication::translate("TaskPanelWidget", "Duration", 0));
        labelDuration_6->setText(QApplication::translate("TaskPanelWidget", "dd", 0));
        labelDuration_7->setText(QApplication::translate("TaskPanelWidget", "hh", 0));
        labelDuration_4->setText(QApplication::translate("TaskPanelWidget", "mm", 0));
        labelDuration_8->setText(QApplication::translate("TaskPanelWidget", "ss", 0));
        m_pCancelButton->setText(QApplication::translate("TaskPanelWidget", "Cancel", 0));
        labelTask->setText(QApplication::translate("TaskPanelWidget", "Task", 0));
        labelPriority->setText(QApplication::translate("TaskPanelWidget", "Priority", 0));
        labelRisk->setText(QApplication::translate("TaskPanelWidget", "Risk Level", 0));
        labelAssocTask->setText(QApplication::translate("TaskPanelWidget", "Associated Task", 0));
        labelTask_2->setText(QApplication::translate("TaskPanelWidget", "Small UAV", 0));
        labelTask_3->setText(QApplication::translate("TaskPanelWidget", "Heavy UAV", 0));
        m_pSNumLabel->setText(QApplication::translate("TaskPanelWidget", "00", 0));
        m_pHNumLabel->setText(QApplication::translate("TaskPanelWidget", "00", 0));
        m_pSLabel_2->setText(QApplication::translate("TaskPanelWidget", "selected", 0));
        m_pSLabel_3->setText(QApplication::translate("TaskPanelWidget", "selected", 0));
        m_pSNumLabel_2->setText(QApplication::translate("TaskPanelWidget", "12", 0));
        m_pSNumLabel_3->setText(QApplication::translate("TaskPanelWidget", "  3", 0));
    } // retranslateUi

};

namespace Ui {
    class TaskPanelWidget: public Ui_TaskPanelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKPANELWIDGET_H
