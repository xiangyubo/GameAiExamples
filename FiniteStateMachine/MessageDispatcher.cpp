#include"GameEntity.h"
#include"MessageDispatcher.h"
#include"Message.h"
#include"EntityManager.h"
#include"Timer.h"	//�����Support�ļ���ֻ���߼��ϵ�
#include<iostream>	//ʵ���ϲ����ڣ����԰���·�����ǵ�ǰ�ļ�����
MessageDispatcher::MessageDispatcher()
{
	
}

MessageDispatcher * MessageDispatcher::getInstence()
{
	static MessageDispatcher instence;
	return &instence;;
}

void MessageDispatcher::sendMessage(Message *msg)
{
	if(msg->getDelay() < 0.001)
	{
		send(msg);
	}
	else
	{
		msg->setSendTime(msg->getDelay() + Clock->getCurrentTime());
		MessageQueue.insert(msg);
	}
}

void MessageDispatcher::sendMessageDelay()
{
	if(MessageQueue.empty() == true)
	{
		return ;
	}
	double curTime = Clock->getCurrentTime();
	for(auto it = MessageQueue.begin(); it != MessageQueue.end(); ++it)
	{
		if((*it)->getSendTime() >= curTime)
		{
			send(*it);
		}
		else
		{
			break;
		}
	}
}

void MessageDispatcher::send(Message *msg)
{
	GameEntity *receiver = EntityManager::getInstence()->getGameEntityById(msg->getReceiverId());
	if(receiver != nullptr)
	{
		if(receiver->handle_message(msg) == false)
		{
			std::cout<<"can't handle this message!"<<std::endl;
		}
	}
	else
	{
		std::cout<<"no receiver!"<<std::endl;
	}
}