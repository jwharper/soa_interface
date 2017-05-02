/*
 * MergePolicy.h
 *
 *  Created on: Aug 19, 2015
 *      Author: biggimh1
 */

#ifndef MERGEPOLICY_H_
#define MERGEPOLICY_H_
#include "Belief.h"
#include "soa_shared_ptr.h"

namespace soa {

class Belief;

	class MergePolicy
	{

		public:

			virtual ~MergePolicy() {}

			virtual BeliefPtr merge(BeliefPtr currentBelief, BeliefPtr incomingBeliefs) = 0;
	};

	typedef soa_shared_ptr<MergePolicy> MergePolicyPtr;

} // namespace



#endif /* MERGEPOLICY_H_ */
