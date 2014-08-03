#include"Timer.h"
#include<windows.h>	//或者#include<Windows.h>
#pragma comment( lib,"winmm.lib" )	//用来链接某个静态库
Timer::Timer()
{
	startTime = timeGetTime() * 0.001;
}

Timer* Timer::getInstence()
{
	static Timer instence;
	return &instence;
}

double Timer::getCurrentTime()
{
	return timeGetTime() * 0.001 - startTime;
}