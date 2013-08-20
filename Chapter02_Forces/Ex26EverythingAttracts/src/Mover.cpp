//
//  Mover.cpp
//  Ex26EverythingAttracts
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover( const float mass_, const float x, const float y )
: location( x, y ),
  velocity( Vec2f::zero() ),
  acceleration( Vec2f::zero() ),
  mass( mass_ ),
  radius( mass * 4 )
{ }

float Mover::getMass() const
{
    return mass;
}

Vec2f Mover::getLocation() const
{
    return location;
}

Vec2f Mover::getVelocity() const
{
    return velocity;
}

void Mover::applyForce( const Vec2f& force )
{
    Vec2f scaledForce = force / mass;
    acceleration += scaledForce;
}

void Mover::update()
{
    velocity += acceleration;
    location += velocity;
    lastAcceleration = acceleration;
    acceleration = Vec2f::zero();
}

void Mover::draw() const
{
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::pushMatrices();
    gl::translate( location );
    gl::color( 1.0f, 1.0f, 1.0f, 0.4f );
    gl::drawLine( Vec2f::zero(), lastAcceleration * 150 );
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::drawSolidCircle( Vec2f::zero(), radius );
    gl::popMatrices();
}

Vec2f Mover::attract( const Mover& m, const float g ) const
{
    Vec2f force = location - m.getLocation();
    float distance = force.lengthSquared();
    distance = ( distance < 25.0f ) ? 25.0f : ( ( distance > 625.0f ) ? 625.0 : distance );
    force.normalize();
    
    float strength = g * mass * m.getMass() / ( distance );
    force *= strength;
    return force;
}
