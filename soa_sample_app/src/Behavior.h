/*
 * Behavior.h
 *
 *  Created on: Jul 15, 2016
 *      Author: harpejw1
 */

#include <string>

#include "SoaAutonomy.h"

#ifndef SAMPLE_AUTONOMY_SRC_BEHAVIOR_H_
#define SAMPLE_AUTONOMY_SRC_BEHAVIOR_H_


class Behavior
{

protected:
	soa::SoaAutonomy api;

public:
	Behavior(soa::AgentID id, std::string serverIP)
		: api(id, serverIP)
	{}

	virtual ~Behavior() {}

	virtual void run() = 0;
};



#endif /* SAMPLE_AUTONOMY_SRC_BEHAVIOR_H_ */
