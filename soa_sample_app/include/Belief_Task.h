/*
 * Belief_Task.h
 *
 *  Created on: Jun 6, 2017
 *      Author: harpejw1
 */

#ifndef API_BELIEF_TASK_H_
#define API_BELIEF_TASK_H_

#include "task/Task.h"
#include "Belief_Custom.h"

namespace soa
{

	class Belief_Task : public Belief_Custom
	{
	private:
		task::TaskPtr task;

	public:

		static const int Type = 0x0AE00000;

		Belief_Task(task::TaskPtr task);

		virtual ~Belief_Task();

		virtual BeliefPtr getCopy() const;

		virtual std::string toString();

		task::TaskPtr getTask() const;
	};

}



#endif /* API_BELIEF_TASK_H_ */
