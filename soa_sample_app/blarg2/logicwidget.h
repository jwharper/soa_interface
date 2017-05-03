// logicwidget.h
//
// Created by Musad Haque
// 2016

#ifndef LOGICWIDGET_H
#define LOGICWIDGET_H

// System Includes
#include <QWidget>
#include <QWebView>
#include <QObject>
#include <QTimer>
#include <vector>
#include "../include/SoaAutonomy.h"
#include "../include/Belief_Actor.h"
#include "../include/WorldDataManager.h"
#include "../taskpanelwidget/taskpanelwidget.h"


struct actor;
struct site;


//forward declarations
class WebView;
class MapWidget;
class QWebFrame;
class QDomElement;


class LogicWidget: public QWidget{
    Q_OBJECT
public:
    LogicWidget(/*bool createConsole = true, */QWidget * pParent = 0);
    WebView * m_pWebView;
    QWebFrame * getWebFrame();
    Q_SLOT void debug(QString str);
    Q_SLOT void enableTaskDraw(QString taskShape, QString taskColor);
    Q_SLOT void sendCoord(QString coords);
    Q_SLOT void getBeliefInfo();
    Q_SLOT void debuggingFunc();
    Q_SLOT void taskSOA(taskInfo* tInfo);
    Q_SLOT void tasksForVideo(taskInfo* tInfo);
    Q_SLOT void checkWaypointsProgress(taskInfo * tInfo);
    Q_SIGNAL void commitTask(taskInfo* tInfo);
    Q_SIGNAL void actuallySendCoord(QString coords);
    Q_SIGNAL void newData(QString);
    Q_SIGNAL void actorData(actor * pActor);
    Q_SIGNAL void siteData(site * pSite);
    Q_SIGNAL void removeWaypoints(int actorID);
    Q_SIGNAL void endTask(int id);
    void setFileName(QString configurationFilename);

//protected:
    MapWidget * m_pMapWidget;
    QString filename;
    soa::SoaAutonomy * m_pSoaAutonomy;
    soa::WorldDataManager * m_pWDM;
    QTimer * m_pBeliefTimer;
    QTimer * m_pDebuggingTimer;

    soa::GridMath* gm;

    float hLatToGoogle(float hex);
    float hLngToGoogle(float hex);

    float googleToHLat(float lat);
    float googleToHLng(float lng);

    QHash<int, int> velocityZeroHash; //Used to resolve icon flickering issue

};

#endif // LOGICWIDGET_H
