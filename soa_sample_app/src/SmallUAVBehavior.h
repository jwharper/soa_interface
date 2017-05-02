/*
 * SmallUAVBehavior.h
 *
 *  Created on: Jul 15, 2016
 *      Author: harpejw1
 */

#include <vector>

#include "SoaAutonomy.h"
#include "Behavior.h"

#ifndef SAMPLE_AUTONOMY_SRC_SMALLUAVBEHAVIOR_H_
#define SAMPLE_AUTONOMY_SRC_SMALLUAVBEHAVIOR_H_

class SmallUAVBehavior : public Behavior
{
protected:
		enum State {STARTING, PATROLLING};
		std::vector<soa::WorldLocation> waypoints;
		State state;

public:

	SmallUAVBehavior(soa::AgentID agentID, std::string serverIP);

	virtual ~SmallUAVBehavior() {}

	virtual void run ();

protected:

	void startPatrol();

	void patrol();

	bool isOnBase();

	bool acquireWaypoints();

};


#endif /* SAMPLE_AUTONOMY_SRC_SMALLUAVBEHAVIOR_H_ */
