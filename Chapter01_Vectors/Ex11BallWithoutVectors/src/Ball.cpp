//
//  Ball.cpp
//  Ex11BallWithoutVectors
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#include "Ball.hpp"
#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

using namespace ci;

Ball::Ball( const float x, const float y, const ci::Rand& random )
: x{ x },
  y{ y },
  radius{ 20.f },
x_velocity{ random.randFloat( -8.5f, 8.5f ) },
y_velocity{ random.randFloat( -8.5f, 8.5f ) }
{ }

void Ball::update()
{
    x += x_velocity;
    y += y_velocity;
    
    if ( ( x < radius ) || ( x > app::getWindowWidth() - radius ) ) {
        x_velocity *= -1;
    }
    
    if ( ( y < radius ) || ( y > app::getWindowHeight() - radius ) ) {
        y_velocity *= -1;
    }
}

void Ball::draw() const
{
    gl::color( Color( 0.88f, 0.88f, 0.88f ) );
    gl::drawSolidCircle( vec2{ x, y }, radius );
}