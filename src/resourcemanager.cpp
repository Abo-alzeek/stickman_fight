#include "../headers/resourcemanager.h"

int toNumber(const std::string& str) {
    // Add input validation
    if (str.empty()) {
        return 0;
    }
    
    int ret = 0;
    for(int i = (str[0] == '-');i < (int)str.size();i++) {
        // Validate that character is a digit
        if (str[i] < '0' || str[i] > '9') {
            return 0; // Return 0 for invalid input
        }
        ret *= 10;
        ret += (str[i] - '0');
    }

    
    if(str[0] == '-') ret *= -1;
    return ret;
}

ResourceManager::ResourceManager() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "---------------------LOADING...---------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;

    // Load individual sprites from res/images directory
    std::string imagesDir = "res/images";
    
    // Load tile sprites (files starting with "tile_")
    std::cout << "Loading tile sprites..." << std::endl;
    loadTextures(imagesDir + "/tiles", "tile_", m_tiles);
    
    // Load character sprites (files starting with "character_")
    std::cout << "Loading character sprites..." << std::endl;
    loadTextures(imagesDir + "/characters", "character_", m_characters);
        
    // Load background sprites (files starting with "background_")
    std::cout << "Loading background sprites..." << std::endl;
    loadTextures(imagesDir + "/backgrounds", "background_", m_backgrounds);
    
    // Load fonts
    std::cout << "FONTS: " << std::endl;
    try {
        for (const auto& entry : std::filesystem::directory_iterator("res/fonts")) {
            std::cout << "    " << entry.path() << std::endl;

            sf::Font f;
            if(!f.openFromFile(entry.path())) {
                std::cout << "Unable to load font '" << entry.path() << "'" << std::endl;
            }
            else m_fonts.push_back(f);
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << " -> Error: " << e.what() << std::endl;
    }

    // Load maps
    std::cout << "MAPS: " << std::endl;
    try {
        for (const auto& entry : std::filesystem::directory_iterator("res/maps")) {
            std::cout << "    " << entry.path() << std::endl;
            
            std::ifstream file(entry.path());
            if(!file) {
                std::cout << "Unable to load map: '" << entry.path() << "'" << std::endl;
                continue;
            }

            std::string mapName;
            std::vector<std::vector<int>> vec;

            std::string line;
            file >> mapName;

            file >> line;
            int mapBG = toNumber(line);
            file >> line;
            int mapHeight = toNumber(line);
            file >> line;
            int mapWidth = toNumber(line);

            for(int i = 0;i < mapHeight;i++) {
                vec.emplace_back();
                for(int j = 0;j < mapWidth;j++) {
                    file >> line;
                    vec.back().push_back(toNumber(line));
                }
            }

            m_maps.push_back(MyMap(mapBG, vec, mapName));
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << " -> Error: " << e.what() << std::endl;
    }

    this->print_loaded_resources();

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

ResourceManager::~ResourceManager() {
}

// Load textures (files starting with "texture_")
void ResourceManager::loadTextures(const std::string& directory, const std::string& prefix, std::vector<sf::Texture>& target_vector) {
    try {
        std::vector<std::pair<int, std::string>> files; // (number, filename)
        
        // Scan directory for files with the specified prefix
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            std::string filename = entry.path().filename().string();
            
            // Check if file starts with the prefix and ends with .png
            if (filename.substr(0, prefix.length()) == prefix && 
                filename.substr(filename.length() - 4) == ".png") {
                
                // Extract the number from the filename (e.g., "tile_5.png" -> 5)
                std::string numberStr = filename.substr(prefix.length());
                numberStr = numberStr.substr(0, numberStr.length() - 4); // Remove .png
                
                int number = toNumber(numberStr);
                files.push_back({number, entry.path().string()});
            }
        }
        
        // Sort files by number to ensure consistent loading order
        sort(files.begin(), files.end());
                
        for (const auto& [number, filepath] : files) {
            sf::Texture texture;
            if (texture.loadFromFile(filepath)) {
                target_vector.push_back(texture);
                std::cout << "    Loaded: " << std::filesystem::path(filepath).filename().string() << std::endl;
            } else {
                std::cout << "    Failed to load: " << std::filesystem::path(filepath).filename().string() << std::endl;
            }
        }
        
        std::cout << "    Total " << prefix << " loaded: " << target_vector.size() << std::endl;
        
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error loading textures: " << e.what() << std::endl;
    }
}

// Texture getters
const sf::Texture& ResourceManager::get_background(int background_id) const {
    if (static_cast<size_t>(background_id) < m_backgrounds.size()) {
        return m_backgrounds[background_id];
    }
    throw std::out_of_range("Texture ID out of range");
}

const sf::Texture& ResourceManager::get_character(int character_id) const {
    if (static_cast<size_t>(character_id) < m_characters.size()) {
        return m_characters[character_id];
    }
    throw std::out_of_range("Character ID out of range");
}

const sf::Texture& ResourceManager::get_tile(int tile_id) const {
    if (static_cast<size_t>(tile_id) < m_tiles.size()) {
        return m_tiles[tile_id];
    }
    throw std::out_of_range("Character ID out of range");
}

// Font getters
const sf::Font& ResourceManager::get_font(size_t font_id) const {
    if (font_id < m_fonts.size()) {
        return m_fonts[font_id];
    }
    throw std::out_of_range("Font ID out of range");
}

// Map getters
const MyMap& ResourceManager::get_map(size_t map_id) const {
    if (map_id < m_maps.size()) {
        return m_maps[map_id];
    }
    throw std::out_of_range("Map ID out of range");
}

size_t ResourceManager::get_map_count() const {
    return m_maps.size();
}

// Debug functions
void ResourceManager::print_loaded_resources() const {
    std::cout << "Loaded Resources:" << std::endl;
    std::cout << "  Characters: " << m_characters.size() << std::endl;
    std::cout << "  Tiles: " << m_tiles.size() << std::endl;
    std::cout << "  Backgrounds: " << m_backgrounds.size() << std::endl;
    std::cout << "  Fonts: " << m_fonts.size() << std::endl;
    std::cout << "  Maps: " << m_maps.size() << std::endl;
}
