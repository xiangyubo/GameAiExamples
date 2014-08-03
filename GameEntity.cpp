#include"GameEntity.h"
int GameEntity::global_id;

GameEntity::GameEntity():entity_id(++global_id)
{}

GameEntity::~GameEntity()
{}

int GameEntity::getEntityId()
{
	return entity_id;
}