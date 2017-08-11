/*
 * PointTask.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#include "task/Task.h"
#include "WorldLocation.h"

#ifndef API_TASK_POINTTASK_H_
#define API_TASK_POINTTASK_H_


namespace soa
{
	namespace task
	{
		class PointTaskBuilder;

		class PointTask : public Task
		{
		private:
			friend class PointTaskBuilder;

			soa::WorldLocation location;

		public:

			PointTask(TaskID id,
						TaskType::Value type);

			virtual ~PointTask();

			virtual PointTask* clone() const;

			virtual std::string serialize() const;

			virtual std::string toString() const;

			soa::WorldLocation getLocation() const;

		};
	}
}

#endif /* API_TASK_POINTTASK_H_ */
