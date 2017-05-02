#include "Belief.h"
#include "GridCell.h"
#include <vector>

#ifndef BELIEF_NGOSITE_H
#define BELIEF_NGOSITE_H

namespace soa{

class Belief_NGOSite : public Belief{
private:
	std::vector<GridCell> cells;
	float supplies;
	float casualties;
	float civilians;

public:
	Belief_NGOSite(int id, std::vector<GridCell> cells, float supplies, float casualties, float civilians);

	virtual ~Belief_NGOSite() {}

	Belief::BeliefType getBeliefType() const;

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	GridCell getGridLocation() const;

	std::vector<GridCell> getCells();

	float getSupplies();

	float getCasualties();

	float getCivilians();
};

}

#endif
