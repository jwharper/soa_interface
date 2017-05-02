/*
 * Belief_NoFlyZon.h
 *
 *  Created on: Jul 28, 2016
 *      Author: harpejw1
 */

#include "Region.h"

#ifndef API_BELIEF_NOFLYZONE_H_
#define API_BELIEF_NOFLYZONE_H_

namespace soa
{

	class Belief_NoFlyZone : public Belief_Custom
	{
	public:
		static const int Type = 0x01000000;

	protected:
		RegionPtr region;

	public:
		Belief_NoFlyZone(int zoneID, RegionPtr region);

		RegionPtr getRegion() const;

		bool contains(WorldLocation location) const;
	};
}

#endif /* API_BELIEF_NOFLYZONE_H_ */
