#include "headers/resourcemanager.h"
#include "headers/game.h"

const int WIDTH = 1280, HEIGHT = 768;

int main() {
    srand(time(NULL));
    
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "SFML Test");	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

    static ResourceManager RM;

    Game game(RM, 0, window, WIDTH, HEIGHT);
    game.run(window);

    return 0;
}
