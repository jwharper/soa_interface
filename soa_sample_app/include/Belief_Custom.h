#include "Belief.h"

#ifndef BELIEF_CUSTOM_H
#define BELIEF_CUSTOM_H

namespace soa{

class Belief_Custom : public Belief{

public:
	Belief_Custom(int customType, int actorID, const char* data, int dataLength);

	Belief_Custom(const char* data, int dataLength);

	virtual ~Belief_Custom();

	virtual Belief::BeliefType getBeliefType() const final;

	virtual Belief::Key getBeliefKey() const final;

	virtual BeliefPtr getCopy() const;

	virtual std::string toString();

	virtual char* getData();

	virtual int getDataLength();

	virtual int getCustomBeliefType() const;

protected:

	void copy(const char* data);

	char* data;
	int dataLength;
	int customType;
};

}

#endif
