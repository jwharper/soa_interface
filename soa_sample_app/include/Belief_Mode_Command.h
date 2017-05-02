#include "Belief.h"
#include <cstdint>
#include <inttypes.h>

#ifndef BELIEF_MODE_COMMAND_H
#define BELIEF_MODE_COMMAND_H

namespace soa{

class Belief_Mode_Command : public Belief{
private:
	uint64_t request_time;
    int actor_id;
	int mode_id;

public:
	Belief_Mode_Command(uint64_t request_time, int actor_id, int mode_id);

	virtual ~Belief_Mode_Command() {}

	Belief::BeliefType getBeliefType() const;

	uint64_t getRequest_time();

	int getActor_id();

	int getMode_id();

	virtual BeliefPtr getCopy() const;

	virtual std::string toString();
};

}

#endif
