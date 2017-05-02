/********************************************************************************
** Form generated from reading UI file 'interfacewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEWINDOW_H
#define UI_INTERFACEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfaceWindow)
    {
        if (InterfaceWindow->objectName().isEmpty())
            InterfaceWindow->setObjectName(QStringLiteral("InterfaceWindow"));
        InterfaceWindow->resize(1034, 395);
        centralWidget = new QWidget(InterfaceWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        InterfaceWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfaceWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 25));
        InterfaceWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InterfaceWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InterfaceWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InterfaceWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InterfaceWindow->setStatusBar(statusBar);

        retranslateUi(InterfaceWindow);

        QMetaObject::connectSlotsByName(InterfaceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceWindow)
    {
        InterfaceWindow->setWindowTitle(QApplication::translate("InterfaceWindow", "InterfaceWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class InterfaceWindow: public Ui_InterfaceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEWINDOW_H
