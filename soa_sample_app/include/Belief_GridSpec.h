#include "Belief.h"

#ifndef BELIEF_GRIDSPEC_H
#define BELIEF_GRIDSPEC_H

namespace soa{

class Belief_GridSpec : public Belief{
private:
    int width;
    int height;
	float gridOrigin_x;
	float gridOrigin_z;
	float gridToWorldScale;

public:
	Belief_GridSpec(int width, int height,
		float gridOrigin_x, float gridOrigin_z, float gridToWorldScale);

	virtual ~Belief_GridSpec() {}

	Belief::BeliefType getBeliefType() const;

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	int getWidth();

	int getHeight();

	float getGridOrigin_x();

	float getGridOrigin_z();

	float getGridToWorldScale();
};

}

#endif
