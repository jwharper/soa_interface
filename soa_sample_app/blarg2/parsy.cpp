//
// parsy.cpp
//
// Created by Musad Haque and EAB, 2015
//

#include "parsy.h"
#include "../../home/haquema1/Downloads/soa_sample_app/blarg2/mapWidget/mapwidget.h"

Parsy::Parsy(QWidget * parent) :	QObject(parent)
{
    //qDebug()<<"Parsy!!!";
}

void Parsy::boo()
{
    //Q_EMIT(newData("Parsy::boo()"));
}

void Parsy::booboo(QProcess::ProcessError x)
{
    QString xx = "error occurred ";
    xx.append(x);
    //Q_EMIT(newData(xx));
}


//void Parsy::parseIt(QString line){

//    //Examples of line with site state:
//    //Base: id=0, coordinates(-3.0311, 0, -9.75001)
//    //NGO Site: id=1, coordinates(-21.2176, 0, -1.25001)

//    //An example of line with actor state:
//    //Actor: id=100, status=Alive, affiliation=Blue, type=Heavy UAV, coordinates=(0.481,0.5,-9.696), timestamp=1460043824146

////    int colon = line.indexOf(":"); //where is the ":"
////    QString agent = line.left(colon); //keep everything left of the ":"
////    line.remove(0, colon+2); //get rid of the ":  "
////    QStringList otherStuff = line.split(", "); //otherStuff = ["id=100" , "status=Alive" , "affiliation=Blue" , ...]

//    actor * tActor = new actor;
//    site * tSite = new site;

//    if (agent == "Actor")
//    {

//        otherStuff[0].remove("id=");  //otherStuff = ["100" , "status=Alive" , ...]
//        tActor->id = otherStuff[0].toInt();

//        otherStuff[1].remove("status=");
//        tActor->status = otherStuff[1];

//        otherStuff[2].remove("affiliation=");
//        tActor->affiliation = otherStuff[2];
//        tActor->affiliation = tActor->affiliation.toUpper();


//        otherStuff[3].remove("type=");
//        tActor->type = otherStuff[3];
//        if (tActor->type == "Heavy UAV")
//            tActor->type = "HUAV";
//        if (tActor->type == "Small UAV")
//            tActor->type = "SUAV";

//        otherStuff[4].remove("coordinates=(");
//        otherStuff[4].remove(")");
//        QStringList coordSim = otherStuff[4].split(","); //coordSim = ["0.481" , "0.5", "-9.696"]
//        tActor->coordinates[0] = hLatToGoogle(coordSim[2]);
//        tActor->coordinates[1] = coordSim[1].toFloat();
//        tActor->coordinates[2] = hLngToGoogle(coordSim[0]);
//        otherStuff[5].remove("timestamp=");
//        tActor->timestamp = otherStuff[5].toInt();

//        Q_EMIT(actorData(tActor)); //MOVED inside if statement
//    }
//    else if (agent == "Base" || agent == "NGO Site" || agent == "Village"){
//        //agent is either "Base" or "NGO Site" or "Village"
//        if (agent == "NGO Site")
//            agent = "NGO";
//        tSite->type = agent;

//        //otherStuff = ["id=0" , "coordinates(-3.0311, 0, -9.75001)"]
//        otherStuff[0].remove("id=");
//        tSite->id = otherStuff[0].toInt();

//        otherStuff[1].remove("coordinates=(");
//        otherStuff[1].remove(")");
//        QStringList coordSim = otherStuff[1].split(",");
//        tSite->coordinates[0] = hLatToGoogle(coordSim[2]);
//        tSite->coordinates[1] = coordSim[1].toFloat();
//        tSite->coordinates[2] = hLngToGoogle(coordSim[0]);


//        Q_EMIT(siteData(tSite));

//    }

//}


//float Parsy::hLatToGoogle(QString hex)
//{
//   // qDebug()<<"Lat from sim: ";
//   // qDebug()<<hex;
//    float lat = hex.toFloat();
//    lat = lat * 0.860157 / 16; //(0,0) to top is 16km
//    //lat = lat/670; //744
//    //lat = lat * 1;
//    lat = lat + 40.199487; //Move to Dugway, UT
//    //qDebug()<<"Lat google: ";
//    //qDebug()<<lat;
//    return lat;
//}

//float Parsy::hLngToGoogle(QString hex)
//{
//    //qDebug()<<"Lng from sim: ";
//    //qDebug()<<hex;
//    float lng = hex.toFloat();
//    lng = lng * 1.947409 / 28; //(0,0) to right is 28km
//    //lng = lng/1000; //1111
//    //lng = lng * 1;
//    lng = lng - 112.939870; //Move to Dugway, UT
//    //qDebug()<<"Lng google: ";
//    //qDebug()<<lng;
//    return lng;
//}
