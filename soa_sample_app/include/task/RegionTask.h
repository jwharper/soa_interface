/*
 * RegionTask.h
 *
 *  Created on: Feb 17, 2017
 *      Author: harpejw1
 */

#include "task/Task.h"
#include "Region.h"

#ifndef API_TASK_REGIONTASK_H_
#define API_TASK_REGIONTASK_H_

namespace soa
{
	namespace task
	{
		class RegionTaskBuilder;

		class RegionTask : public Task
		{
		private:
			friend class RegionTaskBuilder;

			soa::RegionPtr region;

		public:

			RegionTask(TaskID id,
						TaskType::Value type);

			virtual ~RegionTask();

			virtual RegionTask* clone() const;

			virtual std::string serialize() const;

			virtual std::string toString() const;

			soa::RegionPtr getRegion() const;

		};
	}

}



#endif /* API_TASK_REGIONTASK_H_ */
