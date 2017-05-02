/*
 * BaseBehavior.h
 *
 *  Created on: Jul 18, 2016
 *      Author: harpejw1
 */

#include "Behavior.h"
#include "CustomBeliefExample.h"

#ifndef SAMPLE_AUTONOMY_SRC_BASEBEHAVIOR_H_
#define SAMPLE_AUTONOMY_SRC_BASEBEHAVIOR_H_


class BaseBehavior : public Behavior
{
private:
	Task nextTask;

public:
	BaseBehavior(std::string serverIP);

	virtual ~BaseBehavior() {}

	virtual void run();

private:
	void assignTask(int agentID);

	bool needsTasking(int agentID);

	soa::WorldLocation getAgentLocation(int agentID);

	void forceHeavyUAVsToEnterBaseFromSouth();
};


#endif /* SAMPLE_AUTONOMY_SRC_BASEBEHAVIOR_H_ */
