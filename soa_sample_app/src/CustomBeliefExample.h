/*
 * CustomBeliefExample.h
 *
 *  Created on: Jul 18, 2016
 *      Author: harpejw1
 */

#include "Belief_Custom.h"
#include "Serializer.h"
#include "Belief.h"

#ifndef SAMPLE_AUTONOMY_SRC_CUSTOMBELIEFEXAMPLE_H_
#define SAMPLE_AUTONOMY_SRC_CUSTOMBELIEFEXAMPLE_H_

enum Task
{
	VILLAGE_0,
	VILLAGE_1,
	VILLAGE_2,
	VILLAGE_3,
	VILLAGE_4,
	NGO_0,
	NGO_1,
	NGO_2,
	NGO_3,
	NUM_TASKS
};

enum TaskStatus
{
	IN_PROGRESS,
	FINISHED
};

class Belief_Task : public soa::Belief_Custom
{
public:
	static const int TYPE = 123;

private:
	Task task;
	TaskStatus status;

public:
	Belief_Task(int actorID, Task task, TaskStatus status);

	Task getCurrentTask() const;

	TaskStatus getStatus() const;
};

class TaskSerializer : public soa::Serializer
{
	string serializeBelief(soa::Belief* belief);

		// Serialized string to Belief conversion
	soa::Belief* generateBelief(string serial);
};


#endif /* SAMPLE_AUTONOMY_SRC_CUSTOMBELIEFEXAMPLE_H_ */
