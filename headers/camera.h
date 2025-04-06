#ifndef CAMERA_H_
#define CAMERA_H_

#include <SFML/Graphics.hpp>

class Camera {
public:
    sf::RectangleShape map, center;
    sf::View view;

    void moveView(sf::Vector2f);
    void checkBoxesCollision(sf::RectangleShape = sf::RectangleShape());
    
    Camera();
    Camera(int, int, int = 1280, int = 768, sf::Vector2f = sf::Vector2f(0, 0));
    ~Camera();
};

#endif