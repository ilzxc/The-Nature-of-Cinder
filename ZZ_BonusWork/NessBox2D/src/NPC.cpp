//
//  NPC.cpp
//  NessBox2D
//
//  Created by Ilya Rostovtsev on 7/5/13.
//
//

#include "NPC.h"

using namespace ci;

NPC::NPC(const ci::Surface * spriteSheet, const gl::Texture::Format &fmt, const int spriteSizeX, const int spriteSizeY, const int sizeX, const int sizeY) {
    size = Area(0, 0, sizeX, sizeY);
    step = 50;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            Area subset = Area(spriteSizeX * i, spriteSizeY * j, spriteSizeX * i + spriteSizeX, spriteSizeY * j + spriteSizeY);
            frames[i][j] = gl::Texture( spriteSheet->clone( subset ), fmt );
        }
    }
    
    direction = 1;
    position = ci::app::getWindowCenter();
    timeBetweenFrames = 0.2;
}

void NPC::draw() {
    gl::pushMatrices();
    gl::translate(position.x, position.y);
    if (!moving) {
        if((direction != 1) && (direction != 5)) {
            gl::draw( frames[direction][0], size );
        } else if (direction == 1) {
            gl::draw( frames[0][0], size );
        } else {
            gl::draw( frames[0][1], size );
        }
    } else {
        if( ci::app::getElapsedSeconds() - switchedLastFrame >= timeBetweenFrames ) {
            frameTwo++;
            frameTwo %= 2;
            switchedLastFrame = ci::app::getElapsedSeconds();
        }
        gl::draw( frames[direction][frameTwo], size );
    }
    
    gl::popMatrices();
}

void NPC::update() {
    
    if (timer >= timeToNext) {
        timer = 0.0;
        Rand::randomize();
        timeToNext = randFloat(0.5f, 5.5f);
        if (randInt(0, 2) == 0) {
            moving = false;
        } else {
            moving = true;
            direction = randInt(1, 9);
        }
    }
    deltaTime = ci::app::getElapsedSeconds() - previousFrameTime;
    previousFrameTime = ci::app::getElapsedSeconds();
    timer += deltaTime;
    if (moving) {
        stepSize = step * deltaTime;
        switch (direction) {
            case 1:
                position.y += stepSize;
                break;
            case 2:
                position.x -= stepSize; position.y += stepSize;
                break;
            case 3:
                position.x -= stepSize;
                break;
            case 4:
                position.y -= stepSize; position.x -= stepSize;
                break;
            case 5:
                position.y -= stepSize;
                break;
            case 6:
                position.x += stepSize; position.y -= stepSize;
                break;
            case 7:
                position.x += stepSize;
                break;
            case 8:
                position.x += stepSize; position.y += stepSize;
                break;
        }
    }
}


void NPC::setMoving(const bool go){
    if (moving != go ) { // only update if go differs from current state
        moving = go;
        frameTwo = 0;
        if (go) {
            switchedLastFrame = ci::app::getElapsedSeconds();
        }
    }
}

float NPC::getY(){
    return position.y;
}
