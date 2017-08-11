/*
 * Belief_TaskConstraint.h
 *
 *  Created on: Jun 8, 2017
 *      Author: harpejw1
 */

#include "Belief.h"
#include "Belief_Custom.h"

#include "task/TaskConstraint.h"

#ifndef API_BELIEF_TASKCONSTRAINT_H_
#define API_BELIEF_TASKCONSTRAINT_H_

namespace soa
{

	class Belief_TaskConstraint : public Belief_Custom
	{

	private:

		task::ConstraintPtr constraint;

	public:

		static const int Type = 0x0AF00000;

		Belief_TaskConstraint(int id, const task::TaskConstraint& constraint);

		Belief_TaskConstraint(int id, task::ConstraintPtr constraintPtr);

		virtual ~Belief_TaskConstraint();

		virtual BeliefPtr getCopy() const;

		virtual std::string toString();

		task::ConstraintPtr getConstraint() const;

	};
}



#endif /* API_BELIEF_TASKCONSTRAINT_H_ */
