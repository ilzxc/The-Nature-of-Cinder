//
//  Bob.cpp
//  Ex37Spring
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#include "Bob.h"

void Bob::update( const Vec2f& mouseLocation ) {
    if (!dragging) {
        velocity += acceleration;
        velocity *= damping;
        location += velocity;
        acceleration.set( Vec2f::zero() );
    } else {
        location = mouseLocation + dragOffset;
    }
}

void Bob::draw() const {
    if (dragging) {
        gl::color( 50.0f/255, 50.0f/255, 50.0f/255 );
    } else {
        gl::color( 175.0f/255, 175.0f/255, 175.0f/255 );
    }
    gl::drawSolidCircle(location, mass);
}

void Bob::clicked( const Vec2f& mouseLocation ) {
    float d = (location - mouseLocation).length();
    if (d < mass) {
        dragging = true;
        dragOffset.set( location - mouseLocation );
    }
    
}

void Bob::stopDragging() {
    dragging = false;
    acceleration.set( Vec2f::zero() );
    
}

void Bob::applyForce( const Vec2f& f ) {
    Vec2f force = f / mass;
    acceleration += force;
}

Vec2f Bob::getLocation() const {
    return location;
}
void Bob::setLocation( const Vec2f& newLocation ) {
    location = newLocation;
}
