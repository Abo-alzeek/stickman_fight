#include "../headers/menumanager.h"

MenuManager::MenuManager(sf::Font &font) {
    this->f = font;

    this->menus =  {std::make_shared<Mainmenu>(f), 
                    std::make_shared<Play>(f), 
                    std::make_shared<Controls>(f), 
                    std::make_shared<Lobby>(f), 
                    std::make_shared<Credits>(f)};

    this->state = 0;
}

MenuManager::~MenuManager() {

}

void MenuManager::run(sf::RenderWindow &window) {
    this->menus[state]->handleInput(window, state);

    if(state < 0) {
        return;
    }

    this->menus[state]->draw(window);   
}