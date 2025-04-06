#ifndef MYMAP_H_
#define MYMAP_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class MyMap {
public:
    std::string name;
    std::vector< std::vector<int> > tiles;
    int background;

    MyMap(int, std::vector<std::vector<int>>, std::string);
    ~MyMap();
};

#endif