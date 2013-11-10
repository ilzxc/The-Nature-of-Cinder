//
//  Vehicle.cpp
//  Ex62WanderingVehicle
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#include "Vehicle.h"

void Vehicle::toggleDebug()
{
    debug = !debug;
}

void Vehicle::update()
{
    wander();
    velocity += acceleration;
    velocity.limit( maxSpeed );
    position += velocity;
    acceleration.set( Vec2f::zero() );
    borders();
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
}

void Vehicle::draw() const
{
    if ( debug ) {
        drawWander();
    }
    
    gl::pushMatrices();
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidTriangle( Vec2f{ size * 2, 0.f }, Vec2f{ -size * 2, size }, Vec2f{ -size * 2, -size } );
    gl::popMatrices();
}

void Vehicle::drawWander() const
{
    // position, circle, target, wanderR
    gl::drawStrokedCircle( circle, wanderR );
    gl::drawStrokedCircle( target, 4.f );
    gl::drawLine( position, circle );
    gl::drawLine( circle, target );
}

void Vehicle::wander()
{
    wanderTheta += Rand::randFloat( -change, change );
    
    circle = Vec2f{ velocity };
    circle.normalize();
    circle *= wanderD;
    circle += position;
    
    auto h = ( atan2f( circle.y, circle.x ) );
    auto circleOffset = Vec2f{ wanderR * cos( wanderTheta + h ), wanderR * sin( wanderTheta + h ) };
    target = circle + circleOffset;
    seek( target );
}

void Vehicle::borders()
{
    if ( position.x < -size ) {
        position.x = app::getWindowWidth() + size;
    } else if ( position.x > app::getWindowWidth() + size ) {
        position.x = -size;
    }
    
    if ( position.y < -size ) {
        position.y = app::getWindowHeight() + size;
    } else if ( position.y > app::getWindowHeight() + size ) {
        position.y = -size;
    }
}

void Vehicle::seek( const Vec2f& target )
{
    auto desired = target - position;
    desired.normalize();
    desired *= maxSpeed;
    desired -= velocity; // steer
    desired.limit( maxForce );
    acceleration += desired;
}