//Chris Manlove
#include <SDL2/SDL.h>

#include "game.h"
#include "input.h"


namespace {
    const int FPS = 60; //Change to 50 if physics errors later on
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}
Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}
Game::~Game(){

}
void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    this->mPlayer = Sprite(graphics, "../contents/sprites/MyChar.png", 0, 0, 16, 16, 100, 100);
    
    int lastUpdateTime = SDL_GetTicks();
    //Start game loop
    while(true) {
        input.beginNewFrame();

        if(SDL_PollEvent(&event)) {
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) { //Not holding down key
                    input.keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT) return; //Closes the game window (X buton clicked)

        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) return; //Closes the game window (escape pressed)

        int currentTimeMS = SDL_GetTicks();
        int elapsedTimeMS = currentTimeMS - lastUpdateTime;
        this->update(std::min(elapsedTimeMS, MAX_FRAME_TIME)); 
        lastUpdateTime = currentTimeMS;

        this->draw(graphics);
    }
}
void Game::draw(Graphics& graphics) {
    graphics.clear();

    this->mPlayer.draw(graphics, 100, 100);

    graphics.render();

}
void Game::update(float elapsedTime) {

}