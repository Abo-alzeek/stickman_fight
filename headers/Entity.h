#ifndef ENTITY_H_
#define ENTITY_H_

#include <memory>
#include <iostream>
#include "Components.h"

class Entity {
	size_t m_id = 0;
	bool m_alive = true;
	std::shared_ptr<std::string> m_tag = std::make_shared<std::string> ("Default");

public:
	Entity();
	~Entity();
	Entity(const size_t id, std::shared_ptr<std::string> tag);

	std::shared_ptr<CInput>          			cInput;
	std::shared_ptr<CTexture>      				cTextrue;
	std::vector<std::shared_ptr<CCollision>>	cCollision;
	std::shared_ptr<CAnimation>					cAnimation;
	std::shared_ptr<CTransform>					cTransform;
	std::shared_ptr<CBones>          			cBones;
	std::shared_ptr<CState>          			cState;
	std::shared_ptr<CHealth>                    cHealth;
	std::shared_ptr<CPos>         	            cPos;
	
	void destroy();
	bool isActive();
	std::shared_ptr<std::string> tag();
	size_t id();
};

#endif
