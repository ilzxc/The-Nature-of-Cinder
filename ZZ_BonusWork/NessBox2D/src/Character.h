//
//  Character.h
//  NessBox2D
//
//  Created by Ilya Rostovtsev on 6/29/13.
//
//

#ifndef __NessBox2D__Character__
#define __NessBox2D__Character__

#include "cinder/ImageIo.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include <iostream>

using namespace ci;

class Character {
    
private:
    gl::Texture frames[9][2];      // textures live on the GPU
    bool moving, currentCharacter;
    int direction;
    Vec2f position;
    Area size;
    double deltaTime;
    double previousFrameTime;
    double switchedLastFrame;
    double timeBetweenFrames;
    int frameTwo;
    float step;
    float stepSize;
    
    void input(const bool keysPressed[]);
    void setMoving(const bool go);
    void setRun(const bool run);
    
public:
    Character() {}
    Character(const ci::Surface *spriteSheet, const ci::gl::Texture::Format &fmt, const int spriteSizeX, const int spriteSizeY, const int sizeX, const int sizeY);
    void draw();
    void update(const bool keysPressed[]);
    float getY();

    
};

#endif /* defined(__NessBox2D__Character__) */
