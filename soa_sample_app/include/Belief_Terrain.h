#include "Belief.h"
#include "GridCell.h"
#include <vector>

#ifndef BELIEF_TERRAIN_H
#define BELIEF_TERRAIN_H

namespace soa{

class Belief_Terrain : public Belief{
public:
	enum Terrain {NONE = 0, MOUNTAIN=1, WATER=2};
	typedef std::vector<GridCell>::const_iterator CellIterator;

private:
	Terrain type;
	std::vector<GridCell> cells;

public:
	Belief_Terrain(int type, std::vector<GridCell> cells);

	virtual ~Belief_Terrain() {}

	Belief::BeliefType getBeliefType() const;

	virtual BeliefPtr getCopy() const;

	virtual string toString();

	int getType();

	Terrain getTerrainType() const;

	std::vector<GridCell> getCells();

	CellIterator begin() const;

	CellIterator end() const;
};

}

#endif
