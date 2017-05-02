#include "Belief.h"
#include <cstdint>
#include <inttypes.h>

#ifndef BELIEF_SPOI_H
#define BELIEF_SPOI_H

namespace soa{

class Belief_SPOI : public Belief{
private:
    uint64_t request_time;
    int actor_id;
    float pos_x;
	float pos_y;
    float pos_z;

public:
	Belief_SPOI(uint64_t request_time, int actor_id, float pos_x, float pos_y, float pos_z);

	virtual ~Belief_SPOI() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getRequest_time();

	int getActor_id();

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	float getPos_x();

	float getPos_y();

	float getPos_z();
};

}

#endif
