#include"Girl.h"
#include"Message.h"
#include"MessageType.h"
#include"MessageDispatcher.h"
#include"MessageTestFunc.h"
#include<ctime>
void tellHerSomething(Girl *her)
{
	if(rand() % 100 <= 50)
	{
		Message to_study(0.0f, 
						-1/*匿名发送*/,
						her->getEntityId(),
						GO_TO_STUDY,
						nullptr);
		MsgDispatcher->sendMessage(&to_study);
	}
	else
	{
		Message to_play(0.0f, 
						-1/*匿名发送*/,
						her->getEntityId(),
						HAVE_A_REST,
						nullptr);
		MsgDispatcher->sendMessage(&to_play);
	}
}