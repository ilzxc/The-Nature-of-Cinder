//
//  Ball.cpp
//  Ex11_BallWithoutVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "Ball.h"

Ball::Ball( const float _x, const float _y, const Rand& _r )
: x{ _x },
  y{ _y },
  cRadius{ 20.0f },
  xSpeed{ _r.randFloat( -8.5f, 8.5f ) },
  ySpeed{ _r.randFloat( -8.5f, 8.5f ) },
  grey{ _r.randFloat() }
{ }  // body of constructor empty due to the use of the initializer list

void Ball::update()
{
    x += xSpeed;
    y += ySpeed;
    if ( ( x < cRadius ) || ( x > ( app::getWindowWidth() - cRadius ) ) ) {
        xSpeed *= -1;
    }
    if ( ( y < cRadius ) || ( y > ( app::getWindowHeight() - cRadius ) ) ) {
        ySpeed *= -1;
    }
}

void Ball::draw() const
{
    gl::color( Color{ grey, grey, grey } );
    gl::drawSolidCircle( Vec2f{ x, y }, cRadius );
}