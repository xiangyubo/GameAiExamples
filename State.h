#ifndef _STATE
#define _STATE
class Message;
template<typename Entity_type>
class State
{
public:
	virtual void enter(Entity_type *entity) = 0;
	virtual void excute(Entity_type *entity) = 0;
	virtual void exit(Entity_type *entity) = 0;
	virtual bool hand_message(Entity_type *entity, Message *msg) const = 0;
protected:
	virtual void transform(Entity_type *entity) = 0;
};
#endif