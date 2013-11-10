//
//  Mover.cpp
//  Ex22Gravity
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#include "Mover.h"

Mover::Mover( const float mass_, const float x, const float y )
: location{ x, y },
  velocity{ Vec2f::zero() },
  acceleration{ Vec2f::zero() },
  mass{ mass_ },
  radius{ mass * 8 }
{ }

const float Mover::getMass() const
{
    return mass;
}

void Mover::applyForce( const Vec2f& force )
{
    acceleration += force / mass;
}

void Mover::update()
{
    velocity += acceleration;
    location += velocity;
    checkEdges();
    acceleration = Vec2f::zero();
}

void Mover::draw() const
{
    gl::color( 1.f, 1.f, 1.f );
    gl::drawSolidCircle( location, radius );
}

void Mover::checkEdges()
{
    if ( location.x > app::getWindowWidth() - radius ) {
        location.x = app::getWindowWidth() - radius;
        velocity.x *= -1;
    } else if ( location.x < radius ) {
        location.x = radius;
        velocity.x *= -1;
    }
    
    if ( location.y > app::getWindowHeight() - radius ) {
        location.y = app::getWindowHeight() - radius;
        velocity.y *= -1;
    }
}


