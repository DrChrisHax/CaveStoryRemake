//Chris Manlove
#include "sprite.h"
#include "globals.h"


Sprite::Sprite() {}

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
        float posX, float posY) : 
            mPosX(posX),
            mPosY(posY)
{
    this->mSourceRect.x = sourceX;
    this->mSourceRect.y = sourceY;
    this->mSourceRect.w = width;
    this->mSourceRect.h = height;
    
    this->mSpriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if(this->mSpriteSheet == NULL)
        printf("\nError: Unable to load image\n");
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics& graphics, int x, int y) {
    SDL_Rect destinationRectangle = {x, y, this->mSourceRect.w * globals::SPRITE_SCALE, 
        this->mSourceRect.h * globals::SPRITE_SCALE};
    graphics.blitSurface(this->mSpriteSheet, &this->mSourceRect, &destinationRectangle);
}

void Sprite::update() {}