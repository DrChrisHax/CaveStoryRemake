//Chris Manlove
#include "level.h"

Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics& graphics) {
    mMapName = mapName;
    mSpawnPoint = spawnPoint;
    mSize = Vector2(0,0);

    this->loadMap(mapName, graphics);
}

Level::~Level() {}

void Level::loadMap(std::string mapName, Graphics& graphics) {
    //TEMPORARY CODE
    this->mBackgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("../contents/backgrounds/bkBlue.png"));
    this->mSize = Vector2(1280, 960); //Double the screen size
}

void Level::update(int elapsedTime) {

}

void Level::draw(Graphics& graphics) {
    SDL_Rect sourceRect = { 0, 0, 64, 64};
    SDL_Rect destRect;
    for(int x = 0; x < this->mSize.x / 64; x++) {
        for(int y = 0; y < this->mSize.y / 64; y++) {
            destRect.x = x * 64;
            destRect.y = y * 64;
            destRect.w = 64;
            destRect.h = 64;
            graphics.blitSurface(this->mBackgroundTexture, &sourceRect, &destRect);
        }
    }
}
