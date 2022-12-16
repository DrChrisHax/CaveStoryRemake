//Chris Manlove
#ifndef SPRITE_H
#define SPRITE_H

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
    float mPosX, mPosY;
    SDL_Rect mSourceRect;
    SDL_Texture* mSpriteSheet;
private:
};


#endif