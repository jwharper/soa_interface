/********************************************************************************
** Form generated from reading UI file 'bytaskpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BYTASKPANEL_H
#define UI_BYTASKPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ByTaskPanel
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QProgressBar *progressBar;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_9;

    void setupUi(QWidget *ByTaskPanel)
    {
        if (ByTaskPanel->objectName().isEmpty())
            ByTaskPanel->setObjectName(QStringLiteral("ByTaskPanel"));
        ByTaskPanel->resize(923, 610);
        verticalLayout = new QVBoxLayout(ByTaskPanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(ByTaskPanel);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 831, 52));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(40, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8("icon.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(400, 0));
        label->setMaximumSize(QSize(400, 16777215));
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        label->setIndent(0);

        horizontalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(240, 16777215));

        verticalLayout_2->addWidget(label_11);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMaximumSize(QSize(240, 30));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 70, 831, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(40, 40));
        QFont font;
        font.setPointSize(21);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_10);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(40, 40));
        label_6->setPixmap(QPixmap(QString::fromUtf8("icon2.png")));
        label_6->setScaledContents(true);

        horizontalLayout_2->addWidget(label_6);

        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(40, 40));
        label_5->setPixmap(QPixmap(QString::fromUtf8("icon3.jpeg")));
        label_5->setScaledContents(true);

        horizontalLayout_2->addWidget(label_5);

        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(40, 40));
        label_8->setPixmap(QPixmap(QString::fromUtf8("icon6.png")));
        label_8->setScaledContents(true);

        horizontalLayout_2->addWidget(label_8);

        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(40, 40));
        label_7->setIndent(8);

        horizontalLayout_2->addWidget(label_7);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(40, 40));
        label_4->setPixmap(QPixmap(QString::fromUtf8("icon5.png")));
        label_4->setScaledContents(true);

        horizontalLayout_2->addWidget(label_4);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(40, 40));
        label_3->setMaximumSize(QSize(40, 40));
        label_3->setIndent(6);

        horizontalLayout_2->addWidget(label_3);

        label_9 = new QLabel(horizontalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(16777215, 40));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_9->setIndent(15);

        horizontalLayout_2->addWidget(label_9);


        verticalLayout->addWidget(groupBox);


        retranslateUi(ByTaskPanel);

        QMetaObject::connectSlotsByName(ByTaskPanel);
    } // setupUi

    void retranslateUi(QWidget *ByTaskPanel)
    {
        ByTaskPanel->setWindowTitle(QApplication::translate("ByTaskPanel", "ByTaskPanel", 0));
        groupBox->setTitle(QApplication::translate("ByTaskPanel", "GroupBox", 0));
        label_2->setText(QString());
        label->setText(QApplication::translate("ByTaskPanel", "Task Name", 0));
        label_11->setText(QApplication::translate("ByTaskPanel", "TextLabel", 0));
        label_10->setText(QApplication::translate("ByTaskPanel", "6", 0));
        label_6->setText(QString());
        label_5->setText(QString());
        label_8->setText(QString());
        label_7->setText(QApplication::translate("ByTaskPanel", "2", 0));
        label_4->setText(QString());
        label_3->setText(QApplication::translate("ByTaskPanel", "0", 0));
        label_9->setText(QApplication::translate("ByTaskPanel", "Leader Name", 0));
    } // retranslateUi

};

namespace Ui {
    class ByTaskPanel: public Ui_ByTaskPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BYTASKPANEL_H
