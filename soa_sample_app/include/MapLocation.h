/*
 * MapLocation.h
 *
 *  Created on: Jul 23, 2016
 *      Author: harpejw1
 */

#include "GridMath.h"

#ifndef API_MAPLOCATION_H_
#define API_MAPLOCATION_H_

namespace soa
{
	class GridCell;
	class WorldLocation;

	class MapLocation
	{
	public:
		int m, n;

		MapLocation();

		MapLocation(int m, int n);

		bool isValid() const;

		WorldLocation convertToWorldLocation(GridMath* gridMath) const;

		GridCell convertToGridLocation(GridMath* gridMath) const;

		bool operator==(const MapLocation& other) const;

		bool operator!=(const MapLocation& other) const;

		bool operator<(const MapLocation& other) const;

		friend std::ostream& operator << (std::ostream& stream, const MapLocation& cell);

	};

	std::size_t hash_value(const GridCell& cell);
}

namespace std
{
	template<>
	struct hash<soa::MapLocation>
	{
		size_t operator()(const soa::MapLocation& location) const;
	};
}

#endif /* API_MAPLOCATION_H_ */
