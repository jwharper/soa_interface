#include "Belief.h"
#include "GridCell.h"
#include <vector>

#ifndef BELIEF_BASE_H
#define BELIEF_BASE_H

namespace soa{

class Belief_Base : public Belief{
private:
	std::vector<GridCell> cells;
	float supplies;

public:
	Belief_Base(int id, std::vector<GridCell> cells, float supplies);

	virtual ~Belief_Base(){};

	virtual Belief::BeliefType getBeliefType() const;

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	GridCell getGridLocation() const;

	std::vector<GridCell> getCells();

	float getSupplies();

};

}

#endif
