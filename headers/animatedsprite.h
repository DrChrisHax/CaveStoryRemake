#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <vector>
#include "sprite.h"
#include "globals.h"

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, 
            float posX, float posY, float timeToUpdate);
    //Plays animation if not already playing
    //Bool determins loop or not
    void playAnimation(std::string animation, bool once = false);

    void update(int elapsedTime);
    void draw(Graphics& graphics, int x, int y);

protected:
    double mTimeToUpdate;
    bool mCurrentAnimationOnce;
    std::string mCurrentAnimation;

    //Adds animation to map of animations
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

    //Resets all animations for this sprite
    void resetAnimation();
    void stopAnimation();
    void setVisible(bool visible);
    virtual void animationDone(std::string currentAnimation) = 0;
    virtual void setupAnimation() = 0;
    

private:
    std::map<std::string, std::vector<SDL_Rect>> mAnimations;
    std::map<std::string, Vector2> mOffsets;

    int mFrameIndex;
    double mTimeElapsed;
    bool mVisible;
};


#endif