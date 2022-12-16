//Chris Manlove
#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"

//Forward declare SDL objects
struct SDL_Rect;
struct SDL_Texture;

class Sprite {
public:
    Sprite();
    Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics& graphics, int x, int y);
private:
    SDL_Rect mSourceRect;
    SDL_Texture* mSpriteSheet;

    float mPosX, mPosY;
};


#endif