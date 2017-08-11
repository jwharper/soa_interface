#include "taskpanelwidget.h"
#include "ui_taskpanelwidget.h"
#include <QDebug>


TaskPanelWidget::TaskPanelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskPanelWidget)
{
    //Required since a .ui is included
    ui->setupUi(this);

    //Initialize the task panel
    initialize();
}


TaskPanelWidget::~TaskPanelWidget(){
    delete ui;
}


void TaskPanelWidget::initialize(){

    enoughRobots = false;
    enoughMapPoints = false;

    //User cannot touch vehicle sliders at this point
    ui->m_pSSlider->setEnabled(false);
    ui->m_pHSlider->setEnabled(false);

    //Max and min small UAVs
    ui->m_pSSlider->setMinimum(0);
    ui->m_pSSlider->setMaximum(13);

    //Max and min heavy UAVs
    ui->m_pHSlider->setMinimum(0);
    ui->m_pHSlider->setMaximum(3);

    //Vehicles sliders signal that they have been moved
    connect(ui->m_pSSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderMoved(int)));
    connect(ui->m_pHSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderMoved(int)));

    //Add tasks and don't set any item
    ui->m_pTaskSelect->addItem("Move to Location");
    ui->m_pTaskSelect->addItem("Maintain Location");
    ui->m_pTaskSelect->addItem("Return to FOB");
    ui->m_pTaskSelect->addItem("Home");
    ui->m_pTaskSelect->addItem("Refuel");
    ui->m_pTaskSelect->addItem("Avoid");
    ui->m_pTaskSelect->setCurrentIndex(-1); //default is nothing being selected

    //Disable associated tasks
    ui->m_pAssocTaskSelect->setEnabled(false);
    ui->labelAssocTask->setEnabled(false);

    //Add priorities, don't set any item, and disable
    for (int i = 1; i < 11; i++)
    {
        ui->m_pPrioritySelect->addItem(QString::number(i));
    }
    ui->m_pPrioritySelect->setCurrentIndex(-1);
    ui->m_pPrioritySelect->setEnabled(false);

    //Add risks, don't set any item, and disable
    ui->m_pRiskSelect->addItem("Low");
    ui->m_pRiskSelect->addItem("Medium");
    ui->m_pRiskSelect->addItem("High");
    ui->m_pRiskSelect->setCurrentIndex(-1);
    ui->m_pRiskSelect->setEnabled(false);

    //Add duration, don't set any item, and disable
    ui->m_pDDSelect->setMaximum(31);
    ui->m_pDHSelect->setMaximum(24);
    ui->m_pDMSelect->setMaximum(60);
    ui->m_pDSSelect->setMaximum(60);
    ui->m_pDurationSmallBox->setVisible(false);

    //Disable push buttons
    ui->m_pCancelButton->setEnabled(false);
    ui->m_pResetButton->setEnabled(false);
    ui->m_pCommitButton->setEnabled(false);

    //Connect sliders to labels
    connect(ui->m_pSSlider, SIGNAL(valueChanged(int)), this, SLOT(tieToSlider()));
    connect(ui->m_pHSlider, SIGNAL(valueChanged(int)), this, SLOT(tieToSlider()));

    //Start listening for a task being selected
    connect(ui->m_pTaskSelect, SIGNAL(activated(int)), this, SLOT(taskSelected()));
    //Start listering for a map-based task being selected
    connect(this, SIGNAL(actAsMapButton()), this, SLOT(enableTaskAreaSelection()));

    //Tie these three buttons to cancel, commit, and reset
    connect(ui->m_pResetButton, SIGNAL(clicked(bool)), this, SLOT(cancel()));
    connect(ui->m_pCommitButton, SIGNAL(clicked(bool)), this, SLOT(commit()));
    connect(ui->m_pResetButton, SIGNAL(clicked(bool)), this, SLOT(reset()));
}


void TaskPanelWidget::tieToSlider()
{
    ui->m_pSNumLabel->setText(QString::number(ui->m_pSSlider->value()));
    ui->m_pHNumLabel->setText(QString::number(ui->m_pHSlider->value()));
}


void TaskPanelWidget::taskSelected(){

    //Enable risk and priority
    ui->m_pRiskSelect->setEnabled(true);
    ui->m_pPrioritySelect->setEnabled(true);

    /*
     * Task selections have default risk and priority settings
     * Control additional user settings are considered:
     *          Allow vehicle selection?
     *          Does it have a temporal component?
     *          Is map interaction necessary?
    */

    if (ui->m_pTaskSelect->currentText() == "Move to Location"){
        //Priority 7
        ui->m_pPrioritySelect->setCurrentIndex(6);
        //Risk medium
        ui->m_pRiskSelect->setCurrentIndex(1);
        //Duration disappers
        ui->m_pDurationSmallBox->setVisible(false);
        //A map-based task was selected, so emit signal
        Q_EMIT(actAsMapButton());
        //Enable vehicle selection
        ui->m_pSSlider->setEnabled(true);
        ui->m_pHSlider->setEnabled(true);
    }
    else if (ui->m_pTaskSelect->currentText() == "Maintain Location"){
        //Priority 7
        ui->m_pPrioritySelect->setCurrentIndex(6);
        //Risk medium
        ui->m_pRiskSelect->setCurrentIndex(1);
        //Duration appears
        ui->m_pDurationSmallBox->setVisible(true);
        ui->m_pDDSelect->setValue(00);
        ui->m_pDHSelect->setValue(00);
        ui->m_pDMSelect->setValue(10);
        ui->m_pDSSelect->setValue(00);
        //A check for commit button since no emit signal
        enoughMapPoints = true;
        //Enable vehicle selection
        ui->m_pSSlider->setEnabled(true);
        ui->m_pHSlider->setEnabled(true);
    }
    else if (ui->m_pTaskSelect->currentText() == "Return to FOB"){
        //Priority 7
        ui->m_pPrioritySelect->setCurrentIndex(8);
        //Risk low
        ui->m_pRiskSelect->setCurrentIndex(0);
        //Duration disappers
        ui->m_pDurationSmallBox->setVisible(false);
        //A check for commit button since no emit signal
        enoughMapPoints = true;
        //Enable vehicle selection
        ui->m_pSSlider->setEnabled(true);
        ui->m_pHSlider->setEnabled(true);
    }
    else if (ui->m_pTaskSelect->currentText() == "Home"){
        //Priority 7
        ui->m_pPrioritySelect->setCurrentIndex(8);
        //Risk low
        ui->m_pRiskSelect->setCurrentIndex(0);
        //Duration disappers
        ui->m_pDurationSmallBox->setVisible(false);
        //A check for commit button since no emit signal
        enoughMapPoints = true;
        //Enable vehicle selection
        ui->m_pSSlider->setEnabled(true);
        ui->m_pHSlider->setEnabled(true);
    }
    else if (ui->m_pTaskSelect->currentText() == "Refuel"){
        //Priority 7
        ui->m_pPrioritySelect->setCurrentIndex(8);
        //Risk low
        ui->m_pRiskSelect->setCurrentIndex(0);
        //Duration disappers
        ui->m_pDurationSmallBox->setVisible(false);
        //A check for commit button since no emit signal
        enoughMapPoints = true;
        //Enable vehicle selection
        ui->m_pSSlider->setEnabled(true);
        ui->m_pHSlider->setEnabled(true);
    }
    else if (ui->m_pTaskSelect->currentText() == "Avoid"){
        //Priority 7
        ui->m_pPrioritySelect->setCurrentIndex(9);
        //Risk medium
        ui->m_pRiskSelect->setCurrentIndex(1);
        //Duration disappers
        ui->m_pDurationSmallBox->setVisible(false);
        //A map-based task was selected, so emit signal
        Q_EMIT(actAsMapButton());
        //A check for commit button since no vehicles involved
        enoughRobots = true;
        //No vehicles involved
    }
    else
    {
        //Duration disappers
        ui->m_pDurationSmallBox->setVisible(false);
    }
    //Enable the three buttons
    ui->m_pCancelButton->setEnabled(true);
    ui->m_pResetButton->setEnabled(true);
    enableCommitBtn(); //Check enoughMapPoints and enoughRobots first
}


void TaskPanelWidget::enableCommitBtn()
{
    if (enoughRobots && enoughMapPoints)
        ui->m_pCommitButton->setEnabled((true));
    else
        ui->m_pCommitButton->setEnabled((false));

}


void TaskPanelWidget::enableTaskAreaSelection(){

    //A map-based task has been selected
    qDebug()<<"Turn on the Javascript task selection";

    //Default color and shape of task on map
    QString taskColor = "#FFFFFF";
    QString taskShape = "polygon";

    if (ui->m_pTaskSelect->currentText() == "Move to Location"){
        taskShape = "polyline";
    }
    else if (ui->m_pTaskSelect->currentText() == "Maintain Location"){
        taskShape = "point";
    }
    else if (ui->m_pTaskSelect->currentText() == "Return to FOB"){
        return;
    }
    else if (ui->m_pTaskSelect->currentText() == "Home"){
        return;
    }
    else if (ui->m_pTaskSelect->currentText() == "Refuel"){
        return;
    }
    else if (ui->m_pTaskSelect->currentText() == "Avoid"){
        taskColor = "#fe0000";
        taskShape = "polygon";
    }
    else
    {
        //Done
    }
    /*
     * Task's shape and color have been set
     * Signal is caught by logicWidget's SLOT enableTaskDraw
     * Connection between SIGNAL and SLOT can be found in interfacewindow.cpp
    */
    Q_EMIT taskShapeAndColor(taskShape, taskColor);
}


/*
 *
*/
void TaskPanelWidget::mapCoordFromJS (QString locationJS)
{
    m_PointList.clear();
    /*
     * Location comes from JS and looks like this:
     * "( (lat0, lng0), (lat1, lng2), ..., (latN, lngN) )"
     * This needs to be changed to
     * ("(lat0" , "lng0)", "(lat1", "lng2)", ..., "(latN", "lngN)")
     * And then to
     * ("lat0", "lng0", "lat1", "lng2", ..., "latN", "lngN")
     *
    */

    QStringList coordList = locationJS.split(", ");
    if(coordList.size()%2 != 0) {
        qDebug()<< "Bad Coordinates returned from the browser.";
        return;
    }

    for (int i=0; i < coordList.size(); i++){
        coordList[i].remove("(");
        coordList[i].remove(")");
    }

    for (int i=0; i < coordList.size(); i++){
        m_PointList.append(coordList[i].toFloat());
    }
    enoughMapPoints = true;
    enableCommitBtn();
}

void TaskPanelWidget::taskBeliefUpdated(soa_shared_ptr<soa::Belief_Task> taskBelief)
{
    std::cout << "Emitting task updated" << std::endl;
    Q_EMIT(taskUpdated(taskBelief));
}

void TaskPanelWidget::commit(){

    /*
     * Gather task information from fields into a taskInfo * pTaskInfo.
     * The goal is to emit this information using the sendTaskInfo SIGNAL
     * The associated SLOTS are logicWidget's commitTask and taskSOA and
     * tabPanel2's addTask. The connections can be found in interfacewindow.cpp
    */
    taskInfo * pTaskInfo = new taskInfo;

    //Name of the task
    pTaskInfo->task       = ui->m_pTaskSelect->currentText();

    //Priority and risk
    pTaskInfo->priority   = ui->m_pPrioritySelect->currentText().toInt();
    pTaskInfo->risk       = ui->m_pRiskSelect->currentText().toInt();
    pTaskInfo->numHeavyUAVs = ui->m_pHSlider->value();
    pTaskInfo->numSmallUAVs = ui->m_pSSlider->value();

    //Remove spaces from the name of the task...
    if (pTaskInfo->task == "Move to Location")
    {
        pTaskInfo->task = "MoveToLocation";
    }
    else if (pTaskInfo->task == "Maintain Location")
    {
        pTaskInfo->task = "MaintainLocation";
    }
    else if (pTaskInfo->task == "Return to FOB")
    {
        pTaskInfo->task = "ReturnToFOB";
    }
    else
    {
        //do nothing.
    }

    //Processed JS coords
    pTaskInfo->points = m_PointList;

    //Duration
    QString tempDuration = "";
    tempDuration.append(QString::number(ui->m_pDDSelect->value()));
    tempDuration.append(QString::number(ui->m_pDHSelect->value()));
    tempDuration.append(QString::number(ui->m_pDMSelect->value()));
    tempDuration.append(QString::number(ui->m_pDSSelect->value()));
    pTaskInfo->duration = tempDuration;

    /*
     * The following code scripts a set of tasks
     *      00  Avoid (setup of no fly zone)
     *      01  Move to location    2 small UAVS    (103 104)
     *      01  Move to location    3 small UAVS    (105 106 107)
     *      01  Move to location    3 small UAVS    (108 109 110)
     *      01  Maintain location   3 small UAVS    (108 109 110)
     *      01  Move to location    1 heavy UAVS    (101)
     *      01  Return to FOB       2 small UAVS    (103 104)
     *
    */

    //00 Avoid
    if (commitCounter == 0)
    {
        pTaskInfo->id = 300;
        pTaskInfo->actor = " ";
        pTaskInfo->actorId = 103;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    //01 Move to Location
    else if (commitCounter == 1)
    {
        pTaskInfo->id = 301;
        pTaskInfo->actor = "Small UAV 103, 104";
        pTaskInfo->actorId = 103;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    //02 Move to Location
    else if (commitCounter == 2)
    {
        pTaskInfo->id = 302;
        pTaskInfo->actor = "Small UAV 105, 106, 107";
        pTaskInfo->actorId = 105;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    //03 Move to Location
    else if (commitCounter == 3)
    {
        pTaskInfo->id = 303;
        pTaskInfo->actor = "Small UAV 108, 109, 110";
        pTaskInfo->actorId = 108;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    //04 Maintain Location
    else if (commitCounter == 4)
    {
        pTaskInfo->id = 304;
        pTaskInfo->actor = "Small UAV 108, 109, 110";
        pTaskInfo->actorId = 108;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    //05 Move to Location
    else if (commitCounter == 5)
    {
        pTaskInfo->id = 305;
        pTaskInfo->actor = "Heavy UAV 101";
        pTaskInfo->actorId = 101;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    //07 Return to FOB
    else if (commitCounter == 6)
    {
        pTaskInfo->id = 306;
        pTaskInfo->actor = "Small UAV 103, 104";
        pTaskInfo->actorId = 103;
        Q_EMIT sendTaskInfo(pTaskInfo);
    }
    commitCounter++;
    resetAll();
}


void TaskPanelWidget::reset(){
    resetAll();
}


void TaskPanelWidget::cancel(){
    resetAll();
}


void TaskPanelWidget::updatePts(QString pts){
    qDebug()<<pts;
}


void TaskPanelWidget::setConnections(){
    //
}


void TaskPanelWidget::createTask(){
    //createTask() SLOT
}


void TaskPanelWidget::resetAll()
{
    //Buttons
    ui->m_pCancelButton->setEnabled(false);
    ui->m_pResetButton->setEnabled(false);
    ui->m_pCommitButton->setEnabled(false);
    //Duration
    ui->m_pDurationSmallBox->setVisible(false);
    //Risk
    ui->m_pRiskSelect->setCurrentIndex(-1);
    ui->m_pRiskSelect->setEnabled(false);
    //Priority
    ui->m_pPrioritySelect->setCurrentIndex(-1);
    ui->m_pPrioritySelect->setEnabled(false);
    //Associated task
    ui->m_pAssocTaskSelect->setEnabled(false);
    ui->labelAssocTask->setEnabled(false);
    //Task dropdown
    ui->m_pTaskSelect->setCurrentIndex(-1);
    //Vehicle selection
    ui->m_pSSlider->setValue(0);
    ui->m_pSSlider->setEnabled(false);
    ui->m_pHSlider->setValue(0);
    ui->m_pHSlider->setEnabled(false);
    //
    enoughMapPoints = false;
    enoughRobots = false;
}


void TaskPanelWidget::sliderMoved(int bots)
{
    if (bots > 0)
        enoughRobots = true;
    else if (ui->m_pSSlider->value() == 0 && ui->m_pHSlider->value() == 0)
        enoughRobots = false;
    enableCommitBtn();
}


