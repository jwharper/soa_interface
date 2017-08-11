/*
 * TaskBuilder.h
 *
 *  Created on: Feb 17, 2017
 *      Author: harpejw1
 */

#include "task/TaskID.h"
#include "task/Constants.h"
#include "task/Task.h"
#include "task/RegionTask.h"
#include "task/PointTask.h"
#include "task/TrackingTask.h"
#include "task/PatrolTask.h"

#include "WorldDataManager.h"
#include "Belief_Task.h"

#ifndef API_TASK_TASKBUILDER_H_
#define API_TASK_TASKBUILDER_H_

namespace soa
{
	namespace task
	{
		class TaskBuilder
		{
		protected:
			Task* task;

			/**
			 * Constructor that allows you to
			 * create a new task object with
			 * some initial state. This will
			 * create a task with the same id
			 * and provides a way of modifying
			 * existing tasks.
			 *
			 * toCopy - existing task object to
			 * 			initialize the state of
			 * 			the new task
			 */
			TaskBuilder(const Task& toModify);

		public:

			TaskBuilder(const TaskBuilder& toCopy);

			TaskBuilder(TaskBuilder&& toMove);

			TaskBuilder& operator=(const TaskBuilder& toCopy);

			TaskBuilder& operator=(TaskBuilder&& toMove);

			/**
			 * Default destructor
			 */
			virtual ~TaskBuilder();

			/**
			 * Creates a deep copy of this object
			 * and returns a pointer to the new
			 * copy. You are responsible for
			 * cleaning up the pointer.
			 */
			virtual TaskBuilder* clone() const = 0;

			/**
			 * Returns a copy of the Task object
			 * being built.
			 */
			virtual TaskPtr getTask() const final;

			/**
			 * Sets the start time of the task to timeMS
			 * and the end time to TimeConstants::EndOfTime
			 */
			virtual TaskBuilder& anyTimeAfter(Time timeMS);

			/**
			 * Sets the start time of the task to
			 * TimeConstants::BeginningOfTime and the end time
			 * to timeMS
			 */
			virtual TaskBuilder& anyTimeBefore(Time timeMS);

			/**
			 * Sets the start time of the task to startMS and the
			 * end time to endMS
			 */
			virtual TaskBuilder& anyTimeBetween(Time startMS, Time endMS);

			/**
			 * Sets the priority to PriorityConstants::Highest
			 */
			virtual TaskBuilder& highestPriority();

			/**
			 * Sets the priority to PriorityConstants::Lowest
			 */
			virtual TaskBuilder& lowestPriority();

			/**
			 * Sets the integer valued priority of this task
			 * relative to other tasks. The priority value
			 * must be between PriorityConstants::Highest
			 * and PriorityConstants::Lowest
			 */
			virtual TaskBuilder& setPriority(Priority priority);

			/**
			 * Sets whether the task is complete or not.
			 */
			virtual TaskBuilder& setFinished(bool isFinished);

			/**
			 * Adds n CargoRequirement objects to the task.
			 */
			virtual TaskBuilder& addCargoRequirements(ResourceType::Value cargoType, size_t n=1);

			/**
			 * Adds n SensorRequirement objects to the task.
			 */
			virtual TaskBuilder& addSensorRequirements(ResourceType::Value sensorType=ResourceType::SENSOR_CAMERA, size_t n=1);

			/**
			 * Adds a requirement that the agent with agentID
			 * must be assigned to this task.
			 */
			virtual TaskBuilder& addAgentRequirement(int agentID);

			virtual TaskBuilder& setRequirementFinished(RequirementID id);

			/**
			 * Adds an existing resource requirement to this task.
			 * This should really only be used for deserialization
			 * unless you know for sure what you are doing.
			 */
			virtual void addRequirement(const ResourceRequirement& toAdd);

			/**
			 * Assigns an agent to a resource requirement for this task.
			 * The given priority is mean to help resolve conflicts if
			 * more than one agents assigns themselves to the task.
			 */
			virtual TaskBuilder& assignAgentToResource(RequirementID reqID, int agentID, Priority priority);

			/**
			 * Finishes the construction of the tasks and submits
			 * it to the WorldDataManager.
			 */
			virtual TaskID build(soa::WorldDataManager* wdm);

			/**
			 * Merges the two tasks into the task that is
			 * being built. The merged task will override
			 * any changes previously made with the builder.
			 */
			virtual void merge(TaskPtr older, TaskPtr newer);

		protected:

			virtual RequirementID getNextReqID() const;

		};
	}
}



#endif /* API_TASK_TASKBUILDER_H_ */
