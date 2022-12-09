#include <SDL2/SDL.h>
#include "graphics.h"

Graphics::Graphics() {
    //int Width, int Height, int Flags, Refernce to window, Reference to renderer
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->pWindow, &this->pRenderer);
    SDL_SetWindowTitle(this->pWindow, "Cavestory");
}
Graphics::~Graphics() {
    SDL_DestroyWindow(this->pWindow);
}


