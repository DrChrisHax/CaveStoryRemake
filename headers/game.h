//Chris Manlove
#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics& graphics);
    void update(float elapsedTime);

    Player mPlayer;


};



#endif