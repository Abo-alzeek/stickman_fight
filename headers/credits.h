#ifndef CREDITS_H_
#define CREDITS_H_

#include "menu.h"

class Credits : public menu {
public:
    Credits(sf::Font &);
    ~Credits();
    
    void build() override;
    void handleInput(sf::RenderWindow &, int &) override;
};

#endif