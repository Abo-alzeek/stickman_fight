#include "headers/menumanager.h"
#include "headers/resourcemanager.h"
#include "headers/game.h"

const int WIDTH = 1280, HEIGHT = 768;

int main() {
    srand(time(NULL));
    
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WIDTH, HEIGHT)), "SFML Test");	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

    static ResourceManager RM;
    MenuManager MM(RM.fonts[0]);

    while(window.isOpen()) {
        window.clear();
        MM.run(window);

        if(MM.state == -1) {
            window.close();
            break;
        }

        if(MM.state < -1) {
            // int random = rand() 
            Game game(std::make_shared<ResourceManager>(RM), abs(MM.state) - 10, window, WIDTH, HEIGHT);
            MM.state = 0;

            window.close();
        }

        window.display();
    }

    return 0;
}
