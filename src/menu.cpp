#include "../headers/menu.h"


void menu::addOption(std::shared_ptr<Option> op) {
    this->options.back().push_back(op);
}

void menu::moveUp() {
    this->options[this->currentTab][currentOption]->toggleFocus();
    currentOption = (currentOption - 1 + options[this->currentTab].size()) % (int)(options[this->currentTab].size());
    this->options[this->currentTab][currentOption]->toggleFocus();
}

void menu::moveDown() {
    this->options[this->currentTab][currentOption]->toggleFocus();
    currentOption = (currentOption + 1) % (int)(options[this->currentTab].size());
    this->options[this->currentTab][currentOption]->toggleFocus();
}

void menu::draw(sf::RenderWindow &window) {
    for(int i = 0;i < (int)options.size();i++) {
        for(int j = 0;j < (int)options[i].size();j++) {
            window.draw(options[i][j]->label);
        }
    }
}

menu::menu(sf::Font &font) {
    this->f = font;
}

menu::~menu() {

}
