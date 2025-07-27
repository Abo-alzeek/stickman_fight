#include "../headers/game.h"

// Constants to replace magic numbers
const float TILE_SIZE = 64.0f;
const float CAMERA_MOVE_SPEED = 10.0f;
const float PLAYER_OFFSET = 32.0f;

// Static string constants to reduce memory allocations
static const std::string TILE_TAG = "TILE";
static const std::string STICKMAN_TAG = "STICKMAN";
static const std::string SKELETAL_TAG = "SKELETALTAG";

Game::Game(ResourceManager& rm, int x, sf::RenderWindow &window, int screen_width, int screen_height) 
    : m_resources(rm) {  // Initialize reference member in initialization list
    std::vector<sf::Vector2f> spawning_points;
    this->map = std::make_shared<MyMap>(m_resources.get_map(x));
    
    for(size_t i = 0; i < this->map->tiles.size(); i++) {
        for(size_t j = 0; j < this->map->tiles[i].size(); j++) {
            // std::cout << this->map->tiles[i][j] << " ";

            if(this->map->tiles[i][j] == -1) {
                spawning_points.push_back(sf::Vector2f(j * TILE_SIZE, i * TILE_SIZE));
            }
            else if(this->map->tiles[i][j] != Tiles::NOTHING) {
                auto e = this->m_entities.addEntity(std::make_shared<std::string>(TILE_TAG));

                e->cPos = std::make_shared<CPos>(j * TILE_SIZE, i * TILE_SIZE);
                e->cCollision.push_back(std::make_shared<CCollision>(e->cPos->position, TILE_SIZE, TILE_SIZE));
                
                // Map tile types to sprite indices - now using individual tile files
                int tileType = this->map->tiles[i][j];
                if (tileType >= 0) {
                    e->cTexture = std::make_shared<CTexture>(tileType);
                } else {
                    e->cTexture = std::make_shared<CTexture>(0); // Default to first tile
                }
            }
        }
        // std::cout << std::endl;
    }

    // Fix: Add bounds checking for spawn points
    if (spawning_points.empty()) {
        // Fallback to a default position if no spawn points found
        spawning_points.push_back(sf::Vector2f(0.0f, 0.0f));
    }
    
    // Create multiple characters at spawn points
    createMultipleCharacters(spawning_points);
    
    // Set camera to first character position
    sf::Vector2f firstPos = spawning_points[0];
    this->cam = Camera(this->map->tiles[0].size() * TILE_SIZE, this->map->tiles.size() * TILE_SIZE, screen_width, screen_height, firstPos);
    
    this->run(window);
}

Game::~Game() {

}

void Game::handleInput(sf::RenderWindow &window) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                window.close();
                this->running = false;                
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
                this->cam.moveView(sf::Vector2f(-CAMERA_MOVE_SPEED, 0.0));
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
                this->cam.moveView(sf::Vector2f(CAMERA_MOVE_SPEED, 0.0));
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::F) {
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
                this->cam.moveView(sf::Vector2f(0.0, CAMERA_MOVE_SPEED));
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
                this->cam.moveView(sf::Vector2f(0.0, -CAMERA_MOVE_SPEED));
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Right) {
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Left) {
            }
        }
        else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
            if (keyReleased->scancode == sf::Keyboard::Scancode::Escape) {
                this->running = false;
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::A) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::D) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::W) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::S) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::F) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::Space) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::Right) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::Left) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::Up) {
            }
            else if (keyReleased->scancode == sf::Keyboard::Scancode::Down) {
            }
        }
    }
}

void Game::update() {

}

void Game::checkCollisions(sf::RenderWindow &) {

}

void Game::render(sf::RenderWindow &window) {
    window.clear(sf::Color(255, 255, 255, 255));

    // Draw background (if available)
    try {
        window.draw(m_resources.get_background_sprite());
    } catch (const std::out_of_range&) {
        // No background sprite available, continue
    }

    // Draw tiles
    for(auto e : m_entities.getEntities(TILE_TAG)) {
        if (e->cTexture && e->cTexture->sprite >= 0) {
            try {
                sf::Sprite tileSprite = m_resources.get_sprite(static_cast<Sprites>(e->cTexture->sprite));
                tileSprite.setPosition(e->cPos->position);
                window.draw(tileSprite);
            } catch (const std::out_of_range&) {
                // Sprite not found, skip this tile
                std::cout << "Warning: Tile sprite " << e->cTexture->sprite << " not found" << std::endl;
            }
        }
    }

    // Draw characters
    for(auto e : m_entities.getEntities(STICKMAN_TAG)) {
        if (e->cTexture) {
            try {
                sf::Sprite characterSprite = m_resources.get_character(Characters::CHARACTER_DEMO);
                characterSprite.setPosition(e->cPos->position);
                window.draw(characterSprite);
            } catch (const std::out_of_range&) {
                // Character sprite not found, skip this character
                std::cout << "Warning: Character sprite not found" << std::endl;
            }
        }
    }

    window.setView(this->cam.view);

    window.display();
}

void Game::run(sf::RenderWindow &window) {

    while(running) {
        m_entities.update();

        handleInput(window);
        update();
        checkCollisions(window);
        render(window);

        m_currentFrame++;
    }

}

// Character creation functions
void Game::createCharacter(sf::Vector2f position, int playerId) {
    auto character = this->m_entities.addEntity(std::make_shared<std::string>(STICKMAN_TAG));
    
    // Set position
    character->cPos = std::make_shared<CPos>(position);
    
    // Add physics/transform
    character->cTransform = std::make_shared<CTransform>();
    
    // Add health system
    character->cHealth = std::make_shared<CHealth>(100, position);
    
    // Add input handling
    character->cInput = std::make_shared<CInput>();
    character->cInput->idx = playerId;  // Set player ID
    
    // Add state management
    character->cState = std::make_shared<CState>();
    
    // Add collision detection
    character->cCollision.push_back(std::make_shared<CCollision>(position, 32.0f, 64.0f));
    
    // Add texture/sprite for character
    character->cTexture = std::make_shared<CTexture>(0);  // Use first character sprite
}

void Game::createMultipleCharacters(const std::vector<sf::Vector2f>& spawnPoints) {
    for(size_t i = 0; i < spawnPoints.size(); i++) {
        createCharacter(spawnPoints[i], i);
    }
}

// void moveAll(std::shared_ptr<Entity> , sf::Vector2f);
// void createSkeletonBoundingBoxes(std::shared_ptr<Entity>);
// void spawnStickman(bool, bool, bool, bool, bool, bool, bool, bool, int);

