#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QPlainTextEdit>
#include "console.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString title, QWidget *parent = 0);
    ~MainWindow();

protected:
    Console * m_pConsole;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


