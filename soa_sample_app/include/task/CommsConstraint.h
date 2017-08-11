/*
 * CommsConstraint.h
 *
 *  Created on: Jun 6, 2017
 *      Author: harpejw1
 */

#ifndef API_TASK_COMMSCONSTRAINT_H_
#define API_TASK_COMMSCONSTRAINT_H_

#include "task/TaskConstraint.h"
#include "task/TaskConstraintBuilder.h"

namespace soa
{
	namespace task
	{
		class CommsConstraintBuilder;



		class CommsConstraint : public TaskConstraint
		{
		private:
			friend class CommsConstraintBuilder;

			float maxDistance_Km;

		public:
			CommsConstraint(float maxDistance_Km);

			virtual ~CommsConstraint();

			virtual std::string serialize() const;

			virtual CommsConstraint* clone() const;

			virtual ConstraintType::Value getType() const;

			float getMaxDistance_Km() const;
		};

		class CommsConstraintBuilder : public TaskConstraintBuilder
		{
		public:

			CommsConstraintBuilder();

			CommsConstraintBuilder(const CommsConstraint& toCopy);

			virtual ~CommsConstraintBuilder();

			virtual CommsConstraintBuilder* clone() const;

			virtual CommsConstraintBuilder& maxDistance_Km(float maxDistance);

		protected:

			CommsConstraint* commsConstraint() const;
		};
	}
}

#endif /* API_TASK_COMMSCONSTRAINT_H_ */
