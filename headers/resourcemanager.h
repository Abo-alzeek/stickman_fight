#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "mymap.h"
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <algorithm>

// Resource type enums - now using indices for individual files
enum Textures {TILE_TEXTURES, DEMO_CHARACTER};
enum Tiles {NOTHING = -2, SPAWNING_POINT, GRASS, DIRT, WATER_SURFACE, UNDER_WATER, BROWN_BRICKS_WALL, GRAY_BRICKS_WALL, WOODEN_BOX};
// enum Sprites {TILE_GRASS, TILE_DIRT, TILE_WATER_SURFACE, TILE_UNDER_WATER, TILE_BROWN_BRICKS, TILE_GRAY_BRICKS, TILE_WOODEN_BOX};
enum Characters {CHARACTER_DEMO};
enum Others {BACKGROUND_SPRITE};

class ResourceManager {
private:
    // Organized resource storage
    std::vector<sf::Texture> m_backgrounds;   // Raw texture data
    std::vector<sf::Texture> m_tiles;         // Tile sprites
    std::vector<sf::Texture> m_characters;    // Character sprites
    std::vector<sf::Font> m_fonts;            // Fonts
    std::vector<MyMap> m_maps;                // Maps

    // Helper functions for loading individual sprites
    void loadTextures(const std::string& directory, const std::string& prefix, std::vector<sf::Texture>& target_vector);

public:
    ResourceManager();
    ~ResourceManager();

    // Texture getters
    const sf::Texture& get_texture(Textures texture_id) const;
    
    // Sprite getters
    const sf::Texture& get_tile(int sprite_id) const;
    const sf::Texture& get_background(int background_id) const;
    const sf::Texture& get_character(int character_id) const;
    
    // Font getters
    const sf::Font& get_font(size_t font_id) const;
    
    // Map getters
    const MyMap& get_map(size_t map_id) const;
    size_t get_map_count() const;
        
    // Debug functions
    void print_loaded_resources() const;
};

#endif