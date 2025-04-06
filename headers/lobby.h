#ifndef LOBBY_H_
#define LOBBY_H_

#include "menu.h"
#include <set>

enum Input_Device_type {KEYBOARD, JOYSTICK};

class Lobby : public menu {
public:
    Lobby(sf::Font &);
    ~Lobby();
    
    int keyboardCount = 0, lobbyOwner;
	std::vector<std::set<int>> Players; // first is player input device(1 -> keyboard, 0 -> joystick), second is the id of the player 

    void build() override;
    void handleInput(sf::RenderWindow &window, int &state) override;
};

#endif