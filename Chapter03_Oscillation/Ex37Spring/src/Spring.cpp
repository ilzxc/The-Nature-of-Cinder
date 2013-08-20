//
//  Spring.cpp
//  Ex37Spring
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#include "Spring.h"

Spring::Spring( const float x, const float y, const float length_ )
: anchor( x, y ),
  length( length_ ),
  k( 0.2f )
{ }

void Spring::update( Bob& b, const float minLength, const float maxLength )
{
    Vec2f force = b.getLocation() - anchor;
    Vec2f dir = force;
    float d = force.length();
    float stretch = d - length;
    force.normalize();
    force *= ( -k * stretch );
    b.applyForce( force );
    
    if ( ( d < minLength ) || ( d > maxLength ) ) {
        dir.normalize();
        dir *= ( d < minLength ) ? minLength : maxLength;
        b.setLocation( anchor + dir );
    }
    
}

void Spring::draw( const Bob& b ) const
{
    gl::color( 175.0f / 255, 175.0f / 255, 175.0f / 255 );
    gl::drawLine( b.getLocation(), anchor );
    gl::pushMatrices();
    gl::translate( anchor );
    gl::drawSolidRect( Rectf( -5.0f, -5.0f, 5.0f, 5.0f ) );
    gl::popMatrices();
}