#include "../headers/resourcemanager.h"

int toNumber(const std::string& str) {
    int ret = 0;
    for(int i = (str[0] == '-');i < (int)str.size();i++) {
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

    // load textures
    std::cout << "Textures:" << std::endl;

    try {
        for (const auto& entry : std::filesystem::directory_iterator("res/images")) {
            std::cout << "    " << entry.path() << std::endl;
            sf::Texture t;
            if(!t.loadFromFile(entry.path())) {
                std::cout << "Unable to load texture '" << entry.path() << "'" << std::endl;
            }
            else this->images.push_back(t);
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << " -> Error: " << e.what() << std::endl;
    }

    // load tiles
    // {GRASS, DIRT, WATER_SURFACE, UNDER_WATER, BROWN_BRICKS_WALL, GRAY_BRICKS_WALL, WOODEN_BOX};

    sf::Sprite sp(this->images[Textures::TILE_TEXTURES]);

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({0, 0}, {64, 64}));

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({192, 0}, {64, 64}));

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({256, 0}, {64, 64}));

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({256, 64}, {64, 64}));

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({192, 192}, {64, 64}));

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({192, 256}, {64, 64}));

    this->sprites.push_back(sp);
    this->sprites.back().setTextureRect(sf::IntRect({256, 320}, {64, 64}));

    // load fonts
    std::cout << "FONTS: \n";

    try {
        for (const auto& entry : std::filesystem::directory_iterator("res/fonts")) {
            std::cout << "    " << entry.path() << std::endl;

            sf::Font f;
            if(!f.openFromFile(entry.path())) {
                std::cout << "Unable to load font '" << entry.path() << "'" << std::endl;
            }
            else this->fonts.push_back(f);
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << " -> Error: " << e.what() << std::endl;
    }

    // load maps
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

            this->maps.push_back(MyMap(mapBG, vec, mapName));
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << " -> Error: " << e.what() << std::endl;
    }

    // load animations
    // load sound

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

ResourceManager::~ResourceManager() {

}
