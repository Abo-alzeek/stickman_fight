#ifndef Components_h_
#define Components_h_

// #include "basic.h"

#include <memory>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

const double PI = acos(-1);


class CPos {
public:
    sf::Vector2f position;

    CPos();
    CPos(sf::Vector2f pos);
    CPos(float x, float y);
    ~CPos();
};

class CTransform {
public:
	sf::Vector2f velocity = {0, 0};
    sf::Vector2f gravity = {0, 0};

    CTransform();
    ~CTransform();
    CTransform(sf::Vector2f, sf::Vector2f);

    void setGravity(sf::Vector2f &);
    void setVelocity(sf::Vector2f &);
    void updateVelocity(sf::Vector2f &);

    void move(sf::Vector2f &);
};

class CCollision {
public:
	sf::RectangleShape boundingBox;

    CCollision();
	CCollision(sf::Vector2f, float, float);
    ~CCollision();

    void updatePosition(sf::Vector2f &);
};

class CTexture {
    public:
    int sprite;
    
    CTexture();
    CTexture(int);
    ~CTexture();
};

class CInput {
public:
    int idx = 1;
    int angle = 0;

    bool screen = false;

	CInput();
    ~CInput();
};

class CState {
public:
    int state;
    int lastFrameState;
    int toUpdate;
    int lastState;

    int hp;
    
    sf::Vector2f position;

    const int INF = 2e9;

    CState();
    ~CState();
    void update();
};


class CHealth {
public:
    int HP = 0;
    sf::RectangleShape healthBar, health;

    void updateHealth(int upd = -7);
    void setBarsPosition(sf::Vector2f);

    CHealth();
    ~CHealth();
    CHealth(int, sf::Vector2f);
};

#endif


// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------

// struct Bone {
//     Bone();
//     ~Bone();
    
//     sf::Vector2f p1, p2;
//     int side = 0;
//     int parent = 0;
//     float length = 0;
//     std::vector<int> children;

//     sf::CircleShape c1, c2;
//     sf::RectangleShape R;

//     void init(bool, float radius = 4.0);
//     void draw(sf::RenderWindow &);
//     void update();
// };

// class CBones {
// public:
//     std::vector< Bone > bones;
//     std::vector< std::pair<int, float> > subMoves;
//     std::vector< std::vector<std::pair<int, float>> > moves;
//     int remaining = 0, idx = 0;

//     CBones();
//     ~CBones();

//     void update(int);
//     void setBonePosition(int, sf::Vector2f);
//     void printState();
//     void moveBone(int, sf::Vector2f);
//     void rotateBone(int, float);
//     void setBoneAngle(int, float);
//     void addBone(sf::Vector2f, sf::Vector2f, int, int, float, int);
//     void makeHumanSkeleton(float, float, float, float, float, float, float, float);
// };

// ----------------------------------------------------------------------------------------------------------------------------------


// class CAnimation {
//     public:
//     float frameTL;
//     int invert = 1;
//     sf::Clock timer;
//     int currentFrame, framesCount;
//     int currentAnimation, forceFrameOut;
//     std::vector< std::vector<std::pair<int, float>> > moves;

//     CAnimation();
//     ~CAnimation();
//     // void setAnimation(anime, int);
//     void playAnimation(std::vector< std::vector<std::pair<int, float>> > &, CBones &, std::shared_ptr<CState> &);
// };
