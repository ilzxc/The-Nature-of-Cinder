//
//  Pendulum.cpp
//  Ex36Pendulum
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#include "Pendulum.h"

void Pendulum::update( const Vec2f& mouse ) {
    if (!dragging) {
        angleAcceleration = ( -0.4f / arm ) * sin(angle);
        angleVelocity += angleAcceleration;
        angleVelocity *= damping;
        angle += angleVelocity;
    } else {
        Vec2f diff = origin - mouse;
        angle = atan2f( -diff.y, diff.x ) - (PI / 2.0);
    }
    
    location.set( arm * sin(angle), arm * cos(angle) );
    location += origin;
}


void Pendulum::draw() const {
    gl::color( 0.444f, 0.444f, 0.444f );
    gl::drawLine( origin, location );
    gl::color( 175.0f/255, 175.0f/255, 175.0/255 );
    gl::drawSolidCircle(location, radius);
}

void Pendulum::clicked( const Vec2f& mouse ) {
    float d = (mouse - location).length();
    if ( d < radius ) {
        dragging = true;
    }
}

void Pendulum::stopDragging() {
    angleVelocity = 0.0f;
    dragging = false;
}