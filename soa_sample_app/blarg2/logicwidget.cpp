// logicwidget.cpp
//
// Created by Musad Haque
// 2016

// System Includes
#include <QToolBar>
#include <QLineEdit>
#include <QAction>
#include <QDebug>
#include <QStatusBar>
#include <QProgressBar>
#include <QLabel>
#include <QWebFrame>
#include <QFile>
#include <QTimer>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include "logicwidget.h"
#include <iostream>
#include <QTextStream>
#include <QUrl>
#include <QBoxLayout>
#include <vector>

// Application Includes
#include "mapWidget/webview.h"
#include "mapWidget/mapwidget.h"

#include "../include/WorldLocation.h"


LogicWidget::LogicWidget(QWidget * pParent) : QWidget(pParent)
{
    //qDebug()<<"LogicWidget::LogicWidget()";
}


void LogicWidget::setFileName(QString configurationFilename)
{
    //qDebug()<<"LogicWidget::setFileName()";


    //Call getBeliefIno using timer
    m_pBeliefTimer = new QTimer();
    connect(m_pBeliefTimer, SIGNAL(timeout()), this, SLOT(getBeliefInfo()));
    m_pBeliefTimer->setInterval(1000);


    m_pMapWidget = new MapWidget(configurationFilename, this);
    m_pWebView = m_pMapWidget->GetWebView();
    QVBoxLayout * nl = new QVBoxLayout(this);
    nl->addWidget(m_pWebView);
    m_pWebView->seeMe();


    connect(this, SIGNAL(siteData(site*)), m_pMapWidget, SLOT(updateSite(site*)));
    connect(this, SIGNAL(actorData(actor*)), m_pMapWidget, SLOT(updateActor(actor*)));
    connect(m_pWebView, SIGNAL(coordRecvFromJS(QString)), this, SLOT(sendCoord(QString)));
    connect(this, SIGNAL(commitTask(taskInfo*)), m_pMapWidget, SLOT(commitTask(taskInfo*)));
    connect(m_pMapWidget, SIGNAL(endTask(int)), this, SIGNAL(endTask(int)));

    //SoaAutonomy pointer and worldDataManager pointer using agent0
    m_pSoaAutonomy = new soa::SoaAutonomy(0, "localhost:11511");
    m_pWDM = m_pSoaAutonomy->getWorldDataManager();

}

void LogicWidget::debuggingFunc()
{
    m_pWebView->eval("log('debugging Function');");
    //m_pWebView->eval("add_robot(39.6753, -113.151, affiliation.BLUE, robot_type.Base); window.Base_0=last_item;");
}

void LogicWidget::debug(QString str)
{
    qDebug()<< str;
}


QWebFrame * LogicWidget::getWebFrame()
{
    return m_pWebView->getWebFrame();
}

void LogicWidget::enableTaskDraw(QString taskColor, QString taskShape)
{
    //qDebug()<<"LogicWidget::enableTaskDraw()";
    QString sendMe = "drawTask('";
    sendMe.append(taskColor);
    sendMe.append("', '");
    sendMe.append(taskShape);
    sendMe.append("');");
    m_pWebView->eval(sendMe);
}

void LogicWidget::sendCoord(QString coords)
{
    qDebug()<<coords;
    Q_EMIT actuallySendCoord(coords);
}


void LogicWidget::getBeliefInfo()
{
    //Create temporary actors and sites
    actor * tActor;
    site * tSite;

    //Base information
    gm = m_pWDM->getGridMath();
    float tempX, tempZ;

    std::map<int, soa_shared_ptr<soa::Belief>> baseMap = m_pWDM->getAllBeliefs(soa::Belief::BASE);
    std::map<int, soa_shared_ptr<soa::Belief> >::iterator baseIter;

    for(baseIter = baseMap.begin(); baseIter != baseMap.end(); baseIter++){
        tSite = new site;
        soa::Belief_Base* base = static_cast<soa::Belief_Base*>(baseIter->second.get());
        gm->gridToWorld(base->getCells()[0].getCol(), base->getCells()[0].getRow(), tempX, tempZ);

        //Print info to screen
        //qDebug() << "Base: id=" << base->getId() << ", position=(" << tempX << ",0," << tempZ << ")";
        //qDebug() << ", suppliesAvailable=" << base->getSupplies();
        //qDebug() << ", timestamp=" << base->getBeliefTime() << endl;

        //Store info in tSite
        tSite->id = base->getId();
        tSite->type = "Base";
        tSite->coordinates[0] = hLatToGoogle(tempZ);
        tSite->coordinates[2] = hLngToGoogle(tempX);

        //Emit tSite
        Q_EMIT(siteData(tSite));

    }//End for each base


    // Print out NGO information
    std::map<int, soa_shared_ptr<soa::Belief> > ngoMap = m_pWDM->getAllBeliefs(soa::Belief::NGOSITE);
    std::map<int, soa_shared_ptr<soa::Belief> >::iterator ngoIter;
    for(ngoIter = ngoMap.begin(); ngoIter != ngoMap.end(); ngoIter++){
        tSite = new site;
        soa::Belief_NGOSite* ngo = static_cast<soa::Belief_NGOSite*>(ngoIter->second.get());
        gm->gridToWorld(ngo->getCells()[0].getCol(), ngo->getCells()[0].getRow(), tempX, tempZ);

        //Print info to screen
        //qDebug() << "NGO Site: id=" << ngo->getId() << ", position=(" << tempX << ",0," << tempZ << ")";
        //qDebug() << ", suppliesRemaining=" << ngo->getSupplies() << ", casualtiesAvailable=" << ngo->getCasualties() <<
        //", civiliansTaken=" << ngo->getCivilians();
        //qDebug() << ", timestamp=" << ngo->getBeliefTime() << endl;

        //Store info in tSite
        tSite->id = ngo->getId();
        tSite->type = "NGO";
        tSite->coordinates[0] = hLatToGoogle(tempZ);
        tSite->coordinates[2] = hLngToGoogle(tempX);

        //Emit tSite
        Q_EMIT(siteData(tSite));

    }//End for each NGO


    // Print out village information
    std::map<int, soa_shared_ptr<soa::Belief> > villageMap = m_pWDM->getAllBeliefs(soa::Belief::VILLAGE);
    std::map<int, soa_shared_ptr<soa::Belief> >::iterator villageIter;
    for(villageIter = villageMap.begin(); villageIter != villageMap.end(); villageIter++){
        tSite = new site;
        soa::Belief_Village* village = static_cast<soa::Belief_Village*>(villageIter->second.get());
        gm->gridToWorld(village->getCells()[0].getCol(), village->getCells()[0].getRow(), tempX, tempZ);

        //Print info to screen
        //qDebug() << "Village: id=" << village->getId() << ", position=(" << tempX << ",0," << tempZ << ")";
        //qDebug() << ", suppliesRemaining=" << village->getSupplies() << ", casualtiesAvailable=" << village->getCasualties();
        //qDebug() << ", timestamp=" << village->getBeliefTime() << endl;

        //Store info in tSite
        tSite->id = village->getId();
        tSite->type = "Village";
        tSite->coordinates[0] = hLatToGoogle(tempZ);
        tSite->coordinates[2] = hLngToGoogle(tempX);

        //Emit tSite
        Q_EMIT(siteData(tSite));

    }//End for each village


     // Print out actor information
     std::map<int, soa_shared_ptr<soa::Belief> > actorMap = m_pWDM->getAllBeliefs(soa::Belief::ACTOR);
     std::map<int, soa_shared_ptr<soa::Belief> >::iterator actorIter;
     for(actorIter = actorMap.begin(); actorIter!= actorMap.end(); actorIter++){
         tActor = new actor;
         soa::Belief_Actor* actor = static_cast<soa::Belief_Actor*>(actorIter->second.get());
         // ID
         //qDebug() << "Actor: id=" << actor->getId();
         // Alive or not
        string aliveStatus;
        if(actor->getIsAlive()){
            aliveStatus = "Alive";
        }else{
            aliveStatus = "Destroyed";
        }
        //qDebug() << ", status=" << aliveStatus;
        // Affiliation
        string affiliation;
        switch(actor->getAffiliation()){
        case 0:
            affiliation = "Blue";
            break;
        case 1:
            affiliation = "Red";
            break;
        case 2:
            affiliation = "Neutral";
            break;
        case 3:
            affiliation = "Unclassified";
            break;
        default:
            affiliation = "Invalid";
            break;
        }
        //qDebug() << ", affiliation=" << affiliation;
        // Type of actor
        string actorType;
        switch(actor->getType()){
        case 0: // Base
            actorType = "Base";
            break;
        case 1: // Small UAV
            actorType = "Small UAV";
            break;
        case 2: // Heavy UAV
            actorType = "Heavy UAV";
            break;
        case 3: // Dismount
            actorType = "Dismount";
            break;
        case 4: // Truck
            actorType = "Truck";
            break;
        case 5: // Police
            actorType = "Police";
            break;
        case 6: // Balloon
            actorType = "Balloon";
            break;
        default:
            actorType = "Invalid";
            break;
        }
        //qDebug() << ", type=" << actorType;
        // Coordinates
        //qDebug() << ", position=(" << actor->getPos_x() << "," << actor->getPos_y() << ","
             //<< actor->getPos_z() << ")";
        //qDebug() << ", velocityValid=" << actor->getVelocity_x_valid() &&
             //actor->getVelocity_y_valid() && actor->getVelocity_z_valid();
        //qDebug() << ", velocity=(" << actor->getVelocity_x() << "," << actor->getVelocity_y() << ","
            // << actor->getVelocity_z() << ")";
        // Actor-specific information
        switch(actor->getType()){
        case 0: // Base
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            break;
        case 1: // Small UAV
            //qDebug() << ", fuelRemaining=" << actor->getFuelRemaining();
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            break;
        case 2: // Heavy UAV
            //qDebug() << ", fuelRemaining=" << actor->getFuelRemaining();
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            //qDebug() << "\t\ttotalStorage=" << actor->getNumStorageSlots() <<
//                ", availableStorage=" << actor->getNumFreeSlots() <<
//                ", casualtiesStored=" << actor->getNumCasualtiesStored() <<
//                ", suppliesStored=" << actor->getNumSuppliesStored() << endl;
            break;
        case 3: // Dismount
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            //qDebug() << "\t\t" << "isWeaponized=" << actor->getIsWeaponized() <<
                //", totalStorage=" << actor->getNumStorageSlots() <<
               // ", availableStorage=" << actor->getNumFreeSlots() <<
               // ", civiliansStored=" << actor->getNumCiviliansStored() << endl;
            break;
        case 4: // Truck
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            //qDebug() << "\t\t" << "isWeaponized=" << actor->getIsWeaponized() <<
//                ", hasJammer=" << actor->getHasJammer() <<
//                ", totalStorage=" << actor->getNumStorageSlots() <<
//                ", availableStorage=" << actor->getNumFreeSlots() <<
//                ", civiliansStored=" << actor->getNumCiviliansStored() <<endl;
            break;
        case 5: // Police
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            break;
        case 6: // Balloon
            //qDebug() << ", timestamp=" << actor->getBeliefTime() << endl;
            break;
        }

        tActor->id = actor->getId();
        tActor->status = QString::fromStdString(aliveStatus);
        tActor->affiliation = QString::fromStdString(affiliation);
        tActor->affiliation = tActor->affiliation.toUpper();
        tActor->type = QString::fromStdString(actorType);
        if (tActor->type == "Heavy UAV")
            tActor->type = "HUAV";
        if (tActor->type == "Small UAV")
            tActor->type = "SUAV";
        tActor->coordinates[0] = hLatToGoogle(actor->getPos_z());
        tActor->coordinates[2] = hLngToGoogle(actor->getPos_x());
        tActor->taskId = -1;

        //Emit tActor
        Q_EMIT(actorData(tActor));

     }//End for each actor
}


float LogicWidget::hLatToGoogle(float hex)
{
    float lat = hex;
    lat = lat * 0.860157 / 16; //(0,0) to top is 16km
    lat = lat + 40.199487; //Move to Dugway, UT
    return lat;
}


float LogicWidget::hLngToGoogle(float hex)
{
    float lng = hex;
    lng = lng * 1.947409 / 28; //(0,0) to right is 28km
    lng = lng - 112.939870; //Move to Dugway, UT
    return lng;
}


float LogicWidget::googleToHLat(float lat)
{
    float hex = lat;
    hex = hex - 40.199487;
    hex = hex * 16 / 0.860157;
    return hex;
}


float LogicWidget::googleToHLng(float lng)
{
    float hex = lng;
    hex = hex + 112.939870;
    hex = hex * 28 / 1.947409;
    return hex;
}


void LogicWidget::taskSOA(taskInfo *tInfo)
{
    if (tInfo->task == "MoveToLocation")
    {
        if (tInfo->points.size() > 2)
        {
            vector <soa::WorldLocation> tPoints;
            for (int i = 0; i < tInfo->points.size(); i += 2)
            {
                tPoints.push_back(soa::WorldLocation(googleToHLng(tInfo->points[i+1]), 0 ,googleToHLat(tInfo->points[i])));
            }
            m_pSoaAutonomy->sendWaypointPathCommand(tInfo->actorId, tPoints);
        }
        else
        m_pSoaAutonomy->sendWaypointCommand(tInfo->actorId, soa::WorldLocation(googleToHLng(tInfo->points[1]),
                                            0, googleToHLat(tInfo->points[0])));

    }
    else if (tInfo->task == "MaintainLocation")
    {
        m_pSoaAutonomy->sendMaintainLocationCommand(tInfo->actorId);
    }
    else if (tInfo->task == "ReturnToFOB")
    {
        m_pSoaAutonomy->sendReturnToFOBCommand(tInfo->actorId);
    }
    else if (tInfo->task == "Home")
    {
        m_pSoaAutonomy->sendReturnToFOBCommand(tInfo->actorId);
    }
    else if (tInfo->task == "Refuel")
    {
        m_pSoaAutonomy->sendRefuelCommand(tInfo->actorId);
    }
    else if (tInfo->task == "Avoid")
    {
        if (tInfo->points.size() > 2)
        {
            vector <soa::WorldLocation> tPointsAvoid;
            for (int i = 0; i < tInfo->points.size(); i += 2)
            {
                tPointsAvoid.push_back(soa::WorldLocation(googleToHLng(tInfo->points[i+1]), 0 ,googleToHLat(tInfo->points[i])));
            }
            m_pSoaAutonomy->addNoFlyZone(tPointsAvoid);
        }
        else
        m_pSoaAutonomy->addNoFlyZone(soa::WorldLocation(googleToHLng(tInfo->points[1]),
                                     0, googleToHLat(tInfo->points[0])), tInfo->avoidRadius);
    }
    else
    {;
        //do nothing
    }
    std::map<int, soa_shared_ptr<soa::Belief> > actorMap = m_pWDM->getAllBeliefs(soa::Belief::ACTOR);
    qDebug()<<"just stop here for a sec.";
}


void LogicWidget::checkWaypointsProgress(taskInfo *tInfo)
{
    //Only doing this for MoveToLocation
    if (tInfo->task == "MoveToLocation")
    {
        //Go through all the actors (NOT GREAT, FIX LATER)
        std::map<int, soa_shared_ptr<soa::Belief> > actorMap = m_pWDM->getAllBeliefs(soa::Belief::ACTOR);
        std::map<int, soa_shared_ptr<soa::Belief> >::iterator actorIter;
        for(actorIter = actorMap.begin(); actorIter!= actorMap.end(); actorIter++)
        {
            soa::Belief_Actor* actor = static_cast<soa::Belief_Actor*>(actorIter->second.get());
            //If velocity is 0
            if (actor->getVelocity_x() == 0 && actor->getVelocity_z() == 0)
            {
                //Actor with zero velocity is already in hash with first timestamp
                if (velocityZeroHash.contains(actor->getId()))
                {
                    if (actor->getBeliefTime() - velocityZeroHash.value(actor->getId() > 100))
                    {
                        Q_EMIT(removeWaypoints(actor->getId()));
                    }
                }
                //Populate the hash with actorID and first timestamp when velocity is 0
                else
                    velocityZeroHash.insert(actor->getId(), actor->getBeliefTime());
            }
        }
    }
}


void LogicWidget::tasksForVideo(taskInfo* tInfo)
{
    if (tInfo->id == 300)
    {
        Q_EMIT(commitTask(tInfo));
        //tInfo->actor = "Small UAV 103";
        //tInfo->actorId = 103;
        taskSOA(tInfo);
    }
    //01 Move to Location
    else if (tInfo->id == 301)
    {
        Q_EMIT(commitTask(tInfo));
        tInfo->actor = "Small UAV 103";
        tInfo->actorId = 103;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 104";
        tInfo->actorId = 104;
        taskSOA(tInfo);
    }
    //02 Move to Location
    else if (tInfo->id == 302)
    {
        Q_EMIT(commitTask(tInfo));
        tInfo->actor = "Small UAV 105";
        tInfo->actorId = 105;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 106";
        tInfo->actorId = 106;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 107";
        tInfo->actorId = 107;
        taskSOA(tInfo);
    }
    //03 Move to Location
    else if (tInfo->id == 303)
    {
        Q_EMIT(commitTask(tInfo));
        tInfo->actor = "Small UAV 108";
        tInfo->actorId = 108;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 109";
        tInfo->actorId = 109;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 110";
        tInfo->actorId = 110;
        taskSOA(tInfo);
    }
    //04 Maintain Location
    else if (tInfo->id == 304)
    {
        Q_EMIT(commitTask(tInfo));
        tInfo->actor = "Small UAV 108";
        tInfo->actorId = 108;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 109";
        tInfo->actorId = 109;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 110";
        tInfo->actorId = 110;
        taskSOA(tInfo);
    }
    //05 Move to Location
    else if (tInfo->id == 305)
    {
        Q_EMIT(commitTask(tInfo));
        tInfo->actor = "Heavy UAV 101";
        tInfo->actorId = 101;
        taskSOA(tInfo);
    }
    //07 Return to FOB
    else if (tInfo->id == 306)
    {
        Q_EMIT(commitTask(tInfo));
        tInfo->actor = "Small UAV 103";
        tInfo->actorId = 103;
        taskSOA(tInfo);
        tInfo->actor = "Small UAV 104";
        tInfo->actorId = 104;
        taskSOA(tInfo);
    }
}
