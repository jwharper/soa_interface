/*
 * CustomBeliefHandler.h
 *
 *  Created on: May 1, 2015
 *      Author: biggimh1
 */

#ifndef CUSTOMBELIEFHANDLER_H_
#define CUSTOMBELIEFHANDLER_H_

#include "Belief_Custom.h"
#include "soa_shared_ptr.h"

namespace soa
{

	class CustomBeliefHandler
	{
	public:

		virtual ~CustomBeliefHandler(){};

		virtual void processCustomBelief(soa_shared_ptr<Belief_Custom> belief) = 0;
	};

}

#endif /* CUSTOMBELIEFHANDLER_H_ */
