//Chris Manlove
#ifndef GAME_H
#define GAME_H

#include "animatedsprite.h"
#include "graphics.h"


class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics& graphics);
    void update(float elapsedTime);

    AnimatedSprite mPlayer;


};



#endif