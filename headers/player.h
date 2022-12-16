//Chris Manlove
#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"

class Player : public AnimatedSprite{
public:
    Player();
    Player(Graphics& graphics, float x, float y);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimation();
private:
};

#endif