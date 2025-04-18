#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <iostream>
#include <map>
#include <memory>
#include "Entity.h"

typedef std::vector <std::shared_ptr<Entity>> EntityVec;
typedef std::map <std::string, EntityVec> EntityMap;

class EntityManager {
	EntityVec m_toAdd;
	EntityVec m_entities;
	EntityMap m_entityMap;
	size_t m_totalEntities = 0;

public:
	EntityManager();
	void update();
	std::shared_ptr<Entity> addEntity(std::shared_ptr<std::string>);
	EntityVec& getEntities();
	EntityVec& getEntities(const std::string& tag);
};

#endif
