#include "bytaskpanel.h"
#include "ui_bytaskpanel.h"

ByTaskPanel::ByTaskPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ByTaskPanel)
{
    ui->setupUi(this);
}

ByTaskPanel::~ByTaskPanel()
{
    delete ui;
}
