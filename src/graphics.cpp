#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"

Graphics::Graphics() {
    //int Width, int Height, int Flags, Refernce to window, Reference to renderer
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->pWindow, &this->pRenderer);
    SDL_SetWindowTitle(this->pWindow, "Cavestory");
}
Graphics::~Graphics() {
    SDL_DestroyWindow(this->pWindow);
}
SDL_Surface* Graphics::loadImage(const std::string& filePath) {
    if(this->pSpriteSheets.count(filePath) == 0) {
        this->pSpriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->pSpriteSheets[filePath];
}
void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->pRenderer, texture, sourceRectangle, destinationRectangle);
}
void Graphics::render() {
    SDL_RenderPresent(this->pRenderer);
}
void Graphics::clear() {
    SDL_RenderClear(this->pRenderer);
}
SDL_Renderer* Graphics::getRenderer() const {
    return this->pRenderer;
}



