#include "../headers/mainmenu.h"

Mainmenu::Mainmenu(sf::Font &f) : menu(f) {
    this->options.emplace_back();

    this->options.back().push_back(std::make_shared<Button>("PLAY", this->f, sf::Color::White, 100));
    this->options.back().push_back(std::make_shared<Button>("OPTIONS", this->f, sf::Color::White, 100));
    this->options.back().push_back(std::make_shared<Button>("CREDITS", this->f, sf::Color::White, 100));
    this->options.back().push_back(std::make_shared<Button>("EXIT", this->f, sf::Color::White, 100));

    this->build();
}

Mainmenu::~Mainmenu() {

}

void Mainmenu::build() {
    float ypos = 0;
    for(int i = 0;i < (int)options[0].size();i++) {
        ypos += options[0][i]->label.getGlobalBounds().size.y;
        options[0][i]->label.setFillColor(sf::Color::White);
    }

    ypos = (768 - ypos) / 2 - 20;

    for(int i = 0;i < (int)options[0].size();i++) {
        options[0][i]->label.setPosition(sf::Vector2f( (1280 - options[0][i]->label.getGlobalBounds().size.x) / 2, ypos) );
        ypos += (options[0][i]->label.getGlobalBounds().size.y + 5);
    }

    this->options[0][this->currentOption]->toggleFocus();
}

void Mainmenu::handleInput(sf::RenderWindow &window, int &state) {
    sf::Event e;
    while(window.pollEvent(e)) {        
        if(e.type == sf::Event::Closed) {
            window.close();
        }
        else if(e.type == sf::Event::KeyPressed) {
            if(e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::W) {
                this->moveUp();
            }
            else if(e.key.code == sf::Keyboard::Down || e.key.code == sf::Keyboard::S) {
                this->moveDown();
            }
            else if(e.key.code == sf::Keyboard::Return) {
                if(currentOption == 0) state = MENUS::PLAY;
                else if(currentOption == 1) state = MENUS::CONTROLS;
                else if(currentOption == 2) state = MENUS::CREDITS;
                else if(currentOption == 3) state = -1;
            }
        }
    }
}

