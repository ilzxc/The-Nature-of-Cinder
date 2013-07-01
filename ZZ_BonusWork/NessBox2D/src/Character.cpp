//
//  Character.cpp
//  NessBox2D
//
//  Created by Ilya Rostovtsev on 6/29/13.
//
//

#include "Character.h"

using namespace ci;

Character::Character(const ci::Surface &spriteSheet, const gl::Texture::Format &fmt, const int spriteSizeX, const int spriteSizeY, const int sizeX, const int sizeY) {
    size = Area(0, 0, sizeX, sizeY);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            Area subset = Area(spriteSizeX * i, spriteSizeY * j, spriteSizeX * i + spriteSizeX, spriteSizeY * j + spriteSizeY);
            frames[i][j] = gl::Texture( spriteSheet.clone( subset ), fmt );
        }
    }
    
    direction = 1;
    position = ci::app::getWindowCenter();
    timeBetweenFrames = 0.1;
    currentCharacter = true;
}

void Character::draw() {
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

void Character::update(const bool keysPressed[]) {
    
    // it has been ci::app::getElapsedSeconds() since the game started
    // it has been ci::app::getElapsedSeconds() - previousFrameTime since last frame
    deltaTime = ci::app::getElapsedSeconds() - previousFrameTime;
    previousFrameTime = ci::app::getElapsedSeconds();
    
    
    if (currentCharacter) {
        input(keysPressed);
    }
    
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

void Character::input(const bool keysPressed[]){
    
    if ( (!(keysPressed[0] || keysPressed[1] || keysPressed[2] || keysPressed[3])) || (keysPressed[0] && keysPressed[2]) || (keysPressed[1] && keysPressed[3]) ) {
        setMoving( false ); // setMoving off if the character is not moving (checking opposite directions)
    } else {
        if (keysPressed[0]) {
            direction = 3;
        }
        if (keysPressed[1]) {
            direction = 5;
        }
        if (keysPressed[2]) {
            direction = 7;
        }
        if (keysPressed[3]) {
            direction = 1;
        }
        if (keysPressed[0] && keysPressed[1]) {
            direction = 4;
        }
        if (keysPressed[0] && keysPressed[3]) {
            direction = 2;
        }
        if (keysPressed[2] && keysPressed[1]) {
            direction = 6;
        }
        if (keysPressed[2] && keysPressed[3]) {
            direction = 8;
        }
        setMoving( true ); // set moving true (after updating direction)
    }
    
    if (keysPressed[4]) { // run key
        setRun( true );
    } else {
        setRun( false );
    }
}


void Character::setMoving(const bool go){
    if (moving != go ) { // only update if go differs from current state
        moving = go;
        frameTwo = 0;
        if (go) {
            switchedLastFrame = ci::app::getElapsedSeconds();
        }
    }
}

void Character::setRun(const bool run){
    if (run) {
        step = 400;
    } else {
        step = 200;
    }
}