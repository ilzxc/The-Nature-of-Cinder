//
//  Vehicle.cpp
//  Ex63StayingWithinWalls
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#include "Vehicle.h"

void Vehicle::update() {
    boundaries();
    velocity += acceleration;
    velocity.limit( maxSpeed );
    position += velocity;
    acceleration.set( Vec2f::zero() );
    
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
}

void Vehicle::draw() const {
    gl::color( 0.77f, 0.77f, 0.77f );
    gl::drawStrokedRect( bounds );
    gl::pushMatrices();
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidTriangle( Vec2f(size*2, 0), Vec2f(-size*2, size), Vec2f(-size*2, -size) );
    gl::popMatrices();
}

void Vehicle::setBoundary( const Vec2f& dimensions ) {
    bounds = Rectf( dimensions.x * boundaryPercent, dimensions.y * boundaryPercent, dimensions.x * (1.0f - boundaryPercent), dimensions.y * (1.0f - boundaryPercent) );
}

void Vehicle::boundaries() {
    Vec2f desired = Vec2f::zero();
    
    if ( position.x < bounds.x1 ) {
        desired = Vec2f( maxSpeed, velocity.y );
    }
    else if ( position.x > bounds.x2 ) {
        desired = Vec2f( -maxSpeed, velocity.y );
    }
    
    if ( position.y < bounds.y1 ) {
        desired = Vec2f( velocity.x, maxSpeed );
    }
    else if ( position.y > bounds.y2 ) {
        desired = Vec2f( velocity.x, -maxSpeed );
    }
    
    if ( desired != Vec2f::zero() ) {
        desired.normalize();
        desired *= maxSpeed;
        Vec2f steer = desired - velocity;
        steer.limit(maxForce);
        acceleration += steer;
    }
}