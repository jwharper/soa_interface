#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

#ifndef GRIDMATH_H
#define GRIDMATH_H

namespace soa{
	static std::string INVALID_GRID_MATH = "Grid math not initialized";

	// Unit basis vector (in world coordinates) defining hex grid u-axis direction
	// (Hard coded for now since grid type/axes are fixed)
	static const float uHat_x = sqrt(3.0f)/2.0f;
	static const float uHat_z = 1.0f/2.0f;

	// Unit basis vector (in world coordinates) defining hex grid v-axis direction
	// (Hard coded for now since grid type/axes are fixed)
	static const float vHat_x = 0.0f;
	static const float vHat_z = 1.0f;

	// This class contains static coordinate transform functions for converting between hex cell center 
	// (u,v) grid coordinates and world (x,z) coordinates
	class GridMath{
	private:
		// The grid coordinate origin (u=0, v=0) as expressed in world (x,z) coordinates
		float gridOrigin_x;
		float gridOrigin_z;
		float gridToWorldScale;

		// There is no round function in the standard C++ library
		float round(float x);

	public:

		// Constructor used to set scaling and offset values
		// gridOrigin_x - The x-component of grid coordinate origin (u=0, v=0) as expressed in world (x,z) coordinates
		// gridOrigin_z - The z-component of grid coordinate origin (u=0, v=0) as expressed in world (x,z) coordinates
		// gridToWorldScale - Length of a line (in world coordinates) that connects the centers of two adjacent hex cells
		GridMath(float gridOrigin_x, float gridOrigin_z, float gridToWorldScale);

		// Transforms a hex cell center (u,v) in grid coordinates to a point (x,z) in world coordinates
		// Based on reference: http://www.redblobgames.com/grids/hexagons/#hex-to-pixel
		void gridToWorld(int grid_u, int grid_v, float &world_x, float &world_z);

		// Transforms a point (x,z) in world coordinates to the (u,v) of the hex cell that contains it
		// Based on references: http://www.redblobgames.com/grids/hexagons/#pixel-to-hex
		//                      http://www.redblobgames.com/grids/hexagons/#rounding
		void worldToGrid(float world_x, float world_z, int &grid_u, int &grid_v);

		// Transforms a point (u,v) in grid coordinates to the corresponding point (m,n) in map coordinates
        static void gridToMap(int grid_u, int grid_v, int &map_m, int &map_n);

		// Transforms a point (m,n) in map coordinates to the corresponding point (u,v) in grid coordinates
        static void mapToGrid(int map_m, int map_n, int &grid_u, int &grid_v);

		// Convenience functions to not have to make two calls
		void worldToMap(float world_x, float world_z, int &map_m, int &map_n);

		void mapToWorld(int map_m, int map_n, float &world_x, float &world_z);

		float getGridToWorldScale() const { return gridToWorldScale; }
	};
}

#endif
