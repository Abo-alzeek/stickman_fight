#ifndef CONTROLS_H_
#define CONTROLS_H_

#include "menu.h"

class Controls : public menu {
public:
    Controls(sf::Font &);
    ~Controls();
    
    void build() override;
    void handleInput(sf::RenderWindow &window, int &state) override;
};

#endif