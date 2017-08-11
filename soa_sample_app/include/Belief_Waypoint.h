#include "Belief.h"
#include <cstdint>
#include <inttypes.h>

#ifndef BELIEF_WAYPOINT_H
#define BELIEF_WAYPOINT_H

#define MAX_SPEED 20

namespace soa{

class Belief_Waypoint : public Belief{
private:
    uint64_t request_time;
    int actor_id;
    float pos_x;
    float pos_y;
    float pos_z;
    float speed;// m/s

public:
    Belief_Waypoint(int actor_id, float x , float y, float z, float speed=MAX_SPEED);

	Belief_Waypoint(uint64_t request_time, int actor_id, float pos_x, float pos_y, float pos_z, float speed);

	virtual ~Belief_Waypoint() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getRequest_time() const;

	int getActor_id() const;

	float getPos_x() const;

	float getPos_y() const;

	float getPos_z() const;

	//Speed to move towards waypoint in m/s
	float getSpeed() const;

	virtual BeliefPtr getCopy() const;

	virtual string toString();
};

}

#endif
