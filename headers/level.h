#ifndef LEVEL_H
#define LEVEL_H

#include "globals.h"
#include "graphics.h"

class Level {
public:
    Level();
    Level(std::string mapName, Vector2 spawnPoint, Graphics& graphics);
    ~Level();
    void update(int elapsedTime);
    void draw(Graphics& graphics);

private:
    std::string mMapName;
    Vector2 mSpawnPoint;
    Vector2 mSize;
    SDL_Texture* mBackgroundTexture;

    //Only called from within level class
    void loadMap(std::string mapName, Graphics& graphics);
};

#endif