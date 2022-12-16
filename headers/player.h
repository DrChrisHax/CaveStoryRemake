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

    //Moves player negative dx (Left)
    void moveLeft();
    //Moves player positive dx (Right)
    void moveRight();
    //Stops moving player
    void stopMoving();

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimation();
private:
    float mdx, mdy; //Change in x and y position

    Direction mDirection;
};

#endif