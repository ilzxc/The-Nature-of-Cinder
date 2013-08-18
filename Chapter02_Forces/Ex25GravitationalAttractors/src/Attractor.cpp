//
//  Attractor.cpp
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Attractor.h"

Attractor::Attractor( const float _x, const float _y )
    : mass( 30.0f ),
      G( 1.5f ),
      location( _x, _y ),
      dragging( false ),
      rollover( false ),
      dragOffset( Vec2f::zero() )
    { }

Vec2f Attractor::attract( const Mover& m ) {
    Vec2f force = location - m.getLocation();
    float d = force.length();
    d = ( d < 5.0 ) ? 5.0 : ( ( d > 25.0 ) ? 25.0 : d );
    force.normalize();
    float strength = ( G * mass * m.getMass() ) / ( d * d );
    force *= strength;
    return force;
}

void Attractor::draw() const {
    if ( rollover ) {
        gl::color( 0.9f, 0.9f, 0.9f );
    } else {
        gl::color( 0.66f, 0.66f, 0.66f );
    }
    gl::drawSolidCircle( location, mass );
    
}
void Attractor::clicked( const Vec2f& mouse ) {
    float d = mouse.distance( location );
    if ( d < mass ) {
        dragging = true;
        dragOffset = location - mouse;
    }
}

void Attractor::hover( const Vec2f& mouse ) {
    float d = mouse.distance( location );
    if ( d < mass ) {
        rollover = true;
    } else {
        rollover = false;
    }
}

void Attractor::stopDragging() {
    dragging = false;
}

void Attractor::drag( const Vec2f& mouse ) {
    if ( dragging ) {
        location = ( mouse + dragOffset );
    }
}