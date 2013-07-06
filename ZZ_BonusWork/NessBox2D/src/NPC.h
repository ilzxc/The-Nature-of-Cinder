//
//  NPC.h
//  NessBox2D
//
//  Created by Ilya Rostovtsev on 7/5/13.
//
//

#ifndef __NessBox2D__NPC__
#define __NessBox2D__NPC__

#include "cinder/ImageIo.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

using namespace ci;

class NPC {
    
private:
    gl::Texture frames[9][2];      // textures live on the GPU
    bool moving;
    int direction;
    Vec2f position;
    Area size;
    Rectf bounds;
    double timer, timeToNext;
    double deltaTime;
    double previousFrameTime;
    double switchedLastFrame;
    double timeBetweenFrames;
    int frameTwo;
    float step;
    float stepSize;
    
    void setMoving(const bool go);
    
public:
    NPC() {}
    NPC(const ci::Surface *spriteSheet, const ci::gl::Texture::Format &fmt, const int spriteSizeX, const int spriteSizeY, const int sizeX, const int sizeY);
    void draw();
    void update();
    float getY();
    
};

#endif /* defined(__NessBox2D__NPC__) */
