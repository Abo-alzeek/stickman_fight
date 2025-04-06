#ifndef BUTTON_H_
#define BUTTON_H_

#include "option.h"

class Button : public Option {
public:
    Button(std::string, sf::Font &, sf::Color, int, std::uint32_t = sf::Text::Regular, Option_Location = Option_Location::CENTER_CENTER);
    ~Button();

    void toggleFocus() override;
    int location;
};

#endif