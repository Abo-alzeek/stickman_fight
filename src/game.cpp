#include "../headers/game.h"

Game::Game(std::shared_ptr<ResourceManager>(rm) , int x, sf::RenderWindow &window, int screen_width, int screen_height) {
    this->m_resources = rm;
    std::vector<sf::Vector2f> spawning_points;
    this->map = std::make_shared<MyMap>(m_resources->maps[x]);
    
    for(int i = 0;i < (int)this->map->tiles.size();i++) {
        for(int j = 0;j < (int)this->map->tiles[i].size();j++) {
            std::cout << this->map->tiles[i][j] << " ";

            if(this->map->tiles[i][j] == -1) {
                spawning_points.push_back(sf::Vector2f(j * 64.0, i * 64.0));
            }
            else if(this->map->tiles[i][j] != Tiles::NOTHING) {
                auto e = this->m_entities.addEntity(std::make_shared<std::string>(tileTag));

                e->cPos = std::make_shared<CPos>(j * 64.0, i * 64.0);

                e->cCollision.push_back(std::make_shared<CCollision>(e->cPos->position, 64.0, 64.0));

                e->cTextrue = std::make_shared<CTexture>(this->map->tiles[i][j]);
            }
        }
        std::cout << std::endl;
    }

    this->cam = Camera(this->map->tiles[0].size() * 64.0, this->map->tiles.size() * 64.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]);
    
    // if(this->playersCount == 1) this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0, this->map->tiles.size() * 64.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    // else if(this->playersCount == 2) {
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    // }
    // else if(this->playersCount == 3) {
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0 / 2.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0 / 2.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    // }
    // else if(this->playersCount == 4) {
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0 / 2.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0 / 2.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0 / 2.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    //     this->cams.push_back(Camera(this->map->tiles[0].size() * 64.0 / 2.0, this->map->tiles.size() * 64.0 / 2.0, screen_width, screen_height, spawning_points[rand() % (int)spawning_points.size()]));
    // }

    this->run(window);
}

Game::~Game() {

}

void Game::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while(window.pollEvent(event)) {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                this->running = false;
            break;
            case sf::Event::KeyPressed:            
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        this->running = false;
                        break;
                    case sf::Keyboard::A:
                        this->cam.moveView(sf::Vector2f(-10.0, 0.0));

                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL && abs(e->cState->state) != Animations::STICKMAN_DAMAGE && abs(e->cState->state) != Animations::STICKMAN_DIE) {
                        //         e->cState->toUpdate = -1 * Animations::STICKMAN_RUN;
                        //         break;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::D:
                        this->cam.moveView(sf::Vector2f(10.0, 0.0));
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL && abs(e->cState->state) != Animations::STICKMAN_DAMAGE && abs(e->cState->state != Animations::STICKMAN_DIE)) {
                        //         e->cState->toUpdate = Animations::STICKMAN_RUN;
                        //         break;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::F:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL && abs(e->cState->state) != Animations::STICKMAN_DAMAGE && abs(e->cState->state) != Animations::STICKMAN_DIE) {
                        //         e->cState->toUpdate = Animations::STICKMAN_PUNCH * e->cAnimation->invert;
                        //         break;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::S:
                        this->cam.moveView(sf::Vector2f(0.0, 10.0));
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL && abs(e->cState->state) != Animations::STICKMAN_DAMAGE && abs(e->cState->state != Animations::STICKMAN_DIE)) {
                        //         e->cState->toUpdate = Animations::STICKMAN_RUN;
                        //         break;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::W:
                        this->cam.moveView(sf::Vector2f(0.0, -10.0));
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL && abs(e->cState->state) != Animations::STICKMAN_DAMAGE && abs(e->cState->state != Animations::STICKMAN_DIE)) {
                        //         e->cState->toUpdate = Animations::STICKMAN_RUN;
                        //         break;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::Space:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL && abs(e->cState->state) != Animations::STICKMAN_DAMAGE && abs(e->cState->state) != Animations::STICKMAN_DIE) {
                        //         e->cState->toUpdate = Animations::STICKMAN_JUMP * e->cAnimation->invert;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::Up:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL) {
                        //         e->cInput->idx = (e->cInput->idx + 1) % 10;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::Down:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL) {
                        //         e->cInput->idx = (e->cInput->idx - 1 + 10) % 10;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::Right:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL) {
                        //         e->cInput->angle = (e->cInput->angle + 5) % 360;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::Left:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL) {
                        //         e->cInput->angle = (e->cInput->angle - 5 + 360) % 360;
                        //     }
                        // }
                        break;
                    default:
                        break;
                }
            break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        this->running = false;
                        break;
                    case sf::Keyboard::A:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL) {
                        //         if(e->cState->state == -1) e->cState->toUpdate = Animations::STICKMAN_IDLE;
                        //         break;
                        //     }
                        // }
                        break;
                    case sf::Keyboard::D:
                        // for(auto e : m_entities.getEntities()) {
                        //     if(e->cInput != NULL) {
                        //         if(e->cState->state == 1) e->cState->toUpdate = Animations::STICKMAN_IDLE;
                        //         break;
                        //     }
                        // }
                        break;
                    default:
                        break;
                }
            break;
        default:
            break;
        }
    }
}

void Game::update() {

}

void Game::checkCollisions(sf::RenderWindow &) {

}

void Game::render(sf::RenderWindow &window) {
    window.clear(sf::Color(255, 255, 255, 255));

    window.draw( this->m_resources->sprites[this->map->background] );

    for(auto e : m_entities.getEntities(tileTag)) {
        this->m_resources->sprites[e->cTextrue->sprite].setPosition(e->cPos->position);
        window.draw(this->m_resources->sprites[e->cTextrue->sprite]);
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

// void moveAll(std::shared_ptr<Entity> , sf::Vector2f);
// void createSkeletonBoundingBoxes(std::shared_ptr<Entity>);
// void spawnStickman(bool, bool, bool, bool, bool, bool, bool, bool, int);

