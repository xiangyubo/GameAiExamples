#ifndef _TIMER_
#define _TIMER_

#define Clock Timer::getInstence()	//不错的技巧，记住了

class Timer
{
private:
	double startTime;
public:
	static Timer* getInstence();
	double getCurrentTime();
private:
	Timer();
	Timer(const Timer& );
	Timer operator = (const Timer& );
};
#endif