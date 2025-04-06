#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "mymap.h"
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>

enum Textures {BRICKS_BACKGROUND, TILE_TEXTURES};
enum Tiles {NOTHING = -2, SPAWNING_POINT, GRASS, DIRT, WATER_SURFACE, UNDER_WATER, BROWN_BRICKS_WALL, GRAY_BRICKS_WALL, WOODEN_BOX};

class ResourceManager {
public:
    std::vector<MyMap> maps;
    std::vector<sf::Texture> images;
    std::vector<sf::Font> fonts;
    std::vector<sf::Sprite> sprites;
    
    // std::vector<sf::Sound> sounds;
    // std::vector<Animations> animations;

    ResourceManager();
    ~ResourceManager();
};

#endif