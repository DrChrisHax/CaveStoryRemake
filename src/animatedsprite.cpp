//Chris Manlove
#include "animatedsprite.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, 
        int width, int height, float posX, float posY, float timeToUpdate) : 
                Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY) {
        mFrameIndex = 0;
        mTimeToUpdate = timeToUpdate;
        mVisible = true;
        mCurrentAnimationOnce = false;
        mCurrentAnimation = ""; 
}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset) {
        std::vector<SDL_Rect> rectangles; //Temp hold on to rectangles to add to map
        for(int i = 0; i < frames; i++) {
                SDL_Rect newRect = { (i + x) * width, y, width, height };
                rectangles.push_back(newRect);
        }
        this->mAnimations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
        this->mOffsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
        this->mCurrentAnimationOnce = once;
        if(this->mCurrentAnimation != animation) {
                this->mCurrentAnimation = animation;
                this->mFrameIndex = 0;
        }
}


void AnimatedSprite::resetAnimation() {
        this->mAnimations.clear();
        this->mOffsets.clear();
}

void AnimatedSprite::stopAnimation() {
        this->mFrameIndex = 0;
        this->animationDone(this->mCurrentAnimation);
}

void AnimatedSprite::setVisible(bool visible) {
        this->mVisible = visible;
}

void AnimatedSprite::update(int elapsedTime) {
        Sprite::update();

        this->mTimeElapsed += elapsedTime;
        if(this->mTimeElapsed > this->mTimeToUpdate) {
                this->mTimeElapsed -= this->mTimeToUpdate;
                //Checks if at last frame in index
                if(static_cast<unsigned long int>(this->mFrameIndex) < this->mAnimations[this->mCurrentAnimation].size() - 1) { 
                        mFrameIndex++;
                }
                else {
                        if(this->mCurrentAnimationOnce)
                                this->setVisible(false);
                        this->stopAnimation();
                }
        }
}

void AnimatedSprite::draw(Graphics& graphics, int x, int y) {
        if(this->mVisible) {
                SDL_Rect destinationRectangle;
                destinationRectangle.x = x + this->mOffsets[this->mCurrentAnimation].x;
                destinationRectangle.y = y + this->mOffsets[this->mCurrentAnimation].y;
                destinationRectangle.w = this->mSourceRect.w * globals::SPRITE_SCALE;
                destinationRectangle.h = this->mSourceRect.h * globals::SPRITE_SCALE;

                SDL_Rect sourceRect = this->mAnimations[this->mCurrentAnimation][this->mFrameIndex];
                graphics.blitSurface(this->mSpriteSheet, &sourceRect, & destinationRectangle);
        }
}

