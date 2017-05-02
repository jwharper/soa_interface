/*
 * HeavyLiftBehavior.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: harpejw1
 */

#include <thread>

#include "soa_shared_ptr.h"
#include "CustomBeliefExample.h"
#include "HeavyLiftBehavior.h"

HeavyLiftBehavior::HeavyLiftBehavior(soa::AgentID agentID, std::string serverIP)
	: Behavior(agentID, serverIP),
	  lastTaskTime(0)
{
	soa::SerializerPtr serializer(new TaskSerializer());
	api.getWorldDataManager()->setSerializerForType(soa::Belief::Key(Belief_Task::TYPE), serializer);
}

void HeavyLiftBehavior::run(void)
{
	std::cout << "Starting heavy lift behavior" << std::endl;
	api.waitForConnectionToServer();
	while (api.getWorldDataManager()->getIsAlive())
	{
		soa_shared_ptr<Belief_Task> taskBelief = api.getWorldDataManager()->getTypedBelief<Belief_Task>(soa::Belief::Key(Belief_Task::TYPE), api.getAgentID());
		if (taskBelief.get() != NULL)
		{
			Task task = taskBelief->getCurrentTask();
			soa::WorldLocation destination;
			switch (task)
			{
			case VILLAGE_0:
				destination = api.getWorldDataManager()->getVillageLocation(0);
				break;
			case VILLAGE_1:
				destination = api.getWorldDataManager()->getVillageLocation(1);
				break;
			case VILLAGE_2:
				destination = api.getWorldDataManager()->getVillageLocation(2);
				break;
			case VILLAGE_3:
				destination = api.getWorldDataManager()->getVillageLocation(3);
				break;
			case VILLAGE_4:
				destination = api.getWorldDataManager()->getVillageLocation(4);
				break;
			case NGO_0:
				destination = api.getWorldDataManager()->getNGOSiteLocation(0);
				break;
			case NGO_1:
				destination = api.getWorldDataManager()->getNGOSiteLocation(1);
				break;
			case NGO_2:
				destination = api.getWorldDataManager()->getNGOSiteLocation(2);
				break;
			case NGO_3:
				destination = api.getWorldDataManager()->getNGOSiteLocation(3);
				break;
			}

			soa::WorldLocation agentLocation = getCurrentLocation();

			if (taskBelief->getStatus() == IN_PROGRESS && destination.isValid() && agentLocation.isValid())
			{
				std::cout << "Distance to destination: " << agentLocation.distance(destination) << std::endl;
				if (agentLocation.distance(destination) < 0.7)
				{
					std::cout << "Finishing task " << api.getAgentID() << std::endl;
					finishTask(taskBelief);
				}
				else if (taskBelief->getBeliefTime() != lastTaskTime)
				{
					lastTaskTime = taskBelief->getBeliefTime();
					//Only plan your route once
					std::cout << "Moving to destination" << std::endl;
					api.moveToDestination(destination);
				}
			}
		}
		else
		{
			std::cout  << "No tasking belief" << std::endl;
			if (api.getWorldDataManager()->getBelief(soa::Belief::Key(Belief_Task::TYPE), api.getAgentID()).get() != NULL)
			{
				std::cout << "Bust i have a custom belief of that type" << std::endl;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void HeavyLiftBehavior::finishTask(soa_shared_ptr<Belief_Task> taskBelief)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));//Sleep while picking up casualties
	soa_shared_ptr<Belief_Task> finished(new Belief_Task(taskBelief->getId(), taskBelief->getCurrentTask(), FINISHED));
	api.getWorldDataManager()->addBelief(finished);
	api.returnToFOB();
}

soa::WorldLocation HeavyLiftBehavior::getCurrentLocation()
{
	soa_shared_ptr<soa::Belief_Actor> actorBelief = api.getWorldDataManager()->getTypedBelief<soa::Belief_Actor>(soa::Belief::ACTOR, api.getAgentID());
	if (actorBelief.get() != NULL)
	{
		return actorBelief->getPosition();
	}
	std::cout << "No position about myself " << api.getAgentID() << std::endl;
	soa::WorldLocation invalid;
	return invalid;
}
