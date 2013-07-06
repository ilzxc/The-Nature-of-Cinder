//
//  Mover.cpp
//  Ex15_VectorAccelRandom
//
//  Created by Ilya Rostovtsev on 7/5/13.
//
//

#include "Mover.h"

void Mover::randomizeAcceleration(){
    const float maximumAccel = 0.3f;
    Rand::randomize();
    acceleration = Vec2f( randFloat(maximumAccel * 2) - maximumAccel, randFloat(maximumAccel * 2) - maximumAccel );
}

void Mover::update(){
    randomizeAcceleration();
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
    
    if (position.x > app::getWindowWidth()) {
        position.x = 0;
    } else if (position.x < 0) {
        position.x = app::getWindowWidth();
    }
    
    if (position.y > app::getWindowHeight()) {
        position.y = 0;
    } else if (position.y < 0) {
        position.y = app::getWindowHeight();
    }
}

void Mover::draw(){
    gl::color( 178, 178, 178, 1.0 );
    gl::drawSolidCircle( position, 7.0f);
    gl::color( 0, 0, velocity.length() / 10.0f );
    gl::drawSolidRect( Rectf( position.x - 4, position.y - 4, position.x + 4, position.y + 4) );
}
