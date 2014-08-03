#ifndef _MESSAGE_
#define _MESSAGE_
class Message
{
private:
	union AboutTime
	{
		double delay;
		double sendTime; 
	};
	AboutTime time;
	int	senderId;
	int receiverId;
	int messageId;
	void *extendInfo;
public:
	Message(float del, int s_id, int r_id, int msg_id,void* info);
	int getSenderId() const;
	int getReceiverId() const;
	int getMsgId() const;
	double getDelay() const;
	void setSendTime(double sendTime);
	double getSendTime();
	bool operator < (const Message &msg) const;
};
#endif