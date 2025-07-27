#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include "mymap.h"
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <algorithm>

// Resource type enums - now using indices for individual files
enum Textures {BRICKS_BACKGROUND, TILE_TEXTURES, DEMO_CHARACTER};
enum Tiles {NOTHING = -2, SPAWNING_POINT, GRASS, DIRT, WATER_SURFACE, UNDER_WATER, BROWN_BRICKS_WALL, GRAY_BRICKS_WALL, WOODEN_BOX};
enum Sprites {TILE_GRASS, TILE_DIRT, TILE_WATER_SURFACE, TILE_UNDER_WATER, TILE_BROWN_BRICKS, TILE_GRAY_BRICKS, TILE_WOODEN_BOX};
enum Characters {CHARACTER_DEMO};
enum Others {BACKGROUND_SPRITE};

class ResourceManager {
private:
    // Organized resource storage
    std::vector<sf::Texture> m_textures;      // Raw texture data
    std::vector<sf::Sprite> m_sprites;        // Tile sprites
    std::vector<sf::Sprite> m_characters;     // Character sprites
    std::vector<sf::Sprite> m_others;         // Other sprites (backgrounds, UI, etc.)
    std::vector<sf::Font> m_fonts;            // Fonts
    std::vector<MyMap> m_maps;                // Maps

    // Helper functions for loading individual sprites
    void loadIndividualSprites(const std::string& directory, const std::string& prefix, std::vector<sf::Sprite>& target_vector);
    void loadTextures(const std::string& directory);
    void loadBackgrounds(const std::string& directory);

public:
    ResourceManager();
    ~ResourceManager();

    // Texture getters
    const sf::Texture& get_texture(Textures texture_id) const;
    
    // Sprite getters
    const sf::Sprite& get_sprite(Sprites sprite_id) const;
    const sf::Sprite& get_character(Characters character_id) const;
    const sf::Sprite& get_other(Others other_id) const;
    
    // Font getters
    const sf::Font& get_font(size_t font_id) const;
    
    // Map getters
    const MyMap& get_map(size_t map_id) const;
    size_t get_map_count() const;
    
    // Background getter (for backward compatibility)
    const sf::Sprite& get_background_sprite() const;
    
    // Debug functions
    void print_loaded_resources() const;
};

#endif