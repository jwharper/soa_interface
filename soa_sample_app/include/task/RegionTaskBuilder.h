/*
 * RegionTaskBuilder.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#include "task/RegionTask.h"
#include "task/TaskBuilder.h"

#ifndef API_TASK_REGIONTASKBUILDER_H_
#define API_TASK_REGIONTASKBUILDER_H_

namespace soa
{
	namespace task
	{
		class RegionTaskBuilder : public TaskBuilder
		{
		public:

			RegionTaskBuilder(TaskID id, TaskType::Value regionTaskType);

			RegionTaskBuilder(const RegionTask& toCopy);

			virtual ~RegionTaskBuilder();

			virtual RegionTaskBuilder* clone() const;

			virtual void setRegion(soa::RegionPtr region);

			virtual void merge(TaskPtr older, TaskPtr newer);

		protected:

			RegionTask* regionTask() const;
		};
	}
}

#endif /* API_TASK_REGIONTASKBUILDER_H_ */
