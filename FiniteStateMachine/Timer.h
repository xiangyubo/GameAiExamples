#ifndef _TIMER_
#define _TIMER_

#define Clock Timer::getInstence()	//����ļ��ɣ���ס��

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