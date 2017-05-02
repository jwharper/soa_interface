#include "tabpanelwidget.h"
#include "ui_tabpanelwidget.h"

TabPanelWidget::TabPanelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPanelWidget)
{
    ui->setupUi(this);
    initialize();
}

TabPanelWidget::~TabPanelWidget()
{
    delete ui;
}


void TabPanelWidget::initialize()
{
    ui->m_pTestLabel->setVisible(false);

    //Connect sliders to textBrowsers
    connect(ui->m_pSliderSUAV, SIGNAL(valueChanged(int)), this, SLOT(summarize()));
    connect(ui->m_pSliderHUAV, SIGNAL(valueChanged(int)), this, SLOT(summarize()));
    connect(ui->m_pSliderBUAV, SIGNAL(valueChanged(int)), this, SLOT(summarize()));
    //connect(ui->m_pSliderSUAV, SIGNAL(sliderMoved(int)), ui->m_pTextEdit, SLOT(setText(QString::number(ui->m_pSliderHUAV->value()))));
}

void TabPanelWidget::summarize()
{
    ui->m_pTestLabel->setText(QString::number(ui->m_pSliderSUAV->value()));
    ui->m_pTestLabel->setVisible(true);

    QString messageSUAV;
    messageSUAV.append(QString::number(ui->m_pSliderSUAV->value()));
    ui->m_pSliderSelectedSUAV->setText(messageSUAV);
    ui->m_pSliderSelectedSUAV->setAlignment(Qt::AlignRight);

    QString messageHUAV;
    messageHUAV.append(QString::number(ui->m_pSliderHUAV->value()));
    ui->m_pSliderSelectedHUAV->setText(messageHUAV);
    ui->m_pSliderSelectedHUAV->setAlignment(Qt::AlignRight);

    QString messageBUAV;
    messageBUAV.append(QString::number(ui->m_pSliderBUAV->value()));
    ui->m_pSliderSelectedBUAV->setText(messageBUAV);
    ui->m_pSliderSelectedBUAV->setAlignment(Qt::AlignRight);
}
