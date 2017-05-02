#include "Belief.h"
#include "TimeManager.h"
#include "WorldLocation.h"

#ifndef BELIEF_ACTOR_H
#define BELIEF_ACTOR_H

namespace soa{

class Belief_Actor : public Belief{

private:
    int affiliation;
    int type;
	bool isAlive;
	uint32_t numStorageSlots;
	uint32_t numCasualtiesStored;
	uint32_t numSuppliesStored;
	uint32_t numCiviliansStored;
	bool isWeaponized;
	bool hasJammer;
	float fuelRemaining;
    float pos_x;
    float pos_y;
    float pos_z;
	bool velocity_x_valid;
    float velocity_x;
	bool velocity_y_valid;
    float velocity_y;
	bool velocity_z_valid;
    float velocity_z;

public:
	Belief_Actor(int unique_id, int affiliation, int type, bool isAlive, 
		uint32_t numStorageSlots, uint32_t numCasualtiesStored,
		uint32_t numSuppliesStored, uint32_t numCivliansStored, 
		bool isWeaponized, bool hasJammer, float fuelRemaining, 
		float pos_x, float pos_y, float pos_z, 
		bool velocity_x_valid = false, float velocity_x = 0.0, 
		bool velocity_y_valid = false, float velocity_y = 0.0,
		bool velocity_z_valid = false, float velocity_z = 0.0);

	virtual ~Belief_Actor(){}

	Belief::BeliefType getBeliefType() const;

	int getUnique_id();
	int getAffiliation();
	int getType();
	bool getIsAlive();
	uint32_t getNumStorageSlots();
	uint32_t getNumCasualtiesStored();
	uint32_t getNumSuppliesStored();
	uint32_t getNumCiviliansStored();
	uint32_t getNumFreeSlots();
	bool getIsWeaponized();
	bool getHasJammer();
	float getFuelRemaining();
	float getPos_x();
	float getPos_y();
	float getPos_z();

	WorldLocation getPosition();

	bool getVelocity_x_valid();
	float getVelocity_x();
	bool getVelocity_y_valid();
	float getVelocity_y();
	bool getVelocity_z_valid();
	float getVelocity_z();

	enum ACTOR_TYPE{
		BASE=0,
		SMALLUAV=1,
		HEAVYLIFT=2,
		DISMOUNT=3,
		TRUCK=4,
		POLICE=5,
		BALLOON=6
	};

	enum AFFILIATION_TYPE{
		BLUE=0,
		RED=1,
		NEUTRAL=2,
		UNCLASSIFIED=3
	};

	virtual BeliefPtr getCopy() const;

	virtual std::string toString();
};

}

#endif
