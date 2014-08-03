#include"Girl.h"
#include"Message.h"
#include"MessageType.h"
#include"EntityManager.h"
#include"MessageDispatcher.h"
#include"MessageTestFunc.h"

#include<ctime>
#include<iomanip>
#include<iostream>
#include<windows.h>
int main()
{
	Girl zpl("zpl");
	EntityManager::getInstence()->registerEntity(&zpl);
	srand((unsigned)time(NULL));
	for(int tick = 0; tick < 240; ++tick)
	{
		std::cout<<"现在时间："<<std::setfill('0')<<std::setw(2)<<tick/10<<":"<<std::setfill('0')<<std::setw(2)<<(tick%10)*6<<"	";
		zpl.update();
		if(tick % 20 == 0)
		{
			tellHerSomething(&zpl);
		}
		MsgDispatcher->sendMessageDelay();
		Sleep(800);
	}
	return 0;
}