//
//  Vehicle.cpp
//  Ex63StayingWithinWalls
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#include "Vehicle.h"

void Vehicle::update()
{
    boundaries();
    velocity += acceleration;
    velocity.limit( maxSpeed );
    position += velocity;
    acceleration.set( Vec2f::zero() );
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
}

void Vehicle::draw() const
{
    gl::color( 0.77f, 0.77f, 0.77f );
    gl::drawStrokedRect( bounds );
    gl::pushMatrices();
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidTriangle( Vec2f{ size * 2, 0.f }, Vec2f{ -size * 2, size }, Vec2f{ -size * 2, -size } );
    gl::popMatrices();
}

void Vehicle::setBoundary( const Vec2f& dimensions )
{
    bounds = { dimensions.x * boundaryPercent, dimensions.y * boundaryPercent, dimensions.x * ( 1.f - boundaryPercent ), dimensions.y * ( 1.f - boundaryPercent ) };
}

void Vehicle::boundaries()
{
    auto desired = Vec2f::zero();
    
    if ( position.x < bounds.x1 ) {
        desired = { maxSpeed, velocity.y };
    }
    else if ( position.x > bounds.x2 ) {
        desired = { -maxSpeed, velocity.y };
    }
    
    if ( position.y < bounds.y1 ) {
        desired = { velocity.x, maxSpeed };
    }
    else if ( position.y > bounds.y2 ) {
        desired = { velocity.x, -maxSpeed };
    }
    
    if ( desired != Vec2f::zero() ) {
        desired.normalize();
        desired *= maxSpeed;
        desired -= velocity;    // seek
        desired.limit(maxForce);
        acceleration += desired;
    }
}