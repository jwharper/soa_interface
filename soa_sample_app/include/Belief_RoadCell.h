#include "Belief.h"
#include "GridCell.h"

#ifndef BELIEF_ROADCELL_H
#define BELIEF_ROADCELL_H

namespace soa{

class Belief_RoadCell : public Belief{
private:
	bool isRoadEnd;
	GridCell cell;

public:
	Belief_RoadCell(bool isRoadEnd, GridCell cell);

	virtual ~Belief_RoadCell(){}

	Belief::BeliefType getBeliefType() const;

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	bool getIsRoadEnd();

	GridCell getCell();
};

}

#endif
