#include "../headers/lobby.h"


Lobby::Lobby(sf::Font &f): menu(f) {
    this->options.emplace_back();
    this->options.emplace_back();
    this->options.emplace_back();

    this->options[0].push_back(std::make_shared<Button>("PLAYERS", this->f, sf::Color::White, 100, sf::Text::Underlined, Option_Location::CENTER_LEFT));
    this->options[2].push_back(std::make_shared<Button>("START", this->f, sf::Color::White, 100));
    this->options[2].push_back(std::make_shared<Button>("BACK", this->f, sf::Color::White, 100));

    this->Players.emplace_back();
    this->Players.emplace_back();

    this->currentOption = 0;
    this->currentTab = 2;

    this->lobbyOwner = 0;
    this->Players[Input_Device_type::KEYBOARD].insert(keyboardCount);
    this->options[0].push_back(std::make_shared<Button>("Keyboard_" + std::to_string(keyboardCount++), this->f, sf::Color::White, 75));

    this->build();
}


Lobby::~Lobby() {
    // std::cout << "Number of keyboard players: " << this->Players[Input_Device_type::KEYBOARD].size() << std::endl;
    // std::cout << "Number of joystick players: " << this->Players[Input_Device_type::JOYSTICK].size() << std::endl;
}


void Lobby::build() {
    float ypos = 50;

    // tab_1

    for(int i = 0;i < (int)options[0].size();i++) {
        options[0][i]->setPosition(0.0, 1280.0 / 2.0);
        options[0][i]->label.setPosition(this->options[0][i]->label.getPosition().x, ypos);
        ypos += (options[0][i]->label.getGlobalBounds().height + ((i == 0) * 20) + 5 + (50.0 / 100.0 * options[0][i]->label.getGlobalBounds().height));
    }

    // tab_2

    // tab_3

    int xpos = 0;
    for(int i = 0;i < (int)options[2].size();i++) {
        xpos += this->options[2][i]->label.getGlobalBounds().width;
    }

    ypos = 768 * 4 / 5;
    xpos = 1280/2 + (1280/2 - xpos)/2;
    for(int i = 0;i < (int)options[2].size();i++) {
        this->options[2][i]->label.setPosition(sf::Vector2f(xpos, ypos));
        xpos += this->options[2][i]->label.getGlobalBounds().width + 40;
    }

    this->options[this->currentTab][this->currentOption]->toggleFocus();
}

void Lobby::handleInput(sf::RenderWindow &window, int &state) {
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
                if(this->currentTab == 0) {

                }
                else if(this->currentTab == 1) {

                }
                else if(this->currentTab == 2) {
                    if(this->currentOption == 0) state = -10;
                    else if(this->currentOption == 1) state = MENUS::PLAY;
                }
            }
        }
        else if(e.type == sf::Event::JoystickConnected) {
            std::cout << "Joystick " << e.joystickConnect.joystickId << " connected.\n";
        }
        else if(e.type == sf::Event::JoystickDisconnected) {
            std::cout << "Joystick " << e.joystickConnect.joystickId << " disconnected.\n";
        }
        else if (e.type == sf::Event::JoystickButtonPressed) {
            // std::cout << "Joystick " << e.joystickButton.joystickId << " pressed button " << e.joystickButton.button << ".\n";

            if(e.joystickButton.button == 9 || e.joystickButton.button == 2) {
                if(this->Players[Input_Device_type::JOYSTICK].count(e.joystickButton.joystickId)) return;

                this->Players[Input_Device_type::JOYSTICK].insert(e.joystickButton.joystickId);

                float ypos = 50;
                for(int i = 0;i < (int)options[0].size();i++) {
                    std::cout << i << ": " << ypos << std::endl;
                    ypos += (options[0][i]->label.getGlobalBounds().height + ((i == 0) * 20) + 5 + (50.0 / 100.0 * options[0][i]->label.getGlobalBounds().height));
                }


                this->options[0].push_back(std::make_shared<Button>("JOYSTICK_" + std::to_string(e.joystickButton.joystickId), this->f, sf::Color::White, 75));
                this->options[0].back()->setPosition(0, 1280.0/2.0);
                this->options[0].back()->label.setPosition(this->options[0].back()->label.getPosition().x, ypos);
            }
        }

    }
}