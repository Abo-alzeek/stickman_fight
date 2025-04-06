#include "../headers/option.h"

Option::Option(Option_Location option_location) {
    this->location = option_location;
}


Option::~Option() {

}

void Option::setPosition(float parentStart, float parentEnd) {
    float xpos;

    if(this->location == Option_Location::CENTER_LEFT) {
        xpos = parentStart + (parentEnd - parentStart) * 5.0 / 100.0;
        this->label.setPosition(sf::Vector2f(xpos, this->label.getPosition().y));
    }
    else if(this->location == Option_Location::CENTER_CENTER) {
        xpos = (parentEnd - parentStart - this->label.getGlobalBounds().size.x) / 2.0;
        this->label.setPosition(sf::Vector2f(xpos, this->label.getPosition().y));
    }
    else if(this->location == Option_Location::CENTER_RIGHT) {
        xpos = parentEnd - this->label.getGlobalBounds().size.x - (parentEnd - parentStart) * 5.0 / 100.0;
        this->label.setPosition(sf::Vector2f(xpos, this->label.getPosition().y));
    }
}