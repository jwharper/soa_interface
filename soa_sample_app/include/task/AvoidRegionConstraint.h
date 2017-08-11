/*
 * AvoidRegionConstraint.h
 *
 *  Created on: Jun 6, 2017
 *      Author: harpejw1
 */

#ifndef API_TASK_AVOIDREGIONCONSTRAINT_H_
#define API_TASK_AVOIDREGIONCONSTRAINT_H_

#include "Region.h"

#include "task/TaskConstraint.h"
#include "task/TaskConstraintBuilder.h"

namespace soa
{
	namespace task
	{
		class AvoidRegionConstraintBuilder;



		class AvoidRegionConstraint : public TaskConstraint
		{
		private:
			friend class AvoidRegionConstraintBuilder;

			soa::RegionPtr region;

		public:
			AvoidRegionConstraint();

			AvoidRegionConstraint(soa::RegionPtr region);

			virtual ~AvoidRegionConstraint();

			virtual AvoidRegionConstraint* clone() const;

			virtual ConstraintType::Value getType() const;

			soa::RegionPtr getRegion() const;

			std::string serialize() const;
		};



		class AvoidRegionConstraintBuilder : public TaskConstraintBuilder
		{
		public:

			AvoidRegionConstraintBuilder();

			AvoidRegionConstraintBuilder(const AvoidRegionConstraint& constraint);

			virtual ~AvoidRegionConstraintBuilder();

			virtual AvoidRegionConstraintBuilder* clone() const;

			virtual AvoidRegionConstraintBuilder& avoid(soa::RegionPtr region);

		private:

			AvoidRegionConstraint* avoidRegionConstraint() const;
		};
	}
}



#endif /* API_TASK_AVOIDREGIONCONSTRAINT_H_ */
