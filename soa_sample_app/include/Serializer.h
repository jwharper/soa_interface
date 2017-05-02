// For our sample belief messages
#include "Belief.h"
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
#include "Belief_Waypoint.h"
#include "Belief_Waypoint_Override.h"
#include <string>

#ifndef SERIALIZER_H
#define SERIALIZER_H

using std::string;

namespace soa{

class Serializer{
public:
	virtual ~Serializer() {}

	// Belief to serialized string
	virtual string serializeBelief(Belief* belief) = 0;

	// Serialized string to Belief conversion
	virtual Belief* generateBelief(string serial) = 0;
};

typedef soa_shared_ptr<Serializer> SerializerPtr;

}

#endif
