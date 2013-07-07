//
//  Mover.cpp
//  Ex16_VectorAccelMouse
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#include "Mover.h"

using namespace ci;

void Mover::update( const Vec2f& mousePosition) {
    acceleration = (mousePosition - position).normalized() * 1.7f;
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
}

void Mover::draw() {
    gl::color( 178, 178, 178, 1.0f );
    gl::drawSolidCircle( position, 6.0f );
    gl::color( velocity.length() / 10.0f, velocity.length() / 10.0f, 0.0f);
    gl::drawSolidCircle( position, 3.0f);
}
