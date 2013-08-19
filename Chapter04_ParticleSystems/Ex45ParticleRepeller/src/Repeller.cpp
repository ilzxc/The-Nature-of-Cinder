//
//  Repeller.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#include "Repeller.h"

Repeller::Repeller( const Vec2f& location_ )
: location( location_ ),
  radius( 50.0f ),
  strength( 30.0f )
{ }

void Repeller::setLocation( const Vec2i& mouse )
{
    location = mouse;
}

Vec2f Repeller::repel( const Vec2f& particlePosition ) const
{
    Vec2f direction = location - particlePosition;
    float d = direction.length();
    direction.normalize();
    if ( d < 15.0f ) {
        d = 15.0f;
    } else if ( d > radius * 2 ) {
        d = radius * 2;
    }
    float force = -1.0f * strength / ( d * d );
    direction *= force;
    return direction;
}

void Repeller::draw() const
{
    gl::pushMatrices();
    gl::translate( location );
    gl::color( 30.0f / 255, 95.0f / 255, 153.0f / 255 );
    gl::drawSolidCircle( Vec2f::zero(), radius );
    gl::color( 102.0f / 255, 156.0f / 255, 204.0f / 255 );
    gl::drawSolidCircle( Vec2f::zero(), radius * 0.80f );
    gl::popMatrices();
}

