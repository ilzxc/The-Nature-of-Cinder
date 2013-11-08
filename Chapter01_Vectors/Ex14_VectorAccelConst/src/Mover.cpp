//
//  Mover.cpp
//  Ex14_VectorAccelConst
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover()
: position{ Vec2f::zero() },
  velocity{ Vec2f::zero() },
  acceleration{ Vec2f::zero() }
{ }

void Mover::randomizeAcceleration()
{
    const float maximumAccel = 0.3f;
    Rand::randomize();
    acceleration = Vec2f{ randFloat( maximumAccel * 2 ) - maximumAccel, randFloat( maximumAccel * 2 ) - maximumAccel };
}

void Mover::update()
{
    velocity += acceleration;
    velocity.limit( 10.0f );
    position += velocity;
    
    if ( position.x > app::getWindowWidth() ) {
        position.x = 0.0f;
    } else if ( position.x < 0.0f ) {
        position.x = app::getWindowWidth();
    }
    
    if ( position.y > app::getWindowHeight() ) {
        position.y = 0.0f;
    } else if ( position.y < 0.0f ) {
        position.y = app::getWindowHeight();
    }
}

void Mover::draw() const
{
    gl::color( 178.0f / 255, 178.0 / 255, 178.0f / 255 );
    gl::drawSolidCircle( position, 7.0f );
    gl::color( velocity.length() / 10.0f, 0.0f, 0.0f );
    gl::drawSolidCircle( position, 3.5f );
}