#include "blarg2window.h"
#include "ui_blarg2window.h"

Blarg2Window::Blarg2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Blarg2Window)
{
    ui->setupUi(this);
    m_pLogicWidget = ui->m_pLogicWidget;
    m_pLogicWidget->setFileName("Scripts/RVA_derived.htm");
}

Blarg2Window::~Blarg2Window()
{
    delete ui;
}
