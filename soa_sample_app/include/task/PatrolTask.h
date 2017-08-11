/*
 * PatrolTask.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#include "task/Task.h"
#include "Belief_WaypointPath.h"

#ifndef API_TASK_PATROLTASK_H_
#define API_TASK_PATROLTASK_H_

namespace soa
{
	namespace task
	{
		class PatrolTaskBuilder;

		class PatrolTask : public Task
		{
		private:
			friend class PatrolTaskBuilder;

			soa::Belief_WaypointPath::WaypointPath path;
			size_t waypointIndex;
			int direction;

		public:

			PatrolTask(TaskID id);

			virtual ~PatrolTask();

			virtual PatrolTask* clone() const;

			virtual std::string serialize() const;

			virtual std::string toString() const;

			soa::Belief_WaypointPath::WaypointPath getPath() const;

			size_t getPathLength() const;

			size_t getWaypointIndex() const;

			int getDirection() const;

		};
	}
}




#endif /* API_TASK_PATROLTASK_H_ */
