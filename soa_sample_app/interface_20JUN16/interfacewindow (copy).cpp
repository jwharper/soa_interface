#include "interfacewindow.h"
#include "ui_interfacewindow.h"
#include <QGridLayout>
#include "borderlayout.h"
#include <QTabWidget>


InterfaceWindow::InterfaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfaceWindow)
{

    //Send arguments to console to run the .cpp that talks to simulator
    QString file = "../build/test";
    QStringList args;
    args.append("-1");
    args.append("soa-testroom-blue");
    m_pConsole = new Console(file, args, this);
    connect(m_pConsole, SIGNAL(newData(QString)), this, SLOT(debug(QString)));
    m_pConsole->start();

    ui->setupUi(this);

    //Window title
    this->setWindowTitle("SOA User Interface");
    //Window icon
    this->setWindowIcon(QIcon("maria2.png"));

    //Add a LogicWidget
    m_pLogicWidget = new LogicWidget;
    m_pLogicWidget->setFileName2(m_pConsole, "Scripts/RVA_derived.htm");
    m_pLogicWidget->setMinimumHeight(700);
    m_pLogicWidget->setMinimumWidth(1000);

    //Add a TaskPanelWidget
    m_pTaskPanelWidget = new TaskPanelWidget;
    m_pTaskPanelWidget->setMinimumHeight(300);
    m_pTaskPanelWidget->setMinimumWidth(1000);

    //Add a TabPanelWidget
    m_pTabPanelWidget = new TabPanelWidget;
    m_pTabPanelWidget->setMinimumHeight(1000);
    m_pTabPanelWidget->setMinimumWidth(300);

    //Add the three widgets to a grid layout
    //QGridLayout *layout = new QGridLayout;
    //layout->addWidget(m_pLogicWidget, 1, 1);
    //layout->addWidget(m_pTaskPanelWidget, 2, 1);
    //layout->addWidget(m_pTabPanelWidget, 1, 2);

    //Add the three widgets to a border layout
    BorderLayout *layout = new BorderLayout;
    layout->addWidget(m_pLogicWidget, BorderLayout::Center);
    layout->addWidget(m_pTabPanelWidget, BorderLayout::East);
    layout->addWidget(m_pTaskPanelWidget, BorderLayout::South);
    setLayout(layout);
    setMinimumHeight(1000);
    setMinimumWidth(1000);
    setWindowTitle(tr("Border Layout"));

    //ui->centralWidget->setLayout(layout);
    //ui->centralWidget->showMaximized();

    //Connect selectTaskArea to enableTaskDraw
    connect(m_pTaskPanelWidget, SIGNAL(selectTaskArea(QString, QString)), m_pLogicWidget, SLOT(enableTaskDraw(QString, QString)));

    //Connect coordinates recvd from JS to taskPanelWidget for processing
    connect(m_pLogicWidget, SIGNAL(actuallySendCoord(QString)), m_pTaskPanelWidget, SLOT(mapCoordFromJS(QString)));
}

InterfaceWindow::~InterfaceWindow()
{
    delete ui;
}

void InterfaceWindow::debug(QString msg){
    qDebug()<<msg;
}
