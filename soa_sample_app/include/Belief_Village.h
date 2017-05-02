#include "Belief.h"
#include "GridCell.h"
#include "GridMath.h"
#include <vector>

#ifndef BELIEF_VILLAGE_H
#define BELIEF_VILLAGE_H

namespace soa{

class Belief_Village : public Belief{
private:
	std::vector<GridCell> cells;
	float supplies;
	float casualties;

public:
	Belief_Village(int id, std::vector<GridCell> cells, float supplies, float casualties);

	virtual ~Belief_Village() {}

	Belief::BeliefType getBeliefType() const ;

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	GridCell getGridLocation() const;

	std::vector<GridCell> getCells();

	float getSupplies();

	float getCasualties();
};

}

#endif
