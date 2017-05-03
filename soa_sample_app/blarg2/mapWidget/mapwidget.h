//
// mapwidget.cpp
//
// Created by EAB and Musad Haque
// 2016

#ifndef __MapWidget__
#define __MapWidget__

// System includes
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QSet>
#include <QPolygon>
#include <QDebug>
#include <QHash>

#include "../logicwidget.h"
#include "../../taskpanelwidget/taskpanelwidget.h"


QT_BEGIN_NAMESPACE
class QGesture;
class QGestureEvent;
class QPanGesture;
class QPinchGesture;
class QSwipeGesture;
QT_END_NAMESPACE

// Forward Declarations
class WebView;
class QDomElement;
class QLabel;
class QLineEdit;
class QProgressBar;
class QWebFrame;


/*
 * Blue
 *      Small UAV
 *      Heavy UAV
 *      Police
 *      Blimp
 *
 * Red
 *      Dismount
 *      Truck
 *
 * Neutral
 *      Dismount
 *      Truck
 *
*/
struct actor
{
    int id;
    QString status;
    QString affiliation;
    QString type;
    float coordinates[3];
    long int timestamp;
    int sinceLast;
    int taskId;
};


//Base, NGO Site, Village (or Red Base)
struct site
{
    int id;
    QString type;
    float coordinates[3];
};



class MapWidget : public QWidget{
    Q_OBJECT

public:
    MapWidget(QString fileName, LogicWidget * pParent = NULL);
    QWebFrame * GetWebFrame();
    WebView * GetWebView() const {return(m_pWebView);}
    int ItemCount();
    QString QPoint2LatLng(QPointF pos);
    int Runs(){return 1;}
    int nextTaskId(){return nextTId++;}

    Q_SIGNAL void ManifestsReady();
    Q_SIGNAL void endTask(int id);
    Q_SIGNAL void ShowWebInspectorRequest();

public Q_SLOTS:

    void CenterOn(QPointF latLng);
    void IncomingData(QString placeholder);
    void sendCmdToJS(taskInfo* tInfo);


    void updateActor(actor * pActor);
    Q_SLOT void updateSite(site * pSite);


    QString OutgoingData(QString requestPlaceholder);
    void ZoomIn(){qDebug()<<"zoom in";}
    void ZoomOut(){qDebug()<<"zoom out";}
    void ZoomReset(){qDebug()<<"zoom reset";}


public:

    void Initialize(QString fileName);

    WebView * m_pWebView;
    QString m_HtmlFileName;

    LogicWidget * m_pLogicWidget;

    QHash<int, taskInfo*> taskHash;
    QHash<int, actor*> actorHash;
    QHash<int, site*> siteHash;

    int nextTId;
};


#endif // MAPWIDGET_H


