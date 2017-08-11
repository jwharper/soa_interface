/*
 * ResourceRequirement.h
 *
 *  Created on: Feb 17, 2017
 *      Author: harpejw1
 */

#include <string>

#include "task/RequirementID.h"
#include "task/Constants.h"

#ifndef API_TASK_RESOURCEREQUIREMENT_H_
#define API_TASK_RESOURCEREQUIREMENT_H_


namespace soa
{
	namespace task
	{
		namespace ResourceType
		{
			enum Value
			{
				CARGO_SUPPLIES,
				CARGO_CASUALTY,
				SENSOR_CAMERA,
				AGENT
			};

			std::string name(Value type);
		}

		typedef unsigned short RequirementID;

		class ResourceRequirement
		{

		protected:

			RequirementID id;
			ResourceType::Value type;
			int assignedAgent;
			Priority assignmentPriority;
			bool fulfilled;

		public:

			ResourceRequirement(RequirementID id, ResourceType::Value resourceType, bool fulfilled);

			ResourceRequirement(RequirementID id, int assignedAgent, bool fulfilled);

			ResourceRequirement(RequirementID id, ResourceType::Value resourceType, int assignedAgent, Priority priority, bool fulfilled);

			RequirementID getID() const;

			ResourceType::Value getType() const;

			int getAssignedAgent() const;

			Priority getAssignmentPriority() const;

			bool isFulfilled() const;

			std::string toString() const;
		};
	}
}

#endif /* API_TASK_RESOURCEREQUIREMENT_H_ */
