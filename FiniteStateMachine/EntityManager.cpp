#include"EntityManager.h"
#include"GameEntity.h"
 EntityManager * EntityManager::getInstence()
{
	static EntityManager instence;
	return &instence;
}

 GameEntity * EntityManager::getGameEntityById(int id)
 {
	 if(EntityMap.find(id) == EntityMap.end())
	 {
		 return nullptr;
	 }
	 return EntityMap[id];
 }

 void EntityManager::registerEntity(GameEntity *entity)
 {
	 if(EntityMap.empty() != true && EntityMap.find(entity->getEntityId()) != EntityMap.end())
	{
		return ;
	}
	EntityMap[entity->getEntityId()] = entity;
 }

 void EntityManager::deregisterEntity(GameEntity *entity)
 {
	EntityMap.erase(entity->getEntityId());
 }

 void EntityManager::reset()
 {
	 EntityMap.clear();
 }

 EntityManager::EntityManager()
 {}