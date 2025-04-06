#include "../headers/play.h"

Play::Play(sf::Font &f): menu(f) {
    this->options.emplace_back();

    this->options.back().push_back(std::make_shared<Button>("HOST", this->f, sf::Color::White, 100));
    this->options.back().push_back(std::make_shared<Button>("JOIN", this->f, sf::Color::White, 100));
    this->options.back().push_back(std::make_shared<Button>("Local Game", this->f, sf::Color::White, 100));
    this->options.back().push_back(std::make_shared<Button>("BACK", this->f, sf::Color::White, 100));

    this->build();
}

Play::~Play() {
    
}

void Play::build() {
    float ypos = 0;
    for(int i = 0;i < (int)options[0].size();i++) {
        ypos += options[0][i]->label.getGlobalBounds().height;
        options[0][i]->label.setFillColor(sf::Color::White);
    }

    ypos = (768 - ypos) / 2;

    for(int i = 0;i < (int)options[0].size();i++) {
        options[0][i]->label.setPosition(sf::Vector2f( (1280 - options[0][i]->label.getGlobalBounds().width) / 2, ypos) );
        ypos += (options[0][i]->label.getGlobalBounds().height + 5);

        if(i == (int)options[0].size() - 2) ypos += 10;
    }

    this->options[0][this->currentOption]->toggleFocus();
}

void Play::handleInput(sf::RenderWindow &window, int &state) {
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
                if(currentOption == 0) state = MENUS::LOBBY;
                else if(currentOption == 1) state = MENUS::LOBBY;
                else if(currentOption == 2) state = MENUS::LOBBY;
                else if(currentOption == 3) state = MENUS::MAIN_MENU;
            }
        }
    }
}

