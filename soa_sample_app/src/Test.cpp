// Test script to create beliefs and send across network

#include <iostream>
#include "WorldDataManager.h"
#include "Belief_Actor.h"
#include "Belief_Base.h"
#include "Belief_Casualty_Delivery.h"
#include "Belief_Casualty_Pickup.h"
#include "Belief_Custom.h"
#include "Belief_GridSpec.h"
#include "Belief_Mode_Command.h"
#include "Belief_NGOSite.h"
#include "Belief_RoadCell.h"
#include "Belief_SPOI.h"
#include "Belief_Supply_Delivery.h"
#include "Belief_Supply_Pickup.h"
#include "Belief_Terrain.h"
#include "Belief_Time.h"
#include "Belief_Village.h"
#include "Belief_Waypoint_Override.h"
#include "Belief_Waypoint.h"
#include "Belief.h"
#include "Belief_WaypointPath.h"

#include "CustomBeliefHandler.h"
#include "soa_shared_ptr.h"
#include <cstdint>
#include <math.h>
#include <thread>

#include "BaseBehavior.h"
#include "HeavyLiftBehavior.h"
#include "SmallUAVBehavior.h"

# ifndef SLEEP
#	define SLEEP(time_ms) std::this_thread::sleep_for(std::chrono::milliseconds(4))
# endif

using namespace soa;
using namespace std;

//Test and print functions
static void RandomDataConnectivityTest(int id);
static void PrintAllBeliefsType(string beliefTypeName, std::map<int, soa_shared_ptr<Belief> > beliefMap);

//Autonomy behavior functions called from main
static void heavyLiftUavBehavior(int actorId, string roomname);
static void smallUavBehavior(int actorId, string roomname);
static void pollDataManagerBehavior(int actorId, string roomname);

struct waypoint{
	float x;
	float z;
};

static void runBehavior(Behavior* behavior)
{
	std::cout << "Inside thread" << std::endl;
	if (behavior == NULL)
	{
		std::cerr << "Null reference" << std::endl;
		return;
	}
	behavior->run();
}

int main(int argc, char* argv[]){
	std::string serverIP = "localhost:11511";

	Behavior* heavyUAV1 = new HeavyLiftBehavior(AgentID::BLUE_HEAVY_LIFT_1, serverIP);
	std::thread tHUAV1(runBehavior, heavyUAV1);

	Behavior* heavyUAV2 = new HeavyLiftBehavior(AgentID::BLUE_HEAVY_LIFT_2, serverIP);
	std::thread tHUAV2(runBehavior, heavyUAV2);

	Behavior* smallUAV1 = new SmallUAVBehavior(AgentID::BLUE_SMALL_UAV_1, serverIP);
	std::thread tUAV1(runBehavior, smallUAV1);

	Behavior* smallUAV2 = new SmallUAVBehavior(AgentID::BLUE_SMALL_UAV_2, serverIP);
	std::thread tUAV2(runBehavior, smallUAV2);

	Behavior* smallUAV3 = new SmallUAVBehavior(AgentID::BLUE_SMALL_UAV_3, serverIP);
	std::cout << "Starting thread" << std::endl;
	std::thread tUAV3(runBehavior, smallUAV3);

	Behavior* base = new BaseBehavior(serverIP);
	base->run();

	return 0;
}

/**
 * Sample code showing how to pull out information from data manager
 */
void pollDataManagerBehavior(int actorId, string roomname){
	// Create a world data manager
	printf("Initializing blue base data manager...\n");

	//Create your data manager for this agent
	WorldDataManager * dm = WorldDataManager::create(actorId, roomname);

	// Wait to connect
	bool connected = false;
	while(!connected){
		// We can use existence of base belief as indication that we've connected to sim
		std::map<int, soa_shared_ptr<Belief> > baseMap = dm->getAllBeliefs(Belief::BASE);
		if(baseMap.begin() == baseMap.end()){
			SLEEP(100);
		}else{
			connected = true;
		}
	}

	// Infinite loop
	GridMath* gm = NULL; 		
	while(1){
		// Need to wait for grid belief to come through before we can determine site locations		
		while(gm == NULL){
			SLEEP(500);
			gm = dm->getGridMath();
		}
		
		// New iteration
		cout << "***********************************************************" << endl;

		// Print out base information
		float tempX, tempY, tempZ;
		std::map<int, soa_shared_ptr<Belief> > baseMap = dm->getAllBeliefs(Belief::BASE);
		std::map<int, soa_shared_ptr<Belief> >::iterator baseIter;
		for(baseIter = baseMap.begin(); baseIter != baseMap.end(); baseIter++){
			Belief_Base* base = static_cast<Belief_Base*>(baseIter->second.get());
			gm->gridToWorld(base->getCells()[0].getCol(), base->getCells()[0].getRow(), tempX, tempZ);
			cout << "Base: id=" << base->getId() << ", position=(" << tempX << ",0," << tempZ << ")";
			cout << ", suppliesAvailable=" << base->getSupplies();
			cout << ", timestamp=" << base->getBeliefTime() << endl;
		}

		// Print out NGO information
		std::map<int, soa_shared_ptr<Belief> > ngoMap = dm->getAllBeliefs(Belief::NGOSITE);
		std::map<int, soa_shared_ptr<Belief> >::iterator ngoIter;
		for(ngoIter = ngoMap.begin(); ngoIter != ngoMap.end(); ngoIter++){
			Belief_NGOSite* ngo = static_cast<Belief_NGOSite*>(ngoIter->second.get());
			gm->gridToWorld(ngo->getCells()[0].getCol(), ngo->getCells()[0].getRow(), tempX, tempZ);
			cout << "NGO Site: id=" << ngo->getId() << ", position=(" << tempX << ",0," << tempZ << ")";
			cout << ", suppliesRemaining=" << ngo->getSupplies() << ", casualtiesAvailable=" << ngo->getCasualties() << 
				", civiliansTaken=" << ngo->getCivilians();
			cout << ", timestamp=" << ngo->getBeliefTime() << endl;
		}

		// Print out village information
		std::map<int, soa_shared_ptr<Belief> > villageMap = dm->getAllBeliefs(Belief::VILLAGE);
		std::map<int, soa_shared_ptr<Belief> >::iterator villageIter;
		for(villageIter = villageMap.begin(); villageIter != villageMap.end(); villageIter++){
			Belief_Village* village = static_cast<Belief_Village*>(villageIter->second.get());
			gm->gridToWorld(village->getCells()[0].getCol(), village->getCells()[0].getRow(), tempX, tempZ);
			cout << "Village: id=" << village->getId() << ", position=(" << tempX << ",0," << tempZ << ")"; 
			cout << ", suppliesRemaining=" << village->getSupplies() << ", casualtiesAvailable=" << village->getCasualties();
			cout << ", timestamp=" << village->getBeliefTime() << endl;
		}

		// Print out actor information
		std::map<int, soa_shared_ptr<Belief> > actorMap = dm->getAllBeliefs(Belief::ACTOR);
		std::map<int, soa_shared_ptr<Belief> >::iterator actorIter;
		for(actorIter = actorMap.begin(); actorIter!= actorMap.end(); actorIter++){
			Belief_Actor* actor = static_cast<Belief_Actor*>(actorIter->second.get());

			// ID
			cout << "Actor: id=" << actor->getId();

			// Alive or not
			string aliveStatus;
			if(actor->getIsAlive()){
				aliveStatus = "Alive";
			}else{
				aliveStatus = "Destroyed";
			}
			cout << ", status=" << aliveStatus;

			// Affiliation
			string affiliation;
			switch(actor->getAffiliation()){
				case 0:
					affiliation = "Blue";
					break;
				case 1:
					affiliation = "Red";
					break;
				case 2:
					affiliation = "Neutral";
					break;
				case 3:
					affiliation = "Unclassified";
					break;
				default:
					affiliation = "Invalid";
					break;
			}
			cout << ", affiliation=" << affiliation;

			// Type of actor
			string actorType;
			switch(actor->getType()){
				case 0: // Base
					actorType = "Base";
					break;
				case 1: // Small UAV
					actorType = "Small UAV";
					break;
				case 2: // Heavy UAV
					actorType = "Heavy UAV";
					break;
				case 3: // Dismount
					actorType = "Dismount";
					break;
				case 4: // Truck
					actorType = "Truck";
					break;
				case 5: // Police
					actorType = "Police";
					break;
				case 6: // Balloon
					actorType = "Balloon";
					break;
				default:
					actorType = "Invalid";
					break;
			}
			cout << ", type=" << actorType;

			// Coordinates
			cout << ", position=(" << actor->getPos_x() << "," << actor->getPos_y() << "," 
				<< actor->getPos_z() << ")";
			cout << ", velocityValid=" << actor->getVelocity_x_valid() && 
				actor->getVelocity_y_valid() && actor->getVelocity_z_valid();
			cout << ", velocity=(" << actor->getVelocity_x() << "," << actor->getVelocity_y() << "," 
				<< actor->getVelocity_z() << ")";

			// Actor-specific information
			switch(actor->getType()){
				case 0: // Base
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					break;
				case 1: // Small UAV
					cout << ", fuelRemaining=" << actor->getFuelRemaining();		
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					break;
				case 2: // Heavy UAV
					cout << ", fuelRemaining=" << actor->getFuelRemaining();
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					cout << "\t\ttotalStorage=" << actor->getNumStorageSlots() <<
						", availableStorage=" << actor->getNumFreeSlots() <<
						", casualtiesStored=" << actor->getNumCasualtiesStored() <<
						", suppliesStored=" << actor->getNumSuppliesStored() << endl;
					break;
				case 3: // Dismount
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					cout << "\t\t" << "isWeaponized=" << actor->getIsWeaponized() << 
						", totalStorage=" << actor->getNumStorageSlots() <<
						", availableStorage=" << actor->getNumFreeSlots() <<
						", civiliansStored=" << actor->getNumCiviliansStored() << endl;			
					break;
				case 4: // Truck
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					cout << "\t\t" << "isWeaponized=" << actor->getIsWeaponized() << 
						", hasJammer=" << actor->getHasJammer() << 
						", totalStorage=" << actor->getNumStorageSlots() <<
						", availableStorage=" << actor->getNumFreeSlots() <<
						", civiliansStored=" << actor->getNumCiviliansStored() <<endl;
					break;
				case 5: // Police
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					break;
				case 6: // Balloon
					cout << ", timestamp=" << actor->getBeliefTime() << endl;
					break;
			}
		}

		// Wait a while before polling for information again
		SLEEP(500);
	}
}


/**Autonomy behavior functions called from main for Heavy Lift UAV
 *
 * Creates a waypointlist from all NGOsites/villages with a waypoint to the base
 * following each village or NGO waypoint.  Follows the next waypoint in the list until the
 * actor is within waypointAchivedDistance.  Then goes to next waypoint in the list.
 * If at the end of the list, start from the beginning.
 *
 */
void heavyLiftUavBehavior(int actorId, string roomname)
{
	printf("Initializing heavy data manager\n");
	//Create your data manager for this agent
	printf("*************I AM %d\n", actorId);
	WorldDataManager * dm = WorldDataManager::create(actorId, roomname);

	//Uncomment to print all beliefs as they are added to the DataManager
	//dm->setPrintAddedBeliefs(true);

	float myPos_x;
	float myPos_y;
	float myPos_z;

	float goal_x;
	float goal_y;
	float goal_z;

	//uint64_t gameTime = TimeManager::getTimeManager()->getCurrentTime();

	/*
	 * Create waypoint list once beliefs about the environment are received
	 */

	std::vector<waypoint> waypointList;
	while(1)
	{

		std::map<int, soa_shared_ptr<Belief> > baseMap = dm->getAllBeliefs(Belief::BASE);
		GridMath * gm = dm->getGridMath();
		if(baseMap.size()>0 && gm != NULL)
		{
			soa_shared_ptr<Belief> basePtr = baseMap.begin()->second;
			Belief_Base * base = static_cast<Belief_Base *>(basePtr.get());
			float baseX = 0;
			float baseZ = 0;
			gm->gridToWorld(base->getCells()[0].getCol(),base->getCells()[0].getRow(), baseX, baseZ);

			std::map<int, soa_shared_ptr<Belief> > NGOSiteMap = dm->getAllBeliefs(Belief::NGOSITE);
			std::map<int, soa_shared_ptr<Belief> > villageMap = dm->getAllBeliefs(Belief::VILLAGE);

			std::map<int, soa_shared_ptr<Belief> >::iterator ngoiter = NGOSiteMap.begin();
			std::map<int, soa_shared_ptr<Belief> >::iterator viter = villageMap.begin();

			float ngoX, ngoZ;
			float villageX, villageZ;
			while(ngoiter != NGOSiteMap.end() || viter != villageMap.end())
			{
				if(ngoiter != NGOSiteMap.end())
				{
					Belief_NGOSite * ngoSite = static_cast<Belief_NGOSite *>(ngoiter->second.get());
					gm->gridToWorld(ngoSite->getCells()[0].getCol(), ngoSite->getCells()[0].getRow(), ngoX, ngoZ);
					waypointList.push_back(waypoint{ngoX, ngoZ});
					waypointList.push_back(waypoint{baseX, baseZ});
					ngoiter++;
				}

				if(viter != villageMap.end())
				{
					Belief_Village * villageSite = static_cast<Belief_Village *>(viter->second.get());
					gm->gridToWorld(villageSite->getCells()[0].getCol(), villageSite->getCells()[0].getRow(), villageX, villageZ);
					waypointList.push_back(waypoint{villageX, villageZ});
					waypointList.push_back(waypoint{baseX, baseZ});
					viter++;

				}
			}

			break;
		}

		SLEEP(1000);
	}

	printf("Entering main loop\n");

	vector<waypoint>::iterator waypointIter = waypointList.begin();

	/**
	 * Main loop of behvior
	 */
	while (1) {

/*
			PrintAllBeliefsType("BASE", dm->getAllBeliefs(Belief::BASE));
			PrintAllBeliefsType("GRIDSPEC", dm->getAllBeliefs(Belief::GRIDSPEC));
			PrintAllBeliefsType("TERRAIN", dm->getAllBeliefs(Belief::TERRAIN));
			PrintAllBeliefsType("NGOSITE", dm->getAllBeliefs(Belief::NGOSITE));
			PrintAllBeliefsType("VILLAGE", dm->getAllBeliefs(Belief::VILLAGE));
*/

		SLEEP(1000);

		float waypointAchivedDistance = .5f;
		//Access your actor belief
		soa_shared_ptr<Belief> myActorPtr = dm->getBelief(Belief::ACTOR,actorId);
		if(myActorPtr.get()==NULL)
		{
			printf("No belief for actor id %d\n", actorId);
			continue;
		}

		printf("Have actor belief\n");
		Belief_Actor * myActor = static_cast<Belief_Actor *>(myActorPtr.get());
		myPos_x = myActor->getPos_x();
		myPos_y = myActor->getPos_y();
		myPos_z = myActor->getPos_z();

		printf("Actor position: %f %f %f\n", myPos_x, myPos_z, myPos_y);
		//Find nearest red
		double distance = sqrt(pow((*waypointIter).x -myPos_x,2)+pow((*waypointIter).z -myPos_z,2));

		if(distance < waypointAchivedDistance)
		{
			waypointIter++;
			if(waypointIter == waypointList.end())
			{
				waypointIter = waypointList.begin();
			}
		}

		goal_x = (*waypointIter).x;
		goal_y = myPos_y;
		goal_z = (*waypointIter).z;

		printf("Commanding Waypoint %f %f %f\n", goal_x, goal_z, goal_y);
		Belief_Waypoint* waypoint = new Belief_Waypoint(TimeManager::getTimeManager()->getCurrentTime(), actorId, goal_x, goal_y, goal_z);
		dm->addBelief(waypoint);
	}
}


/**
 * Travel horizontally back and forth across he map with z coordinate set to 0.
 * If actor detects a red force, follow the nearest detected red force.
 */
static void smallUavBehavior(int actorId, string roomname)
{
	printf("Initializing data manager\n");
	//Create your data manager for this agent
	WorldDataManager* dm = WorldDataManager::create(actorId, roomname);

	//Uncomment to print all beliefs as they are added to the DataManager
	//dm->setPrintAddedBeliefs(true);

	float myPos_x;
	float myPos_y;
	float myPos_z;

	float goal_x;
	float goal_y;
	float goal_z;

	//uint64_t gameTime = TimeManager::getTimeManager()->getCurrentTime();

	printf("Entering main loop\n");
	//Go north or "Chase the nearest red" behavior
	//int count = 1;
	float translationDirectionX = 1;

	/**
	 * Hello world autonomy algorithm below
	 * Vehicle will be commanded to go north until z coordinate is greater than 20.
	 * Vehicle will then be command south until z coordinate is less than -20
	 * If at any time a red vehicle is sensed, chase the nearest red vehicle.
	 */
	while (1) {

		/*
		 * Print all beliefs about environment
		 * base, gridspec, terrain, ngo, village, roadcell.
		 * Set if statement to true to see this information.
		 */
		if(false)
		{
			PrintAllBeliefsType("BASE", dm->getAllBeliefs(Belief::BASE));
			PrintAllBeliefsType("GRIDSPEC", dm->getAllBeliefs(Belief::GRIDSPEC));
			PrintAllBeliefsType("TERRAIN", dm->getAllBeliefs(Belief::TERRAIN));
			PrintAllBeliefsType("NGOSITE", dm->getAllBeliefs(Belief::NGOSITE));
			PrintAllBeliefsType("VILLAGE", dm->getAllBeliefs(Belief::VILLAGE));
		}

		//How to get a single belief of a BeliefType and id.
		//Choose your belief type, choose the correct id.
		//Call get belief and store result in a soa_shared_ptr<Belief>
		//get the belief from the shared pointer using static cast
		Belief::BeliefType type = Belief::BASE;
		int beliefId = 1;
		soa_shared_ptr<Belief> base = dm->getBelief(type, beliefId);

		//Check to make sure data is not null
		if(base.get()!=NULL)
		{
			Belief_Base* baseBelief = static_cast<Belief_Base*>(base.get());
			//Use the information in the belief...
			baseBelief->getCells();
		}


		//If one of your functions needs to return a beleif,
		//Only return soa_shared_ptr of beliefs, never return the actual pointer because
		//That pointer may get deleted by another thread.

		SLEEP(1000);

		//Access your actor belief
		soa_shared_ptr<Belief> myActorPtr = dm->getBelief(Belief::ACTOR,actorId);
		if(myActorPtr.get()==NULL)
		{
			printf("No belief for actor id %d\n", actorId);
			continue;
		}

		printf("Have actor belief\n");
		Belief_Actor * myActor = static_cast<Belief_Actor *>(myActorPtr.get());
		myPos_x = myActor->getPos_x();
		myPos_y = myActor->getPos_y();
		myPos_z = myActor->getPos_z();

		printf("Actor position: %f %f %f\n", myPos_x, myPos_z, myPos_y);
		//Find nearest red
		bool hasGoal = false;
		double minDistance = 99999999999.0;

		//Get a std::map<int, soa_shared_ptr<Belief> > of all beliefs of type indicated by BeliefType argument
		std::map<int, soa_shared_ptr<Belief> > actorMap = dm->getAllBeliefs(Belief::ACTOR);
		std::map<int, soa_shared_ptr<Belief> >::iterator it;
		soa_shared_ptr<Belief> target;
		for(it = actorMap.begin(); it!= actorMap.end(); it++){
			//You could also check the type field of the actor_belief to make sure it is red
			Belief_Actor * otherActor = static_cast<Belief_Actor *>(it->second.get());
			if(otherActor->getAffiliation() == 1){
				Belief_Actor * redActor = otherActor;
				double distanceXY = sqrt(powf((myPos_x-redActor->getPos_x()),2)+powf((myPos_z-redActor->getPos_z()),2));
				if(distanceXY<minDistance){
					hasGoal = true;
					minDistance = distanceXY;
					goal_x = redActor->getPos_x();
					goal_y = myActor->getPos_y();
					printf("Red actor id %d %d %d\n", redActor->getId(), redActor->getAffiliation(), redActor->getIsAlive());
					goal_z = redActor->getPos_z();
					target = it->second;
				}
			}
		}


		//if no red, go north 1
		if(!hasGoal){
			printf("Actor has no goal, moving laterally\n");
			goal_z = 0;
			goal_y = myPos_y;

			if(myPos_x > 20)
			{
				translationDirectionX = -1;
			}else if(myPos_x < -20)
			{
				translationDirectionX = 1;
			}

			goal_x = myPos_x + 5 * translationDirectionX;
		}else{
			Belief_Actor * targetActor = static_cast<Belief_Actor *>(target.get());
			printf("Actor has goal %f %f %f\n", goal_x, goal_y, goal_z);
			printf("Chasing %d %d\n", targetActor->getId(), targetActor->getAffiliation());
		}

		Belief_Waypoint* waypoint = new Belief_Waypoint(TimeManager::getTimeManager()->getCurrentTime(), actorId, goal_x, goal_y, goal_z);
		dm->addBelief(waypoint);

		/*	Code for pointing the sensor.  The sensor is currently sphere shaped so pointing has no effect.
		 *
		 * Belief_SPOI * spoi = new Belief_SPOI(TimeManager::getTimeManager()->getCurrentTime(), actorId, goal_x, goal_y, goal_z);
		 * dm->addBelief(spoi);
		 */
	}


}

/*
 * Uses to string function of belief to print all the beliefs in the belief map argument.
 * Use this function for debugging belief data/connectivity.
 */
static void PrintAllBeliefsType(string beliefTypeName, std::map<int, soa_shared_ptr<Belief> > beliefMap) {
	printf("BeliefType %s\n", beliefTypeName.c_str());
	std::map<int, soa_shared_ptr<Belief> >::iterator itr = beliefMap.begin();
	while (itr != beliefMap.end()) {
		printf("%s\n", (itr->second).get()->toString().c_str());
		itr++;
	}
}


/**
 *	Send random data to the server.  All agents connect should receive this data.
 *	setPrintAddedBeliefs is set.  Beliefs will only be added when recieved from the photon server in this test.
 *	Run two instances of this function for test.
 */
static void RandomDataConnectivityTest(int id) {
	// Source ID
		int sourceID = 0;

		// Create managers
		WorldDataManager* dm = WorldDataManager::create(1,"soa-testroom-blue");
		dm->setPrintAddedBeliefs(true);
		// Pointer to created beliefs
		Belief* b;

		// Wait a little while
		SLEEP(500);

		int randCase = -1;
		int i=0;

		while(1){
	//	while(i < 5){
	//		i++;

			// Create 64 bit time field
			uint64_t randTime = rand();
			randTime = (randTime << 32) | rand();

			// Create and send beliefs
			randCase = (randCase + 1) % 12;
			//randCase = 3;
			switch(randCase){
			case 0:
				{
					b = new Belief_Actor(0, rand(), rand(), true, rand(), rand(), rand(), rand(), 
						true, true, (float)rand()+0.1234f, 
						(float)rand()+0.1234f, (float)rand()+0.1234f, (float)rand()+0.1234f,
						true, (float)rand()+0.1234f,
						false, (float)rand()+0.1234f,
						true, (float)rand()+0.1234f);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 1:
				{
					vector<GridCell> l;
					GridCell c1(rand(), rand());
					GridCell c2(rand(), rand());
					GridCell c3(rand(), rand());
					l.push_back(c1);
					l.push_back(c2);
					l.push_back(c3);
					b = new Belief_Base(rand(), l, rand());
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 2:
				{
					b = new Belief_GridSpec(rand(), rand(), rand(), rand(), 1.0f);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 3:
				{
					b = new Belief_Mode_Command(randTime, rand(), rand());
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 4:
				{
					vector<GridCell> l;
					GridCell c1(rand(), rand());
					GridCell c2(rand(), rand());
					GridCell c3(rand(), rand());
					l.push_back(c1);
					l.push_back(c2);
					l.push_back(c3);
					b = new Belief_NGOSite(rand(), l, rand(), rand(), rand());
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 5:
				{
					GridCell c(rand(), rand());
					b = new Belief_RoadCell(true, c);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 6:
				{
					b = new Belief_SPOI(randTime, rand(), (float)rand()+0.1234f, (float)rand()+0.1234f, (float)rand()+0.1234f);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 7:
				{
					vector<GridCell> l;
					GridCell c1(rand(), rand());
					GridCell c2(rand(), rand());
					GridCell c3(rand(), rand());
					l.push_back(c1);
					l.push_back(c2);
					l.push_back(c3);
					b = new Belief_Terrain(rand(), l);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 8:
				{
					b = new Belief_Time(randTime);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 9:
				{
					vector<GridCell> l;
					GridCell c1(rand(), rand());
					GridCell c2(rand(), rand());
					GridCell c3(rand(), rand());
					l.push_back(c1);
					l.push_back(c2);
					l.push_back(c3);
					b = new Belief_Village(rand(), l, rand(), rand());
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 10:
				{
					b = new Belief_Waypoint(randTime, rand(), (float)rand()+0.1234f, (float)rand()+0.1234f, (float)rand()+0.1234f);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			case 11:
				{
					b = new Belief_Waypoint_Override(randTime, rand(), (float)rand()+0.1234f, (float)rand()+0.1234f, (float)rand()+0.1234f);
					cout << "Test: Source ID " << sourceID << " Enqueueing belief type " << b->getBeliefType() << endl << b->toString() << endl;
					dm->addBelief(b);
					break;
				}
			default:
				{
					cout << "Test: Unrecognized case" << endl;
					break;
				}
			}

			SLEEP(5000);
		}
		// Disconnect
		//cm.terminate();

		// Rest a bit before returning
		SLEEP(500);
}
