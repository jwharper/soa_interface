#include "Belief.h"
#include <cstdint>
#include <vector>
#include <inttypes.h>

#ifndef BELIEF_SUPPLY_PICKUP_H
#define BELIEF_SUPPLY_PICKUP_H

namespace soa{

class Belief_Supply_Pickup : public Belief{
private:
    uint64_t request_time;
    int actor_id;
	bool greedy;
	int multiplicity;

public:
	Belief_Supply_Pickup(uint64_t request_time, int actor_id, bool greedy, int multiplicity);

	virtual ~Belief_Supply_Pickup() {}

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
