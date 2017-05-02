/*
 * BaseBehavior.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: harpejw1
 */

#include <iostream>
#include <random>
#include <thread>
#include "BaseBehavior.h"

BaseBehavior::BaseBehavior(std::string serverIP)
	: Behavior(soa::AgentID::BLUE_BASE, serverIP),
	  nextTask(Task::VILLAGE_0)
{
	soa::SerializerPtr serializer(new TaskSerializer());
	api.getWorldDataManager()->setSerializerForType(soa::Belief::Key(Belief_Task::TYPE), serializer);
}

void BaseBehavior::run(void)
{
	api.waitForConnectionToServer();

	forceHeavyUAVsToEnterBaseFromSouth();

	soa::WorldLocation ngo1 = api.getWorldDataManager()->getNGOSiteLocation(1);
	soa::WorldLocation vill1 = api.getWorldDataManager()->getVillageLocation(1);
	soa::WorldLocation vill2 = api.getWorldDataManager()->getVillageLocation(2);
	soa::WorldLocation center = ngo1.add(vill1).add(vill2);
	center.x /= 3.f;
	center.y = 0;
	center.z /= 3.f;

	//Example of circular no fly zone
	int circularNoFlyZone = api.addNoFlyZone(center, center.distance(ngo1) - 1);

	int seconds = 0;
	while(true)
	{
		if (seconds++ == 120) {
			//Example of how to remove a no fly zone
			api.removeNoFlyZone(circularNoFlyZone);
		}

		soa::WorldLocation base = api.getWorldDataManager()->getBlueBaseLocation();
		if(base.isValid())
		{
 		        assignTask(soa::BLUE_HEAVY_LIFT_1);
			assignTask(soa::BLUE_HEAVY_LIFT_2);
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void BaseBehavior::assignTask(int agentID)
{
	soa::WorldLocation heavy1 = getAgentLocation(agentID);
	if (!heavy1.isValid())
	{
		std::cout << "Waiting for position information for agent" << agentID << std::endl;
	}
	if (heavy1.isValid() && needsTasking(agentID))
	{
		Task task = nextTask;
		nextTask = (Task)((nextTask + 1) % Task::NUM_TASKS);
		soa_shared_ptr<Belief_Task> assigned(new Belief_Task(agentID, task, IN_PROGRESS));
		api.getWorldDataManager()->addBelief(assigned);
	}
	else
	{
		std::cout << "Not retasking because needs tasking=" << needsTasking(agentID) << std::endl;
	}
}

bool BaseBehavior::needsTasking(int agentID)
{
	soa_shared_ptr<Belief_Task> taskBelief = api.getWorldDataManager()->getTypedBelief<Belief_Task>(soa::Belief::Key(Belief_Task::TYPE), agentID);
	if (taskBelief.get() == NULL) {
		std::cout << "Need to create a new task for agent" << agentID << std::endl;
		return true;
	}

	if (taskBelief->getStatus() == IN_PROGRESS) {
		return false;
	} else
	{
		std::cout << "Task belief is finished" << std::endl;
	}

	soa::WorldLocation base = api.getWorldDataManager()->getBlueBaseLocation();
	soa::WorldLocation agent = getAgentLocation(agentID);
	float distance = agent.distance(base);
	std::cout << "Agent is " << distance << " away from base" << std::endl;
	return distance < 0.7;
}

soa::WorldLocation BaseBehavior::getAgentLocation(int agentID)
{
	soa_shared_ptr<soa::Belief_Actor> agentBelief = api.getWorldDataManager()->getTypedBelief<soa::Belief_Actor>(soa::Belief::ACTOR, agentID);
	if (agentBelief.get() != NULL)
	{
		return agentBelief->getPosition();
	}

	soa::WorldLocation invalid;
	return invalid;
}

void BaseBehavior::forceHeavyUAVsToEnterBaseFromSouth()
{
	//Create a horseshoe around base leaving only south entrance
	soa::GridMath* math = api.getWorldDataManager()->getGridMath();
	soa::WorldLocation base = api.getWorldDataManager()->getBlueBaseLocation();
	soa::GridCell baseCell = base.convertToGridLocation(math);
	soa::WorldLocation sw(baseCell.southWest().south().convertToWorldLocation(math));
	soa::WorldLocation nw(baseCell.northWest().north().convertToWorldLocation(math));
	soa::WorldLocation ne(baseCell.northEast().north().convertToWorldLocation(math));
	soa::WorldLocation se(baseCell.southEast().south().convertToWorldLocation(math));

	std::vector<soa::WorldLocation> noFlyZone;
	noFlyZone.push_back(soa::WorldLocation(sw.x + 0.1, 0, sw.z));
	noFlyZone.push_back(soa::WorldLocation(sw.x + 0.1, 0, base.z + 0.6));
	noFlyZone.push_back(soa::WorldLocation(se.x - 0.1, 0, base.z + 0.6));
	noFlyZone.push_back(soa::WorldLocation(se.x - 0.1, 0, se.z));
	noFlyZone.push_back(soa::WorldLocation(se.x + 2, 0, se.z));
	noFlyZone.push_back(soa::WorldLocation(ne.x + 2, 0, ne.z+2));
	noFlyZone.push_back(soa::WorldLocation(nw.x - 2, 0, nw.z+2));
	noFlyZone.push_back(soa::WorldLocation(sw.x - 2, 0, sw.z));

	api.addNoFlyZone(noFlyZone);
}

