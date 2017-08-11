/*
 * TaskConstraintBuilder.h
 *
 *  Created on: Jun 6, 2017
 *      Author: harpejw1
 */

#include <memory>

#include "Region.h"
#include "WorldDataManager.h"

#include "task/TaskConstraint.h"

#ifndef API_TASK_TASKCONSTRAINTBUILDER_H_
#define API_TASK_TASKCONSTRAINTBUILDER_H_

namespace soa
{
	namespace task
	{

		class TaskConstraintBuilder
		{
		protected:

			TaskConstraint* constraint;

			TaskConstraintBuilder(const TaskConstraint& constraint);


		public:

			TaskConstraintBuilder(const TaskConstraintBuilder&);

			TaskConstraintBuilder(TaskConstraintBuilder&&);

			virtual ~TaskConstraintBuilder();

			TaskConstraintBuilder& operator=(const TaskConstraintBuilder&);

			TaskConstraintBuilder& operator=(TaskConstraintBuilder&&);

			virtual TaskConstraintBuilder* clone() const = 0;

			virtual TaskConstraintBuilder& priority(Priority priority);

			virtual TaskConstraintBuilder& appliesToTask(TaskID task);

			virtual TaskConstraintBuilder& appliesToAll(std::vector<TaskID> tasks);

			virtual TaskConstraintBuilder& anytimeAfter(Time start);

			virtual TaskConstraintBuilder& anytimeBefore(Time end);

			virtual TaskConstraintBuilder& between(Time start, Time end);

			virtual std::unique_ptr<TaskConstraint> getConstraint() const;

			virtual void build(soa::WorldDataManager* wdm);
		};
	}
}



#endif /* API_TASK_TASKCONSTRAINTBUILDER_H_ */
