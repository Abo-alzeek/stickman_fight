#include "../headers/Components.h"


CPos::CPos() {

}

CPos::CPos(sf::Vector2f pos) {
    this->position = pos;
}

CPos::CPos(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}

CPos::~CPos() {
    
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CTransform::CTransform() {
    this->gravity = {0, 0};
    this->velocity = {0, 0};
}

CTransform::CTransform(sf::Vector2f gr, sf::Vector2f velo) {
    this->gravity = gr;
    this->velocity = velo;
}

CTransform::~CTransform() {
    ;
}

void CTransform::move(sf::Vector2f &pos) {
    pos += this->velocity;
}

void CTransform::setVelocity(sf::Vector2f &velo) {
    this->velocity = velo;
}
void CTransform::updateVelocity(sf::Vector2f &velo) {
    this->velocity += velo;
}

void CTransform::setGravity(sf::Vector2f &gr) {
    this->gravity = gr;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CCollision::CCollision() {
    ;
}

CCollision::~CCollision() {
    ;
}


CCollision::CCollision(sf::Vector2f topLeft, float width, float height) {
    this->boundingBox.setPosition(topLeft);
    this->boundingBox.setSize(sf::Vector2f(width, height));

}

void CCollision::updatePosition(sf::Vector2f &pos)  {
    this->boundingBox.setPosition(pos);
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CTexture::~CTexture() {
    ;
}

CTexture::CTexture() {
    ;
}

CTexture::CTexture(int s) {
    this->sprite = s;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CInput::CInput() {
    ;
}

CInput::~CInput() {
    ;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CState::CState() {
    this->state = 0;
    this->lastFrameState = 0;
    this->toUpdate = INF;
    this->lastState = 0;
    this->hp = 100;
}

CState::~CState() {
    ;
}

void CState::update() {
    this->state = this->toUpdate;
    this->toUpdate = this->INF;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

CHealth::CHealth() {
    ;
}

CHealth::~CHealth() {
    ;
}

CHealth::CHealth(int hp, sf::Vector2f v) {
    this->HP = hp;

    this->healthBar.setSize(sf::Vector2f(100, 10));
    this->healthBar.setPosition(v);
    this->healthBar.setOutlineThickness(2);
    this->healthBar.setOutlineColor(sf::Color::Black);
    this->healthBar.setFillColor(sf::Color::White);

    this->health.setSize(sf::Vector2f(100 * (this->HP / 100.0), 10));
    this->health.setFillColor(sf::Color::Red);
    this->health.setPosition(v);
}

void CHealth::setBarsPosition(sf::Vector2f v) {
    this->health.setPosition(v);
    this->healthBar.setPosition(v);
}

void CHealth::updateHealth(int upd) {    
    HP += upd;

    if(HP < 0) HP = 0;

    this->health.setSize(sf::Vector2f(100 * (this->HP / 100.0), 10));
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// CBones::CBones() {
//     // std::cout << "KOS" << std::endl;
//     ;
// }

// CBones::~CBones() {
//     // std::cout << "KOS" << std::endl;
//     ;
// }

// void CBones::addBone(sf::Vector2f p1, sf::Vector2f p2, int p, int side, float length, int isHead) {
//     Bone b;

//     if(p > -1) {
//         if(side == 1) b.p1 = this->bones[p].p1;
//         else          b.p1 = this->bones[p].p2;

//         if(isHead) length *= -1;
//         b.p2.x = b.p1.x;
//         b.p2.y = b.p1.y + length;
        
//         this->bones[p].children.push_back( (int)this->bones.size() );
//     }
//     else {
//         b.p1 = p1;
//         b.p2 = p2;
//     }

//     b.parent = p;
//     b.length = abs(length);
//     b.side = side;
    
//     if(isHead == 1) b.init(isHead, length);
//     else b.init(0);

//     this->bones.push_back(b);
// }

// void CBones::makeHumanSkeleton(float waist = 25.0, float backBone = 45.0, float arm = 35.0, float hand = 37.0, float leg = 35.0, float foot = 40.0, float neck = 25.0, float head = 20.0) {
//     sf::Vector2f p1, p2, no;
//     p1.x = 600;
//     p1.y = 300;
//     p2.x = p1.x;
//     p2.y = p1.y + waist;
//     no.x = -1;
//     no.y = -1;

//     this->addBone(p1, p2, -1, -1, waist, 0);
//     this->addBone(no, no, STICKPARTS::WAIST, 1, backBone, 0);
//     this->addBone(no, no, STICKPARTS::BACK, 2, arm, 0); // right 
//     this->addBone(no, no, STICKPARTS::BACK, 2, arm, 0); // left
//     this->addBone(no, no, STICKPARTS::RIGHT_ARM, 2, hand, 0); // right 
//     this->addBone(no, no, STICKPARTS::LEFT_ARM, 2, hand, 0); // left
//     this->addBone(no, no, STICKPARTS::WAIST, 2, leg, 0); // right leg
//     this->addBone(no, no, STICKPARTS::WAIST, 2, leg, 0); // left leg
//     this->addBone(no, no, STICKPARTS::RIGHT_LEG, 2, foot, 0); // right foot
//     this->addBone(no, no, STICKPARTS::LEFT_LEG, 2, foot, 0); // left foot
//     this->addBone(no, no, STICKPARTS::BACK, 2, neck, 0);
//     this->addBone(no, no, STICKPARTS::NECK, 2, head, 1);
//     this->rotateBone(STICKPARTS::NECK, 180);
//     this->rotateBone(STICKPARTS::BACK, 180);
// }

// void CBones::moveBone(int id, sf::Vector2f v) {
//     this->bones[id].p1 += v;
//     this->bones[id].p2 += v;

//     this->bones[id].update();
//     this->update(id);
// }

// void CBones::setBonePosition(int id, sf::Vector2f v) {
//     float x = this->bones[id].p1.x;
//     float y = this->bones[id].p1.y;

//     x = v.x - x;
//     y = v.y - y;

//     this->bones[id].p1.x += x;
//     this->bones[id].p1.y += y;

//     this->bones[id].p2.x += x;
//     this->bones[id].p2.y += y;

//     this->bones[id].update();
//     this->update(id);
// }

// void CBones::rotateBone(int id, float deg) {
//     float x = this->bones[id].p2.x - this->bones[id].p1.x;
//     float y = (this->bones[id].p2.y - this->bones[id].p1.y) * -1;
//     float r = this->bones[id].length;

//     if(abs(x) < 1e-4) x = 0;
//     if(abs(y) < 1e-4) y = 0;
    
//     float X = r * cos(atan2(y, x) + PI / 180.0 * deg);
//     float Y = r * sin(atan2(y, x) + PI / 180.0 * deg);

//     if(abs(X) < 1e-4) X = 0;
//     if(abs(Y) < 1e-4) Y = 0;

//     x = X;
//     y = -Y;

//     x += this->bones[id].p1.x;
//     y += this->bones[id].p1.y;
    
//     this->bones[id].p2.x = x;
//     this->bones[id].p2.y = y;

//     this->bones[id].R.rotate(-deg);
//     this->bones[id].update();

//     this->update(id);
// }

// void CBones::setBoneAngle(int id, float deg) {
//     // std::cout << "ROTATING BONE " << id << " ANGLE EQUALS: " << deg << std::endl;
//     float x = this->bones[id].p2.x - this->bones[id].p1.x;
//     float y = (this->bones[id].p2.y - this->bones[id].p1.y) * -1;

//     float newAngle = (PI / 180.0 * deg - atan2(y, x));
//     this->rotateBone(id, newAngle * 180.0 / PI);
// }

// void CBones::update(int u) {
//     bones[u].update();

//     for(auto v : bones[u].children) {
//         sf::Vector2f move;

//         if(bones[v].side == 1) {
//             move.x = bones[u].p1.x - bones[v].p1.x;
//             move.y = bones[u].p1.y - bones[v].p1.y;
//             bones[v].p1 = bones[u].p1;
//         }
//         else {
//             move.x = bones[u].p2.x - bones[v].p1.x;
//             move.y = bones[u].p2.y - bones[v].p1.y;
//             bones[v].p1 = bones[u].p2;
//         }

//         bones[v].p2.x += move.x;
//         bones[v].p2.y += move.y;


//         this->update(v);
//     }
// }

// void CBones::printState() {
//     for(int i = 0;i < (int)bones.size();i++) {
//         std::cout << i << ": " << atan2(bones[i].p2.y - bones[i].p1.y, bones[i].p2.x - bones[i].p1.x) * 180.0 / PI << std::endl;
//     }
//     std::cout << "-----" << std::endl;
// }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Bone::Bone() {
//     ;
// }
// Bone::~Bone() {
//     ;
// }


// void Bone::init(bool isHead, float radius)  {
//     if(isHead) {
//         c1.setRadius(radius);
//         c1.setOrigin(sf::Vector2f(radius, radius));
//         c1.setPosition(sf::Vector2f(p1.x, p1.y));
//         c1.setFillColor(sf::Color(0, 0, 0, 255));
//     }
//     else {
//         c1.setRadius(radius);
//         c1.setOrigin(sf::Vector2f(radius, radius));
//         c1.setPosition(sf::Vector2f(p1.x, p1.y));
//         c1.setFillColor(sf::Color(0, 0, 0, 255));

//         c2.setRadius(radius);
//         c2.setOrigin(sf::Vector2f(radius, radius));
//         c2.setPosition(sf::Vector2f(p2.x, p2.y));
//         c2.setFillColor(sf::Color(0, 0, 0, 255));

//         R = sf::RectangleShape(sf::Vector2f(2 * radius, abs(p1.y - p2.y)));
//         R.setOrigin(sf::Vector2f(radius, 0));
//         R.setPosition(sf::Vector2f(p1.x, p1.y));
//         R.setFillColor(sf::Color(0, 0, 0, 255));
//     }
// }

// void Bone::draw(sf::RenderWindow &window)  {
//     window.draw(R);
//     window.draw(c1);
//     window.draw(c2);
// }

// void Bone::update()  {
//     c1.setPosition(sf::Vector2f(p1.x, p1.y));
//     c2.setPosition(sf::Vector2f(p2.x, p2.y));
//     R.setPosition(sf::Vector2f(p1.x, p1.y));
// }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// CAnimation::CAnimation() {
//     currentFrame = 0;
//     framesCount = 10;
//     frameTL = 0.12;
//     currentAnimation = 0;

//     timer.restart();
// }

// CAnimation::~CAnimation() {
//     ;
// }

// void CAnimation::playAnimation(std::vector< std::vector<std::pair<int, float>> > &subMove, CBones &bones, std::shared_ptr<CState> &e) {
//     if( timer.getElapsedTime().asSeconds() >= this->frameTL ) {
//         currentFrame = (currentFrame + 1) % framesCount;
//         timer.restart();

//         if(!currentFrame && this->forceFrameOut > 0) this->forceFrameOut--;
//         if(!this->forceFrameOut) return;
//     }

//     for(int i = 0;i < (int)subMove[this->currentFrame].size();i++) {
//         bones.setBoneAngle( subMove[this->currentFrame][i].first, subMove[this->currentFrame][i].second );
//     }
// }

// void CAnimation::setAnimation(anime a, int in) {
//     // set timer and currentframe to zero
//     this->timer.restart();
//     this->currentFrame = 0;

//     // set frames count
//     this->framesCount = a.framesCount;

//     // set force frame out
//     this->forceFrameOut = a.forceStopAfter;

//     // set frame time
//     this->frameTL = a.frameTL;
//     this->moves = a.movement;

//     // set enum
//     this->currentAnimation = a.idx;

//     // set invert
//     if(in) this->invert = in / abs(in);

//     if(this->invert < 0) {
//         for(auto &m : moves) {
//             for(auto &sm : m) {
//                 sm.second = 180.0 - sm.second;
//             }
//         }
//     }


// }

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
