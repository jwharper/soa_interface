// taskpanelwidget.h
//
// Created by Musad Haque
// 2015


#ifndef TASKPANELWIDGET_H
#define TASKPANELWIDGET_H

#include <QWidget>
#include <QTime>
#include <QList>

struct taskInfo{
    float lat;
    float alt;
    float lng;
    QList <float> points;
    QString actor;
    QString task;
    QString summary;
    QString duration;
    int id;
    int actorId;
    float avoidRadius;
    int priority;
    int risk;
};


namespace Ui {
class TaskPanelWidget;
}

class TaskPanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskPanelWidget(QWidget *parent = 0);
    ~TaskPanelWidget();

    //Q_SIGNAL void taskSOA();
    Q_SIGNAL void replacedMapButton();
    Q_SIGNAL void sendTask(taskInfo * pTaskInfo);
    Q_SIGNAL void selectTaskArea(QString taskColor, QString taskShape);
    Q_SIGNAL void actAsMapButton();

    Q_SLOT void resetAll();

    //Buttons
    Q_SLOT void commit();
    Q_SLOT void reset();
    Q_SLOT void cancel();
    Q_SLOT void tieToSlider();

    int commitCounter = 0;

    //Q_SLOT void updateNumSmall();
    //Q_SLOT void updateNumHeavy();

    void initialize();

    //Task area selection
    Q_SLOT void enableTaskAreaSelection();
    Q_SLOT void updatePts(QString pts);
    void setConnections();
    Q_SLOT void createTask();

    //Receives location from the map
    Q_SLOT void mapCoordFromJS (QString locationJS);

    Q_SLOT void taskSelected();
    QList <float> m_PointList;
    Q_SLOT void enableCommitBtn();
    Q_SLOT void sliderMoved(int bots);


private:
    //ui->element is how to access to elements that are part of this panel
    Ui::TaskPanelWidget *ui;

    bool enoughRobots;
    bool enoughMapPoints;
};

#endif // TASKPANELWIDGET_H


