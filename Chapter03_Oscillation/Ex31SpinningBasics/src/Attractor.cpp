//
//  Attractor.cpp
//  Ex31SpinningBasics
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "Attractor.h"

Vec2f Attractor::attract( const Mover& m ){
    Vec2f force = location - m.getLocation();
    float d = force.length();
    d = (d < 5.0) ? 5.0 : ( (d > 25.0) ? 25.0 : d);
    force.normalize();
    float strength = (G * mass * m.getMass()) / (d * d);
    force *= strength;
    return force;
}


void Attractor::draw() {
    gl::color( 255.0f/255, 224.0f/255, 216.0f/255 );
    gl::drawSolidCircle( location, mass );
    if (rollover) {
        gl::color( 152.0f/255, 255.0f/255, 249.0f/255 );

    } else {
        gl::color( 204.0f/255, 33.0f/255, 25.0f/255 );
    }
    gl::drawSolidCircle( location, mass * 0.75 );
    
}
void Attractor::clicked( const Vec2f& mouse ) {
    float d = mouse.distance( location );
    if (d < mass) {
        dragging = true;
        dragOffset = location - mouse;
    }
}

void Attractor::hover( const Vec2f& mouse ) {
    float d = mouse.distance( location );
    if (d < mass) {
        rollover = true;
    } else {
        rollover = false;
    }
}

void Attractor::stopDragging() {
    dragging = false;
}

void Attractor::drag( const Vec2f& mouse ) {
    if (dragging) {
        location = (mouse + dragOffset);
    }
}
