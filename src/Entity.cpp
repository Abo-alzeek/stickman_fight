#include "../headers/Entity.h"

Entity::Entity() {
	// std::cout << "ENTITIY CREATED\n";
	cInput = NULL;
	cTextrue = NULL;
	cCollision.clear();
	cAnimation = NULL;
	cTransform = NULL;
	cHealth = NULL;
	// zob = NULL;
}

Entity::~Entity() {
	cInput = NULL;
	cTextrue = NULL;
	cCollision.clear();
	cAnimation = NULL;
	cTransform = NULL;
	cHealth = NULL;
	// zob = NULL;
}


Entity::Entity(const size_t id, std::shared_ptr<std::string> tag) {
	m_id = id;
	m_tag = tag;
}

void Entity::destroy(){
	m_alive = false;
}

bool Entity::isActive() {
	return m_alive;
}

std::shared_ptr<std::string> Entity::tag() {
	return m_tag;
}

size_t Entity::id() {
	return m_id;
}