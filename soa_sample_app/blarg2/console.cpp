// console.cpp
//
// Created by Musad Haque
// 2015

#include "console.h"
#include <QDebug>

//Console::Console(QString mfile, QStringList margs, QWidget * parent) :	QObject(parent) /!!!
Console::Console(QString mfile, QWidget * parent) :	QObject(parent)
{
    m_File = mfile;
    //m_Args = margs; /!!!
}

void Console::start()
{
    //qDebug()<<"Console::start()";
    //qDebug()<<m_File;
    //qDebug()<<m_Args;
    m_pProcess = new QProcess(this);
    connect(m_pProcess, SIGNAL(started()), this, SLOT(boo()));
    connect(m_pProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(booboo(QProcess::ProcessError)));
    //m_pProcess->start(m_File, m_Args);
    m_pProcess->start(m_File);
    connect(m_pProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readIt()));
}

void Console::boo()
{
    Q_EMIT(newData("Console::boo()")); //We're getting here
}

void Console::booboo(QProcess::ProcessError x)
{
    //qDebug()<<"Console::booboo()";
    QString xx = "error occurred ";
    xx.append(x);
    Q_EMIT(newData(xx));
}

void Console::readIt(){
    //qDebug()<<"Console::readIt()";
    QByteArray temp = m_pProcess->readLine(800); //Changed from 80 to 800
    QString tOutput(temp); //Converts QByteArray to QString
   // qDebug()<<"Data dump:";
    //qDebug()<<tOutput;
    Q_EMIT(newData(tOutput));
}
