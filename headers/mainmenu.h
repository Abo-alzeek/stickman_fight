#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "menu.h"

class Mainmenu : public menu {
public:
    Mainmenu(sf::Font &);
    ~Mainmenu();

    void build() override;
    void handleInput(sf::RenderWindow &window, int &state) override;
};

#endif
