#ifndef _GAME_ENTITY
#define _GAME_ENTITY
class Message;
class GameEntity
{
protected:
	static int global_id;
	int		entity_id;
public:
	GameEntity();
	int getEntityId();
	virtual bool handle_message(Message *msg) = 0;
	virtual void update() = 0;
	virtual ~GameEntity();
};
#endif