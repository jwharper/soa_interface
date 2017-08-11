/*
 * BeliefWaypointPath.h
 *
 *  Created on: Nov 16, 2015
 *      Author: biggimh1
 */

#ifndef BELIEFWAYPOINTPATH_H_
#define BELIEFWAYPOINTPATH_H_

#include <vector>
#include <cstdint>
#include <inttypes.h>

#include "Belief.h"
#include "WorldLocation.h"

namespace soa {

struct Navpoint
{
private:
	WorldLocation location;
	float speed;

public:

	Navpoint(WorldLocation location, float speed);

	WorldLocation getLocation() const;

	float getSpeed() const;
};

typedef std::vector<Navpoint> NavpointPath;

class Belief_WaypointPath : public Belief {

public:

	typedef std::vector<WorldLocation> WaypointPath;

	Belief_WaypointPath(int id, WaypointPath waypoints);

	Belief_WaypointPath(uint64_t _request_time, int id, WaypointPath waypoints);

	Belief_WaypointPath(int id, NavpointPath navpoints);

	Belief_WaypointPath(uint64_t _request_time, int id, NavpointPath navpoints);

	virtual ~Belief_WaypointPath();

	virtual Belief::BeliefType getBeliefType() const;

	int getNumWaypoints();

	WaypointPath getWaypoints();

	NavpointPath getNavpoints();

	virtual BeliefPtr getCopy() const;

	virtual std::string toString();

	virtual uint64_t getRequestTime() const { return request_time; }

private:
	uint64_t request_time;
	NavpointPath navpoints;

};

typedef Belief_WaypointPath::WaypointPath WaypointPath;

} /* namespace soa */
#endif /* BELIEFWAYPOINTPATH_H_ */
