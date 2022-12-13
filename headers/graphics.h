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
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    std::map<std::string, SDL_Surface*> pSpriteSheets;
};


#endif