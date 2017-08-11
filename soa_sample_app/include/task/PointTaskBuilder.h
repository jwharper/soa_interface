/*
 * PointTaskBuilder.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#ifndef API_TASK_POINTTASKBUILDER_H_
#define API_TASK_POINTTASKBUILDER_H_

#include "task/TaskBuilder.h"
#include "task/PointTask.h"

namespace soa
{
	namespace task
	{
		class PointTaskBuilder : public TaskBuilder
		{
		public:

			PointTaskBuilder(TaskID id, TaskType::Value pointTaskType);

			PointTaskBuilder(const PointTask& toCopy);

			virtual ~PointTaskBuilder();

			virtual PointTaskBuilder* clone() const;

			virtual void setLocation(soa::WorldLocation location);

			virtual void merge(TaskPtr older, TaskPtr newer);

		protected:

			PointTask* pointTask() const;
		};
	}
}

#endif /* API_TASK_POINTTASKBUILDER_H_ */
