/*
 * HeavyLiftUAV.h
 *
 *  Created on: Jul 18, 2016
 *      Author: harpejw1
 */

#include "Behavior.h"
#include "CustomBeliefExample.h"

#ifndef SAMPLE_AUTONOMY_SRC_HEAVYLIFTBEHAVIOR_H_
#define SAMPLE_AUTONOMY_SRC_HEAVYLIFTBEHAVIOR_H_


class HeavyLiftBehavior : public Behavior
{

public:
	HeavyLiftBehavior(soa::AgentID agentID, std::string serverIP);

	virtual ~HeavyLiftBehavior() {}

	virtual void run ();

private:
	soa::WorldLocation getCurrentLocation();

	void finishTask(soa_shared_ptr<Belief_Task> taskBelief);

	uint64_t lastTaskTime;
};


#endif /* SAMPLE_AUTONOMY_SRC_HEAVYLIFTBEHAVIOR_H_ */
