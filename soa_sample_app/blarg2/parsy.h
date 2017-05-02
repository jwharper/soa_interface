//
// parsy.h
//
// Created by Musad Haque and EAB, 2015
//

#ifndef PARSY_H
#define PARSY_H

#include <QFile>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QWidget>
#include <QProcess>

//Forward declaration - this exists - go find it - it can be found - just not here
struct actor;
struct site;

class Parsy : public QObject{
    Q_OBJECT

public:
    Parsy(QWidget * parent = 0);

    //Q_SIGNAL void newData(QString);
    //Q_SIGNAL void actorData(actor * pAct);
    //Q_SIGNAL void siteData(site * pSit); //!!!!!!!!!!!!!

    //Q_SLOT void parseIt(QString line);
    Q_SLOT void boo();
    Q_SLOT void booboo(QProcess::ProcessError x);

    //float hLatToGoogle(QString hex);
    //float hLngToGoogle(QString hex);

//protected:

};

#endif // PARSY_H
