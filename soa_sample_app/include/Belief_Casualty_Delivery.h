#include "Belief.h"
#include <cstdint>
#include <vector>
#include <inttypes.h>

#ifndef BELIEF_CASUALTY_DELIVERY_H
#define BELIEF_CASUALTY_DELIVERY_H

namespace soa{

class Belief_Casualty_Delivery : public Belief{
private:
    uint64_t request_time;
    int actor_id;
	bool greedy;
	int multiplicity;

public:
	Belief_Casualty_Delivery(uint64_t request_time, int actor_id, bool greedy, int multiplicity);

	virtual ~Belief_Casualty_Delivery() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getRequest_time();

	int getActor_id();

	bool getGreedy();

	int getMultiplicity();

	virtual BeliefPtr getCopy() const;

	virtual string toString();
};

}

#endif
