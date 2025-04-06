#ifndef PLAY_H_
#define PLAY_H_

#include "menu.h"

class Play : public menu {
public:
    Play(sf::Font &);
    ~Play();

    void build() override;
    void handleInput(sf::RenderWindow &window, int &state) override;
};

#endif
