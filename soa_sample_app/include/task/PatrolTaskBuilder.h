/*
 * PatrolTaskBuilder.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#include "task/PatrolTask.h"
#include "task/TaskBuilder.h"

#include "WorldLocation.h"

#ifndef API_TASK_PATROLTASKBUILDER_H_
#define API_TASK_PATROLTASKBUILDER_H_

namespace soa
{
	namespace task
	{
		class PatrolTaskBuilder : public TaskBuilder
		{
		public:

			PatrolTaskBuilder(TaskID id);

			PatrolTaskBuilder(const PatrolTask& toCopy);

			virtual ~PatrolTaskBuilder();

			virtual PatrolTaskBuilder* clone() const;

			virtual void setPath(soa::Belief_WaypointPath::WaypointPath path);

			virtual void addWaypointToPath(soa::WorldLocation waypoint);

			virtual void setWaypointIndex(size_t waypointIndex);

			virtual void setDirection(int direction);

			virtual void setNumberOfLaps(uint32_t numLaps);

			virtual void merge(TaskPtr older, TaskPtr newer);

		protected:

			PatrolTask* patrolTask() const;

		};
	}
}

#endif /* API_TASK_PATROLTASKBUILDER_H_ */
