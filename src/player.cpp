//Chris Manlove
#include "player.h"

namespace player_constants {
    const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics& graphics, float x, float y) :
    AnimatedSprite(graphics, "../contents/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100)
{
    graphics.loadImage("../contents/sprites/MyChar.png");

    this->setupAnimation();
    this->playAnimation("RunRight");
}

void Player::setupAnimation() {
    //Frames, XPos, YPos, Name, Width, Height, Offset
    this->addAnimation(1, 0, 00, "IdleLeft",  16, 16, Vector2(0,0));
    this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0,0));
    this->addAnimation(3, 0, 00, "RunLeft",   16, 16, Vector2(0,0));
    this->addAnimation(3, 0, 16, "RunRight",  16, 16, Vector2(0,0));
    
}

void Player::animationDone(std::string currentAnimation) {}

void Player::moveLeft() {
    this->mdx = -player_constants::WALK_SPEED;
    this->playAnimation("RunLeft");
    this->mDirection = LEFT;
}

void Player::moveRight() {
    this->mdx = player_constants::WALK_SPEED;
    this->playAnimation("RunRight");
    this->mDirection = RIGHT;
}

void Player::stopMoving() {
    this->mdx = 0.0f;
    this->playAnimation(this->mDirection == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::update(float elapsedTime) {
    //Move by dx
    //ElapsedTime keeps everything moving at the same rate regardless of computer
    this->mPosX += this->mdx * elapsedTime;

    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
    AnimatedSprite::draw(graphics, this->mPosX, this->mPosY);
}




