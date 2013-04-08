//
//  Mover.cpp
//  Ex1_4_VectorAccelConst
//
//  Created by Ilya Rostovtsev on 4/7/13.
//
//

#include "Mover.h"

using namespace ci;

Mover::Mover(){
    position = Vec2f( 0.0f, 0.0f );
    Rand::randomize();
    float maxSpeed = 20;
    velocity = Vec2f( randFloat(maxSpeed * 2) - maxSpeed, randFloat(maxSpeed * 2) - maxSpeed );
}

void Mover::resetPosition() {
    position = Vec2f(app::getWindowWidth() / 2.0f, app::getWindowHeight() / 2.0f);
}

void Mover::newAcceleration() {
    float maximumAccel = 0.3f;
    acceleration = Vec2f( randFloat(maximumAccel * 2) - maximumAccel, randFloat(maximumAccel * 2) - maximumAccel);
}

void Mover::update() {
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
    if ( position.x > app::getWindowWidth()) {
        position.x = 0;
    } else if ( position.x < 0 ) {
        position.x = app::getWindowWidth();
    }
    
    if ( position.y > app::getWindowHeight()) {
        position.y = 0;
    } else if ( position. y < 0 ) {
        position.y = app::getWindowHeight();
    }
}

void Mover::draw() {
    gl::color( 178, 178, 178, 1.0 );
    gl::drawSolidCircle( position, 6.0f );
}