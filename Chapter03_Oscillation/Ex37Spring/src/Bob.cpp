//
//  Bob.cpp
//  Ex37Spring
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#include "Bob.h"

Bob::Bob( const float _x, const float _y )
    : location( _x, _y ),
      velocity( Vec2f::zero() ),
      acceleration( Vec2f::zero() ),
      mass( 24.0f ),
      damping( 0.98f ),
      dragOffset( Vec2f::zero() ),
      dragging( false )
{ }

void Bob::update( const Vec2f& mouseLocation ) {
    if ( !dragging ) {
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
    gl::drawSolidCircle( location, mass );
}

void Bob::clicked( const Vec2f& mouseLocation ) {
    float d = ( location - mouseLocation ).length();
    if ( d < mass ) {
        dragging = true;
        dragOffset.set( location - mouseLocation );
    }
}

void Bob::stopDragging() {
    dragging = false;
    acceleration.set( Vec2f::zero() );
}

void Bob::applyForce( const Vec2f& force ) {
    Vec2f scaledForce = force / mass;
    acceleration += scaledForce;
}

Vec2f Bob::getLocation() const {
    return location;
}
void Bob::setLocation( const Vec2f& newLocation ) {
    location = newLocation;
}