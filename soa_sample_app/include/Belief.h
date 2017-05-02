// Added any include statement so that Visual Studio does not give PCH warning error 
#include <iostream>
#include <string>
#include "TimeManager.h"
#include <string>
#include <sstream>
#include <time.h>
#include <map>

#include "soa_shared_ptr.h"

#include "MergePolicy.h"

//#define _EG_WINDOWS_PLATFORM
#define _EG_LINUX_PLATFORM
#if defined _EG_LINUX_PLATFORM
#define __STDC_FORMAT_MACROS
#endif

#if defined _EG_WINDOWS_PLATFORM
#	define snprintf(a,b,...) _snprintf_s(a,b,b,__VA_ARGS__)
#else
#include <sys/time.h>
#endif

#ifndef BELIEF_H
#define BELIEF_H

using namespace std;

namespace soa{

class MergePolicy;

class Belief{
private:

public:

	enum BeliefType {
		INVALID = 0,
        	ACTOR, 
        	BASE, 
			CASUALTY_DELIVERY,
			CASUALTY_PICKUP,
        	GRIDSPEC,
        	MODE_COMMAND,
			NGOSITE, 
	    	ROADCELL, 
	    	SPOI, 
			SUPPLY_DELIVERY,
			SUPPLY_PICKUP,
        	TERRAIN,
        	TIME,
       	 	VILLAGE, 
       	 	WAYPOINT, 
			WAYPOINT_OVERRIDE,
			WAYPOINT_PATH,
			CUSTOM,
			TARGET,
			SINK,
			SOURCE,
			DESIRED_SITE,
			SEARCH_AREA,
			TELEOP
	};

	static std::string nameOf(BeliefType type);

	class Key
	{
	public:
		Key() : type(INVALID), customType(0) {}

		Key(BeliefType _type) : type(_type), customType(0) {}

		Key(int _customType) : type(Belief::CUSTOM), customType(_customType) {}

		bool operator== (const Key& other) const;

		bool operator!= (const Key& other) const;

		BeliefType getType() const { return type; }

		int getCustomType() const { return customType; }

	private:
		friend struct std::hash<Key>;
		friend bool operator < (const Key& key1, const Key& key2);
		friend ostream& operator << (ostream& stream, const Key& key);

		BeliefType type;
		int customType;
	};

	Belief(int id);

	virtual ~Belief(){};

	virtual Key getBeliefKey() const { return Key(getBeliefType()); }

	virtual Belief::BeliefType getBeliefType() const;

	virtual int getId() const {return myId;}

	virtual soa_shared_ptr<Belief> getCopy() const = 0;

	virtual string toString();

	virtual uint64_t getBeliefTime() const { return beliefTime; }

	virtual void setBeliefTime(uint64_t beliefTime) {this->beliefTime = beliefTime;}

protected:
	int myId;
	uint64_t beliefTime;
};

typedef soa_shared_ptr<Belief> BeliefPtr;
typedef std::map<Belief::Key, std::map<int,BeliefPtr> > BeliefMap;

 ostream& operator << (ostream& stream, const Belief::Key& key);
 bool operator < (const Belief::Key& key1, const Belief::Key& key2);
}

namespace std
{
	template <>
	struct hash<soa::Belief::Key>
	{
		size_t operator()(const soa::Belief::Key& key) const
		{
			return std::hash<int>()((int)key.type) + (std::hash<int>()(key.customType) << 8);
		}
	};
}

#endif
