#include<set>
class Message;
class GameEntity;

#define MsgDispatcher MessageDispatcher::getInstence()

class MessageDispatcher
{
private:
	std::set<Message *> MessageQueue;
public:
	static MessageDispatcher* getInstence();
	void sendMessage(Message *msg);
	void sendMessageDelay();
private:
	MessageDispatcher();
	MessageDispatcher(const MessageDispatcher& );
	MessageDispatcher& operator = (const MessageDispatcher& );
	void send(Message *msg);	//a tool func
};