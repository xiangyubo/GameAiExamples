#include"Timer.h"
#include<windows.h>	//����#include<Windows.h>
#pragma comment( lib,"winmm.lib" )	//��������ĳ����̬��
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