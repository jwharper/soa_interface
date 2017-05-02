/*
 * CustomBeliefExample.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: harpejw1
 */

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include "CustomBeliefExample.h"

Belief_Task::Belief_Task(int actorID, Task task, TaskStatus status)
	: Belief_Custom(Belief_Task::TYPE, actorID, NULL, 0),
	  task(task),
	  status(status)
{}

Task Belief_Task::getCurrentTask() const
{
	return task;
}

TaskStatus Belief_Task::getStatus() const
{
	return status;
}

std::string TaskSerializer::serializeBelief(soa::Belief* belief)
{
	Belief_Task* taskBelief = dynamic_cast<Belief_Task*>(belief);
	char buffer[12];
	int taskInt = htonl(taskBelief->getCurrentTask());
	int statusInt = htonl(taskBelief->getStatus());
	int actorID = htonl(belief->getId());
	memcpy(&buffer[0], &taskInt, 4);
	memcpy(&buffer[4], &statusInt, 4);
	memcpy(&buffer[8], &actorID, 4);
	return std::string(buffer, 12);
}

soa::Belief* TaskSerializer::generateBelief(std::string serial)
{
	std::cout << "De-serializing task belief" << std::endl;
	const char* buffer = serial.c_str();
	int taskInt, statusInt, actorID;
	memcpy(&taskInt, &buffer[0], 4);
	memcpy(&statusInt, &buffer[4], 4);
	memcpy(&actorID, &buffer[8], 4);
	taskInt = ntohl(taskInt);
	statusInt = ntohl(statusInt);
	actorID = ntohl(actorID);
	return new Belief_Task(actorID, (Task)taskInt, (TaskStatus)statusInt);
}

