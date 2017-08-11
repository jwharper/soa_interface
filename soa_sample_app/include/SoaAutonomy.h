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

#include "task/RegionTaskBuilder.h"
#include "task/PointTaskBuilder.h"
#include "task/PatrolTaskBuilder.h"
#include "task/TrackingTaskBuilder.h"
#include "task/AvoidRegionConstraint.h"
#include "task/AvoidThreatConstraint.h"
#include "task/CommsConstraint.h"

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
	void moveToDestination(WorldLocation location, float speed=MAX_SPEED);

	/**
	 * Move this agent to the center of the given
	 * hex cell.
	 */
	void moveToDestination(GridCell location, float speed=MAX_SPEED);

	/**
	 * Commands the agent with the given ID to move to the
	 * given 3D location.
	 */
	void sendWaypointCommand(int agentID, WorldLocation location, float speed=MAX_SPEED);

	/**
	 * Commands the agent with the given ID to move to the center
	 * of the given hex cell
	 */
	void sendWaypointCommand(int agentID, GridCell location, float speed=MAX_SPEED);

	/**
	 * Moves this agent along a path of waypoints.
	 * Note: this is equivalent to
	 * sendWaypointPathCommand(getAgentID(), waypoints);
	 */
	void moveAlongPath(const std::vector<WorldLocation>& waypoints, float speed=MAX_SPEED);

	/**
	 * Moves this agent along a path of waypoints.
	 * Note: this is equivalent to
	 * sendWaypointPathCommand(getAgentID(), waypoints);
	 */
	void moveAlongPath(const std::vector<GridCell>& waypoints, float speed=MAX_SPEED);

	/**
	 * Commands an agent to follow the given path of waypoints.
	 */
	void sendWaypointPathCommand(int agentID, const std::vector<WorldLocation>& waypoints, float speed=MAX_SPEED);

	/**
	 * Commands an agent to follow the given path of waypoints.
	 */
	void sendWaypointPathCommand(int agentID, const std::vector<GridCell>& waypoints, float speed=MAX_SPEED);

	/**
	 * Returns a safe path from the agent to the destination. This will avoid both mountains
	 * and no-fly zones.
	 */
	std::vector<soa::WorldLocation> findPathTo(int agentID, soa::WorldLocation destination);

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

	/**
	 * Creates a new builder class for instantiating a region task.
	 *
	 * Inputs:
	 * 	- TaskType::Value - The type of region task to create. This must
	 * 						be one of {SEARCH, DISPERSE, PERIMETER}.
	 *
	 * Outputs:
	 *  - task::RegionTaskBuilder - a builder object that has methods
	 *  							for setting important fields on
	 *  							the region task.
	 */
	task::RegionTaskBuilder newRegionTaskBuilder(task::TaskType::Value type);

	/**
	 * Creates a new builder class for instantiating a point task.
	 *
	 * Inputs:
	 * 	- TaskType::Value - The type of region task to create. This must
	 * 						be one of {RALLY, DELIVERY, PICKUP, GOTO}.
	 *
	 * Outputs:
	 *  - task::PointTaskBuilder - a builder object that has methods
	 *  							for setting important fields on
	 *  							the point task.
	 */
	task::PointTaskBuilder newPointTaskBuilder(task::TaskType::Value type);

	/**
	 * Creates a new builder class for instantiating a tracking task.
	 *
	 * Outputs:
	 *  - task::TrackingTaskBuilder - a builder object that has methods
	 *  							for setting important fields on
	 *  							the tracking task.
	 */
	task::TrackingTaskBuilder newTrackingTaskBuilder();

	/**
	 * Creates a new builder class for instantiating a patrol task.
	 *
	 * Outputs:
	 *  - task::PatrolTaskBuilder - a builder object that has methods
	 *  							for setting important fields on
	 *  							the patrol task.
	 */
	task::PatrolTaskBuilder newPatrolTaskBuilder();

	/**
	 * Creates a new builder class for instantiating
	 * an AvoidRegionConstraint
	 *
	 * Outputs:
	 *  - task::AvoidRegionConstraintBuilder - A builder object for
	 *  										creating a no-fly zone.
	 */
	task::AvoidRegionConstraintBuilder newAvoidRegionBuilder();

	/**
	 * Creates a new builder class for instantiating
	 * an AvoidThreatConstraint
	 *
	 * Outputs:
	 *  - task::AvoidThreatConstraintBuilder - A builder object for
	 *  										a constraint to avoid
	 *  										a particular agent.
	 */
	task::AvoidThreatConstraintBuilder newAvoidThreatBuilder();

	/**
	 * Creates a new builder class for instantiating
	 * an CommsConstraintBuilder
	 *
	 * Outputs:
	 *  - task::CommsConstraintBuilder - A builder object for
	 *  								 requiring agents to
	 *  								 maintain comms with each
	 *  								 other.
	 */
	task::CommsConstraintBuilder newMaintainCommsBuilder();

	/**
	 * Returns a list of agent IDs for any agents that
	 * are not assigned to an active task.
	 */
	std::vector<int> getUnassignedAgents();

	/**
	 * Returns a list of task pointers
	 * (shared_ptr<Task>) for tasks that are active
	 * and assigned to the specified agent.
	 */
	std::vector<task::TaskPtr> getTasksAssignedTo(int agentID);

	/**
	 * Returns a list of IDs of the agents that are
	 * assigned (manually or self-assigned) to fulfill
	 * one or more resource requirements for the
	 * specified task.
	 */
	std::vector<int> getAgentsAssignedTo(task::TaskID taskID);

	/**
	 * Returns a list of all tasks that have unassigned
	 * resources requirements.
	 */
	std::vector<task::TaskPtr> getUnfulfilledTasks();

private:
	WorldDataManager* dataManager;
	bool destroyDataManager;
};

}



#endif /* INCLUDE_AUTONOMYAPI_H_ */
