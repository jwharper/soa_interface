#ifndef __TIME_MANAGER_H
#define __TIME_MANAGER_H

#include <cstdint>
#include <sys/time.h>

namespace soa {

class TimeManager {
	public:
		static TimeManager* getTimeManager(){
			if(timeManager==0){
				timeManager = new TimeManager();
			}
			return timeManager;
		}

		//void setTime(uint64_t newTime){currentTime = newTime;}
		uint64_t getCurrentTime(){
			struct timeval tp;
			gettimeofday(&tp, 0);
			currentTime = (uint64_t) tp.tv_sec * 1000L + tp.tv_usec / 1000;
			return currentTime;}

	private:
		static TimeManager *timeManager;

		uint64_t currentTime;

		TimeManager(){currentTime = 0;}
};
}

#endif
