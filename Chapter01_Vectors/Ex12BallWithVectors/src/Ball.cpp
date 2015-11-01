//
//  Ball.cpp
//  Ex12BallWithVectors
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#include "Ball.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace std;

Ball::Ball( const vec2& position )
: position{ position },
  radius{ 30.0f }
{
    cout << "ctor (const vec2&)" << endl;
    Rand::randomize();
    velocity = vec2{ randFloat( -10.f, 10.f ), randFloat( -10.f, 10.f ) };
}

/// Copy Constructor
Ball::Ball( const Ball& other )
: position{ other.position },
  velocity{ other.velocity },
  radius{ other.radius }
{
    cout << "copy (const Ball&)" << endl;
}

/// Copy Assignment Operator (extremely simplified version):
Ball& Ball::operator=( const Ball& other )
{
    cout << "operator=(const Ball&)" << endl;
    if ( &other == this ) return *this; // check for assignment to self
    auto result = new Ball{ other }; // call the copy constructor
    return *result;
}


void Ball::update()
{
    position += velocity;
    
    if ( ( position.x < radius ) || ( position.x > ( app::getWindowWidth() - radius ) ) ) {
        velocity.x *= -1;
    }
    
    if ( ( position.y < radius ) || ( position.y > ( app::getWindowHeight() - radius ) ) ) {
        velocity.y *= -1;
    }
}

void Ball::draw() const
{
    gl::pushMatrices();
    gl::translate( position );
    gl::color( 0.88f, 0.88f, 0.88f );
    gl::drawSolidCircle( vec2{ 0.f, 0.f }, radius );
    gl::popMatrices();
}