#include "../headers/credits.h"

Credits::Credits(sf::Font &f): menu(f) {
    this->options.emplace_back();

    this->options.back().push_back(std::make_shared<Button>("Stickman fight game, Made by @Abo_alzeek00", this->f, sf::Color::White, 75, sf::Text::Underlined));
    this->options.back().push_back(std::make_shared<Button>("BACK", this->f, sf::Color::White, 100));

    this->currentOption = 1;
    this->build();
}

Credits::~Credits() {
    
}

void Credits::build() {
    float ypos = 0;

    ypos = (768 - options[0][0]->label.getGlobalBounds().height) / 2 - 75;

    for(int i = 0;i < (int)options[0].size();i++) {
        options[0][i]->label.setPosition(sf::Vector2f( (1280 - options[0][i]->label.getGlobalBounds().width) / 2, ypos) );
        ypos += (options[0][i]->label.getGlobalBounds().height + 5);

        if(i == (int)options[0].size() - 2) ypos += 100;
    }

    this->options[0][this->currentOption]->toggleFocus();
}

void Credits::handleInput(sf::RenderWindow &window, int &state) {
    sf::Event e;
    while(window.pollEvent(e)) {
        if(e.type == sf::Event::Closed) {
            window.close();
        }
        else if(e.type == sf::Event::KeyPressed) {
            if(e.key.code == sf::Keyboard::Up || e.key.code == sf::Keyboard::W) {
                // this->moveUp();
            }
            else if(e.key.code == sf::Keyboard::Down || e.key.code == sf::Keyboard::S) {
                // this->moveDown();
            }
            else if(e.key.code == sf::Keyboard::Return) {
                if(currentOption == 0) ;
                else if(currentOption == 1) state = MENUS::MAIN_MENU;
            }
        }
    }
}

