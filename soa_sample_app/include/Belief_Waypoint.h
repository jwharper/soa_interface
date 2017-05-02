#include "Belief.h"
#include <cstdint>
#include <inttypes.h>

#ifndef BELIEF_WAYPOINT_H
#define BELIEF_WAYPOINT_H

namespace soa{

class Belief_Waypoint : public Belief{
private:
    uint64_t request_time;
    int actor_id;
    float pos_x;
    float pos_y;
    float pos_z;

public:
    Belief_Waypoint(int actor_id, float x , float y, float z);

	Belief_Waypoint(uint64_t request_time, int actor_id, float pos_x, float pos_y, float pos_z);

	virtual ~Belief_Waypoint() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getRequest_time();

	int getActor_id();

	float getPos_x();

	float getPos_y();

	float getPos_z();

	virtual BeliefPtr getCopy() const;

	virtual string toString();
};

}

#endif
