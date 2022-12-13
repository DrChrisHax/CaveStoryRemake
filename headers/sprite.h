#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
public:
    Sprite();
    Sprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Spirte();
    virtual void update();
    void draw(Graphics& graphics, int x, int y);
private:
    SDL_Rect mSourceRect;
    SDL_Texture* mSpriteSheet;

    float mPosX, mPosY;
};


#endif