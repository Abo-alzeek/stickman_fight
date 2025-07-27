#ifndef GAME_H_
#define GAME_H_

#include "camera.h"
#include "EntityManager.h"
#include "resourcemanager.h"

class Game
{
	bool running = true;
	int m_currentFrame = 0;
	// Removed unused playersCount variable

	// std::vector<Camera> cams;
	Camera cam;
	EntityManager m_entities;
	std::shared_ptr<MyMap> map;
	ResourceManager& m_resources;

	// Removed unused member string variables - now using static constants

public : 
	~Game();
	Game(ResourceManager& rm, int, sf::RenderWindow&, int, int);

	void handleInput(sf::RenderWindow &);
	void update();
	void checkCollisions(sf::RenderWindow &);
	void render(sf::RenderWindow &);

	void run(sf::RenderWindow &);
	
	// Character creation functions
	void createCharacter(sf::Vector2f position, int playerId = 0);
	void createMultipleCharacters(const std::vector<sf::Vector2f>& spawnPoints);
};

#endif