//
// mapwidget.cpp
//
// Created by EAB and Musad Haque
// 2016

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
}

QString MapWidget::OutgoingData(QString requestPlaceholder)
{
    Q_UNUSED(requestPlaceholder);
    return QString("Response to requestPlaceholder");
}


void MapWidget::Initialize(QString fileName)
{
    Q_UNUSED(fileName);

    //Create a new SimpleWebView and set it as the WebView
    if(m_pWebView == NULL)
    {
        m_pWebView = new WebView(m_HtmlFileName, this);
    }
    connect(this, SIGNAL(ShowWebInspectorRequest()), m_pWebView, SLOT(showWebInspector()));

    //*** *** ***
    //The following command opens the web inspector
    //when the page loads (debugging purposes):
    //
    //connect(m_pWebView, SIGNAL(loaded()), m_pWebView, SLOT(showWebInspector()));
    //
    //*** *** ***

    //LogicWindow's beliefTimer is tied to WebView being loaded
    connect(m_pWebView, SIGNAL(loaded()), m_pLogicWidget->m_pBeliefTimer, SLOT(start()));
}


/*
 * Send the actor information to JS using WebView
 * JS responds to the commands
 *      removeTask($taskID$); //to remove a task
 *      trigger(map, 'move_item', _%1.$a, new LatLng($l1, $l2)); // move existing icon
 *      destroy($a); //JS will put a cross over the icon
 *      add_robot($c1, $c2, affiliation.BLUE, robot_type.$t); // to add an icon
 *      window.$t_%1 = last_item;
 * Method below provides the $-prefixed entities to JS
 * Prepare in QString cmd
*/
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

            //Example of logging information to console:
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

        for (int i = 0; i < 3; i++)
        {
            actorHash.value(pActor->id)->coordinates[i] = pActor->coordinates[i];
        }
        actorHash.value(pActor->id)->sinceLast = pActor->timestamp - actorHash.value(pActor->id)->timestamp;
        actorHash.value(pActor->id)->timestamp = pActor->timestamp;

        cmd = "trigger(map, 'move_item', ";
        cmd.append(pActor->affiliation);
        cmd.append("_");
        cmd.append(QString("%1").arg(pActor->id));
        cmd.append(", new LatLng(");
        cmd.append(QString::number(pActor->coordinates[0]));
        cmd.append(", ");
        cmd.append(QString::number(pActor->coordinates[2]));
        cmd.append("), ");
        cmd.append(QString::number(pActor->sinceLast));
        cmd.append(");");

        //WebView
        m_pWebView->eval(cmd);

        if (pActor->status == "Destroyed" && actorHash.value(pActor->id)->status != "Destroyed")
        {
            cmd = "destroy(";
            cmd.append(QString::number(pActor->id));
            cmd.append(");");

            //WebView
            m_pWebView->eval(cmd);
        }
        delete pActor;
    }

    else
    {
        //actorHash doesn't contain this actor
        //Add it to the hash

        actorHash.insert(pActor->id, pActor); //adding actor, but to JS its adding a "robot"
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

        //WebView
        m_pWebView->eval(cmd);
    }

}


/*
 * Send the site information to JS using WebView
 * JS responds to the commands
 *      add_robot($c1, $c2, affiliation.BLUE, robot_type.$t); // to add an icon
 *      window.$t_%1 = last_item;
 * Method below provides the $-prefixed entities to JS
 * Prepare in QString cmd
*/
void MapWidget::updateSite(site * pSite)
{
    QString cmdSite;
    if (siteHash.contains(pSite->id))
    {;
        //delete pSite;
        //qDebug()<<"here";
    }
    else
    {
        siteHash.insert(pSite->id, pSite); //adding site, but to JS its adding a "robot"

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

        //WebView
        m_pWebView->eval(cmdSite);
    }
}


/*
 * Send taskInfo to JS using WebView
 * taskInfo received from logicWidget's commitTask()
 * SIGNAL-SLOT connection made in LogicWidget::setFileName()
 *
 * JS responds to the commands
 *      finishTask($tID, $a, $tn, $ts, $tn) //to send a task
 * Method below provides the $-prefixed entities to JS
 * Prepare in QString cmd
 *
*/
void MapWidget::sendCmdToJS(taskInfo* tInfo)
{
    tInfo->id = nextTaskId();

    taskHash.insert(tInfo->id, tInfo); //add taskInfo to a taskHash

    actorHash.value(tInfo->actorId)->taskId = tInfo->id;

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

    //Webview
    m_pWebView->eval(cmd);

    //Example of how to log information to console
    qDebug()<<"Operator asked*************";
    qDebug()<<cmd;
    qDebug()<<"*************";
}


