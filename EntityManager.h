#include<map>
class GameEntity;
class EntityManager
{
private:
	std::map<int, GameEntity*>	EntityMap;
public:
	static EntityManager * getInstence();
	void registerEntity(GameEntity *entity);
	GameEntity * getGameEntityById(int id);
	void deregisterEntity(GameEntity *entity);
	void reset();
private:
	EntityManager();
	EntityManager(const EntityManager& );
	EntityManager& operator = (const EntityManager& );
};