//
//  Mover.cpp
//  Ex32DirectionOfMovement
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

using namespace ci;

Mover::Mover()
: position( Vec2f::zero() ),
  velocity( Vec2f::zero() ),
  acceleration( Vec2f::zero() ),
  bounds( -20.0f, -10.0f, 20.0f, 10.0f ),
  dotBounds( -6.0f, -6.0f, 6.0f, 6.0f )
{ }

void Mover::update( const Vec2f& mousePosition )
{
    acceleration = ( mousePosition - position ).normalized() * 1.7f;
    velocity += acceleration;
    velocity.limit( 8.0f );
    position += velocity;
    
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
}

void Mover::draw() const
{
    gl::color( 0.888f, 0.888f, 0.888f );
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidRect( bounds );
    gl::color( velocity.length() / 10.0f, 0.0f, velocity.length() / 10.0f );
    gl::drawSolidRect( dotBounds );
    gl::popMatrices();
}
