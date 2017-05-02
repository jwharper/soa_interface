// console.h
//
// Created by Musad Haque
// 2015

#ifndef CONSOLE_H
#define CONSOLE_H

#include <QFile>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QWidget>
#include <QProcess>

class Console : public QObject{
    Q_OBJECT

public:
    //Console(QString mfile, QStringList margs, QWidget * parent = 0);
    Console(QString mfile, QWidget * parent = 0); //!!!
    Q_SLOT void readIt();
    Q_SLOT void boo();
    Q_SLOT void booboo(QProcess::ProcessError x);
    Q_SIGNAL void newData(QString output);
    void start();

//protected:
    QProcess * m_pProcess;
    QString m_File;
    //QStringList m_Args; //!!!

};

#endif // CONSOLE_H
