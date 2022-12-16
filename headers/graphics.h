//Chris Manlove
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <map>
#include <string>


class Graphics {
public:
    Graphics();
    ~Graphics();

    //Loads sprite map if it does not already exist
    //Each image is only ever loaded once
    SDL_Surface* loadImage(const std::string& filePath);
    
    //Draws a texture to the screen
    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    //Renders everything to the screen
    void render();

    //Clears the screen
    void clear();

    //Returns the renderer
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    std::map<std::string, SDL_Surface*> mSpriteSheets;
};


#endif