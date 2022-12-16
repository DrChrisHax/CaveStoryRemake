//Chris Manlove
#include "input.h"

//Called at each new frame to reset
//keys that are not relevant
void Input::beginNewFrame() {
    this->mPressedKeys.clear();
    this->mReleasedKeys.clear();
}
//Key gets released
void Input::keyUpEvent(const SDL_Event& event) {
    this->mReleasedKeys[event.key.keysym.scancode] = true;
    this->mHeldKeys[event.key.keysym.scancode] = false;
}
//Key gets pressed
void Input::keyDownEvent(const SDL_Event& event) {
    this->mPressedKeys[event.key.keysym.scancode] = true;
    this->mHeldKeys[event.key.keysym.scancode] = true;

}
//Key pressed during current frame
bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->mPressedKeys[key];
}
//Key released during current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->mReleasedKeys[key];
}
//Key held during curent frame
bool Input::isKeyHeld(SDL_Scancode key) {
    return this->mHeldKeys[key];
}