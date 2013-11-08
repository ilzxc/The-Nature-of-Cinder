//
//  Mover.cpp
//  Ex16_VectorAccelMouse
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover()
: position { Vec2f::zero() },
  velocity { Vec2f::zero() },
  acceleration { Vec2f::zero() }
{ }

void Mover::update( const Vec2f& mousePosition )
{
    acceleration = ( mousePosition - position ).normalized() * 1.7f;
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
}

void Mover::draw() const
{
    gl::color( 178.0f / 255, 178.0f / 255, 178.0f / 255 );
    gl::drawSolidCircle( position, 9.0f );
    gl::color( velocity.length() / 10.0f, velocity.length() / 15.0f, 0.0f );
    gl::drawSolidCircle( position, 4.5f );
}
