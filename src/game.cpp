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

    this->mPlayer = Player(graphics, 100, 100);


    
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
            else if(event.type == SDL_QUIT) return; //Closes the game window (X button clicked)

        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) { return; } //Closes the game window (escape pressed)
        else if(input.isKeyHeld(SDL_SCANCODE_LEFT) ||
                input.isKeyHeld(SDL_SCANCODE_A)){ this->mPlayer.moveLeft();  } //Moves Left if left arrow or A is held
        else if(input.isKeyHeld(SDL_SCANCODE_RIGHT)||
                input.isKeyHeld(SDL_SCANCODE_D)){ this->mPlayer.moveRight(); } //Moves Right if right arrow or D is held
        
        if(!(input.isKeyHeld(SDL_SCANCODE_RIGHT) || input.isKeyHeld(SDL_SCANCODE_A) || 
             input.isKeyHeld(SDL_SCANCODE_LEFT)  || input.isKeyHeld(SDL_SCANCODE_D))) {
                this->mPlayer.stopMoving();
            }


        int currentTimeMS = SDL_GetTicks();
        int elapsedTimeMS = currentTimeMS - lastUpdateTime;
        this->update(std::min(elapsedTimeMS, MAX_FRAME_TIME)); 
        lastUpdateTime = currentTimeMS;

        this->draw(graphics);
    }
}
void Game::draw(Graphics& graphics) {
    graphics.clear();

    this->mPlayer.draw(graphics);

    graphics.render();

}
void Game::update(float elapsedTime) {
    this->mPlayer.update(elapsedTime);

}