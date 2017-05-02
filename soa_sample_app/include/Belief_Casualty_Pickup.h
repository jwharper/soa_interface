#include "Belief.h"
#include <cstdint>
#include <vector>
#include <inttypes.h>

#ifndef BELIEF_CASUALTY_PICKUP_H
#define BELIEF_CASUALTY_PICKUP_H

namespace soa{

class Belief_Casualty_Pickup : public Belief{
private:
    uint64_t request_time;
    int actor_id;
	bool greedy;
	std::vector<int> ids;
	std::vector<int> multiplicity;

public:
	Belief_Casualty_Pickup(uint64_t request_time, int actor_id, bool greedy, std::vector<int> ids, std::vector<int> multiplicity);

	Belief::BeliefType getBeliefType() const;

	virtual ~Belief_Casualty_Pickup() {}

	uint64_t getRequest_time();

	int getActor_id();

	bool getGreedy();

	std::vector<int> getIds();

	std::vector<int> getMultiplicity();

	virtual BeliefPtr getCopy() const ;

	virtual string toString();
};

}

#endif
