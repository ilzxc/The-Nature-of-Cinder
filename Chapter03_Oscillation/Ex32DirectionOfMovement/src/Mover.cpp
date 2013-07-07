//
//  Mover.cpp
//  Ex32DirectionOfMovement
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "Mover.h"

using namespace ci;

void Mover::update( const Vec2f& mousePosition) {
    acceleration = (mousePosition - position).normalized() * 1.7f;
    velocity += acceleration;
    velocity.limit( 6.0f );
    position += velocity;
    
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
}

void Mover::draw() {
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidRect( bounds );
    gl::color( velocity.length() / 10.0f, 0.0f, velocity.length() / 10.0f );
    gl::drawSolidRect( dotBounds );
    gl::popMatrices();
}
