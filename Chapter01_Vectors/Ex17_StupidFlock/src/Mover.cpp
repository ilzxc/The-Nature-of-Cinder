//
//  Mover.cpp
//  Ex17_StupidFlock
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover( const float _fatness )
: fatness( _fatness ),
  position( Vec2f::zero() ),
  velocity( Vec2f::zero() ),
  acceleration( Vec2f::zero() )
{ }

void Mover::setAccel( const Vec2f& mousePosition )
{
    const float maxAccel = 3.0f;
    acceleration = ( mousePosition - position ).normalized() * ( maxAccel - fatness );
}

void Mover::update()
{
    velocity += acceleration;
    velocity.limit( 20.0f );
    position += velocity;
}

void Mover::draw() const
{
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::drawSolidCircle( position, ( 10.0f * fatness ) );
}
