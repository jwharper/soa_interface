/*
 * WorldLocation.h
 *
 *  Created on: Jul 23, 2016
 *      Author: harpejw1
 */

#include <ostream>

#include "GridMath.h"

#ifndef API_WORLDLOCATION_H_
#define API_WORLDLOCATION_H_

namespace soa
{
	class GridCell;
	class MapLocation;

	class WorldLocation
	{
	public:
		float x, y, z;

		WorldLocation();

		WorldLocation(float x, float y, float z);

		bool isValid() const;

		float distance(const WorldLocation& other) const;

		GridCell convertToGridLocation(GridMath* gridMath) const;

		MapLocation convertToMapLocation(GridMath* gridMath) const;

		WorldLocation add(WorldLocation location) const;

		WorldLocation subtract(WorldLocation location) const;

		friend std::ostream& operator<<(std::ostream& stream, const WorldLocation& location);
	};
}

#endif /* API_WORLDLOCATION_H_ */
