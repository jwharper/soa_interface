#include "Belief.h"
#include <cstdint>
#include <inttypes.h>

#ifndef BELIEF_TIME_H
#define BELIEF_TIME_H

namespace soa{

class Belief_Time : public Belief{
private:
	uint64_t time;

public:
	Belief_Time(uint64_t time);

	virtual ~Belief_Time() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getTime();

	virtual BeliefPtr getCopy() const;

	virtual string toString();
};

}

#endif
