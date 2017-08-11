#include <string>
#include <sstream>
#include <vector>

#include "GridMath.h"

#ifndef GRIDCELL_H
#define GRIDCELL_H

namespace soa
{
	class WorldLocation;
	class MapLocation;

	class GridCell
	{
	private:
		int row;
		int col;

	public:
		GridCell();

		GridCell(int row, int col);

		GridCell(const GridCell &g);

		std::string toString();

		int getRow() const;

		int getCol() const;

		bool isValid() const;

		WorldLocation convertToWorldLocation(GridMath* gridMath) const;

		MapLocation convertToMapLocation(GridMath* gridMath) const;

		bool operator==(const GridCell& other) const;

		bool operator!=(const GridCell& other) const;

		bool operator<(const GridCell& other) const;

		friend std::ostream& operator << (std::ostream& stream, const GridCell& cell);

		std::vector<GridCell> neighbors() const;

		GridCell north() const;

		GridCell south() const;

		GridCell northEast() const;

		GridCell northWest() const;

		GridCell southEast() const;

		GridCell southWest() const;
	};

	std::size_t hash_value(const GridCell& cell);

}

namespace std
{
	template <>
	struct hash<soa::GridCell>
	{
		size_t operator()(const soa::GridCell& gridLocation) const;
	};
}

#endif
