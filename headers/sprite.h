//Chris Manlove
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include <string>

#include "globals.h"
#include "graphics.h"

class Sprite {
public:
    Sprite();
    Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics& graphics, int x, int y);
protected:
    SDL_Rect mSourceRect;
    SDL_Texture* mSpriteSheet;
private:

    float mPosX, mPosY;
};


#endif