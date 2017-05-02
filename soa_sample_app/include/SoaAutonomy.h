/*
 * AutonomyAPI.h
 *
 *  Created on: May 9, 2016
 *      Author: harpejw1
 */

#include "WorldDataManager.h"
#include "Belief_Actor.h"
#include "GridCell.h"
#include <vector>
#include "Belief_WaypointPath.h"

#ifndef INCLUDE_AUTONOMYAPI_H_
#define INCLUDE_AUTONOMYAPI_H_

namespace soa {

enum AgentID {
	BLUE_BASE 			= 0,
	BLUE_HEAVY_LIFT_1 	= 100,
	BLUE_HEAVY_LIFT_2 	= 101,
	BLUE_SMALL_UAV_1 	= 102,
	BLUE_SMALL_UAV_2 	= 103,
	BLUE_SMALL_UAV_3 	= 104,
	BLUE_BALLOON 		= 105,
};

class SoaAutonomy {

public:
	enum Task {

	};

	/**
	 * Initializes a connection with the
	 * SOA world.
	 *
	 * myId - ID for agent that will be making the
	 * 			commands.
	 *
	 * roomName - a unique string that identifies
	 * 				a particular simulation running.
	 * 			    Note: This must match the name
	 * 			    in the SoaSimConfig.xml file.
	 */
	SoaAutonomy(int myId, string roomName);

	/**
	 * Constructs the class with an existing data manager.
	 * Using this contructor will NOT deconstruct the
	 * WorldDataManager when this class is deconstructed.
	 */
	SoaAutonomy(WorldDataManager* existingDataManager);

	/**
	 * Destroys the world data manager and
	 * closes the connection with the
	 * simulator.
	 */
	~SoaAutonomy();

	/**
	 * Blocks until beliefs about the game are received
	 * from the server.
	 */
	void waitForConnectionToServer();

	/**
	 * Returns a reference to the world data manager
	 */
	WorldDataManager* getWorldDataManager() const;

	/**
	 * Returns the ID of the agent using this API.
	 */
	int getAgentID();

	/**
	 * Returns a list of all the blue and red actors
	 * that this agent knows about.
	 */
	std::vector<Belief_Actor> getAllActorBeliefs();

	/**
	 * Move this agent to a particular location.
	 * Note: this is equivalent to
	 * sendWaypointCommand(getAgentID(), x, y, z);
	 */
	void moveToDestination(WorldLocation location);

	/**
	 * Move this agent to the center of the given
	 * hex cell.
	 */
	void moveToDestination(GridCell location);

	/**
	 * Commands the agent with the given ID to move to the
	 * given 3D location.
	 */
	void sendWaypointCommand(int agentID, WorldLocation location);

	/**
	 * Commands the agent with the given ID to move to the center
	 * of the given hex cell
	 */
	void sendWaypointCommand(int agentID, GridCell location);

	/**
	 * Moves this agent along a path of waypoints.
	 * Note: this is equivalent to
	 * sendWaypointPathCommand(getAgentID(), waypoints);
	 */
	void moveAlongPath(const std::vector<WorldLocation>& waypoints);

	/**
	 * Moves this agent along a path of waypoints.
	 * Note: this is equivalent to
	 * sendWaypointPathCommand(getAgentID(), waypoints);
	 */
	void moveAlongPath(const std::vector<GridCell>& waypoints);

	/**
	 * Commands an agent to follow the given path of waypoints.
	 */
	void sendWaypointPathCommand(int agentID, const std::vector<WorldLocation>& waypoints);

	/**
	 * Commands an agent to follow the given path of waypoints.
	 */
	void sendWaypointPathCommand(int agentID, const std::vector<GridCell>& waypoints);

	/**
	 * Moves this agent back to the FOB to refuel.
	 */
	void refuel();

	/**
	 * Commands a particular agent to return to the FOB
	 * to refuel.
	 */
	void sendRefuelCommand(int agentID);

	/**
	 * Moves this agent back to FOB.
	 */
	void returnToFOB();

	/**
	 * Commands the specified agent to return
	 * to the FOB.
	 */
	void sendReturnToFOBCommand(int agentID);

	/**
	 * Commands this agent to remain at its
	 * current location
	 */
	void maintainLocation();

	/**
	 * Commands the specified agent to remain
	 * at its current location.
	 */
	void sendMaintainLocationCommand(int agentID);

	/**
	 * Adds a region for the agents to avoid. The region
	 * is defined by the ordered list of points passed
	 * into this method. The points can be either
	 * clockwise or counter-clockwise. Returns an integer
	 * that uniquely identifies the region. This can
	 * be used to remove the zone later.
	 */
	int addNoFlyZone(const std::vector<WorldLocation>& outline);

	/**
	 * Adds a region for the agents to avoid. The region
	 * is defined by a circle defined by the center and
	 * radius passing into the method. Returns an integer
	 * that uniquely identifies the region. This can
	 * be used to remove the zone later.
	 */
	int addNoFlyZone(WorldLocation center, float radius);

	/**
	 * Clears out a previously defined no-fly zone.
	 * The zoneID should be an integer returned by
	 * the addNoFlyZone method.
	 */
	void removeNoFlyZone(int zoneID);

private:
	WorldDataManager* dataManager;
	bool destroyDataManager;
};

}



#endif /* INCLUDE_AUTONOMYAPI_H_ */
