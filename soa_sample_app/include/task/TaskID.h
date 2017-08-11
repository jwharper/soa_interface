/*
 * TaskID.h
 *
 *  Created on: Feb 17, 2017
 *      Author: harpejw1
 */

#include <cstddef>
#include <functional>
#include <iostream>

#ifndef API_TASK_TASKID_H_
#define API_TASK_TASKID_H_

namespace soa
{
	namespace task
	{
		class TaskID
		{
		private:
			int creatorID;
			unsigned int instance;

		public:

			TaskID(int creatorID, unsigned int instance);

			int getCreatorID() const;

			unsigned int getInstance() const;

			int intHash() const;

			size_t hash() const;

			bool operator==(const TaskID& other) const;

		};
	}
}

namespace std
{
	std::ostream& operator<<(std::ostream& stream, const soa::task::TaskID& id);

	template <>
	struct hash<soa::task::TaskID>
	{
		size_t operator()(const soa::task::TaskID& key) const
		{
			return key.hash();
		}
	};
}

#endif /* API_TASK_TASKID_H_ */
