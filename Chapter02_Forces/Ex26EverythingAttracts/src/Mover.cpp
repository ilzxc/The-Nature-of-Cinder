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
: location{ x, y },
  velocity{ Vec2f::zero() },
  acceleration{ Vec2f::zero() },
  mass{ mass_ },
  radius{ mass * 4 }
{ }

const float Mover::getMass() const
{
    return mass;
}

const Vec2f& Mover::getLocation() const
{
    return location;
}

const Vec2f& Mover::getVelocity() const
{
    return velocity;
}

void Mover::applyForce( const Vec2f& force )
{
    acceleration += force / mass;
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
    gl::color( 1.f, 1.f, 1.f );
    gl::pushMatrices();
    gl::translate( location );
    gl::color( 1.f, 1.f, 1.f, 0.4f );
    gl::drawLine( Vec2f::zero(), lastAcceleration * 150 );
    gl::color( 1.f, 1.f, 1.f );
    gl::drawSolidCircle( Vec2f::zero(), radius );
    gl::popMatrices();
}

const Vec2f Mover::attract( const Mover& m, const float g ) const
{
    auto force = location - m.getLocation();
    auto distance = force.lengthSquared();
    distance = ( distance < 25.0f ) ? 25.0f : ( ( distance > 625.0f ) ? 625.0 : distance );
    force.normalize();
    force *= g * mass * m.getMass() / ( distance );
    return force;
}
