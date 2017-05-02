/*
 * WorldDataManager.h
 *
 *  Created on: Jul 13, 2016
 *      Author: harpejw1
 */

#include <string>
#include <vector>
#include <unordered_map>

#include "MergePolicy.h"
#include "soa_shared_ptr.h"
#include "Belief.h"
#include "GridMath.h"
#include "GridCell.h"
#include "Serializer.h"
#include "CustomBeliefHandler.h"

#ifndef API_WORLDDATAMANAGER_H_
#define API_WORLDDATAMANAGER_H_

namespace soa
{

	class TerrainMap
	{
	private:
		typedef std::unordered_map<GridCell, Belief_Terrain::Terrain> BackingType;
		BackingType map;
	public:

		TerrainMap();

		TerrainMap(const TerrainMap& toCopy);

		Belief_Terrain::Terrain getTerrain(GridCell cell) const;

		Belief_Terrain::Terrain& operator[](const GridCell& cell);

		BackingType::const_iterator find(GridCell cell) const;

		BackingType::const_iterator end() const;
	};

	class WorldDataManager
	{
	public:

		static WorldDataManager* create(int agentID, std::string roomname);

		virtual ~WorldDataManager() {}

		virtual void waitForInitialData() = 0;

		virtual void setDefaultMergePolicy(soa_shared_ptr<MergePolicy> defaultPolicy) = 0;

		virtual void setMergePolicyForType(Belief::Key key, soa_shared_ptr<MergePolicy> policy) = 0;

		virtual void setSerializerForType(Belief::Key key, SerializerPtr serializer) = 0;

		virtual void addBelief(Belief * b) = 0;

		virtual void addBelief(BeliefPtr b) = 0;

		virtual BeliefPtr getBelief(Belief::BeliefType, int id) = 0;

		virtual BeliefPtr getBelief(Belief::Key key, int id) = 0;

		virtual std::vector<int> getAllBeliefIds(Belief::BeliefType) = 0;

		virtual std::vector<int> getAllBeliefIds(Belief::Key) = 0;

		virtual std::map<int, BeliefPtr> getAllBeliefs(Belief::BeliefType) = 0;

		virtual std::map<int, BeliefPtr> getAllBeliefs(Belief::Key) = 0;

		virtual bool getGridHasRoad(const GridCell& cell) = 0;

		virtual void setPrintAddedBeliefs(bool b) = 0;

		virtual WorldLocation getNGOSiteLocation(int id) = 0;

		virtual WorldLocation getVillageLocation(int id) = 0;

		virtual WorldLocation getBlueBaseLocation() = 0;

		virtual WorldLocation getAgentLocation(int id) = 0;

		virtual Belief_Terrain::Terrain getTerrainType(const GridCell& cell) const = 0;

		virtual TerrainMap getAllTerrain() const = 0;

		virtual void addCustomBeliefHandler(const soa_shared_ptr<CustomBeliefHandler>& handler) = 0;

		/**
		 * Returns pointer to gridMath object that has been initialized from
		 * Belief_GridSpec.
		 *
		 * if object is not initialized, return NULL
		 */
		virtual GridMath * getGridMath() = 0;

		/*
		 * Return the grid cell of for the x, z coordinate
		 */
		virtual GridCell getGridCell(float x, float z) = 0;

		virtual bool getIsAlive() = 0;

		virtual int getAgentID() = 0;

		template <typename BeliefClass>
		soa_shared_ptr<BeliefClass> getTypedBelief(Belief::BeliefType type, int id)
		{
			return getTypedBelief<BeliefClass>(Belief::Key(type), id);
		}

		template <typename BeliefClass>
		soa_shared_ptr<BeliefClass> getTypedBelief(Belief::Key key, int id)
		{
			BeliefPtr belief = getBelief(key, id);
			BeliefClass* castPtr = dynamic_cast<BeliefClass*>(belief.get());
			if (castPtr == NULL) {
				return soa_shared_ptr<BeliefClass>();
			}
			return soa_shared_ptr<BeliefClass>(belief, castPtr);
		}

		template <typename BeliefClass>
		std::vector<soa_shared_ptr<BeliefClass>> getAllTypedBeliefs(Belief::Key key)
		{
			auto beliefMap = getAllBeliefs(key);
			std::vector<soa_shared_ptr<BeliefClass>> beliefs;
			beliefs.reserve(beliefMap.size());

			for (auto entry = beliefMap.begin(); entry != beliefMap.end(); ++entry)
			{
				BeliefPtr belief = entry->second;
				BeliefClass* castPtr = dynamic_cast<BeliefClass*>(belief.get());
				if (castPtr != NULL) {
					soa_shared_ptr<BeliefClass> sharedPtr = soa_shared_ptr<BeliefClass>(belief, castPtr);
					beliefs.push_back(sharedPtr);
				}
			}

			return beliefs;
		}
	};

}

#endif /* API_WORLDDATAMANAGER_H_ */
