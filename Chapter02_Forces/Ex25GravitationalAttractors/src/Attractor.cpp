//
//  Attractor.cpp
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Attractor.h"

Attractor::Attractor( const float x, const float y )
: mass{ 30.f },
  G{ 1.5f },
  location{ x, y },
  dragging{ false },
  rollover{ false },
  dragOffset{ Vec2f::zero() }
{ }

const Vec2f Attractor::attract( const Mover& m ) const
{
    auto force = location - m.getLocation();
    auto d = force.length();
    d = ( d < 5.f ) ? 5.f : ( ( d > 25.f ) ? 25.f : d );
    force.normalize();
    force *= ( G * mass * m.getMass() ) / ( d * d );
    return force;
}

void Attractor::draw() const
{
    if ( rollover ) {
        gl::color( 0.9f, 0.9f, 0.9f );
    } else {
        gl::color( 0.66f, 0.66f, 0.66f );
    }
    gl::drawSolidCircle( location, mass );
    
}
void Attractor::clicked( const Vec2f& mouse )
{
    auto d = mouse.distance( location );
    if ( d < mass ) {
        dragging = true;
        dragOffset = location - mouse;
    }
}

void Attractor::hover( const Vec2f& mouse )
{
    auto d = mouse.distance( location );
    if ( d < mass ) {
        rollover = true;
    } else {
        rollover = false;
    }
}

void Attractor::stopDragging()
{
    dragging = false;
}

void Attractor::drag( const Vec2f& mouse )
{
    if ( dragging ) {
        location = ( mouse + dragOffset );
    }
}