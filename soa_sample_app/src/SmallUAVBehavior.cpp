/*
 * SmallUAVBehavior.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: harpejw1
 */

#include <thread>

#include "SmallUAVBehavior.h"

# ifndef SLEEP
#	define SLEEP(time_seconds) std::this_thread::sleep_for(std::chrono::seconds(time_seconds))
# endif

using namespace soa;

SmallUAVBehavior::SmallUAVBehavior(AgentID agentID, std::string serverIP)
	: Behavior(agentID, serverIP),
	  state(State::STARTING)
{}

void SmallUAVBehavior::run()
{
	api.waitForConnectionToServer();

	while (true)
	{
		switch (state)
		{
		case STARTING:
			startPatrol();
			break;
		case PATROLLING:
			patrol();
			break;
		}

		SLEEP(1);
	}
}

void SmallUAVBehavior::startPatrol()
{
	waypoints.clear();

	if (acquireWaypoints()) {
		api.moveAlongPath(waypoints);
		state = PATROLLING;
	}
}

void SmallUAVBehavior::patrol()
{
	if (isOnBase())
	{
		state = STARTING;
	}
}

bool SmallUAVBehavior::isOnBase()
{
	soa_shared_ptr<Belief_Actor> actorBelief = api.getWorldDataManager()->getTypedBelief<Belief_Actor>(Belief::ACTOR, api.getAgentID());
	if (actorBelief.get() != NULL)
	{
		float dX = actorBelief->getPos_x() - -3.028;
		float dZ = actorBelief->getPos_z() - -9.749;
		float dist = sqrt(dX*dX + dZ*dZ);
		return dist < 0.1;
	}
	return false;
}

bool SmallUAVBehavior::acquireWaypoints()
{

	WorldDataManager* data = api.getWorldDataManager();

	WorldLocation village0 = data->getVillageLocation(0);
	WorldLocation village1 = data->getVillageLocation(1);
	WorldLocation village2 = data->getVillageLocation(2);
	WorldLocation village3 = data->getVillageLocation(3);
	WorldLocation village4 = data->getVillageLocation(4);

	WorldLocation ngo0 = data->getNGOSiteLocation(0);
	WorldLocation ngo1 = data->getNGOSiteLocation(1);
	WorldLocation ngo2 = data->getNGOSiteLocation(2);
	WorldLocation ngo3 = data->getNGOSiteLocation(3);

	WorldLocation base = data->getBlueBaseLocation();

	switch (api.getAgentID())
	{
	case BLUE_SMALL_UAV_1:
		if (!village1.isValid() || !ngo0.isValid() || !village4.isValid() || !base.isValid()) {
			return false;
		}
		waypoints.push_back(village1);
		waypoints.push_back(ngo0);
		waypoints.push_back(WorldLocation(village4.x - 2, 0, village4.z));
		waypoints.push_back(village4);
		waypoints.push_back(base);
		break;
	case BLUE_SMALL_UAV_2:
		if (!ngo1.isValid() || !village0.isValid() || !village2.isValid() || !ngo2.isValid() || !base.isValid()) {
			return false;
		}
		waypoints.push_back(ngo1);
		waypoints.push_back(village0);
		waypoints.push_back(WorldLocation(village2.x, 0, village2.z + 2));
		waypoints.push_back(ngo2);
		waypoints.push_back(base);
		break;
	case BLUE_SMALL_UAV_3:
		if (!ngo3.isValid() || !ngo2.isValid() || !village3.isValid() || !base.isValid()) {
			return false;
		}

		waypoints.push_back(ngo3);
		waypoints.push_back(WorldLocation(ngo3.x, 0, (ngo3.z + ngo2.z)/2.));//Don't hit the mountain!
		waypoints.push_back(ngo2);
		waypoints.push_back(village3);
		waypoints.push_back(base);
		break;
	default:
		return false;
	}

	return true;
}
