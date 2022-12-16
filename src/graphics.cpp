//Chris Manlove
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics() {
    //int Width, int Height, int Flags, Refernce to window, Reference to renderer
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->mWindow, &this->mRenderer);
    SDL_SetWindowTitle(this->mWindow, "Cavestory");
}
Graphics::~Graphics() {
    SDL_DestroyWindow(this->mWindow);
}
SDL_Surface* Graphics::loadImage(const std::string& filePath) {
    if(this->mSpriteSheets.count(filePath) == 0) {
        this->mSpriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->mSpriteSheets[filePath];
}
void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->mRenderer, texture, sourceRectangle, destinationRectangle);
}
void Graphics::render() {
    SDL_RenderPresent(this->mRenderer);
}
void Graphics::clear() {
    SDL_RenderClear(this->mRenderer);
}
SDL_Renderer* Graphics::getRenderer() const {
    return this->mRenderer;
}



