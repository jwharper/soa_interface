/*
 * TaskConstraint.h
 *
 *  Created on: Jun 6, 2017
 *      Author: harpejw1
 */

#include <unordered_set>
#include <vector>
#include <memory>

#include "task/Constants.h"
#include "task/Task.h"

#ifndef API_TASK_TASKCONSTRAINT_H_
#define API_TASK_TASKCONSTRAINT_H_

namespace soa
{
	namespace task
	{

		class TaskConstraintDeserializer;

		namespace ConstraintType
		{
			enum Value
			{
				AVOID_THREAT,
				AVOID_REGION,
				MAINTAIN_COMMS
			};

			std::string name(Value type);

			std::unique_ptr<TaskConstraintDeserializer> deserializer_for(Value type);
		}

		class TaskConstraint
		{
		private:
			friend class TaskConstraintBuilder;

			ConstraintType::Value type;
			Priority priority;
			std::unordered_set<TaskID> targetTasks;
			Time startTime;
			Time endTime;

		public:

			TaskConstraint(ConstraintType::Value);

			virtual ~TaskConstraint();

			virtual std::string serialize() const = 0;

			virtual TaskConstraint* clone() const = 0;

			virtual ConstraintType::Value getType() const;

			virtual Priority getPriority() const final;

			virtual Time getStartTime_ms() const final;

			virtual Time getEndTime_ms() const final;

			virtual bool applies(Time currentTime, std::vector<TaskID> assignedTasks) final;

			virtual std::unordered_set<TaskID> getTargetTasks() const;

			virtual size_t getTargetTaskCount() const;

			virtual std::string toString() const;
		};

		typedef soa_shared_ptr<TaskConstraint> ConstraintPtr;

	}
}



#endif /* API_TASK_TASKCONSTRAINT_H_ */
