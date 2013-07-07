//
//  Mover.cpp
//  Ex31SpinningBasics
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "Mover.h"

void Mover::applyForce( const Vec2f& force ) {
    Vec2f f = force / mass;
    acceleration += f;
}

void Mover::update() {
    velocity += acceleration;
    location += velocity;
    
    angleAcceleration = acceleration.x;
    angleVelocity += angleAcceleration;
    angleVelocity = (angleVelocity < -4.0f) ? -4.0f : ( (angleVelocity > 4.0f) ? 4.0 : angleVelocity);
    angle += angleVelocity;
    
    acceleration = Vec2f::zero();
}

void Mover::draw() {
    gl::color( 102.0f/255, 156.0f/255, 204.0f/255 );
    gl::pushMatrices();
    gl::translate( location );
    gl::rotate( angle );
    gl::drawSolidRect( bounds );
    gl::color( 30.0f/255, 95.0f/255, 153.0f/255 );
    gl::drawSolidRect( bounds * 0.75f );
    gl::popMatrices();
}

float Mover::getMass() const {
    return mass;
}

Vec2f Mover::getLocation() const {
    return location;
}

Vec2f Mover::getVelocity() const {
    return velocity;
}

