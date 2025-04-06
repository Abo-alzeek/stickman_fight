#ifndef MENU_H_
#define MENU_H_

#include "button.h"
#include <memory>

enum MENUS {MAIN_MENU, PLAY, CONTROLS, LOBBY, CREDITS};

class menu {
public:
    int currentOption = 0, currentTab = 0;
    sf::Font f;
    std::vector<std::vector<std::shared_ptr<Option>>> options;

    virtual ~menu();
    menu(sf::Font &);

    void addOption(std::shared_ptr<Option> op);
    void moveUp();
    void moveDown();
    void draw(sf::RenderWindow &);

    virtual void build() = 0;
    virtual void handleInput(sf::RenderWindow &, int &) = 0;
};

#endif