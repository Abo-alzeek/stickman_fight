#ifndef OPTION_H_
#define OPTION_H_

#include <iostream>
#include <SFML/Graphics.hpp>

enum Option_Location {TOP_LEFT, TOP_CENTER, TOP_RIGHT, CENTER_LEFT, CENTER_CENTER, CENTER_RIGHT, BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT};

class Option {
public:
    bool focus = false;
    sf::Font f;
    sf::Text label{f, ""};
    Option_Location location;
    
    Option(Option_Location = Option_Location::CENTER_CENTER);
    virtual ~Option();

    virtual void toggleFocus() = 0;
    void setPosition(float, float);
};

#endif