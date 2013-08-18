//
//  Mover.cpp
//  Ex26EverythingAttracts
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover( const float _mass, const float _x, const float _y )
    : location( _x, _y ),
      velocity( Vec2f::zero() ),
      acceleration( Vec2f::zero() ),
      mass( _mass ),
      radius( _mass * 4 )
    { }

float Mover::getMass() const {
    return mass;
}

Vec2f Mover::getLocation() const {
    return location;
}

Vec2f Mover::getVelocity() const {
    return velocity;
}

void Mover::applyForce( const Vec2f& force ) {
    Vec2f f = force / mass;
    acceleration += f;
}

void Mover::update() {
    velocity += acceleration;
    location += velocity;
    lastAcceleration = acceleration;
    acceleration = Vec2f::zero();
}

void Mover::draw() const {
    gl::color( 1, 1, 1 );
    gl::pushMatrices();
    gl::translate( location );
    gl::color( 1, 1, 1, 0.4 );
    gl::drawLine( Vec2f::zero(), lastAcceleration * 150 );
    gl::color( 1, 1, 1 );
    gl::drawSolidCircle( Vec2f::zero(), radius );
    gl::popMatrices();
}

Vec2f Mover::attract( const Mover& m, const float g ) const {
    Vec2f force = location - m.getLocation();
    float distance = force.lengthSquared();
    distance = ( distance < 25.0f ) ? 25.0f : ( ( distance > 625.0f ) ? 625.0 : distance );
    force.normalize();
    
    float strength = g * mass * m.getMass() / ( distance );
    force *= strength;
    return force;
}
