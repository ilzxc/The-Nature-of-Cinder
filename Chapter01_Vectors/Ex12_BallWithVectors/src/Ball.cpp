//
//  Ball.cpp
//  Ex12_BallWithVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "Ball.h"

void Ball::update() {
    position += velocity;
    
    if ( (position.x < radius) || (position.x > (app::getWindowWidth() - radius) ) ) {
        velocity.x *= -1;
    }
    
    if ( (position.y < radius) || (position.y > (app::getWindowHeight() - radius) ) ) {
        velocity.y *= -1;
    }
}


void Ball::draw() {
    gl::pushMatrices();
    {
        gl::translate(position);
        gl::color( 0.3, 0.6, 0.9, 1.0 );
        gl::drawSolidCircle( Vec2f::zero(), 20.0f );
    }
    gl::popMatrices();
}