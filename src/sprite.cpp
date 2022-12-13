#include "sprite.h"
#include "graphics.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
        float posX, float posY) : 
            mPosX(posX),
            mPosY(posY)
{
    this->sourceRect.x = sourceX;
    this->sourceRect.y = sourceY;
    this->sourceRect.w = width;
    this->sourceRect.h = height;
    
}