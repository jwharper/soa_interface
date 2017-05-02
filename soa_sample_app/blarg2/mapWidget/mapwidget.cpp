//
// mapwidget.cpp
//
// Created by EAB, HMT lab
//

#include "mapwidget.h"

// System includes
#include <cassert>
#include <cmath>
#include <iostream>
#include <QGesture>
#include <QGraphicsItem>
#include <QScrollBar>
#include <QtWidgets>
#include <QWheelEvent>

// Application includes
#include   "webview.h"


MapWidget::MapWidget(QString fileName, LogicWidget * parent)
    :	QWidget(parent), m_pWebView(NULL), m_pLogicWidget(parent), nextTId(300)
{
    Initialize(fileName);
}

QWebFrame * MapWidget::GetWebFrame()
{
    return m_pWebView->getWebFrame();
}

void MapWidget::CenterOn(QPointF latLng)
{
    qDebug()<< "Center on " << latLng.rx() << ", " << latLng.rx();
}


void MapWidget::IncomingData(QString placeholder)
{
    Q_UNUSED(placeholder);
    //qDebug()<< "From JS:\n\t";
    //qDebug()<< placeholder.toStdString().c_str();
}

QString MapWidget::OutgoingData(QString requestPlaceholder)
{
    Q_UNUSED(requestPlaceholder);
    //qDebug()<< requestPlaceholder.toStdString().c_str();
    return QString("Response to requestPlaceholder");
}

/******************************************************************************
Protected Functions
******************************************************************************/
void MapWidget::Initialize(QString fileName)
{
    Q_UNUSED(fileName);

    //m_pParsy = new Parsy(this);
    //m_pLogicWidget = new LogicWidget(this);

    //DONE: Create a new SimpleWebView and set it as the WebView
    if(m_pWebView == NULL)
    {
        m_pWebView = new WebView(m_HtmlFileName, this);
    }


    //Connect Parsy::actorData to updateActor
    //connect(m_pParsy, SIGNAL(actorData(actor*)), this, SLOT(updateActor(actor*)));
    //Connect Parsy::siteData to updateSite
    //connect(m_pParsy, SIGNAL(siteData(site*)), this, SLOT(updateSite(site*))); //!!!!!!!!!!!!!

    connect(this, SIGNAL(ShowWebInspectorRequest()), m_pWebView, SLOT(showWebInspector()));


    //This command automatically opens the web inspector when the page loads.
    //Only needed if it is necessary to debug in the complete interface.
    //connect(m_pWebView, SIGNAL(loaded()), m_pWebView, SLOT(showWebInspector()));
    connect(m_pWebView, SIGNAL(loaded()), m_pLogicWidget->m_pBeliefTimer, SLOT(start()));

}


void MapWidget::updateActor(actor * pActor)
{

    QString cmd;
    if (actorHash.contains(pActor->id))
    {
        if (actorHash.value(pActor->id)->taskId  > -1)
        {
            taskInfo * ttask = taskHash.value(actorHash.value(pActor->id)->taskId);
            float tlat = ttask->points[ttask->points.size()-2];
            float tlng = ttask->points[ttask->points.size()-1];
            qDebug()<< "Actor: (" << pActor->coordinates[0] << ", " << pActor->coordinates[2] << ")";
            qDebug()<< "Task:  (" << tlat << ", " << tlng << ")";
            if ((actorHash.value(pActor->id)->coordinates[0] == pActor->coordinates[0] &&
                 actorHash.value(pActor->id)->coordinates[2] == pActor->coordinates[2]) &&
                (abs(tlat - pActor->coordinates[0]) < 0.01 &&
                 abs(tlng - pActor->coordinates[2]) < 0.01))
            {
                //Need a better test for when task is done
                QString tcmd = "removeTask(";
                tcmd.append(QString::number(actorHash.value(pActor->id)->taskId));
                tcmd.append(");");
                qDebug()<<tcmd;
                m_pWebView->eval(tcmd);
                Q_EMIT(endTask(actorHash.value(pActor->id)->taskId));
                actorHash.value(pActor->id)->taskId = -1;
            }
        }
            //qDebug()<<actorHash.value(pActor->id)->coordinates[0];
            //qDebug()<<pActor->coordinates[0];
            //qDebug()<<actorHash.value(pActor->id)->coordinates[0] - pActor->coordinates[0];
            //float coord0 = actorHash.value(pActor->id)->coordinates[0] - pActor->coordinates[0];
            //float coord2 = actorHash.value(pActor->id)->coordinates[2] - pActor->coordinates[2];
            //float dif0 = 0.0001;
            //float dif2 = 0.0001;

            //Check to see if coordinates are new; if not, return.
            //if (coord0 < dif0 && coord2 < dif2) {
                //qDebug()<<pActor->id;
                //Do nothing
            //} else {
        for (int i = 0; i < 3; i++)
        {
            actorHash.value(pActor->id)->coordinates[i] = pActor->coordinates[i];
        }
        actorHash.value(pActor->id)->sinceLast = pActor->timestamp - actorHash.value(pActor->id)->timestamp;
        actorHash.value(pActor->id)->timestamp = pActor->timestamp;
        cmd = "trigger(map, 'move_item', ";
        cmd.append(pActor->affiliation);
        cmd.append("_");
        cmd.append(QString("%1").arg(pActor->id)); //cmd.append(QString("%1").arg(id));
        cmd.append(", new LatLng(");
        cmd.append(QString::number(pActor->coordinates[0]));
        cmd.append(", ");
        cmd.append(QString::number(pActor->coordinates[2]));
        cmd.append("), ");
        cmd.append(QString::number(pActor->sinceLast));
        cmd.append(");");
        m_pWebView->eval(cmd);
        if (pActor->status == "Destroyed" && actorHash.value(pActor->id)->status != "Destroyed")
        {
            cmd = "destroy(";
            cmd.append(QString::number(pActor->id));
            cmd.append(");");
            m_pWebView->eval(cmd);
        }
        delete pActor;
    }
        //}
    else
    {
         actorHash.insert(pActor->id, pActor);
         pActor->sinceLast = 0;
         cmd = "add_robot(" ;

         cmd.append(QString::number(pActor->coordinates[0]));
         cmd.append(", ");
         cmd.append(QString::number(pActor->coordinates[2]));

         cmd.append(", affiliation.");
         cmd.append(pActor->affiliation);
         cmd.append(", robot_type.");
         cmd.append(pActor->type);
         cmd.append(", ");
         cmd.append(QString::number(pActor->id));
         cmd.append("); window.");
         cmd.append(pActor->affiliation);
         cmd.append("_");
         cmd.append(QString("%1").arg(pActor->id));
         cmd.append(" = last_item;");
         m_pWebView->eval(cmd);
     }

}




void MapWidget::updateSite(site * pSite)
{
    //qDebug()<<"MapWidget::updateSite()";
    //qDebug()<<pSite->id;

    QString cmdSite;
    if (siteHash.contains(pSite->id))
        {;
            //delete pSite;
            //qDebug()<<"here";
        }
    else
        {
            siteHash.insert(pSite->id, pSite);
            cmdSite = "add_robot(" ;
            cmdSite.append(QString::number(pSite->coordinates[0]));
            cmdSite.append(", ");
            cmdSite.append(QString::number(pSite->coordinates[2]));
            cmdSite.append(", affiliation.BLUE, robot_type.");
            cmdSite.append(pSite->type);
            cmdSite.append("); window.");
            cmdSite.append(pSite->type);
            cmdSite.append("_");
            cmdSite.append(QString("%1").arg(pSite->id));
            cmdSite.append(" = last_item;");            
            //qDebug()<<"*";
            //qDebug()<<cmdSite;
            m_pWebView->eval(cmdSite);

        }
}


void MapWidget::commitTask(taskInfo* tInfo)
{
   tInfo->id = nextTaskId();
   taskHash.insert(tInfo->id, tInfo);
   actorHash.value(tInfo->actorId)->taskId = tInfo->id;
   //finishTask(tId, actor, taskName, summary, rtype)
   QString cmd = "finishTask(";
   cmd.append(QString::number(tInfo->id));
   cmd.append(", '");
   cmd.append(tInfo->actor);
   cmd.append("', '");
   cmd.append(tInfo->task);
   cmd.append("', '");
   cmd.append(tInfo->summary);
   cmd.append("', '");
   cmd.append(tInfo->task);
   cmd.append("');");
   m_pWebView->eval(cmd);
   qDebug()<<"You've asked*************************";
   qDebug()<<cmd;
   qDebug()<<"*************************";

}
