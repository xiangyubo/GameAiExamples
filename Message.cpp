#include"Message.h"
Message::Message(float del, 
				 int s_id, 
				 int r_id, 
				 int msg_id,
				 void* info):/*time({del}),*///union的初始化不会...
							senderId(s_id),
							receiverId(r_id), 
							messageId(msg_id), 
							extendInfo(info)	
{
	time.delay = del;
}

bool Message::operator < (const Message &msg) const
{
	return time.sendTime < msg.time.sendTime;
}

double Message::getDelay() const
{
	return time.delay;
}

int Message::getMsgId() const
{
	return messageId;
}

int Message::getReceiverId() const
{
	return receiverId;
}

int Message::getSenderId() const
{
	return senderId;
}

void Message::setSendTime(double sendTime)
{
	time.sendTime = sendTime;
}

double Message::getSendTime()
{
	return time.sendTime;
}