//
//  Vehicle.cpp
//  Ex64FlowFieldFollowing
//
//  Created by Ilya Rostovtsev on 7/16/13.
//
//

#include "Vehicle.h"

Vehicle::Vehicle( const Vec2f& _position, const float _maxforce, const float _maxspeed )
: position{ _position },
  velocity{ Vec2f::zero() },
  acceleration{ Vec2f::zero() },
  size{ 5.f },
  maxForce{ _maxforce },
  maxSpeed{ _maxspeed },
  angle{ 0.f }
{ }

void Vehicle::update( const FlowField& flow )
{
    auto desired = flow.lookup( position );
    desired *= maxSpeed;
    desired -= velocity;        // steer
    desired.limit( maxForce );
    acceleration += desired;
    velocity += acceleration;
    velocity.limit( maxSpeed );
    position += velocity;
    acceleration.set( Vec2f::zero() );
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
    borders();
}

void Vehicle::draw() const
{
    gl::pushMatrices();
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidTriangle( Vec2f{ size * 2, 0 }, Vec2f{ -size * 2, size }, Vec2f{ -size * 2, -size } );
    gl::popMatrices();
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
