/*
 * TrackTaskBuilder.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#include "task/TrackingTask.h"
#include "task/TaskBuilder.h"

#ifndef API_TASK_TRACKINGTASKBUILDER_H_
#define API_TASK_TRACKINGTASKBUILDER_H_

namespace soa
{
	namespace task
	{
		class TrackingTaskBuilder : public TaskBuilder
		{
		public:

			TrackingTaskBuilder(TaskID id);

			TrackingTaskBuilder(const TrackingTask& toCopy);

			virtual ~TrackingTaskBuilder();

			virtual TrackingTaskBuilder* clone() const;

			virtual void setTargetID(int targetID);

			virtual void merge(TaskPtr older, TaskPtr newer);

		protected:

			TrackingTask* trackingTask() const;
		};
	}
}

#endif /* API_TASK_TRACKINGTASKBUILDER_H_ */
