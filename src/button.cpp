#include "../headers/button.h"

Button::Button(std::string l, sf::Font &f, sf::Color c, int sz, std::uint32_t style, Option_Location option_location) : Option(option_location) {
    this->label = sf::Text(f, l);
    this->label.setFillColor(c);
    this->label.setCharacterSize(sz);
    this->label.setStyle(style);
}

Button::~Button() {

}

void Button::toggleFocus() {
    this->focus = !this->focus;
    
    if(this->focus) this->label.setFillColor(sf::Color::Red);
    else this->label.setFillColor(sf::Color::White);
}
