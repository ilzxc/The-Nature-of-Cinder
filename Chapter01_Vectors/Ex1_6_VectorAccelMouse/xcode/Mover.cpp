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
    velocity = Vec2f( 0.0f, 0.0f );
}

void Mover::resetPosition() {
    position = app::getWindowCenter();
}

void Mover::setAccel( Vec2f mousePos ) {
    acceleration = (mousePos - position).normalized() * 1.7f;
}

void Mover::update() {
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
}

void Mover::draw() {
    gl::color( 178, 178, 178, 1.0 );
    gl::drawSolidCircle( position, 6.0f );
}