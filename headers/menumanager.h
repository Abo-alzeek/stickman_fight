#ifndef MENUMANAGER_H_
#define MENUMANAGER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"
#include "mainmenu.h"
#include "play.h"
#include "lobby.h"
#include "controls.h"
#include "credits.h"

class MenuManager {
public:
    sf::Font f;
    int state;
    std::vector<std::shared_ptr<menu>> menus;

    ~MenuManager();
    MenuManager(sf::Font &);
    void run(sf::RenderWindow &);
};

#endif