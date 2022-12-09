#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

//Forward declare SDL objects
struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();

    SDL_Surface* loadImage(const::std string& filePath_);

private:
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    std::map<std::string, SDL_Surface*> pSpriteSheets;
};


#endif