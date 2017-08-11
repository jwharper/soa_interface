/*
 * AvoidThreatConstraint.h
 *
 *  Created on: Jun 6, 2017
 *      Author: harpejw1
 */

#ifndef API_TASK_AVOIDTHREATCONSTRAINT_H_
#define API_TASK_AVOIDTHREATCONSTRAINT_H_

#include "task/TaskConstraint.h"
#include "task/TaskConstraintBuilder.h"

namespace soa
{
	namespace task
	{
		class AvoidThreatConstraintBuilder;


		class AvoidThreatConstraint : public TaskConstraint
		{
		private:
			friend class AvoidThreatConstraintBuilder;

			int threatID;

		public:
			AvoidThreatConstraint();

			AvoidThreatConstraint(int threatID);

			virtual ~AvoidThreatConstraint();

			virtual std::string serialize() const;

			virtual AvoidThreatConstraint* clone() const;

			virtual ConstraintType::Value getType() const;

			int getThreatID() const;
		};

		class AvoidThreatConstraintBuilder : public TaskConstraintBuilder
		{
		public:

			AvoidThreatConstraintBuilder();

			AvoidThreatConstraintBuilder(const AvoidThreatConstraint& toCopy);

			virtual ~AvoidThreatConstraintBuilder();

			virtual AvoidThreatConstraintBuilder* clone() const;

			virtual AvoidThreatConstraintBuilder& avoid(int threatID);

		protected:

			virtual AvoidThreatConstraint* avoidThreatConstraint() const;
		};
	}
}

#endif /* API_TASK_AVOIDTHREATCONSTRAINT_H_ */
