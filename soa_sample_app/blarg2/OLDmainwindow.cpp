#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString title, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->m_pPlainTextEdit->ensureCursorVisible();
    setWindowTitle(title);

    QString file = "/home/musadhaque/Downloads/soa_sample_app/build/test";
    QStringList args;

    args.append("-1");
    args.append("soa-testroom-blue");
    ui->m_pPlainTextEdit->insertPlainText(file);
    m_pConsole = new Console(file, args, this);
    connect(m_pConsole, SIGNAL(newData(QString)), ui->m_pPlainTextEdit, SLOT(insertPlainText(QString)));
    m_pConsole->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

