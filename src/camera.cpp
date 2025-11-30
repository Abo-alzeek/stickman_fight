#include "../headers/camera.h"

#include <iostream>

// Constants to replace magic numbers
const float VIEW_OFFSET = 32.0f;

Camera::Camera() {

}

Camera::Camera(int map_width, int map_height, int view_width, int view_height, sf::Vector2f view_location) {
    this->map.setSize(sf::Vector2f((float)map_width, (float)map_height));
    this->map.setPosition(sf::Vector2f(0, 0));

    // Create view centered on view_location
    this->view.setSize(sf::Vector2f((float)view_width, (float)view_height));
    this->view.setCenter(sf::Vector2f(view_location.x + VIEW_OFFSET, view_location.y + VIEW_OFFSET));
}

Camera::~Camera() {

}

void Camera::moveView(sf::Vector2f vec) {
    this->view.move(vec);
    this->checkBoxesCollision();
}

void Camera::checkBoxesCollision(sf::RectangleShape BB) {
    // BB.getFillColor();
    // check collision between boundingboxes and center
    // update location of view based on collisiong between BB and center
    
    // Get current view bounds for cleaner code
    sf::Vector2f viewCenter = this->view.getCenter();
    sf::Vector2f viewSize = this->view.getSize();
    sf::Vector2f mapSize = this->map.getGlobalBounds().size;
    
    // Check left boundary
    if(viewCenter.x - viewSize.x/2.0 < 0) {
        this->view.move(sf::Vector2f(abs(viewCenter.x - viewSize.x/2.0), 0));
    }
    // Check top boundary
    else if(viewCenter.y - viewSize.y/2.0 < 0) {
        this->view.move(sf::Vector2f(0.0, abs(viewCenter.y - viewSize.y/2.0)));
    }
    // Check right boundary
    else if(viewCenter.x > (mapSize.x - viewSize.x/2.0)) {
        this->view.move(sf::Vector2f((mapSize.x - viewSize.x/2.0) - viewCenter.x, 0.0));
    }
    // Check bottom boundary
    else if(viewCenter.y > (mapSize.y - viewSize.y/2.0)) {
        this->view.move(sf::Vector2f(0.0, (mapSize.y - viewSize.y/2.0) - viewCenter.y));
    }

    // update location of center if there is any collision between map and view
}
