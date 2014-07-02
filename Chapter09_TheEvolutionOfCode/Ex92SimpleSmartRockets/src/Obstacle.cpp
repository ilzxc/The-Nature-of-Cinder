//
//  Obstacle.cpp
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#include "Obstacle.h"

Obstacle::Obstacle( const float x, const float y, const float w, const float h )
: draw_rect( x, y, x + w, y + h )
{
    
}

void Obstacle::draw()
{
    gl::color( 0.686f, 0.686f, 0.686f );
    gl::drawSolidRect( draw_rect );
}

bool Obstacle::contains( const Vec2f& check ) const
{
    if ( draw_rect.contains( check ) ) {
        return true;
    }
    return false;
}