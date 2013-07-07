//
//  Mover.cpp
//  Ex17_StupidFlock
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#include "Mover.h"

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
