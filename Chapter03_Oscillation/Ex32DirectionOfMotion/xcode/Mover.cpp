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
    vehicle.set(-10, -5, 10, 5);
    position = Vec2f( 0.0f, 0.0f );
    velocity = Vec2f( 0.0f, 0.0f );
    angle = 0;
}

void Mover::resetPosition() {
    position = app::getWindowCenter();
}

void Mover::setAccel( Vec2f mousePos ) {
    float maxAccel = 3.0f;
    acceleration = (mousePos - position).normalized() * (maxAccel);
}

void Mover::update() {
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
    angle = toDegrees( atan2f(velocity.y, velocity.x) );
}

void Mover::draw() {
    gl::color( 178, 178, 178, 1.0 );
    gl::pushMatrices();
    gl::translate(position);
    gl::rotate(angle);
    gl::drawSolidRect( vehicle );
    gl::popMatrices();
}