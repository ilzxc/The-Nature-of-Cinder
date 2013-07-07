//
//  Mover.cpp
//  Ex26EverythingAttracts
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
    acceleration = Vec2f::zero();
}

void Mover::draw() {
    gl::color( 1, 1, 1 );
    gl::drawSolidCircle( location, radius );
}

Vec2f Mover::attract( const Mover& m, const float g ) {
    Vec2f force = location - m.getLocation();
    float distance = force.length();
    distance = (distance < 5.0f) ? 5.0f : ( (distance > 25.0f) ? 25.0 : distance );
    force.normalize();
    
    float strength = g * mass * m.getMass() / (distance * distance);
    force *= strength;
    return force;
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
