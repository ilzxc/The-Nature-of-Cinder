//
//  Liquid.cpp
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Liquid.h"

Liquid::Liquid( const float x1, const float y1, const float x2, const float y2, const float c_ )
: bounds( x1, y1, x2, y2 ),
  c( c_ )
{ }

bool Liquid::contains( const Mover& m )
{
    Vec2f l = m.getLocation();
    if ( ( l.x > bounds.x1 ) && ( l.x < bounds.x2 ) && ( l.y > bounds.y1 ) && ( l.y < bounds.y2 ) ) {
        return true;
    }
    return false;
}

Vec2f Liquid::drag( const Mover& m )
{
    float speed = ( m.getVelocity() ).length();
    float dragMagnitude = c * speed * speed;
    Vec2f dragForce = m.getVelocity();
    if ( dragForce != Vec2f::zero() ) {
        dragForce *= -1.0f;
        dragForce.normalize();
        dragForce *= dragMagnitude;
    }
    return dragForce;
}

void Liquid::draw() const
{
    gl::color( 0.4f, 0.3f, 0.6f, 0.4f );
    gl::drawSolidRect( bounds );
}