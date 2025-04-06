#include "../headers/camera.h"


#include <iostream>

Camera::Camera() {

}

Camera::Camera(int map_width, int map_height, int view_width, int view_height, sf::Vector2f view_location) {
    this->map.setSize(sf::Vector2f((float)map_width, (float)map_height));
    this->map.setPosition(sf::Vector2f(0, 0));

    this->view = sf::View(sf::FloatRect((view_location.x + 32) - view_width/2.0, (view_location.y + 32)- view_height/2.0, view_width, view_height));
}

Camera::~Camera() {

}

void Camera::moveView(sf::Vector2f vec) {
    this->view.move(vec);
    this->checkBoxesCollision();
}

void Camera::checkBoxesCollision(sf::RectangleShape BB) {
    BB.getFillColor();
    // check collision between boundingboxes and center
    // update location of view based on collisiong between BB and center
    if(this->view.getCenter().x - this->view.getSize().x/2.0 < 0) {
        this->view.move(sf::Vector2f(abs(this->view.getCenter().x - this->view.getSize().x/2.0), 0));
    }
    else if(this->view.getCenter().y - this->view.getSize().y/2.0 < 0) {
        this->view.move(sf::Vector2f(0.0, abs(this->view.getCenter().y - this->view.getSize().y/2.0)));
    }
    else if(this->view.getCenter().x > (this->map.getGlobalBounds().width - this->view.getSize().x/2.0)) {
        this->view.move(sf::Vector2f((this->map.getGlobalBounds().width - this->view.getSize().x/2.0) - this->view.getCenter().x, 0.0));
    }
    else if(this->view.getCenter().y > (this->map.getGlobalBounds().height - this->view.getSize().y/2.0)) {
        this->view.move(sf::Vector2f(0.0, (this->map.getGlobalBounds().height - this->view.getSize().y/2.0) - this->view.getCenter().y));
    }

    // update location of center if there is any collision between map and view
}
