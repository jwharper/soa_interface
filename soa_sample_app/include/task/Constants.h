/*
 * Types.h
 *
 *  Created on: May 9, 2017
 *      Author: harpejw1
 */

#ifndef API_TASK_CONSTANTS_H_
#define API_TASK_CONSTANTS_H_

namespace soa
{
	namespace task
	{
		typedef unsigned long Time;
		struct TimeConstants
		{
			static const Time BeginningOfTime;
			static const Time EndOfTime;
		};

		typedef unsigned short Priority;
		struct PriorityConstants
		{
			static const Priority Highest;
			static const Priority Normal;
			static const Priority Lowest;
		};
	}
}



#endif /* API_TASK_CONSTANTS_H_ */
