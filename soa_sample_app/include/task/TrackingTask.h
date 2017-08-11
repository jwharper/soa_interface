/*
 * TrackingTask.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#include "task/Task.h"

#ifndef API_TASK_TRACKINGTASK_H_
#define API_TASK_TRACKINGTASK_H_

namespace soa
{
	namespace task
	{
		class TrackingTaskBuilder;

		class TrackingTask : public Task
		{
		private:
			friend class TrackingTaskBuilder;

			int targetID;

		public:

			TrackingTask(TaskID id);

			virtual ~TrackingTask();

			virtual TrackingTask* clone() const;

			virtual std::string serialize() const;

			virtual std::string toString() const;

			int getTargetID() const;

		};
	}

}


#endif /* API_TASK_TRACKINGTASK_H_ */
