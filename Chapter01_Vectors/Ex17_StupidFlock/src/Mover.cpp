//
//  Mover.cpp
//  Ex17_StupidFlock
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#include "Mover.h"

Mover::Mover( float fat ){
    fatness = fat;
    position = Vec2f( 0.0f, 0.0f );
    velocity = Vec2f( 0.0f, 0.0f );
}

void Mover::resetPosition() {
    position = app::getWindowCenter();
}

void Mover::setAccel( Vec2f mousePos ) {
    const float maxAccel = 3.0f;
    acceleration = (mousePos - position).normalized() * (maxAccel - fatness);
}

void Mover::update() {
    velocity += acceleration;
    velocity.limit( 20.0f );
    position += velocity;
}

void Mover::draw() {
    gl::color( 178, 178, 178, 1.0 );
    gl::drawSolidCircle( position, (fatMax * fatness) );
}
