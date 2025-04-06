#ifndef GAME_H_
#define GAME_H_

#include "camera.h"
#include "EntityManager.h"
#include "resourcemanager.h"

class Game
{
	bool running = true;
	int m_currentFrame = 0;
	int playersCount = 0;

	// std::vector<Camera> cams;
	Camera cam;
	EntityManager m_entities;
	std::shared_ptr<MyMap> map;
	std::shared_ptr<ResourceManager> m_resources;

	std::string tileTag = "TILE";
	std::string stickmanTag = "STICKMAN";
	std::string skeletalTag = "SKELETALTAG";

public : 
	~Game();
	Game(std::shared_ptr<ResourceManager>(rm), int, sf::RenderWindow&, int, int);

	void handleInput(sf::RenderWindow &);
	void update();
	void checkCollisions(sf::RenderWindow &);
	void render(sf::RenderWindow &);

	void run(sf::RenderWindow &);
};

#endif