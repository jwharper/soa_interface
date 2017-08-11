/*
 * Task.h
 *
 *  Created on: Feb 17, 2017
 *      Author: harpejw1
 */

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "soa_shared_ptr.h"

#include "task/TaskID.h"
#include "task/ResourceRequirement.h"
#include "task/RequirementID.h"
#include "task/Constants.h"

#ifndef API_TASK_TASK_H_
#define API_TASK_TASK_H_

#define ENUM(name) const

namespace soa
{

	namespace task
	{
		class Task;
		class TaskBuilder;

		typedef ::soa_shared_ptr<Task> TaskPtr;

		namespace TaskType
		{
			enum Value
			{
				SEARCH,
				TRACK,
				DELIVERY,
				PICKUP,
				PATROL,
				DISPERSE,
				RALLY,
				PERIMETER,
				GOTO,		//
				ERROR
			};

			std::string name(Value type);

			std::unique_ptr<TaskBuilder> builder_for(TaskPtr task);

			std::unique_ptr<TaskBuilder> builder_for(TaskID id, Value type);
		}

		class Task
		{
		private:

			friend class TaskBuilder;

			typedef std::unordered_map<soa::task::RequirementID, ResourceRequirement> RequirementsMap;

			TaskID id;
			TaskType::Value type;
			Time start;
			Time end;
			Priority priority;
			RequirementsMap requirements;
			bool finished;

		public:

			/**
			 *	TaskType::Value type - The type that this task represents
			 *
			 *	Time start - The time at which the task should start.
			 *				 The value should be defined in milliseconds
			 *				 since epoch.
			 *
			 *	Time end - The time at which the task should end.
			 *				The value should be defined in milliseconds
			 *				since epoch.
			 *
			 *	Priority priority - The relative priority of this task vs.
			 *						other tasks.
			 *
			 */
			Task(TaskID id, TaskType::Value type, Time start, Time end, Priority priority);

			/**
			 * TaskID - An identifier for this task to distinguis it from other tasks.
			 *
			 * This constructor uses the following defaults:
			 * 		type
			 *
			 */
			Task(TaskID id, TaskType::Value type);


			virtual ~Task();

			/**
			 * Returns a copy of this task. You
			 * are now responsible for cleaning up
			 * the memory.
			 */
			virtual Task* clone() const = 0;

			/**
			 * Returns an object that can serialize this
			 * task into a byte array that can be sent
			 * across the network.
			 */
			virtual std::string serialize() const = 0;

			/**
			 * Makes a human-readable string to describe
			 * the current task.
			 */
			virtual std::string toString() const;

			/**
			 * Returns an identifier that uniquely represents
			 * this task object.
			 */
			virtual TaskID getID() const final;

			/**
			 * Returns one of the enumerated
			 * types of tasks. See soa::task::TaskType::Value
			 */
			virtual TaskType::Value getType() const final;

			/**
			 * Returns the time in milliseconds from epoch
			 * at which the task should start.
			 */
			virtual Time getStartTimeMS() const final;

			/**
			 * Returns the time in milliseconds from epoch
			 * at which the task should end.
			 */
			virtual Time getEndTimeMS() const final;

			/**
			 * Returns a priority value that allows
			 * the autonomy to determine which is
			 * more important in case of conflicting
			 * tasks.
			 */
			virtual Priority getPriority() const final;

			/**
			 * Returns true if this task is finished
			 * and can now be ignored.
			 */
			virtual bool isFinished() const final;

			/**
			 * Returns a list of the requirements for this task.
			 */
			virtual std::vector<ResourceRequirement> getRequirements() const final;

			/**
			 * Returns the number of requires for this task.
			 */
			virtual size_t getRequirementsCount() const final;

		};
	}
}

namespace std
{
	template<>
	struct hash<soa::task::TaskType::Value>
	{
		size_t operator()(const soa::task::TaskType::Value& type) const
		{
			return type;
		}
	};
}

#endif /* API_TASK_TASK_H_ */
