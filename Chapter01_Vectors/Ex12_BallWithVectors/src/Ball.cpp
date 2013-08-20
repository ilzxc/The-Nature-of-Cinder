//
//  Ball.cpp
//  Ex12_BallWithVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/17/13
//

#include "Ball.h"

Ball::Ball( const Vec2f& position_ )   // constructor overloading
: position( position_ ),
  //velocity( randFloat( -10.0f, 10.0f ), randFloat( -10.0, 10.0f ) ),
  radius( 30.0f )
{
    /* the example above calls "randFloat" - a static function of Rand.
     due to the fact that Rand::randomize() has never been called, the
     "random" behavior will be the same. For non-random behavior, comment
     the below lines and uncomment the velocity declaration in the
     initializer list above.                                             */
    
    Rand::randomize();
    velocity = Vec2f( randFloat(-10.0f, 10.0f), randFloat( -10.0, 10.0f ) );
}

Ball::Ball( const float x_, const float y_ )
: Ball( Vec2f( x_, y_ ) )   // invoke another constructor (after transforming the values)
{ }

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
    gl::color( 0.888f, 0.888f, 0.888f );
    gl::drawSolidCircle( Vec2f::zero(), radius );
    gl::popMatrices();
}