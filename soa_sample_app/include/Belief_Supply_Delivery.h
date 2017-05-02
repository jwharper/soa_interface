#include "Belief.h"
#include <cstdint>
#include <vector>
#include <inttypes.h>

#ifndef BELIEF_SUPPLY_DELIVERY_H
#define BELIEF_SUPPLY_DELIVERY_H

namespace soa{

class Belief_Supply_Delivery : public Belief{
private:
    uint64_t request_time;
    int actor_id;
	bool greedy;
	std::vector<int> ids;
	std::vector<int> multiplicity;

public:
	Belief_Supply_Delivery(uint64_t request_time, int actor_id, bool greedy, std::vector<int> ids, std::vector<int> multiplicity);

	virtual ~Belief_Supply_Delivery() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getRequest_time();

	int getActor_id();

	bool getGreedy();

	std::vector<int> getIds();

	std::vector<int> getMultiplicity();

	virtual BeliefPtr getCopy() const;

	virtual string toString();
};

}

#endif
