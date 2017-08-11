/*
 * Region.h
 *
 *  Created on: Jul 28, 2016
 *      Author: harpejw1
 */

#include <string>
#include <vector>

#include "WorldLocation.h"
#include "soa_shared_ptr.h"

#ifndef INCLUDE_PLANNING_REGION_REGION_H_
#define INCLUDE_PLANNING_REGION_REGION_H_

namespace soa
{

	class Bounds
	{
	protected:
		WorldLocation min;
		WorldLocation max;
	public:
		/**
		 * Default bounds that contains no points
		 */
		Bounds();

		/**
		 * Specify the default bounds yourself
		 */
		Bounds(WorldLocation min, WorldLocation max);

		/**
		 * Grows the bounds to include the point
		 */
		void addPoint(WorldLocation location);

		/**
		 * Return true if the given point is within
		 * the bounds.
		 */
		bool contains(WorldLocation location) const;

		WorldLocation center() const;

		float minX() const;

		float maxX() const;

		float minZ() const;

		float maxZ() const;
	};



	class Region;
	typedef soa_shared_ptr<Region> RegionPtr;

	class Region
	{
	public:
		/**
		 * Returns an object that always returns
		 * false for contains(WorldLocation).
		 * i.e. uses null pattern
		 */
		static RegionPtr null();

		/**
		 * Returns an object that represents a
		 * circular region centered around the
		 * given point.
		 */
		static RegionPtr circle(WorldLocation center, float radius);

		/**
		 * Returns an object that represents
		 * arbitrary polygons. The order points
		 * should be in order (either clockwise
		 * or counter-clockwise) around the
		 * edge of the polygon.
		 */
		static RegionPtr polygon(const std::vector<WorldLocation>& orderedBoundary);

		/**
		 * Returns an object that represents a
		 * rectangular region where the smallest
		 * x/z are given by minBounds and the
		 * largest x/z are given by maxBounds.
		 */
		static RegionPtr rectangle(WorldLocation minBounds, WorldLocation maxBounds);

		virtual ~Region() {}

		/**
		 * Returns true if the given point is inside
		 * this region of space.
		 */
		virtual bool contains(WorldLocation location) const = 0;

		/**
		 * Returns a bounding box that contains
		 * the region.
		 */
		virtual Bounds bounds() const = 0;
	};
}

#endif /* INCLUDE_PLANNING_REGION_REGION_H_ */
