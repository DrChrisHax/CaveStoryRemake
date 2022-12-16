//Chris Manlove
#ifndef GAME_H
#define GAME_H

#include "sprite.h"


class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics& graphics);
    void update(float elapsedTime);

    Sprite mPlayer;


};



#endif