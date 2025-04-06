#include "../headers/mymap.h"

MyMap::MyMap(int bg, std::vector<std::vector<int>> vec, std::string n) {
    this->background = bg;
    this->tiles = vec;
    this->name = n;
}

MyMap::~MyMap() {
    
}